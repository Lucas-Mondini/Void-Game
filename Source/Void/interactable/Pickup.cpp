// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "../ThirdPersonCharacter.h"
#include "Kismet/GameplayStatics.h"


APickup::APickup() {
	name = FString("Pickup Base");
	helpText = "Press " + getActionKey() + " To pickup ";
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUp Mesh"));
	Mesh->SetSimulatePhysics(true);
}

void APickup::BeginPlay() {
	helpText = helpText + FString::Printf(TEXT("%s"), *name);
}


void APickup::Interact() {
	Super::Interact();

	AThirdPersonCharacter* CharacterWhoPicked = Cast<AThirdPersonCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	//here goes the implementation of the interaction with the character
	
}

void APickup::Action() {
	Interact();
	onPickedUp();
}

void APickup::onPickedUp() {
	GLog->Log("picked up item: " + name);

	isPickedUp = true;

	if(Mesh) {
		Mesh->SetVisibility(false);
		Mesh->SetSimulatePhysics(false);
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}
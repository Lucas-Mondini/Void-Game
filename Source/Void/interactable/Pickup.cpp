// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "../ThirdPersonCharacter.h"
#include "Kismet/GameplayStatics.h"


APickup::APickup() {
	setName(FString("Pickup Base"));
	setHelpText(FString("Press " + getActionKey() + " To pickup "));
	
	UStaticMeshComponent *mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUp Mesh"));
	mesh->SetSimulatePhysics(true);

	setMesh(mesh);
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

void APickup::setTexture(UTexture2D* newTexture) {
	this->Texture = newTexture;
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

void APickup::onEquiped() {
	GLog->Log("Equiped item: " + name);
    
    	if(Mesh) {
    		Mesh->SetVisibility(true);
    	}
}

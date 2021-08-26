// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC.h"

#include "Void/CharacterAttributes.h"
#include "Void/CharacterStatus.h"
#include "Void/Inventory/InventoryComponent.h"

ABaseNPC::ABaseNPC()
{
	PrimaryActorTick.bCanEverTick = false;

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	Inventory->setOwner(this);
	Drops = CreateDefaultSubobject<UInventoryComponent>(TEXT("Drops"));
	Drops->setOwner(this);
	
	Status = CreateDefaultSubobject<UCharacterStatus>(TEXT("Status"));
	
	Attributes = CreateDefaultSubobject<UCharacterAttributes>(TEXT("Attributes"));

}

void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABaseNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


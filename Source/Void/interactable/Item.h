// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class VOID_API AItem : public APickup
{
	GENERATED_BODY()

	public:

	void Action() override;

	void onPickedUp() override;

	enum ItemType
	{
		Weapon = 1,
		Armor,
		Consumable
	};

	ItemType itemType = ItemType::Weapon;
	
	
};

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

	UPROPERTY(BlueprintReadOnly, Category="Owner", meta = (AllowPrivateAccess = "true"))
	class AThirdPersonCharacter *EquippedOwner;

	public:

	AItem();

	void Action() override;

	void onPickedUp() override;

	void onEquiped() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interactable properties", meta = (AllowPrivateAccess = "true"))
	FString Description;

	UFUNCTION(BlueprintCallable)
	void setDescription(FString newDescription);

	UFUNCTION(BlueprintCallable)
	FString getDescription() const {return Description;}

	UFUNCTION(BlueprintCallable)
	void setEquippedOwner(class AThirdPersonCharacter *newEquippedOwner);
	
	UFUNCTION(BlueprintCallable)
	class AThirdPersonCharacter* getEquippedOwner();

	enum ItemType
	{
		Weapon = 1,
		Armor,
		Consumable
	};

	ItemType itemType = ItemType::Weapon;
	
	
};

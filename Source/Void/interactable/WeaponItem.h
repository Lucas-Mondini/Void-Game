// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "WeaponItem.generated.h"

enum WeaponType
{
	GreatSword = 1,
	Sword,
	axe
};

/**
 * 
 */
UCLASS()
class VOID_API AWeaponItem : public AItem
{
	GENERATED_BODY()

	AWeaponItem();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* collisionCapsule;

	public:
	void AttachToBack(class AThirdPersonCharacter* Character);

	void AttachToHand(class AThirdPersonCharacter* Character);

	//by default the weapon type is a great Sword
	WeaponType weaponType  = WeaponType::GreatSword;
};


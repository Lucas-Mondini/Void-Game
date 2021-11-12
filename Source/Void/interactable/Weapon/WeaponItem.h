// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Void/interactable/Item.h"
#include "WeaponItem.generated.h"

enum WeaponType
{
	GreatSword = 1,
	Sword,
	axe
};

USTRUCT(BlueprintType)
struct FMaxComboCount {
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Max Combo Count")
	int weakAttack;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Max Combo Count")
	int strongAttack;
};

/**
 * 
 */
UCLASS()
class VOID_API AWeaponItem : public AItem
{
	GENERATED_BODY()

	AWeaponItem();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category= "Attack Type")
	bool Weak;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category= "Attack Type")
	bool Strong;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"), Category= "Damage")
	float __WeakDamageMultiplierValue = 1.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"), Category= "Damage")
	float __StrongDamageMultiplierValue = 1.2f;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* collisionCapsule;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class AThirdPersonCharacter* equipping;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Status and Attributes", meta = (AllowPrivateAccess = "true"))
	class UWeaponAttributes* Attributes;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category= "Status and Attributes", meta = (AllowPrivateAccess = "true"))
	class UDamageComponent* Damage;

	public:
	void AttachToBack(class AThirdPersonCharacter* Character);

	void Equiped(class AThirdPersonCharacter* player);
	void onUnquiped();

	void AttachToHand(class AThirdPersonCharacter* Character);

	void DetachFromCharacter(class AThirdPersonCharacter* Character);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Attack", meta = (AllowPrivateAccess = "true"))
		void weakAttack(int attackCount);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Attack", meta = (AllowPrivateAccess = "true"))
		void strongAttack(int attackCount);

	UFUNCTION(BlueprintCallable, Category="Combo", meta = (AllowPrivateAccess = "true"))
	int getWeakMaxComboCount() const {return comboCount.weakAttack;}
	
	UFUNCTION(BlueprintCallable, Category="Combo", meta = (AllowPrivateAccess = "true"))
	int getStrongMaxComboCount() const {return comboCount.strongAttack;}

	//by default the weapon type is a great Sword
	WeaponType weaponType  = WeaponType::GreatSword;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	FMaxComboCount comboCount;

	
	UFUNCTION()
	void OnOverlap( 
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult );

	protected:
	UFUNCTION(BlueprintCallable)
	void ProcessDamage(class AThirdPersonCharacter *Enemy, float Scale);
	
};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponAttributes.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOID_API UWeaponAttributes : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Base Damage")
	int WeakAttackBaseDamage = 10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Base Damage")
	int HeavyAttackBaseDamage = 15;

	//Scales
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int VitalityMultiplier = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int AttunementMultiplier = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int EnduranceMultiplier = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int StrengthMultiplier = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int DexterityMultiplier = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int ResistanceMultiplier = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int IntelligenceMultiplier = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Scale Multiplier")
	int FaithMultiplier = 0;

	//@returns X to weak and Y t heavy
	UFUNCTION(BlueprintCallable)
	FVector2D CalculateDamage(class UCharacterAttributes* Attributes);

	
	UWeaponAttributes();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

		
};

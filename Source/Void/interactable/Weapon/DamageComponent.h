// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOID_API UDamageComponent : public UActorComponent
{
	GENERATED_BODY()

	float D_multiplier = 1.0f;
	float S_multiplier = 1.0f;

public:	
	UDamageComponent();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Physical_D	= 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Magical_D	= 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Bleeding_D	= 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Poison_D	= 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Fire_D		= 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Dark_D		= 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Light_D		= 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damages / Resistances")
		int Balance_D	= 0;

	int CalculateDamage(UDamageComponent *Resistance);
	int CalculateBalanceDamage(UDamageComponent *Resistance);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetDamageMultiplier() const { return this->D_multiplier; }
	UFUNCTION(BlueprintCallable)
	void SetDamageMultiplier(float M);
	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetScaleMultiplier() const { return this->S_multiplier; }
	UFUNCTION(BlueprintCallable)
	void SetScaleMultiplier(float S);
	

protected:
	virtual void BeginPlay() override;

public:	
	
};

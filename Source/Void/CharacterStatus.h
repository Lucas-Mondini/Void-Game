// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterStatus.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOID_API UCharacterStatus : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCharacterStatus();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int MaxHP = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int MaxMP = 20;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int MaxStamina = 200;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int WeightLimit = 20;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int MaxBalance = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int HP = MaxHP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int MP = MaxMP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int Stamina = MaxStamina;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int Weight = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int Balance = MaxBalance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int StaminaRecoveryRate = 5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int BalanceRecoveryRate = 5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	bool isAtMaxHP = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	bool isAtMaxMP = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	bool isAtMaxStamina = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	bool isAtMaxBalance = true;


	UFUNCTION(BlueprintCallable)
	void RecoverHP(int RecoveryFactor);
	UFUNCTION(BlueprintCallable)
	void RecoverMP(int RecoveryFactor);
	UFUNCTION(BlueprintCallable)
	void RecoverStamina(int RecoveryFactor);
	void RecoverStamina();
	UFUNCTION(BlueprintCallable)
	void RecoverBalance(int RecoveryFactor);
	void RecoverBalance();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

public:	

		
};

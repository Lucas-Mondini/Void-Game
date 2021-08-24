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
	int HP = MaxHP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int MP = MaxMP;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int Stamina = MaxStamina;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Status")
	int Weight = 0;

protected:
	virtual void BeginPlay() override;

public:	

		
};

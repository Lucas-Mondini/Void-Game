// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterAttributes.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOID_API UCharacterAttributes : public UActorComponent
{
	GENERATED_BODY()
public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Level;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Souls;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Vitality;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Attunement;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Endurance;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Strength;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Dexterity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Resistance;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Intelligence;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Character Attributes")
	int Faith;
	UCharacterAttributes();

protected:
	virtual void BeginPlay() override;

public:	

		
};

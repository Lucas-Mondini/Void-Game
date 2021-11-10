// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOID_API UDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDamageComponent();
	int Physical_D	= 10;
	int Magical_D	= 0;
	int Bleeding_D	= 0;
	int Poison_D	= 0;
	int Fire_D		= 0;
	int Dark_D		= 0;
	int Light_D		= 0;
	int Balance_D	= 0;

protected:
	virtual void BeginPlay() override;

public:	
	
};

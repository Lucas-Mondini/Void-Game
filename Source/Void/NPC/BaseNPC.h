// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseNPC.generated.h"

UCLASS()
class VOID_API ABaseNPC : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class AWeaponItem* equippedWeapon = nullptr;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Inventory", meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* Inventory;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Inventory", meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* Drops;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Status and Attributes", meta = (AllowPrivateAccess = "true"))
	class UCharacterStatus* Status;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Status and Attributes", meta = (AllowPrivateAccess = "true"))
	class UCharacterAttributes* Attributes;

public:
	ABaseNPC();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

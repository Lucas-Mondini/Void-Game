// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdPersonCharacter.generated.h"

class ABaseWeapon;
UCLASS()
class VOID_API AThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	ABaseWeapon* equippedWeapon = nullptr;

	void MoveForward(float MoveRate);
	void MoveRight(float MoveRate);
	void LookUp(float lookUpRate);
	void LookSide(float lookSideRate);
	void Action();
	bool equipeWeapon(class ABaseWeapon* newWeapon);
	
public:
	AThirdPersonCharacter();

	FORCEINLINE ABaseWeapon* getEquipedWeapon() const {return this->equippedWeapon;}

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* actionArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccsess = "true"));
	float turnRightRate = 45;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccsess = "true"));
	float lookUpRate = 45;

	
public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float yawRotationFactor = 540.0f;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

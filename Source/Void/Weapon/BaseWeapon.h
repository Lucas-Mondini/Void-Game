// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class VOID_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* weaponMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* collisionCapsule;
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	FORCEINLINE class UCapsuleComponent* getCollisionCapsule() const {return this->collisionCapsule;}

	UFUNCTION(BlueprintCallable)
	void pickUpWeapon(class AThirdPersonCharacter* player);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

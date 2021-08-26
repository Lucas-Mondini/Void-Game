// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseNPC_AIController.generated.h"

/**
 * 
 */
UCLASS()
class VOID_API ABaseNPC_AIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category="Attack Count")
	int attackCount = 0;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool rolling = false;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool avoiding = false;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool attacking = false;
	
public:
	ABaseNPC_AIController();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;
	
	virtual FRotator getControlRotation() const {return FRotator(0, GetPawn()->GetActorRotation().Yaw, 0);}

	UFUNCTION()
	void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	float AISightRadius = 500;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	float AISightAge = 5;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	float AILoseSightRadius = 700;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	float AISightAngle = 70;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	float AI_FOV = 90;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	class UAISenseConfig_Sight* SightConfig;
};

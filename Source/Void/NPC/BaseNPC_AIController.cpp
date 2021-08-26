// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC_AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Void/ThirdPersonCharacter.h"

ABaseNPC_AIController::ABaseNPC_AIController() {
	PrimaryActorTick.bCanEverTick = true;
	
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AI Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception")));

	SightConfig->SightRadius = this->AISightRadius;
	SightConfig->LoseSightRadius = this->AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = this->AI_FOV;
	SightConfig->SetMaxAge(this->AISightAge);
	
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	AAIController::GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	AAIController::GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ABaseNPC_AIController::OnPawnDetected);
	AAIController::GetPerceptionComponent()->ConfigureSense(*SightConfig);
	
	
}

void ABaseNPC_AIController::BeginPlay() {
	Super::BeginPlay();
	
}

void ABaseNPC_AIController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);
}

void ABaseNPC_AIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}


void ABaseNPC_AIController::OnPawnDetected(const TArray<AActor*> &DetectedPawns) {
	
	for (AActor* pawn : DetectedPawns) {
		if(Cast<AThirdPersonCharacter>(pawn)->IsPlayerControlled()) {
			GLog->Log("player found");
			this->MoveToActor(pawn);
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

#include "GameFramework/CharacterMovementComponent.h"

ABaseEnemy::ABaseEnemy() {
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 600, 0);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponItem.h"

#include "Components/CapsuleComponent.h"
#include "Void/ThirdPersonCharacter.h"

AWeaponItem::AWeaponItem() {
	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	collisionCapsule->SetupAttachment(Mesh);

	this->name = FString("Weapon Item");
}


inline void AWeaponItem::AttachToBack(AThirdPersonCharacter* Character) {
	Mesh->SetSimulatePhysics(false);
	RootComponent->SetUsingAbsoluteRotation(false);
	this->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_back"));
}

inline void AWeaponItem::AttachToHand(AThirdPersonCharacter* Character) {
	this->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_hand"));
}
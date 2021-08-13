// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponItem.h"

#include "Components/CapsuleComponent.h"
#include "Void/ThirdPersonCharacter.h"

AWeaponItem::AWeaponItem() {
	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	collisionCapsule->SetupAttachment(Mesh);

	setName(FString("Weapon Item Base"));
	setDescription(FString("This is the Weapon Item Base description"));
}


inline void AWeaponItem::AttachToBack(AThirdPersonCharacter* Character) {
	Mesh->SetSimulatePhysics(false);
	RootComponent->SetUsingAbsoluteRotation(false);
	this->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_back"));
}

inline void AWeaponItem::AttachToHand(AThirdPersonCharacter* Character) {
	this->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_hand"));
}

void AWeaponItem::DetachFromCharacter(AThirdPersonCharacter* Character) {
	this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	this->onPickedUp();
}

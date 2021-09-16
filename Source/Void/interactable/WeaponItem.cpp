// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponItem.h"

#include "WeaponAttributes.h"
#include "Components/CapsuleComponent.h"
#include "Void/ThirdPersonCharacter.h"

AWeaponItem::AWeaponItem() {
	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	collisionCapsule->SetupAttachment(Mesh);
	collisionCapsule->OnComponentBeginOverlap.AddDynamic(this,  &AWeaponItem::OnOverlap);

	setName(FString("Weapon Item Base"));
	setDescription(FString("This is the Weapon Item Base description"));

	Attributes = CreateDefaultSubobject<UWeaponAttributes>(TEXT("WeaponAttributes"));
}


inline void AWeaponItem::AttachToBack(AThirdPersonCharacter* Character) {
	Mesh->SetSimulatePhysics(false);
	RootComponent->SetUsingAbsoluteRotation(false);
	this->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_back"));
}

void AWeaponItem::Equiped(AThirdPersonCharacter* player) {
	this->equipping = player;
}

void AWeaponItem::onUnquiped() {
	this->equipping = nullptr;
}

void AWeaponItem::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                            int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	AThirdPersonCharacter* hitted = Cast<AThirdPersonCharacter>(OtherActor);
	if(equipping && hitted && equipping->getIsAttacking() && hitted != equipping) {
			GLog->Log("tocou em " + OtherActor->GetFName().ToString());
			ProcessDamage(hitted, Attributes->CalculateDamage(equipping->getAttributes()));
	}
}

inline void AWeaponItem::AttachToHand(AThirdPersonCharacter* Character) {
	this->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_hand"));
}

void AWeaponItem::DetachFromCharacter(AThirdPersonCharacter* Character) {
	this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	this->onPickedUp();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Void/ThirdPersonCharacter.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	weaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon mesh"));
	weaponMesh->SetSimulatePhysics(true);
	RootComponent = weaponMesh;
	
	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	collisionCapsule->SetupAttachment(weaponMesh);
	collisionCapsule->OnComponentBeginOverlap.AddDynamic(this, &ABaseWeapon::OnOverlap);



}

void ABaseWeapon::AttachToBack(AThirdPersonCharacter* player) {
	weaponMesh->SetSimulatePhysics(false);
	RootComponent->SetUsingAbsoluteRotation(false);
	this->AttachToComponent(player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_back"));
}

void ABaseWeapon::AttachToHand(AThirdPersonCharacter* player) {
	this->AttachToComponent(player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("DefaultWeapon_hand"));
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	GLog->Log(OtherActor->GetFName().ToString());
	GLog->Log("Bateu");
}
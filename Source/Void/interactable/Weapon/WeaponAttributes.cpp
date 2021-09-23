#include "WeaponAttributes.h"

// Sets default values for this component's properties
UWeaponAttributes::UWeaponAttributes()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UWeaponAttributes::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

FVector2D UWeaponAttributes::CalculateDamage(UCharacterAttributes* Attributes) {
	FVector2D damage;
	//needs implementation
	return FVector2D(WeakAttackBaseDamage, HeavyAttackBaseDamage);
}
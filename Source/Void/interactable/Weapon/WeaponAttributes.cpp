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

float UWeaponAttributes::CalculateDamageScale(UCharacterAttributes* Attributes) {
	//needs implementation
	float D_Scale = 1;

	//will return the scale value to the damageComponentMultiplication
	return D_Scale;
}
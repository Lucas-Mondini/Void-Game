#include "DamageComponent.h"

UDamageComponent::UDamageComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDamageComponent::BeginPlay()
{
	Super::BeginPlay();
}

int UDamageComponent::CalculateDamage(UDamageComponent *Resistance) {
	int total_Physical_D	= 	S_multiplier * D_multiplier * Physical_D	- Resistance->Physical_D;
	int total_Magical_D		= 	S_multiplier * D_multiplier * Magical_D		- Resistance->Magical_D;
	int total_Bleeding_D	= 	S_multiplier * D_multiplier * Bleeding_D	- Resistance->Bleeding_D;
	int total_Poison_D		= 	S_multiplier * D_multiplier * Poison_D		- Resistance->Poison_D;
	int total_Fire_D		=	S_multiplier * D_multiplier * Fire_D		- Resistance->Fire_D;
	int total_Dark_D		=	S_multiplier * D_multiplier * Dark_D		- Resistance->Dark_D;
	int total_Light_D		= 	S_multiplier * D_multiplier * Light_D		- Resistance->Light_D;

	//can't be a negative damage
	if(total_Physical_D < 0)
		total_Physical_D = 0;
	if(total_Magical_D < 0)
		total_Magical_D = 0;
	if(total_Bleeding_D < 0)
		total_Bleeding_D = 0;
	if(total_Poison_D < 0)
		total_Poison_D = 0;
	if(total_Fire_D < 0)
		total_Fire_D = 0;
	if(total_Dark_D < 0)
		total_Dark_D = 0;
	if(total_Light_D < 0)
		total_Light_D = 0;

	return	total_Physical_D 	+
			total_Magical_D 	+
			total_Bleeding_D 	+
			total_Poison_D 		+
			total_Fire_D 		+
			total_Dark_D 		+
			total_Light_D;
}

int UDamageComponent::CalculateBalanceDamage(UDamageComponent* Resistance) {
	if (Resistance->Balance_D >= Balance_D)
		return 0;
	return Balance_D - Resistance->Balance_D;
}


void UDamageComponent::SetDamageMultiplier(float M) {
	D_multiplier = M;
}
void UDamageComponent::SetScaleMultiplier(float S) {
	S_multiplier = S;
}
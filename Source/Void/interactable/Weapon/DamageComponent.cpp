#include "DamageComponent.h"

UDamageComponent::UDamageComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDamageComponent::BeginPlay()
{
	Super::BeginPlay();
}
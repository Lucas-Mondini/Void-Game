#include "CharacterAttributes.h"

UCharacterAttributes::UCharacterAttributes()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCharacterAttributes::BeginPlay()
{
	Super::BeginPlay();
	
}
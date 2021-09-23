
#include "CharacterStatus.h"

UCharacterStatus::UCharacterStatus()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}


void UCharacterStatus::RecoverHP(int RecoveryFactor) {
	if(!isAtMaxHP)
		HP+= RecoveryFactor;
}

void UCharacterStatus::RecoverMP(int RecoveryFactor) {
	if(!isAtMaxMP)
		MP+= RecoveryFactor;
}
void UCharacterStatus::RecoverStamina() {
	this->RecoverStamina(StaminaRecoveryRate);
}

void UCharacterStatus::RecoverStamina(int RecoveryFactor) {
	if(!isAtMaxStamina)
		Stamina+= RecoveryFactor;
}
void UCharacterStatus::RecoverBalance() {
	this->RecoverBalance(BalanceRecoveryRate);
}
void UCharacterStatus::RecoverBalance(int RecoveryFactor) {
	if(!isAtMaxBalance)
		Balance+= RecoveryFactor;
}

// Called when the game starts
void UCharacterStatus::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCharacterStatus::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	if(HP < MaxHP)
		isAtMaxHP = false;
	else {
		isAtMaxHP = true;
		HP = MaxHP;
	}
	if(MP < MaxMP)
		isAtMaxMP = false;
	else {
		isAtMaxMP = true;
		MP = MaxMP;
	}
	if(Stamina < MaxStamina)
		isAtMaxStamina = false;
	else {
		isAtMaxStamina = true;
		Stamina = MaxStamina;
	}
	if(Balance < MaxBalance)
		isAtMaxBalance = false;
	else {
		isAtMaxBalance = true;
		Balance = MaxBalance;
	}
}


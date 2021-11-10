
#include "CharacterStatus.h"

#include <future>

UCharacterStatus::UCharacterStatus()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

//
//HP
//
void UCharacterStatus::RecoverHP(int RecoveryFactor) {
	if(!isAtMaxHP)
		HP+= RecoveryFactor;
}

void UCharacterStatus::LoseHP(int LostHP) {
	if(canLoseHP)
		HP -= LostHP;
}
//
//HP
//
//
//MP
//
void UCharacterStatus::RecoverMP(int RecoveryFactor) {
	if(!isAtMaxMP)
		MP+= RecoveryFactor;
}
void UCharacterStatus::LoseMP(int LostMP) {
	MP -= LostMP;
}
//
//MP
//
//
//Stamina
//
void UCharacterStatus::RecoverStamina(int RecoveryFactor) {
	if(!isAtMaxStamina)
		Stamina+= RecoveryFactor;
}

void UCharacterStatus::LoseStamina(int LostStamina) {
	if(canLoseStamina)
		Stamina -= LostStamina;
}
//
//Stamina
//
//
//Balance
//
void UCharacterStatus::RecoverBalance(int RecoveryFactor) {
	if(!isAtMaxBalance)
		Balance+= RecoveryFactor;
}

void UCharacterStatus::LoseBalance(int LostBalance) {
	if(canLoseBalance)
		Balance -= LostBalance;
}
//
//Balance
//

// Called when the game starts
void UCharacterStatus::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCharacterStatus::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {

	//Async call to update if the player can lose some status
	if (Balance <= 0) {
		canLoseBalance = false;
		std::thread ([&](int time) {
			std::this_thread::sleep_for (std::chrono::milliseconds(time));
			canLoseBalance = true;
		}, ClowdownMilisecondsBalance).detach();
	}
	//Async call to update if the player can lose some status
	if (HP <= 0) {
		canLoseHP = false;
		std::thread ([&](int time) {
			std::this_thread::sleep_for (std::chrono::seconds(time));
			canLoseHP = true;
		}, ClowdownMilisecondsHP).detach();
	}
	//Async call to update if the player can lose some status
	if (Stamina <= 0) {
		canLoseStamina = false;
		std::thread ([&](int time) {
			std::this_thread::sleep_for (std::chrono::seconds(time));
			canLoseStamina = true;
		}, ClowdownMilisecondsStamina).detach();
	}
	
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


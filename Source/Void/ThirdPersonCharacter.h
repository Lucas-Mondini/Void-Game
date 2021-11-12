// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "ThirdPersonCharacter.generated.h"
UCLASS()
class VOID_API AThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

	FTimerHandle StatusRecoveryTimerHandle;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class AWeaponItem* equippedWeapon = nullptr;



	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* DeathAnimation = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* DamageAnimation = nullptr;

	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
    bool dead = false;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool rolling = false;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool avoiding = false;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool attacking = false;


	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool inventoryOpened = false;
	
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool canMove = true;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool canDodge = true;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool canAttack = true;
	

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	bool canRecoveryStamina = true;


	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category="Attack Count")
	int attackCount = 0;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category="Attack Count")
	bool canResetAttackCount = false;


	

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Inventory", meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* Inventory;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Status and Attributes", meta = (AllowPrivateAccess = "true"))
	class UCharacterStatus* Status;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Status and Attributes", meta = (AllowPrivateAccess = "true"))
    class UCharacterAttributes* Attributes;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category= "Status and Attributes", meta = (AllowPrivateAccess = "true"))
	class UDamageComponent *Resistances;

	void MoveForward(float MoveRate);
	void MoveRight(float MoveRate);
	void LookUp(float lookUpRate);
	void LookSide(float lookSideRate);
	void Action();

	void callOpenCloseInventory();
	void drawSheatheWeapon();
	void Dodge();
	void weakAttack_implementation();
	void strongAttack_implementation();

	void RecoverStaminaAndBalance();
	void RecoverStamina();
	void RecoverBalance();

	UFUNCTION(BlueprintCallable, Category="equip Weapon")
	bool equipNewWeaponBack(class AWeaponItem* newWeapon);

	UFUNCTION(BlueprintCallable, Category="Die")
	void Die();

	//functions related to animations
	UFUNCTION(BlueprintCallable, Category="equip Weapon")
		bool EquipWeaponHand();
	UFUNCTION(BlueprintCallable, Category="equip Weapon")
		bool EquipWeaponBack();

		void addItemsToInventory(TArray<AActor*> Items);
	UFUNCTION(BlueprintCallable, Category="equip Weapon")
		void addItemsToInventory(class AItem* Item);
	
public:
	AThirdPersonCharacter();

	AWeaponItem* GetEquippedWeapon() const {return this->equippedWeapon;} 

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "equippedWeapon")
	bool isEquippedWeapon = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,  Category = "isInAnimation")
	bool isInDrawSheatheAnim = false;


	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* actionArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccsess = "true"));
	float turnRightRate = 45;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccsess = "true"));
	float lookUpRate = 45;


	//UI related function
	UFUNCTION(BlueprintImplementableEvent)
		void OpenCloseInventory();


	//animation related function

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (AllowPrivateAccess = "true"))
		void ActionChangeSwordHand();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (AllowPrivateAccess = "true"))
		void ActionChangeSwordBack();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (AllowPrivateAccess = "true"))
		void ProcessEndedAttack();
	
	UFUNCTION(BlueprintImplementableEvent)
		void drawWeapon();

	UFUNCTION(BlueprintImplementableEvent)
		void sheatheWeapon();

	UFUNCTION(BlueprintImplementableEvent, Category="Attack")
		void weakAttack();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Attack")
		void strongAttack();
	
	UFUNCTION(BlueprintImplementableEvent, Category="RollAvoid")
		bool Roll();
	UFUNCTION(BlueprintImplementableEvent, Category="RollAvoid")
		bool Avoid();

	
public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RecoveryRate = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float yawRotationFactor = 540.0f;

	UFUNCTION(BlueprintCallable)
	bool TakeDamage(class UDamageComponent *damage);

	FORCEINLINE bool getIsAttacking() const {
		 return this->attacking;
	}
	FORCEINLINE class UCharacterAttributes* getAttributes() const {
		return this->Attributes;
	}

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
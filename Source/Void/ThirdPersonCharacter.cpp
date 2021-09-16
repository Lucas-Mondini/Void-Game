

#include "ThirdPersonCharacter.h"

#include <string>

#include "CharacterAttributes.h"
#include "CharacterStatus.h"
#include "Inventory/InventoryComponent.h"

#include "interactable/Item.h"
#include "interactable/WeaponItem.h"
#include "Weapon/BaseWeapon.h"


#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

AThirdPersonCharacter::AThirdPersonCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	MainCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	MainCamera->bUsePawnControlRotation = false;

	actionArea = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collection area"));
	actionArea->SetupAttachment(RootComponent);

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	Inventory->setOwner(this);

	Status = CreateDefaultSubobject<UCharacterStatus>(TEXT("Status"));
	Attributes = CreateDefaultSubobject<UCharacterAttributes>(TEXT("Attributes"));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, yawRotationFactor, 0);

}
void AThirdPersonCharacter::BeginPlay() {
	Super::BeginPlay();
	
}

void AThirdPersonCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if(Status->HP <= 0 && !dead) {
		Die();
	}

}

void AThirdPersonCharacter::drawSheatheWeapon() {
	if(equippedWeapon)
		if(!isInDrawSheatheAnim) {
			
			if(isEquippedWeapon) {
				UCharacterMovementComponent *movement = Cast<UCharacterMovementComponent>(GetMovementComponent());
				movement->MaxWalkSpeed = 600;
				sheatheWeapon();
			}
			else {
				UCharacterMovementComponent *movement = Cast<UCharacterMovementComponent>(GetMovementComponent());
				movement->MaxWalkSpeed = 300;
				drawWeapon();
			}
		}
}


bool AThirdPersonCharacter::TakeDamage(int damage) {
	GLog->Log(FString::FromInt(damage));
	this->Status->HP -= damage;
	GLog->Log("HP = " + this->Status->HP);
	if (this->Status->HP > 0)
		return false;
	return true;
}

void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveFront", this, &AThirdPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AThirdPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AThirdPersonCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AThirdPersonCharacter::LookSide);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AThirdPersonCharacter::Action);
	PlayerInputComponent->BindAction("WeaponDrawSheathe", IE_Pressed, this, &AThirdPersonCharacter::drawSheatheWeapon);
	PlayerInputComponent->BindAction("Dodge", IE_Pressed, this, &AThirdPersonCharacter::Dodge);
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AThirdPersonCharacter::callOpenCloseInventory);
	PlayerInputComponent->BindAction("Weak_Attack", IE_Pressed, this, &AThirdPersonCharacter::weakAttack_implementation);
	PlayerInputComponent->BindAction("Strong_Attack", IE_Pressed, this, &AThirdPersonCharacter::strongAttack_implementation);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

}

void AThirdPersonCharacter::MoveForward(float MoveRate) {
	if(Controller && MoveRate) {
		if(canMove) {
			if(MoveRate < 0 && isEquippedWeapon) {
				bUseControllerRotationYaw = true;
			}
			else 
				bUseControllerRotationYaw = false;
			
			const FRotator rotation = Controller->GetControlRotation();
			const FRotator Yaw(0, rotation.Yaw, 0);
			const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);
			AddMovementInput(direction, MoveRate);
		}
	}
}

void AThirdPersonCharacter::MoveRight(float MoveRate) {
	if(Controller && MoveRate)
	{
		if(canMove) {
			if(isEquippedWeapon)
				bUseControllerRotationYaw = true;
			
			const FRotator rotation = Controller->GetControlRotation();
			const FRotator Yaw(0, rotation.Yaw, 0);
			const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);
			AddMovementInput(direction, MoveRate);
		}
	}
}

void AThirdPersonCharacter::LookUp(float lookRate) {
	AddControllerPitchInput(GetWorld()->GetDeltaSeconds() * lookRate * this->lookUpRate);
}

void AThirdPersonCharacter::LookSide(float lookRate) {
	AddControllerYawInput(GetWorld()->GetDeltaSeconds() * lookRate * this->turnRightRate);
}

void AThirdPersonCharacter::Dodge() {
	float y = InputComponent->GetAxisValue("MoveFront");
	float x = InputComponent->GetAxisValue("MoveRight");
	if(canDodge && isEquippedWeapon) {
		if(x || y) {
				canMove = false;		
				Roll();
				canDodge = false;
		}
		else {
				canMove = false;
				Avoid();
				canDodge = false;
		}
	}
}

void AThirdPersonCharacter::Action() {

	TArray<AActor*> Items;
	actionArea->GetOverlappingActors(Items, AItem::StaticClass());
	addItemsToInventory(Items);
}

bool AThirdPersonCharacter::equipNewWeaponBack(AWeaponItem* newWeapon) {
	UE_LOG(LogTemp, Warning, TEXT("object name = %s"), *newWeapon->GetName());
	try {
		if(this->equippedWeapon && this->equippedWeapon != newWeapon) {
			addItemsToInventory(equippedWeapon);
			equippedWeapon->DetachFromCharacter(this);
		}
		this->equippedWeapon = newWeapon;
		newWeapon->onEquiped();
		newWeapon->setEquippedOwner(this);
	} catch (int e) {
		UE_LOG(LogTemp, Error, TEXT("An error ocurred on equip weapon code: %i"), e);
		return false;
	}
	equippedWeapon->AttachToBack(this);
	return true;
}

void AThirdPersonCharacter::callOpenCloseInventory() {
	OpenCloseInventory();
}

bool AThirdPersonCharacter::EquipWeaponHand() {
	if(this->equippedWeapon) {
		UE_LOG(LogTemp, Warning, TEXT("object name = %s"), *this->equippedWeapon->GetName());
		this->equippedWeapon->AttachToHand(this);
		try {
			this->equippedWeapon->Equiped(this);
		} catch (std::exception e) {
			GLog->Log(e.what());
		}
		return true;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("no weapon equiped"));
	}
	return false;
}

bool AThirdPersonCharacter::EquipWeaponBack() {
	if(this->equippedWeapon) {
		UE_LOG(LogTemp, Warning, TEXT("object name = %s"), *this->equippedWeapon->GetName());
		this->equippedWeapon->AttachToBack(this);
		return true;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("no weapon equiped"));
	}
	return false;
}

void AThirdPersonCharacter::addItemsToInventory(TArray<AActor*> Items) {
	for (int i = 0; i < Items.Num(); i++) {
		AItem *item = Cast<AItem>(Items[i]);
		if(item && !item->IsPendingKill()) {
			if(Inventory->AddItem(item))
				item->onPickedUp();
			//if the item is a weapon and the player isn't equipped with a weapon
			if(!equippedWeapon && item->itemType == AItem::Weapon) {
				//the player will equip the weapon
				equipNewWeaponBack(Cast<AWeaponItem>(item));
				item->onEquiped();
			} 
		}
	}
}

void AThirdPersonCharacter::addItemsToInventory(AItem* Item) {
	if(Item && !Item->IsPendingKill()) {
		if(Inventory->AddItem(Item))
			Item->onPickedUp();
	}
}


void AThirdPersonCharacter::weakAttack_implementation() {
	if(canAttack && !inventoryOpened) {
		attacking = true;
		weakAttack(); 
	}	
}

void AThirdPersonCharacter::strongAttack_implementation() {
	if(canAttack && !inventoryOpened) {
		attacking = true;
		strongAttack();
	}	
}

void AThirdPersonCharacter::Die() {
    dead = true;
	
     
	FTimerHandle TimerHandle;
	

	PlayAnimMontage(DeathAnimation, 1, NAME_None);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {
		this->Destroy();
	}, DeathAnimation->GetPlayLength(), 1);
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, , DeathAnimation->GetPlayLength(), false);
}


#include "ThirdPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Weapon/BaseWeapon.h"

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

}

void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveFront", this, &AThirdPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AThirdPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AThirdPersonCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AThirdPersonCharacter::LookSide);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AThirdPersonCharacter::Action);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

}

void AThirdPersonCharacter::MoveForward(float MoveRate) {
	if(Controller && MoveRate) {
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator Yaw(0, rotation.Yaw, 0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);
		AddMovementInput(direction, MoveRate);
	}
}
void AThirdPersonCharacter::MoveRight(float MoveRate) {
	if(Controller && MoveRate)
	{
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator Yaw(0, rotation.Yaw, 0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, MoveRate);
	}
}

void AThirdPersonCharacter::LookUp(float lookRate) {
	AddControllerPitchInput(GetWorld()->GetDeltaSeconds() * lookRate * this->lookUpRate);
}

void AThirdPersonCharacter::LookSide(float lookRate) {
	AddControllerYawInput(GetWorld()->GetDeltaSeconds() * lookRate * this->turnRightRate);
}

void AThirdPersonCharacter::Action() {
	TArray<AActor*> weapons;
	actionArea->GetOverlappingActors(weapons, ABaseWeapon::StaticClass());

	for(int i = 0; i < weapons.Num(); i++) {
		ABaseWeapon* weapon = Cast<ABaseWeapon>(weapons[i]);
		if(weapon && !weapon->IsPendingKill() && this->equippedWeapon != weapon) {
			if(equipeWeapon(weapon))
				return;
		}
	}

	if(this->equippedWeapon)
		UE_LOG(LogTemp, Warning, TEXT("equipped weapon = %s"), *this->equippedWeapon->GetName());
}

bool AThirdPersonCharacter::equipeWeapon(ABaseWeapon* newWeapon) {
	UE_LOG(LogTemp, Warning, TEXT("object name = %s"), *newWeapon->GetName());
	try {
		this->equippedWeapon = newWeapon;
	} catch (int e) {
		UE_LOG(LogTemp, Error, TEXT("An error ocurred on equip weapon code: %i"), e);
		return false;
	}
	equippedWeapon->pickUpWeapon(this);
	return true;
}


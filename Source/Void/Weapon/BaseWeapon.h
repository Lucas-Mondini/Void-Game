#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

enum WeaponType
{
	GreatSword = 1,
	Sword,
	axe
};

UCLASS()
class VOID_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* weaponMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* collisionCapsule;
	
public:	
	ABaseWeapon();

	FORCEINLINE class UCapsuleComponent* getCollisionCapsule() const {return this->collisionCapsule;}

	UFUNCTION(BlueprintCallable)
	    void AttachToBack(class AThirdPersonCharacter* player);
	
	UFUNCTION(BlueprintCallable)
    	void AttachToHand(class AThirdPersonCharacter* player);

	//by default the weapon type is a great Sword
	WeaponType weaponType  = WeaponType::GreatSword;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};

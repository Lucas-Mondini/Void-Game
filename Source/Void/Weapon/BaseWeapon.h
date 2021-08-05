#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

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

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};

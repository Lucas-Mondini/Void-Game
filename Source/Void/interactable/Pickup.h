// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class VOID_API APickup : public AInteractable
{
private:
	GENERATED_BODY()

public:
	APickup();

	virtual void Action();

	virtual void Interact() override;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	bool isPickedUp = false;

	UPROPERTY(BlueprintReadWrite, Category= "Pickup properties", meta = (allowPrivateAccess = "true"))
	UTexture2D *Texture;

	UFUNCTION(BlueprintCallable)
	UTexture2D* getTexture() {return Texture;}
	
protected:

	//called when item is pickedUp
    virtual void onPickedUp();
	virtual void onEquiped();
};

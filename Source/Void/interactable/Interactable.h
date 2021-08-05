// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class VOID_API AInteractable : public AActor
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Interactable properties", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* actionArea;
	
public:	
	AInteractable();

	FString getActionKey();

protected:
	virtual void BeginPlay() override;
	

	//assume that every interactable class should have a mesh
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Interactable properties", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;

	//assume that every interactable class should have a name
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Interactable properties", meta = (AllowPrivateAccess = "true"))
	FString name = "Interactable baseclass";

	//assume that every interactable class should have a helptext
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Interactable properties", meta = (AllowPrivateAccess = "true"))
	FString helpText;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Action Key", meta = (AllowPrivateAccess = "true"))
	FString ActionKey = "F";
	

public:	

	UFUNCTION(BlueprintCallable)
	virtual void Interact();

};

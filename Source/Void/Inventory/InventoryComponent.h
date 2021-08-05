// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOID_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	TArray<class AItem *> Items;

	/**
	 * @brief
	 * here goes the owner of the inventory, can be any actor
	 */
	AActor *Owner;

public:	
	
	UInventoryComponent();

	void setOwner(AActor* Owner);

	UFUNCTION(BlueprintCallable, Category= "Inventory")
	bool AddItem(class AItem *Item);

	UFUNCTION(BlueprintCallable, Category= "Inventory")
	bool RemoveItem(class AItem *Item);
	
	template <class T>
	UFUNCTION(BlueprintCallable, Category= "Inventory")
	bool DropItem(class AItem* Item);
	
	UFUNCTION(BlueprintCallable, Category= "Inventory")
	bool DestroyItem(class AItem *Item);

protected:
	
	virtual void BeginPlay() override;

public:	

};

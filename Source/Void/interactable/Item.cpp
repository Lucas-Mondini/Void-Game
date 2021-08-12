// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

AItem::AItem() {
	Description = FString("This is the item description");
	name = FString("Item");
}

void AItem::Action() {
}

void AItem::onPickedUp() {
	Super::onPickedUp();
}

void AItem::onEquiped() {
	Super::onEquiped();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

AItem::AItem() {
	setName(FString("Item base"));
	setDescription(FString("This is the item description"));
}

void AItem::Action() {
}

void AItem::onPickedUp() {
	Super::onPickedUp();
}

void AItem::onEquiped() {
	Super::onEquiped();
}

void AItem::setDescription(FString newDescription) {
	this->Description = newDescription;
}

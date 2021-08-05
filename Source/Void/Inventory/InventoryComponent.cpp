#include "InventoryComponent.h"
#include "Void/interactable/Item.h"

UInventoryComponent::UInventoryComponent() {
	
}

void UInventoryComponent::setOwner(AActor* newOwner) {
	this->Owner = newOwner;	
}


void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

bool UInventoryComponent::AddItem(AItem *Item) {

	if(Item) {
		//if(!Item->isPickedUp)
			//Item->onPickedUp();
		
		Items.Add(Item);
		//updateUI
		return true;
	}
	return false;
}

bool UInventoryComponent::RemoveItem(AItem* Item) {
	if(Item) {
		Items.Remove(Item);
		//updateUI
		return true;
	}
	return false;	
}

template <typename T>
bool UInventoryComponent::DropItem(AItem *Item) {
	if(Item) {
		Items.Remove(Item);
		//updateUI
		const FActorSpawnParameters Parameters;
		const TSubclassOf<T> ItemToSpawn;
		Owner->GetWorld()->SpawnActor<T>(ItemToSpawn, Owner->GetActorLocation(), Owner->GetActorRotation(), Parameters);
	}
	return true;
}

bool UInventoryComponent::DestroyItem(AItem *Item) {

	if(Item) {
		Items.Remove(Item);
		Item->Destroy();
	}
	return true;
}

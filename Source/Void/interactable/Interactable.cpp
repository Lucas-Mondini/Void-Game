
#include "Interactable.h"

#include <RenderDebug.h>

#include "GameFramework/InputSettings.h"

FString AInteractable::getActionKey() {
	UInputSettings* Settings = const_cast<UInputSettings*>(GetDefault<UInputSettings>());
	if(Settings) {
		TArray <FInputActionKeyMapping> OutMappings;
		Settings->GetActionMappingByName("Action", OutMappings);
		const FInputActionKeyMapping KeyMapped = OutMappings[0];
		ActionKey = KeyMapped.ActionName.ToString();	
	}
	
	return ActionKey;
}


AInteractable::AInteractable()
{
	helpText = "press " +getActionKey() + " To Interact";
	
}

void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractable::Interact() {
	GLog->Log("Interacting: " + this->name);
}



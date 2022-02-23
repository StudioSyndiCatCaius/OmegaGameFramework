// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Input/InputReceiverComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UInputReceiverComponent::UInputReceiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInputReceiverComponent::BeginPlay()
{
	Super::BeginPlay();

	OverrideInputOwner(GetOwner());
	
}

void UInputReceiverComponent::OverrideInputOwner(AActor* NewOwner)
{
	if(!NewOwner || !InputAction)
	{
		return;
	}
	UEnhancedInputComponent* NewInputComp = Cast<UEnhancedInputComponent>(NewOwner->InputComponent);
	if(NewInputComp)
	{
		
		OwnerInputComp = NewInputComp;
		OwnerInputComp->BindAction(InputAction, ETriggerEvent::Started, this, &UInputReceiverComponent::Native_Started);
		OwnerInputComp->BindAction(InputAction, ETriggerEvent::Triggered, this, &UInputReceiverComponent::Native_Triggered);
		OwnerInputComp->BindAction(InputAction, ETriggerEvent::Canceled, this, &UInputReceiverComponent::Native_Cancel);
		OwnerInputComp->BindAction(InputAction, ETriggerEvent::Completed, this, &UInputReceiverComponent::Native_Complete);
		OwnerInputComp->BindAction(InputAction, ETriggerEvent::Ongoing, this, &UInputReceiverComponent::Native_Ongoing);
		OwnerInputComp->BindActionValue(InputAction);
	}
}

FInputActionValue UInputReceiverComponent::GetInputActionValue()
{
	FInputActionValue BadValue;
	if(!OwnerInputComp || !InputAction)
	{
		return BadValue;
	}
	return OwnerInputComp->GetBoundActionValue(InputAction);
}

void UInputReceiverComponent::Native_Started()
{
	OnInputStarted.Broadcast();
}

void UInputReceiverComponent::Native_Triggered()
{
	OnInputTriggered.Broadcast();
}

void UInputReceiverComponent::Native_Complete()
{
	OnInputCompleted.Broadcast();
}

void UInputReceiverComponent::Native_Cancel()
{
	OnInputCancel.Broadcast();
}

void UInputReceiverComponent::Native_Ongoing()
{
	
}



// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/InputReceiverComponent.h"

#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

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

	//Local_InputAction = NewObject<UInputAction>(this, UInputAction::StaticClass());
	
	BindToPawn(Cast<APawn>(GetOwner()));
}

void UInputReceiverComponent::OverrideInputOwner(AActor* NewOwner)
{
	if(NewOwner && InputAction)
	{
		if(UEnhancedInputComponent* NewInputComp = Cast<UEnhancedInputComponent>(NewOwner->InputComponent))
		{
			UE_LOG(LogTemp, Display, TEXT("Valid New Input Component") );
			OwnerInputComp = NewInputComp;
			OwnerInputComp->BindAction(InputAction, ETriggerEvent::Started, this, &UInputReceiverComponent::Native_Started);
			OwnerInputComp->BindAction(InputAction, ETriggerEvent::Triggered, this, &UInputReceiverComponent::Native_Triggered);
			OwnerInputComp->BindAction(InputAction, ETriggerEvent::Canceled, this, &UInputReceiverComponent::Native_Cancel);
			OwnerInputComp->BindAction(InputAction, ETriggerEvent::Completed, this, &UInputReceiverComponent::Native_Complete);
			OwnerInputComp->BindAction(InputAction, ETriggerEvent::Ongoing, this, &UInputReceiverComponent::Native_Ongoing);
			OwnerInputComp->BindActionValue(InputAction);
		}
	}
	else
	{
		//UE_LOG(LogTemp, Display, TEXT("Ckecing Input Action: %s"), *InputAction->GetName());
		if(!InputAction)
		{
			UE_LOG(LogTemp, Display, TEXT("Input Action invalid on %s"), *GetOwner()->GetClass()->GetName());
		}
		if (!NewOwner)
		{
			UE_LOG(LogTemp, Display, TEXT("Input Owner invalid on %s"), *GetOwner()->GetClass()->GetName());
		}
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
	UE_LOG(LogTemp, Display, TEXT("Attempted Input Reciever Action: Started") );
	OnInputStarted.Broadcast();
}

void UInputReceiverComponent::Native_Triggered()
{
	UE_LOG(LogTemp, Display, TEXT("Attempted Input Reciever Action: Triggered") );
	OnInputTriggered.Broadcast();
}

void UInputReceiverComponent::Native_Complete()
{
	UE_LOG(LogTemp, Display, TEXT("Attempted Input Reciever Action: Completed") );
	OnInputCompleted.Broadcast();
}

void UInputReceiverComponent::Native_Cancel()
{
	UE_LOG(LogTemp, Display, TEXT("Attempted Input Reciever Action: Canceled") );
	OnInputCancel.Broadcast();
}

void UInputReceiverComponent::Native_Ongoing()
{
	
}

void UInputReceiverComponent::OnOwningControllerChange(APawn* Pawn, AController* OldController, AController* NewController)
{
	UE_LOG(LogTemp, Display, TEXT("Attempted Input Reciever Owner Change (on new controller)") );
	AActor* LocalActorRef = Pawn;
	OverrideInputOwner(LocalActorRef);

	if(Cast<APlayerController>(OldController))
	{
		GetOwner()->DisableInput(Cast<APlayerController>(OldController));
	}
	
	if(Cast<APlayerController>(NewController))
	{
		GetOwner()->EnableInput(Cast<APlayerController>(NewController));
	}
}

void UInputReceiverComponent::BindToPawn(APawn* Pawn)
{
	if(Pawn)
	{
		UE_LOG(LogTemp, Display, TEXT("Bound Input Reciever event on owner controller change") );
		Pawn->ReceiveControllerChangedDelegate.AddDynamic(this, &UInputReceiverComponent::OnOwningControllerChange);
	}
}




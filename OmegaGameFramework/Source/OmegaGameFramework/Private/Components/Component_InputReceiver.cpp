// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_InputReceiver.h"

#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"


bool UOmegaInputAction::IsInputActive(APlayerController* Controller) const
{
	if(Script) { return Script->IsInputActive(Controller); } return false;
}

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



void UInputReceiverComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	cached_dt=DeltaTime;

	//If using UE Input Action, ignore
	if(!InputAction && GetInputAction())
	{
		UOmegaInputAction* REF_action = GetInputAction();
		//If Just Pressed
		if(!bIsInputActive && REF_action->IsInputActive(REF_OwningController))
		{
			bIsInputActive=true;
			OnInputStarted.Broadcast();
		}
		//If Just Released
		if(bIsInputActive && !REF_action->IsInputActive(REF_OwningController))
		{
			bIsInputActive=false;
			OnInputCompleted.Broadcast();
		}
		if(bIsInputActive)
		{
			OnInputTriggered.Broadcast(DeltaTime);
		}
	}
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInputReceiverComponent::OverrideInputOwner(AActor* NewOwner)
{
	if(NewOwner)
	{
		for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			if (APlayerController* PlayerController = Iterator->Get())
			{
				if(PlayerController->IsInputComponentInStack(NewOwner->InputComponent))
				{
					REF_OwningController=PlayerController;
					break;
				}
			}
		}
	}
	if(NewOwner && InputAction)
	{
		//Use custom input action
		if(InputAction)
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
			else
			{
			}
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
	OnInputTriggered.Broadcast(cached_dt);
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
	
	if((REF_OwningController = Cast<APlayerController>(NewController)) != nullptr)
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




// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_InputReceiver.h"

#include "InputMappingContext.h"
#include "OmegaSettings.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"


void UOmegaInputAction::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                          FText& Description)
{
	Name=ActionDescription;
	Description=DisplayDescription;
	IDataInterface_General::GetGeneralDataText_Implementation(Label, Context, Name, Description);
}

APlayerController* UInputReceiverComponent::GetContextPlayer()
{
	if (CachedPlayerController) { return CachedPlayerController; }
	if (ContextOwner)
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(ContextOwner))
		{
			CachedPlayerController = PlayerController;
			return PlayerController;
		}
		if (APawn* Pawn = Cast<APawn>(ContextOwner))
		{
			if (APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController()))
			{
				CachedPlayerController = PlayerController;
				return PlayerController;
			}
		}
	}
	return nullptr;
}

bool UInputReceiverComponent::CheckKeysPressed() const
{
	if (!CachedPlayerController)
	{
		return false;
	}

	// At least ONE key must be pressed
	for (const FKey& Key : GetKeys())
	{
		if (CachedPlayerController->IsInputKeyDown(Key))
		{
			return true;
		}
	}
	
	return false;
}

bool UInputReceiverComponent::CheckPrerequisiteKeys() const
{
	
	if (!CachedPlayerController)
	{
		return false;
	}

	// If no prerequisite keys, condition is always met
	if (PrerequisiteKeys.Num() == 0)
	{
		return true;
	}

	// ALL prerequisite keys must be pressed
	for (const FKey& Key : PrerequisiteKeys)
	{
		if (!CachedPlayerController->IsInputKeyDown(Key))
		{
			return false;
		}
	}
	
	return true;
}

TMap<FKey, FVector> UInputReceiverComponent::GetKeyValues() const
{
	TMap<FKey, FVector> out=GetMutableDefault<UOmegaSettings>()->GetInputActionConfig(InputPresetToUse).KeyInputs;
	out.Append(Keys);
	return out;
}

TArray<FKey> UInputReceiverComponent::GetKeys() const
{
	TArray<FKey> out;
	GetKeyValues().GetKeys(out);
	return out;
}

FVector UInputReceiverComponent::GetKey_InputValue(FKey Key)
{
	if (GetKeyValues().Contains(Key)) { return GetKeyValues()[Key]; }
	return FVector();
}

TArray<FName> UInputReceiverComponent::L_GetInputNames() const
{
	TArray<FName> out;
	GetMutableDefault<UOmegaSettings>()->GetAllInputActionConfigs().GetKeys(out);
	return out;
}

UInputReceiverComponent::UInputReceiverComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	bIsInputActive = false;
}

void UInputReceiverComponent::BeginPlay()
{
	Super::BeginPlay();
	if (bStartInCooldown)
	{
		f_cooldownTime=CooldownTime;
	}
	
	BindToPawn(Cast<APawn>(GetOwner()));
	if (APawn* playerPawn=UGameplayStatics::GetPlayerPawn(this,GetOwner()->AutoReceiveInput-1))
	{
		OverrideInputOwner(playerPawn);
	}
	else
	{
		OverrideInputOwner(GetOwner());
	}
}

void UInputReceiverComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	cached_dt=DeltaTime;
	f_cooldownTime=-DeltaTime;
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	

	
	if (!IsInputInCooldown())
	{
		// Early exit if no valid data
		if (!CachedPlayerController || Keys.Num() == 0)
		{
			// If input was active but no longer valid, complete it
			if (bIsInputActive)
			{
				bIsInputActive = false;
				OnInputCompleted.Broadcast(cached_InputValue);
			}
			return;
		}
		
		cached_InputValue=FVector(0,0,0);
		//calculate input value from keys down
		for (FKey Key : GetKeys())
		{
			if (CachedPlayerController->IsInputKeyDown(Key))
			{
				cached_InputValue+=GetKey_InputValue(Key);
			}
		}
	
		// Check if input condition is met: Prerequisites AND at least one main key
		bool bInputConditionMet = CheckPrerequisiteKeys() && CheckKeysPressed();

		// Handle state transitions
		if (bInputConditionMet)
		{
			if (!bIsInputActive)
			{
				// Input just started
				bIsInputActive = true;
				OnInputStarted.Broadcast(cached_InputValue);
			}
		
			// Input is active (continuing or just started)
			OnInputTriggered.Broadcast(DeltaTime,cached_InputValue);
		}
		else
		{
			if (bIsInputActive)
			{
				// Input just ended
				bIsInputActive = false;
				OnInputCompleted.Broadcast(cached_InputValue);
				f_cooldownTime=CooldownTime;
			}
		}
	}
}

bool UInputReceiverComponent::IsInputInCooldown() const
{
	if (f_cooldownTime<=0.0)
	{
		return false;
	}
	return true;
}

void UInputReceiverComponent::OverrideInputOwner(AActor* NewOwner)
{
	if (NewOwner)
	{
		ContextOwner=NewOwner;
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
	CachedPlayerController=nullptr;
	GetContextPlayer();
	
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
	OnInputStarted.Broadcast(cached_InputValue);
}

void UInputReceiverComponent::Native_Triggered()
{
	OnInputTriggered.Broadcast(cached_dt,cached_InputValue);
}

void UInputReceiverComponent::Native_Complete()
{
	OnInputCompleted.Broadcast(cached_InputValue);
}

void UInputReceiverComponent::Native_Cancel()
{
	OnInputCompleted.Broadcast(cached_InputValue);
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




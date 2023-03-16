// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaAbility.h"

#include "GameFramework/Character.h"
#include "Gameplay/CombatantComponent.h"
#include "Input/InputReceiverComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "OmegaGameManager.h"
#include "Components/TimelineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/OmegaPlayerSubsystem.h"

// Sets default values
AOmegaAbility::AOmegaAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
	DefaultInputReceiver = CreateDefaultSubobject<UInputReceiverComponent>(TEXT("Default Input Reciever"));
	bActivateOnStarted = true;
	
}

// Called when the game starts or when spawned
void AOmegaAbility::BeginPlay()
{
	Super::BeginPlay();

	Private_SetSoftTagsOnActor(GrantedActorOwnerTags, true);

	DefaultInputReceiver->OverrideInputOwner(CombatantOwner->GetOwner());
	//Bind Default Inputs
	if(bActivateOnStarted)
	{
		DefaultInputReceiver->OnInputStarted.AddDynamic(this, &AOmegaAbility::Native_InputTrigger);
	}
	if(bActivateOnTriggered)
	{
		DefaultInputReceiver->OnInputTriggered.AddDynamic(this, &AOmegaAbility::Native_InputTrigger);
	}
	if(bFinishOnInputComplete)
	{
		DefaultInputReceiver->OnInputCompleted.AddDynamic(this, &AOmegaAbility::CompleteAbility);
	}
	if(bFinishOnInputCancel)
	{
		DefaultInputReceiver->OnInputCancel.AddDynamic(this, &AOmegaAbility::CancelAbility);
	}
	
	GetGameInstance()->GetOnPawnControllerChanged().AddDynamic(this, &AOmegaAbility::TryAssignControlInput);


	if(CombatantOwner->GetOwnerPlayerController() && HudClass)
	{
		CombatantOwner->GetOwnerPlayerController()->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->AddHUDLayer(HudClass, this);
	}

	//COOLDOWN
	if(BeginInCooldown)
	{
		CooldownLerp = 0;
	}
	else
	{
		CooldownLerp = 1;
	}
	
	SetInputEnabledForOwner(true);

	CombatantOwner->OnCombatantNotify.AddDynamic(this, &AOmegaAbility::OnCombatantNotify);
	CombatantOwner->OnTargetAdded.AddDynamic(this, &AOmegaAbility::OnRegisteredTarget);
	CombatantOwner->OnTargetRemoved.AddDynamic(this, &AOmegaAbility::OnUnregisteredTarget);
	//CombatantOwner->OnDamaged.AddDynamic(this, &AOmegaAbility::OnDamaged);
	CombatantOwner->OnActiveTargetChanged.AddDynamic(this, &AOmegaAbility::OnActiveTargetChanged);
}



void AOmegaAbility::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason == EEndPlayReason::Destroyed && !GetWorld()->bIsTearingDown)
	{
		Private_SetSoftTagsOnActor(GrantedActorOwnerTags, false);
	
		if(CombatantOwner->GetOwnerPlayerController() && HudClass)
		{
			CombatantOwner->GetOwnerPlayerController()->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->RemoveHUDLayer(HudClass, "AbilityUngranted");
		}
	
		RecieveFinish(true);
	}
	Super::EndPlay(EndPlayReason);
}

void AOmegaAbility::TryAssignControlInput(APawn* Pawn, AController* Controller)
{
	if(Pawn == GetAbilityOwnerCharacter())
	{
		if(Cast<APlayerController>(Controller))
		{
			EnableInput(Cast<APlayerController>(Controller));
		}
	}
}

void AOmegaAbility::Native_AbilityActivated(UObject* Context)
{
	Local_TriggerEvents(EventsOnActivate);
	if(GetAbilityActivationTimeline())
	{
		GetAbilityActivationTimeline()->Play();
	}
	Private_SetSoftTagsOnActor(ActiveActorOwnerTags, true);

	if(bEnableInputOnActivation && GetAbilityOwnerPlayer())
	{
		EnableInput(GetAbilityOwnerPlayer());
	}
	AbilityActivated(Context);
}

void AOmegaAbility::Native_AbilityFinished(bool Cancelled)
{
	//EVENTS
	Local_TriggerEvents(EventsOnFinish);
	if(Cancelled)
	{
		Local_TriggerEvents(EventsOnCancel);
	}
	else
	{
		Local_TriggerEvents(EventsOnComplete);
	}
	
	if(GetAbilityActivationTimeline())
	{
		GetAbilityActivationTimeline()->Reverse();
	}
	
	Private_SetSoftTagsOnActor(ActiveActorOwnerTags, false);
	
	if(bEnableInputOnActivation && GetAbilityOwnerPlayer())
	{
		UE_LOG(LogTemp, Warning, TEXT("Some warning message") );
		DisableInput(GetAbilityOwnerPlayer());
	}
	
	AbilityFinished(Cancelled);
}

void AOmegaAbility::Native_ActivatedTick(float DeltaTime)
{
	ActivatedTick(DeltaTime);
}

bool AOmegaAbility::Native_CanActivate(UObject* Context)
{
	return CanActivate(Context);
}

// Called every frame
void AOmegaAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bIsActive)
	{
		Native_ActivatedTick(DeltaTime);
	}

	//COOLDOWN TICk
	if(!bIsActive && !IsAbilityInCooldown())
	{
		CooldownLerp  = UKismetMathLibrary::FInterpTo_Constant(CooldownLerp, 1.0, DeltaTime, 1/GetCooldownTime());
	}
}

void AOmegaAbility::Execute(UObject* Context)
{
	// Success if:
	if(!bIsActive																							// Ability is not already active
		&& !CombatantOwner->IsAbilityTagBlocked(AbilityTags)												// Ability tags are not blocked
		&& Native_CanActivate(Context) && !CombatantOwner->CombatantHasAnyTag(RestrictedOwnerTags)				// Combatant does not have any restricted tags
		&& (CombatantOwner->CombatantHasAllTag(RequiredOwnerTags) || RequiredOwnerTags.IsEmpty())			// Combatant has all required tags.
		&& !IsAbilityInCooldown()																			// Is Ability In Cooldown?
		)
	{
		UE_LOG(LogTemp, Warning, TEXT("Valid Execute"));
		bIsActive = true;
		CombatantOwner->CancelAbilitiesWithTags(CancelAbilities);
		CombatantOwner->CancelAbilitiesWithTags(BlockAbilities);
		CombatantOwner->SetAbilityActive(true, this);

		// TIMLEINE
		if(GetAbilityActivationTimeline())
		{
			GetAbilityActivationTimeline()->Play();
		}
		if(!Context)
		{
			Context = nullptr;
		}
		Native_AbilityActivated(Context);
	}
}

void AOmegaAbility::Native_Execute()
{
	UE_LOG(LogTemp, Warning, TEXT("Try Execute"));
	Execute(ContextObject);
}

void AOmegaAbility::Native_InputTrigger()
{
	if(FlipFlopInput && bIsActive)
	{
		CompleteAbility();
	}
	else
	{
		Native_Execute();
	}
}

////Local Activate / Deactivate

bool AOmegaAbility::CanActivate_Implementation(const UObject* Context)
{
	return true;
}


bool AOmegaAbility::SetInputEnabledForOwner(bool Enabled)
{
	APlayerController* TempController;
	if(GetAbilityOwnerCharacter() && Cast<APlayerController>(GetAbilityOwnerCharacter()->GetController()))
	{
		TempController = Cast<APlayerController>(GetAbilityOwnerCharacter()->GetController());
		if(Enabled)
		{
			EnableInput(TempController);
			return true;
		}
		else
		{
			DisableInput(TempController);
			return true;
		}
	}
	else
	{
		return false;
	}
}

void AOmegaAbility::CompleteAbility()
{
	RecieveFinish(false);
}

void AOmegaAbility::CancelAbility()
{
	RecieveFinish(true);
}

ACharacter* AOmegaAbility::GetAbilityOwnerCharacter()
{
	return CachedCharacter;
}

APlayerController* AOmegaAbility::GetAbilityOwnerPlayer()
{
	return CombatantOwner->GetOwnerPlayerController();
}

UCharacterMovementComponent* AOmegaAbility::GetAbilityOwnerCharacterMoveComponent()
{
	TempMoveComp = CachedCharacter->GetMovementComponent();
	if (TempMoveComp)
	{
		return Cast<UCharacterMovementComponent>(TempMoveComp);
	}
	else
	{
		return nullptr;
	}
	
}

USkeletalMeshComponent* AOmegaAbility::GetAbilityOwnerMesh()
{
	if (CachedCharacter)
	{
		return CachedCharacter->GetMesh();
	}
	else
	{
		return nullptr;
	}
}

void AOmegaAbility::AddBlockedAbilityTags(FGameplayTagContainer AddedTags)
{
	TArray<FGameplayTag> TagList;
	AddedTags.GetGameplayTagArray(TagList);
	for (FGameplayTag TempTag : TagList)
	{
		BlockAbilities.AddTag(TempTag);
	}
}

void AOmegaAbility::RemoveBlockedAbilityTags(FGameplayTagContainer RemovedTags)
{
	TArray<FGameplayTag> TagList;
	RemovedTags.GetGameplayTagArray(TagList);
	for (FGameplayTag TempTag : TagList)
	{
		BlockAbilities.RemoveTag(TempTag);
	}
}

//------------------//
/// COOLDOWN
//------------------//
bool AOmegaAbility::IsAbilityInCooldown() const
{
	return CooldownLerp < 1;
}

void AOmegaAbility::GetRemainingCooldownValues(float& Normalized, float& Seconds)
{
	Normalized = CooldownLerp;
	Seconds = GetCooldownTime()/CooldownLerp;
}

/////////////////////
///Input
/////////////////////

//Finish Ability
void AOmegaAbility::RecieveFinish(bool bCancel)
{
	if (bIsActive && !GetWorld()->bIsTearingDown)
	{
		bIsActive = false;
		CombatantOwner->SetAbilityActive(false, this);
		Native_AbilityFinished(bCancel);
		OnAbilityFinished.Broadcast(bCancel);
		// TIMLEINE
		if(GetAbilityActivationTimeline())
		{
			GetAbilityActivationTimeline()->Reverse();
		}
	}
}

void AOmegaAbility::Local_TriggerEvents(TArray<FName> Events)
{
	for(FName TempEv : Events)
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireGlobalEvent(TempEv, this);
	}
}
	


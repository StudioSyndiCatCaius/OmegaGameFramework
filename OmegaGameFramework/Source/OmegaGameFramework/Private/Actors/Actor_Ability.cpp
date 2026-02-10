// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/Actor_Ability.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_InputReceiver.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Components/TimelineComponent.h"
#include "Condition/Condition_Actor.h"
#include "Functions/F_TagEvent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/Subsystem_Player.h"
#include "Engine/GameInstance.h"
#include "Functions/F_Component.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Gameplay.h"
#include "Widget/HUDLayer.h"

bool UOmegaAbilityConfig::L_CanActivate(AOmegaAbility* ability, UObject* Context) const
{
	if(ability)
	{
		FOmegaConditions_Actor con;
		con.Conditions=OwnerConditions_CanActivate;
		if(!con.CheckConditions(ability->CombatantOwner->GetOwner()))
		{
			return false;
		}
		
		UOmegaGameplaySubsystem* sys=ability->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
		if(!sys->IsSystemTagActive(Required_SystemTags) && !Required_SystemTags.IsEmpty())
		{
			return false;
		}
		if(!Restricted_SystemTags.IsEmpty() && sys->IsSystemTagActive(Restricted_SystemTags) )
		{
			return false;
		}
	}
	return true;
}

void UOmegaAbilityConfig::L_OnActivate(AOmegaAbility* ability, UObject* Context) const
{
	if(ability)
	{
		FActorModifiers m;
		m.Script=Modifiers_OnActivate;
		m.ApplyMods(ability->CombatantOwner->GetOwner());
	}
}

void UOmegaAbilityConfig::L_OnFinish(AOmegaAbility* ability, UObject* Context, bool cancelled) const
{
	if(ability)
	{
		FActorModifiers m;
		m.Script=Modifiers_OnFinish;
		m.ApplyMods(ability->CombatantOwner->GetOwner());
	}
}

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

	OGF_Actor::SetTagsActive(GetOwner(),GrantedActorOwnerTags,false);

	DefaultInputReceiver->OverrideInputOwner(CombatantOwner->GetOwner());
	//Bind Default Inputs
	if(bActivateOnStarted)
	{
		DefaultInputReceiver->OnInputStarted.AddDynamic(this, &AOmegaAbility::L_OnInput_Start);
	}
	if(bActivateOnTriggered)
	{
		//DefaultInputReceiver->OnInputTriggered.AddDynamic(this, &AOmegaAbility::Native_InputTrigger);
	}
	if(bFinishOnInputComplete)
	{
		DefaultInputReceiver->OnInputCompleted.AddDynamic(this, &AOmegaAbility::L_OnInput_End);
	}
	if(bFinishOnInputCancel)
	{
	//	DefaultInputReceiver->OnInputCompleted.AddDynamic(this, &AOmegaAbility::L_OnInput_End);
	}
	
	GetGameInstance()->GetOnPawnControllerChanged().AddDynamic(this, &AOmegaAbility::TryAssignControlInput);
	
	if(CombatantOwner->GetOwnerPlayerController() && HudClass)
	{
		CombatantOwner->GetOwnerPlayerController()->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->AddHUDLayer(HudClass, this);
	}

	//COOLDOWN
	if(BeginInCooldown)
	{
		f_cooldownTime = 1;
	}
	else
	{
		f_cooldownTime = 0;
	}
	
	SetInputEnabledForOwner(true);

	DefaultInputReceiver->BindToPawn(GetAbilityOwnerCharacter());
	
	CombatantOwner->OnCombatantNotify.AddDynamic(this, &AOmegaAbility::OnCombatantNotify);
	CombatantOwner->OnTargetAdded.AddDynamic(this, &AOmegaAbility::OnRegisteredTarget);
	//CombatantOwner->OnDamaged.AddDynamic(this, &AOmegaAbility::OnDamaged);
	CombatantOwner->OnActiveTargetChanged.AddDynamic(this, &AOmegaAbility::OnActiveTargetChanged);
}



void AOmegaAbility::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason == EEndPlayReason::Destroyed && !GetWorld()->bIsTearingDown)
	{
		OGF_Actor::SetTagsActive(GetOwner(),GrantedActorOwnerTags,false);
	
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

void AOmegaAbility::Local_SetInputEnabled(bool Enabled)
{
	if(GetAbilityOwnerPlayer())
	{
		if(Enabled)
		{
			EnableInput(GetAbilityOwnerPlayer());
		}
		else
		{
			DisableInput(GetAbilityOwnerPlayer());
		}
	}
}

void AOmegaAbility::Native_AbilityActivated(UObject* Context)
{
	if(Config)
	{
		Config->L_OnActivate(this,Context);
	}
	if(GetAbilityActivationTimeline())
	{
		GetAbilityActivationTimeline()->Play();
	}
	OGF_Actor::SetTagsActive(GetOwner(),ActiveActorOwnerTags,true);
	
	if(bEnableInputOnActivation && GetAbilityOwnerPlayer())
	{
		EnableInput(GetAbilityOwnerPlayer());
	}
	AbilityActivated(Context);
}

void AOmegaAbility::Native_AbilityFinished(bool Cancelled)
{
	if(Config)
	{
		Config->L_OnFinish(this,ContextObject,Cancelled);
	}
	
	if(GetAbilityActivationTimeline())
	{
		GetAbilityActivationTimeline()->Reverse();
	}

	OGF_Actor::SetTagsActive(GetOwner(),ActiveActorOwnerTags,false);
	
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
	if(bIsActive) { return false; }
	if(Config && !Config->L_CanActivate(this,Context))
	{
		return false;
	}
	if(CombatantOwner)
	{
		// is in cooldown
		if(IsAbilityInCooldown()) { return false; }

		// ability tags are blocked
		if(!AbilityTags.IsEmpty() && CombatantOwner->IsAbilityTagBlocked(AbilityTags)) { return false; }
		
		// Doesn't have required tags
		if(!RequiredOwnerTags.IsEmpty() && !CombatantOwner->CombatantHasAllTag(RequiredOwnerTags)) { return false; }
		
		// Has restricted owner tags
		if(!RestrictedOwnerTags.IsEmpty() && CombatantOwner->CombatantHasAnyTag(RestrictedOwnerTags)) { return false; }

		return CanActivate(Context);
	}
	return false;
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
	if(!bIsActive && IsAbilityInCooldown())
	{
		f_cooldownTime-=DeltaTime;
	}
}

void AOmegaAbility::L_OnInput_Start(FVector Value)
{
	Execute(nullptr);
}

void AOmegaAbility::L_OnInput_End(FVector Value)
{
	CompleteAbility();
}

bool AOmegaAbility::Execute(UObject* Context)
{
	// Success if:
	if(Native_CanActivate(Context))
	{
		CombatantOwner->CancelAbilitiesWithTags(CancelAbilities);
		CombatantOwner->CancelAbilitiesWithTags(BlockAbilities);
		
		ContextObject=Context;
		if(!Context)
		{
			ContextObject = nullptr;
		}
		bIsActive = true;
		UActorTagEventFunctions::FireTagEventsOnActor(CombatantOwner->GetOwner(),OwnerEventsOnActivate);
		
		// TIMLEINE
		if(GetAbilityActivationTimeline())
		{
			GetAbilityActivationTimeline()->Play();
		}
		Native_AbilityActivated(Context);
		return true;
	}
	return false;
}

bool AOmegaAbility::Native_Execute() 
{
	return Execute(ContextObject);
}

void AOmegaAbility::Native_Start()
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
	return ref_character;
}

APlayerController* AOmegaAbility::GetAbilityOwnerPlayer()
{
	return CombatantOwner->GetOwnerPlayerController();
}

UCharacterMovementComponent* AOmegaAbility::GetAbilityOwnerCharacterMoveComponent()
{
	if(!ref_character)
	{
		return nullptr;
	}
	rev_moveComp = ref_character->GetMovementComponent();
	if (rev_moveComp)
	{
		return Cast<UCharacterMovementComponent>(rev_moveComp);
	}
	else
	{
		return nullptr;
	}
	
}

USkeletalMeshComponent* AOmegaAbility::GetAbilityOwnerMesh()
{
	if (ref_character)
	{
		return ref_character->GetMesh();
	}
	else
	{
		return nullptr;
	}
}

//------------------//
/// COOLDOWN
//------------------//
bool AOmegaAbility::IsAbilityInCooldown() const
{
	return f_cooldownTime > 0.0;
}

void AOmegaAbility::GetRemainingCooldownValues(float& Normalized, float& Seconds)
{
	Normalized = f_cooldownTime;
	Seconds = GetCooldownTime()/f_cooldownTime;
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
		Native_AbilityFinished(bCancel);
		OnAbilityFinished.Broadcast(bCancel);

		UActorTagEventFunctions::FireTagEventsOnActor(CombatantOwner->GetOwner(),OwnerEventsOnFinish);
		// TIMLEINE
		if(GetAbilityActivationTimeline())
		{
			GetAbilityActivationTimeline()->Reverse();
		}
		f_cooldownTime=GetCooldownTime();
	}
}

void AOmegaAbility::Local_TriggerEvents(TArray<FName> Events)
{
	for(FName TempEv : Events)
	{
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireGlobalEvent(TempEv, this, FOmegaCommonMeta());
	}
}
	


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
#include "Subsystems/Subsystem_World.h"
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
		
		UOmegaSubsystem_World* sys=ability->GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
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

void AOmegaAbility::L_Log(const FString& str)
{
	OGF_Log::LogWarning("ABILITY"+GetName()+" On actor "+CombatantOwner->GetOwner()->GetName()+" -- "+str);
}

// Sets default values
AOmegaAbility::AOmegaAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
	
}

// Called when the game starts or when spawned
void AOmegaAbility::BeginPlay()
{
	Super::BeginPlay();
	
	
	GetGameInstance()->GetOnPawnControllerChanged().AddDynamic(this, &AOmegaAbility::TryAssignControlInput);
	
	if(CombatantOwner->GetOwnerPlayerController() && HudClass)
	{
		CombatantOwner->GetOwnerPlayerController()->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->AddHUDLayer(HudClass, this);
	}
	
	
	SetInputEnabledForOwner(true);
	
	
	CombatantOwner->OnCombatantNotify.AddDynamic(this, &AOmegaAbility::OnCombatantNotify);
	CombatantOwner->OnTargetAdded.AddDynamic(this, &AOmegaAbility::OnRegisteredTarget);
	//CombatantOwner->OnDamaged.AddDynamic(this, &AOmegaAbility::OnDamaged);
	CombatantOwner->OnActiveTargetChanged.AddDynamic(this, &AOmegaAbility::OnActiveTargetChanged);
	
	SetSubstate_Index(0);
}



void AOmegaAbility::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason == EEndPlayReason::Destroyed && !GetWorld()->bIsTearingDown)
	{
	
		if(CombatantOwner->GetOwnerPlayerController() && HudClass)
		{
			CombatantOwner->GetOwnerPlayerController()->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>()->RemoveHUDLayer(HudClass, "AbilityUngranted");
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
	
	
	if(bEnableInputOnActivation && GetAbilityOwnerPlayer())
	{
		UE_LOG(LogTemp, Warning, TEXT("Some warning message") );
		DisableInput(GetAbilityOwnerPlayer());
	}
	f_cooldownTime=CooldownTime;
	AbilityFinished(Cancelled);
}

void AOmegaAbility::Native_ActivatedTick(float DeltaTime)
{
	ActivatedTick(DeltaTime);
}

bool AOmegaAbility::Native_CanActivate(UObject* Context)
{
	if(bIsActive) { return false; }
	/*
	if(Config && !Config->L_CanActivate(this,Context))
	{
		return false;
	}
	*/
	if(CombatantOwner)
	{
		// is in cooldown
		if(IsAbilityInCooldown())
		{
			L_Log(" Failed to activate :: In cooldown");
			return false;
		}

		// ability tags are blocked
		if(!AbilityTags.IsEmpty() && CombatantOwner->IsAbilityTagBlocked(AbilityTags))
		{
			L_Log(" Failed to activate :: Ability Tag Blocked");
			return false;
		}
		
		// Doesn't have required tags
		if(!RequiredOwnerTags.IsEmpty() && !CombatantOwner->CombatantHasAllTag(RequiredOwnerTags))
		{
			L_Log(" Failed to activate :: Combatant Does not have required tag");
			return false;
		}
		
		// Has restricted owner tags
		if(!RestrictedOwnerTags.IsEmpty() && CombatantOwner->CombatantHasAnyTag(RestrictedOwnerTags))
		{
			L_Log(" Failed to activate :: Combatant has restricted tag");
			return false;
		}

		if (CanActivate(Context))
		{
			return true;
		}
		L_Log(" Failed to activate :: Blocked from blueprint function 'CanActivate'");
		return false;
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

USkeletalMeshComponent* AOmegaAbility::GetAbilityOwnerMesh() const
{
	if (CombatantOwner->Override_AbilitySkelMesh)
	{
		return CombatantOwner->Override_AbilitySkelMesh;
	}
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
	Seconds = f_cooldownTime/f_cooldownTime;
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
		
		// TIMLEINE
		if(GetAbilityActivationTimeline())
		{
			GetAbilityActivationTimeline()->Reverse();
		}
	}
}

void AOmegaAbility::SetSubstate_Name(FName State)
{
	if (Substates.Contains(State))
	{
		SetSubstate_Index(Substates.Find(State));
	}
}

void AOmegaAbility::SetSubstate_Index(int32 State)
{
	if (State!=Substate)
	{
		int32 OldState=Substate;
		Substate=State;
		
		OnSubstateChange(State,GetSubstate_NameFromIndex(State),OldState,GetSubstate_NameFromIndex(OldState));
	}
}

FName AOmegaAbility::GetSubstate_NameFromIndex(int32 index) const
{
	if (Substates.IsValidIndex(index))
	{
		return Substates[index];
	}
	return FName();
}


void AOmegaAbility::Local_TriggerEvents(TArray<FName> Events)
{
	for(FName TempEv : Events)
	{
		OGF_Subsystems::oGameInstance(this)->FireGlobalEvent(TempEv, this, FOmegaCommonMeta());
	}
}
	


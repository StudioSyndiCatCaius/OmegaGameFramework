// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/OmegaGameplaySystem.h"
#include "Engine/GameInstance.h"
#include "Functions/F_Common.h"
#include "Subsystems/Subsystem_Gameplay.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_Save.h"
#include "EnhancedInputSubsystems.h"
#include "OmegaSettings.h"
#include "OmegaSettings_Global.h"
#include "Actors/Actor_Player.h"
#include "Components/Component_Combatant.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/GeneralDataObject.h"
#include "Subsystems/Subsystem_Actors.h"
#include "Subsystems/Subsystem_Message.h"

void AOmegaBaseSystem::L_CleanupStateChange(bool state)
{
	if(state)
	{
		
	}
	else
	{
		
	}
}

TArray<APlayerController*> AOmegaBaseSystem::L_GetPlayers()
{
	TArray<APlayerController*>out;
	TArray <AActor*> FoundPlayers;
	UGameplayStatics::GetAllActorsOfClass(this, APlayerController::StaticClass(), FoundPlayers);
	for(auto* a : FoundPlayers)
	{
		if(APlayerController* p =Cast<APlayerController>(a))
		{
			out.Add(p);
		}
	}
	return out;
}

// Sets default values
AOmegaBaseSystem::AOmegaBaseSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
	//bIsSpatiallyLoaded = false;
}

void AOmegaBaseSystem::Native_Activate(UObject* Context, const FString& Flag)
{
	GetMutableDefault<UOmegaSettings>()->GetGlobalSettings()->OnGameplaySystem_Activate(this,Context,Flag);
	SystemActivated(Context, Flag);
}

// Called when the game starts or when spawned
void AOmegaBaseSystem::BeginPlay()
{
	l_subsys_sav=GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	l_subsys_qquery=GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueueEvents>();
	///ATTACH TO GAME MODE
	if(!GetAttachParentActor())
	{
		if(!GetOwner())
		{
			SetOwner(UGameplayStatics::GetGameMode(this));
		}
		AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
	}
	L_CleanupStateChange(true);
	
	//Get Players


	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnGlobalEvent.AddDynamic(this, &AOmegaBaseSystem::OnGlobalEvent);
	GetGameInstance()->GetSubsystem<UOmegaGameManager>()->OnTaggedGlobalEvent.AddDynamic(this, &AOmegaBaseSystem::OnTaggedGlobalEvent);
	GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->OnNewGameStarted.AddDynamic(this, &AOmegaBaseSystem::OnNewGameStarted);
	GetGameInstance()->GetSubsystem<UOmegaMessageSubsystem>()->OnGameplayMessage.AddDynamic(this, &AOmegaBaseSystem::OnGameplayMessage);
	
	GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueueEvents>()->SetQueuedDelaySourceRegistered(this,true);
	
	if(UOmegaSubsystem_QueueEvents* REF_QuerySubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueueEvents>()) 
	{ 
		REF_QuerySubsystem->SetQueuedQuerySourceRegistered(this,true); 
	} 

	//Setup Actor event bindings
	UOmegaActorSubsystem* sub_a=GetWorld()->GetSubsystem<UOmegaActorSubsystem>();
	sub_a->OnActorTagEvent.AddDynamic(this,&AOmegaBaseSystem::OnActor_TagEvent);
	sub_a->OnActorInteraction.AddDynamic(this,&AOmegaBaseSystem::OnActor_Interaction);
	sub_a->OnActorGroupChange.AddDynamic(this,&AOmegaBaseSystem::OnActor_RegisteredToGroup);
	sub_a->OnActorIdentityRegistered.AddDynamic(this,&AOmegaBaseSystem::OnActor_IdentityRegistered);
	
	for (APlayerController* P : L_GetPlayers())
	{
		//Add New Widgets To Player Screen
		for (const TSubclassOf <UHUDLayer>& TempWidgetClass : local_GetAllHudClasses())
		{
			UOmegaPlayerSubsystem* LocalSystem = P->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
			UHUDLayer* CreatedLayer = LocalSystem->AddHUDLayer(TempWidgetClass, this,WidgetsOnPlayerScreen);
			ActivePlayerWidgets.Add(CreatedLayer);
		}
		//Set Input Mode
		if(PlayerInputMode)
		{
			P->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SetCustomInputMode(PlayerInputMode);
		}
		// Add New Mapping Context
		for(UInputMappingContext* TempMap : AddPlayerInputMapping)
		{
			Cast<APlayerController>(P)->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()->AddMappingContext(TempMap, InputPriority);
		}
	}

	UOmegaGameplaySubsystem* GameplaySubsys = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();

	GameplaySubsys->OnGameplayStateChange.AddDynamic(this, &AOmegaBaseSystem::OnGameplayStateChange);
	
	//GRANT ABILITIES
	for(auto* TempComb : GameplaySubsys->GetAllCombatants())
	{
		Local_GrantAbilities(TempComb);
	}
	GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->OnCombatantRegistered.AddDynamic(this, &AOmegaBaseSystem::Local_GrantAbilities);

	//FLAGS
	Local_SetFlagsActive(true);

	//SetupSave
	GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->SetSaveSourceRegistered(this,true);
	local_globalEventTags(GlobalEvents_OnActivate);
	Super::BeginPlay();
}

void AOmegaBaseSystem::Destroyed()
{
	Super::Destroyed();
}

void AOmegaBaseSystem::Local_SetFlagsActive(bool State)
{
	for(const auto& LocalFlag : ActiveFlags)
	{
		GetGameInstance()->GetSubsystem<UOmegaGameManager>()->SetFlagActive(LocalFlag, State);
	}
}

// =============================================================================================================
// =============================================================================================================
// Gameplay
// =============================================================================================================
// =============================================================================================================


void AOmegaGameplaySystem::L_CleanupStateChange(bool state)
{
	if(UOmegaGameplaySubsystem* SubsysRef=GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>())
	{
		if(state)
		{
			SubsysRef->OnGameplaySystemActiveStateChange.Broadcast(this,Shutdown_Context,Shutdown_Flag,true);
		}
		else
		{
			SubsysRef->OnGameplaySystemActiveStateChange.Broadcast(this,Shutdown_Context,Shutdown_Flag,false);
		}
		
	}
}

void AOmegaPlayerSystem::BeginPlay()
{
	if(AOmegaPlayer* p =GetSystemOwningPlayer())
	{
		EnableInput(p);
	}
	Super::BeginPlay();
}

AOmegaPlayerSystem::AOmegaPlayerSystem()
{
	WidgetsOnPlayerScreen=true;
}

TArray<APlayerController*> AOmegaPlayerSystem::L_GetPlayers()
{
	TArray<APlayerController*> out;
	if(AOmegaPlayer* p=GetSystemOwningPlayer())
	{
		out.Add(p);
	}
	return out;
}


// =============================================================================================================
// =============================================================================================================
// PLAYER
// =============================================================================================================
// =============================================================================================================


void AOmegaPlayerSystem::L_CleanupStateChange(bool state)
{
	if(AOmegaPlayer* p=GetSystemOwningPlayer())
	{
		if(state)
		{
			//SubsysRef->OnGameplaySystemActiveStateChange.Broadcast(this,Shutdown_Context,Shutdown_Flag,true);
		}
		else
		{
			//SubsysRef->OnGameplaySystemActiveStateChange.Broadcast(this,Shutdown_Context,Shutdown_Flag,false);
		}
		
	}
}

AOmegaPlayer* AOmegaPlayerSystem::GetSystemOwningPlayer() const
{
	if(GetOwner())
	{
		if(AOmegaPlayer* p=Cast<AOmegaPlayer>(GetOwner()))
		{
			return p;
		}
	}
	return nullptr;
}

// Called every frame
void AOmegaBaseSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOmegaBaseSystem::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	
}

void AOmegaBaseSystem::SystemShutdown_Implementation(UObject* Context, const FString& Flag)
{
	
}

void AOmegaBaseSystem::Shutdown(UObject* Context, FString Flag)
{
	// Block if already shutting down;
	if(bIsInShutdown)
	{
		return;
	}

	
	Shutdown_Context = nullptr;
	if(Context)
	{
		Shutdown_Context = Context;
	}
	Shutdown_Flag = Flag;
	
	bIsInShutdown = true;
	OnBeginShutdown(Shutdown_Context, Shutdown_Flag);
	
}

void AOmegaBaseSystem::OnBeginShutdown_Implementation(UObject* Context, const FString& Flag)
{
	CompleteShutdown();
}

void AOmegaBaseSystem::CompleteShutdown()
{
	if(bIsInShutdown)
	{
		TArray <AActor*> FoundPlayers;
		UGameplayStatics::GetAllActorsOfClass(this, APlayerController::StaticClass(), FoundPlayers);

		if(l_subsys_sav)
		{
			l_subsys_sav->SetSaveSourceRegistered(this,false);
		}
		if(l_subsys_sav)
		{
			l_subsys_qquery->SetQueuedQuerySourceRegistered(this,false);
		}
		// Remove Player Widgets
		for (class UHUDLayer* TempWidget : ActivePlayerWidgets)
		{
			if(TempWidget)
			{
				TempWidget->RemoveHUDLayer();
			}
		}
		OnSystemShutdown.Broadcast(Shutdown_Context, Shutdown_Flag);
		SystemShutdown(Shutdown_Context, Shutdown_Flag);
		L_CleanupStateChange(false);

		//Remove Mapping Context
		for (AActor* TempActor : FoundPlayers)
		{
			for(UInputMappingContext* TempMap : AddPlayerInputMapping)
			{
				Cast<APlayerController>(TempActor)->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()->RemoveMappingContext(TempMap);
			}
		}

		//Remove Abilities
		for(FGameplaySystemAbilityRules TempData : GrantedAbilities)
		{
			for(auto* TempComb : GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->GetAllCombatants())
			{
				TempComb->SetAbilityGranted(TempData.AbilityClass,true);
			}	
		}
		
		//FLAGS
		Local_SetFlagsActive(false);
		
		if(local_InRestart)
		{
			GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(GetClass(), ContextObject, ActivationFlag);
		}
		else
		{
			//Activate New Systems
			for(auto TempSys : SystemsActivatedOnShutdown)
			{
				if(TempSys)
				{
					GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(TempSys, this, this->GetFName().ToString());
				}
			}
		}
		local_globalEventTags(GlobalEvents_OnShutdown);
		GetMutableDefault<UOmegaSettings>()->GetGlobalSettings()->OnGameplaySystem_Shutdown(this);
		
		K2_DestroyActor();
	}
}

void AOmegaBaseSystem::OutputNotify(UObject* Context, const FString& Flag)
{
	GetMutableDefault<UOmegaSettings>()->GetGlobalSettings()->OnGameplaySystem_Notify(this,Context,Flag);
	OnSystemNotify.Broadcast(Context,Flag);
}

void AOmegaBaseSystem::Restart(UObject* Context, FString Flag)
{
	local_InRestart = true;
	Shutdown(Context,Flag);
}


AOmegaPlayer* AOmegaBaseSystem::GetSystemOwningPlayer() const
{
	if(GetWorld())
	{
		if(AOmegaPlayer* p=Cast<AOmegaPlayer>(GetWorld()->GetFirstPlayerController()))
		{
			return p;
		}
	}
	return nullptr;
}

void AOmegaBaseSystem::local_globalEventTags(FGameplayTagContainer tags)
{
	{
		for(FGameplayTag tempTag : tags.GetGameplayTagArray())
		{
			GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>()->FireTaggedGlobalEvent(tempTag,this);
		}
	}
}

void AOmegaBaseSystem::Local_GrantAbilities(UCombatantComponent* Combatant)
{
	if(Combatant)
	{
		for(FGameplaySystemAbilityRules TempData : GrantedAbilities)
		{
			const bool AcceptFaction = (TempData.AcceptedFactions.HasTag(Combatant->GetFactionTag()) || TempData.AcceptedFactions.IsEmpty());
			const bool AcceptTags = (Combatant->GetCombatantTags().MatchesQuery(TempData.AcceptedCombatantTags)) || (TempData.AcceptedCombatantTags.IsEmpty());

			if(AcceptFaction & AcceptTags)
			{
				Combatant->SetAbilityGranted(TempData.AbilityClass,true);
			}
		}
	}
}

// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/OmegaGameplaySystem.h"
#include "Engine/GameInstance.h"
#include "Functions/F_Common.h"
#include "Subsystems/Subsystem_World.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_Save.h"
#include "EnhancedInputSubsystems.h"
#include "OmegaSettings.h"
#include "OmegaGameManager.h"
#include "Actors/Actor_Player.h"
#include "Components/Component_Combatant.h"
#include "Functions/F_Player.h"
#include "GameFramework/Character.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaGameMode.h"


TArray<APlayerController*> AOmegaGameplaySystem::L_GetPlayers()
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
AOmegaGameplaySystem::AOmegaGameplaySystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
	RootComponent=CreateOptionalDefaultSubobject<USceneComponent>("Root");
	//bIsSpatiallyLoaded = false;
}

void AOmegaGameplaySystem::Native_Activate(UObject* Context, const FString& Flag)
{
	GetMutableDefault<UOmegaSettings>()->GetGameCore()->OnGameplaySystem_Activate(this,Context,Flag);
	SetSubstate_Index(0);
	SystemActivated(Context, Flag);
}

// Called when the game starts or when spawned
void AOmegaGameplaySystem::BeginPlay()
{
	Super::BeginPlay();

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

	SS_GI->OnGlobalEvent.AddDynamic(this, &AOmegaGameplaySystem::OnGlobalEvent);
	SS_GI->OnTaggedGlobalEvent.AddDynamic(this, &AOmegaGameplaySystem::OnTaggedGlobalEvent);
	SS_Save->OnNewGameStarted.AddDynamic(this, &AOmegaGameplaySystem::OnNewGameStarted);

	//Setup Actor event bindings
	SS_World->OnGameplayMessage_Begin.AddDynamic(this, &AOmegaGameplaySystem::OnGameplayMessage);
	SS_World->OnActorTagEvent.AddDynamic(this,&AOmegaGameplaySystem::OnActor_TagEvent);
	SS_World->OnActorInteraction.AddDynamic(this,&AOmegaGameplaySystem::OnActor_Interaction);
	SS_World->OnActorGroupChange.AddDynamic(this,&AOmegaGameplaySystem::OnActor_RegisteredToGroup);
	SS_World->OnActorIdentityRegistered.AddDynamic(this,&AOmegaGameplaySystem::OnActor_IdentityRegistered);
	
	for (APlayerController* P : L_GetPlayers())
	{
		if (P)
		{
			if (UOmegaSubsystem_Player* LocalSystem = P->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>())
			{
				//Add New Widgets To Player Screen
				for (const TSubclassOf <UHUDLayer>& TempWidgetClass : local_GetAllHudClasses())
				{
					UHUDLayer* CreatedLayer = LocalSystem->AddHUDLayer(TempWidgetClass, this,WidgetsOnPlayerScreen);
					ActivePlayerWidgets.Add(CreatedLayer);
				}
				//Set Input Mode
				if(PlayerInputMode)
				{
					LocalSystem->SetCustomInputMode(PlayerInputMode);
				}
				// Add New Mapping Context
				for(UInputMappingContext* TempMap : AddPlayerInputMapping)
				{
					Cast<APlayerController>(P)->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()->AddMappingContext(TempMap, InputPriority);
				}
			}
		}
		
	}
	
	//GRANT ABILITIES
	for(auto* TempComb : SS_World->GetAllCombatants())
	{
		Local_GrantAbilities(TempComb);
	}
	GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->OnCombatantRegistered.AddDynamic(this, &AOmegaGameplaySystem::Local_GrantAbilities);

	//FLAGS
	Local_SetFlagsActive(true);

	//SetupSave
	GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->SetSaveSourceRegistered(this,true);
	local_globalEventTags(GlobalEvents_OnActivate);
	
	UOmegaPlayerFunctions::SetInputActionTargetActive(GetSystemOwningPlayer(),this,true);
}

void AOmegaGameplaySystem::Destroyed()
{
	UOmegaPlayerFunctions::SetInputActionTargetActive(GetSystemOwningPlayer(),this,false);
	Super::Destroyed();
}

void AOmegaGameplaySystem::Local_SetFlagsActive(bool State)
{
	
}

AOmegaGameplaySystem* L_GetFirstTemplateSystem(UObject* outer, TSubclassOf<AOmegaGameplaySystem> sys)
{
	if (AOmegaGameMode* gm=Cast<AOmegaGameMode>(UGameplayStatics::GetGameMode(outer)))
	{
		if (AOmegaGameplaySystem* s =FOmegaGameplaySystemConfig::GetConfigTemplate_System(gm->System_Config,sys))
		{
			return s;
		}
	}
	if (AOmegaGameplaySystem* s=FOmegaGameplaySystemConfig::GetConfigTemplate_System(OGF_GAME_CORE()->System_Config,sys))
	{
		return s;			
	}
	return nullptr;
}


AOmegaGameplaySystem* FOmegaBaseSystemStats::Activate(TSubclassOf<AOmegaGameplaySystem> sys, UObject* Context,
	const FString& Flag, UObject* WorldC, AActor* owner, FOmegaCommonMeta meta)
{
	
	if(!WorldC || !sys)
	{
		//UE_LOG(LogTemp, Log, TEXT("Failed to active system: World or SystemClass invalid"));
		return nullptr;
	}
	if(CanActivateSystem(sys))
	{
		FTransform SpawnWorldPoint;
		if(owner)
		{
			SpawnWorldPoint=owner->GetActorTransform();
		}
		FActorSpawnParameters params;
		
		if (AOmegaGameplaySystem* s= L_GetFirstTemplateSystem(WorldC, sys))
		{
			params.Template=s;			
		}
		params.Owner=owner;
		
		AOmegaGameplaySystem* DummySystem = WorldC->GetWorld()->SpawnActor<AOmegaGameplaySystem>(sys, SpawnWorldPoint,params);
		if(!DummySystem)
		{
			UE_LOG(LogTemp, Log, TEXT("Failed to Spawn system Actor: %s "), *sys->GetName());
			return nullptr;
		}
		if (DummySystem && !DummySystem->IsActorInitialized())
		{
			DummySystem->FinishSpawning(SpawnWorldPoint);	
		}
		active_systems.Add(DummySystem);
		if(Context)
		{
			DummySystem->ContextObject = Context;
		}
		DummySystem->ActivationFlag=Flag;
		DummySystem->SystemMeta=meta;
		Validate();
		DummySystem->Native_Activate(Context, Flag);
		UE_LOG(LogTemp, Log, TEXT("System %s - Successfully Activated "), *DummySystem->GetName());
		return DummySystem;
	}
	return nullptr;
}

// =============================================================================================================
// =============================================================================================================
// Gameplay
// =============================================================================================================
// =============================================================================================================


void AOmegaGameplaySystem::L_CleanupStateChange(bool state)
{
	if(UOmegaSubsystem_World* SubsysRef=GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
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


void AOmegaGameplaySystem::SetSubstate_Name(FName State)
{
	if (Substates.Contains(State))
	{
		SetSubstate_Index(Substates.Find(State));
	}
}

void AOmegaGameplaySystem::SetSubstate_Index(int32 State)
{
	if (State!=Substate)
	{
		int32 OldState=Substate;
		Substate=State;
		
		OnSubstateChange(State,GetSubstate_NameFromIndex(State),OldState,GetSubstate_NameFromIndex(OldState));
	}
}

FName AOmegaGameplaySystem::GetSubstate_NameFromIndex(int32 index) const
{
	if (Substates.IsValidIndex(index))
	{
		return Substates[index];
	}
	return FName();
}

// Called every frame
void AOmegaGameplaySystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOmegaGameplaySystem::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	
}

void AOmegaGameplaySystem::SystemShutdown_Implementation(UObject* Context, const FString& Flag)
{
	
}

void AOmegaGameplaySystem::Shutdown(UObject* Context, FString Flag)
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

void AOmegaGameplaySystem::OnBeginShutdown_Implementation(UObject* Context, const FString& Flag)
{
	CompleteShutdown();
}

void AOmegaGameplaySystem::CompleteShutdown()
{
	if(bIsInShutdown)
	{
		TArray <AActor*> FoundPlayers;
		UGameplayStatics::GetAllActorsOfClass(this, APlayerController::StaticClass(), FoundPlayers);

		if(SS_Save)
		{
			SS_Save->SetSaveSourceRegistered(this,false);
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
		
		
		//FLAGS
		Local_SetFlagsActive(false);
		
		if(local_InRestart)
		{
			GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->ActivateGameplaySystem(GetClass(), ContextObject, ActivationFlag);
		}
		else
		{
			
		}
		local_globalEventTags(GlobalEvents_OnShutdown);
		GetMutableDefault<UOmegaSettings>()->GetGameCore()->OnGameplaySystem_Shutdown(this);
		
		K2_DestroyActor();
	}
}

void AOmegaGameplaySystem::OutputNotify(UObject* Context, const FString& Flag)
{
	GetMutableDefault<UOmegaSettings>()->GetGameCore()->OnGameplaySystem_Notify(this,Context,Flag);
	OnSystemNotify.Broadcast(Context,Flag);
}

void AOmegaGameplaySystem::Restart(UObject* Context, FString Flag)
{
	local_InRestart = true;
	Shutdown(Context,Flag);
}


AOmegaPlayer* AOmegaGameplaySystem::GetSystemOwningPlayer() const
{
	if(GetOwner())
	{
		if(AOmegaPlayer* p=Cast<AOmegaPlayer>(GetOwner()))
		{
			return p;
		}
	}
	if(GetWorld())
	{
		if(AOmegaPlayer* p=Cast<AOmegaPlayer>(GetWorld()->GetFirstPlayerController()))
		{
			return p;
		}
	}
	return nullptr;
}

APawn* AOmegaGameplaySystem::GetSystemOwningPlayer_Pawn() const
{
	if (!GetSystemOwningPlayer()) { return nullptr;}
	if (APawn* p =Cast<APawn>(GetSystemOwningPlayer()->K2_GetPawn()))
	{
		return p;
	}
	return nullptr;
}

ACharacter* AOmegaGameplaySystem::GetSystemOwningPlayer_Character() const
{
	if (GetSystemOwningPlayer())
	{
		if (ACharacter* p =Cast<ACharacter>(GetSystemOwningPlayer()->K2_GetPawn()))
		{
			return p;
		}
	}
	return nullptr;
}

UCombatantComponent* AOmegaGameplaySystem::GetSystemOwningPlayer_Combatant() const
{
	if (APawn* p =GetSystemOwningPlayer_Pawn())
	{
		if (UCombatantComponent* c=Cast<UCombatantComponent>(p->GetComponentByClass(UCombatantComponent::StaticClass())))
		{
			return c;
		}
	}
	return nullptr;
}

void AOmegaGameplaySystem::local_globalEventTags(FGameplayTagContainer tags)
{
	for(FGameplayTag tempTag : tags.GetGameplayTagArray())
	{
		SS_GI->FireTaggedGlobalEvent(tempTag,this, FOmegaCommonMeta());
	}
}

void AOmegaGameplaySystem::Local_GrantAbilities(UCombatantComponent* Combatant)
{
	if(Combatant)
	{
		
	}
}

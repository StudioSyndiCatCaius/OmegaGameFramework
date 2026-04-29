// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/Subsystem_World.h"

#include <string>

#include "Actors/OmegaGameplaySystem.h"
#include "DataAssets/DA_Zone.h"

#include "Engine/World.h"
#include "EngineUtils.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "LuaSettings.h"
#include "MetasoundSource.h"
#include "OmegaGameplayConfig.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "OmegaSettings.h"
#include "OmegaGameManager.h"
#include "Actors/Actor_Null.h"
#include "Actors/Actor_Quest.h"
#include "Actors/Actor_Zone.h"
#include "Components/AudioComponent.h"
#include "Components/Component_GameplayActor.h"
#include "Components/Component_AssetSquad.h"
#include "Components/Component_Combatant.h"
#include "DataAssets/DA_BGM.h"
#include "Functions/F_Combatant.h"
#include "Functions/F_Common.h"
#include "Functions/F_Entity.h"
#include "Functions/F_GlobalParam.h"
#include "Functions/F_Level.h"
#include "Functions/F_Save.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Save.h"
#include "Types/OmegaActorInstanceMetadata.h"


void UOmegaSubsystem_World::Initialize(FSubsystemCollectionBase& Colection)
{
	SystemsData.active_systems.Empty();
	WorldManager = nullptr;
	GetWorldManager();
}

void UOmegaSubsystem_World::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	UOmegaSaveSubsystem* _sys=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	FString level_name=UGameplayStatics::GetCurrentLevelName(_sys);
	
	//Setup World manager
	// Try to find existing world manager
	UWorld* World = GetWorld();
	if (World)
	{
		if (AOmegaWorldManager* m = Cast<AOmegaWorldManager>(UGameplayStatics::GetActorOfClass(World, AOmegaWorldManager::StaticClass())))
		{
			WorldManager = m;
		}
		// If not found, spawn one
		if (!WorldManager.IsValid())
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Name = FName(TEXT("OmegaWorldManager"));
			SpawnParams.NameMode = FActorSpawnParameters::ESpawnActorNameMode::Required_ReturnNull;
			TSubclassOf<AOmegaWorldManager> in_class=AOmegaWorldManager::StaticClass();
			if (TSubclassOf<AOmegaWorldManager> mc=OGF_CFG()->WorldManagerClass.LoadSynchronous())
			{
				in_class=mc;
			}
			WorldManager = World->SpawnActor<AOmegaWorldManager>(in_class,SpawnParams);
		}
	}
	
	
	for(auto* TempState : _sys->GetActiveStoryStates())
	{
		for(auto* TempScript : TempState->Scripts)
		{
			TempScript->OnLevelChange(_sys, TempState,level_name);
		}
	}
	
	UOmegaSettings* _set=GetMutableDefault<UOmegaSettings>();
}

AOmegaGameplaySystem* UOmegaSubsystem_World::ActivateGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context, FString Flag,FOmegaCommonMeta meta)
{
	if (Class)
	{
		TSubclassOf<AOmegaGameplaySystem> _InClass=GetMutableDefault<UOmegaSettings>()->CorrectClass_System(Class);
		
		if(AOmegaGameplaySystem* DummySystem=Cast<AOmegaGameplaySystem>(SystemsData.Activate(_InClass,Context,Flag,this,nullptr,meta)))
		{
			OnGameplaySystemActiveStateChange.Broadcast(DummySystem,Context,Flag,true);
			return DummySystem;
		}
	}
	return nullptr;
}

bool UOmegaSubsystem_World::ShutdownGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context, FString Flag)
{
	bool bIsActive = false;
	TSubclassOf<AOmegaGameplaySystem> _InClass=GetMutableDefault<UOmegaSettings>()->CorrectClass_System(Class);
	AOmegaGameplaySystem* TempSystem = GetGameplaySystem(_InClass, bIsActive);
	if (TempSystem)
	{
		TempSystem->Shutdown(Context, Flag);
		return true;
	}
	return false;
}

AOmegaGameplaySystem* UOmegaSubsystem_World::GetGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive)
{
	AOmegaGameplaySystem* DummyObject = nullptr;

	for (AOmegaGameplaySystem* TempSystem : GetActiveGameplaySystems())
	{
		if (TempSystem->GetClass()->IsChildOf(Class) && !DummyObject)
		{
			DummyObject = TempSystem;
		}
	}
	
	if (DummyObject && !DummyObject->bIsInShutdown)
	{
		bIsActive = true;
		return DummyObject;
	}
	else
	{
		bIsActive = false;
		return nullptr;
	}
}

TArray<AOmegaGameplaySystem*> UOmegaSubsystem_World::GetActiveGameplaySystems(bool bIncludeSystemsInShutdown)
{
	TArray<AOmegaGameplaySystem*> OutSystems;
	for(auto* TempSystem : SystemsData.GetActiveSystems(bIncludeSystemsInShutdown))
	{
		OutSystems.Add(Cast<AOmegaGameplaySystem>(TempSystem));
	}
	return OutSystems;
}

TArray<AOmegaGameplaySystem*> UOmegaSubsystem_World::GetActiveGameplaySystemsWithInterface(
	TSubclassOf<UInterface> Interface)
{
	TArray<AOmegaGameplaySystem*> OutSystems;
	for(auto* TempSys : GetActiveGameplaySystems())
	{
		if(TempSys->GetClass()->ImplementsInterface(Interface))
		{
			OutSystems.Add(TempSys);
		}
	}
	return OutSystems;
}

FGameplayTagContainer UOmegaSubsystem_World::GetBlockedSystemTags()
{
	FGameplayTagContainer out = FGameplayTagContainer::CreateFromArray(ExtraBlockedSystemTags);
	for(const auto* TempSys : GetActiveGameplaySystems(true))
	{
		out.AppendTags(TempSys->BlockSystemTags);
	}
	return out;
}

bool UOmegaSubsystem_World::IsSystemTagBlocked(FGameplayTagContainer Tags)
{
	return GetBlockedSystemTags().HasAnyExact(Tags);;
}

bool UOmegaSubsystem_World::IsSystemTagActive(FGameplayTagContainer Tags)
{
	for(auto* TempSys : GetActiveGameplaySystems())
	{
		if(TempSys->SystemTags.HasAnyExact(Tags))
		{
			return true;
		}
	}
	return false;
}

TArray<AOmegaGameplaySystem*> UOmegaSubsystem_World::GetActiveSystemsWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaGameplaySystem*> OutSystems;
	for (auto* TempSys : GetActiveGameplaySystems())
	{
		if(TempSys->SystemTags.HasAnyExact(Tags))
		{
			OutSystems.AddUnique(TempSys);
		}
	}
	return OutSystems;
}

void UOmegaSubsystem_World::SetSystemTagsBlocked(FGameplayTagContainer Tags, bool bBlocked)
{
	if(bBlocked)
	{
		for(const FGameplayTag& Tag : Tags)
		{
			ExtraBlockedSystemTags.AddUnique(Tag);
		}
	}
	else
	{
		for(const FGameplayTag& Tag : Tags)
		{
			ExtraBlockedSystemTags.Remove(Tag);
		}
	}
}

void UOmegaSubsystem_World::Local_RefreshSystemState()
{
	//Shutdown Blocked Systems
	for(auto* TempSys : GetActiveSystemsWithTags(GetBlockedSystemTags()))
	{
		TempSys->Shutdown(this, "Canceled");
	}
}


void UOmegaSubsystem_World::Native_RegisterCombatant(UCombatantComponent* Combatant, bool bRegistered)
{
	if(bRegistered)
	{
		ActiveCombatants.AddUnique(Combatant);
		Combatant->OnDamaged.AddDynamic(this, &UOmegaSubsystem_World::Native_OnDamaged);
		OnCombatantRegistered.Broadcast(Combatant);
	}
	else
	{
		ActiveCombatants.Remove(Combatant);
		OnCombatantUnegistered.Broadcast(Combatant);
	}
		
}

void UOmegaSubsystem_World::Native_OnDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
	float FinalDamage, UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit)
{
	OnCombatantDamaged.Broadcast(Combatant, Attribute, FinalDamage, Instigator, DamageType, Hit);
}

TArray<UCombatantComponent*> UOmegaSubsystem_World::GetAllCombatants()
{
	TArray<UCombatantComponent*> OutCombatants;
	for(UCombatantComponent* TempCombatant : ActiveCombatants)
	{
		if(IsValid(TempCombatant))
		{
			OutCombatants.Add(TempCombatant);
		}
	}
	return OutCombatants;
}


TArray<UCombatantComponent*> UOmegaSubsystem_World::RunCustomCombatantFilter(TSubclassOf<UCombatantFilter> FilterClass,
	UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& Combatants)
{
	TArray<UCombatantComponent*> OutCombatants;
	if(FilterClass)
	{
		
		OutCombatants = NewObject<UCombatantFilter>(this, FilterClass)->FilterCombatants(Instigator, Combatants);
	}
	return OutCombatants;
}

UOmegaGameplayMessage* UOmegaSubsystem_World::Message_Send(UObject* Instigator, FText Text, FGameplayTag CategoryTag,
	FOmegaGameplayMessageMeta meta)
{
	UOmegaGameplayMessage* out=NewObject<UOmegaGameplayMessage>(this,UOmegaGameplayMessage::StaticClass());
	out->Temp_Text=Text;
	out->meta=meta;
	out->subsytem_ref=this;
	if (Instigator)
	{
		out->Temp_Instigator=Instigator;
	}
	out->Temp_Tag=CategoryTag;
	
	ActiveMessages.Add(out);
	OnGameplayMessage_Begin.Broadcast(out,CategoryTag,meta);
	return out;
}

bool UOmegaSubsystem_World::Message_End(UOmegaGameplayMessage* Message)
{
	if (Message && ActiveMessages.Contains(Message))
	{
		ActiveMessages.Remove(Message);
		OnGameplayMessage_End.Broadcast(Message,Message->Temp_Tag,Message->meta);
		return true;
	}
	return false;
}

UOmegaGameplayMessage* UOmegaSubsystem_World::Message_GetFirstOfCategory(FGameplayTag CategoryTag)
{
	for (auto* m : ActiveMessages)
	{
		if (m && UDataInterface_General::GetGCategory(m)==CategoryTag)
		{
			return m;
		}
	}
	return nullptr;
}

void UOmegaSubsystem_World::L_MessageDelegateEvent(UOmegaGameplayMessage* Message)
{
}

void UOmegaSubsystem_World::SetGlobalActorBinding(FName Binding, AActor* Actor)
{
	if(Actor)
	{
		ActorBindings_Named.Add(Binding, Actor);
	}
}

void UOmegaSubsystem_World::ClearGlobalActorBinding(FName Binding)
{
	ActorBindings_Named.Remove(Binding);
}

AActor* UOmegaSubsystem_World::GetGlobalActorBinding(FName Binding)
{
	if(ActorBindings_Named.Contains(Binding))
	{
		return ActorBindings_Named.FindOrAdd(Binding);
	}
	return nullptr;
}


//############################################################################################################################################################
//------------------------------------------------------------------------------
// GAMEPLAY PAUSE COMPONENT
//------------------------------------------------------------------------------
//############################################################################################################################################################


TMap<FName, FString>& UOmegaSubsystem_World::GetA_PMap(AActor* a)
{
	return actors_meta.FindOrAdd(a).boundParam;
}

FString UOmegaSubsystem_World::GetAParam_string(AActor* a, FName key, FString def)
{
	
	return OGF_SoftParam::Conv_string(GetA_PMap(a),key,def);
}

float UOmegaSubsystem_World::GetAParam_float(AActor* a, FName key, float def)
{
	return OGF_SoftParam::Conv_float(GetA_PMap(a),key,def);
}

int32 UOmegaSubsystem_World::GetAParam_int(AActor* a, FName key, int32 def)
{
	return OGF_SoftParam::Conv_int(GetA_PMap(a),key,def);
}

bool UOmegaSubsystem_World::GetAParam_bool(AActor* a, FName key, bool def)
{
	return OGF_SoftParam::Conv_bool(GetA_PMap(a),key,def);
}

void UOmegaSubsystem_World::SetAParam_string(AActor* a, FName key, FString def)
{
	if(a) { OGF_SoftParam::set_string(GetA_PMap(a),key,def); }
}

void UOmegaSubsystem_World::SetAParam_float(AActor* a, FName key, float def)
{
	if(a) { OGF_SoftParam::set_float(GetA_PMap(a),key,def); }
}

void UOmegaSubsystem_World::SetAParam_int(AActor* a, FName key, int32 def)
{
	if(a) { OGF_SoftParam::set_int(GetA_PMap(a),key,def); }
}

void UOmegaSubsystem_World::SetAParam_bool(AActor* a, FName key, bool def)
{
	if(a) { OGF_SoftParam::set_bool(GetA_PMap(a),key,def); }
}

AOmegaWorldManager* UOmegaSubsystem_World::GetWorldManager()
{
	if (AOmegaWorldManager* wm=WorldManager.Get())
	{
		return wm;
	}
	return nullptr;
}


void UOmegaSubsystem_World::OnCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void UOmegaSubsystem_World::OnCompEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void UOmegaSubsystem_World::LinkComponentToTagTarget(UPrimitiveComponent* Component, AActor* Actor, FGameplayTag Tag, bool bLinked)
{
	if (Component && Actor)
	{
		if (bLinked)
		{
			Component->OnComponentBeginOverlap.AddDynamic(this, &UOmegaSubsystem_World::OnCompBeginOverlap);
			Component->OnComponentEndOverlap.AddDynamic(this, &UOmegaSubsystem_World::OnCompEndOverlap);	
		}
		else
		{
			Component->OnComponentBeginOverlap.RemoveDynamic(this, &UOmegaSubsystem_World::OnCompBeginOverlap);
			Component->OnComponentEndOverlap.RemoveDynamic(this, &UOmegaSubsystem_World::OnCompEndOverlap);	
		}
		
	}
}


void UOmegaSubsystem_World::local_RegisterActorIdComp(UGameplayActorComponent* Component, bool bIsRegister)
{
	if(Component)
	{
		if(bIsRegister && !REF_ActorIdComps.Contains(Component))
		{
			REF_ActorIdComps.Add(Component);
			OnActorIdentityRegistered.Broadcast(Component->GetOwner(),Component,true);
		}
		if(!bIsRegister && REF_ActorIdComps.Contains(Component))
		{
			REF_ActorIdComps.Remove(Component);
			OnActorIdentityRegistered.Broadcast(Component->GetOwner(),Component,false);
		}
	}
}

TArray<UGameplayActorComponent*> UOmegaSubsystem_World::GetAllActorIdentityComponents()
{
	TArray<UGameplayActorComponent*> out;
	for(auto* i : REF_ActorIdComps)
	{
		if(i) {out.Add(i);}
	}
	return out;
}

AActor* UOmegaSubsystem_World::GetFirstActorIfIdentity(UPrimaryDataAsset* Identity,TSubclassOf<AActor> FilterClass)
{
	if(Identity)
	{
		for(auto* a : GetAllActorIdentityComponents())
		{
			if(a && a->GetIdentitySourceAsset()==Identity && (!FilterClass || a->GetClass()->IsChildOf(FilterClass)))
			{
				return a->GetOwner();
			}
		}
	}
	return nullptr;
}

bool UOmegaSubsystem_World::CanInteract(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if(TargetActor && Instigator && TargetActor->GetClass()->ImplementsInterface(UActorInterface_Interactable::StaticClass()))
	{
		if(IActorInterface_Interactable::Execute_IsInteractionBlocked(TargetActor,Instigator,Tag,Context))
		{
			return false;
		}
		return true;
	}
	return false;
}


void UOmegaSubsystem_World::PerformInteraction(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, FOmegaCommonMeta Context)
{
	if(Instigator && TargetActor)
	{
		if(CanInteract(Instigator,TargetActor,Tag,Context))
		{
			if(TargetActor->GetClass()->ImplementsInterface(UActorInterface_Interactable::StaticClass()))
			{
				IActorInterface_Interactable::Execute_OnInteraction(TargetActor,Instigator,Tag,Context);
			}
			for (UActorComponent* ac : TargetActor->GetComponentsByInterface(UActorInterface_Interactable::StaticClass()))
			{
				if (ac)
				{
					IActorInterface_Interactable::Execute_OnInteraction(ac,Instigator,Tag,Context);
				}
			}
			OnActorInteraction.Broadcast(Instigator,TargetActor,Tag,Context);
		}
	}
}

bool UOmegaSubsystem_World::IsActorInGroup(FGameplayTag GroupTag, AActor* Actor) const
{
	return GetActorsInGroup(GroupTag).Contains(Actor);
}

void UOmegaSubsystem_World::SetActorRegisteredToGroup(FGameplayTag GroupTag, AActor* Actor, bool registered)
{
	if (!Actor)
	{
		return;
	}
	
	if (registered)
	{
		if (!OGF_GAME_CORE()->ActorGroup_AllowActor(Actor,GroupTag))
		{
			return;
		}
		// Make sure the group exists in the map
		if (!actorGroups.Contains(GroupTag))
		{
			actorGroups.Add(GroupTag, FOmegaActorGroupData());
		}

		// Add the actor to the group if not already present
		actorGroups[GroupTag].Actors.AddUnique(Actor);
		OnActorGroupChange.Broadcast(Actor,GroupTag,registered);
	}
	else
	{
		// Remove the actor from the group if the group exists
		if (actorGroups.Contains(GroupTag))
		{
			actorGroups[GroupTag].Actors.Remove(Actor);
			OnActorGroupChange.Broadcast(Actor,GroupTag,registered);
		}
	}
}

void UOmegaSubsystem_World::SetActorsRegisteredToGroup(FGameplayTag GroupTag, TArray<AActor*> Actors, bool registered)
{
	for(auto* a : Actors)
	{
		SetActorRegisteredToGroup(GroupTag,a,registered);
	}
}

void UOmegaSubsystem_World::ClearActorGroup(FGameplayTag GroupTag)
{
	if (actorGroups.Contains(GroupTag))
	{
		actorGroups[GroupTag].Actors.Empty();
	}
}

TArray<AActor*> UOmegaSubsystem_World::GetActorsInGroup(FGameplayTag GroupTag) const
{
	TArray<AActor*> ac;
	if (actorGroups.Contains(GroupTag))
	{
		ac=actorGroups[GroupTag].Actors;
	}
	ac=OGF_GAME_CORE()->ActorGroup_Filter(this,GroupTag,ac);
	for (auto* m : OGF_Subsystems::oGameInstance(this)->ActiveModules)
	{
		if (m)
		{
			ac=m->ActorGroup_Filter(GroupTag,ac);		
		}
	}
	return ac;
}

void UOmegaSubsystem_World::SetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag, AActor* Target)
{
	if(Instigator)
	{
		FOmegaActorMeta temp_meta=actors_meta.FindOrAdd(Instigator);
		if(AActor* previous = temp_meta.TaggedTargets.FindOrAdd(Tag))
		{
			OnActorTaggedTargetChange.Broadcast(Instigator,Tag,previous,false);
			temp_meta.TaggedTargets.Add(Tag,nullptr);
		}
		if(Target)
		{
			if (OGF_GAME_CORE()->Actor_CanSetTagTarget(Instigator,Target,Tag))
			{
				OnActorTaggedTargetChange.Broadcast(Instigator,Tag,Target,true);
				temp_meta.TaggedTargets.Add(Tag,Target);
			}
		}
		actors_meta.Add(Instigator,temp_meta);
	}
}

AActor* UOmegaSubsystem_World::GetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag)
{
	if(Instigator)
	{
		if(AActor* out=actors_meta.FindOrAdd(Instigator).TaggedTargets.FindOrAdd(Tag))
		{
			return out;
		}
	}
	return nullptr;
}

// ========================================================================================================
// Instanced Entity
// ========================================================================================================

AOmegaInstancedEntity::AOmegaInstancedEntity()
{
	PrimaryActorTick.bCanEverTick = false;
	bNetLoadOnClient = false;
	
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
	ActorID=CreateOptionalDefaultSubobject<UGameplayActorComponent>("ActorID");
}

// ========================================================================================================
// World Manager
// ========================================================================================================

AOmegaWorldManager::AOmegaWorldManager()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused=true;
	bNetLoadOnClient = false;
	
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
	//Combatant_B=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant 2");
	//Combatant_C=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant 3");
	ActorID=CreateOptionalDefaultSubobject<UGameplayActorComponent>("ActorID");
	AssetSquad=CreateOptionalDefaultSubobject<UAssetSquadComponent>("AssetSquad");
	EntityInstances=CreateOptionalDefaultSubobject<UInstanceActorComponent>("Entity Instances");
	
	EntityInstances->Instance_NamePrefex="E__";
	EntityInstances->InstancedActorClass=AOmegaInstancedEntity::StaticClass();
	
	AssetSquad->SaveBinding="_Global";
	AssetSquad->bBindToSave=true;
}

void AOmegaInstancedEntity::PreBeginPlay()
{
	Super::PreBeginPlay();
	if (UPrimaryDataAsset* da=Cast<UPrimaryDataAsset>(ContextObject))
	{
		Combatant->entity_id=UOmegaFunctions_Entity::Conv_DataAsset_2_EntityID(da);
		Combatant->use_entity_id=true;
		ActorID->SetIdentitySourceAsset(da);
	}
}


void AOmegaInstancedEntity::BeginPlay()
{
	Super::BeginPlay();
}

void AOmegaWorldManager::L_SetLoadStateSting(FString s) const
{
	if (SS_GI)
	{
		SS_GI->SetLoadStateString(s);
	}
}

FLuaValue AOmegaWorldManager::GetLevelLuaTable()
{
	FString lvl_nam=UGameplayStatics::GetCurrentLevelName(this);
	return ULuaBlueprintFunctionLibrary::LuaGetGlobal(this,nullptr,OGF_CFG_LUA()->Level_GlobalKey+"."+lvl_nam);
}

void AOmegaWorldManager::BeginPlay()
{
	Super::BeginPlay();
	SS_GI->L_InitBgmComponent();
	
	PrimaryActorTick.bTickEvenWhenPaused = true;
	
	//NullActor_Entities=Cast<AOmegaNullActor>(GetWorld()->SpawnActor(AOmegaNullActor::StaticClass()));
	NullActor_Quests=Cast<AOmegaNullActor>(GetWorld()->SpawnActor(AOmegaNullActor::StaticClass()));
	NullActor_Quests->AttachToActor(this,FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
#if WITH_EDITOR
	//NullActor_Entities->SetActorLabel("_ENTITIES_");
	NullActor_Quests->SetActorLabel("_Quests_");
#endif
	
	if (bStartWithNewGame)
	{
		SS_Save->StartGame(SS_Save->CreateNewGame(),false,FGameplayTagContainer());
	}
	
	//Resume saved quests
	for (auto* q : Quest_GetActive())
	{
		if (q)
		{
			OGF_Log::LogInfo("Attempting to resume: "+q->GetName());
			Quest_Start(q,true);
		}
	}
	
	//lua autoload
	if (OGF_CFG_LUA()->Level_AutoloadLuaTable)
	{
	//	GetLevelLuaTable();
	}
	uint8 _zoneTransitState=SS_GI->Zone_ZoneTransitState;
	SS_GI->Zone_ZoneTransitState=0;

	//Do initial Load
	FTimerHandle timer_handle;
	GetWorld()->GetTimerManager().SetTimer(timer_handle, FTimerDelegate::CreateLambda([this, _zoneTransitState]()
		{
			AOmegaZonePoint* dummy_point=nullptr;
			
			switch (_zoneTransitState)
			{
			case OGF_ZONE_TANSITSTATE_FROMLEVEL: // LEVEL TRANSIT
				
				if (SS_GI->Zone_LevelTransitingFrom.IsValid())
				{
					if (AOmegaZonePoint* p=Zone_GetPointFromlevel(SS_GI->Zone_LevelTransitingFrom,SS_GI->Zone_LevelTransitingTag))
					{
						OGF_Log::Info("WORLD MANAGER: - Finishing Level Load: FROM: "+SS_GI->Zone_LevelTransitingFrom.ToString());
						Zone_Transit(p,UGameplayStatics::GetPlayerController(this,0));
					}
					else
					{
						OGF_Log::Warning("WORLD MANAGER: -		FAILED to find target spawn point for level transit");
					}
				}
				
				break;
			case OGF_ZONE_TANSITSTATE_FROMSAVE: // game load
					
				dummy_point=GetWorld()->SpawnActorDeferred<AOmegaZonePoint>(AOmegaZonePoint::StaticClass(),FTransform());
				if (dummy_point)
				{
					dummy_point->SetLifeSpan(0.5);
					dummy_point->FinishSpawning(UOmegaSaveFunctions::GetSave_Game(this)->SavedPlayerTransform);
					Zone_Transit(dummy_point,UGameplayStatics::GetPlayerController(this,0));
				}
				else
				{
					OGF_Log::Warning("WORLD MANAGER: -		Could not spawn dummy_point for game load");
				}
					
				break;
			default: ;
		}
	}), OGF_CFG()->SpawnAtFirstPointDelay, false);
	
	//preload SaveState sublevels
	if (OGF_CFG()->SublevelSave_Autoload)
	{
		for (FName _sublvl : UOmegaLevelFunctions::Sublevel_GetAll(this))
		{
			FString sublvl=_sublvl.ToString();
			if (sublvl.Contains(OGF_CFG()->SublevelSave_Prefix))
			{
				sublvl=UKismetStringLibrary::Replace(sublvl,OGF_CFG()->SublevelSave_Prefix,"");
				FString sl_param;
				FString sl_val;
				if (sublvl.Split(TEXT("_"),&sl_param,&sl_val,ESearchCase::IgnoreCase,ESearchDir::FromEnd))
				{
					OGF_Log::LogInfo("ZONE MANAGER - Attempt load sublevel from save param:"+_sublvl.ToString()+"  || EVALUATE --- "+sl_param+"=="+sl_val);
					if (FCString::Atoi(*sl_val)==UOmegaFunctions_GlobalVars::GetGlobalVariable_Int32(this,EOmegaGlobalParamTarget::SAVE_GAME,*sl_param))
					{
						UOmegaLevelFunctions::Sublevel_SetLoaded(this,_sublvl,true);
					}
				}
			}
		}
	}
	OGF_GAME_CORE()->OnGame_LevelStart(GetWorld()->GetGameInstance(),UGameplayStatics::GetCurrentLevelName(this));
	SS_GI->Patch_Event(2,nullptr);
}

void AOmegaWorldManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	SS_GI->Patch_Event(3,nullptr);
	Super::EndPlay(EndPlayReason);
}

// ------------------------------------------------------------
// Quest
// ------------------------------------------------------------
AOmegaQuestInstance* AOmegaWorldManager::Quest_Start(UOmegaQuest* q, bool bResumeFormSave)
{
	if (Quest_CanStart(q) || bResumeFormSave)
	{
		if (AOmegaQuestInstance* new_inst=GetWorld()->SpawnActorDeferred<AOmegaQuestInstance>(AOmegaQuestInstance::StaticClass(),FTransform()))
		{
			new_inst->QuestAsset=q;
#if WITH_EDITOR
			new_inst->SetActorLabel("QuestInst__"+q->GetName());
#endif
			
			new_inst->FinishSpawning(FTransform());
			quest_instances.Add(new_inst);
			new_inst->AttachToActor(NullActor_Quests,FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
			new_inst->StartQuest(bResumeFormSave);
			
			return new_inst;
		}
		OGF_Log::Error("Failed to Start quest: could not spawn instance");
	}
	else
	{
		OGF_Log::Error("Failed to Start quest: Quest Start disabled");
	}
	return nullptr;
}

bool AOmegaWorldManager::Quest_CanStart(UOmegaQuest* q)
{
	if (q)
	{
		//if already has active instance, don't start
		for (auto* inst : quest_instances)
		{
			if (inst && inst->QuestAsset==q)
			{
				OGF_Log::LogWarning("QUEST: Failed to start quest "+q->GetName()+" - already has instance");
				return false;
			}
		}
		
		//if already active, return false
		FOmegaQuestData _dat=*Quest_GetData(q);
		if (_dat.Status==EOmegaQuestStatus::QuestStatus_Active)
		{
			OGF_Log::LogWarning("QUEST: Failed to start quest "+q->GetName()+" - already active");
			return false;
		}
		
		if (q->Replayable || !Quest_IsComplete(q))
		{
			return true;
		}
		OGF_Log::LogWarning("QUEST: Failed to start quest "+q->GetName()+" - is finished");
	}
	return false;
}

FOmegaQuestData* AOmegaWorldManager::Quest_GetData(UOmegaQuest* q)
{
	if (q)
	{
		UOmegaSaveGame* g=SS_Save->ActiveSaveData;
		if (g)
		{
			if (!g->quest_data.Contains(q))
			{
				g->quest_data.Add(q,FOmegaQuestData());
			}
			return &g->quest_data[q];
		}
	}
	return &dummy_questData;
}

bool AOmegaWorldManager::Quest_IsComplete(UOmegaQuest* q)
{
	if (q)
	{
		FOmegaQuestData _dat=*Quest_GetData(q);
		return _dat.Status==EOmegaQuestStatus::QuestStatus_Complete || _dat.Status==EOmegaQuestStatus::QuestStatus_Failed;
	}
	return false;
}

EOmegaQuestStatus AOmegaWorldManager::Quest_GetStatus(UOmegaQuest* q)
{
	if (q)
	{
		FOmegaQuestData _dat=*Quest_GetData(q);
		return _dat.Status;	
	}
	return EOmegaQuestStatus::QuestStatus_Unstarted;
}

bool AOmegaWorldManager::Quest_Stop(UOmegaQuest* q, bool bFailed)
{
	if (Quest_GetStatus(q)==QuestStatus_Active)
	{
		if (bFailed)
		{
			Quest_GetData(q)->Status=QuestStatus_Failed;
		}
		else
		{
			Quest_GetData(q)->Status=QuestStatus_Complete;
		}
		
		if (AOmegaQuestInstance* inst=Quest_GetInstance(q))
		{
			if (!inst->IsActorBeingDestroyed())
			{
				inst->K2_DestroyActor();	
			}
		}
		
	}
	return false;
}

AOmegaQuestInstance* AOmegaWorldManager::Quest_GetInstance(UOmegaQuest* q)
{
	for (auto* inst : quest_instances)
	{
		if (inst && inst->QuestAsset==q)
		{
			return inst;
		}
	}
	return nullptr;
}

TArray<UOmegaQuest*> AOmegaWorldManager::Quest_GetActive()
{
	TArray<UOmegaQuest*> out;
	
	TArray<UOmegaQuest*> checkList;
	OGF_Subsystems::oSave(this)->ActiveSaveData->quest_data.GetKeys(checkList);
	
	for (auto* q : checkList)
	{
		if (Quest_GetData(q)->Status==QuestStatus_Active)
		{
			out.Add(q);
		}
	}
	
	return out;
}

TArray<AOmegaQuestInstance*> AOmegaWorldManager::Quest_GetInstancesFromQuests(TArray<UOmegaQuest*> q)
{
	TArray<AOmegaQuestInstance*> out;
	for (auto* Quest : q)
	{
		if (AOmegaQuestInstance* inst=Quest_GetInstance(Quest))
		{
			out.Add(inst);
		}
	}
	return out;
}


// ----------------------------------------------------------------------------------------------------
// ZONE
// ----------------------------------------------------------------------------------------------------

AOmegaZonePoint* AOmegaWorldManager::Zone_GetPointFromlevel(TSoftObjectPtr<UWorld> Level, FGameplayTag Tag) const
{
	TArray<AActor*> ZonePoints;
	UGameplayStatics::GetAllActorsOfClass(this,AOmegaZonePoint::StaticClass(),ZonePoints);
	for (auto* a : ZonePoints)
	{
		if (AOmegaZonePoint* p=Cast<AOmegaZonePoint>(a))
		{
			if (p->FromLevel==Level && (!Tag.IsValid() || p->ZonePointID==Tag))
			{
				return p;
			}
		}
	}
	return nullptr;
}



void AOmegaWorldManager::L_SetTransitState(uint8 TransitState)
{
	FTimerHandle TimerHandle;
	auto _SetTransitSystemActive = [this](bool bActive)
	{
		if (TSubclassOf<AOmegaGameplaySystem> sys=OGF_CFG()->ZoneTransitSystem.LoadSynchronous())
		{
			UOmegaGameFrameworkBPLibrary::SetGameplaySystemActive(this,sys,bActive,"",this);
		}
	};
	
	zone_TransitState=TransitState;
		switch (zone_TransitState)
		{
			// none ----------------------------------------------------------------------
		case 0: 
			OGF_Log::LogInfo("ZONE -	TRANSIT STATE = 0	:	NONE ");
			_SetTransitSystemActive(false);
			break;
			// Fade OUT ----------------------------------------------------------------------
		case 1:
			OGF_Log::LogInfo("ZONE -	TRANSIT STATE = 1	:	FADE OUT ");
			_SetTransitSystemActive(true);
			L_PlayTransitAnim(false,2);
			L_SetLoadStateSting("Loading Zone - Play Transit Fade");
			break;
			// transit ----------------------------------------------------------------------
		case 2: 
			OGF_Log::LogInfo("ZONE -	TRANSIT STATE = 2	:	TRANSITING ");
			L_SetLoadStateSting("Loading Zone - Transiting");
			
			if (SS_GI->Zone_ZoneTransitState==1)
			{
				OGF_Log::LogInfo("ZONE -	TRANSIT STATE = 2.5	:	TO NEW LEVEL : ");
				UGameplayStatics::OpenLevel(this,transitLevelTarget);
			}
			else
			{
				if (zone_playerInTransit && zone_targetSpawn)
				{
					zone_playerInTransit->K2_GetPawn()->SetActorTransform(zone_targetSpawn->GetActorTransform());
					zone_playerInTransit->SetControlRotation(zone_targetSpawn->GetActorRotation());
					SS_World->OnZone_PlayerSpawnAtPoint.Broadcast(zone_playerInTransit,zone_targetSpawn);
				}
				
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
				{
					L_SetTransitState(3);
				
				}), OGF_CFG()->SpawnAtFirstPointDelay, false);
			}
			break;
			// Fade IN ----------------------------------------------------------------------
		case 3: 
			OGF_Log::LogInfo("ZONE -	TRANSIT STATE = 3	:	FADE IN ");
			L_PlayTransitAnim(true,4);
			break;
			// FINISH ----------------------------------------------------------------------
		case 4: 
			OGF_Log::LogInfo("ZONE -	TRANSIT STATE = 4	:	FINISHING ");
			L_SetTransitState(0);
			
			break;
		default: ;
		}
}


void AOmegaWorldManager::L_PlayTransitAnim(bool bReverse,uint8 next_state)
{
	float transit_time=0.5;
	if (ULevelSequencePlayer* pl=Zone_GetTransitSequencePlayer())
	{
		if (bReverse)
		{
			pl->PlayReverse();
		}
		else
		{
			pl->Play();
		}
					
		transit_time=pl->GetDuration().AsSeconds();
		if (transit_time>0.1)
		{
			TimerHandle_transit.Invalidate();
			FString _st="ZONE -		Transit Sequence -	 Timer START."+FString::SanitizeFloat(transit_time);
			OGF_Log::Warning(_st);
			i_zoneTransitNextState=next_state;
			f_zoneTransitAnimTime=transit_time;
		}
		else
		{
			OGF_Log::Warning("ZONE -		Transit Sequence -	 <0.1 seconds. Skipping.");
			L_SetTransitState(next_state);
		}
	}
	else
	{
		OGF_Log::Warning("ZONE -		Transit Sequence -	 invalid sequence player. Skipping.");
		L_SetTransitState(next_state);
	}
}

void AOmegaWorldManager::TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
	
	if (i_zoneTransitNextState!=-1 && f_zoneTransitAnimTime>0.0)
	{
		f_zoneTransitAnimTime-=DeltaTime;
		if (f_zoneTransitAnimTime<=0.0)
		{
			OGF_Log::Warning("ZONE -		Transit Sequence -	 Timer END.");
			L_SetTransitState(i_zoneTransitNextState);
			i_zoneTransitNextState=-1;
		}
	}
	if (SS_World)
	{
		if (SS_GI->f_loadStringCooldown>0.0)
		{
			SS_GI->f_loadStringCooldown-=DeltaTime;
			if (SS_GI->f_loadStringCooldown<=0.0)
			{
				//after load state cooldown, invalidate string for memeory
				SS_GI->LoadStateString=FString();
			}
		}
	}
}	


void AOmegaWorldManager::Zone_Transit(AOmegaZonePoint* Point, APlayerController* Player)
{
	if (Point && Player)
	{
		zone_targetSpawn=Point;
		zone_playerInTransit=Player;
		if (zone_TransitState==0)
		{
			OGF_Log::LogInfo("ZONE - Begining ZONE Transit ");
			SS_GI->Zone_ZoneTransitState=0;
			L_SetTransitState(1);
		}
	}
	else
	{
		OGF_Log::Error("WORLD MANAGER: FAILED to transit. Player or Point invalid");
	}
}

ULevelSequence* AOmegaWorldManager::Zone_GetTransitSequence() const
{
	if (ULevelSequence* s=OGF_CFG()->Sequence_ZoneTransit.LoadSynchronous())
	{
		return s;
	}
	return nullptr;
}

ULevelSequencePlayer* AOmegaWorldManager::Zone_GetTransitSequencePlayer()
{
	if (!zone_SequencePlayer)
	{
		if (ULevelSequence* s=Zone_GetTransitSequence())
		{
			FMovieSceneSequencePlaybackSettings set;
			set.bAutoPlay=false;
			zone_SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(),s,set,zone_SequenceActor);
		}
	}
	return zone_SequencePlayer;
}

void AOmegaWorldManager::ZoneEntity_Register(UZoneEntityComponent* entity, bool bIsEntityRegistered)
{
	if(bIsEntityRegistered && !registered_entities.Contains(entity))
	{
		registered_entities.AddUnique(entity);
	}
	if(!bIsEntityRegistered && registered_entities.Contains(entity))
	{
		registered_entities.Remove(entity);
	}
}



UOmegaLevelData* AOmegaWorldManager::Zone_GetLevelData(TSoftObjectPtr<UWorld> SoftLevelReference)
{
	// Get the current level path
	FString CurrentLevelPath = SoftLevelReference.GetLongPackageName();
	UE_LOG(LogTemp, Warning, TEXT("LEVEL DATA CHECK --> CurrentLevelPath: %s"), *CurrentLevelPath);
	// Remove ":PersistentLevel" from the level path
	FString LevelPathWithoutPersistentLevel = CurrentLevelPath.Replace(TEXT(":PersistentLevel"), TEXT(""));
	LevelPathWithoutPersistentLevel.ReplaceInline(TEXT("UEDPIE_0_"),TEXT(""));
	
	UE_LOG(LogTemp, Warning, TEXT("LEVEL DATA CHECK --> LevelPathWithoutPersistentLevel: %s"), *LevelPathWithoutPersistentLevel);
	FString MainNameLevel;
	FString MainNamePath;
	
	// Find the position of the first occurrence of "."
	int32 DotIndex = -1;
	if (LevelPathWithoutPersistentLevel.FindChar('/', DotIndex))
	{
		// Extract the level name from the path
		LevelPathWithoutPersistentLevel.Split("/",&MainNamePath,&MainNameLevel,ESearchCase::IgnoreCase,ESearchDir::FromEnd);

		// Construct the DataAsset path
		FString _suf=OGF_CFG()->LevelData_Suffix;
		FString DataAssetPath = LevelPathWithoutPersistentLevel+_suf+"."+MainNameLevel+_suf;
		
		// Print the DataAsset path to the log for debugging
		UE_LOG(LogTemp, Warning, TEXT("LEVEL DATA CHECK --> DataAssetPath: %s"), *DataAssetPath);

		// Load the DataAsset
		UOmegaLevelData* OmegaLevelData = Cast<UOmegaLevelData>(StaticLoadObject(UOmegaLevelData::StaticClass(), nullptr, *DataAssetPath));

		if (!OmegaLevelData)
		{
			// Handle the case when the DataAsset is not found.
			UE_LOG(LogTemp, Warning, TEXT("OmegaLevelData '%s' not found!"), *DataAssetPath);
		}

		return OmegaLevelData;
	}
	else
	{
		// Handle the case when "." is not found in the path.
		UE_LOG(LogTemp, Warning, TEXT("Invalid level path: %s"), *CurrentLevelPath);
		return nullptr;
	}
}

UOmegaLevelData* AOmegaWorldManager::Zone_GetLevelData_Current()
{
	if(!LevelData)
	{
		LevelData = Zone_GetLevelData(GetCurrentLevelSoftReference());
	}
	return LevelData;
}

TSoftObjectPtr<UWorld> AOmegaWorldManager::GetCurrentLevelSoftReference()
{
	UWorld* CurrentWorld = GetWorld();
	if (!CurrentWorld)
	{
		UE_LOG(LogTemp, Warning, TEXT("No current world found!"));
		return nullptr;
	}
	const TSoftObjectPtr<UWorld> LevelAssetPtr(GetWorld()->GetCurrentLevel()->GetOuter()); // Get the level path name
	return LevelAssetPtr;
}

TArray<UOmegaZoneData*> AOmegaWorldManager::Zone_GetLoaded()
{
	return LoadedZones;
}

UOmegaZoneData* AOmegaWorldManager::Zone_GetFirstLoaded()
{
	if(Zone_GetLoaded().IsValidIndex(0))
	{
		return Zone_GetLoaded()[0];
	}
	return nullptr;
}

bool AOmegaWorldManager::Zone_IsLoaded(UOmegaZoneData* Zone)
{
	if(Zone)
	{
		return Zone_GetLoaded().Contains(Zone);
	}
	return false;
}

bool AOmegaWorldManager::Zone_IsLoading() const
{
	return zone_TransitState!=0;
}

void AOmegaWorldManager::Zone_TransitToLevel(TSoftObjectPtr<UWorld> Level, FGameplayTag SpawnID)
{
	const FString StartPath = Level.ToString();
	FString EmptyPath;
	FString targetLevel;
	StartPath.Split(TEXT("."),&EmptyPath,&targetLevel, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	OGF_Log::Info("Try Transit to soft level: "+targetLevel);
	Zone_TransitToLevel_Name(FName(targetLevel),SpawnID);
}

void AOmegaWorldManager::Zone_TransitToLevel_Name(FName Level, FGameplayTag SpawnID)
{
	OGF_Log::LogInfo("ZONE - Begining LEVEL Transit ");
	SS_GI->Zone_ZoneTransitState=1;
	const UWorld* CurrentWorld = GetWorld();
	const ULevel* CurrentLevel = CurrentWorld->GetCurrentLevel();
	const TSoftObjectPtr<UWorld> LevelAssetPtr(CurrentLevel->GetOuter());
	SS_GI->Zone_LevelTransitingFrom=LevelAssetPtr;
	SS_GI->Zone_LevelTransitingTag=SpawnID;
	transitLevelTarget=Level;
	
	L_SetTransitState(1);
}


TArray<UZoneEntityComponent*> AOmegaWorldManager::ZoneEntity_GetRegistered() const
{
	TArray<UZoneEntityComponent*> out;
	for(UZoneEntityComponent* temp_entity : registered_entities)
	{
		if(temp_entity)
		{
			out.Add(temp_entity);
		}
	}
	return out;
}

TArray<UZoneEntityComponent*> AOmegaWorldManager::GetRegisteredZoneEntities_OfLegend(UZoneLegendAsset* Legend) const
{
	TArray<UZoneEntityComponent*> out;
	for(UZoneEntityComponent* temp_entity : ZoneEntity_GetRegistered())
	{
		if(temp_entity && temp_entity->LegendAsset==Legend)
		{
			out.Add(temp_entity);
		}
	}
	return out;
}

TArray<AOmegaInstancedEntity*> AOmegaWorldManager::GetInstanceEntities_OfSquad(UAssetSquad_Identity* Squad) const
{
	TArray<AOmegaInstancedEntity*> out;
	if (Squad)
	{
		TArray<UPrimaryDataAsset*> as=AssetSquad->GetSquadMembers(Squad);
		for (auto* a :as)
		{
			if (a)
			{
				
			}
		}
	}
	return out;
}


void AOmegaWorldManager::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (UPrimaryDataAsset* da=OGF_CFG()->GlobalEntityIdentity.LoadSynchronous())
	{
		if (Combatant)
		{
			Combatant->entity_id=UOmegaFunctions_Entity::Conv_DataAsset_2_EntityID(da);
			Combatant->use_entity_id=true;
		}
		if (ActorID)
		{
			ActorID->SetIdentitySourceAsset(da);
		}
	}
}

FOmegaActorInstanceMetadata AOmegaWorldManager::GetActorMetadata(AActor* Actor) const
{
	if (const FOmegaActorInstanceMetadata* Found = ActorInstanceMetadata.Find(Actor))
	{
		return *Found;
	}
	return FOmegaActorInstanceMetadata();
}

void AOmegaWorldManager::SetActorMetadata(AActor* Actor, const FOmegaActorInstanceMetadata& Metadata)
{
	if (!Actor)
	{
		return;
	}

	// If metadata is empty, remove it from the map
	if (Metadata.IsMetadataEmpty())
	{
		RemoveActorMetadata(Actor);
	}
	else
	{
		ActorInstanceMetadata.Add(Actor, Metadata);
	}
}

void AOmegaWorldManager::RemoveActorMetadata(AActor* Actor)
{
	if (Actor)
	{
		ActorInstanceMetadata.Remove(Actor);
	}
}

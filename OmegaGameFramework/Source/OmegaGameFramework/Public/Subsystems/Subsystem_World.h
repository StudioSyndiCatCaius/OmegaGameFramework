// Copyright Studio Syndicat 2021. All Rights Reserved.

// The Gameplay Subsystem is the primary World Subsystem, and handles combatants and Gameplay System actors.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "UObject/Interface.h"
#include "Tickable.h"
#include "Engine/HitResult.h"
#include "JsonObjectWrapper.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Components/Component_InstancedActor.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_SoftParams.h"
#include "Interfaces/I_Interaction.h"
#include "Types/OmegaActorInstanceMetadata.h"
#include "Types/Struct_Message.h"
#include "Subsystem_World.generated.h"

class AOmegaNullActor;
class UAudioComponent;
class UAssetSquad_Identity;
class UAssetSquadComponent;
class UGameplayActorComponent;
class ALevelSequenceActor;
class ULevelSequencePlayer;
class AOmegaZonePoint;
class AOmegaGameplaySystem;
class UOmegaSettings;
class UDamageFormula;
class UCombatantFilter;
class UOmegaQuest;
class AOmegaQuestInstance;
class UCombatantComponent;
class UOmegaZoneData;
class UOmegaLevelData;
class UZoneLegendAsset;
class UZoneEntityComponent;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnActorInteraction, AActor*, InteractInstigator, AActor*, Target,FGameplayTag, Tag, FOmegaCommonMeta, Context);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnActorTaggedTargetChange, AActor*, Instigator, FGameplayTag, Tag, AActor*, Target, bool, regsitered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorGroupChange, AActor*, Actor, FGameplayTag, Tag, bool, regsitered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorTagEvent, AActor*, Actor, FGameplayTag, Tag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FActorIdentityDelegateRegister, AActor*, Actor, UGameplayActorComponent*, Component, bool, Registered);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantRegisterDelegate, UCombatantComponent*, Combatant);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnCombatantDamaged, UCombatantComponent*, Combatant, UOmegaAttribute*, Attribute, float, FinalDamage, class UCombatantComponent*, Instigator, UOmegaDamageType*, DamageType, FHitResult, Hit);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayStateChange, FGameplayTag, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnGameplaySystemActiveStateChange, AOmegaGameplaySystem*, system, UObject*, context, const FString&, flag, bool, bActive);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGameplayMessage, UOmegaGameplayMessage*, Message, FGameplayTag, MessageCategory, FOmegaGameplayMessageMeta, meta);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FZonePointDelegate, APlayerController*, Player,AOmegaZonePoint*, Point);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOmegaQuestDelegate, AOmegaQuestInstance* ,Component, UOmegaQuest*, Quest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestStatusChanged, AOmegaQuestInstance* ,Component, EOmegaQuestStatus, NewStatus);

USTRUCT()
struct FOmegaActorGroupData
{
	GENERATED_BODY()
	UPROPERTY() TArray<AActor*> Actors;
};



// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// World Manager
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────



UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaInstancedEntity : public AOmegaInstanceActor
{
	GENERATED_BODY()

protected:
	AOmegaInstancedEntity();
	virtual void BeginPlay() override;
	virtual void PreBeginPlay() override;
	
public:
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCombatantComponent* Combatant;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UGameplayActorComponent* ActorID;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaWorldManager : public AOmegaActorBASE
{
	GENERATED_BODY()

protected:
	
	void L_SetLoadStateSting(FString s) const;
	
	int8 i_zoneTransitNextState=-1;
	float f_zoneTransitAnimTime=0.0;
	FTimerHandle TimerHandle_transit;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
public:
	AOmegaWorldManager();
	
	UPROPERTY() AOmegaNullActor* NullActor_Entities;
	UPROPERTY() AOmegaNullActor* NullActor_Quests;
	UPROPERTY() TMap<AActor*, FOmegaActorInstanceMetadata> ActorInstanceMetadata;
	UPROPERTY() UOmegaLevelData* LevelData;
	UPROPERTY() TArray<UOmegaZoneData*> LoadedZones;

	FOmegaActorInstanceMetadata GetActorMetadata(AActor* Actor) const;
	void SetActorMetadata(AActor* Actor, const FOmegaActorInstanceMetadata& Metadata);
	void RemoveActorMetadata(AActor* Actor);

	//In world manager start, creates and starts a new save game. (This is useful for things like a title screen level, to ensure no extra save data is carried over.)
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="🗺️World Manager") bool bStartWithNewGame;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCombatantComponent* Combatant;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UGameplayActorComponent* ActorID;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UAssetSquadComponent* AssetSquad;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UInstanceActorComponent* EntityInstances;
	
	UFUNCTION(BlueprintPure, Category="WorldManager") FLuaValue GetLevelLuaTable();

	// ------------------------------------------------------------
	// Quest
	// ------------------------------------------------------------
	
private:
	FOmegaQuestData dummy_questData;
public:
	
	UPROPERTY() TArray<AOmegaQuestInstance*> quest_instances;
	
	AOmegaQuestInstance* Quest_Start(UOmegaQuest* q, bool bResumeFormSave=false);
	bool Quest_CanStart(UOmegaQuest* q);
	FOmegaQuestData* Quest_GetData(UOmegaQuest* q);
	bool Quest_IsComplete(UOmegaQuest* q);
	EOmegaQuestStatus Quest_GetStatus(UOmegaQuest* q);
	bool Quest_Stop(UOmegaQuest* q, bool bFailed);
	AOmegaQuestInstance* Quest_GetInstance(UOmegaQuest* q);
	TArray<UOmegaQuest*> Quest_GetActive();
	TArray<AOmegaQuestInstance*> Quest_GetInstancesFromQuests(TArray<UOmegaQuest*> q);
	
	
	// ------------------------------------------------------------
	// Zone
	// ------------------------------------------------------------
	
	UPROPERTY() AOmegaZonePoint* zone_targetSpawn=nullptr;
	UPROPERTY() APlayerController* zone_playerInTransit=nullptr;
	UPROPERTY() ULevelSequencePlayer* zone_SequencePlayer=nullptr;
	UPROPERTY() ALevelSequenceActor* zone_SequenceActor=nullptr;
	UPROPERTY() TArray<UZoneEntityComponent*> registered_entities;
	
	//0=none | 1=fade_OUT | 2=transiting | 3=fade_in | 4=finishing
	uint8 zone_TransitState=0;
	FName transitLevelTarget;
	
private:
	void L_SetTransitState(uint8 TransitState);
	void L_PlayTransitAnim(bool bReverse,uint8 next_state);
public:
	
	AOmegaZonePoint* Zone_GetPointFromlevel(TSoftObjectPtr<UWorld> Level, FGameplayTag Tag) const;
	void Zone_Transit(AOmegaZonePoint* Point,APlayerController* Player);
	ULevelSequence* Zone_GetTransitSequence() const;
	ULevelSequencePlayer* Zone_GetTransitSequencePlayer();

	TArray<UOmegaZoneData*> Zone_GetLoaded();
	void Zone_TransitToLevel(TSoftObjectPtr<UWorld> Level, FGameplayTag SpawnID);
	void Zone_TransitToLevel_Name(FName Level, FGameplayTag SpawnID);
	UOmegaLevelData* Zone_GetLevelData(TSoftObjectPtr<UWorld> SoftLevelReference);
	UOmegaLevelData* Zone_GetLevelData_Current();
	TSoftObjectPtr<UWorld> GetCurrentLevelSoftReference();
	UOmegaZoneData* Zone_GetFirstLoaded();
	bool Zone_IsLoaded(UOmegaZoneData* Zone);
	bool Zone_IsLoading() const;
	
	void ZoneEntity_Register(UZoneEntityComponent* entity, bool bIsEntityRegistered);
	
	TArray<UZoneEntityComponent*> ZoneEntity_GetRegistered() const;

	UFUNCTION(BlueprintPure,Category="Zone|Entities")
	TArray<UZoneEntityComponent*> GetRegisteredZoneEntities_OfLegend(UZoneLegendAsset* Legend) const;
	
	// ------------------------------------------------------------
	// Entities
	// ------------------------------------------------------------
	TArray<AOmegaInstancedEntity*> GetInstanceEntities_OfSquad(UAssetSquad_Identity* Squad) const;
	
	UFUNCTION(BlueprintPure,Category="OmegaWorldManager") uint8 GetZoneLoadState() const{ return zone_TransitState; };
};



// #####################################################################################################################
// World Subsystem
// #####################################################################################################################

UCLASS(DisplayName="Omega Subsystem: Gameplay")
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_World : public UWorldSubsystem
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOnGameplaySystemActiveStateChange OnGameplaySystemActiveStateChange;
	
	UPROPERTY() FOmegaBaseSystemStats SystemsData;
	UPROPERTY() FOmegaSoftParams GlobalVars;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Omega") FOmegaEntitySet Entities;
	
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	
	// ────────────────────────────────────────────────────────────────────
	// World Manager
	// ────────────────────────────────────────────────────────────────────
	
	// Get or spawn the world manager
	UFUNCTION(BlueprintCallable, Category = "Omega")
	AOmegaWorldManager* GetWorldManager();
	
	UPROPERTY() TWeakObjectPtr<AOmegaWorldManager> WorldManager;
	
	
	// ────────────────────────────────────────────────────────────────────
	// Gameplay Systems
	// ────────────────────────────────────────────────────────────────────
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="OmegaGameManager|") FJsonObjectWrapper WorldJsonObject;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Omega|Subsystem|Gameplay") FGameplayTagContainer StateTags;
	
	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta=(AdvancedDisplay = "Context, Flag"))
	AOmegaGameplaySystem* ActivateGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, class UObject* Context = nullptr, FString Flag="",FOmegaCommonMeta meta=FOmegaCommonMeta());

	UFUNCTION(BlueprintCallable, Category = "OmegaGameplaySubsystem", meta = (AdvancedDisplay = "Context, Flag"))
	bool ShutdownGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context = nullptr, FString Flag = "");

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem", meta=(DeterminesOutputType = "Class"))
	class AOmegaGameplaySystem* GetGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	TArray<AOmegaGameplaySystem*> GetActiveGameplaySystems(bool bIncludeSystemsInShutdown=false);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	TArray<AOmegaGameplaySystem*> GetActiveGameplaySystemsWithInterface(TSubclassOf<UInterface> Interface);

	UFUNCTION() FGameplayTagContainer GetBlockedSystemTags();
	
	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	bool IsSystemTagBlocked(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	bool IsSystemTagActive(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintPure, Category = "OmegaGameplaySubsystem")
	TArray<AOmegaGameplaySystem*> GetActiveSystemsWithTags(FGameplayTagContainer Tags);

	UFUNCTION()
	void SetSystemTagsBlocked(FGameplayTagContainer Tags, bool bBlocked);
	
	UPROPERTY() TArray<FGameplayTag> ExtraBlockedSystemTags;
private:
	

	//Refreshes system states. will shutdown any systems with blocked tags.
	UFUNCTION()
	void Local_RefreshSystemState();

public:

	UFUNCTION()
	void Native_RegisterCombatant(UCombatantComponent* Combatant, bool bRegistered);
	
	UPROPERTY()
	TArray<UCombatantComponent*> ActiveCombatants;

	UFUNCTION(BlueprintPure, Category="Combat")
	TArray<UCombatantComponent*> GetAllCombatants();
	
	UPROPERTY(BlueprintAssignable) FOnCombatantRegisterDelegate OnCombatantRegistered;
	UPROPERTY(BlueprintAssignable) FOnCombatantRegisterDelegate OnCombatantUnegistered;
	
	UPROPERTY(BlueprintAssignable)
	FOnCombatantDamaged OnCombatantDamaged;
	UFUNCTION()
	void Native_OnDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit);

	UFUNCTION(BlueprintCallable, Category="OmegaGameplaySubsystem")
	TArray<UCombatantComponent*> RunCustomCombatantFilter(TSubclassOf<UCombatantFilter> FilterClass, UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& Combatants);
	
	// ────────────────────────────────────────────────────────────────────
	// Quest
	// ────────────────────────────────────────────────────────────────────
	
	UPROPERTY(BlueprintAssignable) FOnOmegaQuestDelegate OnQuest_Start;
	UPROPERTY(BlueprintAssignable) FOnOmegaQuestDelegate OnQuest_End;
	UPROPERTY(BlueprintAssignable) FOnOmegaQuestDelegate OnQuest_Updated;
	
	// ────────────────────────────────────────────────────────────────────
	// ZONE
	// ────────────────────────────────────────────────────────────────────
	
	UPROPERTY(BlueprintAssignable) FZonePointDelegate OnZone_PlayerSpawnAtPoint;
	
	// ────────────────────────────────────────────────────────────────────
	// Messages
	// ────────────────────────────────────────────────────────────────────
	UPROPERTY(BlueprintAssignable) FOnGameplayMessage OnGameplayMessage_Begin;
	UPROPERTY(BlueprintAssignable) FOnGameplayMessage OnGameplayMessage_End;
	
	UPROPERTY() TArray<UOmegaGameplayMessage*> ActiveMessages;
	
	UOmegaGameplayMessage* Message_Send(UObject* Instigator, FText Text, FGameplayTag CategoryTag, FOmegaGameplayMessageMeta meta);
	bool Message_End(UOmegaGameplayMessage* Message);
	UOmegaGameplayMessage* Message_GetFirstOfCategory(FGameplayTag CategoryTag);
	void L_MessageDelegateEvent(UOmegaGameplayMessage* Message);
	
	// ────────────────────────────────────────────────────────────────────
	// Actor - Global Bindings
	// ────────────────────────────────────────────────────────────────────

	UPROPERTY() TMap<FName, AActor*> ActorBindings_Named;
	UPROPERTY() TMap<FGameplayTag, AActor*> ActorBindings_Tagged;
	
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay Subsystem|Actors")
	void SetGlobalActorBinding(FName Binding, AActor* Actor);
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay Subsystem|Actors")
	void ClearGlobalActorBinding(FName Binding);
	UFUNCTION(BlueprintPure, Category="Omega Gameplay Subsystem|Actors")
	AActor* GetGlobalActorBinding(FName Binding);


	// ────────────────────────────────────────────────────────────────────
	// Actor - Soft Param
	// ────────────────────────────────────────────────────────────────────
	
	UPROPERTY() TArray<UGameplayActorComponent*> REF_ActorIdComps;
	UPROPERTY() TMap<FGameplayTag, FOmegaActorGroupData> actorGroups;
	UPROPERTY() TMap<AActor*, FOmegaActorMeta> actors_meta;
public:
	TMap<FName,FString>& GetA_PMap(AActor* a);
	FString GetAParam_string(AActor* a, FName key, FString def);
	float GetAParam_float(AActor* a, FName key, float def);
	int32 GetAParam_int(AActor* a, FName key, int32 def);
	bool GetAParam_bool(AActor* a, FName key, bool def);
	void SetAParam_string(AActor* a, FName key, FString def);
	void SetAParam_float(AActor* a, FName key, float def);
	void SetAParam_int(AActor* a, FName key, int32 def);
	void SetAParam_bool(AActor* a, FName key, bool def);
	
	UFUNCTION() void OnCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION() void OnCompEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION() void LinkComponentToTagTarget(UPrimitiveComponent* Component, AActor* Actor, FGameplayTag Tag, bool bLinked);
	
	UPROPERTY(BlueprintAssignable) FOnActorInteraction OnActorInteraction;
	UPROPERTY(BlueprintAssignable) FOnActorTaggedTargetChange OnActorTaggedTargetChange;
	UPROPERTY(BlueprintAssignable) FOnActorTagEvent OnActorTagEvent;
	UPROPERTY(BlueprintAssignable) FOnActorGroupChange OnActorGroupChange;
	
	UPROPERTY(BlueprintAssignable) FActorIdentityDelegateRegister OnActorIdentityRegistered;
	
	void local_RegisterActorIdComp(UGameplayActorComponent* Component, bool bIsRegister);

	UFUNCTION(BlueprintCallable,Category="Actor Identity Subsystem")
	TArray<UGameplayActorComponent*> GetAllActorIdentityComponents();

	UFUNCTION(BlueprintCallable,Category="Actor Identity Subsystem")
	AActor* GetFirstActorIfIdentity(UPrimaryDataAsset* Identity,TSubclassOf<AActor> FilterClass=nullptr);

	// ────────────────────────────────────────────────────────────────────
	// Actor - Interaction
	// ────────────────────────────────────────────────────────────────────

	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Interaction")
	bool CanInteract(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, FOmegaCommonMeta Context);
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Interaction")
	void PerformInteraction(AActor* Instigator, AActor* TargetActor, FGameplayTag Tag, FOmegaCommonMeta Context);

	// ────────────────────────────────────────────────────────────────────
	// Actor - Groups
	// ────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintPure,Category="ActorSubsystem|Groups")
	bool IsActorInGroup(FGameplayTag GroupTag, AActor* Actor) const;
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void SetActorRegisteredToGroup(FGameplayTag GroupTag, AActor* Actor, bool registered);

	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void SetActorsRegisteredToGroup(FGameplayTag GroupTag, TArray<AActor*> Actors, bool registered);
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void ClearActorGroup(FGameplayTag GroupTag);
	
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	TArray<AActor*> GetActorsInGroup(FGameplayTag GroupTag) const;

	// ---------------------------------------------------------------------------------
	// Actor Meta
	// ---------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="ActorSubsystem|Groups")
	void SetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag, AActor* Target=nullptr);
	UFUNCTION(BlueprintPure,Category="ActorSubsystem|Groups")
	AActor* GetActorTaggedTarget(AActor* Instigator, FGameplayTag Tag);
	
};


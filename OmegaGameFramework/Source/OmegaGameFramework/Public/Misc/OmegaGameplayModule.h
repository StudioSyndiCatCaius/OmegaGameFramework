// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "OmegaGameMode.h"
#include "Subsystems/Subsystem_QueueEvents.h"

#include "OmegaGameplayModule.generated.h"

class UGameInstance;
class UWorld;
class UOmegaSaveGame;
class UCombatantComponent;
class UOmegaAttribute;
class UOmegaDamageType;

UCLASS(BlueprintType, Blueprintable, EditInlineNew,HideCategories=("Private"))
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayModule : public UObject, public IInterface_QueuedQuery, public IInterface_QueuedSelector
{
	GENERATED_BODY()


	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;
	UPROPERTY() UOmegaGameManager* REF_OwningManager;

	UFUNCTION() void L_OnGameSystemChange(AOmegaGameplaySystem* system, UObject* context, const FString& flag, bool bActive);

protected:
	virtual bool GetQueuedQueryValue_Implementation(FGameplayTag Tag, UObject* Context=nullptr) { return true; };
	
	UFUNCTION()
	void Native_OnLevelOpened(FString LevelName, AOmegaGameMode* GameMode);
	UFUNCTION() void L_ActorIdentityRegistered(AActor* Actor, UActorIdentityComponent* Component, bool Registered);
	UFUNCTION() void L_CombatantInit(UCombatantComponent* combatant);
	UFUNCTION() void L_CombatantUninit(UCombatantComponent* combatant);
	
public:
	UOmegaGameplayModule(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	
	UFUNCTION()
	void Native_Initialize();

	//Properties
	//True = This module will automatically be registered and activated on game start.
	UPROPERTY()
	bool AutoRegisterModule;

	UFUNCTION(BlueprintImplementableEvent,Category="GameplayModule")
	TArray<TSubclassOf<AOmegaGameplaySystem>> GetAutoGameplaySystems();
	
	UPROPERTY()
	TArray<TSubclassOf<AOmegaGameplaySystem>> AutoGameplaySystems;
	
	UPROPERTY()
	FGameplayTagContainer ModuleTags;

	
	//Functions
	UFUNCTION(BlueprintImplementableEvent, Category = "GameplayModule")
	void Initialized();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "GameplayModule")
	void Shutdown();

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayModule")
	void GameFileStarted(UOmegaSaveGame* SaveFile, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintNativeEvent, Category="GameplayModule")
	bool GameFileSaved(UOmegaSaveGame* SaveFile);

	UFUNCTION(BlueprintImplementableEvent, Category="Event")
	void OnGlobalEvent(FName Event, UObject* Instigator,FOmegaCommonMeta meta);
	UFUNCTION(BlueprintImplementableEvent, Category="Event")
	void OnTaggedGlobalEvent(FGameplayTag Event, UObject* Instigator,FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnLevelOpened(const FString& LevelName, AOmegaGameMode* GameMode);
	
	//---------------------------------------------------------------------
	// Actors
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_RegisteredToGroup(AActor* Actor, FGameplayTag Group, bool Registered);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_IdentityRegistered(AActor* Actor, UActorIdentityComponent* Component, bool Registered);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_TagEvent(AActor* Actor, FGameplayTag Event);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_Interaction(AActor* InteractInstigator, AActor* Target, FGameplayTag Tag, FOmegaCommonMeta Context);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_EndOverlap(AActor* OverlappedActor, AActor* OtherActor);
	// Hit event
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_Hit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
	// Mouse events
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_Touched(AActor* TouchedActor);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_BeginCursorOver(AActor* TouchedActor);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_EndCursorOver(AActor* TouchedActor);
	UFUNCTION(BlueprintImplementableEvent,Category="Actor")
	void OnActor_Clicked(AActor* TouchedActor, FKey ButtonPressed);

	//---------------------------------------------------------------------
	// Combatant
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant")
	void OnCombatant_Registered(UCombatantComponent* Combatant);
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant")
	void OnCombatant_Unregistered(UCombatantComponent* Combatant);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant")
	void OnCombatant_Damaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant")
	void OnCombatant_Notify(UCombatantComponent* OwningCombatant, FName Notify, const FString& Flag);

	//---------------------------------------------------------------------
	// system
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant")
	void OnGameplaySystem_Activate(AOmegaGameplaySystem* System,UObject* Context, const FString& flag,FOmegaCommonMeta meta);
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant")
	void OnGameplaySystem_Shutdown(AOmegaGameplaySystem* System,UObject* Context, const FString& flag,FOmegaCommonMeta meta);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayModuleSet : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	TArray<UOmegaGameplayModule*> GetModules() { return ScriptedModules;};
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Modules")
	TArray<UOmegaGameplayModule*> ScriptedModules;
};
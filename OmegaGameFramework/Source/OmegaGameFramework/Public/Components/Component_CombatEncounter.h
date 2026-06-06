// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaComponent.h"
#include "Components/ActorComponent.h"
#include "Misc/GeneralDataObject.h"
#include "Component_CombatEncounter.generated.h"

class UOmegaFaction;
class UOmegaBGM;
class ULevelSequence;
class AOmegaAbility;
class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;
class UCombatantComponent;

// Defines a physical stage layout for a combat encounter, including spawn positions per faction.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaCombatEncounter_Stage : public AActor
{
	GENERATED_BODY()

public:
	AOmegaCombatEncounter_Stage();
	// Tag that uniquely identifies this stage, used to select it when starting an encounter.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter Stage",meta=(Categories="ENCOUNTER.Stage"))
	FGameplayTag StageID=FGameplayTag::RequestGameplayTag("ENCOUNTER.Stage.Default");

	// Returns the spawn transform for battler #index belonging to the given faction on this stage.
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Encounter|Stage")
	FTransform GetTransformForBattler(UPARAM(meta=(Categories="FACTION")) FGameplayTag FactionTag, int32 index);

	// Box component defining the valid area of this stage.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Omega|Encounter|Stage") UBoxComponent* Range;
};

// An in-world actor that represents a running encounter instance, owning the encounter camera and optional overrides.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaCombatEncounter_Instance : public AActor
{
	GENERATED_BODY()

public:
	AOmegaCombatEncounter_Instance();
	// Optional level sequence that overrides the default intro cinematic for this encounter.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	ULevelSequence* OverrideSequence_Intro;
	// Optional BGM asset that overrides the default encounter music.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	UOmegaBGM* OverrideBGM;

	// Spring arm driving the encounter camera.
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Components") USpringArmComponent* comp_spring;
	// The encounter's dedicated camera component.
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Components") UCameraComponent* comp_camera;


	// Returns the spawn transform for battler #index of the given faction within this instance.
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Encounter|Stage")
	FTransform GetTransformByFaction(UPARAM(meta=(Categories="FACTION")) FGameplayTag FactionTag, int32 index);

};



// Implement on character actors that participate in a combat encounter as a battler.
UINTERFACE(MinimalAPI,BlueprintType)
class UActorInterface_EncounterBattler : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_EncounterBattler
{
	GENERATED_BODY()
public:

	// Called once the battler has been spawned and initialized with its identity and faction.
	UFUNCTION(BlueprintNativeEvent,Category="♎I|⚔️Encounter Battler")
	void OnBattlerInit(UOmegaCombatEncounter_Component* Component, UPrimaryDataAsset* Identity, UOmegaFaction* Faction);

};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterBattlerSpawned, ACharacter*, Battler);

// Manages the full lifecycle of a combat encounter: stage selection, battler spawning, BGM, and intro sequence.
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCombatEncounter_Component : public UOmegaComponent
{
	GENERATED_BODY()

	// Sets default values for this component's properties
	UPROPERTY() TArray<AOmegaCombatEncounter_Stage*> REF_StageList;
	UPROPERTY() AOmegaCombatEncounter_Stage* REF_Stage;
	UPROPERTY() AOmegaCombatEncounter_Instance* REF_Instance;

	UPROPERTY() TArray<UCombatantComponent*> REF_BattlerCombatants;
	UPROPERTY() UObject* encounter_source;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UOmegaCombatEncounter_Component();

public:
	// Fires each time a battler character is spawned into the encounter.
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FOnEncounterBattlerSpawned OnEncounterSpawned;

	// The default encounter instance class spawned when no override is specified.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Encounter")
	TSubclassOf<AOmegaCombatEncounter_Instance> DefaultEncounterClass=AOmegaCombatEncounter_Instance::StaticClass();

	// Returns all stage actors registered to this component.
	UFUNCTION(BlueprintCallable,Category="Encounter")
	TArray<AOmegaCombatEncounter_Stage*> GetAllStages();

	// Finds and returns the stage whose StageID matches the given tag.
	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Stage* GetStageFromID(FGameplayTag ID);

	// The character class spawned for each battler. Must implement IActorInterface_EncounterBattler.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter",meta=(MustImplement="/Script/OmegaGameFramework.ActorInterface_EncounterBattler"))
	TSubclassOf<ACharacter> BattlerCharacterClass;

	// Additional abilities granted to every battler spawned in this encounter.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Encounter")
	TArray<TSubclassOf<AOmegaAbility>> ExtraBattlerAbilities;

	// Intro level sequence played when no source or instance override is set.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter")
	ULevelSequence* Default_SequenceIntro;
	// Default BGM played during the encounter when no override is set.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter")
	UOmegaBGM* Default_BGM;

	// Returns the intro sequence to play, respecting instance overrides over the component default.
	UFUNCTION(BlueprintPure,Category="Encounter")
	ULevelSequence* GetEncounter_SequenceIntro() const;
	// Returns the BGM to play, respecting instance overrides over the component default.
	UFUNCTION(BlueprintPure,Category="Encounter")
	UOmegaBGM* GetEncounter_BGM() const;

	// Starts an encounter using the given instance class and stage, spawning the instance actor.
	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Instance* StartEncounter(TSubclassOf<AOmegaCombatEncounter_Instance> EncounterClass,AOmegaCombatEncounter_Stage* Stage);

	// Starts an encounter by reading config from Source (must implement IDataInterface_CombatEncounter).
	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Instance* StartEncounter_FromSource(UObject* Source);

	// Ends the active encounter and tears down the instance actor. Returns false if no encounter is running.
	UFUNCTION(BlueprintCallable,Category="Encounter")
	bool EndEncounter();

	// Spawns a battler character for the given data asset and faction, placing it at the given transform or a stage slot.
	UFUNCTION(BlueprintCallable,Category="Encounter")
	ACharacter* SpawnBattler(UPrimaryDataAsset* DataAsset, UOmegaFaction* Faction, FTransform Transform, int32 StageTransformIndex=-1,
		ESpawnActorCollisionHandlingMethod CollisionMethod=ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);

	// Returns the stage actor currently in use for this encounter.
	UFUNCTION(BlueprintPure,Category="Encounter")
	AOmegaCombatEncounter_Stage* GetCurrent_Stage() const;
	// Returns the encounter instance actor currently running, or null if none.
	UFUNCTION(BlueprintPure,Category="Encounter")
	AOmegaCombatEncounter_Instance* GetCurrent_Encounter() const;

};

// Bundles all configuration options needed to start an encounter (stage, instance class, optional overrides).
USTRUCT(BlueprintType)
struct FOmegaEncounterConfig
{
	GENERATED_BODY()

	// Tag identifying which stage to use for this encounter.
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Encounter",meta=(Categories="ENCOUNTER.STAGE"))
	FGameplayTag StageID;
	// The encounter instance class to spawn; leave blank to use the component default.
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Encounter")
	TSubclassOf<AOmegaCombatEncounter_Instance> EncounterInstance;
	// Optional intro sequence that overrides the stage/component default.
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Encounter")
	TObjectPtr<ULevelSequence> Override_IntroSequence;
	// Optional BGM that overrides the stage/component default.
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Encounter")
	TObjectPtr<UOmegaBGM> Override_BGM;
};


// Implement on objects (data assets, actors) that can initiate and configure a combat encounter.
UINTERFACE(MinimalAPI,BlueprintType,DisplayName="♎Data🔴 - ⚔️ Encounter")
class UDataInterface_CombatEncounter : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_CombatEncounter
{
	GENERATED_BODY()
public:

	// Called when an encounter is started from this source. Return false to cancel the encounter.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|⚔️Encounter",DisplayName="⚔️Encounter - On Begin")
	bool OnEncounterBegin(UOmegaCombatEncounter_Component* Component);

	// Returns the configuration (stage, instance class, overrides) for the encounter this source wants to run.
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|⚔️Encounter",DisplayName="⚔️Encounter - Get Config")
	FOmegaEncounterConfig Encounter_Config();

};


// A data asset that defines a self-contained encounter setup including stage, instance class, and optional overrides.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaEncounter_Asset : public UOmegaDataAsset, public IDataInterface_CombatEncounter
{
	GENERATED_BODY()

public:
	// The encounter instance class used when starting this encounter.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	TSubclassOf<AOmegaCombatEncounter_Instance> InstanceClass;
	// Tag identifying which stage this encounter takes place on.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	FGameplayTag StageTag;
	// Optional intro sequence override for this encounter asset.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	ULevelSequence* Override_IntroSequence;
	// Optional BGM override for this encounter asset.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	UOmegaBGM* Override_BGM;

	virtual FOmegaEncounterConfig Encounter_Config_Implementation() override;

};

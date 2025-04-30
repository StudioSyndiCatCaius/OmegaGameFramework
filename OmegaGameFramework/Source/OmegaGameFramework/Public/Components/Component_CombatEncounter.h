// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaFaction.h"
#include "Subsystems/OmegaSubsystem_BGM.h"
#include "Component_CombatEncounter.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaCombatEncounter_Stage : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter Stage")
	FGameplayTag StageID;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Omega|Encounter|Stage")
	FTransform GetTransformForBattler(FGameplayTag FactionTag, int32 index);
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaCombatEncounter_Instance : public AActor
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	ULevelSequence* OverrideSequence_Intro;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	UOmegaBGM* OverrideBGM;
	
};




//
UCLASS(Blueprintable,BlueprintType,Abstract,EditInlineNew,Const)
class OMEGAGAMEFRAMEWORK_API UOmegaCombatEncounterScript : public UObject
{
	GENERATED_BODY()

	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;

	UOmegaCombatEncounterScript(const FObjectInitializer& ObjectInitializer);

public:

	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;
	
	UFUNCTION(BlueprintPure,Category="Encounter")
	UOmegaCombatEncounter_Component* GetOwningComponent() const;	
	
	UFUNCTION(BlueprintImplementableEvent,Category="Encounter")
	void OnEncounterStarted(AOmegaCombatEncounter_Instance* Instance, AOmegaCombatEncounter_Stage* Stage) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Encounter")
	void OnEncounterEnded(AOmegaCombatEncounter_Instance* Instance, AOmegaCombatEncounter_Stage* Stage) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Encounter")
	void OnBattlerSpawned(ACharacter* Character, UCombatantComponent* Combatant) const;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterBattlerSpawned, ACharacter*, Battler);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCombatEncounter_Component : public UActorComponent
{
	GENERATED_BODY()

	// Sets default values for this component's properties
	UPROPERTY() TArray<AOmegaCombatEncounter_Stage*> REF_StageList;
	UPROPERTY() AOmegaCombatEncounter_Stage* REF_Stage;
	UPROPERTY() AOmegaCombatEncounter_Instance* REF_Instance;

	UPROPERTY()
	TArray<UCombatantComponent*> REF_BattlerCombatants;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UOmegaCombatEncounter_Component();

public:
	UPROPERTY(BlueprintAssignable)
	FOnEncounterBattlerSpawned OnEncounterSpawned;
		
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Encounter")
	UOmegaCombatEncounterScript* EncounterManagerScript;
	
	UFUNCTION(BlueprintCallable,Category="Encounter")
	TArray<AOmegaCombatEncounter_Stage*> GetAllStages();

	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Stage* GetStageFromID(FGameplayTag ID);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Encounter")
	TSubclassOf<ACharacter> BattlerCharacterClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Encounter")
	TArray<TSubclassOf<AOmegaAbility>> ExtraBattlerAbilities;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter")
	ULevelSequence* Default_SequenceIntro;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter")
	UOmegaBGM* Default_BGM;

	UFUNCTION(BlueprintPure,Category="Encounter")
	ULevelSequence* GetEncounter_SequenceIntro() const;
	UFUNCTION(BlueprintPure,Category="Encounter")
	UOmegaBGM* GetEncounter_BGM() const;
	
	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Instance* StartEncounter(TSubclassOf<AOmegaCombatEncounter_Instance> EncounterClass,AOmegaCombatEncounter_Stage* Stage);

	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Instance* StartEncounter_FromSource(UObject* Source);
	
	UFUNCTION(BlueprintCallable,Category="Encounter")
	bool EndEncounter();
	
	UFUNCTION(BlueprintCallable,Category="Encounter")
	ACharacter* SpawnBattler(UPrimaryDataAsset* DataAsset, UOmegaFaction* Faction, FTransform Transform);

	UFUNCTION(BlueprintPure,Category="Encounter")
	AOmegaCombatEncounter_Stage* GetCurrent_Stage() const;
	UFUNCTION(BlueprintPure,Category="Encounter")
	AOmegaCombatEncounter_Instance* GetCurrent_Encounter() const;
	
};

UINTERFACE(MinimalAPI)
class UDataInterface_CombatEncounter : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_CombatEncounter
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,Category="Encounter")
	TSubclassOf<AOmegaCombatEncounter_Instance> GetCombatEncounter_InstanceClass();
	
	UFUNCTION(BlueprintNativeEvent,Category="Encounter")
	FGameplayTag GetCombatEncounter_StageID();
	
	UFUNCTION(BlueprintNativeEvent,Category="Encounter")
	bool OnEncounterBegin(UOmegaCombatEncounter_Component* Component);
};

UCLASS(Blueprintable,BlueprintType,Const,Abstract,CollapseCategories,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaEncounter_AssetScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="Encounter")
	void OnEncounterBegin(UOmegaCombatEncounter_Component* Component) const;
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaEncounter_Asset : public UOmegaDataAsset, public IDataInterface_CombatEncounter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	TSubclassOf<AOmegaCombatEncounter_Instance> InstanceClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	FGameplayTag StageTag;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite,Category="Encounter")
	UOmegaEncounter_AssetScript* Script;

	virtual TSubclassOf<AOmegaCombatEncounter_Instance> GetCombatEncounter_InstanceClass_Implementation() override { return InstanceClass;}
	virtual FGameplayTag GetCombatEncounter_StageID_Implementation() override { return StageTag;};
	virtual bool OnEncounterBegin_Implementation(UOmegaCombatEncounter_Component* Component) override;
	
};
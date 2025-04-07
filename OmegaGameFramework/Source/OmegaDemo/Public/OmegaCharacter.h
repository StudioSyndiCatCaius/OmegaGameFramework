// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataItemComponent.h"
#include "FlowAsset.h"
#include "Actors/Actor_Character.h"
#include "Components/Component_ActorIdentity.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_ActorState.h"
#include "Components/Component_AimTargeter.h"
#include "Components/Component_CombatEncounter.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Skin.h"
#include "Components/Component_Subscript.h"
#include "Functions/OmegaFunctions_Animation.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "GameFramework/Character.h"
#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "Subsystems/OmegaSubsystem_Zone.h"
#include "OmegaCharacter.generated.h"


class UAudioComponent;

UCLASS()
class OMEGADEMO_API AOmegaCharacter : public AOmegaBaseCharacter, public IGameplayTagsInterface, public IActorInterface_AimTarget
{
	GENERATED_BODY()

	UFUNCTION()
	void OnActorIdentityChanged(UPrimaryDataAsset* IdentityAsset, UActorIdentityComponent* Component);

	void _ActivateSubscriptCol(TArray<USubscriptCollection*> ss) const
	{
		for(auto * s : ss)
		{
			if(s) { SubscriptComponent->SetSubscriptCollectionActive(s,true);}
		}
	}

	
public:
	// Sets default values for this character's properties 
	AOmegaCharacter();


protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	void Local_AddCombatantSource(UObject* Source);
	UFUNCTION() void Local_LevelUpdate(int32 NewLevel);
	UFUNCTION() void Local_UpdateDataItem(UOmegaDataItem* NewItem);

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere,Category="Mesh")
	FName MutableComponentName=TEXT("Body");
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="0_OmegaCharacter")
	UPrimaryDataAsset* CharacterAsset;

	UFUNCTION(BlueprintCallable, Category="0_OmegaCharacter")
	void SetCharacterAsset(UPrimaryDataAsset* Asset);

	UPROPERTY(EditAnywhere,Category="Animation")
	UOmegaAnimationEmote* DefaultEmote;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="0_OmegaCharacter")
	UFlowAsset* DialogueFlow;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="0_OmegaCharacter",DisplayName="Subscripts")
	TArray<USubscriptCollection*> SubscriptCollections;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Animation")
	FName LookAimSocketName=TEXT("LookPoint");
	
	UPROPERTY(EditAnywhere,Category="0_OmegaCharacter")
	FGameplayTagContainer CharacterTags;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return CharacterTags; };

	UPROPERTY(EditDefaultsOnly,Category="0_OmegaCharacter",AdvancedDisplay)
	bool Autobind_NamedGlobalEvents;
	UPROPERTY(EditDefaultsOnly,Category="0_OmegaCharacter",AdvancedDisplay)
	bool Autobind_TaggedGlobalEvents;
	
	UFUNCTION(BlueprintImplementableEvent,Category="0_OmegaCharacter")
	void OnGlobalEvent_Named(FName Event, UObject* Context);
	UFUNCTION(BlueprintImplementableEvent,Category="0_OmegaCharacter")
	void OnGlobalEvent_Tagged(FGameplayTag Event, UObject* Context);

	virtual FVector GetAimTargetLocation_Implementation(const UAimTargetComponent* Component) const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UActorIdentityComponent* ActorIdentity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UDataItemComponent* DataItem;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UCombatantComponent* Combatant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UEquipmentComponent* Equipment;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UDataAssetCollectionComponent* Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) ULevelingComponent* Leveling;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UActorStateComponent* ActorState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USubscriptComponent* SubscriptComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USkinComponent* SkinComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAudioComponent* AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UChildActorComponent* SkinTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UGameplayPauseComponent* GameplayPause;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UZoneEntityComponent* ZoneEntity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAimTargetComponent* LookAim;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UCustomizableSkeletalComponent* CustomSkelMesh;

};

// ========================================================================================================
// Encounter Character
// ========================================================================================================

UCLASS()
class OMEGADEMO_API AOmegaEncounterCharacter : public AOmegaCharacter, public IDataInterface_CombatEncounter
{
	GENERATED_BODY()

public:
	AOmegaEncounterCharacter();
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditAnywhere,Category="CombatEncounter")
	TSubclassOf<AOmegaCombatEncounter_Instance> EncounterClass;
	UPROPERTY(EditAnywhere,Category="CombatEncounter")
	FGameplayTag StageID;
	
	virtual TSubclassOf<AOmegaCombatEncounter_Instance> GetCombatEncounter_InstanceClass_Implementation() override
	{
		return EncounterClass;
	}
	virtual FGameplayTag GetCombatEncounter_StageID_Implementation() override
	{
		return StageID;
	}
};


// ========================================================================================================
// Reference Character
// ========================================================================================================

UCLASS(hideCategories = (Info, Rendering, MovementReplication, Collision))
class OMEGADEMO_API AOmegaReferenceCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOmegaReferenceCharacter();
	//virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
};

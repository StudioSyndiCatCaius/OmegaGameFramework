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
class UBillboardComponent;
class UCameraComponent;
class UStateTreeComponent;

UCLASS()
class OMEGADEMO_API AOmegaCharacter : public AOmegaBaseCharacter, public IGameplayTagsInterface, public IActorInterface_AimTarget,
										public IDataInterface_FlowAsset, public IDataInterface_General, public IDataInterface_Traits
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

	bool b_IdentityHasGeneralInterface();
	void L_Camera_Update();

public:
	// Sets default values for this character's properties 
	AOmegaCharacter();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	void Local_AddCombatantSource(UObject* Source);
	UFUNCTION() void Local_LevelUpdate(ULevelingComponent* comp,int32 NewLevel);
	UFUNCTION() void Local_UpdateDataItem(UOmegaDataItem* NewItem);

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//EDITOR
	UFUNCTION(BlueprintCallable,CallInEditor,Category="EDTIOR")
	void Camera_Front();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="FLAGS")
	bool UseCameraPull;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="OmegaCharacter")
	TArray<UOmegaObjectTrait*> Traits;
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="OmegaCharacter")
	FText OverrideName;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="OmegaCharacter")
	UPrimaryDataAsset* CharacterAsset;

	UFUNCTION(BlueprintCallable, Category="OmegaCharacter")
	void SetCharacterAsset(UPrimaryDataAsset* Asset);

	UPROPERTY(EditAnywhere,Category="Animation")
	UOmegaAnimationEmote* DefaultEmote;

	// DIALOGUE
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter")
	TSoftObjectPtr<UFlowAsset> DialogueFlow=nullptr;
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override { return DialogueFlow.LoadSynchronous(); };

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OmegaCharacter",DisplayName="Subscripts")
	TArray<USubscriptCollection*> SubscriptCollections;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Animation")
	FName LookAimSocketName=TEXT("LookPoint");
	
	UPROPERTY(EditAnywhere,Category="OmegaCharacter")
	FGameplayTagContainer CharacterTags;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return CharacterTags; };

	UPROPERTY(EditDefaultsOnly,Category="OmegaCharacter",AdvancedDisplay)
	bool Autobind_NamedGlobalEvents;
	UPROPERTY(EditDefaultsOnly,Category="OmegaCharacter",AdvancedDisplay)
	bool Autobind_TaggedGlobalEvents;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera",AdvancedDisplay,meta=(MakeEditWidget))
	FVector CameraPull;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera",AdvancedDisplay,meta=(MakeEditWidget))
	FVector CameraOffset;
	
	UFUNCTION(BlueprintImplementableEvent,Category="OmegaCharacter")
	void OnGlobalEvent_Named(FName Event, UObject* Context);
	UFUNCTION(BlueprintImplementableEvent,Category="OmegaCharacter")
	void OnGlobalEvent_Tagged(FGameplayTag Event, UObject* Context);

	virtual FVector GetAimTargetLocation_Implementation(const UAimTargetComponent* Component) const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UActorIdentityComponent* ActorIdentity;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UDataItemComponent* DataItem;
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
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UCameraComponent* MainCamera;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UBillboardComponent* Icon_Faction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UTextRenderComponent* Text_Name;

private:
	FText L_GetDisplayName();
	FText L_GetDisplayDescript();
public:
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
};

// ========================================================================================================
// Encounter Character
// ========================================================================================================

UCLASS()
class OMEGADEMO_API AOmegaEncounterCharacter : public AOmegaBaseCharacter, public IDataInterface_CombatEncounter
{
	GENERATED_BODY()

public:
	AOmegaEncounterCharacter();
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UActorIdentityComponent* ActorIdentity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UActorStateComponent* ActorState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USubscriptComponent* SubscriptComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USkinComponent* SkinComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAudioComponent* AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UChildActorComponent* SkinTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UGameplayPauseComponent* GameplayPause;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UZoneEntityComponent* ZoneEntity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAimTargetComponent* LookAim;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UStateTreeComponent* StateTree;
	
	UPROPERTY(EditAnywhere,Category="CombatEncounter")
	UOmegaEncounter_Asset* Encounter;
	UPROPERTY(EditAnywhere,Category="CombatEncounter")
	FGameplayTag StageID;
	
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

UCLASS(hideCategories = (Info, Rendering, MovementReplication, Collision))
class OMEGADEMO_API AOmegaCinematicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOmegaCinematicCharacter();
	//virtual void Const

	UPROPERTY(EditAnywhere,Category="Components") UActorIdentityComponent* ActorIdentityComponent;
};

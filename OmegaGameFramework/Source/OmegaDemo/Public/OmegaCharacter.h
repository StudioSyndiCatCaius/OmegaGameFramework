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
#include "Components/Component_Saveable.h"
#include "Components/Component_Skin.h"
#include "Components/Component_Subscript.h"
#include "Functions/F_Animation.h"
#include "Subsystems/Subsystem_Save.h"
#include "GameFramework/Character.h"
#include "Interfaces/I_BitFlag.h"
#include "Subsystems/Subsystem_Gameplay.h"
#include "Subsystems/Subsystem_Zone.h"
#include "OmegaCharacter.generated.h"

class UDataWidgetComponent;
class UAudioComponent;
class UBillboardComponent;
class UCameraComponent;
class UStateTreeComponent;
class UUtilMeshComponent;
class UOmegaComponent_Interactable;

UCLASS(HideCategories=("Skeletal Mesh, Physics"),DisplayName="Ω Character")
class OMEGADEMO_API AOmegaCharacter : public AOmegaBaseCharacter, public IGameplayTagsInterface, public IActorInterface_AimTarget,
										public IDataInterface_FlowAsset, public IActorTagEventInterface, public IActorInterface_Interactable
{
	GENERATED_BODY()

	UFUNCTION()
	void OnActorIdentityChanged(UPrimaryDataAsset* IdentityAsset, UActorIdentityComponent* Component);

	void _ActivateSubscriptCol(TArray<USubscriptCollection*> ss) const
	{
		for(auto * s : ss)
		{
			//if(s) { SubscriptComponent->SetSubscriptCollectionActive(s,true);}
		}
	}

	bool b_IdentityHasGeneralInterface() const;
	void L_Camera_Update() const;
	virtual void N_OnCharAssetChange(UPrimaryDataAsset* old_asset, UPrimaryDataAsset* new_asset) override;
	virtual int32 GetInteraction_BitFlags_Implementation() override { return Flags.Bitmask;};
	virtual void Bitflags_Set_Implementation(FOmegaBitflagsBase bitmask) override { Flags=bitmask; };
	
public:
	// Sets default values for this character's properties 
	AOmegaCharacter();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	
	void Local_AddCombatantSource(UObject* Source);
	UFUNCTION() void Local_LevelUpdate(ULevelingComponent* comp,int32 NewLevel,int32 LastLevel,UOmegaLevelingAsset* asset);
	UFUNCTION() void Local_UpdateDataItem(UOmegaDataItem* NewItem);

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, UObject* Context) override;
	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override { return !CanInteract; };
	
	//EDITOR
	UFUNCTION(BlueprintCallable,CallInEditor,Category="EDTIOR")
	void Camera_Front();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="FLAGS")
	bool UseCameraPull;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="FLAGS")
	bool CanInteract=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="FLAGS")
	bool UseIdentityTraits;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="OmegaCharacter")
	TArray<UOmegaObjectTrait*> Traits;
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="OmegaCharacter",meta=(EditCondition="!CharacterAsset"))
	FText OverrideName;

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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveableComponent* Saveable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaComponent_Interactable* Interactable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAudioComponent* AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UChildActorComponent* SkinTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UGameplayPauseComponent* GameplayPause;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UZoneEntityComponent* ZoneEntity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAimTargetComponent* LookAim;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UDataWidgetComponent* DataWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UCameraComponent* MainCamera;
	
	UPROPERTY() UBillboardComponent* Icon_Faction;
	UPROPERTY() UTextRenderComponent* Text_Name;

private:
	FText L_GetDisplayName();
	FText L_GetDisplayDescript();
public:
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;

	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
};

// ========================================================================================================
// Encounter Character
// ========================================================================================================

UCLASS(DisplayName="Ω Character - Encounter")
class OMEGADEMO_API AOmegaEncounterCharacter : public AOmegaBaseCharacter, public IDataInterface_CombatEncounter
{
	GENERATED_BODY()

	UFUNCTION() TArray<FName> GetKeys_Encounter();
public:
	AOmegaEncounterCharacter();
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UBoxComponent* OverlapRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UActorIdentityComponent* ActorIdentity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USubscriptComponent* SubscriptComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USkinComponent* SkinComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAudioComponent* AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UChildActorComponent* SkinTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UGameplayPauseComponent* GameplayPause;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UZoneEntityComponent* ZoneEntity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAimTargetComponent* LookAim;
	UPROPERTY() UUtilMeshComponent* UtilMesh;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UStateTreeComponent* StateTree;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatEncounter")
	UOmegaEncounter_Asset* Encounter;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="LUA",meta=(GetOptions="GetKeys_Encounter"))
	FName Encounter_Key;
	UFUNCTION(BlueprintPure,Category="CombatEncounter") UOmegaEncounter_Asset* GetEncounterAsset() const;
};


// ========================================================================================================
// Reference Character
// ========================================================================================================

UCLASS(hideCategories = (Info, Rendering, MovementReplication, Collision), DisplayName="Ω Character - Reference")
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

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Actors/Actor_Character.h"
#include "Components/Component_GameplayActor.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_ActorState.h"
#include "Components/Component_AimTargeter.h"
#include "Components/Component_CombatEncounter.h"
#include "Functions/F_Equipment.h"
#include "Components/Component_Saveable.h"
#include "Components/Component_Skin.h"
#include "Functions/F_Animation.h"
#include "Subsystems/Subsystem_Save.h"
#include "GameFramework/Character.h"
#include "Subsystems/Subsystem_World.h"
#include "OmegaCharacter.generated.h"

class UDataWidgetComponent;
class UAudioComponent;
class UBillboardComponent;
class UCameraComponent;
class UStateTreeComponent;
class UUtilMeshComponent;
class USpringArmComponent;

UCLASS(HideCategories=("Skeletal Mesh, Physics"),DisplayName="Ω Character")
class OMEGADEMO_API AOmegaCharacter : public AOmegaMinimalCharacter, public IActorInterface_AimTarget,
										public IDataInterface_FlowAsset, public IActorTagEventInterface, public IActorInterface_Interactable
{
	GENERATED_BODY()

	UFUNCTION()
	void OnActorIdentityChanged(UPrimaryDataAsset* IdentityAsset, UGameplayActorComponent* Component);

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

	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists) override;
	
public:
	// Sets default values for this character's properties 
	AOmegaCharacter();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	
	void Local_AddCombatantSource(UObject* Source);

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//EDITOR
	UFUNCTION(BlueprintCallable,CallInEditor,Category="EDTIOR")
	void Camera_Front();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="FLAGS") bool UseCameraPull;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="FLAGS") bool CanInteract=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="FLAGS") bool UseIdentityTraits;

	UPROPERTY(EditAnywhere,Category="Animation")
	UOmegaAnimationEmote* DefaultEmote;

	// DIALOGUE
	UPROPERTY()
	TSoftObjectPtr<UFlowAsset> DialogueFlow=nullptr;
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Animation") FName LookAimSocketName=TEXT("LookPoint");

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera",AdvancedDisplay,meta=(MakeEditWidget)) FVector CameraPull;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera",AdvancedDisplay,meta=(MakeEditWidget)) FVector CameraOffset;

	virtual FVector GetAimTargetLocation_Implementation(const UAimTargetComponent* Component) const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UCombatantComponent* Combatant;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveableComponent* Saveable;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAudioComponent* AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UZoneEntityComponent* ZoneEntity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAimTargetComponent* LookAim;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UChildActorComponent* ChildSlot;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UDataWidgetComponent* DataWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UCameraComponent* MainCamera;
	
	UPROPERTY() UBillboardComponent* Icon_Faction;
	UPROPERTY() UTextRenderComponent* Text_Name;
	
	

	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override { return !CanInteract; };
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
};

// ========================================================================================================
// Encounter Character
// ========================================================================================================

UCLASS(DisplayName="Ω Character - Encounter")
class OMEGADEMO_API AOmegaEncounterCharacter : public AOmegaMinimalCharacter, public IDataInterface_CombatEncounter
{
	GENERATED_BODY()

public:
	AOmegaEncounterCharacter();
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UBoxComponent* OverlapRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UOmegaSaveStateComponent* SaveVisibility;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAudioComponent* AudioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UChildActorComponent* SkinTarget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UZoneEntityComponent* ZoneEntity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UAimTargetComponent* LookAim;
	UPROPERTY() UUtilMeshComponent* UtilMesh;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="1_Components",AdvancedDisplay) UStateTreeComponent* StateTree;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CombatEncounter")
	UOmegaEncounter_Asset* Encounter;

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

};

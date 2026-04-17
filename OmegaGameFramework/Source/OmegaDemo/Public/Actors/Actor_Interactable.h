// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Actors/Actor_Prop.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Components/Component_GameplayActor.h"
#include "Functions/F_Component.h"
#include "GameFramework/SpringArmComponent.h"
#include "Subsystems/Subsystem_World.h"
#include "Types/Struct_CustomNamedList.h"
#include "Actor_Interactable.generated.h"

class UActorConfigComponent;
class UTextRenderComponent;
class UUtilMeshComponent;
class UStaticMeshComponent;
class UNiagaraComponent;
class UOmegaCondition_Interact;


UCLASS(DisplayName="Ω Interactable",HideCategories=("Prop"))
class OMEGADEMO_API UOmegaInteractableConfig : public UOmegaActorConfig
{
	GENERATED_BODY()
public:
	
};


UCLASS(DisplayName="Ω Interactable",HideCategories=("Prop"))
class OMEGADEMO_API AOmegaInteractable : public AOmegaGameplayActor, public IDataInterface_FlowAsset, public IDataInterface_Traits,
											public IActorInterface_Interactable
{
	GENERATED_BODY()

	UPROPERTY() UMaterialInstanceDynamic* dynaMat_PointerMesh;
	
	UPrimaryDataAsset* L_GetIdentity() const;
	bool L_IdentityUsesInteractInterface() const;
	
	UFUNCTION()
	void L_InteractionSystemEnd(UObject* Context, FString Flag);
	
public:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	AOmegaInteractable();

	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay") FOmegaBitflagsBase Flags;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay") FOmegaClassNamedLists Lists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gameplay") FOmegaActorRelatives ActorRelatives;
	virtual FOmegaActorRelatives ActorRelatives_Get_Implementation() override { return ActorRelatives; }
	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists) override;
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override;
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override;
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override;
	
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Interactable")
	void Update();
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Interactable")
	void AutosetName();
	UFUNCTION(BlueprintCallable,Category="Interactable")
	void SetPreviewColor(FColor Color);
	
	//Only interactable one per save
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	bool Oneshot;
	//Custom Bitmask Flags
	
	UPROPERTY()
	FText DisplayName;
	UPROPERTY()
	UFlowAsset* DialogueFlow=nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FColor PreviewColor=FColor::Blue;

	//If none listed, defaults to the interact type found in Omega Gameplay Settings.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,Category="Interactable")
	FGameplayTag RequiredInteractType;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,Category="Interactable")
	FVector Range=FVector(1,1,1);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,meta=(MakeEditWidget),Category="Interactable")
	FVector CameraDirection=FVector(100,0,0);
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* RangeBox;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UNiagaraComponent* NiagaraComponent;
	UPROPERTY() UTextRenderComponent* NameText;
	UPROPERTY() UUtilMeshComponent* UtilMesh;

};


UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOmegaInteractable_Preset : public UOmegaProp_Preset, public IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()
public:
	UOmegaInteractable_Preset();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Interactable")
	UFlowAsset* FlowAsset;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Interactable")
	TArray<UOmegaCondition_Interact*> InteractConditions;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Actors/Actor_Prop.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/Component_ActorConfig.h"
#include "GameFramework/Actor.h"
#include "Components/Component_ActorIdentity.h"
#include "Components/StateTreeComponent.h"
#include "Condition/Condition_Actor.h"
#include "Interfaces/I_BitFlag.h"
#include "Functions/F_Component.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interfaces/I_NamedLists.h"
#include "Subsystems/Subsystem_Actors.h"
#include "Types/Struct_CustomNamedList.h"
#include "Actor_Interactable.generated.h"

class UActorConfigComponent;
class UTextRenderComponent;
class UUtilMeshComponent;
class UOmegaCondition_Interact;
class UOmegaComponent_Interactable;


UCLASS(DisplayName="Ω Interactable",HideCategories=("Prop"))
class OMEGADEMO_API UOmegaInteractableConfig : public UOmegaActorConfig
{
	GENERATED_BODY()
public:
	
};


UCLASS(DisplayName="Ω Interactable",HideCategories=("Prop"))
class OMEGADEMO_API AOmegaInteractable : public AOmegaProp, public IDataInterface_FlowAsset, public IDataInterface_Traits,
											public IActorInterface_Interactable
{
	GENERATED_BODY()

	UPROPERTY() UMaterialInstanceDynamic* dynaMat_PointerMesh;
	
	
	UFUNCTION()
	void L_InteractionSystemEnd(UObject* Context, FString Flag);
	
public:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual UOmegaProp_Preset* L_GetPreset() override;
	AOmegaInteractable();

	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override;
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override;
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	
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
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable",DisplayName="Preset")
	UOmegaInteractable_Preset* Interactable_Preset=nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable",DisplayName="Name")
	FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	UFlowAsset* DialogueFlow=nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable")
	FColor PreviewColor=FColor::Blue;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,AdvancedDisplay,Instanced,Category="Interactable")
	TArray<UOmegaObjectTrait*> Traits;
	
	//If none listed, defaults to the interact type found in Omega Gameplay Settings.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,Category="Interactable")
	FGameplayTag RequiredInteractType;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,Category="Interactable")
	FVector Range=FVector(1,1,1);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,meta=(MakeEditWidget),Category="Interactable")
	FVector CameraDirection=FVector(100,0,0);
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCameraComponent* Camera;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Components") UActorIdentityComponent* ActorID;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components",AdvancedDisplay) UOmegaComponent_Interactable* Interactable;
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

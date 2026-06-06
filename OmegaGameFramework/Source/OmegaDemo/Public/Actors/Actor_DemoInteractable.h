// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Prop.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Components/Component_GameplayActor.h"
#include "Functions/F_Component.h"
#include "GameFramework/SpringArmComponent.h"
#include "Subsystems/Subsystem_World.h"
#include "Types/Struct_CustomNamedList.h"
#include "Actor_DemoInteractable.generated.h"

class UActorConfigComponent;
class UTextRenderComponent;
class UUtilMeshComponent;
class UStaticMeshComponent;
class UNiagaraComponent;
class UOmegaCondition_Interact;

USTRUCT(BlueprintType)
struct FOmegaInteractableConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable") UStaticMesh* StaticMesh=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable") FComponentMod_StaticMesh MeshModifiers;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable") FTransform MeshTransform;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable") bool SizeBoxToMeshBounds;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable") UNiagaraSystem* NiagaraSystem=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable") FColor Color=FColor::Blue;
	
};

UINTERFACE(DisplayName="♎Data🔴 - 👆Interactable") class UDataInterface_Interactable : public UInterface
{
	GENERATED_BODY()
public:
};

class OMEGADEMO_API IDataInterface_Interactable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category="♎I|👆Interactable",DisplayName="👆Interactable - On BeginPlay")
	int32 Interactable_OnBeginPlay(AOmegaInteractable* Actor);
	
	UFUNCTION(BlueprintNativeEvent, Category="♎I|👆Interactable",DisplayName="👆Interactable - On Construct")
	int32 Interactable_OnConstruct(AOmegaInteractable* Actor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|👆Interactable",DisplayName="👆Interactable - On Interact")
	void Interactable_OnInteraction(AOmegaInteractable* Actor,AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|👆Interactable",DisplayName="👆Interactable - Is Blocked?")
	bool Interactable_IsInteractionBlocked(AOmegaInteractable* Actor,AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context);
	
	UFUNCTION(BlueprintNativeEvent, Category="♎I|👆Interactable",DisplayName="👆Interactable - Get Config")
	FOmegaInteractableConfig Interactable_GetConfig(AOmegaInteractable* Actor);
};

UCLASS(DisplayName="Ω Interactable",HideCategories=("Prop"))
class OMEGADEMO_API AOmegaInteractable : public AOmegaGameplayActor, public IActorInterface_Interactable
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
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="👆Interactable") TScriptInterface<IDataInterface_Interactable> Preset;
	UFUNCTION(BlueprintCallable,Category="Interactable") void SetPreset(TScriptInterface<IDataInterface_Interactable> _preset);

	virtual bool IsInteractionBlocked_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="👆Interactable") FOmegaBitflagsBase Flags;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="👆Interactable") FOmegaClassNamedLists Lists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="👆Interactable") FOmegaActorRelatives ActorRelatives;
	virtual FOmegaActorRelatives ActorRelatives_Get_Implementation() override { return ActorRelatives; }
	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists);
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override {};
	
	UFUNCTION(BlueprintCallable,Category="Interactable")
	void Update();
	UFUNCTION(BlueprintCallable,Category="Interactable")
	void AutosetName();
	UFUNCTION(BlueprintCallable,Category="Interactable")
	void SetPreviewColor(FColor Color);
	
	UPROPERTY()
	FText DisplayName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="👆Interactable",AdvancedDisplay)
	FColor PreviewColor=FColor::Blue;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,Category="👆Interactable")
	FVector Range=FVector(1,1,1);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,AdvancedDisplay,meta=(MakeEditWidget),Category="👆Interactable")
	FVector CameraDirection=FVector(100,0,0);
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* RangeBox;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UNiagaraComponent* NiagaraComponent;
	UPROPERTY() UTextRenderComponent* NameText;
	UPROPERTY() UUtilMeshComponent* UtilMesh;

};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Gameplay.h"
#include "DataAssets/DA_Appearance.h"
#include "Engine/DataAsset.h"
#include "Functions/F_Component.h"
#include "Functions/F_TagEvent.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_Prop.generated.h"

class UActorConfigComponent;
class UOAsset_Appearance;
class UNiagaraSystem;
class UStateTreeComponent;
class UOmegaSaveableComponent;
class UNiagaraComponent;
class UBoxComponent;
class UAudioComponent;

UCLASS(DisplayName="Ω Prop")
class OMEGAGAMEFRAMEWORK_API UOmegaProp_Preset : public UOmegaDataAsset, public IDataInterface_AppearanceSource
{
	GENERATED_BODY()

	void L_setBoundsFromComp(UBoxComponent* bounds, USceneComponent* comp,FBoxSphereBounds BoxBounds);
	void L_InitToSocket(USceneComponent* target, USceneComponent* socket_source,FName socket);

public:
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") bool SetRangeToMeshBounds=false;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") bool bCanTick=false;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	TEnumAsByte<ECollisionEnabled::Type> CollisionType=ECollisionEnabled::NoCollision;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	TEnumAsByte<EComponentMobility::Type> Mobility=EComponentMobility::Type::Static;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	FTransform BoundsScale;
	
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Prop")
	UComponentModScript_StaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Prop")
	UComponentModScript_SkeletalMesh* SkeletalMesh;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	USoundBase* Audio;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop")
	UNiagaraSystem* Niagara;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Appearance")
	UOAsset_Appearance* Appearance_Preset;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Appearance")
	UOAsset_Appearance* Appearance_Custom;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop",AdvancedDisplay) FName Audio_AttachSocket=TEXT("root_fx");
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop",AdvancedDisplay) FName Niagara_AttachSocket=TEXT("root_fx");
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifiers")
	TArray<UActorModifierScript*> Mods_Construct;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modifiers")
	TArray<UActorModifierScript*> Mods_BeginPlay;

	void Apply(AOmegaProp* prop);

	
	void aConstruct(AOmegaProp* a);
	void aBeginPlay(AOmegaProp* a);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaProp : public AOmegaGameplayActor, public IActorTagEventInterface, public IDataInterface_AppearanceSource
{
	GENERATED_BODY()

public:
	virtual UOAsset_Appearance* GetAppearanceAsset_Implementation() override;
	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual UOmegaProp_Preset* L_GetPreset();
	
	AOmegaProp();
	
	// Components
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* RangeBox;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* MeshStatic;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USkeletalMeshComponent* MeshSkeletal;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UAudioComponent* Audio;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UNiagaraComponent* Niagara;
	
	//properties
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") UOmegaProp_Preset* Preset=nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay") FOmegaBitflagsBase Flags;
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Gameplay") FOmegaClassNamedLists Lists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gameplay") FOmegaActorRelatives ActorRelatives;
	virtual FOmegaActorRelatives ActorRelatives_Get_Implementation() override { return ActorRelatives; }
	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists) override;
};


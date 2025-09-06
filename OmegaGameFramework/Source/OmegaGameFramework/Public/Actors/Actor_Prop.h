// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Functions/OmegaFunctions_TagEvent.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Actor_Prop.generated.h"

class UNiagaraSystem;
class UStateTreeComponent;
class UOmegaSaveableComponent;
class UNiagaraComponent;
class UBoxComponent;

UCLASS(DisplayName="Ω Prop")
class OMEGAGAMEFRAMEWORK_API UOmegaProp_Preset : public UOmegaDataAsset
{
	GENERATED_BODY()

	void L_setBoundsFromComp(UBoxComponent* bounds, USceneComponent* comp,FBoxSphereBounds BoxBounds);
	void L_InitToSocket(USceneComponent* target, USceneComponent* socket_source,FName socket);

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") bool SetRangeToMeshBounds=false;
		
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
class OMEGAGAMEFRAMEWORK_API AOmegaProp : public AActor, public IActorTagEventInterface
{
	GENERATED_BODY()

public:
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
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UOmegaSaveableComponent* Saveable;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStateTreeComponent* StateTree;

	//properties
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Prop") UOmegaProp_Preset* Preset=nullptr;
	
};


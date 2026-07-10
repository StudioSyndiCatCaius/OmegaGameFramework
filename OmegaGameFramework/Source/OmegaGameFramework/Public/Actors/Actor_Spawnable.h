// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Gameplay.h"
#include "GameFramework/Actor.h"
#include "Actor_Spawnable.generated.h"

class UOmegaFlowAssetBase;
class UOmegaZoneData;

USTRUCT(BlueprintType)
struct FOmegaSpawnableConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable",meta=(MustImplement="/Script/OmegaGameFramework.ActorInterface_Spawnable"))
	TSubclassOf<AActor> Class;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TObjectPtr<UPrimaryDataAsset> Identity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TSoftObjectPtr<UOmegaFlowAssetBase> Flow;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TObjectPtr<UOmegaZoneData> Zone;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TArray<FName> Tags;
	
	UPROPERTY() FOmegaBitflagsBase Bitflags;
	UPROPERTY() FOmegaClassNamedLists Lists;
	UPROPERTY() FOmegaActorRelatives Relatives;
	
};


USTRUCT(BlueprintType)
struct FOmegaSpawnableSpawnConfig
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) bool bAutospawn=true;
	
	
	//implement later. This means, if Zone is used, this actor will  spawned on zone load and despawned on zone exit
	UPROPERTY() bool bConsineToZone=true;
};



USTRUCT(BlueprintType)
struct FOmegaSpawnablePreviewConfig
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FString Label;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FLinearColor Color=FLinearColor::White;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FVector RangeOffset = FVector::ZeroVector;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) FVector RangeSize=FVector(50,50,95);
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) float LineThickness=1;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) TObjectPtr<UTexture2D> Icon;
	UPROPERTY(BlueprintReadWrite, Category="Spawnable", EditAnywhere) float IconSize=2;
	
};



class UArrowComponent;
class UBoxComponent;
class UTextRenderComponent;
// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI, DisplayName="♎Actor🔵 - Spawnable") class UActorInterface_Spawnable : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_Spawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable",DisplayName="Spawnable - On Spawn")
	void OnSpawnableSpawn(AOmegaActorSpawnable* Spawner);
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable",DisplayName="Spawnable - Get Preview Config")
	FOmegaSpawnablePreviewConfig GetSpawnablePreviewConfig();
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable",DisplayName="Spawnable - Get Spawn Config")
	void GetSpawnableSpawnConfig(bool& bAutospawn);
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable",DisplayName="Spawnable - Get Actor Label")
	FString GetSpawnable_ActorLabel();
};


UCLASS(HideCategories=(Replication,Collision,HLOD,Physics,Networking,Input,Rendering,LevelInstance,Cooking,WorldPartition,DataLayers))
class OMEGAGAMEFRAMEWORK_API AOmegaActorSpawnable : public AActor
{
	GENERATED_BODY()

	UPROPERTY() AActor* REF_linkedActor=nullptr;
	UPROPERTY() AActor* REF_Default=nullptr;
	bool L_ClassUsesInterface() const;
public:
	AOmegaActorSpawnable();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure,Category="Spawnable")
	bool Spawnable_IsAlive() const;
	UFUNCTION(BlueprintCallable,Category="Spawnable")
	void Spawnable_Spawn(bool bForceRespawn);
	UFUNCTION(BlueprintCallable,Category="Spawnable")
	void Spawnable_Destroy();
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USceneComponent* RootComp;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* DisplayRoot;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBillboardComponent* BillboardComponent;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UTextRenderComponent* TextRenderComponent;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UArrowComponent* ArrowComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable", meta=(ShowOnlyInnerProperties))
	FOmegaSpawnableConfig Config;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	int32 id;
};

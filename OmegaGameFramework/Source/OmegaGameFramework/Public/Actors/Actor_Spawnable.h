// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Gameplay.h"
#include "GameFramework/Actor.h"
#include "Types/Struct_SpawnableTypeConfig.h"
#include "Actor_Spawnable.generated.h"

class UOmegaFlowAssetBase;
class UOmegaZoneData;

USTRUCT(BlueprintType)
struct FOmegaSpawnableConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable",meta=(GetOptions="L_getSpawnables"))
	FName SpawnableID;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TObjectPtr<UPrimaryDataAsset> Identity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TSoftObjectPtr<UOmegaFlowAssetBase> Flow;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TObjectPtr<UOmegaZoneData> Zone;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable") FOmegaBitflagsBase Bitflags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable") FOmegaClassNamedLists Lists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable") FOmegaActorRelatives Relatives;
	
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
	void OnSpawnableSpawn(AOmegaActorSpawnable* Spawner, const FString& Flag);
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable",DisplayName="Spawnable - Get Preview Config")
	void GetSpawnablePreviewConfig(UTexture2D*& Icon, FVector& RootOffset, FText& Name,FColor& Color,float& IconScale,FVector& BoxExtent,float& BoxThickness);
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
	TSubclassOf<AActor> GetSpawnableClass();
	FOmegaSpawnableTypeConfig GetSpawnableTypeConfig(bool& valid);
	bool L_ClassUsesInterface();
public:
	UFUNCTION() TArray<FName> L_getSpawnables() const;
	AOmegaActorSpawnable();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable,CallInEditor,Category="Spawnable") void UpdateWorldLabel();
	
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
	FString Flag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	int32 id;
};

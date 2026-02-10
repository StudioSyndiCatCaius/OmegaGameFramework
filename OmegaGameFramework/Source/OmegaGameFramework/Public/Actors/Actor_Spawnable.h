// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Gameplay.h"
#include "GameFramework/Actor.h"
#include "Actor_Spawnable.generated.h"


class UArrowComponent;
class UBoxComponent;
class UTextRenderComponent;
// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UActorInterface_Spawnable : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IActorInterface_Spawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable")
	void OnSpawnableSpawn(AOmegaActorSpawnable* Spawner, const FString& Flag);
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable")
	void GetSpawnablePreviewConfig(UTexture2D*& Icon, FVector& RootOffset, FText& Name,FColor& Color,float& IconScale,FVector& BoxExtent,float& BoxThickness);
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable")
	void GetSpawnableSpawnConfig(bool& bAutospawn);
	UFUNCTION(BlueprintNativeEvent, Category="ΩI|Spawnable")
	FString GetSpawnable_ActorLabel();
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaActorSpawnable : public AActor
{
	GENERATED_BODY()

	UPROPERTY() AActor* REF_linkedActor=nullptr;
	UPROPERTY() AActor* REF_Default=nullptr;
	
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
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable",meta=(MustImplement="ActorInterface_Spawnable"))
	TSubclassOf<AActor> SpawnableClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	FString Flag;
};

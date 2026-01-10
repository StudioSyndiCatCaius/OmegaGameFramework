// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_ActorConfig.h"
#include "Functions/F_Component.h"
#include "GameFramework/Actor.h"
#include "Actor_Openable.generated.h"

class UBoxComponent;
class UDataAssetCollectionComponent;
class UActorStateComponent;
class UArrowComponent;
class UOmegaSaveStateComponent;
class UCurveFloat;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaOpenableStyle : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Openable") UComponentModScript_SkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable") UAnimSequence* Anim_Open;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable") FTransform RangeTransform;
	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable") UAnimSequence* Anim_Close;

	void Apply(AOmegaOpenableActor* Actor);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaOpenable_Config : public UOmegaActorConfig
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable")
	TArray<TSubclassOf<AActor>> AutoOpenFor_Actors;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable")
	TArray<TSubclassOf<AController>> AutoOpenFor_Controllers;
	
	void Apply(AOmegaOpenableActor* Actor);
	bool CanOpen(AOmegaOpenableActor* Openable,AActor* TargetActor);
	bool CanAutoOpen(AOmegaOpenableActor* Openable,AActor* TargetActor);
	
};





UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AOmegaOpenableActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY() float l_blendVal;
	UPROPERTY() bool l_openForward;
	UPROPERTY() bool L_IsOpening;

	void L_Init();
	float F_GetMaxOpenTime() const
	{
		if(Mesh->AnimationData.AnimToPlay)
		{
			return Mesh->AnimationData.AnimToPlay->GetPlayLength();
		}
		return 1.0f;
	}

	UOmegaOpenable_Config* GetConfig() const;

public:
	AOmegaOpenableActor();
	
	UFUNCTION() void N_ActorOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION() void N_ActorOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,Category="Openable") bool bStartOpen;
	UPROPERTY(EditAnywhere,Category="Openable") bool bLocked;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Openable") UOmegaOpenable_Config* Config;
	
	UFUNCTION(BlueprintNativeEvent,Category="Openable") UOmegaOpenableStyle* GetOpenableStyle();
	UFUNCTION(BlueprintNativeEvent,Category="Openable") void OnOpenBegin(bool bForward);
	UFUNCTION(BlueprintNativeEvent,Category="Openable") void OnOpenEnd(bool bForward);
	UFUNCTION(BlueprintNativeEvent,Category="Openable") void OnOpenUpdate(float time,bool bForward);
	
	UFUNCTION(BlueprintPure,Category="Openable")
	bool CanOpen() const;
	UFUNCTION(BlueprintCallable,Category="Openable")
	void SetLocked(bool Locked);
	
	UFUNCTION(BlueprintCallable,Category="Openable")
	void StartOpening(bool bForward=true,bool bSnap=false);
	UFUNCTION(BlueprintCallable,Category="Openable")
	void SetAnimPosition(float position);
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Openable") USkeletalMeshComponent* Mesh;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Openable") UBoxComponent* Range;
};

// ====================================================================================================================
// DOOR
// ====================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaOpenable_Door_Style : public UOmegaOpenableStyle
{
	GENERATED_BODY()

public:
	
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaOpenable_Door : public AOmegaOpenableActor
{
	GENERATED_BODY()

	virtual UOmegaOpenableStyle* GetOpenableStyle_Implementation() override { return Style;};
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Openable")
	UOmegaOpenable_Door_Style* Style;
};

// ====================================================================================================================
// Chest
// ====================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaOpenable_Chest_Style : public UOmegaOpenableStyle
{
	GENERATED_BODY()

public:
	
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOActor_Chest : public AOmegaOpenableActor
{
	GENERATED_BODY()

	virtual UOmegaOpenableStyle* GetOpenableStyle_Implementation() override { return Style;};
public:
	AOActor_Chest();
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable",AdvancedDisplay) UDataAssetCollectionComponent* Inventory;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Openable")
	UOmegaOpenable_Chest_Style* Style;
};
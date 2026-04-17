// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_Component.h"
#include "GameFramework/Actor.h"
#include "Actor_Openable.generated.h"

class UBoxComponent;
class UDataAssetCollectionComponent;
class UActorStateComponent;
class UArrowComponent;
class UOmegaSaveStateComponent;
class UCurveFloat;
class UAnimSequence;

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



public:
	AOmegaOpenableActor();
	
	UFUNCTION() void N_ActorOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION() void N_ActorOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,Category="Openable") bool bStartOpen;
	UPROPERTY(EditAnywhere,Category="Openable") bool bLocked;
	
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


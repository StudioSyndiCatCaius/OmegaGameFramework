// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_Component.h"
#include "GameFramework/Actor.h"
#include "Actor_Openable.generated.h"

class UBoxComponent;
class UDataAssetCollectionComponent;
class UArrowComponent;
class UOmegaSaveStateComponent;
class UCurveFloat;
class UAnimSequence;

// A data asset defining the visual style of an openable actor: the skeletal mesh, open animation, and range transform.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaOpenableStyle : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Script that assigns the skeletal mesh to the openable actor.
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Openable") UComponentModScript_SkeletalMesh* Mesh;
	// Animation played when the actor opens (forward direction).
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable") UAnimSequence* Anim_Open;
	// Transform applied to the interaction range box relative to the actor root.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Openable") FTransform RangeTransform;

	void Apply(AOmegaOpenableActor* Actor);
};




// Abstract base for door/chest-style actors that play a skeletal animation when opened or closed.
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
	// When true, the actor starts in the fully open state at BeginPlay.
	UPROPERTY(EditAnywhere,Category="Openable") bool bStartOpen;
	// When true, StartOpening calls are ignored and the actor cannot be opened.
	UPROPERTY(EditAnywhere,Category="Openable") bool bLocked;

	// Returns the style asset defining this openable's mesh and animations. Override in Blueprint to provide dynamic styles.
	UFUNCTION(BlueprintNativeEvent,Category="Openable") UOmegaOpenableStyle* GetOpenableStyle();
	// Called in Blueprint or C++ when the open animation begins; bForward is true when opening, false when closing.
	UFUNCTION(BlueprintNativeEvent,Category="Openable") void OnOpenBegin(bool bForward);
	// Called in Blueprint or C++ when the open animation finishes.
	UFUNCTION(BlueprintNativeEvent,Category="Openable") void OnOpenEnd(bool bForward);
	// Called each tick during the open animation; time is the normalized 0–1 playback position.
	UFUNCTION(BlueprintNativeEvent,Category="Openable") void OnOpenUpdate(float time,bool bForward);

	// Returns true if the actor is unlocked and not currently in the middle of an animation.
	UFUNCTION(BlueprintPure,Category="Openable")
	bool CanOpen() const;
	// Sets the locked state. When locked, the actor ignores open/close requests.
	UFUNCTION(BlueprintCallable,Category="Openable")
	void SetLocked(bool Locked);

	// Starts the open or close animation. Pass bSnap=true to skip the animation and jump to the end pose.
	UFUNCTION(BlueprintCallable,Category="Openable")
	void StartOpening(bool bForward=true,bool bSnap=false);
	// Scrubs the open animation to a specific normalized (0–1) position without playing it.
	UFUNCTION(BlueprintCallable,Category="Openable")
	void SetAnimPosition(float position);

	// The skeletal mesh component that plays the open/close animation.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Openable") USkeletalMeshComponent* Mesh;
	// Box component defining the interaction trigger area around the openable.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Openable") UBoxComponent* Range;
};

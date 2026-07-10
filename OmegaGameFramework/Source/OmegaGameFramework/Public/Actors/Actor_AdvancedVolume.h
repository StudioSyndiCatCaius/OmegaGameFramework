// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaActors.h"
#include "Misc/OmegaUtils_Volume.h"
#include "GameFramework/Actor.h"
#include "Actor_AdvancedVolume.generated.h"

class UTextRenderComponent;
class UBillboardComponent;
class UBoxComponent;
class USphereComponent;

// Abstract base for volume actors that render as a colored shape in the editor and expose overlap detection.
UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AAdvancedVolume : public AOmegaActorBASE
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAdvancedVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY() UStaticMesh* ShapeMeshRef_sphere;
	UPROPERTY() UStaticMesh* ShapeMeshRef_box;
	UPROPERTY() UMaterialInterface* VolumeMaterial_ref;
	UPROPERTY() UStaticMesh* ShapeMeshRef;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Controls whether the volume renders as a sphere or a box.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Volume")
	EVolumeShape Shape;
	// The tint color applied to the volume's debug visualization material.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Volume")
	FLinearColor Color;

	// Changes the volume's debug visualization color at runtime.
	UFUNCTION(BlueprintCallable, Category="Volume") void SetColor(FLinearColor NewColor);

	UPROPERTY()
	TEnumAsByte<ECollisionChannel> CollisionType;

	// The static mesh component that visualizes the volume shape in the editor.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* Volume;
	// Text render component used to display a label above the volume in the editor.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UTextRenderComponent* TextDisplay;
	// Billboard icon shown in the editor viewport for this volume.
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBillboardComponent* IconDisplay;
	UPROPERTY() UBoxComponent* Bounds_box;
	UPROPERTY() USphereComponent* Bounds_sphere;
};

// ====================================================================================================
// Global Event
// ====================================================================================================

// A volume that fires a named global event and/or a gameplay tag event when any actor enters it.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AVolumeTrigger_GlobalEvent : public AAdvancedVolume
{
	GENERATED_BODY()

	AVolumeTrigger_GlobalEvent();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:

	// Named event broadcast globally when an actor enters this volume.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="GlobalEvent") FName Event_Named;
	// Gameplay tag event broadcast globally when an actor enters this volume.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="GlobalEvent") FGameplayTag Event_Tag;

};

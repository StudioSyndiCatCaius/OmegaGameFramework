// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Misc/OmegaUtils_Volume.h"
#include "GameFramework/Actor.h"
#include "Actor_AdvancedVolume.generated.h"

class UTextRenderComponent;
class UBillboardComponent;

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API AAdvancedVolume : public AActor
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Volume")
	EVolumeShape Shape;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Volume")
	FLinearColor Color;
	UPROPERTY()
	TEnumAsByte<ECollisionChannel> CollisionType;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Volume")
	UTexture2D* GetVolumeIcon();
	UFUNCTION(BlueprintImplementableEvent, Category="Volume")
	FText GetVolumeText();
	
	UPROPERTY() UStaticMeshComponent* Volume;
	UPROPERTY() UBoxComponent* Bounds_box;
	UPROPERTY() USphereComponent* Bounds_sphere;
	UPROPERTY() UTextRenderComponent* TextDisplay;
	UPROPERTY() UBillboardComponent* IconDisplay;
};

// ====================================================================================================
// Global Event
// ====================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API AVolumeTrigger_GlobalEvent : public AAdvancedVolume
{
	GENERATED_BODY()

	AVolumeTrigger_GlobalEvent();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="GlobalEvent") FName Event_Named;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="GlobalEvent") FGameplayTag Event_Tag;
	
};
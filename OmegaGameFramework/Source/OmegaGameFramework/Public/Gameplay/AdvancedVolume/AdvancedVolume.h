// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VolumeUtils.h"
#include "GameFramework/Actor.h"
#include "AdvancedVolume.generated.h"

class UTextRenderComponent;
class UBillboardComponent;

UCLASS()
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

	UPROPERTY()
	UStaticMesh* ShapeMeshRef_sphere;
	UPROPERTY()
	UStaticMesh* ShapeMeshRef_box;
	UPROPERTY()
	UMaterialInterface* VolumeMaterial_ref;
	UPROPERTY()
	UStaticMesh* ShapeMeshRef;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Volume")
	EVolumeShape Shape;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Volume")
	FLinearColor Color;
	UPROPERTY()
	TEnumAsByte<ECollisionChannel> CollisionType;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Volume")
	UTexture2D* GetVolumeIcon();
	UFUNCTION(BlueprintImplementableEvent, Category="Volume")
	FText GetVolumeText();
	
	UPROPERTY()
	UStaticMeshComponent* Volume;
	UPROPERTY()
	UTextRenderComponent* TextDisplay;
	UPROPERTY()
	UBillboardComponent* IconDisplay;
};

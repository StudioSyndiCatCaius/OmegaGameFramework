// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "Functions/F_Component.h"
#include "Materials/MaterialInterface.h"
#include "modifiers_component.generated.h"

class UOmegaBodyType;
class USkeletalMesh;
class UMaterialInterface;

UCLASS(DisplayName="(🧍 Skeletal Mesh Mod) Mesh")
class OMEGADEMO_API USkelMeshMod_Mesh : public UComponentModScript_SkeletalMesh
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") TSoftObjectPtr<USkeletalMesh> SkeletalMesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") TArray<UMaterialInterface*> Materials;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") TMap<FName,UMaterialInterface*> Materials_BySlot;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod",meta=(InlineEditConditionToggle)) bool bEditLocation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod",meta=(InlineEditConditionToggle)) bool bEditRotation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod",meta=(InlineEditConditionToggle)) bool bEditScale;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod",meta=(EditCondition="bEditLocation")) FVector Location=FVector(0,0,45);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod",meta=(EditCondition="bEditRotation")) FRotator Rotation=FRotator(0,0,-90);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod",meta=(EditCondition="bEditScale")) FVector Scale=FVector(1,1,1);
	
	virtual bool OnAppliedToComponent_Implementation(USkeletalMeshComponent* Component) const override;
};

UCLASS(DisplayName="(🧍 Skeletal Mesh Mod) Body Type Generated")
class OMEGADEMO_API USkelMeshMod_BodyTypeGenerate : public UComponentModScript_SkeletalMesh
{
	GENERATED_BODY()
public:
	
	virtual bool OnAppliedToComponent_Implementation(USkeletalMeshComponent* Component) const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") TSoftObjectPtr<UOmegaBodyType> BodyType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod",meta=(EditCondition="!UseActorSeed")) int32 Seed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") bool UseActorSeed;

};


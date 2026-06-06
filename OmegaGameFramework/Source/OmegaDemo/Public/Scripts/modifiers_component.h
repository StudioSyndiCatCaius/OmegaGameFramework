// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "Functions/F_Component.h"
#include "modifiers_component.generated.h"


UCLASS(DisplayName="(🧍 Skeletal Mesh Mod) Mesh")
class OMEGADEMO_API USkelMeshMod_Mesh : public UComponentModScript_SkeletalMesh
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mod") USkeletalMesh* SkeletalMesh;
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

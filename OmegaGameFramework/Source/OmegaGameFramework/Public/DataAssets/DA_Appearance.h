// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_AssetLib.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Misc/GeneralDataObject.h"
#include "Kismet/KismetMathLibrary.h"
#include "DA_Appearance.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOAsset_Appearance : public UOmegaDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	FComponentMod_SkeletalMesh Mesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_Animation* Library_Anim;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_Sound* Library_Voice;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Appearance")
	UOmegaAssetLibrary_SlateBrush* Library_Slate;
};

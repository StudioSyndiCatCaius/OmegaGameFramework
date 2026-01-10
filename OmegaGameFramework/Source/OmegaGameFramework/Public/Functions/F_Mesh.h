// Copyright Studio Syndicat 2021. All Rights Reserved.

// Common Use Gameplay Functions

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Mesh.generated.h"





UCLASS()
class UOmegaMeshFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Mesh_Skeletal")
	static void AddCurvesToSkeletonFromMorphs(USkeletalMesh* targetMesh);

	/**
	 * Copies bone transforms from source skeletal mesh asset to target skeletal mesh asset
	 * Modifies the reference pose of the target mesh
	 * 
	 * @param From - The skeletal mesh asset to copy transforms from
	 * @param To - The skeletal mesh asset to copy transforms to
	 * @param bCopyLocation - Whether to copy bone locations
	 * @param bCopyRotation - Whether to copy bone rotations
	 * @param bCopyScale - Whether to copy bone scale
	 * @return True if the copy operation was successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Omega|Mesh_Skeletal")
	static bool CopyBoneTransforms(
		USkeletalMesh* From,
		USkeletalMesh* To,
		bool bCopyLocation = false,
		bool bCopyRotation = true,
		bool bCopyScale = false
	);

	//UFUNCTION(BlueprintCallable, Category = "Omega|Mesh_Skeletal")
	//static void DeleteBoneAnimations(UAnimSequence* anim, FName bone);

};

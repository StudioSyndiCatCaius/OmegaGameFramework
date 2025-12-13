// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Mesh.h"
#include "Engine/Texture2D.h"
#include "ImageUtils.h"
#include "RenderUtils.h"

void UOmegaMeshFunctions::AddCurvesToSkeletonFromMorphs(USkeletalMesh* targetMesh)
{
	if(targetMesh)
	{
		for(FString mt : targetMesh->K2_GetAllMorphTargetNames())
		{
			targetMesh->GetSkeleton()->AddCurveMetaData(*mt);
			
			FCurveMetaData* md=targetMesh->GetSkeleton()->GetCurveMetaData(*mt);
			md->Type.bMorphtarget=true;
		}
	}
}

bool UOmegaMeshFunctions::CopyBoneTransforms(USkeletalMesh* From, USkeletalMesh* To, bool bCopyLocation,
    bool bCopyRotation, bool bCopyScale)
{
    // Validate input parameters
    if (!From || !To)
    {
        UE_LOG(LogTemp, Warning, TEXT("CopyBoneTransforms: Source or Target mesh is null"));
        return false;
    }

    // Early exit if nothing to copy
    if (!bCopyLocation && !bCopyRotation && !bCopyScale)
    {
        UE_LOG(LogTemp, Warning, TEXT("CopyBoneTransforms: No transform components selected for copying"));
        return false;
    }

    // Get the reference skeletons
    const FReferenceSkeleton& SourceSkeleton = From->GetRefSkeleton();
    FReferenceSkeleton& TargetSkeleton = To->GetRefSkeleton();

    // Get reference pose arrays
    const TArray<FTransform>& SourceRefPose = SourceSkeleton.GetRefBonePose();
    TArray<FTransform> TargetRefPose = TargetSkeleton.GetRefBonePose();

    int32 CopiedBones = 0;

    // Mark the target mesh for modification
    To->Modify();

    // Iterate through all bones in the target skeleton
    for (int32 TargetBoneIndex = 0; TargetBoneIndex < TargetSkeleton.GetNum(); TargetBoneIndex++)
    {
        const FName& TargetBoneName = TargetSkeleton.GetBoneName(TargetBoneIndex);
        
        // Find corresponding bone in source skeleton
        const int32 SourceBoneIndex = SourceSkeleton.FindBoneIndex(TargetBoneName);
        
        if (SourceBoneIndex != INDEX_NONE && SourceBoneIndex < SourceRefPose.Num())
        {
            // Get the source and target transforms
            const FTransform& SourceTransform = SourceRefPose[SourceBoneIndex];
            FTransform& TargetTransform = TargetRefPose[TargetBoneIndex];

            // Create new transform by selectively copying components
            FTransform NewTransform = TargetTransform;

            if (bCopyLocation)
            {
                NewTransform.SetLocation(SourceTransform.GetLocation());
            }

            if (bCopyRotation)
            {
                NewTransform.SetRotation(SourceTransform.GetRotation());
            }

            if (bCopyScale)
            {
                NewTransform.SetScale3D(SourceTransform.GetScale3D());
            }

            // Apply the new transform to the reference pose
            TargetRefPose[TargetBoneIndex] = NewTransform;
            CopiedBones++;
        }
    }

    if (CopiedBones > 0)
    {
        // Rebuild the reference skeleton to reflect changes
        TargetSkeleton.RebuildRefSkeleton(To->GetSkeleton(), true);
        
        // Mark the mesh as needing to be saved
        To->MarkPackageDirty();
        
        // Force a rebuild of the mesh
        To->InvalidateDeriveDataCacheGUID();
        To->PostEditChange();
    }

    UE_LOG(LogTemp, Log, TEXT("CopyBoneTransforms: Successfully copied transforms for %d bones"), CopiedBones);
    return CopiedBones > 0;
}


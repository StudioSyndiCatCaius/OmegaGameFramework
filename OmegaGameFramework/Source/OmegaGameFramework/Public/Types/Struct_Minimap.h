
#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Struct_Minimap.generated.h"

class UMaterialInterface;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FOmegaMinimapActorConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Material")
	bool UseMinimapMesh=false;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Material",meta=(EditCondition="UseMinimapMesh"))
	TSoftObjectPtr<UStaticMesh> MinimapMesh;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Material",meta=(EditCondition="UseMinimapMesh"))
	TArray<TSoftObjectPtr<UMaterialInterface>> MinimapMeshMaterials;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Material",meta=(EditCondition="UseMinimapMesh"))
	FTransform MeshOffset;
	
	FOmegaMinimapActorConfig()
	{
		
		FString AssetPathString = TEXT("/OmegaGameFramework/Meshes/util/minimap/sm_OMEGA_minimapActor.sm_OMEGA_minimapActor");
		FSoftObjectPath MyAssetPath(AssetPathString);
		MinimapMesh = MyAssetPath; 
		
		MeshOffset.SetTranslation(FVector(0,0,5000));
	}
};
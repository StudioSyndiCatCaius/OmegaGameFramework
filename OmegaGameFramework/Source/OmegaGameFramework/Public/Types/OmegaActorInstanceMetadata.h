// OmegaActorInstanceMetadata.h
#pragma once

#include "CoreMinimal.h"
#include "OmegaActorInstanceMetadata.generated.h"

USTRUCT(BlueprintType)
struct FOmegaActorInstanceMetadata
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metadata")
	TMap<FName, bool> BoolParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metadata")
	TMap<FName, int32> IntParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metadata")
	TMap<FName, float> FloatParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metadata")
	TMap<FName, FString> StringParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metadata")
	TMap<FName, UPrimaryDataAsset*> DataAssetParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metadata")
	TMap<FName, TSoftObjectPtr<AActor>> ActorParams;

	// Function to check if metadata is empty
	bool IsMetadataEmpty() const
	{
		return BoolParams.Num() == 0 && 
			   IntParams.Num() == 0 && 
			   FloatParams.Num() == 0 && 
			   StringParams.Num() == 0 && 
			   DataAssetParams.Num() == 0 && 
			   ActorParams.Num() == 0;
	}
};
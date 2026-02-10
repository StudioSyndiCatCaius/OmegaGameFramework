// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaUtils_Volume.generated.h"

UENUM(BlueprintType)
enum class EVolumeShape : uint8
{
	OmegaVolume_Sphere          UMETA(DisplayName = "Sphere"),
	OmegaVolume_Box				UMETA(DisplayName = "Box"),
};

USTRUCT(BlueprintType)
struct FVolumeSphereData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Volume") FName VolumeName;
	UPROPERTY(BlueprintReadWrite, Category = "Volume") FVector WorldLocation=FVector();
	UPROPERTY(BlueprintReadWrite, Category = "Volume") float Radius=0.0f;

};

USTRUCT(BlueprintType)
struct FVolumeBoxData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Volume") FName VolumeName;
	UPROPERTY(BlueprintReadWrite, Category = "Volume") FVector WorldLocation=FVector(); 
	UPROPERTY(BlueprintReadWrite, Category = "Volume") FRotator WorldRotation=FRotator();
	UPROPERTY(BlueprintReadWrite, Category = "Volume") FVector BoxExtent=FVector::Zero();
};

class OMEGAGAMEFRAMEWORK_API VolumeUtils
{
public:
	VolumeUtils();
	~VolumeUtils();

};

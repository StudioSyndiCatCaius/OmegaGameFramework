// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "VolumeUtils.generated.h"

UENUM(BlueprintType)
enum class EVolumeShape : uint8

{
	/** Description. */
	OmegaVolume_Sphere            UMETA(DisplayName = "Sphere"),
	/** Description. */
	OmegaVolume_Box            UMETA(DisplayName = "Box"),

};

USTRUCT(BlueprintType)
struct FVolumeSphereData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Volume")
		FName VolumeName;

	UPROPERTY(BlueprintReadWrite, Category = "Volume")
		FVector WorldLocation;

	UPROPERTY(BlueprintReadWrite, Category = "Volume")
		float Radius;

};

USTRUCT(BlueprintType)
struct FVolumeBoxData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Volume")
		FName VolumeName;

	UPROPERTY(BlueprintReadWrite, Category = "Volume")
		FVector WorldLocation;

	UPROPERTY(BlueprintReadWrite, Category = "Volume")
		FRotator WorldRotation;

	UPROPERTY(BlueprintReadWrite, Category = "Volume")
		FVector BoxExtent;
};

class OMEGAGAMEFRAMEWORK_API VolumeUtils
{
public:
	VolumeUtils();
	~VolumeUtils();

};

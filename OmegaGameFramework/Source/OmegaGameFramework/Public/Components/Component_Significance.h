// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Component_Significance.generated.h"


UENUM(BlueprintType)
enum EOmegaSignificanceLevel : uint8
{
	SIGNIFICANCE_MAX, //full tick and functionality
	SIGNIFICANCE_HIGH, //near full tick and functionality
	SIGNIFICANCE_MEDIUM,
	SIGNIFICANCE_LOW,
	SIGNIFICANCE_MIN,
};


USTRUCT(BlueprintType)
struct FOmegaSignificanceLevelConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Significance")
	float TickRate=1.0f;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSignificanceProfile : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Significance")
	TMap<TEnumAsByte<EOmegaSignificanceLevel>,FOmegaSignificanceLevelConfig> LevelConfigs;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),DisplayName="Significance (*WIP)")
class OMEGAGAMEFRAMEWORK_API USignificanceComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	USignificanceComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	//By default, get Profile from OmegaSettings, but can be manually overriden here.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Significance")
	TObjectPtr<UOmegaSignificanceProfile> OverrideSignificanceProfile;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Kismet/KismetMathLibrary.h"
#include "AssetScalarComponent.generated.h"



UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UAssetScalarComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//USubscriptComponent();

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	                           

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Scalar")
	TMap<UPrimaryDataAsset*, float> AssetValues;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Scalar")
	float MinValue=0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Scalar")
	float MaxValue=1;

	UFUNCTION(BlueprintCallable, Category="Asset Scalar")
	void AdjustAssetScaleValue(UPrimaryDataAsset* Asset, float Amount);

	UFUNCTION(BlueprintPure, Category="Asset Scalar")
	float GetAssetScaleValue(UPrimaryDataAsset* Asset);
};

inline void UAssetScalarComponent::AdjustAssetScaleValue(UPrimaryDataAsset* Asset, float Amount)
{
	if (Asset)
	{
		const float CurVal = AssetValues.FindOrAdd(Asset);
		AssetValues.Add(Asset,UKismetMathLibrary::Clamp(Amount+CurVal,MinValue,MaxValue));
	}
}

inline float UAssetScalarComponent::GetAssetScaleValue(UPrimaryDataAsset* Asset)
{
	return AssetValues.FindOrAdd(Asset);
}

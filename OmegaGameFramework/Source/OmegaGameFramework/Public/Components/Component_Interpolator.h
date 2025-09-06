// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_Interpolator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInterpolatorUpdate, UInterpolatorComponent*, Component, float, alpha);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UInterpolatorComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() float f_valCurrent;
	UPROPERTY() float f_valTarget;
	
public:
	UInterpolatorComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable) FOnInterpolatorUpdate OnInterpolatorUpdate;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interpolator")
	float MinValue=0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interpolator")
	float MaxValue=0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interpolator")
	float InterpSpeed=0;

	UFUNCTION(BlueprintCallable,Category="Interpolator")
	void AddValue(float amount);
	UFUNCTION(BlueprintCallable,Category="Interpolator")
	void SetValue(float amount);
	
	UFUNCTION(BlueprintPure,Category="Interpolator")
	float GetValue() const { return f_valCurrent;};
};

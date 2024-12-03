// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "Widget_DynamicMeter.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDynamicProgressMeter : public UImage, public FTickableGameObject
{
	GENERATED_BODY()

	virtual void Tick(float DeltaTime) override;
	
	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables );
	}
	virtual bool IsTickableWhenPaused() const
	{
		return false;
	}
	virtual bool IsTickableInEditor() const
	{
		return false;
	}

public:
	virtual void OnWidgetRebuilt() override;
	
	UFUNCTION(BlueprintCallable,Category="DynamicProgressMeter")
	void SetPercent_Progress(const float& value);
	UFUNCTION(BlueprintCallable,Category="DynamicProgressMeter")
	void SetPercent_Ghost(const float& value);
	
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter", FieldNotify, Setter, BlueprintSetter="SetPercent_Progress")
	float Percent_Progress=0.5;
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter", FieldNotify, Setter, BlueprintSetter="SetPercent_Ghost")
	float Percent_Ghost=0.7;
	
	UFUNCTION(BlueprintCallable,Category="DynamicProgressMeter")
	void SetProgress_Color(const FLinearColor& value);
	UFUNCTION(BlueprintCallable,Category="DynamicProgressMeter")
	void SetGhost_Color(const FLinearColor& value);
	
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter", FieldNotify, Setter, BlueprintSetter="SetProgress_Color")
	FLinearColor Progress_Color=FLinearColor(1,0,0,1);
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter", FieldNotify, Setter, BlueprintSetter="SetGhost_Color")
	FLinearColor Ghost_Color=FLinearColor(1,1,1,1);

	
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter")
	bool bClampGhostToProgress=true;
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter")
	bool bInterpGhostToPercent=true;
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter")
	float GhostInterpTime=1;
	
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter")
	UMaterialInterface* MeterMaterial;

	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter",AdvancedDisplay)
	FName MaterialParam_Progress="Progress";
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter",AdvancedDisplay)
	FName MaterialParam_Ghost="Ghost";
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter",AdvancedDisplay)
	FName MaterialParam_ProgressColor="Meter_Color";
	UPROPERTY(EditAnywhere,Category="DynamicProgressMeter",AdvancedDisplay)
	FName MaterialParam_GhostColor="Ghost_Color";
};

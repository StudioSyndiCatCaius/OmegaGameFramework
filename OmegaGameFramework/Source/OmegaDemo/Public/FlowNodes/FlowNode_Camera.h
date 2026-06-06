// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Camera.generated.h"

class UOmegaActorSelector;

UCLASS(DisplayName="🎥Camera - Fade")
class OMEGADEMO_API UFlowNode_Camera_Fade : public UFlowNode
{
	GENERATED_BODY()

	FTimerHandle timer_handle;
	UFUNCTION() void L_Finished();
	
public:
	UFlowNode_Camera_Fade();
	virtual void ExecuteInput(const FName& PinName) override;
	
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Camera"; };
#endif
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	float BeginAlpha = 1.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	float EndAlpha;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	FLinearColor Color;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	float Duration = 0.5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	bool bFadeAudio=false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	bool bHoldOnEnd=true;
};

UCLASS(DisplayName="🎥Camera - Blend")
class OMEGADEMO_API UFlowNode_Camera_Blend : public UFlowNode
{
	GENERATED_BODY()

	FTimerHandle timer_handle;
	UFUNCTION() void L_Finished();

public:
	UFlowNode_Camera_Blend();
	virtual void ExecuteInput(const FName& PinName) override;
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Camera"; };
#endif
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade",DisplayName="BlendTarget", meta=(EditCondition="!bUseSelector", EditConditionHides))
	TSoftObjectPtr<AActor> BlendTargetCamera;
	UPROPERTY(EditAnywhere,Instanced, BlueprintReadWrite, Category="Fade", meta=(EditCondition="bUseSelector", EditConditionHides))
	UOmegaActorSelector* BlendTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	bool bUseSelector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	float Duration = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	TEnumAsByte<EViewTargetBlendFunction> BlendType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	float BlendExponent = 0.2;
	
};

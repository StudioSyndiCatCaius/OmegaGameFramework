// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "Types/Struct_Material.h"
#include "FlowNode_UI.generated.h"

/**
 * 
 */
UCLASS(DisplayName="🖼️Image - Set",Category="UI")
class OMEGADEMO_API UFlowNode_Image_Set : public UFlowNode
{
	GENERATED_BODY()
	
public:
	UFlowNode_Image_Set();
	
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Image",meta=(Categories="IMAGE"))
	FGameplayTag ImageTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Image")
	bool RemoveImage;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Image",meta=(EditCondition="RemoveImage"))
	FSlateBrush Image;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Image",meta=(EditCondition="RemoveImage"))
	FOmegaDynamicMaterialParams MaterialParams;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Image")
	float Delay=0.4f;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

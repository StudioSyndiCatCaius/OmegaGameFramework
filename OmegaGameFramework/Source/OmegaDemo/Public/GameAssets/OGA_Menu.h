// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameAsset.h"
#include "OGA_Menu.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADEMO_API UOmegaGA_Menu : public UOmegaGameAsset
{
	GENERATED_BODY()
public:
	virtual TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> FlowGraph_GetAvailableNodes_Implementation() const override;
	virtual void GetEnabledEditors_Implementation(bool& Enable3DEditor, bool& FlowGraphEditor) const override;
};


UCLASS(Category="Menu")
class OMEGADEMO_API UOGA_Node_Menu_Option : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Option"); };
	virtual FSlateBrush FlowNode_GetIcon_Implementation() const override { return Icon; };
	virtual FSlateBrush FlowNode_GetPortrait_Implementation() const override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") FSlateBrush Icon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") FText Title;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Node") FSlateBrush State_Background;
};

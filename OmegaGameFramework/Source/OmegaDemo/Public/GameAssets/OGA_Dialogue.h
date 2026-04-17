// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameAsset.h"
#include "Statics/OMEGA_Content.h"
#include "OGA_Dialogue.generated.h"


UCLASS()
class OMEGADEMO_API UOmegaGA_Dialogue : public UOmegaGameAsset
{
	GENERATED_BODY()
public:
	virtual TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> FlowGraph_GetAvailableNodes_Implementation() const override;
	virtual void GetEnabledEditors_Implementation(bool& Enable3DEditor, bool& FlowGraphEditor) const override;
};


// NODES

UCLASS(Category="Dialogue")
class OMEGADEMO_API UOGA_Node_DLG_Message : public UOmegaGameAsset_FlowNode, public IDataInterface_General
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Message"); };
	virtual FSlateBrush FlowNode_GetPortrait_Implementation() const override;
	virtual FString FlowNode_GetDescription_Implementation() const override;
	virtual FLinearColor FlowNode_GetColor_Implementation() const override;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node", meta=(ExposeOnSpawn="true",DisallowCreateNew), DisplayName="🗣️Instigator")
	UPrimaryDataAsset* Speaker;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node",meta=(MultiLine),DisplayName="💬Text")
	FText Text;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node",AdvancedDisplay)
	FName MessageKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node",AdvancedDisplay,DisplayName="🗒️Direction Notes") FString Direction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Misc") FOmegaBitflagsBase Flags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Misc") FOmegaClassNamedLists Lists;
	
	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists) override;
};


UCLASS(Category="Dialogue")
class OMEGADEMO_API UOGA_Node_DLG_Choice : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Choice"); };
	virtual FLinearColor FlowNode_GetColor_Implementation() const override { return FLinearColor::Green; };
	virtual FString FlowNode_GetDescription_Implementation() const override { return Text.ToString(); };
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node",meta=(MultiLine),DisplayName="💬Text")
	FText Text;
};

UCLASS(Category="Dialogue")
class OMEGADEMO_API UOGA_Node_DLG_ChoiceHUB : public UOmegaGameAsset_FlowNode
{
	GENERATED_BODY()
	
public:
	virtual FText GetNodeTitle_Implementation() const override { return FText::FromString("Choice HUB"); };
	virtual FLinearColor FlowNode_GetColor_Implementation() const override { return FLinearColor::Green; };
};


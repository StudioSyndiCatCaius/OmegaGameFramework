// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Tool.h"
#include "Misc/GeneralDataObject.h"
#include "DA_CommonTool.generated.h"

UCLASS(DisplayName="♎Demo - Tool (Common)")
class OMEGADEMO_API UOAsset_CommonTool : public UOmegaDemoDataAsset, public IDataInterface_Tool
{
	GENERATED_BODY()
	
public:
	UOAsset_CommonTool();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tool") TSubclassOf<AOmegaToolActor> ToolActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tool") TMap<TEnumAsByte<EOmegaToolEvents>,FOmegaTool_EventAssets> EventAssets;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Tool", meta=(ShowOnlyInnerProperties))
	FOmegaTool_Config Config;
	
	virtual bool Tool_CanTrigger_Implementation(AOmegaToolActor* Tool) override;
	virtual int32 Tool_OnActivate_Implementation(AOmegaToolActor* Tool, bool bActivated) override;
	virtual int32 Tool_OnTrigger_Implementation(AOmegaToolActor* Tool) override;
	virtual int32 ToolActor_BeginPlay_Implementation(AOmegaToolActor* Tool) override;
	virtual void GetTool_EventAssets_Implementation(EOmegaToolEvents Animation, FOmegaTool_EventAssets& Assets) override;
	virtual TSubclassOf<AOmegaToolActor> GetToolActorClass_Implementation() override;
	virtual FOmegaTool_Config GetToolConfig_Implementation() override { return Config; };
};

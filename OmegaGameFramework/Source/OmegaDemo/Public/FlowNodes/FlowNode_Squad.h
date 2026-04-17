// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDemo_Const.h"
#include "Functions/F_Component.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Squad.generated.h"


class UAssetSquadComponent;
class UAssetSquad_Identity;

UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_SquadBASE : public UFlowNode
{
	GENERATED_BODY()

public:

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Squad"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_DEBUG; return true;};
#endif
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad") UPrimaryDataAsset* TargetActor_Identity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad") UAssetSquad_Identity* Squad_Identity;

	UFUNCTION(BlueprintPure,Category="Squad") UAssetSquadComponent* GetLinkedSquadComponent() const;
};


UCLASS(DisplayName="🧑‍🤝‍🧑Squad - Edit")
class OMEGADEMO_API UFlowNode_Squad_Edit : public UFlowNode_SquadBASE
{
	GENERATED_BODY()
public:
	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR

#endif
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Squad") UAssetSquad_Identity* NewDefaultSquad;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit Members") bool bRemoveAllFirst;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit Members",meta=(EditCondition="!bRemoveAllFirst")) TArray<UPrimaryDataAsset*> Members_Removed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit Members") TArray<UPrimaryDataAsset*> Members_Added;
	
};

	
UCLASS(DisplayName="🧑‍🤝‍🧑Squad - Check?")
class OMEGADEMO_API UFlowNode_Squad_Check : public UFlowNode_SquadBASE
{
	GENERATED_BODY()

public:
	UFlowNode_Squad_Check();
	bool L_ValidityCheck();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR

#endif
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit Members") TArray<UPrimaryDataAsset*> RequiredMembers;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Edit Members") bool bRequireAllMembers=true;
	
};



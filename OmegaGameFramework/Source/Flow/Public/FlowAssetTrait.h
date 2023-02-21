// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FlowAssetTrait.generated.h"

class UWorld;
class UGameInstance;

UCLASS(Blueprintable, BlueprintType, Abstract, EditInlineNew)
class FLOW_API UFlowAssetTrait : public UObject
{
	GENERATED_BODY()

public:
	explicit UFlowAssetTrait(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY()
	UGameInstance* GameInstanceRef = nullptr;
	UPROPERTY()
	UWorld* WorldPrivate = nullptr;
	
	virtual UWorld* GetWorld() const override;
	virtual UGameInstance* GetGameInstance() const;
	
	//UPROPERTY()
	//UWorld* WorldPrivate = nullptr;
	
	void Native_FlowBegin(UGameInstance* GameInstance);
	void Native_FlowEnd(FName Output, const FString& Flag);

	UFUNCTION(BlueprintImplementableEvent, Category="Trait")
	void FlowBegin();
	UFUNCTION(BlueprintImplementableEvent, Category="Trait")
	void FlowEnd(FName Output, const FString& Flag);
};


inline void UFlowAssetTrait::Native_FlowBegin(UGameInstance* GameInstance)
{
	if(!GameInstanceRef)
	{
		GameInstanceRef = GameInstance;
	}
	FlowBegin();
}

inline void UFlowAssetTrait::Native_FlowEnd(FName Output, const FString& Flag)
{
	FlowEnd(Output, Flag);
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "Engine/DataAsset.h"
#include "OmegaInputMode.generated.h"

UENUM(BlueprintType) 
enum class EInputModeType : uint8
{
	InputModeType_Game          UMETA(DisplayName = "Game"),
	InputModeType_UI			UMETA(DisplayName = "UI"),
	InputModeType_GameUI		UMETA(DisplayName = "Game & UI"),
};

	
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaInputMode : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Input")
	EInputModeType Type;

	UPROPERTY(EditAnywhere, Category="Input")
	TArray<UInputMappingContext*> AddedMappingContexts;
	
	UPROPERTY(EditAnywhere, Category="Input")
	int32 InputPriority;
	
	UPROPERTY(EditAnywhere, Category="Mouse")
	bool bShowMouseCursor;
	UPROPERTY(EditAnywhere, Category="Mouse")
	bool bEnabledClickEvents;
	UPROPERTY(EditAnywhere, Category="Mouse")
	bool bEnableTouchEvents;
	UPROPERTY(EditAnywhere, Category="Mouse")
	bool bEnableMouseOverEvents;
	UPROPERTY(EditAnywhere, Category="Mouse")
	bool bEnableTouchOverEvents;
};

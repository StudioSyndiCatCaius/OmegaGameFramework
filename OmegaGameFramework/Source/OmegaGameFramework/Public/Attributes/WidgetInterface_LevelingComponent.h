// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UObject/Interface.h"
#include "WidgetInterface_LevelingComponent.generated.h"

//#include "LevelingComponent.h"

class UTextBlock;
class UProgressBar;
class ULevelingComponent;

// This class does not need to be modified.
UINTERFACE()
class UWidgetInterface_LevelingComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IWidgetInterface_LevelingComponent
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	ULevelingComponent* GetLevelingComponent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	void GetLevelingTexts(UTextBlock*& CurrentValue, class UTextBlock*& MaxValue, UTextBlock*& CurrentLevel);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	void GetLevelingProgressBar(UProgressBar*& ProgressBar);
};

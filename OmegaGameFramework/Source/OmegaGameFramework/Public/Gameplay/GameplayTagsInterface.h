// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "GameplayTagContainer.h"

#include "GameplayTagsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameplayTagsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IGameplayTagsInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTag GetObjectGameplayCategory();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTagContainer GetObjectGameplayTags();

};

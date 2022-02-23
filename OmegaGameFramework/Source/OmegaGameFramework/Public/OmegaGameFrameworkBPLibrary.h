// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaGameplaySubsystem.h"
#include "GameplayTagContainer.h"
#include "Kismet/GameplayStatics.h"
#include "OmegaGameFrameworkBPLibrary.generated.h"

class APlayerController;
class UEnhancedInputLocalPlayerSubsystem;
class UOmegaPlayerSubsystem;

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UOmegaGameFrameworkBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	/*UFUNCTION(BlueprintPure, Category = "Ω|Gameplay", meta = (DeterminesOutputType = "Class", CompactNodeTitle = "Gameplay System"))
	static AOmegaGameplaySystem* GetGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive);
	*
	UFUNCTION(BlueprintPure, Category = "Ω|Assets")
	static TArray<UObject*> FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag Category);

	UFUNCTION(BlueprintPure, Category = "Ω|Assets")
	static TArray<UObject*> FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer Category);*/

	UFUNCTION(BlueprintCallable, Category="Ω|Widgets")
	void SetWidgetVisibilityWithTags(FGameplayTagContainer Tags, ESlateVisibility Visibility);
};

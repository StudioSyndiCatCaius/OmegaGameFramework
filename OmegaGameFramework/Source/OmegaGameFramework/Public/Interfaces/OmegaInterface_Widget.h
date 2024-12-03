// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"

#include "OmegaInterface_Widget.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UWidgetInterface_Input : public UInterface
{
	GENERATED_BODY()
};

class OMEGAGAMEFRAMEWORK_API IWidgetInterface_Input
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void OnControlSetWidget();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputNavigate(FVector2D Axis);
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputPage(float Axis);
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputConfirm();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputCancel();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	bool InputBlocked();
	UFUNCTION(BlueprintNativeEvent, Category="Input")
	void InputTag(FGameplayTag Tag);
	
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWidgetInterface_Combatant : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IWidgetInterface_Combatant
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Widget|Combatant")
	class UCombatantComponent* GetCombatantComponent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Widget|Combatant")
	void GetAttributeTexts(class UOmegaAttribute* Attribute, class UTextBlock*& CurrentValue, class UTextBlock*& MaxValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Widget|Combatant")
	void GetAttributeProgressBar(class UOmegaAttribute* Attribute, class UProgressBar*& ProgressBar, bool& bUseAttributeColor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Widget|Combatant")
	void OnCombatantUpdated(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Widget|Combatant")
	void SetAttributeComparison(bool bComparing, UCombatantComponent* Combatant, UObject* ComparedSource, UObject* UncomparedSource);
};
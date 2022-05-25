// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Gameplay/CombatantComponent.h"
#include "OmegaAttribute.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "WidgetInterface_Combatant.generated.h"

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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ω|Widget|Combatant")
	class UCombatantComponent* GetCombatantComponent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ω|Widget|Combatant")
	void GetAttributeTexts(class UOmegaAttribute* Attribute, class UTextBlock*& CurrentValue, class UTextBlock*& MaxValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ω|Widget|Combatant")
	void GetAttributeProgressBar(class UOmegaAttribute* Attribute, class UProgressBar*& ProgressBar, bool& bUseAttributeColor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ω|Widget|Combatant")
	void OnCombatantUpdated(UCombatantComponent* Combatant);

	
};

// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "Widget/UI_Widgets.h"
#include "UI_Panel.generated.h"

class UBorder;
class UTextBlock;

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaUI_Panel : public UUserWidget, public IOmegaWidgetInterface
{
	GENERATED_BODY()

	UOmegaSlateStyle_Panel* L_GetStyle() const;

public:

	// ---- Content --------------------------------------------------------------------------------

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	FText Title;

	// ---- Style system ---------------------------------------------------------------------------

	UPROPERTY(EditAnywhere,Category="Style")
	bool UseStyle = false;

	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.Panel"))
	FGameplayTag StyleTag;

	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle"))
	UOmegaSlateStyle_Panel* OverrideStyle = nullptr;

	UPROPERTY(EditAnywhere,Category="Style")
	UOmegaSlateTheme* OverrideTheme = nullptr;

	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }

	// ---- Lifecycle ------------------------------------------------------------------------------

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	// ---- Public API -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable,Category="Widget")
	void SetTitle(FText NewTitle);

	/** Stores the given style as the override and applies it immediately. */
	UFUNCTION(BlueprintCallable,Category="Widget")
	void SetStyleAsset(UOmegaSlateStyle_Panel* InStyle);

	// ---- Blueprint implementable helpers --------------------------------------------------------

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UTextBlock* GetWidget_Text_Title();

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UBorder* GetWidget_Border_Title();

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UBorder* GetWidget_Border_Body();

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UNamedSlot* GetWidget_Slot();
};

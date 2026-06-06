// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonBorder.h"
#include "GameplayTagContainer.h"
#include "Blueprint/WidgetTree.h"
#include "Widgets/SWidget.h"
#include "Widget/UI_Widgets.h"
#include "UI_Background.generated.h"

class UVerticalBox;
class UImage;
class UNamedSlot;
class UOverlaySlot;
class UOverlay;

// ---------------------------------------------------------------------------------------------------------------------
// Section data
// ---------------------------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct FOmegaUI_SectionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FSlateBrush Brush;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FMargin OuterMargins;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FMargin InnerMargins;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FVector2D BoxSize;
};

// ---------------------------------------------------------------------------------------------------------------------
// Style asset
// ---------------------------------------------------------------------------------------------------------------------

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaUIStyle_Background : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent,Category="UI")
	TArray<FOmegaUI_SectionInfo> GetBorderSections();

	UPROPERTY(EditAnywhere,Category="UI") FSlateBrush Background_Brush;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FMargin Background_Margins;

	UPROPERTY(EditAnywhere,Category="UI") FOmegaUI_SectionInfo Top_Style;
	UPROPERTY(EditAnywhere,Category="UI") FOmegaUI_SectionInfo Center_Style;
	UPROPERTY(EditAnywhere,Category="UI") FOmegaUI_SectionInfo Bottom_Style;

	UPROPERTY(EditAnywhere,Category="PostProcess",meta=(ShowOnlyInnerProperties)) FOmegaWidgetPostProcess PostProcess;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaUIStyle_Background_3Part : public UOmegaUIStyle_Background
{
	GENERATED_BODY()
};

// ---------------------------------------------------------------------------------------------------------------------
// Widget
// ---------------------------------------------------------------------------------------------------------------------

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaUI_Background : public UUserWidget, public IOmegaWidgetInterface
{
	GENERATED_BODY()

	UOmegaUIStyle_Background* L_GetStyle() const;

public:

	// ---- Style system ---------------------------------------------------------------------------

	UPROPERTY(EditAnywhere,Category="Style")
	bool UseStyle = false;

	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle",Categories="UiStyle.Background"))
	FGameplayTag StyleTag;

	UPROPERTY(EditAnywhere,Category="Style",meta=(EditCondition="UseStyle"))
	UOmegaUIStyle_Background* OverrideStyle = nullptr;

	UPROPERTY(EditAnywhere,Category="Style")
	UOmegaSlateTheme* OverrideTheme = nullptr;

	virtual UOmegaSlateTheme* GetSlateTheme_Implementation() const override { return OverrideTheme; }

	// ---- Lifecycle ------------------------------------------------------------------------------

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	// ---- Public API -----------------------------------------------------------------------------

	/** Stores the given style as the override and applies it immediately. */
	UFUNCTION(BlueprintCallable,Category="Widget")
	void SetStyleAsset(UOmegaUIStyle_Background* InStyle);

	/** Applies a style directly to the widget without storing it as an override. */
	UFUNCTION(BlueprintCallable,Category="Widget")
	void SetStyle(UOmegaUIStyle_Background* InStyle);

	// ---- Blueprint implementable helpers --------------------------------------------------------

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	void GetWidgets_Base(UImage*& image, UOverlay*& BaseOverlay, UPanelWidget*& Panel);

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	void GetWidgets_Section(int32 index, UNamedSlot*& NamedSlot, UBorder*& Border, USizeBox*& SizeBox);

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	void OnSection_PostSetup(int32 index, UNamedSlot* slot_top, UBorder* Border, UPanelWidget* Panel);

private:

	void L_Refresh();
	void L_UpdateStyleElements(FOmegaUI_SectionInfo style, int32 index);
	void L_InitSection(UBorder*& border, UNamedSlot*& nslot, FName slotName);
};

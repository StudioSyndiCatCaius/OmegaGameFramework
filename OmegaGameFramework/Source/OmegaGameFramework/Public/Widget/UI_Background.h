// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonBorder.h"
#include "Blueprint/WidgetTree.h"
#include "Widgets/SWidget.h"
#include "UI_Background.generated.h"

class UVerticalBox;
class UImage;
class UNamedSlot;
class UOverlaySlot;
class UOverlay;

USTRUCT(BlueprintType)
struct FOmegaUI_SectionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FSlateBrush Brush;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FMargin OuterMargins;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FMargin InnerMargins;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI") FVector2D BoxSize;
};



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
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaUIStyle_Background_3Part : public UOmegaUIStyle_Background
{
	GENERATED_BODY()
	
public:

};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaUI_Background : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,Category="UI") UOmegaUIStyle_Background* Style;
	
	virtual void NativePreConstruct() override;

	void L_Refresh();
	void L_UpdateStyleElements(FOmegaUI_SectionInfo style, int32 index);
	void L_InitSection(UBorder*& border, UNamedSlot*& nslot, FName slotName);

	UFUNCTION(BlueprintCallable,Category="Widget") void SetStyle(UOmegaUIStyle_Background* InStyle);

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	void GetWidgets_Base(UImage*& image,UOverlay*& BaseOverlay, UPanelWidget*& Panel);
	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	void GetWidgets_Section(int32 index, UNamedSlot*& NamedSlot,UBorder*& Border,USizeBox*& SizeBox);
	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	void OnSection_PostSetup(int32 index, UNamedSlot* slot_top,UBorder* Border,UPanelWidget* Panel);
	

	
};


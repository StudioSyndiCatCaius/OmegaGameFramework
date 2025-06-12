// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonBorder.h"
#include "CommonTextBlock.h"
#include "Blueprint/UserWidget.h"

#include "UI_Panel.generated.h"

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaUI_Panel : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativePreConstruct() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	FText Title;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	TSubclassOf<UCommonBorderStyle> Override_BorderStyle;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	TSubclassOf<UCommonTextStyle> Override_TitleStyle;

	UFUNCTION(BlueprintCallable,Category="Widget")
	void SetTitle(FText NewTitle);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UCommonTextBlock* GetWidget_Text_Title();
	
	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UCommonBorder* GetWidget_Border_Main();

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UNamedSlot* GetWidget_Slot();
};

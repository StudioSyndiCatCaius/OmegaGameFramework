// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "UI_Panel.generated.h"

class UOmegaSlateStyle_Text;
class UOmegaSlateStyle_Border;
class UBorder;
class UTextBlock;

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaUI_Panel : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativePreConstruct() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	FText Title;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	UOmegaSlateStyle_Border* TitleBorder_Style;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	UOmegaSlateStyle_Text* TitleText_Style;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Panel")
	UOmegaSlateStyle_Border* BodyBorder_Style;
	
	UFUNCTION(BlueprintCallable,Category="Widget")
	void SetTitle(FText NewTitle);
	
	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UTextBlock* GetWidget_Text_Title();
	
	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UBorder* GetWidget_Border_Title();

	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UBorder* GetWidget_Border_Body();
	
	UFUNCTION(BlueprintImplementableEvent,Category="Widget")
	UNamedSlot* GetWidget_Slot();
};

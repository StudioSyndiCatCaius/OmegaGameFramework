// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OmegaUserWidget.generated.h"

class UImage;
class UCommonTextBlock;
class UCommonBorder;
class USizeBox;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//---------------------------------------------------------------------------------------------//
	//	Bindings
	//---------------------------------------------------------------------------------------------//
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="OmegaWidget") USizeBox* GetSizeBox_ByName(FName Name);
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="OmegaWidget") UCommonBorder* GetBorder_ByName(FName Name);
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="OmegaWidget") UCommonTextBlock* GetText_ByName(FName Name);
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="OmegaWidget") UImage* GetImage_ByName(FName Name);
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="OmegaWidget") UUserWidget* GetUserWidget_ByName(FName Name);
	
	//---------------------------------------------------------------------------------------------//
	//	Tags
	//---------------------------------------------------------------------------------------------//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OmegaWidget")
	TArray<FName> WidgetTags;
	
	UFUNCTION(BlueprintCallable, Category="Tags")
	void SetWidgetTagActive(FName Tag, bool bActive)
	{
		if(bActive)
		{
			WidgetTags.AddUnique(Tag);
		}
		else
		{
			if(WidgetTags.Contains(Tag))
			{
				WidgetTags.Remove(Tag);
			}
		}
	};
	
	UFUNCTION(BlueprintPure, Category="Tags")
	bool WidgetHasTag(FName Tag) const
	{
		return WidgetTags.Contains(Tag);
	};

};

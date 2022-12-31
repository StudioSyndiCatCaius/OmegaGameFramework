// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataTooltip.h"
#include "GameplayTagContainer.h"
#include "WidgetInterface_Input.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "DataWidget.generated.h"

class UDataList;
class UTextBlock;
class UButton;
class UImage;
class UDataList;
class UWidgetAnimation;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelected, UDataWidget*, DataWidget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHovered, UDataWidget*, DataWidget, bool, bIsHovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHighlight, UDataWidget*, DataWidget, bool, bIsHighlighted);

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
protected:

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category="DataWidget")
	UDataList* ParentList = nullptr;

	UPROPERTY(EditInstanceOnly, Category="DataWidget")
	FString AssetLabel;
	
	UPROPERTY(BlueprintReadOnly, meta=(ExposeOnSpawn = "true", DisplayName="Source Asset"), Category = "DataWidget")
	UObject* ReferencedAsset;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "DataWidget")
	int32 ListIndex;

	UPROPERTY(BlueprintReadOnly, Category = "DataWidget")
	bool bIsHighlighted;

	UPROPERTY(BlueprintReadOnly, Category = "DataWidget")
	bool bIsHovered;

	UFUNCTION(BlueprintImplementableEvent, Category = "DataWidget", meta=(AdvancedDisplay="ListTags, ListFlag"))
		void AddedToDataList(UDataList* DataList, int32 Index, const UObject* Asset, FGameplayTagContainer ListTags, const FString& ListFlag);

	UFUNCTION(BlueprintImplementableEvent, Category = "DataWidget")
		void OnNewListOwner(UObject* ListOwner);

	UFUNCTION()
		FString GetAssetLabel();

	//---------------------------------------------------------------------------------------------//
	//	Tags
	//---------------------------------------------------------------------------------------------//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataWidget")
    TArray<FName> WidgetTags;
	
	UFUNCTION(BlueprintCallable, Category="DataWidget")
	void SetWidgetTagActive(FName Tag, bool bActive);
	
	UFUNCTION(BlueprintPure, Category="DataWidget")
	bool DataWidgetHasTag(FName Tag);

//FUNCTIONS

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void Select();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void Hover();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void Unhover();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void SetHighlighted(bool Highlighted);

	UFUNCTION(BlueprintImplementableEvent, DisplayName="Is Entity Unselectable", Category = "Ω|Widget|DataWidget")
	bool IsEntityDisabled(UObject* Asset);

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataWidget")
	bool GetIsEntitySelectable();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|DataWidget")
	bool IsEntityHidden(UObject* Asset);

	//source asset
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void SetSourceAsset(UObject* Asset);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|DataWidget")
	void OnSourceAssetChanged(UObject* Asset);
	//Sounds
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	USoundBase* SelectSound;
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	USoundBase* HoverSound;
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	USoundBase* ErrorSound;

	//------------------------
	// TOOLTIP
	//------------------------

	UPROPERTY(EditDefaultsOnly, Category="Tooltip")
	TSubclassOf<UDataTooltip> DefaultTooltipWidget;

	UPROPERTY()
	UDataTooltip* DefaultCreatedTooltip;
	
	UFUNCTION(BlueprintPure, Category="Tooltip")
	UDataTooltip* GetDataTooltipWidget();

	UFUNCTION()
	void Local_UpdateTooltip(UObject* AssetRef);
	
	
//BINDABLE WIDGETS

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets")
	UTextBlock* GetNameTextWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets")
	UTextBlock* GetDescriptionTextWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UButton* GetButtonWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UImage* GetTextureImage();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UImage* GetMaterialImage();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UImage* GetBrushImage(bool& bOverrideSize, FVector2D& Size);
	
//BINDABLE Anims
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetSelectAnimation();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetHoverAnimation();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Animations")
	UWidgetAnimation* GetHighlightAnimation();

	//////////////////////////////////////////////////////////////////////////////////////////
//////////______________________________DELEGATES______________________________//////////
////////////////////////////////////////////////////////////////////////////////////////

	UPROPERTY(BlueprintAssignable)
	FOnSelected OnSelected;

	UPROPERTY(BlueprintAssignable)
	FOnHovered OnHovered;

	UPROPERTY(BlueprintAssignable)
	FOnHighlight OnHighlight;

};

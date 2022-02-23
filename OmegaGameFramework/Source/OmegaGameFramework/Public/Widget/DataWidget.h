// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WidgetInterface_Input.h"
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
class OMEGAGAMEFRAMEWORK_API UDataWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;
	
public:
	
	UPROPERTY()
	class UDataList* ParentList;

	UPROPERTY(EditInstanceOnly, Category="DataWidget")
	FString AssetLabel;
	
	UPROPERTY(BlueprintReadOnly, meta=(ExposeOnSpawn = "true", DisplayName="Source Asset"), Category = "DataWidget")
	class UObject* ReferencedAsset;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "DataWidget")
	int32 ListIndex;

	UPROPERTY(BlueprintReadOnly, Category = "DataWidget")
	bool bIsHighlighted;

	UPROPERTY(BlueprintReadOnly, Category = "DataWidget")
	bool bIsHovered;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "DataWidget")
		void AddedToDataList(UDataList* DataList, int32 Index, const UObject* Asset, FGameplayTagContainer ListTags);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "DataWidget")
		void OnNewListOwner(UObject* ListOwner);

	UFUNCTION()
		FString GetAssetLabel();

//FUNCTIONS

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void Select();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void Hover();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void Unhover();

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void SetHighlighted(bool Highlighted);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|DataWidget")
	bool IsEntityDisabled(UObject* Asset);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|DataWidget")
	bool IsEntityHidden(UObject* Asset);

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void SetSourceAsset(UObject* Asset);

	//Sounds
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	USoundBase* SelectSound;
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	USoundBase* HoverSound;
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	USoundBase* ErrorSound;
	
	
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
	UImage* GetBrushImage();
	
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

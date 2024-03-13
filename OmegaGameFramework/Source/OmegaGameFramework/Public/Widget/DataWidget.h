// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataTooltip.h"
#include "GameplayTagContainer.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "LuaObject.h"
#include "Interfaces/OmegaInterface_Widget.h"
#include "Subsystems/OmegaSubsystem_Player.h"
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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWidgetRefreshed, UDataWidget*, DataWidget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWidgetNotify, UDataWidget*, DataWidget, FName, Notify);

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
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void SetVisibility(ESlateVisibility InVisibility) override;
	
	UOmegaPlayerSubsystem* GetPlayerSubsystem() const;
public:
	
	
	UPROPERTY()
	UDataList* ParentList = nullptr;

	UPROPERTY(EditInstanceOnly, Category="DataWidget")
	FString AssetLabel;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, meta=(ExposeOnSpawn = "true", DisplayName="Source Asset"), Category = "DataWidget")
	UObject* ReferencedAsset;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "DataWidget")
	int32 ListIndex;
	
	UFUNCTION(BlueprintImplementableEvent,Category = "DataWidget")
	UMaterialInstanceDynamic* GetHoveredMaterialInstance();

	//---------------------------------------------------------------------------------------------//
	//	Lua
	//---------------------------------------------------------------------------------------------//
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Lua", meta=(MultiLine))
	FLuaScriptContainer Script;

	
	UFUNCTION(BlueprintCallable,Category="Lua",meta=(AdvancedDisplay="State"))
	FLuaValue GetWidgetScript(TSubclassOf<ULuaState> State);
	UFUNCTION(BlueprintCallable,Category="Lua",meta=(AdvancedDisplay="State"))
	FLuaValue WidgetScriptKeyCall(const FString& key, TArray<FLuaValue> args, TSubclassOf<ULuaState> State);

	//---------------------------------------------------------------------------------------------//
	//	Highlight
	//---------------------------------------------------------------------------------------------//
private:
	UFUNCTION()
	void private_refresh(UDataWidget* widget);
public:
	UFUNCTION(BlueprintCallable, Category="DataWidget", meta=(Keywords="update"))
	void Refresh();

	UFUNCTION(BlueprintImplementableEvent,Category = "DataWidget", meta=(Keywords="update"))
	void OnRefreshed(UObject* SourceAsset = nullptr, UObject* ListOwner = nullptr);

	//Automatically calls the "Refresh" function on a timed loop
	UPROPERTY(EditDefaultsOnly, Category = "Refresh")
	bool bAutoRefreshOnTimer;

	//Frequency (in seconds) at which the "Refresh
	UPROPERTY(EditDefaultsOnly, Category = "Refresh")
    double RefreshFrequency = 0.1;

	//Offsets the refresh variance by a random about of this multiplier. (E.G. if RefreshFrequency=0.5, RefreshVariance=0.1, the final refresh value will be between 0.4-0.6.) This will help all avoid refreshes being called on the same tick.
	UPROPERTY(EditDefaultsOnly, Category = "Refresh")
	double RefreshVariance = 0;
private:
	UPROPERTY()
	float refresh_val;
	UPROPERTY()
	FTimerHandle refresh_timer;

public:
	//---------------------------------------------------------------------------------------------//
	//	Highlight
	//---------------------------------------------------------------------------------------------//
	UPROPERTY(BlueprintReadOnly, Category = "DataWidget")
	bool bIsHighlighted;
	
	UPROPERTY(EditDefaultsOnly, Category="Display", DisplayName="Highlight Widget Duration")
	float HighlightWidgetSpeed = 1.1;
	UPROPERTY(EditDefaultsOnly, Category="Display", AdvancedDisplay)
	FName HighlightWidgetPropertyName = "Highlight";
	//---------------------------------------------------------------------------------------------//
	//	Hover
	//---------------------------------------------------------------------------------------------//
	//UPROPERTY(BlueprintReadOnly, Category = "DataWidget", meta=(DeprecatedProperty))
	//bool bIsHovered;
	
	UPROPERTY(EditDefaultsOnly, Category="Display", DisplayName="Hover Widget Duration")
	float HoverWidgetSpeed = 1.0;
	UPROPERTY(EditDefaultsOnly, Category="Display", AdvancedDisplay)
	FName HoverWidgetPropertyName = "Hover";
	//UFUNCTION(BlueprintImplementableEvent, Category="Hover")
	//void OnHoverUpdate(float HoverValue);

private:
	UPROPERTY()
	float hover_value;
public:
	//---------------------------------------------------------------------------------------------//
	//	Notify
	//---------------------------------------------------------------------------------------------//
	UFUNCTION(BlueprintCallable, Category="Notify")
	void WidgetNotify(FName Notify);
	UPROPERTY(BlueprintAssignable)
	FOnWidgetNotify OnWidgetNotify;
	//---------------------------------------------------------------------------------------------//
	//	Data List
	//---------------------------------------------------------------------------------------------//
	UFUNCTION(BlueprintImplementableEvent, Category = "DataWidget", meta=(AdvancedDisplay="ListTags, ListFlag"))
		void AddedToDataList(UDataList* DataList, int32 Index, const UObject* Asset, FGameplayTagContainer ListTags, const FString& ListFlag);

	UFUNCTION(BlueprintImplementableEvent, Category = "DataWidget")
		void OnNewListOwner(UObject* ListOwner);

	UFUNCTION()
		FString GetAssetLabel();

	//---------------------------------------------------------------------------------------------//
	//	ListOwner
	//---------------------------------------------------------------------------------------------//
	
	UFUNCTION(BlueprintPure, Category="DataWidget")
	UDataList* GetOwningList() const;

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

	UFUNCTION(BlueprintPure, Category = "Ω|Widget|DataWidget")
	bool IsDataWidgetHovered();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|DataWidget")
	bool IsEntityHidden(UObject* Asset);

	//source asset

	UPROPERTY()
	UDataWidget* OwnerDataWidget;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DataWidget")
	bool UpdateSourceAssetFromParent;
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void SetSourceAsset(UObject* Asset);

	UPROPERTY()
	FOnWidgetRefreshed OnWidgetRefreshed;
	
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

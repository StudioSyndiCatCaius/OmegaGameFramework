// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTextBlock.h"
#include "DataTooltip.h"
#include "GameplayTagContainer.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "LuaObject.h"
#include "Math/Vector2D.h"
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



UCLASS(Blueprintable,BlueprintType,EditInlineNew, const)
class OMEGAGAMEFRAMEWORK_API UDataWidgetMetadata : public UObject
{
	GENERATED_BODY()
	
public:
		
	UFUNCTION(BlueprintImplementableEvent, Category="Meta")
	void OnMetaApplied(UDataWidget* widget) const;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

	void Local_SetVisFromBool(UWidget* widget, bool val) const
	{
		if(widget)
		{
			if(val)
			{
				widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			}
			else
			{
				widget->SetVisibility(ESlateVisibility::Collapsed);
			}
		}
	}

	void local_overrideTextStyle(UTextBlock* text, TSubclassOf<UCommonTextStyle> style)
	{
		if(text && text->GetClass()->IsChildOf(UCommonTextBlock::StaticClass()) && style)
		{
			Cast<UCommonTextBlock>(text)->SetStyle(style);
		}
	}
	
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

	UPROPERTY(EditAnywhere, Category="DataWidget")
	FText NameText;
	
	UPROPERTY(EditInstanceOnly, Category="DataWidget")
	FString AssetLabel;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, meta=(ExposeOnSpawn = "true", DisplayName="Source Asset"), Category = "DataWidget")
	UObject* ReferencedAsset;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "DataWidget")
	int32 ListIndex;
	
	UFUNCTION(BlueprintImplementableEvent,Category = "DataWidget")
	UMaterialInstanceDynamic* GetHoveredMaterialInstance();

	//---------------------------------------------------------------------------------------------//
	//	Meta
	//---------------------------------------------------------------------------------------------//
	UPROPERTY(EditAnywhere, Instanced, Category="Meta")
	TArray<UDataWidgetMetadata*> WidgetMetadata;
	
	UFUNCTION(BlueprintPure,Category="Meta")
	TArray<UDataWidgetMetadata*> GetWidgetMetadata() const
	{
		return WidgetMetadata;
	}

	UFUNCTION(BlueprintPure,Category="Meta",meta=(DeterminesOutputType="Class"))
	UDataWidgetMetadata* GetWidgetMetadata_FromClass(TSubclassOf<UDataWidgetMetadata> Class);
	
	UFUNCTION()
	void RefreshMeta();
	
	UFUNCTION(BlueprintImplementableEvent,Category="Meta")
	void MetaRefreshed();
	
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
	float HighlightWidgetSpeed = 0.1;

	UPROPERTY(EditDefaultsOnly, Category="Display", AdvancedDisplay)
	FName HighlightWidgetPropertyName = "Highlight";
	//---------------------------------------------------------------------------------------------//
	//	Hover
	//---------------------------------------------------------------------------------------------//
	
	UPROPERTY(EditDefaultsOnly, Category="Display", DisplayName="Hover Widget Duration")
	float HoverWidgetSpeed = 0.1;
	UPROPERTY(EditDefaultsOnly, Category="Display", AdvancedDisplay)
	FName HoverWidgetPropertyName = "Hover";

	UPROPERTY()
	float HoverValue_current;
	UPROPERTY()
	float HighlightValue_current;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Hover")
	void OnHoverUpdate(float HoverValue);
	UFUNCTION(BlueprintImplementableEvent, Category="Hover")
	void OnHighlightUpdate(float HoverValue);
	
private:
	UPROPERTY()
	float hover_value;
public:
	//---------------------------------------------------------------------------------------------//
	//	Notify
	//---------------------------------------------------------------------------------------------//
	UFUNCTION(BlueprintCallable, Category="Notify")
	void WidgetNotify(FName Notify);
protected:
	UFUNCTION(BlueprintImplementableEvent,Category="Notify",DisplayName="On Widget Notify")
	void Local_OnWidgetNotify(FName notify);
public:
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


	UPROPERTY(BlueprintAssignable)
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

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets", DisplayName="Get Widget - Root Panel")
	UTextBlock* GetRootPanelWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets", DisplayName="Get Widget - Name Text")
	UTextBlock* GetNameTextWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets", DisplayName="Get Widget - Description - Text")
	UTextBlock* GetDescriptionTextWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets", DisplayName="Get Widget - Button")
	UButton* GetButtonWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UImage* GetTextureImage();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UImage* GetMaterialImage();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets", DisplayName="Get Widget - Brush Icon")
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

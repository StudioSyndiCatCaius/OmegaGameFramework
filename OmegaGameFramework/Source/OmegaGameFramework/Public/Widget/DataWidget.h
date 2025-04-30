// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonBorder.h"
#include "CommonTextBlock.h"
#include "DataTooltip.h"
#include "GameplayTagContainer.h"
#include "Math/Vector2D.h"
#include "Subsystems/OmegaSubsystem_Player.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Widget/OmegaUserWidget.h"
#include "Components/SizeBox.h"
#include "Curves/CurveVector.h"
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
	
	UFUNCTION(BlueprintNativeEvent, Category="Meta")
	bool CanAddObjectToList(UObject* SourceObject) const;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDataWidget : public UOmegaUserWidget, public IUserObjectListEntry
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

	void LC_UpdateBlendStateVal(bool& bBlending, bool bTarget,float& val, float DT, float max_time, UCurveFloat* curve, FName MatParamName, int type);
	void LC_CallBlendUpdate(int val, float input);

	float _DirFromBool(bool val) const
	{
		if(val) { return 1.0f;} return -1.0;
	}
	float _TargetFromBool(bool val) const
	{
		if(val) { return 1.0f;} return 0.0;
	}
	
	UPROPERTY() bool b_IsHovered;
	UPROPERTY() bool b_IsHighlighted;
	
	UPROPERTY() bool _b_PlayingAnim_hover;
	UPROPERTY() bool _b_PlayingAnim_highlight;
	
	UPROPERTY() float _f_BlendTimeHover;
	UPROPERTY() float _f_BlendTimeHighlight;
	
	UPROPERTY() float _f_HoverBlend_Min=0.0f;
	UPROPERTY() float _f_HoverBlend_Max=1.0f;
	
	UPROPERTY() float _f_HighBlend_Min=0.0f;
	UPROPERTY() float _f_HighBlend_Max=1.0f;
	
	UPROPERTY() float refresh_val;
	UPROPERTY() FTimerHandle refresh_timer;

	UPROPERTY() UCurveFloat* _u_curveHover;
	UPROPERTY() UCurveFloat* _u_curveHighlight;

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void SetVisibility(ESlateVisibility InVisibility) override;
	
	UOmegaPlayerSubsystem* GetPlayerSubsystem() const;
public:
	
	UPROPERTY() UDataList* ParentList = nullptr;
	
	UPROPERTY(EditAnywhere, Category="DataWidget")
	FGameplayTag SlotID;
	
	UPROPERTY(EditAnywhere, Category="DataWidget")
	FText NameText;
	
	UPROPERTY(EditInstanceOnly, Category="DataWidget")
	FString AssetLabel;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, meta=(ExposeOnSpawn = "true", DisplayName="Source Asset"), Category = "DataWidget")
	UObject* ReferencedAsset=nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "DataWidget")
	int32 ListIndex;
	
	UFUNCTION(BlueprintImplementableEvent,Category = "DataWidget")
	UMaterialInstanceDynamic* GetHoveredMaterialInstance() const;

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
	//	Highlight
	//---------------------------------------------------------------------------------------------//
private:
	UFUNCTION()
	void private_refresh(UDataWidget* widget);
public:
	UFUNCTION(BlueprintCallable, Category="DataWidget", meta=(Keywords="update"))
	void Refresh();

	UFUNCTION(BlueprintImplementableEvent,Category = "DataWidget", meta=(Keywords="update"))
	void OnRefreshed(UObject* SourceAsset = nullptr, UObject* ListOwner = nullptr, bool bIsDesignTime=false);

	UFUNCTION() virtual void Native_OnSourceAssetChanged(UObject* SourceAsset);
	UFUNCTION() virtual void Native_OnListOwnerChanged(UObject* ListOwner);
	UFUNCTION() virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner);
	UFUNCTION() virtual void Native_SetHovered(bool bHovered);
	
	//Automatically calls the "Refresh" function on a timed loop
	UPROPERTY(EditDefaultsOnly, Category = "Refresh")
	bool bAutoRefreshOnTimer;

	//Frequency (in seconds) at which the "Refresh
	UPROPERTY(EditDefaultsOnly, Category = "Refresh")
    double RefreshFrequency = 0.1;

	//Offsets the refresh variance by a random about of this multiplier. (E.G. if RefreshFrequency=0.5, RefreshVariance=0.1, the final refresh value will be between 0.4-0.6.) This will help all avoid refreshes being called on the same tick.
	UPROPERTY(EditDefaultsOnly, Category = "Refresh")
	double RefreshVariance = 0;

public:
	
	//---------------------------------------------------------------------------------------------//
	//	Highlight
	//---------------------------------------------------------------------------------------------//

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnHighlightStateChange(bool bHighlight);

	UFUNCTION(BlueprintPure,Category="DataWidget")
	bool IsHighlighted() const {return b_IsHighlighted;}
	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(MetaClass="CurveFloat"))
	FSoftObjectPath HighlightBlendCurve{"/OmegaGameFramework/DEMO/Curves/DemoCurve_0-1sec.DemoCurve_0-1sec"};
	UPROPERTY(EditDefaultsOnly, Category="Display", DisplayName="Highlight Widget Duration")
	float HighlightWidgetSpeed = 0.1;
	UPROPERTY(EditDefaultsOnly, Category="Display", AdvancedDisplay)
	FName HighlightWidgetPropertyName = "Highlight";
	//---------------------------------------------------------------------------------------------//
	//	Hover
	//---------------------------------------------------------------------------------------------//

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnHoverStateChange(bool bHovered);
	
	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(MetaClass="CurveFloat"))
	FSoftObjectPath HoverBlendCurve{"/OmegaGameFramework/DEMO/Curves/DemoCurve_0-1sec.DemoCurve_0-1sec"};
	UPROPERTY(EditDefaultsOnly, Category="Display", DisplayName="Hover Widget Duration")
	float HoverWidgetSpeed = 0.1;
	UPROPERTY(EditDefaultsOnly, Category="Display", AdvancedDisplay)
	FName HoverWidgetPropertyName = "Hover";
	UPROPERTY(EditDefaultsOnly, Category="Display")
	UCurveVector* HoverOffset_Curve;
	UPROPERTY(EditDefaultsOnly, Category="Display")
	FVector HoverOffset_Scale=FVector::One();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Hover")
	void OnHoverUpdate(float HoverValue);
	UFUNCTION(BlueprintImplementableEvent, Category="Hover")
	void OnHighlightUpdate(float HoverValue);


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

	UFUNCTION(BlueprintNativeEvent, Category = "DataWidget")
	void OnNewListOwner(UObject* ListOwner);

	UFUNCTION()
		FString GetAssetLabel();

	//---------------------------------------------------------------------------------------------//
	//	ListOwner
	//---------------------------------------------------------------------------------------------//
	
	UFUNCTION(BlueprintPure, Category="DataWidget")
	UDataList* GetOwningList() const;
	

//FUNCTIONS

	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void Select();
	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Widget|DataWidget")
	void OnSelect();
	
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

	UPROPERTY() UDataWidget* OwnerDataWidget;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DataWidget")
	bool UpdateSourceAssetFromParent;
	
	UFUNCTION(BlueprintCallable, Category = "Ω|Widget|DataWidget")
	void SetSourceAsset(UObject* Asset);

	UPROPERTY(BlueprintAssignable)
	FOnWidgetRefreshed OnWidgetRefreshed;
	
	UFUNCTION(BlueprintNativeEvent, Category = "Ω|Widget|DataWidget")
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

	UPROPERTY(EditAnywhere,BlueprintReadOnly="Overrides")
	bool bCanOverrideSize;
	UPROPERTY(EditAnywhere,BlueprintReadOnly="Overrides",meta=(EditCondition="bCanOverrideSize"))
	FVector2D OverrideSize;

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly="Overrides")
	TSubclassOf<UCommonBorderStyle> OverrideBorderStyle;
	UPROPERTY(EditAnywhere,BlueprintReadOnly="Overrides")
	TSubclassOf<UCommonTextStyle> OverrideTextStyle_Name;
	UPROPERTY(EditAnywhere,BlueprintReadOnly="Overrides")
	TSubclassOf<UCommonTextStyle> OverrideTextStyle_Description;
	
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets", DisplayName="Get Widget (Panel) - Root")
	UTextBlock* GetRootPanelWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets", DisplayName="Get Widget (Text) - Name")
	UTextBlock* GetNameTextWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets", DisplayName="Get Widget (Text) - Description")
	UTextBlock* GetDescriptionTextWidget();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets", DisplayName="Get Widget (Button) - Select")
	UButton* GetButtonWidget();
	
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category = "Widgets", DisplayName="Get Widget (Panel) - SizeBox")
	USizeBox* GetWidget_SizeBox();
	
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UImage* GetTextureImage();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets")
	UImage* GetMaterialImage();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets", DisplayName="Get Widget (Image) - Brush Icon")
	UImage* GetBrushImage(bool& bOverrideSize, FVector2D& Size);

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent, Category="Widgets", DisplayName="Get Widget (Image) - Icon Material")
	UImage* GetWidget_IconMaterial();
	UPROPERTY(EditDefaultsOnly,Category="DataWidget",DisplayName="Icon Texture Param Name")
	FName MaterialParamName_IconTexture=TEXT("Texture");
	
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

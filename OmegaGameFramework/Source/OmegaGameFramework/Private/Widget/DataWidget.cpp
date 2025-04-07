// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/DataWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "CommonUILibrary.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/OmegaSubsystem_Player.h"
#include "Widget/DataList.h"
#include "TimerManager.h"
#include "Functions/OmegaFunctions_Utility.h"
#include "..\..\Public\OmegaSettings_Slate.h"

bool UDataWidgetMetadata::CanAddObjectToList_Implementation(UObject* SourceObject) const
{
	return true;
}

void UDataWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	bIsFocusable = true;
	if(GetNameTextWidget())
	{
		GetNameTextWidget()->SetText(NameText);
		if(OverrideTextStyle_Name)
		{
			if(UCommonTextBlock* _txt = Cast<UCommonTextBlock>(GetNameTextWidget()))
			{
				_txt->SetStyle(OverrideTextStyle_Name);
			}
		}
	}
	if(GetDescriptionTextWidget())
	{
		if(OverrideTextStyle_Description)
		{
			if(UCommonTextBlock* _txt = Cast<UCommonTextBlock>(GetDescriptionTextWidget()))
			{
				_txt->SetStyle(OverrideTextStyle_Description);
			}
		}
	}
	//Setup Source Asset
	SetSourceAsset(ReferencedAsset);
	SetIsEnabled(!IsEntityDisabled(ReferencedAsset));

	if(GetHoveredMaterialInstance())
	{
		GetHoveredMaterialInstance()->SetScalarParameterValue(HoverWidgetPropertyName,0);
		GetHoveredMaterialInstance()->SetScalarParameterValue(HighlightWidgetPropertyName,0);
	}
	Refresh();
	RefreshMeta();
}

void UDataWidget::NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::OnAddedToFocusPath(InFocusEvent);
	Hover();
}

void UDataWidget::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::OnRemovedFromFocusPath(InFocusEvent);
	Unhover();
}

void UDataWidget::LC_UpdateBlendStateVal(bool& bBlending, bool bTarget, float& val, float DT, float max_time, UCurveFloat* curve, FName MatParamName, int type)
{
	if(bBlending)
	{
		float _dir=DT;
		if(!bTarget)
		{
			_dir=DT*-1;
		}
		//add delta to value
		val=UKismetMathLibrary::FClamp(_dir+val,0,max_time);

		// if value exceeds max/min, marking blending for STOP
		if(bTarget)
		{
			if(val>=max_time)
			{
				bBlending=false;
			}
		}
		else
		{
			if(val<=0)
			{
				bBlending=false;
			}
		}

		//Apply Blend Values
		float _input=UKismetMathLibrary::NormalizeToRange(val,0,max_time);
		if(curve)
		{
			_input=curve->GetFloatValue(val);
		}
		_input=UKismetMathLibrary::FClamp(_input,0,1);
		if(GetHoveredMaterialInstance())
		{
			GetHoveredMaterialInstance()->SetScalarParameterValue(MatParamName,_input);
		}
		LC_CallBlendUpdate(type,_input);
	}
}

void UDataWidget::LC_CallBlendUpdate(int val, float input)
{
	if(val==0) { OnHoverUpdate(input); }
	if(val==1) { OnHighlightUpdate(input); }
}

void UDataWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(IsRendered())
	{
		LC_UpdateBlendStateVal(_b_PlayingAnim_hover,b_IsHovered,_f_BlendTimeHover,InDeltaTime,HoverWidgetSpeed, _u_curveHover,HoverWidgetPropertyName,0);
		LC_UpdateBlendStateVal(_b_PlayingAnim_highlight,b_IsHighlighted,_f_BlendTimeHighlight,InDeltaTime,HighlightWidgetSpeed,_u_curveHighlight,HighlightWidgetPropertyName,1);
	}
	else
	{
		_b_PlayingAnim_highlight=false;
		_b_PlayingAnim_hover=false;
	}

	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UDataWidget::SetVisibility(ESlateVisibility InVisibility)
{
	Super::SetVisibility(InVisibility);

	bool bStopTimer=false;
	switch (GetVisibility()) {
		case ESlateVisibility::Visible: break;
		case ESlateVisibility::Collapsed: bStopTimer=true; break;

		case ESlateVisibility::Hidden:bStopTimer=true; break;

		case ESlateVisibility::HitTestInvisible: break;
		case ESlateVisibility::SelfHitTestInvisible: break;
	default: ;
	}

	if(bStopTimer)
	{
		GetWorld()->GetTimerManager().PauseTimer(refresh_timer);
	}
	else
	{
		GetWorld()->GetTimerManager().UnPauseTimer(refresh_timer);
	}
}

UOmegaPlayerSubsystem* UDataWidget::GetPlayerSubsystem() const
{
	if(GetOwningLocalPlayer())
	{
		return GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
	}
	return nullptr;	
}



UDataWidgetMetadata* UDataWidget::GetWidgetMetadata_FromClass(TSubclassOf<UDataWidgetMetadata> Class)
{
	for(auto* tempMeta : WidgetMetadata)
	{
		if(tempMeta && tempMeta->GetClass()->IsChildOf(Class))
		{
			return tempMeta;
		}
	}
	return  nullptr;
}

void UDataWidget::RefreshMeta()
{
	for(auto* tempMeta : WidgetMetadata)
	{
		if(tempMeta)
		{
			tempMeta->OnMetaApplied(this);
		}
		MetaRefreshed();
	}
}


void UDataWidget::private_refresh(UDataWidget* widget)
{
	if(widget)
	{
		if(ReferencedAsset != widget->ReferencedAsset)
		{
			ReferencedAsset=widget->ReferencedAsset;
		}
		
		if (widget->ParentList && widget->ParentList != ParentList)
		{
			ParentList=widget->ParentList;
		}
		
	}
	Refresh();
}

void UDataWidget::Refresh()
{
	if (ReferencedAsset && ReferencedAsset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))		//Only run if asset uses Data interface
	{
		FText LocalDesc;
		FText LocalName;
			
		IDataInterface_General::Execute_GetGeneralDataText(ReferencedAsset, AssetLabel, this, LocalName, LocalDesc);
		if (GetNameTextWidget())
		{
			GetNameTextWidget()->SetText(LocalName);
		}
		if (GetDescriptionTextWidget())
		{
			GetDescriptionTextWidget()->SetText(LocalDesc);
		}

		//get source asset images
		UTexture2D* LocalTexture = nullptr;
		UMaterialInterface* LocalMat = nullptr;
		FSlateBrush LocalBrush;
		IDataInterface_General::Execute_GetGeneralDataImages(ReferencedAsset, AssetLabel, this, LocalTexture, LocalMat, LocalBrush);
		
		
		if(GetTextureImage()&&LocalTexture)
		{
			GetTextureImage()->SetBrushFromTexture(LocalTexture);
		}
		if(GetMaterialImage()&&LocalMat)
		{
			GetMaterialImage()->SetBrushFromMaterial(LocalMat);
		}
		bool Local_OverrideSize;
		FVector2D Local_NewSize;
		if(GetBrushImage(Local_OverrideSize, Local_NewSize) && LocalBrush.GetResourceObject())
		{
			if(Local_OverrideSize)
			{
				LocalBrush.ImageSize = Local_NewSize;
			}
			GetBrushImage(Local_OverrideSize, Local_NewSize)->SetBrush(LocalBrush);
		}

		//try set material image.
		if(!LocalTexture)
		{
			if(UTexture2D* _txtr = Cast<UTexture2D>(LocalBrush.GetResourceObject()) )
			{
				LocalTexture=_txtr;
			}
		}
		if(LocalTexture && GetWidget_IconMaterial())
		{
			GetWidget_IconMaterial()->GetDynamicMaterial()->SetTextureParameterValue(MaterialParamName_IconTexture,LocalTexture);
		}
			
	}//Finish widget setup

	if(GetWidget_SizeBox() && bCanOverrideSize)
	{
		GetWidget_SizeBox()->SetWidthOverride(OverrideSize.X);
		GetWidget_SizeBox()->SetHeightOverride(OverrideSize.Y);
	}
	
	SetIsEnabled(GetIsEntitySelectable());
	UObject* LocalListOwner = nullptr;
	if(GetOwningList() && GetOwningList()->ListOwner)
	{
		LocalListOwner = GetOwningList()->ListOwner;
	}
	RefreshMeta();
	Native_OnRefreshed(ReferencedAsset,LocalListOwner);
	OnWidgetRefreshed.Broadcast(this);
}

void UDataWidget::Native_OnSourceAssetChanged(UObject* SourceAsset)
{
	OnSourceAssetChanged(ReferencedAsset);
}

void UDataWidget::Native_OnListOwnerChanged(UObject* ListOwner)
{
	OnNewListOwner(ListOwner);
}

void UDataWidget::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	OnRefreshed(SourceAsset,ListOwner,IsDesignTime());
}

void UDataWidget::Native_SetHovered(bool bHovered)
{
	if(bHovered!=b_IsHovered)
	{
		b_IsHovered=bHovered;
		_b_PlayingAnim_hover=true;
		if(bHovered)
		{
			// IF NOT RUNTIME, change state and end.
			if(GetOwningLocalPlayer())
			{
				// -------- SOUNDS
				UE_LOG(LogTemp, Warning, TEXT("Success Hover"));
				if(HoverSound)
				{
					GetPlayerSubsystem()->PlayUiSound(HoverSound);
				}
				else if(UOmegaSlateFunctions::GetCurrentSlateStyle())
				{
					GetPlayerSubsystem()->PlayUiSound(UOmegaSlateFunctions::GetCurrentSlateStyle()->Sound_Hover);
				}
	
				if (GetHoverAnimation())
				{
					PlayAnimationForward(GetHoverAnimation(), 1.0f, false);
				}
				OnHovered.Broadcast(this, true);
			}
		
			OnHoverStateChange(true);
		}
		else
		{
			if (GetHoverAnimation())
			{
				PlayAnimationReverse(GetHoverAnimation(), 1.0f, false);
			}
		
			OnHovered.Broadcast(this, false);
			OnHoverStateChange(false);
		}
	}
}



//----------------------NATIVE CONSTRUCT-------------------------------------------//

void UDataWidget::NativeConstruct()
{
	if(HoverBlendCurve.IsValid()) { _u_curveHover=Cast<UCurveFloat>(HoverBlendCurve.TryLoad()); }
	if(HighlightBlendCurve.IsValid()) { _u_curveHighlight=Cast<UCurveFloat>(HighlightBlendCurve.TryLoad()); }
	
	if(_u_curveHover) { _u_curveHover->GetTimeRange(_f_HoverBlend_Min,_f_HoverBlend_Max); }
	if(_u_curveHighlight) { _u_curveHighlight->GetTimeRange(_f_HighBlend_Min,_f_HighBlend_Max); }
	
	if (GetButtonWidget())
	{
		GetButtonWidget()->OnClicked.AddDynamic(this, &UDataWidget::Select);
		GetButtonWidget()->OnHovered.AddDynamic(this, &UDataWidget::Hover);
	}

	TSubclassOf<UDataTooltip> LocalTooltipClass;
	if(DefaultTooltipWidget)
	{
		LocalTooltipClass = DefaultTooltipWidget;
	}
	else
	{
		LocalTooltipClass = UDataTooltip::StaticClass();
	}

	DefaultCreatedTooltip = CreateWidget<UDataTooltip>(this, LocalTooltipClass);
	DefaultCreatedTooltip->SetOwningWidget(this);

	if(UpdateSourceAssetFromParent)
	{
		if(Cast<UDataWidget>(UCommonUILibrary::FindParentWidgetOfType(this, UDataWidget::StaticClass())))
		{
			OwnerDataWidget = Cast<UDataWidget>(UCommonUILibrary::FindParentWidgetOfType(this, UDataWidget::StaticClass()));
			OwnerDataWidget->OnWidgetRefreshed.AddDynamic(this, &UDataWidget::private_refresh);
		}
	}
	Local_UpdateTooltip(ReferencedAsset);

	if(IsDesignTime())
	{
		const double moddedval = FMath::RandRange(RefreshVariance*-1.0f,RefreshVariance);
		refresh_val= moddedval+RefreshFrequency;
		
		GetWorld()->GetTimerManager().SetTimer(refresh_timer, this, &UDataWidget::Refresh, refresh_val, true);
	}

	if(GetOwningLocalPlayer() && SlotID.IsValid())
	{
		GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SlottedDataWidgets.Add(SlotID,this);
	}
	
	Super::NativeConstruct();
}

void UDataWidget::WidgetNotify(FName Notify)
{
	OnWidgetNotify.Broadcast(this, Notify);
	Local_OnWidgetNotify(Notify);
}

void UDataWidget::OnNewListOwner_Implementation(UObject* ListOwner)
{
}

FString UDataWidget::GetAssetLabel()
{
	FString OutString = "None";
	if (ReferencedAsset)
	{
		IDataInterface_General::Execute_GetGeneralAssetLabel(ReferencedAsset, OutString);
	}
	return OutString;
}

UDataList* UDataWidget::GetOwningList() const
{
	if(ParentList)
	{
		return ParentList;
	}
	return nullptr;
}

void UDataWidget::SetWidgetTagActive(FName Tag, bool bActive)
{
	if(bActive)
	{
		WidgetTags.AddUnique(Tag);
	}
	else
	{
		WidgetTags.Remove(Tag);
	}
	
}

bool UDataWidget::DataWidgetHasTag(FName Tag)
{
	return WidgetTags.Contains(Tag);
}

void UDataWidget::Select()
{
	if(GetIsEnabled() && GetIsEntitySelectable())
	{
		if (GetSelectAnimation())
		{
			PlayAnimationForward(GetSelectAnimation(), 1.0f, false);
		}
		OnSelected.Broadcast(this);
		OnSelect();
		if(GetPlayerSubsystem())
		{
			if(SelectSound)
			{
				GetPlayerSubsystem()->PlayUiSound(SelectSound);
			}
			else if(UOmegaSlateFunctions::GetCurrentSlateStyle())
			{
				GetPlayerSubsystem()->PlayUiSound(UOmegaSlateFunctions::GetCurrentSlateStyle()->Sound_Select);
			}
		}
	}
	else
	{
		if(GetPlayerSubsystem())
		{
			if(ErrorSound)
			{
				GetPlayerSubsystem()->PlayUiSound(ErrorSound);
			}
			else if(UOmegaSlateFunctions::GetCurrentSlateStyle())
			{
				GetPlayerSubsystem()->PlayUiSound(UOmegaSlateFunctions::GetCurrentSlateStyle()->Sound_Error);
			}
		}
	}
}

void UDataWidget::Hover()
{
	if(GetOwningLocalPlayer())
	{
		GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->SetCurrentHoverWidget(this);
	}
}

void UDataWidget::Unhover()
{
	if(GetOwningLocalPlayer())
	{
		UOmegaPlayerSubsystem* _sys =GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
		_sys->TryUnhoverWidget(this);
	}
}

void UDataWidget::SetHighlighted(bool Highlighted)
{
	//Check if already highlighted
	if (b_IsHighlighted != Highlighted)
	{
		//Set new State
		b_IsHighlighted = Highlighted;
		_b_PlayingAnim_highlight=true;
		//Check if Valid Highlight Anim exists
		if (GetHighlightAnimation())
		{
			//play correct animation
			if (b_IsHighlighted)
			{
				PlayAnimationForward(GetHighlightAnimation(), 1.0f, false);
			}
			else
			{
				PlayAnimationReverse(GetHighlightAnimation(), 1.0f, false);
			}
		}
		OnHighlight.Broadcast(this,Highlighted);
		OnHoverStateChange(Highlighted);
	}
}

bool UDataWidget::GetIsEntitySelectable()
{
	return !IsEntityDisabled(ReferencedAsset);
}

bool UDataWidget::IsDataWidgetHovered()
{
	if(GetOwningLocalPlayer())
	{
		return GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->GetCurrentHoverWidget()==this;
	}
	return false;
}

void UDataWidget::SetSourceAsset(UObject* Asset)
{
	if (Asset)	 //Only if valid asset
	{
		//Set Tooltip Asset
		Local_UpdateTooltip(Asset);
			
		ReferencedAsset = Asset;

		Native_OnSourceAssetChanged(ReferencedAsset);
		Refresh();
	}
	
}

void UDataWidget::OnSourceAssetChanged_Implementation(UObject* Asset)
{
}

UDataTooltip* UDataWidget::GetDataTooltipWidget()
{
	return DefaultCreatedTooltip;
}

void UDataWidget::Local_UpdateTooltip(UObject* AssetRef)
{
	if(!AssetRef)
	{
		return;
	}
	if(DefaultCreatedTooltip)
	{
		DefaultCreatedTooltip->OnOwnerSourceAssetChanged(AssetRef);

		if(AssetRef->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
		{
			FText LocalDesc;
			FText LocalName;
		
			IDataInterface_General::Execute_GetGeneralDataText(AssetRef, AssetLabel, this, LocalName, LocalDesc);
		
			//update name widget
			if(DefaultCreatedTooltip->GetAssetNameWidget())
			{
				DefaultCreatedTooltip->GetAssetNameWidget()->SetText(LocalName);
			}
			//update description widget
			if(DefaultCreatedTooltip->GetAssetNameWidget())
			{
				DefaultCreatedTooltip->GetAssetDescriptionWidget()->SetText(LocalDesc);
			}
		}
		
	}
}

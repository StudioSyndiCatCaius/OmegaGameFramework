// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/DataWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Interfaces/I_Common.h"
#include "CommonUILibrary.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Subsystems/Subsystem_Player.h"
#include "Widget/DataList.h"
#include "TimerManager.h"
#include "Functions/F_Utility.h"
#include "OmegaSettings_Slate.h"
#include "Functions/F_Text.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Widget/DataTooltip.h"

bool UDataWidgetTraits::CanAddObjectToList_Implementation(UObject* SourceObject) const
{
	return true;
}

void UDataWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	bIsFocusable = true;
	if(GetNameTextWidget())
	{
		GetNameTextWidget()->SetText(L_FormatText(NameText));
	}

	//Setup Source Asset
	SetSourceAsset(ReferencedAsset);
	SetIsEnabled(!IsEntityDisabled(ReferencedAsset));

	if(GetHoveredMaterialInstance())
	{
		GetHoveredMaterialInstance()->SetScalarParameterValue(HoverWidgetPropertyName,0);
		GetHoveredMaterialInstance()->SetScalarParameterValue(HighlightWidgetPropertyName,0);
	}
	//traits
	for(auto* t : WidgetTraits)
	{
		if(t)
		{
			t->OnInit(this);
		}
	}
	
	Refresh();

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



FText UDataWidget::L_FormatText(FText t)
{
	if (OGF_CFG_STYLE()->bAutoFormatText_onDataWidgets)
	{
		return UOmegaTextFunctions::ApplyGameplayTextFormating(this,t,OGF_CFG_STYLE()->DefaultTextFormatTag,FOmegaCommonMeta());
	}
	return t;
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


TArray<FName> UDataWidget::L_getOvrParamName_Float()
{
	TArray<FName>out;
	GetOverrideFields_Floats().GetKeys(out);
	return out;
}

TArray<FName> UDataWidget::L_getOvrParamName_Bool()
{
	TArray<FName>out;
	GetOverrideFields_Bools().GetKeys(out);
	return out;
}

float UDataWidget::GetWidgetOverride_Float(FName field)
{
	TMap<FName,float> tbl=GetOverrideFields_Floats();
	if (GetOwningList())
	{
		if (GetOwningList()->WidgetOverride_Floats.Contains(field))
		{
			return GetOwningList()->WidgetOverride_Floats[field];
		}
	}
	return tbl.FindOrAdd(field);
}

bool UDataWidget::GetWidgetOverride_Bool(FName field)
{
	TMap<FName,bool> tbl=GetOverrideFields_Bools();
	if (GetOwningList())
	{
		if (GetOwningList()->WidgetOverride_Bools.Contains(field))
		{
			return GetOwningList()->WidgetOverride_Bools[field];
		}
	}
	return tbl.FindOrAdd(field);
}

UDataWidgetTraits* UDataWidget::GetWidgetTrait(TSubclassOf<UDataWidgetTraits> Class, bool FallbackToDefault,
                                               bool& Outcome)
{
	if(Class)
	{
		for(auto* tempMeta : WidgetTraits)
		{
			if(tempMeta && tempMeta->GetClass()->IsChildOf(Class))
			{
				Outcome=true;
				return tempMeta;
			}
		}
		if(FallbackToDefault)
		{
			Outcome=true;
			return Class.GetDefaultObject();
		}
	}
	Outcome=false;
	return  nullptr;
}

TMap<FName, UWidget*> UDataWidget::WidgetBinding_Get_Implementation()
{
	TMap<FName, UWidget*> out;
	if (GetNameTextWidget())
	{
		out.Add("text_name", GetNameTextWidget());
	}
	if (GetDescriptionTextWidget())
	{
		out.Add("text_description", GetDescriptionTextWidget());
	}
	return  out;
}

void UDataWidget::WidgetBinding_Apply_Implementation(FName name, UWidget* widget,UOmegaSlateStyle* Asset)
{
	ApplyDefaultWidgetBinding(name,widget,Asset);
}

void UDataWidget::ApplyDefaultWidgetBinding(FName name, UWidget* widget,UOmegaSlateStyle* Asset)
{
	if (widget && Asset)
	{
		// Safe check and call
		Asset->ApplyStyleAgnostic(widget);
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
			GetNameTextWidget()->SetText(L_FormatText(LocalName));
		}
		if (GetDescriptionTextWidget())
		{
			GetDescriptionTextWidget()->SetText(L_FormatText(LocalDesc));
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
		if(GetWidget_IconMaterial())
		{
			if(Override_IconMaterial)
			{
				GetWidget_IconMaterial()->SetBrushFromMaterial(Override_IconMaterial);
			}
			if(UMaterialInstanceDynamic* _dynaMat = GetWidget_IconMaterial()->GetDynamicMaterial())
			{
				if(LocalTexture && GetWidget_IconMaterial())
				{
					_dynaMat->SetTextureParameterValue(MaterialParamName_IconTexture,LocalTexture);
				}
			}
		}
	}//Finish widget setup
	
	SetIsEnabled(GetIsEntitySelectable());
	UObject* LocalListOwner = nullptr;
	if(UDataList* _list=GetOwningList())
	{
		//Apply style overrides
		TMap<FName,UWidget*> _wigs=WidgetBinding_Get();
	
		TMap<FName,UOmegaSlateStyle*> _binds=_list->WidgetOverride_Styles;
		TArray<FName> _bindNames;
		_binds.GetKeys(_bindNames);
	
		for (FName Name : _bindNames)
		{
			WidgetBinding_Apply(Name,_wigs.FindOrAdd(Name),_binds.FindOrAdd(Name));
		}
		
		if (_list->ListOwner)
		{
			LocalListOwner = GetOwningList()->ListOwner;
		}
	}

	//traits
	for(auto* t : WidgetTraits)
	{
		if(t)
		{
			t->OnRefreshed(this,ReferencedAsset,LocalListOwner);
		}
	}
	
	if (DefaultCreatedTooltip)
	{
		DefaultCreatedTooltip->Refresh();
	}
	
	Native_OnRefreshed(ReferencedAsset,LocalListOwner);
	OnWidgetRefreshed.Broadcast(this);
}

void UDataWidget::Native_OnSourceAssetChanged(UObject* SourceAsset)
{
	//traits
	for(auto* t : WidgetTraits)
	{
		if(t)
		{
			t->OnSourceChanged(this,ReferencedAsset);
		}
	}
	OnSourceAssetChanged(ReferencedAsset);
}

void UDataWidget::Native_OnListOwnerChanged(UObject* ListOwner)
{
	//traits
	for(auto* t : WidgetTraits)
	{
		if(t)
		{
			t->OnListOwnerChanged(this,GetOwningList(),ListOwner);
		}
	}
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
				GetPlayerSubsystem()->PlayUiSound(OGF_CFG_STYLE()->Sound_Hover.LoadSynchronous());
	
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
		if(UDataWidget* _parentDW= Cast<UDataWidget>(UCommonUILibrary::FindParentWidgetOfType(this, UDataWidget::StaticClass())))
		{
			OwnerDataWidget = _parentDW;
			OwnerDataWidget->OnWidgetRefreshed.AddDynamic(this, &UDataWidget::private_refresh);
			SetSourceAsset(OwnerDataWidget->ReferencedAsset);
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

FString UDataWidget::GetAssetLabel() const
{
	FString OutString = "None";
	if (ReferencedAsset && ReferencedAsset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
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
			GetPlayerSubsystem()->PlayUiSound(OGF_CFG_STYLE()->Sound_Select.LoadSynchronous());
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
			GetPlayerSubsystem()->PlayUiSound(OGF_CFG_STYLE()->Sound_Error.LoadSynchronous());
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
	if (GetOwningList() && GetOwningList()->override_tooltip)
	{
		return GetOwningList()->override_tooltip;
	}
	return DefaultCreatedTooltip;
}

UObject* UDataWidget::GetTooltip_SourceObject_Implementation()
{
	return ReferencedAsset;
}

void UDataWidget::Local_UpdateTooltip(UObject* AssetRef)
{
	if(!AssetRef)
	{
		return;
	}
	if(UDataTooltip* target_tooltip=GetDataTooltipWidget())
	{
		target_tooltip->SetOwningWidget(this);
		
	}
}

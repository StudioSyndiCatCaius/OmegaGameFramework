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
	}
	
	//Setup Source Asset
	SetSourceAsset(ReferencedAsset);
	SetIsEnabled(!IsEntityDisabled(ReferencedAsset));

	if(GetHoveredMaterialInstance())
	{
		GetHoveredMaterialInstance()->SetScalarParameterValue(HoverWidgetPropertyName,0);
		GetHoveredMaterialInstance()->SetScalarParameterValue(HighlightWidgetPropertyName,0);
	}

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

void UDataWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	const float HoverValue_target = IsDataWidgetHovered();

	if(HoverValue_current!=HoverValue_target)
	{
		HoverValue_current=UKismetMathLibrary::FInterpTo_Constant(HoverValue_current, HoverValue_target, InDeltaTime, (1.0f/HoverWidgetSpeed));
		if(GetHoveredMaterialInstance())
		{
			GetHoveredMaterialInstance()->SetScalarParameterValue(HoverWidgetPropertyName,HoverValue_current);
		}
		OnHoverUpdate(HoverValue_current);
	}
	const float HighlightValue_target = bIsHighlighted;
	if(HighlightValue_current!=HighlightValue_target)
	{

		HighlightValue_current=UKismetMathLibrary::FInterpTo_Constant(HighlightValue_current, HighlightValue_target, InDeltaTime, (1.0f/HighlightWidgetSpeed));
		
		if(GetHoveredMaterialInstance())
		{
			GetHoveredMaterialInstance()->SetScalarParameterValue(HighlightWidgetPropertyName,HighlightValue_current);
		}
		OnHighlightUpdate(HighlightValue_current);
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

FLuaValue UDataWidget::GetWidgetScript(TSubclassOf<ULuaState> State)
{
	return ULuaObjectFunctions::RunLuaScriptContainer(this,Script,State);
}

FLuaValue UDataWidget::WidgetScriptKeyCall(const FString& key, TArray<FLuaValue> args, TSubclassOf<ULuaState> State)
{
	return ULuaBlueprintFunctionLibrary::LuaTableKeyCall(GetWidgetScript(State),key,args);
}

void UDataWidget::private_refresh(UDataWidget* widget)
{
	if(widget)
	{
		if(ReferencedAsset != widget->ReferencedAsset)
		{
			ReferencedAsset=widget->ReferencedAsset;
			OnSourceAssetChanged(ReferencedAsset);
		}
		
		if (widget->ParentList && widget->ParentList != ParentList)
		{
			ParentList=widget->ParentList;
			OnNewListOwner(ParentList);
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
	OnRefreshed(ReferencedAsset, LocalListOwner);
	OnWidgetRefreshed.Broadcast(this);
}

//----------------------NATIVE CONSTRUCT-------------------------------------------//

void UDataWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//Create default metadata if invalid

	
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
}

void UDataWidget::WidgetNotify(FName Notify)
{
	OnWidgetNotify.Broadcast(this, Notify);
	Local_OnWidgetNotify(Notify);
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
	if(!GetPlayerSubsystem())
	{
		OnHoverStateChange(true);
		return;
	}
	//Cancel if already hovered
	if(IsDataWidgetHovered())
	{
		return;
	}

	if(GetPlayerSubsystem()->HoveredWidget)
	{
		GetPlayerSubsystem()->HoveredWidget->Unhover();
	}
	
	if(UUserWidget* TempWidget = GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->HoveredWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempt Unhvover"));
		Cast<UDataWidget>(TempWidget)->Unhover();
	}
	
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
	GetPlayerSubsystem()->HoveredWidget=this;
	GetOwningLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->HoveredWidget = this;
	OnHoverStateChange(true);
}

void UDataWidget::Unhover()
{
	if(!IsDataWidgetHovered())
	{
		OnHoverStateChange(false);
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Success Unhover"));
	OnHovered.Broadcast(this, false);
	if (GetHoverAnimation())
	{
		PlayAnimationReverse(GetHoverAnimation(), 1.0f, false);
	}
	OnHoverStateChange(false);
	//bIsHovered = false;
}

void UDataWidget::SetHighlighted(bool Highlighted)
{
	//Check if already highlighted
	if (bIsHighlighted != Highlighted)
	{
		//Set new State
		bIsHighlighted = Highlighted;
		//Check if Valid Highlight Anim exists
		if (GetHighlightAnimation())
		{
			//play correct animation
			if (bIsHighlighted)
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
	if(GetPlayerSubsystem() && GetPlayerSubsystem()->HoveredWidget==this)
	{
		return true;
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

		OnSourceAssetChanged(Asset);
		Refresh();
	}
	
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

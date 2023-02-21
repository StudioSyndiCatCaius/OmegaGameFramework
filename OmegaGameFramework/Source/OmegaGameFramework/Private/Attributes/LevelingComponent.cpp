// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/LevelingComponent.h"
#include "GameFramework/Actor.h"

#include "Attributes/ActorInterface_Leveling.h"
#include "Attributes/WidgetInterface_LevelingComponent.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetTextLibrary.h"


// Sets default values for this component's properties
ULevelingComponent::ULevelingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULevelingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULevelingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void ULevelingComponent::AddXP(float Amount, bool bUseRateMultipler)
{
	//Save current Level
	const int32 LastLevel = GetCurrentLevel();
	//Add XP
	XP = XP+Amount;
	
	//If new level is greater than last level
	if(GetCurrentLevel()>LastLevel)
	{
		OnLevelUp.Broadcast(GetCurrentLevel());
	}
	//If Level is less than last level, level down.
	else if (GetCurrentLevel()<LastLevel)
	{
		OnLevelDown.Broadcast(GetCurrentLevel());
	}

	OnXPUpdated.Broadcast(XP, Amount);
	Native_Update();
}

void ULevelingComponent::SetXP(float NewValue, bool bUseRateMultipler)
{
	XP = NewValue;
	OnXPUpdated.Broadcast(XP, XP);
	Native_Update();
}

int32 ULevelingComponent::GetCurrentLevel() const
{
	if(!LevelingAsset)
	{
		return 0;
	}
	return LevelingAsset->GetLevelFromXP(XP);
}

float ULevelingComponent::GetPercentageToNextLevel()
{
	return (XP-GetCurrentLevelMinXP())/(GetCurrentLevelMaxXP()-GetCurrentLevelMinXP());
}

float ULevelingComponent::GetCurrentLevelMinXP()
{
	if(!LevelingAsset)
	{
		return 0.0;
	}
	float DumFloat = 0;
	float OutXP = 0.0;
	LevelingAsset->GetXPFromLevel(GetCurrentLevel(), OutXP, DumFloat);
	return OutXP;
}

float ULevelingComponent::GetCurrentLevelMaxXP()
{
	if(!LevelingAsset)
	{
		return 0.0;
	}
	float DumFloat = 0;
	float OutXP = 0.0;
	LevelingAsset->GetXPFromLevel(GetCurrentLevel(), DumFloat, OutXP);
	return OutXP;
}

float ULevelingComponent::AdjustXPRate(float InXP, bool UseAdjust)
{
	if(UseAdjust)
	{
		return GetXPRate()*XP;
	}
	else
	{
		return InXP;
	}
	Native_Update();
}

void ULevelingComponent::Native_Update()
{
	//Update Widgets
	TArray<UUserWidget*> WidgetList;
	UWidgetBlueprintLibrary::GetAllWidgetsWithInterface(this, WidgetList, UWidgetInterface_LevelingComponent::StaticClass(), false);
	for(auto* TempWidget : WidgetList)
	{
		if(IWidgetInterface_LevelingComponent::Execute_GetLevelingComponent(TempWidget) && (this == IWidgetInterface_LevelingComponent::Execute_GetLevelingComponent(TempWidget)))
		{
			// set progress bar
			UProgressBar* LocalProgBar;
			IWidgetInterface_LevelingComponent::Execute_GetLevelingProgressBar(TempWidget, LocalProgBar);
			if(LocalProgBar)
			{
				LocalProgBar->SetPercent(GetPercentageToNextLevel());
			}
			// Set texts
			UTextBlock* Local_CurText;
			UTextBlock* Local_MaxText;
			UTextBlock* Local_CurLev;
			IWidgetInterface_LevelingComponent::Execute_GetLevelingTexts(TempWidget, Local_CurText, Local_MaxText, Local_CurLev);
				//Set "Current XP" Widget
			if(Local_CurText)
			{
				FText LocalText_Val = UKismetTextLibrary::Conv_FloatToText
					(
						XP,
						LevelingAsset->RoundingMode,
						LevelingAsset->bAlwaysSign,
						LevelingAsset->bUseGrouping,
						LevelingAsset->MinIntegralDigits,
						LevelingAsset->MaxIntegralDigits,
						LevelingAsset->MinFractionalDigits,
						LevelingAsset->MaxFractionalDigits
						);
					
				Local_CurText->SetText(LocalText_Val);
			}
			//Set "Max XP" Widget
			if(Local_MaxText)
			{
				FText LocalText_Val = UKismetTextLibrary::Conv_FloatToText
					(
						GetCurrentLevelMaxXP(),
						LevelingAsset->RoundingMode,
						LevelingAsset->bAlwaysSign,
						LevelingAsset->bUseGrouping,
						LevelingAsset->MinIntegralDigits,
						LevelingAsset->MaxIntegralDigits,
						LevelingAsset->MinFractionalDigits,
						LevelingAsset->MaxFractionalDigits
						);
					
				Local_MaxText->SetText(LocalText_Val);
			}
				//Set "Level" Widget
			if(Local_CurLev)
			{
				FText LocalText_Val = UKismetTextLibrary::Conv_IntToText(GetCurrentLevel());
				Local_CurLev->SetText(LocalText_Val);
			}
		}
	}
	
}

float ULevelingComponent::GetXPRate()
{
	if(GetOwner()->Implements<UActorInterface_Leveling>())
	{
		return XPGainRate+(IActorInterface_Leveling::Execute_GetXPRateOffset(GetOwner()));
	}
	else
	{
		return XPGainRate;
	}
}

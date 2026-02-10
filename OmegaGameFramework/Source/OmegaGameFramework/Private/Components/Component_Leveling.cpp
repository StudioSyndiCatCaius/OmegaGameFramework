// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Leveling.h"
#include "GameFramework/Actor.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/ProgressBar.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetTextLibrary.h"


// Sets default values for this component's properties
ULevelingComponent::ULevelingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

UOmegaLevelingAsset* ULevelingComponent::L_ValidateLevelAsset(UOmegaLevelingAsset* Asset) const
{
	if(Asset)
	{
		return Asset;
	}
	return LevelingAsset;
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

void ULevelingComponent::SetLevelingAsset(UOmegaLevelingAsset* Asset)
{
	if (Asset)
	{
		LevelingAsset=Asset;
	}
}


void ULevelingComponent::AddXP(float Amount, bool bUseRateMultipler,UOmegaLevelingAsset* Leveling_Asset)
{
	//Save current Level
	const int32 LastLevel = GetCurrentLevel(Leveling_Asset);
	//Add XP

	SetXP(GetXP(Leveling_Asset)+Amount,bUseRateMultipler,Leveling_Asset);
	
	//If new level is greater than last level
	if(GetCurrentLevel(Leveling_Asset)>LastLevel)
	{
		OnLevelUp.Broadcast(this,GetCurrentLevel(Leveling_Asset),LastLevel,Leveling_Asset);
	}
	//If Level is less than last level, level down.
	else if (GetCurrentLevel(Leveling_Asset)<LastLevel)
	{
		OnLevelDown.Broadcast(this,GetCurrentLevel(Leveling_Asset),LastLevel,Leveling_Asset);
	}

	OnXPUpdated.Broadcast(this,GetXP(Leveling_Asset), Amount,Leveling_Asset);

}

float ULevelingComponent::GetXP(UOmegaLevelingAsset* Leveling_Asset) const
{
	
	if(UOmegaLevelingAsset* a=L_ValidateLevelAsset(Leveling_Asset))
	{
		if(XP.Contains(a))
		{
			return XP[a];
		}
	}
	return 0.0;
}

void ULevelingComponent::SetXP(float NewValue, bool bUseRateMultipler,UOmegaLevelingAsset* Leveling_Asset)
{
	if(UOmegaLevelingAsset* a=L_ValidateLevelAsset(Leveling_Asset))
	{
		XP.Add(a,NewValue);
		OnXPUpdated.Broadcast(this,GetXP(Leveling_Asset), NewValue,Leveling_Asset);
		Native_Update();
	}
}

void ULevelingComponent::SetLevel(int32 Level,UOmegaLevelingAsset* Leveling_Asset)
{
	if(L_ValidateLevelAsset(Leveling_Asset))
	{
		float min;
		float max;
		L_ValidateLevelAsset(Leveling_Asset)->GetXPFromLevel(Level,min,max);
		SetXP(min);
	}
}

int32 ULevelingComponent::GetCurrentLevel(UOmegaLevelingAsset* Leveling_Asset) const
{
	if(!L_ValidateLevelAsset(Leveling_Asset))
	{
		return 0;
	}
	return L_ValidateLevelAsset(Leveling_Asset)->GetLevelFromXP(GetXP(Leveling_Asset));
}

float ULevelingComponent::GetPercentageToNextLevel(UOmegaLevelingAsset* Leveling_Asset)
{
	float offset=GetCurrentLevelMinXP(Leveling_Asset);
	float cur=GetXP(Leveling_Asset)-offset;
	float max=GetCurrentLevelMaxXP(Leveling_Asset)-offset;
	return cur/max;
}

float ULevelingComponent::GetCurrentLevelMinXP(UOmegaLevelingAsset* Leveling_Asset)
{
	if(!L_ValidateLevelAsset(Leveling_Asset))
	{
		return 0.0;
	}
	float DumFloat = 0;
	float OutXP = 0.0;
	L_ValidateLevelAsset(Leveling_Asset)->GetXPFromLevel(GetCurrentLevel(Leveling_Asset), OutXP, DumFloat);
	return OutXP;
}

float ULevelingComponent::GetCurrentLevelMaxXP(UOmegaLevelingAsset* Leveling_Asset) const
{
	if(!L_ValidateLevelAsset(Leveling_Asset))
	{
		return 0.0;
	}
	float DumFloat = 0;
	float OutXP = 0.0;
	L_ValidateLevelAsset(Leveling_Asset)->GetXPFromLevel(GetCurrentLevel(Leveling_Asset), DumFloat, OutXP);
	return OutXP;
}

bool ULevelingComponent::TransferXP_One(ULevelingComponent* To, float Amount, bool TransferAll,
	UOmegaLevelingAsset* Asset)
{
	if(To && Asset)
	{
		if(TransferAll)
		{
			if(GetXP(Asset)>0.0)
			{
				float _in=GetXP(Asset);
				AddXP(_in*-1,true,Asset);
				To->AddXP(_in,true,Asset);
				return true;
			}
		}
		else
		{
			if(GetXP(Asset)>=Amount)
			{
				AddXP(Amount*-1,true,Asset);
				To->AddXP(Amount,true,Asset);
				return true;
			}
		}
	}
	return false;
}

bool ULevelingComponent::TransferXP_All(ULevelingComponent* To, float Amount, bool TransferAll)
{
	bool _out=false;
	TArray<UOmegaLevelingAsset*> _assets;
	XP.GetKeys(_assets);
	for(auto* i :_assets)
	{
		if(i)
		{
			if(TransferXP_One(To,Amount,TransferAll,i))
			{
				_out=true;
			}
		}
	}
	return _out;
}

float ULevelingComponent::AdjustXPRate(float InXP, bool UseAdjust,UOmegaLevelingAsset* Leveling_Asset)
{
	if(UseAdjust)
	{
		return GetXPRate()*GetXP();
	}
	else
	{
		return InXP;
	}
}

void ULevelingComponent::Native_Update()
{
	//Update Widgets
	
}

/*
 * Leveling Interface
 */

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

/*
 * Leveling Asset
 */
int32 UOmegaLevelingAsset::GetLevelFromXP(float XP)
{
	float MinXP;
	float MaxXP;

	for (int i = 0; i <= MaxRank; i++)
	{
		GetXPFromLevel(i, MinXP, MaxXP);
		//if xp greater than max level
		if(i>=MaxRank)
		{
			return MaxRank;
		}
		//If XP is in this level range
		else if (XP >= MinXP && XP < MaxXP)
		{
			return i;
		}

	}
	return 0;
}

void UOmegaLevelingAsset::GetXPFromLevel(int32 Level, float& MinLevelXP, float& MaxLevelXP)
{
	const float LevelFloat = static_cast<float>(Level);
	MinLevelXP = ValueCurve.GetRichCurve()->Eval(LevelFloat);
	MaxLevelXP = ValueCurve.GetRichCurve()->Eval(LevelFloat+1.0);
}


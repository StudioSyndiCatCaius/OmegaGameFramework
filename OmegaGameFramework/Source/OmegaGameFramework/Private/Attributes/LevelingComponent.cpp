// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/LevelingComponent.h"


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

void ULevelingComponent::AddXP(float Amount)
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

	OnXPUpdated.Broadcast(XP);
}

void ULevelingComponent::SetXP(float NewValue)
{
	XP = NewValue;
	OnXPUpdated.Broadcast(XP);
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
	return XP/GetCurrentLevelMaxXP();
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


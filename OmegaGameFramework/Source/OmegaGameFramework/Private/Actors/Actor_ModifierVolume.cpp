// Fill out your copyright notice in the Description page of Project Settings.


// Sets default values

#include "Actors/Actor_ModifierVolume.h"

#include "Condition/Condition_Actor.h"
#include "Functions/F_Actor.h"

void AActor_ModifierVolume::L_RunModifier()
{
	for(auto* a : L_GetActorsToMod())
	{
		if(a)
		{
			FActorModifiers mods;
			mods.Script=Modifiers;
			mods.ApplyMods(a);
		}
	}
}

TArray<AActor*> AActor_ModifierVolume::L_GetActorsToMod() const
{
	TArray<AActor*> out;
	for(auto a : Modify_Direct)
	{
		if(a.IsValid())
		{
			out.Add(a.LoadSynchronous());
		}
	}
	
	if(Modify_Overlaps)
	{
		TArray<AActor*> overlapped;
		GetOverlappingActors(overlapped);
		for(auto* a : overlapped)
		{
			if(a)
			{
				FOmegaConditions_Actor con;
				con.Conditions=Modify_OverlapFilter;
				if(con.CheckConditions(a))
				{
					out.Add(a);
				}
			}
		}
	}

	return out;
}

AActor_ModifierVolume::AActor_ModifierVolume()
{
	Range=CreateDefaultSubobject<UBoxComponent>("Range");
	RootComponent=Range;
}

void AActor_ModifierVolume::BeginPlay()
{
	if(Modify_Delay<=0.0)
	{
		L_RunModifier();
	}
	else
	{
		GetWorldTimerManager().SetTimer(timer_toMod,this,&AActor_ModifierVolume::L_RunModifier,Modify_Delay,false);
	}
	Super::BeginPlay();
}

void AActor_ModifierVolume::OnTagEvent_Implementation(FGameplayTag Event)
{
	TArray<FGameplayTag> _tags;
	Modifiers_OnTagEvent.GetKeys(_tags);
	for(FGameplayTag c : _tags)
	{
		if(Event.MatchesTagExact(c))
		{
			for(auto* a : L_GetActorsToMod())
			{
				if(a)
				{
					Modifiers_OnTagEvent[c].ApplyMods(a);
				}
			}
		}
	}
}

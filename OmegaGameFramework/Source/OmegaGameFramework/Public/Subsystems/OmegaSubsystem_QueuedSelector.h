// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Materials/MaterialExpression.h"
#include "GameplayTags.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaSubsystem_QueuedSelector.generated.h"

UINTERFACE(MinimalAPI)
class UInterface_QueuedSelector : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IInterface_QueuedSelector
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Queued Delay")
	UObject* GetQueuedSelectorObject(FGameplayTag Tag, int32& Priority);

};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_QueuedSelector : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY() TArray<UObject*> queued_sources;
	
public:

	UFUNCTION(BlueprintCallable, Category="Omega|Queued Delay",meta=(DeterminesOutputType="Class",ExpandBoolAsExecs="Result"))
	UObject* GetQueuedSelectedObject(FGameplayTag Tag,UObject* Fallback, TSubclassOf<UObject> Class,bool& Result);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Queued Delay")
	bool SetQueuedSelectorSourceRegistered(UObject* Source, bool bIsRegistered);
};

inline UObject* UOmegaSubsystem_QueuedSelector::GetQueuedSelectedObject(FGameplayTag Tag, UObject* Fallback,
	TSubclassOf<UObject> Class, bool& Result)
{
	
	TArray<UObject*> possibles;
	TMap<UObject*,int32> possible_ints;
	
	for(auto* s : queued_sources)
	{
		if(s)
		{
			int32 _pri;
			if(UObject* _obj=IInterface_QueuedSelector::Execute_GetQueuedSelectorObject(s,Tag,_pri))
			{
				if(!Class || _obj->GetClass()->IsChildOf(Class))
				{
					possibles.Add(_obj);
					possible_ints.Add(_obj,_pri);
				}
			}
			
		}
	}

	// Sort in descending order (highest priority first)
	possibles.Sort([&possible_ints](const UObject& A, const UObject& B) {
		int32 PriorityA = possible_ints.FindRef(&A);
		int32 PriorityB = possible_ints.FindRef(&B);
		return PriorityA > PriorityB;
	});
	
	if(possibles.IsValidIndex(0))
	{
		Result=true;
		return possibles[0];
	}
	if(Fallback && (!Class || Fallback->GetClass()->IsChildOf(Class)))
	{
		Result=true;
		return Fallback;
	}
	Result=false;
	return nullptr;
}

inline bool UOmegaSubsystem_QueuedSelector::SetQueuedSelectorSourceRegistered(UObject* Source, bool bIsRegistered)
{
	if(Source && Source->GetClass()->ImplementsInterface(UInterface_QueuedSelector::StaticClass()))
	{
		if(bIsRegistered && !queued_sources.Contains(Source))
		{
			queued_sources.Add(Source);
			return true;
		}
		if(!bIsRegistered && queued_sources.Contains(Source))
		{
			queued_sources.Remove(Source);
			return true;
		}
	}
	return false;
}




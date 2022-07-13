// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OmegaLinearEvent.h"
#include "OmegaLinearEventSubsystem.h"
#include "../../../../RiderLink/Source/RD/thirdparty/clsocket/src/ActiveSocket.h"
#include "OmegaLinearEventInstance.generated.h"

class UOmegaLinearEventSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEventSequenceFinish);

UCLASS()
class OMEGASEQUENCE_API UOmegaLinearEventInstance : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;
	
	UPROPERTY()
	FLinearEventSequence SequenceData;
	
	UPROPERTY()
	int32 ActiveIndex = -1;

	UPROPERTY(BlueprintAssignable)
	FOnEventSequenceFinish OnEventSequenceFinish;

	UFUNCTION()
	void NextEvent();
	UFUNCTION()
	void EndInstance();
	
};

inline void UOmegaLinearEventInstance::NextEvent()
{
	if(SequenceData.Events.IsValidIndex(ActiveIndex))
	{
		SequenceData.Events[ActiveIndex]->EventEnded.RemoveDynamic(this, &UOmegaLinearEventInstance::NextEvent);
	}
	
	ActiveIndex = ActiveIndex +1;
	
	if(SequenceData.Events.IsValidIndex(ActiveIndex))
	{
		UOmegaLinearEvent* TempEvent = SequenceData.Events[ActiveIndex];
		TempEvent->EventEnded.AddDynamic(this, &UOmegaLinearEventInstance::NextEvent);
		TempEvent->GameInstanceRef = SubsystemRef->GameInstanceReference;
		TempEvent->OnEventBegin();
	}
	else
	{
		EndInstance();
	}
	
}

inline void UOmegaLinearEventInstance::EndInstance()
{
	OnEventSequenceFinish.Broadcast();
	SubsystemRef->TempEvents.Remove(this);
}

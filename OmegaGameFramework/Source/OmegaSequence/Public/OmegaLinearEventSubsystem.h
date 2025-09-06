// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "UObject/Interface.h"
#include "Choice/OmegaLinearChoiceInstance.h"
#include "OmegaLinearEventSubsystem.generated.h"


class UOmegaLinearEventInstance;

USTRUCT(BlueprintType)
struct FLinearEventSequence
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="LinearEvents", instanced, EditAnywhere)
	TArray<class UOmegaLinearEvent*> Events;
};

USTRUCT(BlueprintType)
struct FOmegaLinearEventScriptData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Script")
	FString Event_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Script")
	FString Event_Data;
};

USTRUCT(BlueprintType)
struct FQueuedLinearEventData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QueuedLinearEvent")
	int32 priority=0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QueuedLinearEvent")
	FLinearEventSequence Events;
};


UINTERFACE(MinimalAPI)
class UQueuedLinearEventInterface : public UInterface { GENERATED_BODY() };
class OMEGASEQUENCE_API IQueuedLinearEventInterface
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category = "LinearEvents|Queued")
	TArray<FQueuedLinearEventData> GetQueuedLinearEvents(const FString& Key);
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLinearEventBegin, const UOmegaLinearEventInstance*, Instance, const UOmegaLinearEvent*, Event, int32, EventIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLinearEventSequenceEnd, const UOmegaLinearEventInstance*, Instance, FString, Flag);

UCLASS(DisplayName="Omega Subsystem: Linear Events")
class OMEGASEQUENCE_API UOmegaLinearEventSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION()
	void Local_EndEvent(const FString& Flag, UOmegaLinearEventInstance* Instance);
	UFUNCTION()
	void Local_NewEvent(UOmegaLinearEventInstance* Instance, int32 EventIndex, UOmegaLinearEvent* Event);
public:
	
	UPROPERTY()
	UGameInstance* GameInstanceReference;
	
	UFUNCTION(BlueprintCallable, Category="LinearEvent", meta=(AdvancedDisplay="StartingEvent"))
	UOmegaLinearEventInstance* PlayLinearEvent(FLinearEventSequence Sequence, int32 StartingEvent);

	UFUNCTION(BlueprintCallable, Category="LinearEvent", meta=(AdvancedDisplay="StartingEvent"))
	UOmegaLinearEventInstance* PlayLinearEventFromID(FLinearEventSequence Sequence, FName ID);
	
	UPROPERTY()
	TArray<UOmegaLinearEventInstance*> TempEvents;

	UFUNCTION(BlueprintPure, Category="LinearEvent")
	TArray<UOmegaLinearEventInstance*> GetActiveEventInstances() const
	{
		return TempEvents;
	}

	UPROPERTY(BlueprintAssignable)
	FOnLinearEventBegin OnLinearEventBegin;
	UPROPERTY(BlueprintAssignable)
	FOnLinearEventSequenceEnd OnLinearEventSequenceEnd;
	
	// ============================================================================================================
	// CHOICE
	// ============================================================================================================
	UFUNCTION(BlueprintCallable, Category="LinearEvent")
	AOmegaLinearChoiceInstance* PlayLinearChoice(FOmegaLinearChoices Choices, TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass);

	// ============================================================================================================
	// Queued Events
	// ============================================================================================================
private:
	UPROPERTY() TArray<UObject*> Queued_event_sources;
public:
	
	UFUNCTION(BlueprintCallable,Category="LinearEvents|Queued")
	void RegisterQueuedLinearEventSource(UObject* Source, bool bRegistered);

	UFUNCTION(BlueprintCallable,Category="LinearEvents|Queued")
	FLinearEventSequence GetLinearEventsFromQueueKey(const FString& Key);
};

UCLASS(Blueprintable, BlueprintType)
class OMEGASEQUENCE_API UOmegaLinearEventScriptReader : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, Category="Script")
	TSubclassOf<UOmegaDataParserReader> GetParserClass();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Script")
	TArray<FOmegaLinearEventScriptData> ConvertScriptToEventData(const FString& Script);

	UFUNCTION(BlueprintImplementableEvent, Category="Script")
	TSubclassOf<UOmegaLinearEvent> GetEventClassFromString(const FString& Script);

	UFUNCTION(BlueprintCallable, Category="Script")
	FLinearEventSequence ConvertToLinearEventSequence(const FString& Script, TSubclassOf<UOmegaDataParserReader> ReaderClass, bool ScriptIsPath);
	
};


UINTERFACE(MinimalAPI)
class UDataInterface_EventSequence : public UInterface { GENERATED_BODY() };

class OMEGASEQUENCE_API IDataInterface_EventSequence
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Omega|LinearEvents")
	FLinearEventSequence GetEventSequence(const FString& Flag);
};


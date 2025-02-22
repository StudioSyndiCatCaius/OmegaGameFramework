// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "LuaInterface.h"
#include "OmegaLinearEventSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "OmegaLinearEvent.generated.h"

class UWorld;
class UOmegaLinearEventSubsystem;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEventBegin, UOmegaLinearEvent*, Event, const FString&, Flag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEventEnded, UOmegaLinearEvent*, Event, const FString&, Flag);

UCLASS(BlueprintType, Blueprintable, abstract, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGASEQUENCE_API UOmegaLinearEvent : public UObject
{
	GENERATED_BODY()
public:
	UOmegaLinearEvent(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UPROPERTY() UWorld* WorldPrivate = nullptr;
	UPROPERTY() UGameInstance* GameInstanceRef = nullptr;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;

	UPROPERTY() FGuid EventGuid;
	UFUNCTION(BlueprintCallable,Category="LinearEvent|Guid")
	void SetEventGuid(FGuid Guid)
	{
		if(Guid.IsValid())
		{
			EventGuid=Guid;
		}
	};
	UFUNCTION(BlueprintPure,Category="LinearEvent|Guid") FGuid GetEventGuid()
	{
		if(!EventGuid.IsValid())
		{
			EventGuid=FGuid::NewGuid();
		}
		return  EventGuid;
	};
	
	UPROPERTY() UOmegaLinearEventSubsystem* SubsystemRef;

	UFUNCTION(BlueprintNativeEvent, Category="LinearEvent")
	bool CanPlayEvent();

	UPROPERTY(BlueprintAssignable,Category="LinearEvent") FOnEventBegin EventBegin;
	UPROPERTY(BlueprintAssignable,Category="LinearEvent") FOnEventEnded EventEnded;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="LinearEvent", AdvancedDisplay)
	FName EventID;

	UPROPERTY()
	FName IncomingEventID;
	
	///FUNCTIONS

	UFUNCTION() virtual void Native_Begin(const FString& Flag="");
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventBegin(const FString& Flag);
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventEnd(const FString& Flag);
	
	UFUNCTION(BlueprintCallable, Category="LinearEvent", meta=(AdvancedDisplay="JumpToID"))
	void Finish(const FString& Flag, const FName JumpToID = FName(""));

	UFUNCTION(BlueprintCallable, Category="LinearEvent")
	void StopEventSequence();
	
	UFUNCTION(BlueprintCallable, Category="LinearEvent")
	void JumpToEvent(FName Event, bool EndSequenceIfFail);
	
	UFUNCTION(BlueprintNativeEvent, Category="LinearEvent")
	FString GetLogString() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="LinearEvent")
	bool ReadParsedData(UOmegaDataParserReader* ParsedData);
	
};


// =========================================================================================================================
// Convertor
// =========================================================================================================================

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaLinearEventReaderData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Instanced, BlueprintReadWrite,Category="LinearEventReader")
	UOmegaLinearEventReader* Reader;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="LinearEventReader")
	FString SourceString;
};


UCLASS(BlueprintType,Blueprintable,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGASEQUENCE_API UOmegaLinearEventReader : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="LinearEventReader")
	FString Convert_EventsToString(UObject* WorldContextObject, FLinearEventSequence Sequence);
	UFUNCTION(BlueprintImplementableEvent,Category="LinearEventReader")
	FLinearEventSequence Convert_StringToEvents(UObject* WorldContextObject, const FString& String);
};

UCLASS()
class OMEGASEQUENCE_API UOmegaLinearEventFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable,Category="Omega|LinearEvent|Reader",meta=(WorldContext="WorldContextObject"))
	static FLinearEventSequence CreateLinearEventSequence_FromReader(UObject* WorldContextObject, UOmegaLinearEventReader* Reader, const FString& SourceString);
	UFUNCTION(BlueprintCallable,Category="Omega|LinearEvent|Reader",meta=(WorldContext="WorldContextObject"))
	static FString CreateLinearEventString_FromReader(UObject* WorldContextObject, UOmegaLinearEventReader*  Reader, FLinearEventSequence Events);
};
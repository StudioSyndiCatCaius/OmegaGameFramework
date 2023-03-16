// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Event/OmegaLinearEvent.h"
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLinearEventBegin, const UOmegaLinearEvent*, Event);

UCLASS(DisplayName="Omega Subsystem: Linear Events")
class OMEGASEQUENCE_API UOmegaLinearEventSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;


public:
	UPROPERTY()
	UGameInstance* GameInstanceReference;
	
	UFUNCTION(BlueprintCallable, Category="LinearEvent", meta=(AdvancedDisplay="StartingEvent"))
	UOmegaLinearEventInstance* PlayLinearEvent(FLinearEventSequence Sequence, int32 StartingEvent);

	UFUNCTION(BlueprintCallable, Category="LinearEvent", meta=(AdvancedDisplay="StartingEvent"))
	UOmegaLinearEventInstance* PlayLinearEventFromID(FLinearEventSequence Sequence, FName ID);
	
	UPROPERTY()
	TArray<UOmegaLinearEventInstance*> TempEvents;

	UPROPERTY(BlueprintAssignable)
	FOnLinearEventBegin OnLinearEventBegin;


	///CHOICE
	UFUNCTION(BlueprintCallable, Category="LinearEvent")
	AOmegaLinearChoiceInstance* PlayLinearChoice(FOmegaLinearChoices Choices, TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass);
};

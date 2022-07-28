// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaLinearChoiceInstance.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AyncLinearChoice.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFinish, UOmegaLinearChoice*, Choice, int32, ChoiceIndex);

UCLASS()
class OMEGASEQUENCE_API UAyncLinearChoice : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;
	UPROPERTY()
	FOmegaLinearChoices ChoiceData;
	UPROPERTY()
	TSubclassOf<AOmegaLinearChoiceInstance> InstanceClassRef;
	UFUNCTION()
	void LocalChoiceSelected(UOmegaLinearChoice* Choice, int32 ChoiceIndex);

	UPROPERTY(BlueprintAssignable)
	FOnFinish OnSelected;
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="OmegaSequence", DisplayName="Play Linear Choice")
	static UAyncLinearChoice* PlayLinearChoice(UOmegaLinearEventSubsystem* Subsystem, FOmegaLinearChoices Choices, TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass);

};

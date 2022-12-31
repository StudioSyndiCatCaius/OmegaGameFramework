// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Event/OmegaLinearEvent.h"
#include "LinearEvent_Delay.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Event (Delay)")
class OMEGADEMO_API ULinearEvent_Delay : public UOmegaLinearEvent
{
	GENERATED_BODY()

public:
	virtual void Native_Begin() override;
	
	UPROPERTY()
	FTimerHandle Local_TimerHandle;
	UFUNCTION()
	void Local_TimerEnd();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fade")
	float Duration = 1;
};

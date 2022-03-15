// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "OmegaStoryWorldSubsystem.h"
#include "Components/ActorComponent.h"
#include "OmegaSpeakerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGASTORY_API UOmegaSpeakerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOmegaSpeakerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY()
	UOmegaStoryWorldSubsystem* SubsystemRef;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	//SPEAKER
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Speaker")
	FGameplayTag SpeakerID;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Speaker")
    FText SpeakerName;
	
};

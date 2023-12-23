// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Components/ActorComponent.h"
#include "OmegaComponent.generated.h"


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//USubscriptComponent();

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void ActivateTick(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void DectivateTick(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void DebugTick(bool isActive, float DeltaTime);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void OnActivation(bool IsActive);
	
	UPROPERTY(BlueprintReadWrite, Category="Default", DisplayName="Metadata")
	FJsonObjectWrapper JsonMetadata;

	UPROPERTY(EditAnywhere, Category="Debug")
	bool bDebug;

private:
	virtual void Activate(bool bReset) override;
	virtual void Deactivate() override;
};

inline void UOmegaComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	if(IsActive())
	{
		ActivateTick(DeltaTime);
	}
	else
	{
		DectivateTick(DeltaTime);
	}
	if(bDebug)
	{
		DebugTick(IsActive(),DeltaTime);
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

inline void UOmegaComponent::Activate(bool bReset)
{
	Super::Activate(bReset);
	OnActivation(true);
}

inline void UOmegaComponent::Deactivate()
{
	Super::Deactivate();
	OnActivation(false);
}


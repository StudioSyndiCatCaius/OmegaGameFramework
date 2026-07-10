// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/OmegaUtils_Macros.h"
#include "OmegaComponent.generated.h"


// Abstract base component that splits tick into active/inactive phases and exposes activation state events to Blueprint.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaComponent : public UActorComponent
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;
	virtual void Activate(bool bReset) override;
	virtual void Deactivate() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	// Called every frame while this component is active.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void ActivateTick(float DeltaTime);

	// Called every frame while this component is inactive.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void DectivateTick(float DeltaTime);

	// Called every frame with the current active state; useful for debug-only Blueprint visualization.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void DebugTick(bool isActive, float DeltaTime);

	// Called when the component is activated or deactivated; IsActive reflects the new state.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void OnActivation(bool IsActive);

	// Enables verbose debug behavior for this component when true.
	UPROPERTY(EditAnywhere, Category="Debug")
	bool bDebug;


};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/OmegaUtils_Macros.h"
#include "OmegaComponent.generated.h"


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

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void ActivateTick(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void DectivateTick(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void DebugTick(bool isActive, float DeltaTime);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Omega Component")
	void OnActivation(bool IsActive);
	
	UPROPERTY(EditAnywhere, Category="Debug")
	bool bDebug;


};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaLevelingAsset.h"
#include "Components/ActorComponent.h"
#include "LevelingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnXpUpdated, float, XP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelUp, int32, NewLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelDown, int32, NewLevel);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API ULevelingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULevelingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Leveling")
	UOmegaLevelingAsset* LevelingAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Leveling")
	float XP;
	
	UPROPERTY(BlueprintAssignable)
	FOnLevelUp OnLevelUp;
	UPROPERTY(BlueprintAssignable)
	FOnLevelDown OnLevelDown;
	UPROPERTY(BlueprintAssignable)
	FOnXpUpdated OnXPUpdated;

	UFUNCTION(BlueprintCallable, Category="Leveling")
	void AddXP (float Amount);

	UFUNCTION(BlueprintCallable, Category="Leveling")
	void SetXP (float NewValue);

	UFUNCTION(BlueprintPure, Category="Leveling")
	int32 GetCurrentLevel() const;

	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetPercentageToNextLevel();

	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetCurrentLevelMinXP();
	
	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetCurrentLevelMaxXP();
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaLevelingAsset.h"
#include "Components/ActorComponent.h"
#include "LevelingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnXpUpdated, float, XP, float, AmountChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelUp, int32, NewLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelDown, int32, NewLevel);


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Leveling", meta=(ExposeOnSpawn="true"))
	UOmegaLevelingAsset* LevelingAsset;

	//Multiplier used to offset xp when "Add XP" is called. E.G., a rate multiplier of "0.75" when using AddXP, 100 XP becomes 75 XP.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Leveling", meta=(ExposeOnSpawn="true"))
	float XPGainRate = 1.0;

	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetXPRate();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Leveling")
	float XP;
	
	UPROPERTY(BlueprintAssignable)
	FOnLevelUp OnLevelUp;
	UPROPERTY(BlueprintAssignable)
	FOnLevelDown OnLevelDown;
	UPROPERTY(BlueprintAssignable)
	FOnXpUpdated OnXPUpdated;

	UFUNCTION(BlueprintCallable, Category="Leveling", meta=(AdvancedDisplay ="bUseRateMultipler"))
	void AddXP (float Amount, bool bUseRateMultipler = true);

	UFUNCTION(BlueprintCallable, Category="Leveling", meta=(AdvancedDisplay ="bUseRateMultipler"))
	void SetXP (float NewValue, bool bUseRateMultipler = true);

	UFUNCTION(BlueprintPure, Category="Leveling")
	int32 GetCurrentLevel() const;

	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetPercentageToNextLevel();

	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetCurrentLevelMinXP();
	
	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetCurrentLevelMaxXP();

	UFUNCTION()
	float AdjustXPRate(float InXP, bool UseAdjust);

protected:
	UFUNCTION()
	void Native_Update();
	
};

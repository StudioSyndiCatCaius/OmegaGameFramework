// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Curves/CurveFloat.h"
#include "UObject/Interface.h"
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


// This class does not need to be modified.
UINTERFACE()
class UActorInterface_Leveling : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IActorInterface_Leveling
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	//Adds to the base XpRate value.
	UFUNCTION(BlueprintNativeEvent, Category="Leveling")
	float GetXPRateOffset();

};


UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaLevelingAsset : public UDataAsset
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling", DisplayName="Level Name")
	FText RankName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FText XPName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	int32 MaxRank = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FRuntimeFloatCurve ValueCurve;

	UFUNCTION(BlueprintPure, Category = "Leveling")
	int32 GetLevelFromXP(float XP);

	UFUNCTION(BlueprintPure, Category = "Leveling")
	void GetXPFromLevel(int32 Level, float& MinLevelXP, float& MaxLevelXP);

	///Widget
	UPROPERTY(EditAnywhere, Category="Widget")
	TEnumAsByte<ERoundingMode> RoundingMode = ERoundingMode::HalfToEven;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bAlwaysSign;
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bUseGrouping = true;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinIntegralDigits = 1;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxIntegralDigits = 324;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinFractionalDigits;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxFractionalDigits = 0;
};


// This class does not need to be modified.
UINTERFACE()
class UWidgetInterface_LevelingComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IWidgetInterface_LevelingComponent
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	ULevelingComponent* GetLevelingComponent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	void GetLevelingTexts(UTextBlock*& CurrentValue, class UTextBlock*& MaxValue, UTextBlock*& CurrentLevel);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	void GetLevelingProgressBar(UProgressBar*& ProgressBar);
};

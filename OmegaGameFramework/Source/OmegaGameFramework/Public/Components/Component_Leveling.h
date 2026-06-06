// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "UObject/Interface.h"
#include "Components/ActorComponent.h"
#include "Component_Leveling.generated.h"

class UCurveFloat;
/*
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnXpUpdated, ULevelingComponent*, Component, float, XP, float, AmountChanged,UOmegaLevelingAsset*, Asset);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnLevelChange, ULevelingComponent*, Component, int32, NewLevel,int32,PreviousLevel,UOmegaLevelingAsset*, Asset);

// A leveling component that manages experience points (XP) progression using customizable curves and rates, with support for level-up/down events and UI integration through widget interfaces.
UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent),HideCategories="Navigation, Cooking, Activation, AssetUserData, Asset User Data")
class OMEGAGAMEFRAMEWORK_API ULevelingComponent : public UOmegaGameplayComponent
{
	GENERATED_BODY()

public:
	ULevelingComponent();

	UPROPERTY(BlueprintAssignable, Category="Omega") FOnLevelChange OnLevelUp;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnLevelChange OnLevelDown;
	UPROPERTY(BlueprintAssignable, Category="Omega") FOnXpUpdated OnXPUpdated;

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UOmegaLevelingAsset* L_ValidateLevelAsset(UOmegaLevelingAsset* Asset) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Leveling", meta=(ExposeOnSpawn),DisplayName="Default Leveling Asset")
	UOmegaLevelingAsset* LevelingAsset=nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Leveling")
	TMap<UOmegaLevelingAsset*,float> XP;

	//Multiplier used to offset xp when "Add XP" is called. E.G., a rate multiplier of "0.75" when using AddXP, 100 XP becomes 75 XP.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Leveling", meta=(ExposeOnSpawn))
	float XPGainRate = 1.0;

	UFUNCTION(BlueprintCallable,Category="Leveling")
	void SetLevelingAsset(UOmegaLevelingAsset* Asset);

	UFUNCTION(BlueprintPure, Category="Leveling")
	float GetXPRate();

	UFUNCTION(BlueprintCallable, Category="Leveling", meta=(AdvancedDisplay ="bUseRateMultipler,Leveling_Asset"))
	void AddXP (float Amount, bool bUseRateMultipler = true,UOmegaLevelingAsset* Leveling_Asset=nullptr);
	UFUNCTION(BlueprintPure, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	float GetXP (UOmegaLevelingAsset* Leveling_Asset=nullptr) const;
	UFUNCTION(BlueprintCallable, Category="Leveling", meta=(AdvancedDisplay ="bUseRateMultipler,Leveling_Asset"))
	void SetXP (float NewValue, bool bUseRateMultipler = true,UOmegaLevelingAsset* Leveling_Asset=nullptr);
	UFUNCTION(BlueprintCallable, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	void SetLevel (int32 Level,UOmegaLevelingAsset* Leveling_Asset=nullptr);
	UFUNCTION(BlueprintPure, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	int32 GetCurrentLevel(UOmegaLevelingAsset* Leveling_Asset=nullptr) const;

	UFUNCTION(BlueprintPure, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	float GetPercentageToNextLevel(UOmegaLevelingAsset* Leveling_Asset=nullptr);

	UFUNCTION(BlueprintPure, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	float GetCurrentLevelMinXP(UOmegaLevelingAsset* Leveling_Asset=nullptr);

	UFUNCTION(BlueprintPure, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	float GetCurrentLevelMaxXP(UOmegaLevelingAsset* Leveling_Asset=nullptr) const;

	UFUNCTION(BlueprintCallable, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	bool TransferXP_One(ULevelingComponent* To, float Amount, bool TransferAll,UOmegaLevelingAsset* Asset);

	UFUNCTION(BlueprintCallable, Category="Leveling", meta=(AdvancedDisplay ="Leveling_Asset"))
	bool TransferXP_All(ULevelingComponent* To, float Amount, bool TransferAll);

	UFUNCTION()
	float AdjustXPRate(float InXP, bool UseAdjust,UOmegaLevelingAsset* Leveling_Asset=nullptr);

protected:
	UFUNCTION()
	void Native_Update();

};
*/

// This class does not need to be modified.
UINTERFACE()
class UActorInterface_Leveling : public UInterface
{
	GENERATED_BODY()
};

class OMEGAGAMEFRAMEWORK_API IActorInterface_Leveling
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	// Returns an additive offset applied on top of the base XP gain rate.
	UFUNCTION(BlueprintNativeEvent, Category="Leveling")
	float GetXPRateOffset();



};


// Defines an XP/level progression curve and display formatting for a single type of leveling (e.g. combat rank, crafting skill).
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelingAsset : public UOmegaDataAsset
{
	GENERATED_BODY()

public:

	// Display name shown in UI for this XP type (e.g. "Experience", "Crafting XP").
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FText XPName;

	// The highest level achievable on this leveling track.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	int32 MaxRank = 100;

	// Curve that maps XP value to level; the X axis is XP and the Y axis is the corresponding level.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FRuntimeFloatCurve ValueCurve;

	// Returns the level that corresponds to the given raw XP value.
	UFUNCTION(BlueprintPure, Category = "Leveling")
	int32 GetLevelFromXP(float XP);

	// Returns the minimum and maximum XP bounds for the given level.
	UFUNCTION(BlueprintPure, Category = "Leveling")
	void GetXPFromLevel(int32 Level, float& MinLevelXP, float& MaxLevelXP);

	FText GetTextFromValue(float Value) const;

	///Widget
	// Rounding rule used when formatting XP values for display in widgets.
	UPROPERTY(EditAnywhere, Category="Widget")
	TEnumAsByte<ERoundingMode> RoundingMode = ERoundingMode::HalfToEven;

	// When true, always show a sign (+ or -) on displayed XP values.
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bAlwaysSign;
	// When true, digit grouping separators (e.g. commas) are used in displayed values.
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bUseGrouping = true;

	// Minimum number of digits shown before the decimal point.
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinIntegralDigits = 1;
	// Maximum number of digits shown before the decimal point.
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxIntegralDigits = 324;
	// Minimum number of digits shown after the decimal point.
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinFractionalDigits;
	// Maximum number of digits shown after the decimal point.
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

	// Provides the text blocks used to display current XP value, max XP value, and current level in this widget.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	void GetLevelingTexts(UTextBlock*& CurrentValue, class UTextBlock*& MaxValue, UTextBlock*& CurrentLevel);

	// Provides the progress bar used to display XP progress toward the next level in this widget.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Leveling")
	void GetLevelingProgressBar(UProgressBar*& ProgressBar);
};

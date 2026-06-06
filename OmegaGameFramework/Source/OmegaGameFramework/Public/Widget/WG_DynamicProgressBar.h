// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "WG_DynamicProgressBar.generated.h"

class UCombatantComponent;
class UOmegaAttribute;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDynamicProgressBarPercentChanged, float, NewPercent);

/**
 * Image widget that drives a dynamic material's scalar parameters to represent
 * a progress percentage. Supports an optional "ghost" value that lags behind
 * the real value: when the percent changes the ghost holds for Ghost_DelayStart
 * seconds, then interpolates toward the current percent over Ghost_InterpTime.
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UDynamicProgressBar : public UImage
{
	GENERATED_BODY()

	// -----------------------------------------------------------------------
	// Private state
	// -----------------------------------------------------------------------
	UPROPERTY() UOmegaAttribute* BoundAttribute = nullptr;
	UPROPERTY() UCombatantComponent* BoundCombatant = nullptr;
	UPROPERTY() float GhostPercent = 0.5f;

	FTimerHandle GhostDelayTimerHandle;
	FTimerHandle GhostInterpTimerHandle;

	UFUNCTION() void StartGhostInterp();
	UFUNCTION() void TickGhostInterp();

public:
	
	UDynamicProgressBar();

	// -----------------------------------------------------------------------
	// Material parameter names (editable so the artist can match their shader)
	// -----------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar",AdvancedDisplay)
	FName MatParam_ProgressPercent = "Progress";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar",AdvancedDisplay)
	FName MatParam_GhostPercent = "Ghost";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar",AdvancedDisplay)
	FName MatParam_ProgressColor = "Progress_Color";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar",AdvancedDisplay)
	FName MatParam_GhostColor = "Ghost_Color";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar")
	UMaterialInterface* Material=nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar")
	FLinearColor ProgressColor = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar")
	FLinearColor GhostColor = FLinearColor(1.f, 0.5f, 0.f, 1.f);

	// -----------------------------------------------------------------------
	// Ghost settings
	// -----------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar")
	bool EnableGhosting = false;

	/** Seconds to wait after a percent change before the ghost starts moving. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar",
		meta=(EditCondition="EnableGhosting", ClampMin="0.0"))
	float Ghost_DelayStart = 1.2f;

	/** Seconds for the ghost to travel the full 0→1 range (constant speed). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar",
		meta=(EditCondition="EnableGhosting", ClampMin="0.01"))
	float Ghost_InterpTime = 1.0f;

	// -----------------------------------------------------------------------
	// Progress
	// -----------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicProgressBar",
		meta=(ClampMin="0.0", ClampMax="1.0"))
	float Percent = 0.5f;

	// -----------------------------------------------------------------------
	// API
	// -----------------------------------------------------------------------

	/** Immediately update the progress value and trigger ghost behaviour. */
	UFUNCTION(BlueprintCallable, Category="DynamicProgressBar")
	void SetProgress(float Percentage);

	UFUNCTION()
	void L_OnCombUpdat(UCombatantComponent* Combatant);
	/** Store a reference to the attribute this bar represents (for external logic). */
	UFUNCTION(BlueprintCallable, Category="DynamicProgressBar")
	void BindAttribute(UCombatantComponent* Combatant, UOmegaAttribute* Attribute);

	UFUNCTION(BlueprintCallable, Category="DynamicProgressBar")
	void UnbindAttribute();
	
	/** Fired every time SetProgress is called with the new clamped percent value. */
	UPROPERTY(BlueprintAssignable, Category="DynamicProgressBar")
	FOnDynamicProgressBarPercentChanged OnPercentChanged;

	virtual void SynchronizeProperties() override;
};

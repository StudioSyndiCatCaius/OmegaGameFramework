// Fill out your copyright notice in the Description page of Project Settings.

#include "Widget/WG_DynamicProgressBar.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"
#include "Components/Component_Combatant.h"

// ---------------------------------------------------------------------------
// SynchronizeProperties – called by UMG whenever a property changes in the
// editor or at BeginPlay.  Initialises both material params from the current
// Percent so the bar looks correct before any runtime SetProgress call.
// ---------------------------------------------------------------------------
void UDynamicProgressBar::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (Material)
	{
		SetBrushResourceObject(Material);
	}
	
	// Keep ghost in sync with the designer-set Percent so the first runtime
	// SetProgress starts from the correct baseline rather than 0.
	GhostPercent = Percent;

	if (UMaterialInstanceDynamic* DynMat = GetDynamicMaterial())
	{
		DynMat->SetScalarParameterValue(MatParam_ProgressPercent, Percent);
		DynMat->SetScalarParameterValue(MatParam_GhostPercent, GhostPercent);
		DynMat->SetVectorParameterValue(MatParam_ProgressColor, ProgressColor);
		DynMat->SetVectorParameterValue(MatParam_GhostColor, GhostColor);
	}
}

// ---------------------------------------------------------------------------
// SetProgress – the main runtime entry point.
// Updates the Progress param immediately; if ghosting is on it (re)starts the
// delay timer, cancelling any in-progress interp so the ghost freezes at its
// current position until the delay elapses again.
// ---------------------------------------------------------------------------
void UDynamicProgressBar::SetProgress(float Percentage)
{
	Percent = FMath::Clamp(Percentage, 0.f, 1.f);

	if (UMaterialInstanceDynamic* DynMat = GetDynamicMaterial())
	{
		DynMat->SetScalarParameterValue(MatParam_ProgressPercent, Percent);
		DynMat->SetVectorParameterValue(MatParam_ProgressColor, ProgressColor);
		DynMat->SetVectorParameterValue(MatParam_GhostColor, GhostColor);
	}

	OnPercentChanged.Broadcast(Percent);

	if (!EnableGhosting)
	{
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// Stop any running interp so the ghost holds its current position.
	World->GetTimerManager().ClearTimer(GhostInterpTimerHandle);

	// (Re)start the delay before the ghost begins chasing the new value.
	World->GetTimerManager().ClearTimer(GhostDelayTimerHandle);
	World->GetTimerManager().SetTimer(
		GhostDelayTimerHandle,
		this,
		&UDynamicProgressBar::StartGhostInterp,
		Ghost_DelayStart,
		/*bLoop=*/false);
}

void UDynamicProgressBar::L_OnCombUpdat(UCombatantComponent* Combatant)
{
	if (Combatant==BoundCombatant && BoundAttribute)
	{
		SetProgress(Combatant->GetAttributePercentage(BoundAttribute));
	}
}


// ---------------------------------------------------------------------------
// StartGhostInterp – fired by GhostDelayTimerHandle after the delay elapses.
// Kicks off a per-frame looping timer that moves GhostPercent toward Percent.
// ---------------------------------------------------------------------------
void UDynamicProgressBar::StartGhostInterp()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// Tick at ~60 Hz.  TickGhostInterp reads GetDeltaSeconds() so the actual
	// interval only affects resolution, not the interp speed.
	World->GetTimerManager().SetTimer(
		GhostInterpTimerHandle,
		this,
		&UDynamicProgressBar::TickGhostInterp,
		1.f / 60.f,
		/*bLoop=*/true);
}

// ---------------------------------------------------------------------------
// TickGhostInterp – advances GhostPercent toward Percent at a constant speed
// (1 / Ghost_InterpTime units per second) and updates the material param.
// Stops the timer once the ghost has reached the target.
// ---------------------------------------------------------------------------
void UDynamicProgressBar::TickGhostInterp()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	const float DeltaTime  = World->GetDeltaSeconds();
	const float InterpSpeed = Ghost_InterpTime > 0.f ? (1.f / Ghost_InterpTime) : 10.f;

	GhostPercent = FMath::FInterpConstantTo(GhostPercent, Percent, DeltaTime, InterpSpeed);

	if (UMaterialInstanceDynamic* DynMat = GetDynamicMaterial())
	{
		DynMat->SetScalarParameterValue(MatParam_GhostPercent, GhostPercent);
	}

	// Snap and stop once close enough.
	if (FMath::IsNearlyEqual(GhostPercent, Percent, 0.0005f))
	{
		GhostPercent = Percent;
		if (UMaterialInstanceDynamic* DynMat = GetDynamicMaterial())
		{
			DynMat->SetScalarParameterValue(MatParam_GhostPercent, GhostPercent);
		}
		World->GetTimerManager().ClearTimer(GhostInterpTimerHandle);
	}
}

UDynamicProgressBar::UDynamicProgressBar()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> RadialMatFinder(TEXT("/OmegaGameFramework/Materials/UI/M_OMEGA_ui_DynamicMater_Radial.M_OMEGA_ui_DynamicMater_Radial"));
	if (RadialMatFinder.Succeeded()) Material = RadialMatFinder.Object;
}

// ---------------------------------------------------------------------------
// BindAttribute
// ---------------------------------------------------------------------------

void UDynamicProgressBar::BindAttribute(UCombatantComponent* Combatant, UOmegaAttribute* Attribute)
{
	if (Combatant && Attribute)
	{
		BoundAttribute=Attribute;
		BoundCombatant=Combatant;
		Combatant->OnUpdated.AddDynamic(this,&UDynamicProgressBar::L_OnCombUpdat);
		L_OnCombUpdat(BoundCombatant);
	}
}

void UDynamicProgressBar::UnbindAttribute()
{
	if (BoundCombatant)
	{
		BoundCombatant->OnUpdated.RemoveDynamic(this,&UDynamicProgressBar::L_OnCombUpdat);
	}
	BoundCombatant=nullptr;
	BoundAttribute=nullptr;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSignalSubsystem.h"

void UOmegaSignalSubsystem::FireGlobalSignal(UOmegaSignalAsset* Signal)
{
	OnFireSignal.Broadcast(Signal);
}

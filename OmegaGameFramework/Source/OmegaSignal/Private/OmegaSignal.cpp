// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaSignal.h"

DEFINE_LOG_CATEGORY(OmegaSignal);

#define LOCTEXT_NAMESPACE "FOmegaSignal"

void FOmegaSignal::StartupModule()
{
	UE_LOG(OmegaSignal, Warning, TEXT("OmegaSignal module has been loaded"));
}

void FOmegaSignal::ShutdownModule()
{
	UE_LOG(OmegaSignal, Warning, TEXT("OmegaSignal module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaSignal, OmegaSignal)
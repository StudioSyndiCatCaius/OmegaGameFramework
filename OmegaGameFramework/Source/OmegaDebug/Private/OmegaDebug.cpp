// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaDebug.h"

DEFINE_LOG_CATEGORY(OmegaDebug);

#define LOCTEXT_NAMESPACE "FOmegaDebug"

void FOmegaDebug::StartupModule()
{
	UE_LOG(OmegaDebug, Warning, TEXT("OmegaDebug module has been loaded"));
}

void FOmegaDebug::ShutdownModule()
{
	UE_LOG(OmegaDebug, Warning, TEXT("OmegaDebug module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaDebug, OmegaDebug)
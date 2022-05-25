// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaFlow.h"

DEFINE_LOG_CATEGORY(OmegaFlow);

#define LOCTEXT_NAMESPACE "FOmegaFlow"

void FOmegaFlow::StartupModule()
{
	UE_LOG(OmegaFlow, Warning, TEXT("OmegaFlow module has been loaded"));
}

void FOmegaFlow::ShutdownModule()
{
	UE_LOG(OmegaFlow, Warning, TEXT("OmegaFlow module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaFlow, OmegaFlow)
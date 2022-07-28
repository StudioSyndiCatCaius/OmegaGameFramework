// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaDemo.h"

DEFINE_LOG_CATEGORY(OmegaDemo);

#define LOCTEXT_NAMESPACE "FOmegaDemo"

void FOmegaDemo::StartupModule()
{
	UE_LOG(OmegaDemo, Warning, TEXT("OmegaDemo module has been loaded"));
}

void FOmegaDemo::ShutdownModule()
{
	UE_LOG(OmegaDemo, Warning, TEXT("OmegaDemo module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaDemo, OmegaDemo)
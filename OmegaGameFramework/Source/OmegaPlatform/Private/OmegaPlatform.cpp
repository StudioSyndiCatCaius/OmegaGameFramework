// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaPlatform.h"

DEFINE_LOG_CATEGORY(OmegaPlatform);

#define LOCTEXT_NAMESPACE "FOmegaPlatform"

void FOmegaPlatform::StartupModule()
{
	UE_LOG(OmegaPlatform, Warning, TEXT("OmegaPlatform module has been loaded"));
}

void FOmegaPlatform::ShutdownModule()
{
	UE_LOG(OmegaPlatform, Warning, TEXT("OmegaPlatform module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaPlatform, OmegaPlatform)
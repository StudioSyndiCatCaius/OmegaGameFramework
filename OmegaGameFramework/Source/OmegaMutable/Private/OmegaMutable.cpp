// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaMutable.h"

DEFINE_LOG_CATEGORY(OmegaMutable);

#define LOCTEXT_NAMESPACE "FOmegaMutable"

void FOmegaMutable::StartupModule()
{
	UE_LOG(OmegaMutable, Warning, TEXT("OmegaMutable module has been loaded"));
}

void FOmegaMutable::ShutdownModule()
{
	UE_LOG(OmegaMutable, Warning, TEXT("OmegaMutable module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaMutable, OmegaMutable)
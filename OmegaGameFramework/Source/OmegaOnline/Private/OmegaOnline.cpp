// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaOnline.h"

DEFINE_LOG_CATEGORY(OmegaOnline);

#define LOCTEXT_NAMESPACE "FOmegaOnline"

void FOmegaOnline::StartupModule()
{
	UE_LOG(OmegaOnline, Warning, TEXT("OmegaOnline module has been loaded"));
}

void FOmegaOnline::ShutdownModule()
{
	UE_LOG(OmegaOnline, Warning, TEXT("OmegaOnline module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaOnline, OmegaOnline)
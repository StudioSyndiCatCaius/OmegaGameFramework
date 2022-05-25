// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaData.h"

DEFINE_LOG_CATEGORY(OmegaData);

#define LOCTEXT_NAMESPACE "FOmegaWorld"

void FOmegaWorld::StartupModule()
{
	UE_LOG(OmegaData, Warning, TEXT("OmegaData module has been loaded"));
}

void FOmegaWorld::ShutdownModule()
{
	UE_LOG(OmegaData, Warning, TEXT("OmegaData module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaWorld, OmegaData)
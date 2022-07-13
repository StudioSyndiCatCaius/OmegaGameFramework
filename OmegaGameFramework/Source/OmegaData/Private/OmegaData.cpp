// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaData.h"

DEFINE_LOG_CATEGORY(OmegaData);

#define LOCTEXT_NAMESPACE "FOmegaWorld"

void FOmegaData::StartupModule()
{
	UE_LOG(OmegaData, Warning, TEXT("OmegaData module has been loaded"));
}

void FOmegaData::ShutdownModule()
{
	UE_LOG(OmegaData, Warning, TEXT("OmegaData module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaData, OmegaData)

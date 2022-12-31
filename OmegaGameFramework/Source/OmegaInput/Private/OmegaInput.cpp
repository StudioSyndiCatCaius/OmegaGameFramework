// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaInput.h"

DEFINE_LOG_CATEGORY(OmegaInput);

#define LOCTEXT_NAMESPACE "FOmegaInput"

void FOmegaInput::StartupModule()
{
	UE_LOG(OmegaInput, Warning, TEXT("OmegaInput module has been loaded"));
}

void FOmegaInput::ShutdownModule()
{
	UE_LOG(OmegaInput, Warning, TEXT("OmegaInput module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaInput, OmegaInput)
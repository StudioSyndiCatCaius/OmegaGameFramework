// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaSequence.h"

DEFINE_LOG_CATEGORY(OmegaSequence);

#define LOCTEXT_NAMESPACE "FOmegaSequence"

void FOmegaSequence::StartupModule()
{
	UE_LOG(OmegaSequence, Warning, TEXT("OmegaSequence module has been loaded"));
}

void FOmegaSequence::ShutdownModule()
{
	UE_LOG(OmegaSequence, Warning, TEXT("OmegaSequence module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaSequence, OmegaSequence)
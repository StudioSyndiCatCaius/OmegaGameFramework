// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaAnim.h"

DEFINE_LOG_CATEGORY(OmegaAnim);

#define LOCTEXT_NAMESPACE "FOmegaWorld"

void FOmegaAnim::StartupModule()
{
	UE_LOG(OmegaAnim, Warning, TEXT("OmegaAnim module has been loaded"));
}

void FOmegaAnim::ShutdownModule()
{
	UE_LOG(OmegaAnim, Warning, TEXT("OmegaAnim module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaAnim, OmegaAnim)

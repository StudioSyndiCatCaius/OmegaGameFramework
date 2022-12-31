// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaUI.h"

DEFINE_LOG_CATEGORY(OmegaUI);

#define LOCTEXT_NAMESPACE "FOmegaUI"

void FOmegaUI::StartupModule()
{
	UE_LOG(OmegaUI, Warning, TEXT("OmegaUI module has been loaded"));
}

void FOmegaUI::ShutdownModule()
{
	UE_LOG(OmegaUI, Warning, TEXT("OmegaUI module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaUI, OmegaUI)
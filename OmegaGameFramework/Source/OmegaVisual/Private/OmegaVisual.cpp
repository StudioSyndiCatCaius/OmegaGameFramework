#include "OmegaVisual.h"

DEFINE_LOG_CATEGORY(OmegaVisual);

#define LOCTEXT_NAMESPACE "FOmegaVisual"

void FOmegaVisual::StartupModule()
{
	UE_LOG(OmegaVisual, Warning, TEXT("OmegaVisual module has been loaded"));
}

void FOmegaVisual::ShutdownModule()
{
	UE_LOG(OmegaVisual, Warning, TEXT("OmegaVisual module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaVisual, OmegaVisual)
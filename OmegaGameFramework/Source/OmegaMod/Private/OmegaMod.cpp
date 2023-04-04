#include "OmegaMod.h"

DEFINE_LOG_CATEGORY(OmegaMod);

#define LOCTEXT_NAMESPACE "FOmegaMod"

void FOmegaMod::StartupModule()
{
	UE_LOG(OmegaMod, Warning, TEXT("OmegaMod module has been loaded"));
}

void FOmegaMod::ShutdownModule()
{
	UE_LOG(OmegaMod, Warning, TEXT("OmegaMod module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaMod, OmegaMod)
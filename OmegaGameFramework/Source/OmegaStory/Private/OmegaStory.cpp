#include "OmegaStory.h"

DEFINE_LOG_CATEGORY(OmegaStory);

#define LOCTEXT_NAMESPACE "FOmegaStory"

void FOmegaStory::StartupModule()
{
	UE_LOG(OmegaStory, Warning, TEXT("OmegaStory module has been loaded"));
}

void FOmegaStory::ShutdownModule()
{
	UE_LOG(OmegaStory, Warning, TEXT("OmegaStory module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaStory, OmegaStory)
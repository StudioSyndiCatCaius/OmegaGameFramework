// Copyright Studio SyndiCat 2021. All Rights Reserved.

#include "OmegaGameFramework.h"


DEFINE_LOG_CATEGORY(OmegaGameFramework);

#define LOCTEXT_NAMESPACE "FOmegaGameFrameworkModule"

void FOmegaGameFrameworkModule::StartupModule()
{
	// Create and register the custom platform file

    
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    

}

void FOmegaGameFrameworkModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOmegaGameFrameworkModule, OmegaGameFramework)

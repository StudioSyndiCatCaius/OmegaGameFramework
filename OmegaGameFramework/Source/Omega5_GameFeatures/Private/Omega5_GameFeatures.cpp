// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Omega5_GameFeatures.h"

DEFINE_LOG_CATEGORY(Omega5_GameFeatures);

#define LOCTEXT_NAMESPACE "FOmega5_GameFeatures"

void FOmega5_GameFeatures::StartupModule()
{
	UE_LOG(Omega5_GameFeatures, Warning, TEXT("Omega5_GameFeatures module has been loaded"));
}

void FOmega5_GameFeatures::ShutdownModule()
{
	UE_LOG(Omega5_GameFeatures, Warning, TEXT("Omega5_GameFeatures module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmega5_GameFeatures, Omega5_GameFeatures)
// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaParser.h"

DEFINE_LOG_CATEGORY(OmegaParser);

#define LOCTEXT_NAMESPACE "FOmegaParser"

void FOmegaParser::StartupModule()
{
	UE_LOG(OmegaParser, Warning, TEXT("OmegaParser module has been loaded"));
}

void FOmegaParser::ShutdownModule()
{
	UE_LOG(OmegaParser, Warning, TEXT("OmegaParser module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaParser, OmegaParser)
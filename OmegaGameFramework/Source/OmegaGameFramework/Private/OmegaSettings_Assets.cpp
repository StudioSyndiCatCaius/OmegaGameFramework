// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Assets.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Engine.h"


UOmegaAssetSettings::UOmegaAssetSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Quickload_ContentDirectories.Add("/Game/0_Main/");
	Quickload_ContentDirectories.Add("/OmegaGameFramework/");
	Quickload_ContentDirectories.Add("/OmegaGameAssets/");
	
	Quickload_ClassDirectories.Add("/Assets/");
	Quickload_ClassDirectories.Add("/Data/");
	
	Quickload_ClassNameRemap.Add(TSoftClassPtr<UTexture2D>(),"Textures");
	Quickload_ClassNameRemap.Add(TSoftClassPtr<UMaterialInterface>(),"Materials");
}

void UOmegaAssetSettings::LoadDevConfig()
{
	GEngine->GetEngineSubsystem<UOmegaSubsystem_Engine>()->LoadDevConfig();
}

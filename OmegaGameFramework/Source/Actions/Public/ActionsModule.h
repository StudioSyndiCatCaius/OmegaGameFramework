// Copyright 2015-2020 Piperift. All Rights Reserved.
#pragma once

#include <Modules/ModuleInterface.h>
#include <Modules/ModuleManager.h>

#if WITH_EDITOR
#include "Developer/AssetTools/Public/IAssetTools.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"
#endif //WITH_EDITOR

DECLARE_LOG_CATEGORY_EXTERN(LogActions, All, All);


class FActionsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool SupportsDynamicReloading() override { return true; }

#if WITH_EDITOR
	EAssetTypeCategories::Type GetAssetCategoryBit() const
	{
		return EAssetTypeCategories::Misc;
	}
#endif


	FORCEINLINE static FActionsModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FActionsModule>("Actions");
	}
};

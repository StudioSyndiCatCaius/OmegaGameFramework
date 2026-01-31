// Copyright Studio Syndicat 2021. All Rights Reserved.
#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(OmegaWorld, All, All);

class FOmegaWorld : public IModuleInterface
{
	public:
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
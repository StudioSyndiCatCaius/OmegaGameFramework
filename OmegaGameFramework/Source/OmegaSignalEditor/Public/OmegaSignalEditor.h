// Copyright Studio Syndicat 2021. All Rights Reserved.
#pragma once

#include "TickableEditorObject.h"
#include "Modules/ModuleManager.h"


class FOmegaSignalEditor : public IModuleInterface, public FTickableEditorObject
{
	public:

	/* Called when the module is loaded */
	virtual void StartupModule() override;

	/* Called when the module is unloaded */
	virtual void ShutdownModule() override;

	// FTickableEditorObject interface
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FOmegaSignalEditor, STATGROUP_Tickables); }
	// End FTickableEditorObject interface
};
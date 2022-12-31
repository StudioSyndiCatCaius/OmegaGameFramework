// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaSignalEditor.h"

#define LOCTEXT_NAMESPACE "FOmegaSignalEditor"

void FOmegaSignalEditor::StartupModule()
{
	
}

void FOmegaSignalEditor::ShutdownModule()
{
	
}

void FOmegaSignalEditor::Tick(float DeltaTime)
{
	/*
	// Update any blueprints that are referencing an input action with a modified value type
	if (UInputAction::ActionsWithModifiedValueTypes.Num())
	{
		TSet<UBlueprint*> BPsModified;
		for (TObjectIterator<UK2Node_EnhancedInputAction> NodeIt; NodeIt; ++NodeIt)
		{
			if (UInputAction::ActionsWithModifiedValueTypes.Contains(NodeIt->InputAction))
			{
				NodeIt->ReconstructNode();
				BPsModified.Emplace(NodeIt->GetBlueprint());
			}
		}
		for (TObjectIterator<UK2Node_GetInputActionValue> NodeIt; NodeIt; ++NodeIt)
		{
			if (UInputAction::ActionsWithModifiedValueTypes.Contains(NodeIt->InputAction))
			{
				NodeIt->ReconstructNode();
				BPsModified.Emplace(NodeIt->GetBlueprint());
			}
		}

		if (BPsModified.Num())
		{
			FNotificationInfo Info(FText::Format(LOCTEXT("ActionValueTypeChange", "Changing action value type affected {0} blueprint(s)!"), BPsModified.Num()));
			Info.ExpireDuration = 5.0f;
			FSlateNotificationManager::Get().AddNotification(Info);
		}

		UInputAction::ActionsWithModifiedValueTypes.Reset();
	}
	*/
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaSignalEditor, OmegaSignalEditor)
// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "ActorPreset/ActorPreset_TypeActions.h"
#include "ActorPreset/ActorPreset_EditorToolkit.h"
#include "Interfaces/I_ActorPreset.h"
#include "Misc/GeneralDataObject.h"   // UOmegaMinimalDataAsset
#include "Engine/DataAsset.h"

FText FActorPresetTypeActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "ActorPreset", "Actor Preset");
}

UClass* FActorPresetTypeActions::GetSupportedClass() const
{
	return UOmegaMinimalDataAsset::StaticClass();
}

void FActorPresetTypeActions::OpenAssetEditor(
	const TArray<UObject*>&  InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	// Split objects: those implementing the interface get the custom toolkit;
	// the rest fall through to the default editor.
	TArray<UObject*> PresetAssets;
	TArray<UObject*> OtherAssets;

	for (UObject* Obj : InObjects)
	{
		if (Obj && Obj->Implements<UDataInterface_ActorPreset>())
		{
			PresetAssets.Add(Obj);
		}
		else
		{
			OtherAssets.Add(Obj);
		}
	}

	// Open custom toolkit for preset assets
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
		? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (UObject* Obj : PresetAssets)
	{
		if (UPrimaryDataAsset* Asset = Cast<UPrimaryDataAsset>(Obj))
		{
			TSharedRef<FActorPresetEditorToolkit> Toolkit = MakeShared<FActorPresetEditorToolkit>();
			Toolkit->InitActorPresetEditor(Mode, EditWithinLevelEditor, Asset);
		}
	}

	// Fall back to default details editor for non-preset assets
	if (OtherAssets.Num() > 0)
	{
		FAssetTypeActions_Base::OpenAssetEditor(OtherAssets, EditWithinLevelEditor);
	}
}

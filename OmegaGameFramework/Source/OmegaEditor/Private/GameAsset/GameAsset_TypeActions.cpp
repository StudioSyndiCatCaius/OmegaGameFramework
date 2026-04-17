
#include "GameAsset/GameAsset_TypeActions.h"
#include "GameAsset/GameAsset_EditorToolkit.h"
#include "OmegaGameAsset.h"

FText FGameplayAssetTypeActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "GameplayAsset", "Gameplay Asset");
}

UClass* FGameplayAssetTypeActions::GetSupportedClass() const
{
	return UOmegaGameAsset::StaticClass();
}

uint32 FGameplayAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Gameplay;
}

void FGameplayAssetTypeActions::OpenAssetEditor(
	const TArray<UObject*>&      InObjects,
	TSharedPtr<IToolkitHost>     EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
		? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (UObject* Obj : InObjects)
	{
		if (UOmegaGameAsset* Asset = Cast<UOmegaGameAsset>(Obj))
		{
			TSharedRef<FGameplayAssetEditorToolkit> Toolkit =
				MakeShared<FGameplayAssetEditorToolkit>();
			Toolkit->InitGameplayAssetEditor(Mode, EditWithinLevelEditor, Asset);
		}
	}
}

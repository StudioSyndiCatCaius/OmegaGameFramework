// Copyright Studio SyndiCat 2021. All Rights Reserved.

#include "OmegaEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
#include "Styling/SlateStyleRegistry.h"

#include "Editor/PlacementMode/Public/IPlacementModeModule.h"
#include "Interfaces/IPluginManager.h"
#include "Runtime/Launch/Resources/Version.h"

#include "OmegaCharacter.h"

#include "AssetTypeActions_Base.h"
#include "IAssetTools.h"
#include "OmegaAbility.h"
#include "OmegaGameplayEffect.h"

#include "OmegaGameplaySystem.h"

#include "Widget/DataWidget.h"
#include "Widget/Menu.h"
#include "Widget/HUDLayer.h"

#define LOCTEXT_NAMESPACE "FOmegaEditor"

void FOmegaEditor::StartupModule()
{
	//------REGISTER DEFAULT EVENTS-----////

	//Gameplay Systems
	RegisterDefaultEvent(AOmegaGameplaySystem, SystemActivated);
	RegisterDefaultEvent(AOmegaGameplaySystem, SystemShutdown);

	//Abilities
	RegisterDefaultEvent(AOmegaAbility, AbilityActivated);
	RegisterDefaultEvent(AOmegaAbility, AbilityFinished);
	RegisterDefaultEvent(AOmegaAbility, ActivatedTick);
	RegisterDefaultEvent(AOmegaAbility, OnCombatantNotify);

	//Effects
	RegisterDefaultEvent(AOmegaGameplayEffect, EffectBeginPlay);
	RegisterDefaultEvent(AOmegaGameplayEffect, EffectApplied);

	//Menus
	RegisterDefaultEvent(UMenu, MenuOpened);
	RegisterDefaultEvent(UMenu, MenuClosed);

	//HUD
	RegisterDefaultEvent(UHUDLayer, LayerAdded);
	
	//DataWidget
	RegisterDefaultEvent(UDataWidget, AddedToDataList);
	RegisterDefaultEvent(UDataWidget, OnSourceAssetChanged);
	RegisterDefaultEvent(UDataWidget, OnNewListOwner);
	
	// ------- SETUP CATEGORY FACTORY ------- /////

	IAssetTools &AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	OmegaAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Omega")),LOCTEXT("OmegaCategory","Omega"));

	// --- Attribute
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaAttributes(OmegaAssetCategory)));
	
	// --- DataItem
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaDataItems(OmegaAssetCategory)));
	
	// --- Ability
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaAbility(OmegaAssetCategory)));

	// --- AttributeSet
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaAttributeSet(OmegaAssetCategory)));

	// --- GameplaySystem
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaGameplaySystem(OmegaAssetCategory)));
	
	// --- GameplayModule
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaGameplayModule(OmegaAssetCategory)));
	
	// --- Game Save
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaGameSave(OmegaAssetCategory)));

	// --- Global Save
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaGlobalSave(OmegaAssetCategory)));
	
	// --- Menu
	//AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaMenu(OmegaAssetCategory)));

	// --- HUD Layer
	//AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_HudLayer(OmegaAssetCategory)));

	///////////////////////////////////////////////////////
	//------SETUP ASSET THUMBNAILS-----//// 
	StyleSet = MakeShareable(new FSlateStyleSet("OmegaStyle"));
	FString ContentDir = IPluginManager::Get().FindPlugin("OmegaGameFramework")->GetBaseDir(); 	//Content path of this plugin
	StyleSet->SetContentRoot(ContentDir);
	
	//--------CREATE ASSET BRUSH ICONS-----------//

	// Add Basic Thumbnail Location List
	TArray<FString> ThumnbailNames;
	ThumnbailNames.Add(TEXT("OmegaComponent"));
	ThumnbailNames.Add(TEXT("OmegaAbility"));
	ThumnbailNames.Add(TEXT("OmegaGameplaySystem"));
	ThumnbailNames.Add(TEXT("OmegaGameplayModule"));
	ThumnbailNames.Add(TEXT("OmegaAttribute"));
	ThumnbailNames.Add(TEXT("OmegaAttributeSet"));
	ThumnbailNames.Add(TEXT("OmegaGameplayEffect"));
	ThumnbailNames.Add(TEXT("OmegaGameSettings"));
	ThumnbailNames.Add(TEXT("OmegaSaveGame"));
	ThumnbailNames.Add(TEXT("OmegaSaveGlobal"));
	ThumnbailNames.Add(TEXT("CombatantComponent"));
	ThumnbailNames.Add(TEXT("InputReceiverComponent"));

	ThumnbailNames.Add(TEXT("GamePreferenceFloat"));
	ThumnbailNames.Add(TEXT("GamePreferenceBool"));
	ThumnbailNames.Add(TEXT("GamePreferenceString"));
	ThumnbailNames.Add(TEXT("GamePreferenceTag"));

	ThumnbailNames.Add(TEXT("Menu"));
	ThumnbailNames.Add(TEXT("HUDLayer"));
	ThumnbailNames.Add(TEXT("DataWidget"));
	ThumnbailNames.Add(TEXT("Action"));
	ThumnbailNames.Add(TEXT("OmegaLevelingAsset"));
	ThumnbailNames.Add(TEXT("LevelingComponent"));
	ThumnbailNames.Add(TEXT("EquipmentComponent"));
	ThumnbailNames.Add(TEXT("EquipmentSlot"));
	
	ThumnbailNames.Add(TEXT("DataAssetCollectionComponent"));
	ThumnbailNames.Add(TEXT("CombatantExtensionComponent"));
	ThumnbailNames.Add(TEXT("CombatantGroupComponent"));
	ThumnbailNames.Add(TEXT("OmegaLinearEvent"));
	ThumnbailNames.Add(TEXT("TurnBasedManagerComponent"));
	
	ThumnbailNames.Add(TEXT("OmegaDataItem"));
	ThumnbailNames.Add(TEXT("OmegaDataTrait"));
	ThumnbailNames.Add(TEXT("OmegaDataTraitCollection"));
	ThumnbailNames.Add(TEXT("DataItemComponent"));
	
	ThumnbailNames.Add(TEXT("FlowComponent"));
	ThumnbailNames.Add(TEXT("FlowNode"));
	ThumnbailNames.Add(TEXT("OmegaGameplayMessage"));
	
	ThumnbailNames.Add(TEXT("InstanceActorComponent"));
	ThumnbailNames.Add(TEXT("OmegaInstanceActor"));

	ThumnbailNames.Add(TEXT("OmegaFaction"));
	ThumnbailNames.Add(TEXT("CombatantGambitAsset"));
	ThumnbailNames.Add(TEXT("CombatantGambitCondition"));
	ThumnbailNames.Add(TEXT("CombatantGambitAction"));
	ThumnbailNames.Add(TEXT("OmegaInputMode"));
	ThumnbailNames.Add(TEXT("OmegaBGM"));
	ThumnbailNames.Add(TEXT("OmegaDamageType"));
	ThumnbailNames.Add(TEXT("DynamicCameraState"));
	
	ThumnbailNames.Add(TEXT("OmegaZoneData"));
	ThumnbailNames.Add(TEXT("OmegaLevelData"));
	
	FSlateImageBrush* ThumbnailTemp;
	FSlateImageBrush* IconTemp;

	FString ThumbanilPrefex;
	FString IconPrefex;

	FString DirecPrefex;
	FName IcoName;


	TMap<FString, FSlateImageBrush*> AssetImages;

	for (FString TempString : ThumnbailNames)
	{
		ThumbanilPrefex = "ClassThumbnail.";
		ThumbanilPrefex.Append(TempString);

		IconPrefex = "ClassIcon.";
		IconPrefex.Append(TempString);

		//Get Image Directory
		DirecPrefex = "Resources/Icons/";
		DirecPrefex.Append(TempString);

		//Create and set Thumbnail
		ThumbnailTemp = new FSlateImageBrush(StyleSet->RootToContentDir(DirecPrefex, TEXT(".png")), FVector2D(128.f, 128.f));
		ThumbnailTemp->TintColor = FSlateColor(FLinearColor(1,1,1,1));		//Tint Icon Color
		IcoName = FName(*ThumbanilPrefex);
		StyleSet->Set(IcoName, ThumbnailTemp);

		DirecPrefex.Append("_16");
		//Create and set Icon
		IconTemp = new FSlateImageBrush(StyleSet->RootToContentDir(DirecPrefex, TEXT(".png")), FVector2D(16, 16.f));
		IconTemp->TintColor = FSlateColor(FLinearColor(0,0.65,1,1));		//Tint Icon Color
		IcoName = FName(*IconPrefex);
		StyleSet->Set(IcoName, IconTemp);
	};
	
	//Reguster the created style
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
	//_______________________

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Register editor category
	int Priority = 42;
	FPlacementCategoryInfo OmegaGameFramework( LOCTEXT("OmegaGameFramework", "Omega Game Framework"), "OmegaGameFramework", TEXT("PMOmegaGameFramework"), Priority);
	IPlacementModeModule::Get().RegisterPlacementCategory(OmegaGameFramework);
	
	// Find and register actors to category
	UBlueprint* OmegaCharacter = Cast<UBlueprint>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/OmegaDemoCharacter.OmegaDemoCharacter")).TryLoad());
	if (OmegaCharacter) {
		IPlacementModeModule::Get().RegisterPlaceableItem(OmegaGameFramework.UniqueHandle, MakeShareable(new FPlaceableItem(
			*UActorFactory::StaticClass(),
			FAssetData(OmegaCharacter, true),
			FName("OmegaCharacter.Thumbnail"),
#if ENGINE_MAJOR_VERSION == 5
			FName("OmegaCharacter.Icon"),
#endif
			TOptional<FLinearColor>(),
			TOptional<int32>(),
			NSLOCTEXT("PlacementMode", "OmegaCharacter", "OmegaCharacter")
		)));
	}
	
	
}

void FOmegaEditor::ShutdownModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaEditor, OmegaEditor)


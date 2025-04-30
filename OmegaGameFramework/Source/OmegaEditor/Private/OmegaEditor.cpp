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
#include "OmegaEffectFactory.h"
#include "Actors/Actor_Environment.h"
#include "Actor_EventVolume.h"
#include "Actors/Actor_Ability.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Actors/OmegaGameplaySystem.h"

#include "Widget/DataWidget.h"
#include "Widget/Menu.h"
#include "Widget/HUDLayer.h"

#define LOCTEXT_NAMESPACE "FOmegaEditor"

#define OMACRO_REGISTERASSETTYPE(AssetName, CategoryName) \
AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_##AssetName(CategoryName))); \

#define OMACRO_ADDPLACEABLE(AssetName,DisplayName) \
if (UClass* AssetName##Class = A##AssetName::StaticClass()) { \
		IPlacementModeModule::Get().RegisterPlaceableItem(OmegaGameFramework.UniqueHandle, MakeShareable(new FPlaceableItem( \
			*UActorFactory::StaticClass(), \
			FAssetData(AssetName##Class), \
			FName("A"#AssetName".Thumbnail"), \
			FName("A"#AssetName".Icon"), \
			TOptional<FLinearColor>(), TOptional<int32>(), NSLOCTEXT("PlacementMode", DisplayName, DisplayName) \
		))); \
	} \




void FOmegaEditor::StartupModule()
{
	UThumbnailManager::Get().RegisterCustomRenderer(UOmegaDataItem::StaticClass(), UDataItemThumbnailRender::StaticClass());
	UThumbnailManager::Get().RegisterCustomRenderer(UOmegaDataAsset::StaticClass(), UDataItemThumbnailRender::StaticClass());
	//------REGISTER DEFAULT EVENTS-----////

	RegisterDefaultEvent(AOmegaGameplaySystem, SystemActivated);
	RegisterDefaultEvent(AOmegaGameplaySystem, SystemShutdown);
	RegisterDefaultEvent(AOmegaAbility, AbilityActivated);
	RegisterDefaultEvent(AOmegaAbility, AbilityFinished);
	RegisterDefaultEvent(AOmegaAbility, ActivatedTick);
	RegisterDefaultEvent(AOmegaAbility, OnCombatantNotify);
	RegisterDefaultEvent(AOmegaGameplayEffect, EffectBeginPlay);
	RegisterDefaultEvent(AOmegaGameplayEffect, EffectApplied);
	RegisterDefaultEvent(UMenu, MenuOpened);
	RegisterDefaultEvent(UMenu, MenuClosed);
	RegisterDefaultEvent(UHUDLayer, LayerAdded);
	RegisterDefaultEvent(UDataWidget, AddedToDataList);
	RegisterDefaultEvent(UDataWidget, OnSourceAssetChanged);
	RegisterDefaultEvent(UDataWidget, OnNewListOwner);
	
	// ------- SETUP CATEGORY FACTORY ------- /////

	IAssetTools &AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		OmegaAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Omega")),LOCTEXT("OmegaCategory","_Omega"));
	
	// --- Attribute
	OMACRO_REGISTERASSETTYPE(OmegaAttribute,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaFaction,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaBGM,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaDamageType,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaCommonSkill,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(SubscriptCollection,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaLevelData,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaZoneData,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(ZoneLegendAsset,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(CombatantGambitAsset,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaQuest,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaAnimationEmote,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaStoryStateAsset,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaLevelingAsset,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaActorConfig,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaCharacterConfig,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaDataItems,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaGameplaySystem,OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaAbility, OmegaAssetCategory);
	OMACRO_REGISTERASSETTYPE(OmegaGameplayModule,OmegaAssetCategory);

	//OMACRO_REGISTERASSETTYPE(OmegaGameSave,	OmegaAssetCategory_Gameplay);
	//OMACRO_REGISTERASSETTYPE(OmegaGlobalSave,OmegaAssetCategory_Gameplay);

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
	ThumnbailNames.Add(TEXT("GameplayPauseComponent"));
	ThumnbailNames.Add(TEXT("SkinComponent"));
	ThumnbailNames.Add(TEXT("ActorStateComponent"));
	ThumnbailNames.Add(TEXT("OmegaSaveStateComponent"));
	ThumnbailNames.Add(TEXT("ActorIdentityComponent"));
	ThumnbailNames.Add(TEXT("AimTargetComponent"));
	
	ThumnbailNames.Add(TEXT("OmegaSkin"));
	ThumnbailNames.Add(TEXT("OmegaDataItem"));
	ThumnbailNames.Add(TEXT("OmegaDataTrait"));
	ThumnbailNames.Add(TEXT("OmegaDataTraitCollection"));
	ThumnbailNames.Add(TEXT("DataItemComponent"));
	
	ThumnbailNames.Add(TEXT("FlowComponent"));
	ThumnbailNames.Add(TEXT("FlowNode"));
	ThumnbailNames.Add(TEXT("OmegaGameplayMessage"));
	
	ThumnbailNames.Add(TEXT("InstanceActorComponent"));
	ThumnbailNames.Add(TEXT("OmegaInstanceActor"));
	ThumnbailNames.Add(TEXT("OmegaObjectSorterAsset"));
	
	ThumnbailNames.Add(TEXT("OmegaAnimationEmote"));
	ThumnbailNames.Add(TEXT("OmegaAnimationEmoteScript"));
	
	ThumnbailNames.Add(TEXT("OmegaFaction"));
	ThumnbailNames.Add(TEXT("OmegaCommonSkill"));
	ThumnbailNames.Add(TEXT("CombatantGambitAsset"));
	ThumnbailNames.Add(TEXT("CombatantGambitTarget"));
	ThumnbailNames.Add(TEXT("CombatantGambitCondition"));
	ThumnbailNames.Add(TEXT("CombatantGambitAction"));
	ThumnbailNames.Add(TEXT("OmegaInputMode"));
	ThumnbailNames.Add(TEXT("OmegaBGM"));
	ThumnbailNames.Add(TEXT("OmegaQuest"));
	ThumnbailNames.Add(TEXT("OmegaDamageType"));
	ThumnbailNames.Add(TEXT("DynamicCameraState"));
	ThumnbailNames.Add(TEXT("OmegaActorEnvironment"));
	ThumnbailNames.Add(TEXT("OmegaEnvironmentPreset"));
	ThumnbailNames.Add(TEXT("SubscriptComponent"));
	ThumnbailNames.Add(TEXT("SubscriptCollection"));
	ThumnbailNames.Add(TEXT("Subscript"));
	
	ThumnbailNames.Add(TEXT("OmegaZoneData"));
	ThumnbailNames.Add(TEXT("OmegaLevelData"));
	ThumnbailNames.Add(TEXT("OmegaScriptedEffect"));
	ThumnbailNames.Add(TEXT("OmegaScriptedEffectAsset"));
	ThumnbailNames.Add(TEXT("OmegaPlatformAsset"));
	ThumnbailNames.Add(TEXT("OmegaAchievement"));
	ThumnbailNames.Add(TEXT("OmegaStoryStateAsset"));
	ThumnbailNames.Add(TEXT("GamePreference"));
	ThumnbailNames.Add(TEXT("OmegaSettings_Gameplay"));
	ThumnbailNames.Add(TEXT("OmegaSettings_Slate"));
	ThumnbailNames.Add(TEXT("OmegaGameplayMetaSettings"));
	
	ThumnbailNames.Add(TEXT("GamePreferenceScript"));
	ThumnbailNames.Add(TEXT("OmegaGameplayMetaSetting"));
	ThumnbailNames.Add(TEXT("OmegaScriptedEffect"));
	ThumnbailNames.Add(TEXT("OmegaDynamicCamera"));
	ThumnbailNames.Add(TEXT("OmegaGameplayCue"));
	ThumnbailNames.Add(TEXT("OmegaGameplayCue"));
	ThumnbailNames.Add(TEXT("DataListFormat"));
	ThumnbailNames.Add(TEXT("OmegaZoneTransit"));
	ThumnbailNames.Add(TEXT("OmegaZonePoint"));
	ThumnbailNames.Add(TEXT("ZoneEntityComponent"));
	ThumnbailNames.Add(TEXT("ZoneEntityDisplayActor"));
	ThumnbailNames.Add(TEXT("ZoneLegendAsset"));
	
	ThumnbailNames.Add(TEXT("OmegaCombatEncounter_Instance"));
	ThumnbailNames.Add(TEXT("OmegaCombatEncounter_Stage"));
	ThumnbailNames.Add(TEXT("OmegaCombatEncounter_Component"));
	
	ThumnbailNames.Add(TEXT("OmegaBodyType"));
	ThumnbailNames.Add(TEXT("OmegaBodySlot"));
	ThumnbailNames.Add(TEXT("OmegaBodyPreset"));
	
	ThumnbailNames.Add(TEXT("OmegaDebugProfile"));
	
	ThumnbailNames.Add(TEXT("OmegaActorConfig"));
	ThumnbailNames.Add(TEXT("OmegaCharacterConfig"));
	
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
		
		FLinearColor icon_color=FLinearColor(0,0.65,1,1);
		
		DirecPrefex.Append("_16");
		//Create and set Icon
		IconTemp = new FSlateImageBrush(StyleSet->RootToContentDir(DirecPrefex, TEXT(".png")), FVector2D(16, 16.f));
		if(TempString=="OmegaComponent")
		{
			icon_color=FLinearColor(0.2,1.0,0.4,1);
		}
		else if(TempString=="CombatantExtensionComponent")
		{
			icon_color=FLinearColor(1,0.1,0.1,1);
		}
		IconTemp->TintColor = FSlateColor(icon_color);		//Tint Icon Color
		
		IcoName = FName(*IconPrefex);
		StyleSet->Set(IcoName, IconTemp);
	};
	
	//Reguster the created style
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);

	// Register editor category
	int Priority = 42;
	FPlacementCategoryInfo OmegaGameFramework( LOCTEXT("OmegaGameFramework", "Omega Game Framework"), "OmegaGameFramework", TEXT("PMOmegaGameFramework"), Priority);
	IPlacementModeModule::Get().RegisterPlacementCategory(OmegaGameFramework);
	
	// Find and register actors to category
	UBlueprint* OmegaCharacter = Cast<UBlueprint>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/OmegaDemoCharacter.OmegaDemoCharacter")).TryLoad());
	if (OmegaCharacter) {
		IPlacementModeModule::Get().RegisterPlaceableItem(OmegaGameFramework.UniqueHandle, MakeShareable(new FPlaceableItem(
			*UActorFactory::StaticClass(), FAssetData(OmegaCharacter, true),FName("OmegaCharacter.Thumbnail"),
#if ENGINE_MAJOR_VERSION == 5
			FName("OmegaCharacter.Icon"),
#endif
			TOptional<FLinearColor>(), TOptional<int32>(), NSLOCTEXT("PlacementMode", "Character", "Character")
		))); }
	
	OMACRO_ADDPLACEABLE(OmegaActorEnvironment,"Environment")
	OMACRO_ADDPLACEABLE(Omega_EventVolume,"Event Volume")
	OMACRO_ADDPLACEABLE(OmegaZonePoint,"Zone: Spawn Point")
	OMACRO_ADDPLACEABLE(OmegaZoneTransit,"Zone: Transit Point")


	
	
}

void FOmegaEditor::ShutdownModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());
	if (UObjectInitialized())
	{
		UThumbnailManager::Get().UnregisterCustomRenderer(UOmegaDataItem::StaticClass());
	}
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaEditor, OmegaEditor)


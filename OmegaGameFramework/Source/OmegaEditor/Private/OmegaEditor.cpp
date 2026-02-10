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
#include "Customization_ActorRelatives.h"
#include "Customization_ClassNamedLists.h"
#include "Customization_CustomNamedList.h"
#include "Customization_OmegaLinearChoices.h"
#include "Customization_Bitflags.h"
#include "OmegaObjectCustomization.h"
#include "Customization_Object.h"
#include "OmegaActorDetailsCustomization.h"
#include "OmegaSettings.h"
#include "OmegaGameCore.h"
#include "Actors/Actor_Ability.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Actors/Actor_Interactable.h"
#include "Actors/Actor_Spline.h"
#include "Actors/OmegaGameplaySystem.h"

#include "DataAssets/DA_CommonSkill.h"
#include "DataAssets/DA_CommonCharacter.h"
#include "DataAssets/DA_CommonItem.h"
#include "DataAssets/DA_CommonEquipment.h"
#include "DataAssets/DA_Common_EquipType.h"
#include "DataAssets/DA_CommonRace.h"
#include "DataAssets/DA_Job.h"
#include "Types/Struct_ActorRelatives.h"

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



FString FOmegaEditor::GetPluginFilePath(const FString& RelativePath)
{
	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("OmegaPlugin"));
    
	if (Plugin.IsValid())
	{
		FString PluginBaseDir = Plugin->GetBaseDir();
		return FPaths::Combine(PluginBaseDir, RelativePath);
	}
    
	return FString();
}

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
	AssetCategory_Omega = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Omega")),LOCTEXT("OmegaCategory","_Omega"));
	AssetCategory_OmegaDemo = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("OmegaDemo")),LOCTEXT("OmegaDemo","_OmegaDemo"));
	
	// --- Attribute
	OMACRO_REGISTERASSETTYPE(OmegaGameplaySystem,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaAbility, AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaGameplayModule,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(HudLayer,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaMenu,AssetCategory_Omega);
//	OMACRO_REGISTERASSETTYPE(OmegaGameSave,	OmegaAssetCategory);
//	OMACRO_REGISTERASSETTYPE(OmegaGlobalSave,OmegaAssetCategory);
	
	OMACRO_REGISTERASSETTYPE(OmegaAttribute,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaFaction,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaBGM,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaDamageType,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(SubscriptCollection,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaLevelData,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaZoneData,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(ZoneLegendAsset,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(CombatantGambitAsset,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaQuest,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaAnimationEmote,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaStoryStateAsset,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaLevelingAsset,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaActorConfig,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaCharacterConfig,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaAssetLibrary_Animation,AssetCategory_Omega);
	OMACRO_REGISTERASSETTYPE(OmegaAssetLibrary_Sound,AssetCategory_Omega);
	//OMACRO_REGISTERASSETTYPE(OmegaDataItems,OmegaAssetCategory);
	
	OMACRO_REGISTERASSETTYPE(OAsset_CommonCharacter,AssetCategory_OmegaDemo);
	OMACRO_REGISTERASSETTYPE(OAsset_CommonSkill,AssetCategory_OmegaDemo);
	OMACRO_REGISTERASSETTYPE(OAsset_CommonItem,AssetCategory_OmegaDemo);
	OMACRO_REGISTERASSETTYPE(OAsset_CommonInteractable,AssetCategory_OmegaDemo);
	OMACRO_REGISTERASSETTYPE(OAsset_CommonEquipment,AssetCategory_OmegaDemo);
	OMACRO_REGISTERASSETTYPE(OAsset_Common_EquipType,AssetCategory_OmegaDemo);
	OMACRO_REGISTERASSETTYPE(OAsset_CommonRace,AssetCategory_OmegaDemo);


	///////////////////////////////////////////////////////
	//------SETUP ASSET THUMBNAILS-----//// 
	StyleSet = MakeShareable(new FSlateStyleSet("OmegaStyle"));
	FString ContentDir = IPluginManager::Get().FindPlugin("OmegaGameFramework")->GetBaseDir(); 	//Content path of this plugin
	StyleSet->SetContentRoot(ContentDir);

	FString ConfigFilePath = ContentDir+"/Config/OmegaEditor.ini";
	
	UE_LOG(LogTemp, Log, TEXT("attempting load config file: %s"), *ConfigFilePath);
	ConfigFile.Read(ConfigFilePath);
	const FConfigSection* ThumbnailSection = ConfigFile.FindSection(TEXT("thumbnails"));
	TMap<FString, int32> ThumbnailConfig;
	UE_LOG(LogTemp, Log, TEXT("attempting load config section: thumbnails"));
	if (ThumbnailSection)
	{
		// Iterate over all entries in the thumbnails section
		for (const auto& ConfigPair : *ThumbnailSection)
		{
			FString Key = ConfigPair.Key.ToString();
			FString ValueString = ConfigPair.Value.GetValue();
        
			// Convert string value to int
			int32 Value = FCString::Atoi(*ValueString);
        
			// Add to our map
			ThumbnailConfig.Add(Key, Value);
        
			UE_LOG(LogTemp, Log, TEXT("Loaded thumbnail config: %s = %d"), *Key, Value);
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Failed to load thumbnails section"));
	}
	TArray<FString> ThumnbailNames;
	ThumbnailConfig.GetKeys(ThumnbailNames);
	
	TArray<FLinearColor> ThumbColors;
	ThumbColors.Add({1,1,1,1}); // white
	ThumbColors.Add({0.2,0.2,1}); // red
	ThumbColors.Add({0.2,1,0.7,1}); // green
	ThumbColors.Add({0.1,0.4,1,1}); // blue
	
		
	FSlateImageBrush* ThumbnailTemp;
	FSlateImageBrush* IconTemp;
	FString ThumbanilPrefex;
	FString IconPrefex;
	FString DirecPrefex;
	FName IcoName;
	TMap<FString, FSlateImageBrush*> AssetImages;

	for(const auto& p : ThumbnailConfig)
	{
		ThumbanilPrefex = "ClassThumbnail.";
		ThumbanilPrefex.Append(p.Key);

		IconPrefex = "ClassIcon.";
		IconPrefex.Append(p.Key);

		//Get Image Directory
		DirecPrefex = "Resources/Icons/";
		DirecPrefex.Append(p.Key);

		//Create and set Thumbnail
		ThumbnailTemp = new FSlateImageBrush(StyleSet->RootToContentDir(DirecPrefex, TEXT(".png")), FVector2D(128.f, 128.f));
		ThumbnailTemp->TintColor = FSlateColor(FLinearColor(1,1,1,1));		//Tint Icon Color
		IcoName = FName(*ThumbanilPrefex);
		StyleSet->Set(IcoName, ThumbnailTemp);
		DirecPrefex.Append("_16");
		//Create and set Icon
		IconTemp = new FSlateImageBrush(StyleSet->RootToContentDir(DirecPrefex, TEXT(".png")), FVector2D(16, 16.f));
		
		FLinearColor icon_color=FLinearColor(1,1,1,1);
		if(ThumbColors.IsValidIndex(p.Value))
		{
			icon_color=ThumbColors[p.Value];
		}
		IconTemp->TintColor = FSlateColor(icon_color);		//Tint Icon Color
		
		IcoName = FName(*IconPrefex);
		StyleSet->Set(IcoName, IconTemp);
	}
	
	//Reguster the created style
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);

	// Register editor category
	int Priority = 42;
	FPlacementCategoryInfo OmegaGameFramework( LOCTEXT("OmegaGameFramework", "Omega Game Framework"), "OmegaGameFramework", TEXT("PMOmegaGameFramework"), Priority);
	IPlacementModeModule::Get().RegisterPlacementCategory(OmegaGameFramework);

	OMACRO_ADDPLACEABLE(OmegaCharacter,"Character")
	OMACRO_ADDPLACEABLE(OmegaEncounterCharacter,"Character - Encounter")
	OMACRO_ADDPLACEABLE(OmegaReferenceCharacter,"Character - Reference")
	OMACRO_ADDPLACEABLE(OmegaCinematicCharacter,"Character - Cutscene")
	OMACRO_ADDPLACEABLE(OmegaInteractable,"Interactable")
	OMACRO_ADDPLACEABLE(OmegaActorEnvironment,"Environment")
	OMACRO_ADDPLACEABLE(Omega_EventVolume,"Event Volume")
	OMACRO_ADDPLACEABLE(OmegaZonePoint,"Zone: Spawn Point")
	OMACRO_ADDPLACEABLE(OmegaZoneTransit,"Zone: Transit Point")
	OMACRO_ADDPLACEABLE(OmegaSplineActor,"Spline")

	// ==================================================================================================================================
	// CUSTOM PROPERTY EDITORS
	// ==================================================================================================================================
	
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	
	_bitflagTypes.Add(FOmegaBitflagsBase::StaticStruct()->GetFName());
	
	for (FName n : _bitflagTypes)
	{
		PropertyModule.RegisterCustomPropertyTypeLayout(
		n,FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FOmegaBitflagsCustomization::MakeInstance));
	}
	FName StructName = FOmegaCustomNamedList::StaticStruct()->GetFName();
	UE_LOG(LogTemp, Warning, TEXT("Registering customization for: %s"), *StructName.ToString());
    
	
	PropertyModule.RegisterCustomPropertyTypeLayout(
		FOmegaCustomNamedList::StaticStruct()->GetFName(),
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FCustomization_CustomNamedList::MakeInstance)
	);
	
	PropertyModule.RegisterCustomPropertyTypeLayout(
		FOmegaClassNamedLists::StaticStruct()->GetFName(),
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FCustomization_ClassNamedLists::MakeInstance)
	);
	
	// Register the ActorRelatives struct customization
	PropertyModule.RegisterCustomPropertyTypeLayout(
		FOmegaActorRelatives::StaticStruct()->GetFName(),
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FCustomization_ActorRelatives::MakeInstance)
	);

	// Register for specific classes or all UObjects
//	PropertyModule.RegisterCustomClassLayout(UObject::StaticClass()->GetFName(),
//		FOnGetDetailCustomizationInstance::CreateStatic(&FOmegaObjectCustomization::MakeInstance));
	
	//PropertyModule.RegisterCustomClassLayout(UObject::StaticClass()->GetFName(),
	//	FOnGetDetailCustomizationInstance::CreateStatic(&FOmegaPropertyHidingCustomization::MakeInstance));
	
	PropertyModule.NotifyCustomizationModuleChanged();
}


void FOmegaEditor::RegisterToolbarExtension()
{
	FToolMenuOwnerScoped OwnerScoped(this);
    
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.User");
	FToolMenuSection& Section = Menu->FindOrAddSection("MyCustomButtons");
    
	Section.AddEntry(FToolMenuEntry::InitToolBarButton(
		"WorldInit",
		FExecuteAction::CreateRaw(this, &FOmegaEditor::OnButtonClicked),
		FText::FromString("WORLD INIT"),
		FText::FromString("Rerun WORLD INIT function in `Global Settings`"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "PlayWorld.PlayInViewport")
	));
}

void FOmegaEditor::OnButtonClicked()
{
	if (GEditor)
	{
		UWorld* World = GEditor->GetEditorWorldContext().World();
		if (World)
		{
			GetMutableDefault<UOmegaSettings>()->GetGameCore()->OnWorldInit(World);
		}
	}
}

void FOmegaEditor::ShutdownModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());
	if (UObjectInitialized())
	{
		UThumbnailManager::Get().UnregisterCustomRenderer(UOmegaDataItem::StaticClass());
	}

	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		
		//PropertyModule.UnregisterCustomPropertyTypeLayout(FOmegaLinearChoices::StaticStruct()->GetFName());
		for (FName n : _bitflagTypes)
		{
			PropertyModule.UnregisterCustomPropertyTypeLayout(n);
		}
		
		PropertyModule.UnregisterCustomPropertyTypeLayout(FOmegaCustomNamedList::StaticStruct()->GetFName());
		PropertyModule.UnregisterCustomPropertyTypeLayout(FOmegaClassNamedLists::StaticStruct()->GetFName());
		PropertyModule.UnregisterCustomPropertyTypeLayout(FOmegaActorRelatives::StaticStruct()->GetFName());
		
		PropertyModule.UnregisterCustomClassLayout(UObject::StaticClass()->GetFName());
		PropertyModule.UnregisterCustomClassLayout(AActor::StaticClass()->GetFName());
	}
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaEditor, OmegaEditor)


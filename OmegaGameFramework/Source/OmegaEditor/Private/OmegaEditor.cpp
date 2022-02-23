// Copyright Studio SyndiCat 2021. All Rights Reserved.

#include "OmegaEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"

#include "AssetTypeActions_Base.h"

#include "IAssetTools.h"

#include "OmegaAbility.h"

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

	//Menus
	RegisterDefaultEvent(UMenu, MenuOpened);
	RegisterDefaultEvent(UMenu, MenuClosed);

	//HUD
	RegisterDefaultEvent(UHUDLayer, LayerAdded);
	
	//DataWidget
	RegisterDefaultEvent(UDataWidget, AddedToDataList);


	// ------- SETUP CATEGORY FACTORY ------- /////

	IAssetTools &AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	OmegaAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Omega")),LOCTEXT("OmegaCategory","Omega"));

	// --- Attribute
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaAttributes(OmegaAssetCategory)));
	
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
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OmegaMenu(OmegaAssetCategory)));

	// --- HUD Layer
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_HudLayer(OmegaAssetCategory)));

	///////////////////////////////////////////////////////
	//------SETUP ASSET THUMBNAILS-----//// 
	StyleSet = MakeShareable(new FSlateStyleSet("OmegaStyle"));
	FString ContentDir = IPluginManager::Get().FindPlugin("OmegaGameFramework")->GetBaseDir(); 	//Content path of this plugin
	StyleSet->SetContentRoot(ContentDir);
	
	//--------CREATE ASSET BRUSH ICONS-----------//

	// Add Basic Thumbnail Location List
	TArray<FString> ThumnbailNames;
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
		IcoName = FName(*ThumbanilPrefex);
		StyleSet->Set(IcoName, ThumbnailTemp);

		DirecPrefex.Append("_16");
		//Create and set Icon
		IconTemp = new FSlateImageBrush(StyleSet->RootToContentDir(DirecPrefex, TEXT(".png")), FVector2D(16, 16.f));
		IcoName = FName(*IconPrefex);
		StyleSet->Set(IcoName, IconTemp);
	};

	//Reguster the created style
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
	//_______________________
}

void FOmegaEditor::ShutdownModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());
}


//static EAssetTypeCategories::Type GetOmegaAssetCategory()
//{
	//return OmegaAssetsCategory;
//}

//static EAssetTypeCategories::Type OmegaAssetsCategory;

//EAssetTypeCategories::Type FOmegaEditor::OmegaAssetsCategory;

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOmegaEditor, OmegaEditor)

////////////////////////////////////
////////---ABILITY---//////////////
///////////////////////////////////
//UOmegaAbility_Factory::UOmegaAbility_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	//SupportedClass = AOmegaAbility::StaticClass();
	//bEditAfterNew = true;
	//bCreateNew = true;
//}

//UObject* UOmegaAbility_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
//{
	//check(Class->IsChildOf(AOmegaAbility::StaticClass()));
	//return NewObject<AOmegaAbility>(InParent, Class, Name, Flags | RF_Transactional, Context);
//}

////////////////////////////////////
////////---GAMEPLAY SYSTEM---//////////////
///////////////////////////////////
//UOmegaGameplaySystem_Factory::UOmegaGameplaySystem_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	//SupportedClass = AOmegaGameplaySystem::StaticClass();
	//bEditAfterNew = true;
	//bCreateNew = true;
//}

//UObject* UOmegaGameplaySystem_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
//{
	//check(Class->IsChildOf(AOmegaGameplaySystem::StaticClass()));
	//return NewObject<AOmegaGameplaySystem>(InParent, Class, Name, Flags | RF_Transactional, Context);
//}

// Asset type actions

//class FAssetTypeActions_InputContext : public FAssetTypeActions_Base {
//public:
	//virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_InputMappingContext", "Ability"); }
	//virtual uint32 GetCategories() override { return FOmegaEditor::GetOmegaAssetCategory(); }
	//virtual FColor GetTypeColor() const override { return FColor(255, 255, 127); }
	//virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_InputContextDesc", "A collection of device input to action mappings."); }
	//virtual UClass* GetSupportedClass() const override { return AOmegaAbility::StaticClass(); }
//};
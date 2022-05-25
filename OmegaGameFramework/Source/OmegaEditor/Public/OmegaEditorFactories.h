// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "AssetTypeActions_Base.h"

#include "OmegaAttribute.h"
#include "OmegaAbility.h"
#include "OmegaDataItem.h"
#include "OmegaGameplaySystem.h"
#include "Attributes/OmegaAttributeSet.h"
#include "Save/OmegaSaveGame.h"
#include "Save/OmegaSaveGlobal.h"

#include "AssetTypeActions/AssetTypeActions_Blueprint.h"
#include "Factories/BlueprintFactory.h"
#include "Gameplay/OmegaGameplayModule.h"
#include "Widget/Menu.h"
#include "OmegaEditorFactories.generated.h"

/**
 * 
 */

////////////////////////////////////////////
////////---Asset Factories---//////////////
///////////////////////////////////////////

//static EAssetTypeCategories::Type OmegaAssetCategory;

//Attributes
UCLASS()
class OMEGAEDITOR_API UOmegaAttributes_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};

class FAssetTypeActions_OmegaAttributes : public FAssetTypeActions_Base
{
public:
	FAssetTypeActions_OmegaAttributes(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegaAttributes", "Attribute"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor(201, 29, 85); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_InputContextDesc", "A collection of device input to action mappings."); }
	virtual UClass* GetSupportedClass() const override { return UOmegaAttribute::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//DataItems
UCLASS()
class OMEGAEDITOR_API UOmegaDataItems_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};

class FAssetTypeActions_OmegaDataItems : public FAssetTypeActions_Base
{
public:
	FAssetTypeActions_OmegaDataItems(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegDataItem", "Data Item"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor(50, 255, 180); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegDataItemDesc", "An Item type."); }
	virtual UClass* GetSupportedClass() const override { return UOmegaDataItem::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//Ability
UCLASS()
class OMEGAEDITOR_API UOmegaAbility_Factory : public UBlueprintFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override {return true;};
};

class FAssetTypeActions_OmegaAbility : public FAssetTypeActions_Blueprint
{
public:
	FAssetTypeActions_OmegaAbility(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegaAbility", "Blueprint Ability"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor( 63, 126, 255 ); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_AbilityContextDesc", "This is Ability"); }
	virtual UClass* GetSupportedClass() const override { return AOmegaAbility::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//AttributeSet
UCLASS()
class OMEGAEDITOR_API UOmegaAttributeSet_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
class FAssetTypeActions_OmegaAttributeSet : public FAssetTypeActions_Base
{
public:
	FAssetTypeActions_OmegaAttributeSet(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegaAttributeSet", "Attribute Set"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor(201, 29, 85); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_AttributeContextDesc", "A collection of attributes that can be assigned to a combatant."); }
	virtual UClass* GetSupportedClass() const override { return UOmegaAttributeSet::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//GameplaySystem
UCLASS()
class OMEGAEDITOR_API UOmegaGameplaySystem_Factory : public UBlueprintFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override {return true;};
};
class FAssetTypeActions_OmegaGameplaySystem : public FAssetTypeActions_Blueprint
{
public:
	FAssetTypeActions_OmegaGameplaySystem(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegaGameplaySystem", "Gameplay System"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor( 63, 126, 255 ); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_GameplaySystemContextDesc", "An singleton actor that handles a specific game system."); }
	virtual UClass* GetSupportedClass() const override { return AOmegaGameplaySystem::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//GameplayModules
UCLASS()
class OMEGAEDITOR_API UOmegaGameplayModule_Factory : public UBlueprintFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override {return true;};
};
class FAssetTypeActions_OmegaGameplayModule : public FAssetTypeActions_Blueprint
{
public:
	FAssetTypeActions_OmegaGameplayModule(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegaGameplayModule", "Gameplay Module"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor( 63, 126, 255 ); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_GameplayModuleContextDesc", "An singleton actor that handles a specific game system."); }
	virtual UClass* GetSupportedClass() const override { return UOmegaGameplayModule::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//GameSave
UCLASS()
class OMEGAEDITOR_API UOmegaGameSave_Factory : public UBlueprintFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override {return true;};
};
class FAssetTypeActions_OmegaGameSave : public FAssetTypeActions_Blueprint
{
public:
	FAssetTypeActions_OmegaGameSave(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegaGameSave", "Game Save"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor( 63, 200, 255 ); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_GameSaveContextDesc", "An singleton actor that handles a specific game system."); }
	virtual UClass* GetSupportedClass() const override { return UOmegaSaveGame::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//GlobalSave
UCLASS()
class OMEGAEDITOR_API UOmegaGlobalSave_Factory : public UBlueprintFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override {return true;};
};
class FAssetTypeActions_OmegaGlobalSave : public FAssetTypeActions_Blueprint
{
public:
	FAssetTypeActions_OmegaGlobalSave(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_OmegaGlobalSave", "Global Save"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor( 63, 200, 255 ); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_GlobalSaveContextDesc", "An singleton actor that handles a specific game system."); }
	virtual UClass* GetSupportedClass() const override { return UOmegaSaveGlobal::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};


////////////////// WIDGETS ///////////////////

//Menu
UCLASS()
class OMEGAEDITOR_API UOmegaMenu_Factory : public UBlueprintFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override {return true;};
};
class FAssetTypeActions_OmegaMenu : public FAssetTypeActions_Blueprint
{
public:
	FAssetTypeActions_OmegaMenu(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_Menu", "Menu"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor( 63, 126, 255 ); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_MenuContextDesc", "Menu"); }
	virtual UClass* GetSupportedClass() const override { return UMenu::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

//HudLayer
UCLASS()
class OMEGAEDITOR_API UOmegaHudLayer_Factory : public UBlueprintFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override {return true;};
};
class FAssetTypeActions_HudLayer : public FAssetTypeActions_Blueprint
{
public:
	FAssetTypeActions_HudLayer(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){};
	
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_HudLayer", "HUD Layer"); }
	virtual uint32 GetCategories() override { return OmegaAssetCategory; }
	virtual FColor GetTypeColor() const override { return FColor( 63, 126, 255 ); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_HudLayerContextDesc", "Hud Layer"); }
	virtual UClass* GetSupportedClass() const override { return UHUDLayer::StaticClass(); }
private:
	EAssetTypeCategories::Type OmegaAssetCategory;
};

////////////////// Game Preferences ///////////////////
/*
//GamePreferenceBool
UCLASS()
class OMEGAEDITOR_API UGamePreferenceBool_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};

//GamePreferenceFloat
UCLASS()
class OMEGAEDITOR_API UGamePreferenceFloat_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};

//GamePreferenceString
UCLASS()
class OMEGAEDITOR_API UGamePreferenceString_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};

//GamePreferenceTag
UCLASS()
class OMEGAEDITOR_API UGamePreferenceTag_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
*/

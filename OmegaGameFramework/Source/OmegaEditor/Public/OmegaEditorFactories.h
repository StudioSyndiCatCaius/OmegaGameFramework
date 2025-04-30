// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "AssetTypeActions_Base.h"

#include "Misc/OmegaAttribute.h"
#include "Misc/OmegaFaction.h"
#include "Misc/OmegaDemoAssets.h"
#include "Actors/Actor_Ability.h"
#include "OmegaDataItem.h"
#include "OmegaDebug_Functions.h"
#include "Actors/Actor_Character.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "Subsystems/OmegaSubsystem_Quest.h"
#include "Subsystems/OmegaSubsystem_Zone.h"
#include "Misc/CombatantGambits.h"

#include "AssetTypeActions/AssetTypeActions_Blueprint.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Subscript.h"
#include "Factories/BlueprintFactory.h"
#include "Functions/OmegaFunctions_Actor.h"
#include "Functions/OmegaFunctions_Animation.h"
#include "Functions/OmegaFunctions_Combatant.h"
#include "Misc/OmegaGameplayModule.h"
#include "Subsystems/OmegaSubsystem_BGM.h"
#include "Widget/Menu.h"
#include "OmegaEditorFactories.generated.h"

#define OMACRO_ASSETTYPE_HEADERFIELD(AssetName, DisplayName, AssetDescription, AssetColor, AssetCategory) \
inline UObject* U##AssetName##_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) \
{ \
	check(Class->IsChildOf(U##AssetName##::StaticClass())); \
	return NewObject<U##AssetName##>(InParent, Class, Name, Flags | RF_Transactional); \
} \
inline U##AssetName##_Factory::U##AssetName##_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) { \
	SupportedClass = U##AssetName##::StaticClass(); bEditAfterNew = true; bCreateNew = true; \
} \
class FAssetTypeActions_##AssetName: public FAssetTypeActions_Base \
{ \
public: \
FAssetTypeActions_##AssetName##(EAssetTypeCategories::Type InAssetCategory) : OmegaAssetCategory(InAssetCategory){}; \
virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_"#AssetName"Desc", DisplayName); } \
virtual uint32 GetCategories() override { return OmegaAssetCategory; } \
virtual FColor GetTypeColor() const override { return AssetColor; } \
virtual UClass* GetSupportedClass() const override { return U##AssetName::StaticClass(); } \
virtual const TArray<FText>& GetSubMenus() const override \
{ static const TArray<FText> SubMenus { NSLOCTEXT("AssetTypeActions", "OmegaAssetSubMenu_"#AssetCategory, AssetCategory) }; return SubMenus; }; \
private: \
EAssetTypeCategories::Type OmegaAssetCategory; \
}; \

////////////////////////////////////////////
////////---Asset Factories---//////////////
///////////////////////////////////////////

//Attributes
UCLASS() class OMEGAEDITOR_API UOmegaAttribute_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaAttribute,"Attribute", "Asset Desc here", FColor(201, 29, 85),"Gameplay")

//Factions
UCLASS() class OMEGAEDITOR_API UOmegaFaction_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaFaction,"Faction", "Asset Desc here", FColor(201, 29, 85),"Gameplay")

//DamageType
UCLASS() class OMEGAEDITOR_API UOmegaDamageType_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaDamageType,"Damage Type", "Asset Desc here", FColor(201, 29, 85),"Gameplay")

//Combatant Gambit
UCLASS() class OMEGAEDITOR_API UCombatantGambitAsset_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(CombatantGambitAsset,"Combat Gambit", "Asset Desc here", FColor(201, 29, 85),"Gameplay")

//Quest
UCLASS() class OMEGAEDITOR_API UOmegaQuest_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaQuest,"Quest", "Asset Desc here",FColor(201, 29, 85),"Gameplay")

//Skill
UCLASS() class OMEGAEDITOR_API UOmegaCommonSkill_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaCommonSkill,"Common Skill", "Asset Desc here",FColor(255, 40, 56),"Gameplay")

//Subscript
UCLASS() class OMEGAEDITOR_API USubscriptCollection_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(SubscriptCollection,"Subscript Collection", "Asset Desc here",FColor(40, 120, 255),"Gameplay")

//BGM
UCLASS() class OMEGAEDITOR_API UOmegaBGM_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaBGM,"BGM", "Asset Desc here", FColor(100, 0, 225),"Audio")


//Level Data
UCLASS() class OMEGAEDITOR_API UOmegaLevelData_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaLevelData,"Level: World Data", "Asset Desc here", FColor(225, 150, 0),"World")

//Level Data
UCLASS() class OMEGAEDITOR_API UOmegaZoneData_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaZoneData,"Level: Zone Data", "Asset Desc here", FColor(225, 150, 0),"World")


//Level Data
UCLASS() class OMEGAEDITOR_API UZoneLegendAsset_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(ZoneLegendAsset,"Level: Zone Legend", "Asset Desc here", FColor(225, 155, 40),"World")


//Story State
UCLASS() class OMEGAEDITOR_API UOmegaStoryStateAsset_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaStoryStateAsset,"Story State", "Asset Desc here", FColor(201, 29, 85),"Save")


//Emote
UCLASS() class OMEGAEDITOR_API UOmegaAnimationEmote_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaAnimationEmote,"Emote", "Asset Desc here", FColor(0, 225, 110),"Animation")

//Leveling Asset
UCLASS() class OMEGAEDITOR_API UOmegaLevelingAsset_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaLevelingAsset,"Leveling Asset", "Asset Desc here", FColor(0, 225, 110),"Gameplay")


//Config Actor
UCLASS() class OMEGAEDITOR_API UOmegaActorConfig_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaActorConfig,"Actor Config", "Asset Desc here", FColor(50, 50, 50),"Util")


//Config Character
UCLASS() class OMEGAEDITOR_API UOmegaCharacterConfig_Factory : public UFactory
{
	GENERATED_UCLASS_BODY()
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
OMACRO_ASSETTYPE_HEADERFIELD(OmegaCharacterConfig,"Character Config", "Asset Desc here", FColor(50, 50, 50),"Util")

inline FColor _color_debug=FColor(200,200,200);




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


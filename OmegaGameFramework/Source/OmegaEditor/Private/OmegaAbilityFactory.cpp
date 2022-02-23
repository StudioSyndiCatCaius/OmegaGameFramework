// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaAbilityFactory.h"
//The asset header file that we wish to create
#include "OmegaAbility.h"
//The asset type categories will let us access the various asset categories inside the Editor
#include "AssetTypeCategories.h"

/*
UOmegaAbilityFactory::UOmegaAbilityFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	//Configure the class that this factory creates
	SupportedClass = AOmegaAbility::StaticClass();
}

UObject* UOmegaAbilityFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	//Create the editor asset 
	AOmegaAbility* OmegaEditorAsset = NewObject<AOmegaAbility>(InParent, InClass, InName, Flags);
	return OmegaEditorAsset;
}

// ---- CATEGORY DEFINITIONS ----- //
FOmegaAssetTypeActions::FOmegaAssetTypeActions(uint32 InAssetCategory) : MyAssetCategory(InAssetCategory)
{
}

uint32 FOmegaAssetTypeActions::GetCategories()
{
	return MyAssetCategory;
}


// ---- SET ASSET PROPERTIES ----- //

FText FOmegaAssetTypeActions::GetName() const
{
	return FText::FromString("Omega Ability");
}

FColor FOmegaAssetTypeActions::GetTypeColor() const
{
	return FColor(200, 060, 060);
}

UClass* FOmegaAssetTypeActions::GetSupportedClass() const
{
	return AOmegaAbility::StaticClass();
}
*/
// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaEditorFactories.h"
#include "AssetRegistryModule.h"
#include "BlueprintEditorModule.h"
#include "DetailCategoryBuilder.h"
#include "IAssetTools.h"
#include "KismetCompilerModule.h"
#include "Kismet2/KismetEditorUtilities.h"


#define LOCTEXT_NAMESPACE "AssetTypeActions"

///////////////////////////////////////////////////
//////////////// Asset factories ////////////////
///////////////////////////////////////////////////

//////// Attributes ////////
UOmegaAttributes_Factory::UOmegaAttributes_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UOmegaAttribute::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

UObject* UOmegaAttributes_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UOmegaAttribute::StaticClass()));
	return NewObject<UOmegaAttribute>(InParent, Class, Name, Flags | RF_Transactional);
}

//////// DataItem ////////
UOmegaDataItems_Factory::UOmegaDataItems_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UOmegaDataItem::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

UObject* UOmegaDataItems_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UOmegaDataItem::StaticClass()));
	return NewObject<UOmegaDataItem>(InParent, Class, Name, Flags | RF_Transactional);
}

//////// AttributesSet ////////
UOmegaAttributeSet_Factory::UOmegaAttributeSet_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UOmegaAttributeSet::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaAttributeSet_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UOmegaAttributeSet::StaticClass()));
	return NewObject<UOmegaAttributeSet>(InParent, Class, Name, Flags | RF_Transactional);
}

//////// Ability ////////
UOmegaAbility_Factory::UOmegaAbility_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = AOmegaAbility::StaticClass();
	ParentClass = AOmegaAbility::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaAbility_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(AOmegaAbility::StaticClass()));
	
	if (ParentClass != AOmegaAbility::StaticClass())
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args));
		return nullptr;
	}
	else
	{
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	}
}

//////// Gameplay System ////////
UOmegaGameplaySystem_Factory::UOmegaGameplaySystem_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = AOmegaGameplaySystem::StaticClass();
	ParentClass = AOmegaGameplaySystem::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaGameplaySystem_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(AOmegaGameplaySystem::StaticClass()));
	
	if (ParentClass != AOmegaGameplaySystem::StaticClass())
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args));
		return nullptr;
	}
	else
	{
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	}
}

//////// Gameplay Module ////////
UOmegaGameplayModule_Factory::UOmegaGameplayModule_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UOmegaGameplayModule::StaticClass();
	ParentClass = UOmegaGameplayModule::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaGameplayModule_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(UOmegaGameplayModule::StaticClass()));
	
	if (ParentClass != UOmegaGameplayModule::StaticClass())
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args));
		return nullptr;
	}
	else
	{
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	}
}

//////// Save Game ////////
UOmegaGameSave_Factory::UOmegaGameSave_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UOmegaSaveGame::StaticClass();
	ParentClass = UOmegaSaveGame::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaGameSave_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(UOmegaSaveGame::StaticClass()));
	
	if (ParentClass != UOmegaSaveGame::StaticClass())
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args));
		return nullptr;
	}
	else
	{
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	}
}

//////// Save Global ////////
UOmegaGlobalSave_Factory::UOmegaGlobalSave_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UOmegaSaveGlobal::StaticClass();
	ParentClass = UOmegaSaveGlobal::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaGlobalSave_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(UOmegaSaveGlobal::StaticClass()));
	
	if (ParentClass != UOmegaSaveGlobal::StaticClass())
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args));
		return nullptr;
	}
	else
	{
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	}
}

//////// Menu ////////
UOmegaMenu_Factory::UOmegaMenu_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UMenu::StaticClass();
	ParentClass = UMenu::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaMenu_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(UMenu::StaticClass()));
	
	if (ParentClass != UMenu::StaticClass())
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args));
		return nullptr;
	}
	else
	{
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	}
}

//////// Hud Layer ////////
UOmegaHudLayer_Factory::UOmegaHudLayer_Factory(const class FObjectInitializer& OBJ) : Super(OBJ) {
	SupportedClass = UHUDLayer::StaticClass();
	ParentClass = UHUDLayer::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}
UObject* UOmegaHudLayer_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(UHUDLayer::StaticClass()));
	
	if (ParentClass != UHUDLayer::StaticClass())
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args));
		return nullptr;
	}
	else
	{
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	}
}



// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Public/ActionsSubsystem.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActionsSubsystem() {}
// Cross Module References
	ACTIONS_API UScriptStruct* Z_Construct_UScriptStruct_FActionsTickGroup();
	UPackage* Z_Construct_UPackage__Script_Actions();
	ACTIONS_API UClass* Z_Construct_UClass_UAction_NoRegister();
	ACTIONS_API UScriptStruct* Z_Construct_UScriptStruct_FRootAction();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ACTIONS_API UClass* Z_Construct_UClass_UActionsSubsystem_NoRegister();
	ACTIONS_API UClass* Z_Construct_UClass_UActionsSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ActionsTickGroup;
class UScriptStruct* FActionsTickGroup::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ActionsTickGroup.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ActionsTickGroup.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActionsTickGroup, Z_Construct_UPackage__Script_Actions(), TEXT("ActionsTickGroup"));
	}
	return Z_Registration_Info_UScriptStruct_ActionsTickGroup.OuterSingleton;
}
template<> ACTIONS_API UScriptStruct* StaticStruct<FActionsTickGroup>()
{
	return FActionsTickGroup::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FActionsTickGroup_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TickRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TickRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TickTimeElapsed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TickTimeElapsed;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionsTickGroup_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Contains a list of actions with the same TickRate\n */" },
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
		{ "ToolTip", "Contains a list of actions with the same TickRate" },
	};
#endif
	void* Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActionsTickGroup>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickRate_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickRate = { "TickRate", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActionsTickGroup, TickRate), METADATA_PARAMS(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickRate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickTimeElapsed_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickTimeElapsed = { "TickTimeElapsed", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActionsTickGroup, TickTimeElapsed), METADATA_PARAMS(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickTimeElapsed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickTimeElapsed_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_Actions_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActionsTickGroup, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_Actions_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_Actions_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActionsTickGroup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_TickTimeElapsed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_Actions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewProp_Actions,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActionsTickGroup_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Actions,
		nullptr,
		&NewStructOps,
		"ActionsTickGroup",
		sizeof(FActionsTickGroup),
		alignof(FActionsTickGroup),
		Z_Construct_UScriptStruct_FActionsTickGroup_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionsTickGroup_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FActionsTickGroup()
	{
		if (!Z_Registration_Info_UScriptStruct_ActionsTickGroup.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ActionsTickGroup.InnerSingleton, Z_Construct_UScriptStruct_FActionsTickGroup_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ActionsTickGroup.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RootAction;
class UScriptStruct* FRootAction::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RootAction.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RootAction.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRootAction, Z_Construct_UPackage__Script_Actions(), TEXT("RootAction"));
	}
	return Z_Registration_Info_UScriptStruct_RootAction.OuterSingleton;
}
template<> ACTIONS_API UScriptStruct* StaticStruct<FRootAction>()
{
	return FRootAction::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRootAction_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Owner_MetaData[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Owner;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRootAction_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Represents a dependency of an objects with all its actions\n * Used to cancel actions whose owner is destroyed\n */" },
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
		{ "ToolTip", "Represents a dependency of an objects with all its actions\nUsed to cancel actions whose owner is destroyed" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRootAction_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRootAction>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Owner_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRootAction, Owner), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Owner_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Owner_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Actions_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRootAction, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Actions_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Actions_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRootAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Owner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Actions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRootAction_Statics::NewProp_Actions,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRootAction_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Actions,
		nullptr,
		&NewStructOps,
		"RootAction",
		sizeof(FRootAction),
		alignof(FRootAction),
		Z_Construct_UScriptStruct_FRootAction_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRootAction_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FRootAction_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRootAction_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FRootAction()
	{
		if (!Z_Registration_Info_UScriptStruct_RootAction.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RootAction.InnerSingleton, Z_Construct_UScriptStruct_FRootAction_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RootAction.InnerSingleton;
	}
	DEFINE_FUNCTION(UActionsSubsystem::execCancelAllByOwner)
	{
		P_GET_OBJECT(UObject,Z_Param_Object);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CancelAllByOwner(Z_Param_Object);
		P_NATIVE_END;
	}
	void UActionsSubsystem::StaticRegisterNativesUActionsSubsystem()
	{
		UClass* Class = UActionsSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CancelAllByOwner", &UActionsSubsystem::execCancelAllByOwner },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics
	{
		struct ActionsSubsystem_eventCancelAllByOwner_Parms
		{
			UObject* Object;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActionsSubsystem_eventCancelAllByOwner_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "ActionSubsystem" },
		{ "Comment", "/** Cancel all actions executing inside an object\n\x09 * @param Owner of the actions to cancel\n\x09 */" },
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
		{ "ToolTip", "Cancel all actions executing inside an object\n@param Owner of the actions to cancel" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActionsSubsystem, nullptr, "CancelAllByOwner", nullptr, nullptr, sizeof(Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::ActionsSubsystem_eventCancelAllByOwner_Parms), Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UActionsSubsystem);
	UClass* Z_Construct_UClass_UActionsSubsystem_NoRegister()
	{
		return UActionsSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UActionsSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RootActions_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RootActions_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_RootActions;
		static const UECodeGen_Private::FStructPropertyParams NewProp_TickGroups_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TickGroups_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TickGroups;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActionsSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_Actions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UActionsSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UActionsSubsystem_CancelAllByOwner, "CancelAllByOwner" }, // 1095463260
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActionsSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Actions Subsystem\n * Keeps track of all running actions and their lifetime.\n * It also does a global tick based on tick rate for all actions.\n */" },
		{ "IncludePath", "ActionsSubsystem.h" },
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
		{ "ToolTip", "Actions Subsystem\nKeeps track of all running actions and their lifetime.\nIt also does a global tick based on tick rate for all actions." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_RootActions_ElementProp = { "RootActions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FRootAction, METADATA_PARAMS(nullptr, 0) }; // 3858684371
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_RootActions_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
	};
#endif
	static_assert(TModels<CGetTypeHashable, FRootAction>::Value, "The structure 'FRootAction' is used in a TSet but does not have a GetValueTypeHash defined");
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_RootActions = { "RootActions", nullptr, (EPropertyFlags)0x0040000001000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UActionsSubsystem, RootActions), METADATA_PARAMS(Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_RootActions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_RootActions_MetaData)) }; // 3858684371
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_TickGroups_Inner = { "TickGroups", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FActionsTickGroup, METADATA_PARAMS(nullptr, 0) }; // 4240165443
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_TickGroups_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActionsSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_TickGroups = { "TickGroups", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UActionsSubsystem, TickGroups), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_TickGroups_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_TickGroups_MetaData)) }; // 4240165443
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UActionsSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_RootActions_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_RootActions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_TickGroups_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActionsSubsystem_Statics::NewProp_TickGroups,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActionsSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UActionsSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UActionsSubsystem_Statics::ClassParams = {
		&UActionsSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UActionsSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UActionsSubsystem_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UActionsSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActionsSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActionsSubsystem()
	{
		if (!Z_Registration_Info_UClass_UActionsSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActionsSubsystem.OuterSingleton, Z_Construct_UClass_UActionsSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UActionsSubsystem.OuterSingleton;
	}
	template<> ACTIONS_API UClass* StaticClass<UActionsSubsystem>()
	{
		return UActionsSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActionsSubsystem);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_Statics::ScriptStructInfo[] = {
		{ FActionsTickGroup::StaticStruct, Z_Construct_UScriptStruct_FActionsTickGroup_Statics::NewStructOps, TEXT("ActionsTickGroup"), &Z_Registration_Info_UScriptStruct_ActionsTickGroup, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActionsTickGroup), 4240165443U) },
		{ FRootAction::StaticStruct, Z_Construct_UScriptStruct_FRootAction_Statics::NewStructOps, TEXT("RootAction"), &Z_Registration_Info_UScriptStruct_RootAction, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRootAction), 3858684371U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UActionsSubsystem, UActionsSubsystem::StaticClass, TEXT("UActionsSubsystem"), &Z_Registration_Info_UClass_UActionsSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActionsSubsystem), 3349807154U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_3081806201(TEXT("/Script/Actions"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionsSubsystem_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

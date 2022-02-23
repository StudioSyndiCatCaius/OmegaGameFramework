// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Public/ActionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActionLibrary() {}
// Cross Module References
	ACTIONS_API UClass* Z_Construct_UClass_UActionLibrary_NoRegister();
	ACTIONS_API UClass* Z_Construct_UClass_UActionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Actions();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ACTIONS_API UClass* Z_Construct_UClass_UAction_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UActionLibrary::execCreateAction)
	{
		P_GET_OBJECT(UObject,Z_Param_Owner);
		P_GET_OBJECT(UClass,Z_Param_Type);
		P_GET_UBOOL(Z_Param_bAutoActivate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAction**)Z_Param__Result=UActionLibrary::CreateAction(Z_Param_Owner,Z_Param_Type,Z_Param_bAutoActivate);
		P_NATIVE_END;
	}
	void UActionLibrary::StaticRegisterNativesUActionLibrary()
	{
		UClass* Class = UActionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateAction", &UActionLibrary::execCreateAction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UActionLibrary_CreateAction_Statics
	{
		struct ActionLibrary_eventCreateAction_Parms
		{
			UObject* Owner;
			const TSubclassOf<UAction>  Type;
			bool bAutoActivate;
			UAction* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Owner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Type;
		static void NewProp_bAutoActivate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoActivate;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActionLibrary_eventCreateAction_Parms, Owner), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_Type_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0014040000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActionLibrary_eventCreateAction_Parms, Type), Z_Construct_UClass_UAction_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_Type_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_Type_MetaData)) };
	void Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_bAutoActivate_SetBit(void* Obj)
	{
		((ActionLibrary_eventCreateAction_Parms*)Obj)->bAutoActivate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_bAutoActivate = { "bAutoActivate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ActionLibrary_eventCreateAction_Parms), &Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_bAutoActivate_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActionLibrary_eventCreateAction_Parms, ReturnValue), Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_Owner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_Type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_bAutoActivate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Type" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Action" },
		{ "CPP_Default_bAutoActivate", "false" },
		{ "DefaultToSelf", "Owner" },
		{ "DisplayName", "Create Action" },
		{ "ModuleRelativePath", "Public/ActionLibrary.h" },
		{ "WorldContext", "Owner" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActionLibrary, nullptr, "CreateAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::ActionLibrary_eventCreateAction_Parms), Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActionLibrary_CreateAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActionLibrary_CreateAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UActionLibrary);
	UClass* Z_Construct_UClass_UActionLibrary_NoRegister()
	{
		return UActionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UActionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Actions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UActionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UActionLibrary_CreateAction, "CreateAction" }, // 2671568598
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ActionLibrary.h" },
		{ "ModuleRelativePath", "Public/ActionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UActionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UActionLibrary_Statics::ClassParams = {
		&UActionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UActionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActionLibrary()
	{
		if (!Z_Registration_Info_UClass_UActionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActionLibrary.OuterSingleton, Z_Construct_UClass_UActionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UActionLibrary.OuterSingleton;
	}
	template<> ACTIONS_API UClass* StaticClass<UActionLibrary>()
	{
		return UActionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActionLibrary);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UActionLibrary, UActionLibrary::StaticClass, TEXT("UActionLibrary"), &Z_Registration_Info_UClass_UActionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActionLibrary), 2882931473U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionLibrary_h_922526422(TEXT("/Script/Actions"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_ActionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

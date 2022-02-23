// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Public/BTT_RunAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTT_RunAction() {}
// Cross Module References
	ACTIONS_API UClass* Z_Construct_UClass_UBTT_RunAction_NoRegister();
	ACTIONS_API UClass* Z_Construct_UClass_UBTT_RunAction();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	UPackage* Z_Construct_UPackage__Script_Actions();
	ACTIONS_API UEnum* Z_Construct_UEnum_Actions_EActionState();
	ACTIONS_API UClass* Z_Construct_UClass_UAction_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTreeComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UBTT_RunAction::execOnRunActionFinished)
	{
		P_GET_ENUM(EActionState,Z_Param_Reason);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRunActionFinished(EActionState(Z_Param_Reason));
		P_NATIVE_END;
	}
	void UBTT_RunAction::StaticRegisterNativesUBTT_RunAction()
	{
		UClass* Class = UBTT_RunAction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnRunActionFinished", &UBTT_RunAction::execOnRunActionFinished },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics
	{
		struct BTT_RunAction_eventOnRunActionFinished_Parms
		{
			EActionState Reason;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BTT_RunAction_eventOnRunActionFinished_Parms, Reason), Z_Construct_UEnum_Actions_EActionState, METADATA_PARAMS(Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::NewProp_Reason_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::NewProp_Reason_MetaData)) }; // 696707442
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::NewProp_Reason_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::NewProp_Reason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BTT_RunAction.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBTT_RunAction, nullptr, "OnRunActionFinished", nullptr, nullptr, sizeof(Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::BTT_RunAction_eventOnRunActionFinished_Parms), Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTT_RunAction);
	UClass* Z_Construct_UClass_UBTT_RunAction_NoRegister()
	{
		return UBTT_RunAction::StaticClass();
	}
	struct Z_Construct_UClass_UBTT_RunAction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActionType_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OwnerComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTT_RunAction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_Actions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UBTT_RunAction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UBTT_RunAction_OnRunActionFinished, "OnRunActionFinished" }, // 3064610532
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTT_RunAction_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "BTT_RunAction.h" },
		{ "ModuleRelativePath", "Public/BTT_RunAction.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_ActionType_MetaData[] = {
		{ "Category", "Node" },
		{ "DisplayName", "Action" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BTT_RunAction.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_ActionType = { "ActionType", nullptr, (EPropertyFlags)0x001200000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBTT_RunAction, ActionType), Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_ActionType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_ActionType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_Action_MetaData[] = {
		{ "ModuleRelativePath", "Public/BTT_RunAction.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBTT_RunAction, Action), Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_Action_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_Action_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_OwnerComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BTT_RunAction.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000082008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBTT_RunAction, OwnerComp), Z_Construct_UClass_UBehaviorTreeComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_OwnerComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_OwnerComp_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTT_RunAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_ActionType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_Action,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTT_RunAction_Statics::NewProp_OwnerComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTT_RunAction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTT_RunAction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTT_RunAction_Statics::ClassParams = {
		&UBTT_RunAction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UBTT_RunAction_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_RunAction_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UBTT_RunAction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBTT_RunAction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBTT_RunAction()
	{
		if (!Z_Registration_Info_UClass_UBTT_RunAction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTT_RunAction.OuterSingleton, Z_Construct_UClass_UBTT_RunAction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTT_RunAction.OuterSingleton;
	}
	template<> ACTIONS_API UClass* StaticClass<UBTT_RunAction>()
	{
		return UBTT_RunAction::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTT_RunAction);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_BTT_RunAction_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_BTT_RunAction_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTT_RunAction, UBTT_RunAction::StaticClass, TEXT("UBTT_RunAction"), &Z_Registration_Info_UClass_UBTT_RunAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTT_RunAction), 4119368142U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_BTT_RunAction_h_190762959(TEXT("/Script/Actions"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_BTT_RunAction_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_BTT_RunAction_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

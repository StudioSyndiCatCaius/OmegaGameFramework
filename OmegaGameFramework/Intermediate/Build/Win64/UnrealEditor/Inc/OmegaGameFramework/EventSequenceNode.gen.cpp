// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Event/Sequence/EventSequenceNode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEventSequenceNode() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEventSequenceNode_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEventSequenceNode();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UEventSequenceNode::execFinishEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FinishEvent();
		P_NATIVE_END;
	}
	static FName NAME_UEventSequenceNode_OnEventBegin = FName(TEXT("OnEventBegin"));
	void UEventSequenceNode::OnEventBegin()
	{
		ProcessEvent(FindFunctionChecked(NAME_UEventSequenceNode_OnEventBegin),NULL);
	}
	static FName NAME_UEventSequenceNode_OnEventFinished = FName(TEXT("OnEventFinished"));
	void UEventSequenceNode::OnEventFinished()
	{
		ProcessEvent(FindFunctionChecked(NAME_UEventSequenceNode_OnEventFinished),NULL);
	}
	void UEventSequenceNode::StaticRegisterNativesUEventSequenceNode()
	{
		UClass* Class = UEventSequenceNode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FinishEvent", &UEventSequenceNode::execFinishEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEventSequenceNode_FinishEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEventSequenceNode_FinishEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "EventSequence|Node" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequenceNode.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEventSequenceNode_FinishEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEventSequenceNode, nullptr, "FinishEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEventSequenceNode_FinishEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventSequenceNode_FinishEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEventSequenceNode_FinishEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEventSequenceNode_FinishEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEventSequenceNode_OnEventBegin_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEventSequenceNode_OnEventBegin_Statics::Function_MetaDataParams[] = {
		{ "Category", "EventSequence|Node" },
		{ "Comment", "//Functions\n" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequenceNode.h" },
		{ "ToolTip", "Functions" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEventSequenceNode_OnEventBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEventSequenceNode, nullptr, "OnEventBegin", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEventSequenceNode_OnEventBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventSequenceNode_OnEventBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEventSequenceNode_OnEventBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEventSequenceNode_OnEventBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEventSequenceNode_OnEventFinished_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEventSequenceNode_OnEventFinished_Statics::Function_MetaDataParams[] = {
		{ "Category", "EventSequence|Node" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequenceNode.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEventSequenceNode_OnEventFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEventSequenceNode, nullptr, "OnEventFinished", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEventSequenceNode_OnEventFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventSequenceNode_OnEventFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEventSequenceNode_OnEventFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEventSequenceNode_OnEventFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEventSequenceNode);
	UClass* Z_Construct_UClass_UEventSequenceNode_NoRegister()
	{
		return UEventSequenceNode::StaticClass();
	}
	struct Z_Construct_UClass_UEventSequenceNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldPrivate_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldPrivate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEventSequenceNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UEventSequenceNode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEventSequenceNode_FinishEvent, "FinishEvent" }, // 3200086865
		{ &Z_Construct_UFunction_UEventSequenceNode_OnEventBegin, "OnEventBegin" }, // 2924664153
		{ &Z_Construct_UFunction_UEventSequenceNode_OnEventFinished, "OnEventFinished" }, // 3687644259
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventSequenceNode_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Event/Sequence/EventSequenceNode.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequenceNode.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventSequenceNode_Statics::NewProp_WorldPrivate_MetaData[] = {
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequenceNode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEventSequenceNode_Statics::NewProp_WorldPrivate = { "WorldPrivate", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEventSequenceNode, WorldPrivate), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEventSequenceNode_Statics::NewProp_WorldPrivate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequenceNode_Statics::NewProp_WorldPrivate_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEventSequenceNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventSequenceNode_Statics::NewProp_WorldPrivate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEventSequenceNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEventSequenceNode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEventSequenceNode_Statics::ClassParams = {
		&UEventSequenceNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEventSequenceNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequenceNode_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UEventSequenceNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequenceNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEventSequenceNode()
	{
		if (!Z_Registration_Info_UClass_UEventSequenceNode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEventSequenceNode.OuterSingleton, Z_Construct_UClass_UEventSequenceNode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEventSequenceNode.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UEventSequenceNode>()
	{
		return UEventSequenceNode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEventSequenceNode);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequenceNode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequenceNode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEventSequenceNode, UEventSequenceNode::StaticClass, TEXT("UEventSequenceNode"), &Z_Registration_Info_UClass_UEventSequenceNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEventSequenceNode), 2622997548U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequenceNode_h_2857983202(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequenceNode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequenceNode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

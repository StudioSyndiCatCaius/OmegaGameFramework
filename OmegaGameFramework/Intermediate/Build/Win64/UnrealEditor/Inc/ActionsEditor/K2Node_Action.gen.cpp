// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActionsEditor/Private/Nodes/K2Node_Action.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeK2Node_Action() {}
// Cross Module References
	ACTIONSEDITOR_API UClass* Z_Construct_UClass_UK2Node_Action_NoRegister();
	ACTIONSEDITOR_API UClass* Z_Construct_UClass_UK2Node_Action();
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node();
	UPackage* Z_Construct_UPackage__Script_ActionsEditor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	BLUEPRINTGRAPH_API UScriptStruct* Z_Construct_UScriptStruct_FOptionalPinFromProperty();
	ACTIONSEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FActionProperties();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprint_NoRegister();
// End Cross Module References
	void UK2Node_Action::StaticRegisterNativesUK2Node_Action()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UK2Node_Action);
	UClass* Z_Construct_UClass_UK2Node_Action_NoRegister()
	{
		return UK2Node_Action::StaticClass();
	}
	struct Z_Construct_UClass_UK2Node_Action_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActionClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ActionClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShowClass_MetaData[];
#endif
		static void NewProp_bShowClass_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowClass;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ShowPinForProperties_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShowPinForProperties_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ShowPinForProperties;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentProperties_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentProperties;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActionBlueprint_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionBlueprint;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UK2Node_Action_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK2Node,
		(UObject* (*)())Z_Construct_UPackage__Script_ActionsEditor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_Action_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Nodes/K2Node_Action.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/Nodes/K2Node_Action.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionClass_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/K2Node_Action.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionClass = { "ActionClass", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UK2Node_Action, ActionClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_Action_Statics::NewProp_bShowClass_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/K2Node_Action.h" },
	};
#endif
	void Z_Construct_UClass_UK2Node_Action_Statics::NewProp_bShowClass_SetBit(void* Obj)
	{
		((UK2Node_Action*)Obj)->bShowClass = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UK2Node_Action_Statics::NewProp_bShowClass = { "bShowClass", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UK2Node_Action), &Z_Construct_UClass_UK2Node_Action_Statics::NewProp_bShowClass_SetBit, METADATA_PARAMS(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_bShowClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_bShowClass_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ShowPinForProperties_Inner = { "ShowPinForProperties", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FOptionalPinFromProperty, METADATA_PARAMS(nullptr, 0) }; // 2088080815
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ShowPinForProperties_MetaData[] = {
		{ "Category", "PinOptions" },
		{ "Comment", "/** Output pin visibility control */" },
		{ "ModuleRelativePath", "Private/Nodes/K2Node_Action.h" },
		{ "ToolTip", "Output pin visibility control" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ShowPinForProperties = { "ShowPinForProperties", nullptr, (EPropertyFlags)0x0020080000000041, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UK2Node_Action, ShowPinForProperties), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ShowPinForProperties_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ShowPinForProperties_MetaData)) }; // 2088080815
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_Action_Statics::NewProp_CurrentProperties_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/K2Node_Action.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UK2Node_Action_Statics::NewProp_CurrentProperties = { "CurrentProperties", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UK2Node_Action, CurrentProperties), Z_Construct_UScriptStruct_FActionProperties, METADATA_PARAMS(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_CurrentProperties_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_CurrentProperties_MetaData)) }; // 3931715324
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionBlueprint_MetaData[] = {
		{ "Comment", "/** Blueprint that is binded OnCompile */" },
		{ "ModuleRelativePath", "Private/Nodes/K2Node_Action.h" },
		{ "ToolTip", "Blueprint that is binded OnCompile" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionBlueprint = { "ActionBlueprint", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UK2Node_Action, ActionBlueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionBlueprint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionBlueprint_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UK2Node_Action_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK2Node_Action_Statics::NewProp_bShowClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ShowPinForProperties_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ShowPinForProperties,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK2Node_Action_Statics::NewProp_CurrentProperties,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UK2Node_Action_Statics::NewProp_ActionBlueprint,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UK2Node_Action_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UK2Node_Action>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UK2Node_Action_Statics::ClassParams = {
		&UK2Node_Action::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UK2Node_Action_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_Action_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UK2Node_Action_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UK2Node_Action_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UK2Node_Action()
	{
		if (!Z_Registration_Info_UClass_UK2Node_Action.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UK2Node_Action.OuterSingleton, Z_Construct_UClass_UK2Node_Action_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UK2Node_Action.OuterSingleton;
	}
	template<> ACTIONSEDITOR_API UClass* StaticClass<UK2Node_Action>()
	{
		return UK2Node_Action::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UK2Node_Action);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_K2Node_Action_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_K2Node_Action_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UK2Node_Action, UK2Node_Action::StaticClass, TEXT("UK2Node_Action"), &Z_Registration_Info_UClass_UK2Node_Action, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UK2Node_Action), 3283837113U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_K2Node_Action_h_1442384991(TEXT("/Script/ActionsEditor"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_K2Node_Action_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_K2Node_Action_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActionsEditor/Private/Nodes/ActionReflection.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActionReflection() {}
// Cross Module References
	ACTIONSEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FBaseActionProperty();
	UPackage* Z_Construct_UPackage__Script_ActionsEditor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FEdGraphPinType();
	ACTIONSEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FDelegateActionProperty();
	ACTIONSEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FVariableActionProperty();
	ACTIONSEDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FActionProperties();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_BaseActionProperty;
class UScriptStruct* FBaseActionProperty::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_BaseActionProperty.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_BaseActionProperty.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBaseActionProperty, Z_Construct_UPackage__Script_ActionsEditor(), TEXT("BaseActionProperty"));
	}
	return Z_Registration_Info_UScriptStruct_BaseActionProperty.OuterSingleton;
}
template<> ACTIONSEDITOR_API UScriptStruct* StaticStruct<FBaseActionProperty>()
{
	return FBaseActionProperty::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FBaseActionProperty_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Property_MetaData[];
#endif
		static const UECodeGen_Private::FFieldPathPropertyParams NewProp_Property;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Type;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBaseActionProperty_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBaseActionProperty>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Property_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	const UECodeGen_Private::FFieldPathPropertyParams Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Property = { "Property", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::FieldPath, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBaseActionProperty, Property), &FProperty::StaticClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Property_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Property_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBaseActionProperty, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Type_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBaseActionProperty, Type), Z_Construct_UScriptStruct_FEdGraphPinType, METADATA_PARAMS(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Type_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Type_MetaData)) }; // 824835303
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBaseActionProperty_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Property,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewProp_Type,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBaseActionProperty_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ActionsEditor,
		nullptr,
		&NewStructOps,
		"BaseActionProperty",
		sizeof(FBaseActionProperty),
		alignof(FBaseActionProperty),
		Z_Construct_UScriptStruct_FBaseActionProperty_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBaseActionProperty_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FBaseActionProperty()
	{
		if (!Z_Registration_Info_UScriptStruct_BaseActionProperty.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_BaseActionProperty.InnerSingleton, Z_Construct_UScriptStruct_FBaseActionProperty_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_BaseActionProperty.InnerSingleton;
	}

static_assert(std::is_polymorphic<FDelegateActionProperty>() == std::is_polymorphic<FBaseActionProperty>(), "USTRUCT FDelegateActionProperty cannot be polymorphic unless super FBaseActionProperty is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DelegateActionProperty;
class UScriptStruct* FDelegateActionProperty::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DelegateActionProperty.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DelegateActionProperty.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDelegateActionProperty, Z_Construct_UPackage__Script_ActionsEditor(), TEXT("DelegateActionProperty"));
	}
	return Z_Registration_Info_UScriptStruct_DelegateActionProperty.OuterSingleton;
}
template<> ACTIONSEDITOR_API UScriptStruct* StaticStruct<FDelegateActionProperty>()
{
	return FDelegateActionProperty::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDelegateActionProperty_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDelegateActionProperty_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDelegateActionProperty_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDelegateActionProperty>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDelegateActionProperty_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ActionsEditor,
		Z_Construct_UScriptStruct_FBaseActionProperty,
		&NewStructOps,
		"DelegateActionProperty",
		sizeof(FDelegateActionProperty),
		alignof(FDelegateActionProperty),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FDelegateActionProperty_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDelegateActionProperty_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FDelegateActionProperty()
	{
		if (!Z_Registration_Info_UScriptStruct_DelegateActionProperty.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DelegateActionProperty.InnerSingleton, Z_Construct_UScriptStruct_FDelegateActionProperty_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DelegateActionProperty.InnerSingleton;
	}

static_assert(std::is_polymorphic<FVariableActionProperty>() == std::is_polymorphic<FBaseActionProperty>(), "USTRUCT FVariableActionProperty cannot be polymorphic unless super FBaseActionProperty is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VariableActionProperty;
class UScriptStruct* FVariableActionProperty::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VariableActionProperty.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VariableActionProperty.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVariableActionProperty, Z_Construct_UPackage__Script_ActionsEditor(), TEXT("VariableActionProperty"));
	}
	return Z_Registration_Info_UScriptStruct_VariableActionProperty.OuterSingleton;
}
template<> ACTIONSEDITOR_API UScriptStruct* StaticStruct<FVariableActionProperty>()
{
	return FVariableActionProperty::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVariableActionProperty_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVariableActionProperty_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVariableActionProperty_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVariableActionProperty>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVariableActionProperty_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ActionsEditor,
		Z_Construct_UScriptStruct_FBaseActionProperty,
		&NewStructOps,
		"VariableActionProperty",
		sizeof(FVariableActionProperty),
		alignof(FVariableActionProperty),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVariableActionProperty_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVariableActionProperty_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVariableActionProperty()
	{
		if (!Z_Registration_Info_UScriptStruct_VariableActionProperty.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VariableActionProperty.InnerSingleton, Z_Construct_UScriptStruct_FVariableActionProperty_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VariableActionProperty.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ActionProperties;
class UScriptStruct* FActionProperties::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ActionProperties.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ActionProperties.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActionProperties, Z_Construct_UPackage__Script_ActionsEditor(), TEXT("ActionProperties"));
	}
	return Z_Registration_Info_UScriptStruct_ActionProperties.OuterSingleton;
}
template<> ACTIONSEDITOR_API UScriptStruct* StaticStruct<FActionProperties>()
{
	return FActionProperties::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FActionProperties_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Variables_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Variables_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_Variables;
		static const UECodeGen_Private::FStructPropertyParams NewProp_SimpleDelegates_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SimpleDelegates_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_SimpleDelegates;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ComplexDelegates_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComplexDelegates_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_ComplexDelegates;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionProperties_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FActionProperties_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActionProperties>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_Variables_ElementProp = { "Variables", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVariableActionProperty, METADATA_PARAMS(nullptr, 0) }; // 3750082916
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_Variables_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	static_assert(TModels<CGetTypeHashable, FVariableActionProperty>::Value, "The structure 'FVariableActionProperty' is used in a TSet but does not have a GetValueTypeHash defined");
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_Variables = { "Variables", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActionProperties, Variables), METADATA_PARAMS(Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_Variables_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_Variables_MetaData)) }; // 3750082916
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_SimpleDelegates_ElementProp = { "SimpleDelegates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FDelegateActionProperty, METADATA_PARAMS(nullptr, 0) }; // 1001912983
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_SimpleDelegates_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	static_assert(TModels<CGetTypeHashable, FDelegateActionProperty>::Value, "The structure 'FDelegateActionProperty' is used in a TSet but does not have a GetValueTypeHash defined");
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_SimpleDelegates = { "SimpleDelegates", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActionProperties, SimpleDelegates), METADATA_PARAMS(Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_SimpleDelegates_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_SimpleDelegates_MetaData)) }; // 1001912983
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_ComplexDelegates_ElementProp = { "ComplexDelegates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FDelegateActionProperty, METADATA_PARAMS(nullptr, 0) }; // 1001912983
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_ComplexDelegates_MetaData[] = {
		{ "ModuleRelativePath", "Private/Nodes/ActionReflection.h" },
	};
#endif
	static_assert(TModels<CGetTypeHashable, FDelegateActionProperty>::Value, "The structure 'FDelegateActionProperty' is used in a TSet but does not have a GetValueTypeHash defined");
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_ComplexDelegates = { "ComplexDelegates", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActionProperties, ComplexDelegates), METADATA_PARAMS(Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_ComplexDelegates_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_ComplexDelegates_MetaData)) }; // 1001912983
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActionProperties_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_Variables_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_Variables,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_SimpleDelegates_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_SimpleDelegates,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_ComplexDelegates_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActionProperties_Statics::NewProp_ComplexDelegates,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActionProperties_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ActionsEditor,
		nullptr,
		&NewStructOps,
		"ActionProperties",
		sizeof(FActionProperties),
		alignof(FActionProperties),
		Z_Construct_UScriptStruct_FActionProperties_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionProperties_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FActionProperties_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActionProperties_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FActionProperties()
	{
		if (!Z_Registration_Info_UScriptStruct_ActionProperties.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ActionProperties.InnerSingleton, Z_Construct_UScriptStruct_FActionProperties_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ActionProperties.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_ActionReflection_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_ActionReflection_h_Statics::ScriptStructInfo[] = {
		{ FBaseActionProperty::StaticStruct, Z_Construct_UScriptStruct_FBaseActionProperty_Statics::NewStructOps, TEXT("BaseActionProperty"), &Z_Registration_Info_UScriptStruct_BaseActionProperty, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBaseActionProperty), 3109255192U) },
		{ FDelegateActionProperty::StaticStruct, Z_Construct_UScriptStruct_FDelegateActionProperty_Statics::NewStructOps, TEXT("DelegateActionProperty"), &Z_Registration_Info_UScriptStruct_DelegateActionProperty, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDelegateActionProperty), 1001912983U) },
		{ FVariableActionProperty::StaticStruct, Z_Construct_UScriptStruct_FVariableActionProperty_Statics::NewStructOps, TEXT("VariableActionProperty"), &Z_Registration_Info_UScriptStruct_VariableActionProperty, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVariableActionProperty), 3750082916U) },
		{ FActionProperties::StaticStruct, Z_Construct_UScriptStruct_FActionProperties_Statics::NewStructOps, TEXT("ActionProperties"), &Z_Registration_Info_UScriptStruct_ActionProperties, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActionProperties), 3931715324U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_ActionReflection_h_2635203637(TEXT("/Script/ActionsEditor"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_ActionReflection_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_ActionsEditor_Private_Nodes_ActionReflection_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaWorld/Public/OmegaWorldSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaWorldSettings() {}
// Cross Module References
	OMEGAWORLD_API UScriptStruct* Z_Construct_UScriptStruct_FOmegaZoneData();
	UPackage* Z_Construct_UPackage__Script_OmegaWorld();
	OMEGAWORLD_API UClass* Z_Construct_UClass_AOmegaWorldSettings_NoRegister();
	OMEGAWORLD_API UClass* Z_Construct_UClass_AOmegaWorldSettings();
	ENGINE_API UClass* Z_Construct_UClass_AWorldSettings();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OmegaZoneData;
class UScriptStruct* FOmegaZoneData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OmegaZoneData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OmegaZoneData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOmegaZoneData, Z_Construct_UPackage__Script_OmegaWorld(), TEXT("OmegaZoneData"));
	}
	return Z_Registration_Info_UScriptStruct_OmegaZoneData.OuterSingleton;
}
template<> OMEGAWORLD_API UScriptStruct* StaticStruct<FOmegaZoneData>()
{
	return FOmegaZoneData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOmegaZoneData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FNamePropertyParams NewProp_StreamLevels_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StreamLevels_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_StreamLevels;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaZoneData_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "ModuleRelativePath", "Public/OmegaWorldSettings.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOmegaZoneData>();
	}
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewProp_StreamLevels_Inner = { "StreamLevels", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewProp_StreamLevels_MetaData[] = {
		{ "Category", "\xce\xa9|World" },
		{ "ModuleRelativePath", "Public/OmegaWorldSettings.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewProp_StreamLevels = { "StreamLevels", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOmegaZoneData, StreamLevels), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewProp_StreamLevels_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewProp_StreamLevels_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOmegaZoneData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewProp_StreamLevels_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewProp_StreamLevels,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOmegaZoneData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaWorld,
		nullptr,
		&NewStructOps,
		"OmegaZoneData",
		sizeof(FOmegaZoneData),
		alignof(FOmegaZoneData),
		Z_Construct_UScriptStruct_FOmegaZoneData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaZoneData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaZoneData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaZoneData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FOmegaZoneData()
	{
		if (!Z_Registration_Info_UScriptStruct_OmegaZoneData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OmegaZoneData.InnerSingleton, Z_Construct_UScriptStruct_FOmegaZoneData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OmegaZoneData.InnerSingleton;
	}
	void AOmegaWorldSettings::StaticRegisterNativesAOmegaWorldSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOmegaWorldSettings);
	UClass* Z_Construct_UClass_AOmegaWorldSettings_NoRegister()
	{
		return AOmegaWorldSettings::StaticClass();
	}
	struct Z_Construct_UClass_AOmegaWorldSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Zones_ValueProp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Zones_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Zones_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Zones;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOmegaWorldSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWorldSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaWorld,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaWorldSettings_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Actor Advanced Display Events Object Attachment Info Input Blueprint Layers Tags Replication Input Movement Collision Transformation HLOD DataLayers" },
		{ "IncludePath", "OmegaWorldSettings.h" },
		{ "ModuleRelativePath", "Public/OmegaWorldSettings.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones_ValueProp = { "Zones", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FOmegaZoneData, METADATA_PARAMS(nullptr, 0) }; // 516042637
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones_Key_KeyProp = { "Zones_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones_MetaData[] = {
		{ "Category", "Zones" },
		{ "ModuleRelativePath", "Public/OmegaWorldSettings.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones = { "Zones", nullptr, (EPropertyFlags)0x0010000000000801, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaWorldSettings, Zones), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones_MetaData)) }; // 802167388 516042637
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOmegaWorldSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaWorldSettings_Statics::NewProp_Zones,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOmegaWorldSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOmegaWorldSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOmegaWorldSettings_Statics::ClassParams = {
		&AOmegaWorldSettings::StaticClass,
		"game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AOmegaWorldSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaWorldSettings_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AOmegaWorldSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaWorldSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOmegaWorldSettings()
	{
		if (!Z_Registration_Info_UClass_AOmegaWorldSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOmegaWorldSettings.OuterSingleton, Z_Construct_UClass_AOmegaWorldSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOmegaWorldSettings.OuterSingleton;
	}
	template<> OMEGAWORLD_API UClass* StaticClass<AOmegaWorldSettings>()
	{
		return AOmegaWorldSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOmegaWorldSettings);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_Statics::ScriptStructInfo[] = {
		{ FOmegaZoneData::StaticStruct, Z_Construct_UScriptStruct_FOmegaZoneData_Statics::NewStructOps, TEXT("OmegaZoneData"), &Z_Registration_Info_UScriptStruct_OmegaZoneData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOmegaZoneData), 516042637U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOmegaWorldSettings, AOmegaWorldSettings::StaticClass, TEXT("AOmegaWorldSettings"), &Z_Registration_Info_UClass_AOmegaWorldSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOmegaWorldSettings), 1420746713U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_14309196(TEXT("/Script/OmegaWorld"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaWorldSettings_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

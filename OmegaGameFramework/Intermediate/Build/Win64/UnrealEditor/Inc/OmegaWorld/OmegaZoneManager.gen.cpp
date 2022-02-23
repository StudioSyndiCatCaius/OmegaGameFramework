// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaWorld/Public/OmegaZoneManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaZoneManager() {}
// Cross Module References
	OMEGAWORLD_API UClass* Z_Construct_UClass_AOmegaZoneManager_NoRegister();
	OMEGAWORLD_API UClass* Z_Construct_UClass_AOmegaZoneManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_OmegaWorld();
	OMEGAWORLD_API UScriptStruct* Z_Construct_UScriptStruct_FOmegaZoneData();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
// End Cross Module References
	void AOmegaZoneManager::StaticRegisterNativesAOmegaZoneManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOmegaZoneManager);
	UClass* Z_Construct_UClass_AOmegaZoneManager_NoRegister()
	{
		return AOmegaZoneManager::StaticClass();
	}
	struct Z_Construct_UClass_AOmegaZoneManager_Statics
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
	UObject* (*const Z_Construct_UClass_AOmegaZoneManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaWorld,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaZoneManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OmegaZoneManager.h" },
		{ "ModuleRelativePath", "Public/OmegaZoneManager.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones_ValueProp = { "Zones", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FOmegaZoneData, METADATA_PARAMS(nullptr, 0) }; // 516042637
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones_Key_KeyProp = { "Zones_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones_MetaData[] = {
		{ "Category", "Zones" },
		{ "ModuleRelativePath", "Public/OmegaZoneManager.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones = { "Zones", nullptr, (EPropertyFlags)0x0010000000000801, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaZoneManager, Zones), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones_MetaData)) }; // 802167388 516042637
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOmegaZoneManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaZoneManager_Statics::NewProp_Zones,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOmegaZoneManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOmegaZoneManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOmegaZoneManager_Statics::ClassParams = {
		&AOmegaZoneManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AOmegaZoneManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaZoneManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AOmegaZoneManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaZoneManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOmegaZoneManager()
	{
		if (!Z_Registration_Info_UClass_AOmegaZoneManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOmegaZoneManager.OuterSingleton, Z_Construct_UClass_AOmegaZoneManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOmegaZoneManager.OuterSingleton;
	}
	template<> OMEGAWORLD_API UClass* StaticClass<AOmegaZoneManager>()
	{
		return AOmegaZoneManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOmegaZoneManager);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaZoneManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaZoneManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOmegaZoneManager, AOmegaZoneManager::StaticClass, TEXT("AOmegaZoneManager"), &Z_Registration_Info_UClass_AOmegaZoneManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOmegaZoneManager), 2887047783U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaZoneManager_h_3538009665(TEXT("/Script/OmegaWorld"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaZoneManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaWorld_Public_OmegaZoneManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

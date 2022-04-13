// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/OmegaGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameMode() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameMode_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplaySystem_NoRegister();
// End Cross Module References
	void AOmegaGameMode::StaticRegisterNativesAOmegaGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOmegaGameMode);
	UClass* Z_Construct_UClass_AOmegaGameMode_NoRegister()
	{
		return AOmegaGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AOmegaGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AutoGameplaySystems_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoGameplaySystems_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AutoGameplaySystems;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOmegaGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Gameplay/OmegaGameMode.h" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AOmegaGameMode_Statics::NewProp_AutoGameplaySystems_Inner = { "AutoGameplaySystems", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameMode_Statics::NewProp_AutoGameplaySystems_MetaData[] = {
		{ "Category", "Classes" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameMode.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOmegaGameMode_Statics::NewProp_AutoGameplaySystems = { "AutoGameplaySystems", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameMode, AutoGameplaySystems), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameMode_Statics::NewProp_AutoGameplaySystems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameMode_Statics::NewProp_AutoGameplaySystems_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOmegaGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameMode_Statics::NewProp_AutoGameplaySystems_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameMode_Statics::NewProp_AutoGameplaySystems,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOmegaGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOmegaGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOmegaGameMode_Statics::ClassParams = {
		&AOmegaGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AOmegaGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AOmegaGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOmegaGameMode()
	{
		if (!Z_Registration_Info_UClass_AOmegaGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOmegaGameMode.OuterSingleton, Z_Construct_UClass_AOmegaGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOmegaGameMode.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<AOmegaGameMode>()
	{
		return AOmegaGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOmegaGameMode);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOmegaGameMode, AOmegaGameMode::StaticClass, TEXT("AOmegaGameMode"), &Z_Registration_Info_UClass_AOmegaGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOmegaGameMode), 2148218986U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameMode_h_776009326(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

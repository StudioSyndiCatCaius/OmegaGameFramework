// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaSettings() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSettings_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSettings();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplaySystem_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftClassPath();
// End Cross Module References
	void UOmegaSettings::StaticRegisterNativesUOmegaSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaSettings);
	UClass* Z_Construct_UClass_UOmegaSettings_NoRegister()
	{
		return UOmegaSettings::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AutoActivatedGameplaySystems_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoActivatedGameplaySystems_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AutoActivatedGameplaySystems;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RegisteredGameplayModules_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RegisteredGameplayModules_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RegisteredGameplayModules;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GameSaveClass_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GameSaveClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SaveGamePrefex_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SaveGamePrefex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobalSaveClass_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GlobalSaveClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobalSaveName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_GlobalSaveName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSettings_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "Omega Game Framework" },
		{ "IncludePath", "OmegaSettings.h" },
		{ "ModuleRelativePath", "Public/OmegaSettings.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_AutoActivatedGameplaySystems_Inner = { "AutoActivatedGameplaySystems", nullptr, (EPropertyFlags)0x0004000000004000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSettings_Statics::NewProp_AutoActivatedGameplaySystems_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaSettings.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_AutoActivatedGameplaySystems = { "AutoActivatedGameplaySystems", nullptr, (EPropertyFlags)0x0014000000004000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSettings, AutoActivatedGameplaySystems), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_AutoActivatedGameplaySystems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_AutoActivatedGameplaySystems_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_RegisteredGameplayModules_Inner = { "RegisteredGameplayModules", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSettings_Statics::NewProp_RegisteredGameplayModules_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "MetaClass", "OmegaGameplayModule" },
		{ "ModuleRelativePath", "Public/OmegaSettings.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_RegisteredGameplayModules = { "RegisteredGameplayModules", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSettings, RegisteredGameplayModules), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_RegisteredGameplayModules_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_RegisteredGameplayModules_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GameSaveClass_MetaData[] = {
		{ "Category", "Save" },
		{ "MetaClass", "OmegaSaveGame" },
		{ "ModuleRelativePath", "Public/OmegaSettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GameSaveClass = { "GameSaveClass", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSettings, GameSaveClass), Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GameSaveClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GameSaveClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSettings_Statics::NewProp_SaveGamePrefex_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/OmegaSettings.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_SaveGamePrefex = { "SaveGamePrefex", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSettings, SaveGamePrefex), METADATA_PARAMS(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_SaveGamePrefex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_SaveGamePrefex_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveClass_MetaData[] = {
		{ "Category", "Save" },
		{ "MetaClass", "OmegaSaveGlobal" },
		{ "ModuleRelativePath", "Public/OmegaSettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveClass = { "GlobalSaveClass", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSettings, GlobalSaveClass), Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveName_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/OmegaSettings.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveName = { "GlobalSaveName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSettings, GlobalSaveName), METADATA_PARAMS(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveName_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_AutoActivatedGameplaySystems_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_AutoActivatedGameplaySystems,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_RegisteredGameplayModules_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_RegisteredGameplayModules,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GameSaveClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_SaveGamePrefex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSettings_Statics::NewProp_GlobalSaveName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaSettings_Statics::ClassParams = {
		&UOmegaSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOmegaSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaSettings()
	{
		if (!Z_Registration_Info_UClass_UOmegaSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaSettings.OuterSingleton, Z_Construct_UClass_UOmegaSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaSettings.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaSettings>()
	{
		return UOmegaSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaSettings);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaSettings, UOmegaSettings::StaticClass, TEXT("UOmegaSettings"), &Z_Registration_Info_UClass_UOmegaSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaSettings), 294495471U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaSettings_h_2818398331(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

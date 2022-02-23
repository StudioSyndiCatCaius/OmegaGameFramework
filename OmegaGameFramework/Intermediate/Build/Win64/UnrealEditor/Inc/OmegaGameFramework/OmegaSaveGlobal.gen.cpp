// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Save/OmegaSaveGlobal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaSaveGlobal() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGlobal_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGlobal();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceBool_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceFloat_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceString_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceTag_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
// End Cross Module References
	void UOmegaSaveGlobal::StaticRegisterNativesUOmegaSaveGlobal()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaSaveGlobal);
	UClass* Z_Construct_UClass_UOmegaSaveGlobal_NoRegister()
	{
		return UOmegaSaveGlobal::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaSaveGlobal_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBoolPropertyParams NewProp_BoolPrefs_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoolPrefs_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoolPrefs_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_BoolPrefs;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FloatPrefs_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FloatPrefs_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FloatPrefs_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_FloatPrefs;
		static const UECodeGen_Private::FStrPropertyParams NewProp_StringPrefs_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StringPrefs_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StringPrefs_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_StringPrefs;
		static const UECodeGen_Private::FStructPropertyParams NewProp_TagPrefs_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TagPrefs_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TagPrefs_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_TagPrefs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobalSaveTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GlobalSaveTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaSaveGlobal_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGlobal_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Save/OmegaSaveGlobal.h" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGlobal.h" },
	};
#endif
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs_ValueProp = { "BoolPrefs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs_Key_KeyProp = { "BoolPrefs_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGamePreferenceBool_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs_MetaData[] = {
		{ "Comment", "//GamePreferences\n" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGlobal.h" },
		{ "ToolTip", "GamePreferences" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs = { "BoolPrefs", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGlobal, BoolPrefs), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs_ValueProp = { "FloatPrefs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs_Key_KeyProp = { "FloatPrefs_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGamePreferenceFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGlobal.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs = { "FloatPrefs", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGlobal, FloatPrefs), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs_ValueProp = { "StringPrefs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs_Key_KeyProp = { "StringPrefs_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGamePreferenceString_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGlobal.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs = { "StringPrefs", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGlobal, StringPrefs), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs_ValueProp = { "TagPrefs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs_Key_KeyProp = { "TagPrefs_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGamePreferenceTag_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGlobal.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs = { "TagPrefs", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGlobal, TagPrefs), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs_MetaData)) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_GlobalSaveTags_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGlobal.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_GlobalSaveTags = { "GlobalSaveTags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGlobal, GlobalSaveTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_GlobalSaveTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_GlobalSaveTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaSaveGlobal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_BoolPrefs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_FloatPrefs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_StringPrefs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_TagPrefs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGlobal_Statics::NewProp_GlobalSaveTags,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaSaveGlobal_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaSaveGlobal>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::ClassParams = {
		&UOmegaSaveGlobal::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOmegaSaveGlobal_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGlobal_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaSaveGlobal()
	{
		if (!Z_Registration_Info_UClass_UOmegaSaveGlobal.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaSaveGlobal.OuterSingleton, Z_Construct_UClass_UOmegaSaveGlobal_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaSaveGlobal.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaSaveGlobal>()
	{
		return UOmegaSaveGlobal::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaSaveGlobal);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaSaveGlobal, UOmegaSaveGlobal::StaticClass, TEXT("UOmegaSaveGlobal"), &Z_Registration_Info_UClass_UOmegaSaveGlobal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaSaveGlobal), 2758477489U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_3141557883(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

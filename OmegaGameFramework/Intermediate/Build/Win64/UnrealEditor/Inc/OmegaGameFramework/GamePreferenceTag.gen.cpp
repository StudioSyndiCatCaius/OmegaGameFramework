// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Preferences/Asset/GamePreferenceTag.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamePreferenceTag() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceTag_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceTag();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreference();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
// End Cross Module References
	void UGamePreferenceTag::StaticRegisterNativesUGamePreferenceTag()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGamePreferenceTag);
	UClass* Z_Construct_UClass_UGamePreferenceTag_NoRegister()
	{
		return UGamePreferenceTag::StaticClass();
	}
	struct Z_Construct_UClass_UGamePreferenceTag_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGamePreferenceTag_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGamePreference,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceTag_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Preferences/Asset/GamePreferenceTag.h" },
		{ "ModuleRelativePath", "Public/Preferences/Asset/GamePreferenceTag.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceTag_Statics::NewProp_DefaultValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/Preferences/Asset/GamePreferenceTag.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGamePreferenceTag_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceTag, DefaultValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceTag_Statics::NewProp_DefaultValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceTag_Statics::NewProp_DefaultValue_MetaData)) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGamePreferenceTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceTag_Statics::NewProp_DefaultValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGamePreferenceTag_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGamePreferenceTag>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGamePreferenceTag_Statics::ClassParams = {
		&UGamePreferenceTag::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGamePreferenceTag_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceTag_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceTag_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceTag_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGamePreferenceTag()
	{
		if (!Z_Registration_Info_UClass_UGamePreferenceTag.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGamePreferenceTag.OuterSingleton, Z_Construct_UClass_UGamePreferenceTag_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGamePreferenceTag.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UGamePreferenceTag>()
	{
		return UGamePreferenceTag::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGamePreferenceTag);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceTag_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceTag_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGamePreferenceTag, UGamePreferenceTag::StaticClass, TEXT("UGamePreferenceTag"), &Z_Registration_Info_UClass_UGamePreferenceTag, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGamePreferenceTag), 3374193829U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceTag_h_910310092(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceTag_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceTag_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

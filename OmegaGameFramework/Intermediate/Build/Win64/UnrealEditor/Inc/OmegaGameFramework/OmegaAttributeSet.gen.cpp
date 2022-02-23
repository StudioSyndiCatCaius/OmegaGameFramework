// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Attributes/OmegaAttributeSet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaAttributeSet() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttributeSet_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttributeSet();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
// End Cross Module References
	void UOmegaAttributeSet::StaticRegisterNativesUOmegaAttributeSet()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaAttributeSet);
	UClass* Z_Construct_UClass_UOmegaAttributeSet_NoRegister()
	{
		return UOmegaAttributeSet::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaAttributeSet_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attributes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Attributes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Attributes;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ValueCategory_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ValueCategory;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaAttributeSet_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttributeSet_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Attributes/OmegaAttributeSet.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaAttributeSet.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_Attributes_Inner = { "Attributes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_Attributes_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaAttributeSet.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_Attributes = { "Attributes", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttributeSet, Attributes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_Attributes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_Attributes_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_ValueCategory_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaAttributeSet.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_ValueCategory = { "ValueCategory", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttributeSet, ValueCategory), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_ValueCategory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_ValueCategory_MetaData)) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaAttributeSet_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_Attributes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_Attributes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttributeSet_Statics::NewProp_ValueCategory,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaAttributeSet_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaAttributeSet>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaAttributeSet_Statics::ClassParams = {
		&UOmegaAttributeSet::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOmegaAttributeSet_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttributeSet_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaAttributeSet_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttributeSet_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaAttributeSet()
	{
		if (!Z_Registration_Info_UClass_UOmegaAttributeSet.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaAttributeSet.OuterSingleton, Z_Construct_UClass_UOmegaAttributeSet_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaAttributeSet.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaAttributeSet>()
	{
		return UOmegaAttributeSet::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaAttributeSet);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaAttributeSet_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaAttributeSet_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaAttributeSet, UOmegaAttributeSet::StaticClass, TEXT("UOmegaAttributeSet"), &Z_Registration_Info_UClass_UOmegaAttributeSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaAttributeSet), 2186431388U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaAttributeSet_h_348493123(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaAttributeSet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaAttributeSet_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/OmegaDamageType.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaDamageType() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaDamageType_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaDamageType();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_General_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGameplayTagsInterface_NoRegister();
// End Cross Module References
	void UOmegaDamageType::StaticRegisterNativesUOmegaDamageType()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaDamageType);
	UClass* Z_Construct_UClass_UOmegaDamageType_NoRegister()
	{
		return UOmegaDamageType::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaDamageType_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Icon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamageModifier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamageModifier;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaDamageType_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaDamageType_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Gameplay/OmegaDamageType.h" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaDamageType.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "//General\n" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaDamageType.h" },
		{ "ToolTip", "General" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaDamageType, Name), METADATA_PARAMS(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaDamageType.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaDamageType, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Icon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Icon_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Color_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaDamageType.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaDamageType, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Color_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_BaseDamageModifier_MetaData[] = {
		{ "Category", "Damage" },
		{ "Comment", "//Damage\n" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaDamageType.h" },
		{ "ToolTip", "Damage" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_BaseDamageModifier = { "BaseDamageModifier", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaDamageType, BaseDamageModifier), METADATA_PARAMS(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_BaseDamageModifier_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_BaseDamageModifier_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaDamageType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Icon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_Color,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaDamageType_Statics::NewProp_BaseDamageModifier,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UOmegaDamageType_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UDataInterface_General_NoRegister, (int32)VTABLE_OFFSET(UOmegaDamageType, IDataInterface_General), false },  // 1389727800
			{ Z_Construct_UClass_UGameplayTagsInterface_NoRegister, (int32)VTABLE_OFFSET(UOmegaDamageType, IGameplayTagsInterface), false },  // 2162780125
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaDamageType_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaDamageType>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaDamageType_Statics::ClassParams = {
		&UOmegaDamageType::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOmegaDamageType_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaDamageType_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaDamageType_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaDamageType_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaDamageType()
	{
		if (!Z_Registration_Info_UClass_UOmegaDamageType.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaDamageType.OuterSingleton, Z_Construct_UClass_UOmegaDamageType_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaDamageType.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaDamageType>()
	{
		return UOmegaDamageType::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaDamageType);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaDamageType_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaDamageType_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaDamageType, UOmegaDamageType::StaticClass, TEXT("UOmegaDamageType"), &Z_Registration_Info_UClass_UOmegaDamageType, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaDamageType), 1332814777U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaDamageType_h_1326773285(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaDamageType_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaDamageType_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

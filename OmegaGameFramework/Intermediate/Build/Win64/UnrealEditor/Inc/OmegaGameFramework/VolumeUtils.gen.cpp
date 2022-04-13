// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/VolumeUtils.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVolumeUtils() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EVolumeShape();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FVolumeSphereData();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FVolumeBoxData();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EVolumeShape;
	static UEnum* EVolumeShape_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EVolumeShape.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EVolumeShape.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OmegaGameFramework_EVolumeShape, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("EVolumeShape"));
		}
		return Z_Registration_Info_UEnum_EVolumeShape.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EVolumeShape>()
	{
		return EVolumeShape_StaticEnum();
	}
	struct Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::Enumerators[] = {
		{ "EVolumeShape::OmegaVolume_Sphere", (int64)EVolumeShape::OmegaVolume_Sphere },
		{ "EVolumeShape::OmegaVolume_Box", (int64)EVolumeShape::OmegaVolume_Box },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
		{ "OmegaVolume_Box.Comment", "/** Description. */" },
		{ "OmegaVolume_Box.DisplayName", "Box" },
		{ "OmegaVolume_Box.Name", "EVolumeShape::OmegaVolume_Box" },
		{ "OmegaVolume_Box.ToolTip", "Description." },
		{ "OmegaVolume_Sphere.Comment", "/** Description. */" },
		{ "OmegaVolume_Sphere.DisplayName", "Sphere" },
		{ "OmegaVolume_Sphere.Name", "EVolumeShape::OmegaVolume_Sphere" },
		{ "OmegaVolume_Sphere.ToolTip", "Description." },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		"EVolumeShape",
		"EVolumeShape",
		Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_OmegaGameFramework_EVolumeShape()
	{
		if (!Z_Registration_Info_UEnum_EVolumeShape.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EVolumeShape.InnerSingleton, Z_Construct_UEnum_OmegaGameFramework_EVolumeShape_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EVolumeShape.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VolumeSphereData;
class UScriptStruct* FVolumeSphereData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VolumeSphereData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VolumeSphereData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVolumeSphereData, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("VolumeSphereData"));
	}
	return Z_Registration_Info_UScriptStruct_VolumeSphereData.OuterSingleton;
}
template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<FVolumeSphereData>()
{
	return FVolumeSphereData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVolumeSphereData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VolumeName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_VolumeName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeSphereData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVolumeSphereData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_VolumeName_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_VolumeName = { "VolumeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVolumeSphereData, VolumeName), METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_VolumeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_VolumeName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_WorldLocation_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVolumeSphereData, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_WorldLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_WorldLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVolumeSphereData, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_Radius_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVolumeSphereData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_VolumeName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_WorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewProp_Radius,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVolumeSphereData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		&NewStructOps,
		"VolumeSphereData",
		sizeof(FVolumeSphereData),
		alignof(FVolumeSphereData),
		Z_Construct_UScriptStruct_FVolumeSphereData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeSphereData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVolumeSphereData()
	{
		if (!Z_Registration_Info_UScriptStruct_VolumeSphereData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VolumeSphereData.InnerSingleton, Z_Construct_UScriptStruct_FVolumeSphereData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VolumeSphereData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VolumeBoxData;
class UScriptStruct* FVolumeBoxData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VolumeBoxData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VolumeBoxData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVolumeBoxData, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("VolumeBoxData"));
	}
	return Z_Registration_Info_UScriptStruct_VolumeBoxData.OuterSingleton;
}
template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<FVolumeBoxData>()
{
	return FVolumeBoxData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVolumeBoxData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VolumeName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_VolumeName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoxExtent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_BoxExtent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeBoxData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVolumeBoxData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_VolumeName_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_VolumeName = { "VolumeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVolumeBoxData, VolumeName), METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_VolumeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_VolumeName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldLocation_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVolumeBoxData, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldRotation_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldRotation = { "WorldRotation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVolumeBoxData, WorldRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldRotation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_BoxExtent_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/VolumeUtils.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_BoxExtent = { "BoxExtent", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVolumeBoxData, BoxExtent), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_BoxExtent_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_BoxExtent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVolumeBoxData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_VolumeName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_WorldRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewProp_BoxExtent,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVolumeBoxData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		&NewStructOps,
		"VolumeBoxData",
		sizeof(FVolumeBoxData),
		alignof(FVolumeBoxData),
		Z_Construct_UScriptStruct_FVolumeBoxData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVolumeBoxData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVolumeBoxData()
	{
		if (!Z_Registration_Info_UScriptStruct_VolumeBoxData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VolumeBoxData.InnerSingleton, Z_Construct_UScriptStruct_FVolumeBoxData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VolumeBoxData.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_Statics::EnumInfo[] = {
		{ EVolumeShape_StaticEnum, TEXT("EVolumeShape"), &Z_Registration_Info_UEnum_EVolumeShape, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2098034709U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_Statics::ScriptStructInfo[] = {
		{ FVolumeSphereData::StaticStruct, Z_Construct_UScriptStruct_FVolumeSphereData_Statics::NewStructOps, TEXT("VolumeSphereData"), &Z_Registration_Info_UScriptStruct_VolumeSphereData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVolumeSphereData), 3881269417U) },
		{ FVolumeBoxData::StaticStruct, Z_Construct_UScriptStruct_FVolumeBoxData_Statics::NewStructOps, TEXT("VolumeBoxData"), &Z_Registration_Info_UScriptStruct_VolumeBoxData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVolumeBoxData), 3591652611U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_2441919010(TEXT("/Script/OmegaGameFramework"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

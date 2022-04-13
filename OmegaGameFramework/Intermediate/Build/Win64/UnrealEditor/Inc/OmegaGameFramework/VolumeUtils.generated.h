// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OMEGAGAMEFRAMEWORK_VolumeUtils_generated_h
#error "VolumeUtils.generated.h already included, missing '#pragma once' in VolumeUtils.h"
#endif
#define OMEGAGAMEFRAMEWORK_VolumeUtils_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVolumeSphereData_Statics; \
	OMEGAGAMEFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<struct FVolumeSphereData>();

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h_39_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVolumeBoxData_Statics; \
	OMEGAGAMEFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<struct FVolumeBoxData>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_VolumeUtils_h


#define FOREACH_ENUM_EVOLUMESHAPE(op) \
	op(EVolumeShape::OmegaVolume_Sphere) \
	op(EVolumeShape::OmegaVolume_Box) 

enum class EVolumeShape : uint8;
template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EVolumeShape>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

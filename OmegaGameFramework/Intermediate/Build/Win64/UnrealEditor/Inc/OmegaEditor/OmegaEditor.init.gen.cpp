// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaEditor_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_OmegaEditor;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_OmegaEditor()
	{
		if (!Z_Registration_Info_UPackage__Script_OmegaEditor.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/OmegaEditor",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000040,
				0x129D4979,
				0x6A424FE6,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_OmegaEditor.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_OmegaEditor.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_OmegaEditor(Z_Construct_UPackage__Script_OmegaEditor, TEXT("/Script/OmegaEditor"), Z_Registration_Info_UPackage__Script_OmegaEditor, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x129D4979, 0x6A424FE6));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

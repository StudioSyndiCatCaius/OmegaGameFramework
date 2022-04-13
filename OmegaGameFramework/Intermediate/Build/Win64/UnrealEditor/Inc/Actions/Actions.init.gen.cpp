// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActions_init() {}
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature();
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature();
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature();
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Actions;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Actions()
	{
		if (!Z_Registration_Info_UPackage__Script_Actions.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Actions",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x03B94DA9,
				0xFDCF964A,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Actions.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Actions.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Actions(Z_Construct_UPackage__Script_Actions, TEXT("/Script/Actions"), Z_Registration_Info_UPackage__Script_Actions, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x03B94DA9, 0xFDCF964A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

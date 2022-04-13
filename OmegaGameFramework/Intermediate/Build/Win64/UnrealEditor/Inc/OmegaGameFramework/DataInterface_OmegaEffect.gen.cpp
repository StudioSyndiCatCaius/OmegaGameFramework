// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/DataInterface_OmegaEffect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataInterface_OmegaEffect() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_OmegaEffect_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_OmegaEffect();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FOmegaEffectContainer();
// End Cross Module References
	DEFINE_FUNCTION(IDataInterface_OmegaEffect::execGetOmegaEffects)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FOmegaEffectContainer>*)Z_Param__Result=P_THIS->GetOmegaEffects_Implementation();
		P_NATIVE_END;
	}
	TArray<FOmegaEffectContainer> IDataInterface_OmegaEffect::GetOmegaEffects()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetOmegaEffects instead.");
		DataInterface_OmegaEffect_eventGetOmegaEffects_Parms Parms;
		return Parms.ReturnValue;
	}
	void UDataInterface_OmegaEffect::StaticRegisterNativesUDataInterface_OmegaEffect()
	{
		UClass* Class = UDataInterface_OmegaEffect::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetOmegaEffects", &IDataInterface_OmegaEffect::execGetOmegaEffects },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FOmegaEffectContainer, METADATA_PARAMS(nullptr, 0) }; // 158265011
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_OmegaEffect_eventGetOmegaEffects_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 158265011
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_OmegaEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_OmegaEffect, nullptr, "GetOmegaEffects", nullptr, nullptr, sizeof(DataInterface_OmegaEffect_eventGetOmegaEffects_Parms), Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataInterface_OmegaEffect);
	UClass* Z_Construct_UClass_UDataInterface_OmegaEffect_NoRegister()
	{
		return UDataInterface_OmegaEffect::StaticClass();
	}
	struct Z_Construct_UClass_UDataInterface_OmegaEffect_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataInterface_OmegaEffect_GetOmegaEffects, "GetOmegaEffects" }, // 197671964
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_OmegaEffect.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDataInterface_OmegaEffect>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::ClassParams = {
		&UDataInterface_OmegaEffect::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000040A1u,
		METADATA_PARAMS(Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataInterface_OmegaEffect()
	{
		if (!Z_Registration_Info_UClass_UDataInterface_OmegaEffect.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataInterface_OmegaEffect.OuterSingleton, Z_Construct_UClass_UDataInterface_OmegaEffect_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataInterface_OmegaEffect.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataInterface_OmegaEffect>()
	{
		return UDataInterface_OmegaEffect::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataInterface_OmegaEffect);
	static FName NAME_UDataInterface_OmegaEffect_GetOmegaEffects = FName(TEXT("GetOmegaEffects"));
	TArray<FOmegaEffectContainer> IDataInterface_OmegaEffect::Execute_GetOmegaEffects(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_OmegaEffect::StaticClass()));
		DataInterface_OmegaEffect_eventGetOmegaEffects_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_OmegaEffect_GetOmegaEffects);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IDataInterface_OmegaEffect*)(O->GetNativeInterfaceAddress(UDataInterface_OmegaEffect::StaticClass())))
		{
			Parms.ReturnValue = I->GetOmegaEffects_Implementation();
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataInterface_OmegaEffect, UDataInterface_OmegaEffect::StaticClass, TEXT("UDataInterface_OmegaEffect"), &Z_Registration_Info_UClass_UDataInterface_OmegaEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataInterface_OmegaEffect), 4246368782U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_1339445892(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

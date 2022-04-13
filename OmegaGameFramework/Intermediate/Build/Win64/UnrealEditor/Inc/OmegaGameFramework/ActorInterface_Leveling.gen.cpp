// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Attributes/ActorInterface_Leveling.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorInterface_Leveling() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UActorInterface_Leveling_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UActorInterface_Leveling();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
// End Cross Module References
	DEFINE_FUNCTION(IActorInterface_Leveling::execGetXPRateOffset)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetXPRateOffset_Implementation();
		P_NATIVE_END;
	}
	float IActorInterface_Leveling::GetXPRateOffset()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetXPRateOffset instead.");
		ActorInterface_Leveling_eventGetXPRateOffset_Parms Parms;
		return Parms.ReturnValue;
	}
	void UActorInterface_Leveling::StaticRegisterNativesUActorInterface_Leveling()
	{
		UClass* Class = UActorInterface_Leveling::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetXPRateOffset", &IActorInterface_Leveling::execGetXPRateOffset },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_Leveling_eventGetXPRateOffset_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Leveling" },
		{ "Comment", "//Adds to the base XpRate value.\n" },
		{ "ModuleRelativePath", "Public/Attributes/ActorInterface_Leveling.h" },
		{ "ToolTip", "Adds to the base XpRate value." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActorInterface_Leveling, nullptr, "GetXPRateOffset", nullptr, nullptr, sizeof(ActorInterface_Leveling_eventGetXPRateOffset_Parms), Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UActorInterface_Leveling);
	UClass* Z_Construct_UClass_UActorInterface_Leveling_NoRegister()
	{
		return UActorInterface_Leveling::StaticClass();
	}
	struct Z_Construct_UClass_UActorInterface_Leveling_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActorInterface_Leveling_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UActorInterface_Leveling_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UActorInterface_Leveling_GetXPRateOffset, "GetXPRateOffset" }, // 2153143035
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorInterface_Leveling_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Attributes/ActorInterface_Leveling.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActorInterface_Leveling_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IActorInterface_Leveling>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UActorInterface_Leveling_Statics::ClassParams = {
		&UActorInterface_Leveling::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UActorInterface_Leveling_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActorInterface_Leveling_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActorInterface_Leveling()
	{
		if (!Z_Registration_Info_UClass_UActorInterface_Leveling.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActorInterface_Leveling.OuterSingleton, Z_Construct_UClass_UActorInterface_Leveling_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UActorInterface_Leveling.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UActorInterface_Leveling>()
	{
		return UActorInterface_Leveling::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActorInterface_Leveling);
	static FName NAME_UActorInterface_Leveling_GetXPRateOffset = FName(TEXT("GetXPRateOffset"));
	float IActorInterface_Leveling::Execute_GetXPRateOffset(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UActorInterface_Leveling::StaticClass()));
		ActorInterface_Leveling_eventGetXPRateOffset_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UActorInterface_Leveling_GetXPRateOffset);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IActorInterface_Leveling*)(O->GetNativeInterfaceAddress(UActorInterface_Leveling::StaticClass())))
		{
			Parms.ReturnValue = I->GetXPRateOffset_Implementation();
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UActorInterface_Leveling, UActorInterface_Leveling::StaticClass, TEXT("UActorInterface_Leveling"), &Z_Registration_Info_UClass_UActorInterface_Leveling, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActorInterface_Leveling), 3053447598U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_562415348(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

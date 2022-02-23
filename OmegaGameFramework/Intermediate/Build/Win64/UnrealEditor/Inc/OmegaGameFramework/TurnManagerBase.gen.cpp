// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/TurnBased/TurnManagerBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTurnManagerBase() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UTurnManagerBase_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UTurnManagerBase();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
// End Cross Module References
	static FName NAME_UTurnManagerBase_ShouldTargetActFirst = FName(TEXT("ShouldTargetActFirst"));
	bool UTurnManagerBase::ShouldTargetActFirst(UCombatantComponent* TargetCombatant, UCombatantComponent* ComparedCombatant)
	{
		TurnManagerBase_eventShouldTargetActFirst_Parms Parms;
		Parms.TargetCombatant=TargetCombatant;
		Parms.ComparedCombatant=ComparedCombatant;
		ProcessEvent(FindFunctionChecked(NAME_UTurnManagerBase_ShouldTargetActFirst),&Parms);
		return !!Parms.ReturnValue;
	}
	void UTurnManagerBase::StaticRegisterNativesUTurnManagerBase()
	{
	}
	struct Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetCombatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetCombatant;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComparedCombatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ComparedCombatant;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_TargetCombatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_TargetCombatant = { "TargetCombatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnManagerBase_eventShouldTargetActFirst_Parms, TargetCombatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_TargetCombatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_TargetCombatant_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ComparedCombatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ComparedCombatant = { "ComparedCombatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnManagerBase_eventShouldTargetActFirst_Parms, ComparedCombatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ComparedCombatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ComparedCombatant_MetaData)) };
	void Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TurnManagerBase_eventShouldTargetActFirst_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(TurnManagerBase_eventShouldTargetActFirst_Parms), &Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_TargetCombatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ComparedCombatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnManagerBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnManagerBase, nullptr, "ShouldTargetActFirst", nullptr, nullptr, sizeof(TurnManagerBase_eventShouldTargetActFirst_Parms), Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTurnManagerBase);
	UClass* Z_Construct_UClass_UTurnManagerBase_NoRegister()
	{
		return UTurnManagerBase::StaticClass();
	}
	struct Z_Construct_UClass_UTurnManagerBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTurnManagerBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UTurnManagerBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UTurnManagerBase_ShouldTargetActFirst, "ShouldTargetActFirst" }, // 202032394
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnManagerBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n* \n*/" },
		{ "IncludePath", "Gameplay/TurnBased/TurnManagerBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnManagerBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTurnManagerBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTurnManagerBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTurnManagerBase_Statics::ClassParams = {
		&UTurnManagerBase::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTurnManagerBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnManagerBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTurnManagerBase()
	{
		if (!Z_Registration_Info_UClass_UTurnManagerBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTurnManagerBase.OuterSingleton, Z_Construct_UClass_UTurnManagerBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTurnManagerBase.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UTurnManagerBase>()
	{
		return UTurnManagerBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTurnManagerBase);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTurnManagerBase, UTurnManagerBase::StaticClass, TEXT("UTurnManagerBase"), &Z_Registration_Info_UClass_UTurnManagerBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTurnManagerBase), 450241519U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_1056142274(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

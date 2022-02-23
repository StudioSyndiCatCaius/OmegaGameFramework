// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Widget/WidgetInterface_Combatant.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWidgetInterface_Combatant() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UWidgetInterface_Combatant_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UWidgetInterface_Combatant();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IWidgetInterface_Combatant::execGetAttributeProgressBar)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_OBJECT_REF(UProgressBar,Z_Param_Out_ProgressBar);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAttributeProgressBar_Implementation(Z_Param_Attribute,Z_Param_Out_ProgressBar);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_Combatant::execGetAttributeTexts)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_OBJECT_REF(UTextBlock,Z_Param_Out_CurrentValue);
		P_GET_OBJECT_REF(UTextBlock,Z_Param_Out_MaxValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAttributeTexts_Implementation(Z_Param_Attribute,Z_Param_Out_CurrentValue,Z_Param_Out_MaxValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_Combatant::execGetCombatantComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCombatantComponent**)Z_Param__Result=P_THIS->GetCombatantComponent_Implementation();
		P_NATIVE_END;
	}
	void IWidgetInterface_Combatant::GetAttributeProgressBar(UOmegaAttribute* Attribute, UProgressBar*& ProgressBar)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetAttributeProgressBar instead.");
	}
	void IWidgetInterface_Combatant::GetAttributeTexts(UOmegaAttribute* Attribute, UTextBlock*& CurrentValue, UTextBlock*& MaxValue)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetAttributeTexts instead.");
	}
	UCombatantComponent* IWidgetInterface_Combatant::GetCombatantComponent()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetCombatantComponent instead.");
		WidgetInterface_Combatant_eventGetCombatantComponent_Parms Parms;
		return Parms.ReturnValue;
	}
	void UWidgetInterface_Combatant::StaticRegisterNativesUWidgetInterface_Combatant()
	{
		UClass* Class = UWidgetInterface_Combatant::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAttributeProgressBar", &IWidgetInterface_Combatant::execGetAttributeProgressBar },
			{ "GetAttributeTexts", &IWidgetInterface_Combatant::execGetAttributeTexts },
			{ "GetCombatantComponent", &IWidgetInterface_Combatant::execGetCombatantComponent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProgressBar_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProgressBar;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Combatant_eventGetAttributeProgressBar_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::NewProp_ProgressBar_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::NewProp_ProgressBar = { "ProgressBar", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Combatant_eventGetAttributeProgressBar_Parms, ProgressBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::NewProp_ProgressBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::NewProp_ProgressBar_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::NewProp_ProgressBar,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Combatant" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Combatant, nullptr, "GetAttributeProgressBar", nullptr, nullptr, sizeof(WidgetInterface_Combatant_eventGetAttributeProgressBar_Parms), Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MaxValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Combatant_eventGetAttributeTexts_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_CurrentValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_CurrentValue = { "CurrentValue", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Combatant_eventGetAttributeTexts_Parms, CurrentValue), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_CurrentValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_CurrentValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_MaxValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_MaxValue = { "MaxValue", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Combatant_eventGetAttributeTexts_Parms, MaxValue), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_MaxValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_MaxValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_CurrentValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::NewProp_MaxValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Combatant" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Combatant, nullptr, "GetAttributeTexts", nullptr, nullptr, sizeof(WidgetInterface_Combatant_eventGetAttributeTexts_Parms), Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Combatant_eventGetCombatantComponent_Parms, ReturnValue), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Combatant" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Combatant, nullptr, "GetCombatantComponent", nullptr, nullptr, sizeof(WidgetInterface_Combatant_eventGetCombatantComponent_Parms), Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWidgetInterface_Combatant);
	UClass* Z_Construct_UClass_UWidgetInterface_Combatant_NoRegister()
	{
		return UWidgetInterface_Combatant::StaticClass();
	}
	struct Z_Construct_UClass_UWidgetInterface_Combatant_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWidgetInterface_Combatant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UWidgetInterface_Combatant_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeProgressBar, "GetAttributeProgressBar" }, // 2320965606
		{ &Z_Construct_UFunction_UWidgetInterface_Combatant_GetAttributeTexts, "GetAttributeTexts" }, // 1597443356
		{ &Z_Construct_UFunction_UWidgetInterface_Combatant_GetCombatantComponent, "GetCombatantComponent" }, // 1348288469
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWidgetInterface_Combatant_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Combatant.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWidgetInterface_Combatant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IWidgetInterface_Combatant>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UWidgetInterface_Combatant_Statics::ClassParams = {
		&UWidgetInterface_Combatant::StaticClass,
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
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UWidgetInterface_Combatant_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UWidgetInterface_Combatant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWidgetInterface_Combatant()
	{
		if (!Z_Registration_Info_UClass_UWidgetInterface_Combatant.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWidgetInterface_Combatant.OuterSingleton, Z_Construct_UClass_UWidgetInterface_Combatant_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UWidgetInterface_Combatant.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UWidgetInterface_Combatant>()
	{
		return UWidgetInterface_Combatant::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWidgetInterface_Combatant);
	static FName NAME_UWidgetInterface_Combatant_GetAttributeProgressBar = FName(TEXT("GetAttributeProgressBar"));
	void IWidgetInterface_Combatant::Execute_GetAttributeProgressBar(UObject* O, UOmegaAttribute* Attribute, UProgressBar*& ProgressBar)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Combatant::StaticClass()));
		WidgetInterface_Combatant_eventGetAttributeProgressBar_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Combatant_GetAttributeProgressBar);
		if (Func)
		{
			Parms.Attribute=Attribute;
			Parms.ProgressBar=ProgressBar;
			O->ProcessEvent(Func, &Parms);
			ProgressBar=Parms.ProgressBar;
		}
		else if (auto I = (IWidgetInterface_Combatant*)(O->GetNativeInterfaceAddress(UWidgetInterface_Combatant::StaticClass())))
		{
			I->GetAttributeProgressBar_Implementation(Attribute,ProgressBar);
		}
	}
	static FName NAME_UWidgetInterface_Combatant_GetAttributeTexts = FName(TEXT("GetAttributeTexts"));
	void IWidgetInterface_Combatant::Execute_GetAttributeTexts(UObject* O, UOmegaAttribute* Attribute, UTextBlock*& CurrentValue, UTextBlock*& MaxValue)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Combatant::StaticClass()));
		WidgetInterface_Combatant_eventGetAttributeTexts_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Combatant_GetAttributeTexts);
		if (Func)
		{
			Parms.Attribute=Attribute;
			Parms.CurrentValue=CurrentValue;
			Parms.MaxValue=MaxValue;
			O->ProcessEvent(Func, &Parms);
			CurrentValue=Parms.CurrentValue;
			MaxValue=Parms.MaxValue;
		}
		else if (auto I = (IWidgetInterface_Combatant*)(O->GetNativeInterfaceAddress(UWidgetInterface_Combatant::StaticClass())))
		{
			I->GetAttributeTexts_Implementation(Attribute,CurrentValue,MaxValue);
		}
	}
	static FName NAME_UWidgetInterface_Combatant_GetCombatantComponent = FName(TEXT("GetCombatantComponent"));
	UCombatantComponent* IWidgetInterface_Combatant::Execute_GetCombatantComponent(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Combatant::StaticClass()));
		WidgetInterface_Combatant_eventGetCombatantComponent_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Combatant_GetCombatantComponent);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IWidgetInterface_Combatant*)(O->GetNativeInterfaceAddress(UWidgetInterface_Combatant::StaticClass())))
		{
			Parms.ReturnValue = I->GetCombatantComponent_Implementation();
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UWidgetInterface_Combatant, UWidgetInterface_Combatant::StaticClass, TEXT("UWidgetInterface_Combatant"), &Z_Registration_Info_UClass_UWidgetInterface_Combatant, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWidgetInterface_Combatant), 2133653975U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_1312916240(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

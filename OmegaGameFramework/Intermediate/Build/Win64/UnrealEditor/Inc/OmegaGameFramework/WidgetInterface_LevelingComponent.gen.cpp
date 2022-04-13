// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Attributes/WidgetInterface_LevelingComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWidgetInterface_LevelingComponent() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UWidgetInterface_LevelingComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UWidgetInterface_LevelingComponent();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_ULevelingComponent_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IWidgetInterface_LevelingComponent::execGetLevelingProgressBar)
	{
		P_GET_OBJECT_REF(UProgressBar,Z_Param_Out_ProgressBar);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetLevelingProgressBar_Implementation(Z_Param_Out_ProgressBar);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_LevelingComponent::execGetLevelingTexts)
	{
		P_GET_OBJECT_REF(UTextBlock,Z_Param_Out_CurrentValue);
		P_GET_OBJECT_REF(UTextBlock,Z_Param_Out_MaxValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetLevelingTexts_Implementation(Z_Param_Out_CurrentValue,Z_Param_Out_MaxValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_LevelingComponent::execGetLevelingComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ULevelingComponent**)Z_Param__Result=P_THIS->GetLevelingComponent_Implementation();
		P_NATIVE_END;
	}
	ULevelingComponent* IWidgetInterface_LevelingComponent::GetLevelingComponent()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetLevelingComponent instead.");
		WidgetInterface_LevelingComponent_eventGetLevelingComponent_Parms Parms;
		return Parms.ReturnValue;
	}
	void IWidgetInterface_LevelingComponent::GetLevelingProgressBar(UProgressBar*& ProgressBar)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetLevelingProgressBar instead.");
	}
	void IWidgetInterface_LevelingComponent::GetLevelingTexts(UTextBlock*& CurrentValue, UTextBlock*& MaxValue)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetLevelingTexts instead.");
	}
	void UWidgetInterface_LevelingComponent::StaticRegisterNativesUWidgetInterface_LevelingComponent()
	{
		UClass* Class = UWidgetInterface_LevelingComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetLevelingComponent", &IWidgetInterface_LevelingComponent::execGetLevelingComponent },
			{ "GetLevelingProgressBar", &IWidgetInterface_LevelingComponent::execGetLevelingProgressBar },
			{ "GetLevelingTexts", &IWidgetInterface_LevelingComponent::execGetLevelingTexts },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_LevelingComponent_eventGetLevelingComponent_Parms, ReturnValue), Z_Construct_UClass_ULevelingComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Combatant" },
		{ "ModuleRelativePath", "Public/Attributes/WidgetInterface_LevelingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_LevelingComponent, nullptr, "GetLevelingComponent", nullptr, nullptr, sizeof(WidgetInterface_LevelingComponent_eventGetLevelingComponent_Parms), Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics
	{
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::NewProp_ProgressBar_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::NewProp_ProgressBar = { "ProgressBar", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_LevelingComponent_eventGetLevelingProgressBar_Parms, ProgressBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::NewProp_ProgressBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::NewProp_ProgressBar_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::NewProp_ProgressBar,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Combatant" },
		{ "ModuleRelativePath", "Public/Attributes/WidgetInterface_LevelingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_LevelingComponent, nullptr, "GetLevelingProgressBar", nullptr, nullptr, sizeof(WidgetInterface_LevelingComponent_eventGetLevelingProgressBar_Parms), Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics
	{
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_CurrentValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_CurrentValue = { "CurrentValue", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_LevelingComponent_eventGetLevelingTexts_Parms, CurrentValue), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_CurrentValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_CurrentValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_MaxValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_MaxValue = { "MaxValue", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_LevelingComponent_eventGetLevelingTexts_Parms, MaxValue), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_MaxValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_MaxValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_CurrentValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::NewProp_MaxValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Combatant" },
		{ "ModuleRelativePath", "Public/Attributes/WidgetInterface_LevelingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_LevelingComponent, nullptr, "GetLevelingTexts", nullptr, nullptr, sizeof(WidgetInterface_LevelingComponent_eventGetLevelingTexts_Parms), Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWidgetInterface_LevelingComponent);
	UClass* Z_Construct_UClass_UWidgetInterface_LevelingComponent_NoRegister()
	{
		return UWidgetInterface_LevelingComponent::StaticClass();
	}
	struct Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingComponent, "GetLevelingComponent" }, // 2319829730
		{ &Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingProgressBar, "GetLevelingProgressBar" }, // 1637734580
		{ &Z_Construct_UFunction_UWidgetInterface_LevelingComponent_GetLevelingTexts, "GetLevelingTexts" }, // 1182473552
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Attributes/WidgetInterface_LevelingComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IWidgetInterface_LevelingComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::ClassParams = {
		&UWidgetInterface_LevelingComponent::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWidgetInterface_LevelingComponent()
	{
		if (!Z_Registration_Info_UClass_UWidgetInterface_LevelingComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWidgetInterface_LevelingComponent.OuterSingleton, Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UWidgetInterface_LevelingComponent.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UWidgetInterface_LevelingComponent>()
	{
		return UWidgetInterface_LevelingComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWidgetInterface_LevelingComponent);
	static FName NAME_UWidgetInterface_LevelingComponent_GetLevelingComponent = FName(TEXT("GetLevelingComponent"));
	ULevelingComponent* IWidgetInterface_LevelingComponent::Execute_GetLevelingComponent(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_LevelingComponent::StaticClass()));
		WidgetInterface_LevelingComponent_eventGetLevelingComponent_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_LevelingComponent_GetLevelingComponent);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IWidgetInterface_LevelingComponent*)(O->GetNativeInterfaceAddress(UWidgetInterface_LevelingComponent::StaticClass())))
		{
			Parms.ReturnValue = I->GetLevelingComponent_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UWidgetInterface_LevelingComponent_GetLevelingProgressBar = FName(TEXT("GetLevelingProgressBar"));
	void IWidgetInterface_LevelingComponent::Execute_GetLevelingProgressBar(UObject* O, UProgressBar*& ProgressBar)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_LevelingComponent::StaticClass()));
		WidgetInterface_LevelingComponent_eventGetLevelingProgressBar_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_LevelingComponent_GetLevelingProgressBar);
		if (Func)
		{
			Parms.ProgressBar=ProgressBar;
			O->ProcessEvent(Func, &Parms);
			ProgressBar=Parms.ProgressBar;
		}
		else if (auto I = (IWidgetInterface_LevelingComponent*)(O->GetNativeInterfaceAddress(UWidgetInterface_LevelingComponent::StaticClass())))
		{
			I->GetLevelingProgressBar_Implementation(ProgressBar);
		}
	}
	static FName NAME_UWidgetInterface_LevelingComponent_GetLevelingTexts = FName(TEXT("GetLevelingTexts"));
	void IWidgetInterface_LevelingComponent::Execute_GetLevelingTexts(UObject* O, UTextBlock*& CurrentValue, UTextBlock*& MaxValue)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_LevelingComponent::StaticClass()));
		WidgetInterface_LevelingComponent_eventGetLevelingTexts_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_LevelingComponent_GetLevelingTexts);
		if (Func)
		{
			Parms.CurrentValue=CurrentValue;
			Parms.MaxValue=MaxValue;
			O->ProcessEvent(Func, &Parms);
			CurrentValue=Parms.CurrentValue;
			MaxValue=Parms.MaxValue;
		}
		else if (auto I = (IWidgetInterface_LevelingComponent*)(O->GetNativeInterfaceAddress(UWidgetInterface_LevelingComponent::StaticClass())))
		{
			I->GetLevelingTexts_Implementation(CurrentValue,MaxValue);
		}
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UWidgetInterface_LevelingComponent, UWidgetInterface_LevelingComponent::StaticClass, TEXT("UWidgetInterface_LevelingComponent"), &Z_Registration_Info_UClass_UWidgetInterface_LevelingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWidgetInterface_LevelingComponent), 3524171683U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_2260919930(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

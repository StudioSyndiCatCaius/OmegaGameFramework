// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Widget/WidgetInterface_Input.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWidgetInterface_Input() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UWidgetInterface_Input_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UWidgetInterface_Input();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
// End Cross Module References
	DEFINE_FUNCTION(IWidgetInterface_Input::execInputTag)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_Tag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputTag_Implementation(Z_Param_Tag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_Input::execInputBlocked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->InputBlocked_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_Input::execInputCancel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputCancel_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_Input::execInputConfirm)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputConfirm_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_Input::execInputPage)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Axis);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputPage_Implementation(Z_Param_Axis);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IWidgetInterface_Input::execInputNavigate)
	{
		P_GET_STRUCT(FVector2D,Z_Param_Axis);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputNavigate_Implementation(Z_Param_Axis);
		P_NATIVE_END;
	}
	bool IWidgetInterface_Input::InputBlocked()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InputBlocked instead.");
		WidgetInterface_Input_eventInputBlocked_Parms Parms;
		return Parms.ReturnValue;
	}
	void IWidgetInterface_Input::InputCancel()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InputCancel instead.");
	}
	void IWidgetInterface_Input::InputConfirm()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InputConfirm instead.");
	}
	void IWidgetInterface_Input::InputNavigate(FVector2D Axis)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InputNavigate instead.");
	}
	void IWidgetInterface_Input::InputPage(float Axis)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InputPage instead.");
	}
	void IWidgetInterface_Input::InputTag(FGameplayTag Tag)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InputTag instead.");
	}
	void UWidgetInterface_Input::StaticRegisterNativesUWidgetInterface_Input()
	{
		UClass* Class = UWidgetInterface_Input::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "InputBlocked", &IWidgetInterface_Input::execInputBlocked },
			{ "InputCancel", &IWidgetInterface_Input::execInputCancel },
			{ "InputConfirm", &IWidgetInterface_Input::execInputConfirm },
			{ "InputNavigate", &IWidgetInterface_Input::execInputNavigate },
			{ "InputPage", &IWidgetInterface_Input::execInputPage },
			{ "InputTag", &IWidgetInterface_Input::execInputTag },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WidgetInterface_Input_eventInputBlocked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WidgetInterface_Input_eventInputBlocked_Parms), &Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Input.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Input, nullptr, "InputBlocked", nullptr, nullptr, sizeof(WidgetInterface_Input_eventInputBlocked_Parms), Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_Input_InputCancel_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Input_InputCancel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Input.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Input_InputCancel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Input, nullptr, "InputCancel", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Input_InputCancel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputCancel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Input_InputCancel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Input_InputCancel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Input.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Input, nullptr, "InputConfirm", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Axis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Input_eventInputNavigate_Parms, Axis), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::NewProp_Axis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Input.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Input, nullptr, "InputNavigate", nullptr, nullptr, sizeof(WidgetInterface_Input_eventInputNavigate_Parms), Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Axis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Input_eventInputPage_Parms, Axis), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::NewProp_Axis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Input.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Input, nullptr, "InputPage", nullptr, nullptr, sizeof(WidgetInterface_Input_eventInputPage_Parms), Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Input_InputPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Input_InputPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WidgetInterface_Input_eventInputTag_Parms, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::NewProp_Tag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Input.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWidgetInterface_Input, nullptr, "InputTag", nullptr, nullptr, sizeof(WidgetInterface_Input_eventInputTag_Parms), Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWidgetInterface_Input_InputTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWidgetInterface_Input_InputTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWidgetInterface_Input);
	UClass* Z_Construct_UClass_UWidgetInterface_Input_NoRegister()
	{
		return UWidgetInterface_Input::StaticClass();
	}
	struct Z_Construct_UClass_UWidgetInterface_Input_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWidgetInterface_Input_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UWidgetInterface_Input_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UWidgetInterface_Input_InputBlocked, "InputBlocked" }, // 3839896161
		{ &Z_Construct_UFunction_UWidgetInterface_Input_InputCancel, "InputCancel" }, // 472967445
		{ &Z_Construct_UFunction_UWidgetInterface_Input_InputConfirm, "InputConfirm" }, // 2300757497
		{ &Z_Construct_UFunction_UWidgetInterface_Input_InputNavigate, "InputNavigate" }, // 3617661530
		{ &Z_Construct_UFunction_UWidgetInterface_Input_InputPage, "InputPage" }, // 1798583063
		{ &Z_Construct_UFunction_UWidgetInterface_Input_InputTag, "InputTag" }, // 3142987906
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWidgetInterface_Input_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/WidgetInterface_Input.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWidgetInterface_Input_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IWidgetInterface_Input>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UWidgetInterface_Input_Statics::ClassParams = {
		&UWidgetInterface_Input::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UWidgetInterface_Input_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UWidgetInterface_Input_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWidgetInterface_Input()
	{
		if (!Z_Registration_Info_UClass_UWidgetInterface_Input.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWidgetInterface_Input.OuterSingleton, Z_Construct_UClass_UWidgetInterface_Input_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UWidgetInterface_Input.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UWidgetInterface_Input>()
	{
		return UWidgetInterface_Input::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWidgetInterface_Input);
	static FName NAME_UWidgetInterface_Input_InputBlocked = FName(TEXT("InputBlocked"));
	bool IWidgetInterface_Input::Execute_InputBlocked(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Input::StaticClass()));
		WidgetInterface_Input_eventInputBlocked_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Input_InputBlocked);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IWidgetInterface_Input*)(O->GetNativeInterfaceAddress(UWidgetInterface_Input::StaticClass())))
		{
			Parms.ReturnValue = I->InputBlocked_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UWidgetInterface_Input_InputCancel = FName(TEXT("InputCancel"));
	void IWidgetInterface_Input::Execute_InputCancel(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Input::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Input_InputCancel);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IWidgetInterface_Input*)(O->GetNativeInterfaceAddress(UWidgetInterface_Input::StaticClass())))
		{
			I->InputCancel_Implementation();
		}
	}
	static FName NAME_UWidgetInterface_Input_InputConfirm = FName(TEXT("InputConfirm"));
	void IWidgetInterface_Input::Execute_InputConfirm(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Input::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Input_InputConfirm);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IWidgetInterface_Input*)(O->GetNativeInterfaceAddress(UWidgetInterface_Input::StaticClass())))
		{
			I->InputConfirm_Implementation();
		}
	}
	static FName NAME_UWidgetInterface_Input_InputNavigate = FName(TEXT("InputNavigate"));
	void IWidgetInterface_Input::Execute_InputNavigate(UObject* O, FVector2D Axis)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Input::StaticClass()));
		WidgetInterface_Input_eventInputNavigate_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Input_InputNavigate);
		if (Func)
		{
			Parms.Axis=Axis;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IWidgetInterface_Input*)(O->GetNativeInterfaceAddress(UWidgetInterface_Input::StaticClass())))
		{
			I->InputNavigate_Implementation(Axis);
		}
	}
	static FName NAME_UWidgetInterface_Input_InputPage = FName(TEXT("InputPage"));
	void IWidgetInterface_Input::Execute_InputPage(UObject* O, float Axis)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Input::StaticClass()));
		WidgetInterface_Input_eventInputPage_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Input_InputPage);
		if (Func)
		{
			Parms.Axis=Axis;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IWidgetInterface_Input*)(O->GetNativeInterfaceAddress(UWidgetInterface_Input::StaticClass())))
		{
			I->InputPage_Implementation(Axis);
		}
	}
	static FName NAME_UWidgetInterface_Input_InputTag = FName(TEXT("InputTag"));
	void IWidgetInterface_Input::Execute_InputTag(UObject* O, FGameplayTag Tag)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UWidgetInterface_Input::StaticClass()));
		WidgetInterface_Input_eventInputTag_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UWidgetInterface_Input_InputTag);
		if (Func)
		{
			Parms.Tag=Tag;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IWidgetInterface_Input*)(O->GetNativeInterfaceAddress(UWidgetInterface_Input::StaticClass())))
		{
			I->InputTag_Implementation(Tag);
		}
	}
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UWidgetInterface_Input, UWidgetInterface_Input::StaticClass, TEXT("UWidgetInterface_Input"), &Z_Registration_Info_UClass_UWidgetInterface_Input, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWidgetInterface_Input), 2763076704U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_858976433(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

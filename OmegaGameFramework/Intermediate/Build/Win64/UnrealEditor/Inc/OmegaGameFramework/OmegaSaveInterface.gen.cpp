// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Save/OmegaSaveInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaSaveInterface() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveInterface_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGame_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IOmegaSaveInterface::execOnGameFileStarted)
	{
		P_GET_OBJECT(UOmegaSaveGame,Z_Param_SaveFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameFileStarted_Implementation(Z_Param_SaveFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IOmegaSaveInterface::execOnGameFileSaved)
	{
		P_GET_OBJECT(UOmegaSaveGame,Z_Param_SaveFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OnGameFileSaved_Implementation(Z_Param_SaveFile);
		P_NATIVE_END;
	}
	bool IOmegaSaveInterface::OnGameFileSaved(UOmegaSaveGame* SaveFile)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnGameFileSaved instead.");
		OmegaSaveInterface_eventOnGameFileSaved_Parms Parms;
		return Parms.ReturnValue;
	}
	void IOmegaSaveInterface::OnGameFileStarted(UOmegaSaveGame* SaveFile)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnGameFileStarted instead.");
	}
	void UOmegaSaveInterface::StaticRegisterNativesUOmegaSaveInterface()
	{
		UClass* Class = UOmegaSaveInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnGameFileSaved", &IOmegaSaveInterface::execOnGameFileSaved },
			{ "OnGameFileStarted", &IOmegaSaveInterface::execOnGameFileStarted },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveFile;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::NewProp_SaveFile = { "SaveFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveInterface_eventOnGameFileSaved_Parms, SaveFile), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaSaveInterface_eventOnGameFileSaved_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveInterface_eventOnGameFileSaved_Parms), &Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::NewProp_SaveFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|Save" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveInterface, nullptr, "OnGameFileSaved", nullptr, nullptr, sizeof(OmegaSaveInterface_eventOnGameFileSaved_Parms), Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveFile;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::NewProp_SaveFile = { "SaveFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveInterface_eventOnGameFileStarted_Parms, SaveFile), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::NewProp_SaveFile,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|Save" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveInterface, nullptr, "OnGameFileStarted", nullptr, nullptr, sizeof(OmegaSaveInterface_eventOnGameFileStarted_Parms), Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaSaveInterface);
	UClass* Z_Construct_UClass_UOmegaSaveInterface_NoRegister()
	{
		return UOmegaSaveInterface::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaSaveInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaSaveInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaSaveInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileSaved, "OnGameFileSaved" }, // 2201628072
		{ &Z_Construct_UFunction_UOmegaSaveInterface_OnGameFileStarted, "OnGameFileStarted" }, // 2497027905
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaSaveInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IOmegaSaveInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaSaveInterface_Statics::ClassParams = {
		&UOmegaSaveInterface::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaSaveInterface()
	{
		if (!Z_Registration_Info_UClass_UOmegaSaveInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaSaveInterface.OuterSingleton, Z_Construct_UClass_UOmegaSaveInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaSaveInterface.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaSaveInterface>()
	{
		return UOmegaSaveInterface::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaSaveInterface);
	static FName NAME_UOmegaSaveInterface_OnGameFileSaved = FName(TEXT("OnGameFileSaved"));
	bool IOmegaSaveInterface::Execute_OnGameFileSaved(UObject* O, UOmegaSaveGame* SaveFile)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UOmegaSaveInterface::StaticClass()));
		OmegaSaveInterface_eventOnGameFileSaved_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UOmegaSaveInterface_OnGameFileSaved);
		if (Func)
		{
			Parms.SaveFile=SaveFile;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IOmegaSaveInterface*)(O->GetNativeInterfaceAddress(UOmegaSaveInterface::StaticClass())))
		{
			Parms.ReturnValue = I->OnGameFileSaved_Implementation(SaveFile);
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UOmegaSaveInterface_OnGameFileStarted = FName(TEXT("OnGameFileStarted"));
	void IOmegaSaveInterface::Execute_OnGameFileStarted(UObject* O, UOmegaSaveGame* SaveFile)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UOmegaSaveInterface::StaticClass()));
		OmegaSaveInterface_eventOnGameFileStarted_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UOmegaSaveInterface_OnGameFileStarted);
		if (Func)
		{
			Parms.SaveFile=SaveFile;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IOmegaSaveInterface*)(O->GetNativeInterfaceAddress(UOmegaSaveInterface::StaticClass())))
		{
			I->OnGameFileStarted_Implementation(SaveFile);
		}
	}
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaSaveInterface, UOmegaSaveInterface::StaticClass, TEXT("UOmegaSaveInterface"), &Z_Registration_Info_UClass_UOmegaSaveInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaSaveInterface), 1733132305U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_3064616857(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

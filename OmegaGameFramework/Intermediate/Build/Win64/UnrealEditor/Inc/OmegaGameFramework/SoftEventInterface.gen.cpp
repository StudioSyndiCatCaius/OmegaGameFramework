// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Event/SoftEventInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoftEventInterface() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_USoftEventInterface_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_USoftEventInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ISoftEventInterface::execOnEventTriggered)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Event);
		P_GET_OBJECT(UObject,Z_Param_Instigator);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnEventTriggered_Implementation(Z_Param_Event,Z_Param_Instigator);
		P_NATIVE_END;
	}
	void ISoftEventInterface::OnEventTriggered(FName Event, UObject* Instigator)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnEventTriggered instead.");
	}
	void USoftEventInterface::StaticRegisterNativesUSoftEventInterface()
	{
		UClass* Class = USoftEventInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnEventTriggered", &ISoftEventInterface::execOnEventTriggered },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_Event;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftEventInterface_eventOnEventTriggered_Parms, Event), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftEventInterface_eventOnEventTriggered_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::NewProp_Event,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::Function_MetaDataParams[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/Event/SoftEventInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USoftEventInterface, nullptr, "OnEventTriggered", nullptr, nullptr, sizeof(SoftEventInterface_eventOnEventTriggered_Parms), Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USoftEventInterface_OnEventTriggered()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USoftEventInterface_OnEventTriggered_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USoftEventInterface);
	UClass* Z_Construct_UClass_USoftEventInterface_NoRegister()
	{
		return USoftEventInterface::StaticClass();
	}
	struct Z_Construct_UClass_USoftEventInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USoftEventInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USoftEventInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USoftEventInterface_OnEventTriggered, "OnEventTriggered" }, // 2099057039
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USoftEventInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Event/SoftEventInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USoftEventInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISoftEventInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USoftEventInterface_Statics::ClassParams = {
		&USoftEventInterface::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USoftEventInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USoftEventInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USoftEventInterface()
	{
		if (!Z_Registration_Info_UClass_USoftEventInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USoftEventInterface.OuterSingleton, Z_Construct_UClass_USoftEventInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USoftEventInterface.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<USoftEventInterface>()
	{
		return USoftEventInterface::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USoftEventInterface);
	static FName NAME_USoftEventInterface_OnEventTriggered = FName(TEXT("OnEventTriggered"));
	void ISoftEventInterface::Execute_OnEventTriggered(UObject* O, FName Event, UObject* Instigator)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USoftEventInterface::StaticClass()));
		SoftEventInterface_eventOnEventTriggered_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_USoftEventInterface_OnEventTriggered);
		if (Func)
		{
			Parms.Event=Event;
			Parms.Instigator=Instigator;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (ISoftEventInterface*)(O->GetNativeInterfaceAddress(USoftEventInterface::StaticClass())))
		{
			I->OnEventTriggered_Implementation(Event,Instigator);
		}
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USoftEventInterface, USoftEventInterface::StaticClass, TEXT("USoftEventInterface"), &Z_Registration_Info_UClass_USoftEventInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USoftEventInterface), 689531502U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_3857431733(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

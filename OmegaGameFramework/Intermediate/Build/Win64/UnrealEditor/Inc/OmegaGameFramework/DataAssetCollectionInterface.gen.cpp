// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Data/DataAssetCollectionInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataAssetCollectionInterface() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataAssetCollectionInterface_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataAssetCollectionInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
// End Cross Module References
	DEFINE_FUNCTION(IDataAssetCollectionInterface::execGetMaxCollectionNumber)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetMaxCollectionNumber_Implementation();
		P_NATIVE_END;
	}
	int32 IDataAssetCollectionInterface::GetMaxCollectionNumber()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetMaxCollectionNumber instead.");
		DataAssetCollectionInterface_eventGetMaxCollectionNumber_Parms Parms;
		return Parms.ReturnValue;
	}
	void UDataAssetCollectionInterface::StaticRegisterNativesUDataAssetCollectionInterface()
	{
		UClass* Class = UDataAssetCollectionInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMaxCollectionNumber", &IDataAssetCollectionInterface::execGetMaxCollectionNumber },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionInterface_eventGetMaxCollectionNumber_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionInterface, nullptr, "GetMaxCollectionNumber", nullptr, nullptr, sizeof(DataAssetCollectionInterface_eventGetMaxCollectionNumber_Parms), Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataAssetCollectionInterface);
	UClass* Z_Construct_UClass_UDataAssetCollectionInterface_NoRegister()
	{
		return UDataAssetCollectionInterface::StaticClass();
	}
	struct Z_Construct_UClass_UDataAssetCollectionInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataAssetCollectionInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataAssetCollectionInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataAssetCollectionInterface_GetMaxCollectionNumber, "GetMaxCollectionNumber" }, // 1159914217
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataAssetCollectionInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataAssetCollectionInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDataAssetCollectionInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataAssetCollectionInterface_Statics::ClassParams = {
		&UDataAssetCollectionInterface::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UDataAssetCollectionInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataAssetCollectionInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataAssetCollectionInterface()
	{
		if (!Z_Registration_Info_UClass_UDataAssetCollectionInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataAssetCollectionInterface.OuterSingleton, Z_Construct_UClass_UDataAssetCollectionInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataAssetCollectionInterface.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataAssetCollectionInterface>()
	{
		return UDataAssetCollectionInterface::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataAssetCollectionInterface);
	static FName NAME_UDataAssetCollectionInterface_GetMaxCollectionNumber = FName(TEXT("GetMaxCollectionNumber"));
	int32 IDataAssetCollectionInterface::Execute_GetMaxCollectionNumber(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataAssetCollectionInterface::StaticClass()));
		DataAssetCollectionInterface_eventGetMaxCollectionNumber_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataAssetCollectionInterface_GetMaxCollectionNumber);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IDataAssetCollectionInterface*)(O->GetNativeInterfaceAddress(UDataAssetCollectionInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetMaxCollectionNumber_Implementation();
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataAssetCollectionInterface, UDataAssetCollectionInterface::StaticClass, TEXT("UDataAssetCollectionInterface"), &Z_Registration_Info_UClass_UDataAssetCollectionInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataAssetCollectionInterface), 3736517065U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_3232854281(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

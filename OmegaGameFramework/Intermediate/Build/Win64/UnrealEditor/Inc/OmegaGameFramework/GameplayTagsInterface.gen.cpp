// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/GameplayTagsInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameplayTagsInterface() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGameplayTagsInterface_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGameplayTagsInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
// End Cross Module References
	DEFINE_FUNCTION(IGameplayTagsInterface::execGetObjectGameplayTags)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetObjectGameplayTags_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IGameplayTagsInterface::execGetObjectGameplayCategory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTag*)Z_Param__Result=P_THIS->GetObjectGameplayCategory_Implementation();
		P_NATIVE_END;
	}
	FGameplayTag IGameplayTagsInterface::GetObjectGameplayCategory()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetObjectGameplayCategory instead.");
		GameplayTagsInterface_eventGetObjectGameplayCategory_Parms Parms;
		return Parms.ReturnValue;
	}
	FGameplayTagContainer IGameplayTagsInterface::GetObjectGameplayTags()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetObjectGameplayTags instead.");
		GameplayTagsInterface_eventGetObjectGameplayTags_Parms Parms;
		return Parms.ReturnValue;
	}
	void UGameplayTagsInterface::StaticRegisterNativesUGameplayTagsInterface()
	{
		UClass* Class = UGameplayTagsInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetObjectGameplayCategory", &IGameplayTagsInterface::execGetObjectGameplayCategory },
			{ "GetObjectGameplayTags", &IGameplayTagsInterface::execGetObjectGameplayTags },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameplayTagsInterface_eventGetObjectGameplayCategory_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/Gameplay/GameplayTagsInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayTagsInterface, nullptr, "GetObjectGameplayCategory", nullptr, nullptr, sizeof(GameplayTagsInterface_eventGetObjectGameplayCategory_Parms), Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameplayTagsInterface_eventGetObjectGameplayTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/Gameplay/GameplayTagsInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayTagsInterface, nullptr, "GetObjectGameplayTags", nullptr, nullptr, sizeof(GameplayTagsInterface_eventGetObjectGameplayTags_Parms), Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameplayTagsInterface);
	UClass* Z_Construct_UClass_UGameplayTagsInterface_NoRegister()
	{
		return UGameplayTagsInterface::StaticClass();
	}
	struct Z_Construct_UClass_UGameplayTagsInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameplayTagsInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameplayTagsInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayCategory, "GetObjectGameplayCategory" }, // 3448809437
		{ &Z_Construct_UFunction_UGameplayTagsInterface_GetObjectGameplayTags, "GetObjectGameplayTags" }, // 1016557937
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayTagsInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/GameplayTagsInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameplayTagsInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IGameplayTagsInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameplayTagsInterface_Statics::ClassParams = {
		&UGameplayTagsInterface::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UGameplayTagsInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayTagsInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameplayTagsInterface()
	{
		if (!Z_Registration_Info_UClass_UGameplayTagsInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameplayTagsInterface.OuterSingleton, Z_Construct_UClass_UGameplayTagsInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGameplayTagsInterface.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UGameplayTagsInterface>()
	{
		return UGameplayTagsInterface::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameplayTagsInterface);
	static FName NAME_UGameplayTagsInterface_GetObjectGameplayCategory = FName(TEXT("GetObjectGameplayCategory"));
	FGameplayTag IGameplayTagsInterface::Execute_GetObjectGameplayCategory(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()));
		GameplayTagsInterface_eventGetObjectGameplayCategory_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UGameplayTagsInterface_GetObjectGameplayCategory);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IGameplayTagsInterface*)(O->GetNativeInterfaceAddress(UGameplayTagsInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetObjectGameplayCategory_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UGameplayTagsInterface_GetObjectGameplayTags = FName(TEXT("GetObjectGameplayTags"));
	FGameplayTagContainer IGameplayTagsInterface::Execute_GetObjectGameplayTags(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()));
		GameplayTagsInterface_eventGetObjectGameplayTags_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UGameplayTagsInterface_GetObjectGameplayTags);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IGameplayTagsInterface*)(O->GetNativeInterfaceAddress(UGameplayTagsInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetObjectGameplayTags_Implementation();
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGameplayTagsInterface, UGameplayTagsInterface::StaticClass, TEXT("UGameplayTagsInterface"), &Z_Registration_Info_UClass_UGameplayTagsInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameplayTagsInterface), 2162780125U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_3815768064(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

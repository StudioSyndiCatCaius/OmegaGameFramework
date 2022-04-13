// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/ActorInterface_Combatant.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorInterface_Combatant() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UActorInterface_Combatant_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UActorInterface_Combatant();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IActorInterface_Combatant::execGetAttributeModifiers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UObject*>*)Z_Param__Result=P_THIS->GetAttributeModifiers_Implementation();
		P_NATIVE_END;
	}
	TArray<UObject*> IActorInterface_Combatant::GetAttributeModifiers()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetAttributeModifiers instead.");
		ActorInterface_Combatant_eventGetAttributeModifiers_Parms Parms;
		return Parms.ReturnValue;
	}
	void UActorInterface_Combatant::StaticRegisterNativesUActorInterface_Combatant()
	{
		UClass* Class = UActorInterface_Combatant::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAttributeModifiers", &IActorInterface_Combatant::execGetAttributeModifiers },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_Combatant_eventGetAttributeModifiers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "ModuleRelativePath", "Public/Gameplay/ActorInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActorInterface_Combatant, nullptr, "GetAttributeModifiers", nullptr, nullptr, sizeof(ActorInterface_Combatant_eventGetAttributeModifiers_Parms), Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UActorInterface_Combatant);
	UClass* Z_Construct_UClass_UActorInterface_Combatant_NoRegister()
	{
		return UActorInterface_Combatant::StaticClass();
	}
	struct Z_Construct_UClass_UActorInterface_Combatant_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActorInterface_Combatant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UActorInterface_Combatant_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UActorInterface_Combatant_GetAttributeModifiers, "GetAttributeModifiers" }, // 2084922748
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorInterface_Combatant_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/ActorInterface_Combatant.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActorInterface_Combatant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IActorInterface_Combatant>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UActorInterface_Combatant_Statics::ClassParams = {
		&UActorInterface_Combatant::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UActorInterface_Combatant_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActorInterface_Combatant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActorInterface_Combatant()
	{
		if (!Z_Registration_Info_UClass_UActorInterface_Combatant.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActorInterface_Combatant.OuterSingleton, Z_Construct_UClass_UActorInterface_Combatant_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UActorInterface_Combatant.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UActorInterface_Combatant>()
	{
		return UActorInterface_Combatant::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActorInterface_Combatant);
	static FName NAME_UActorInterface_Combatant_GetAttributeModifiers = FName(TEXT("GetAttributeModifiers"));
	TArray<UObject*> IActorInterface_Combatant::Execute_GetAttributeModifiers(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UActorInterface_Combatant::StaticClass()));
		ActorInterface_Combatant_eventGetAttributeModifiers_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UActorInterface_Combatant_GetAttributeModifiers);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IActorInterface_Combatant*)(O->GetNativeInterfaceAddress(UActorInterface_Combatant::StaticClass())))
		{
			Parms.ReturnValue = I->GetAttributeModifiers_Implementation();
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UActorInterface_Combatant, UActorInterface_Combatant::StaticClass, TEXT("UActorInterface_Combatant"), &Z_Registration_Info_UClass_UActorInterface_Combatant, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActorInterface_Combatant), 2967917989U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_2049496277(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

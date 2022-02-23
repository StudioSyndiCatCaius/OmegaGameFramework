// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/DataInterface_AttributeModifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataInterface_AttributeModifier() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FOmegaAttributeModifier();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_AttributeModifier_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_AttributeModifier();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OmegaAttributeModifier;
class UScriptStruct* FOmegaAttributeModifier::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OmegaAttributeModifier.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OmegaAttributeModifier.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOmegaAttributeModifier, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("OmegaAttributeModifier"));
	}
	return Z_Registration_Info_UScriptStruct_OmegaAttributeModifier.OuterSingleton;
}
template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<FOmegaAttributeModifier>()
{
	return FOmegaAttributeModifier::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Attribute_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Incrementer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Incrementer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Multiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Multiplier;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_AttributeModifier.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOmegaAttributeModifier>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Attribute_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_AttributeModifier.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOmegaAttributeModifier, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Attribute_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Attribute_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Incrementer_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_AttributeModifier.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Incrementer = { "Incrementer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOmegaAttributeModifier, Incrementer), METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Incrementer_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Incrementer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Multiplier_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_AttributeModifier.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Multiplier = { "Multiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOmegaAttributeModifier, Multiplier), METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Multiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Multiplier_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Incrementer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewProp_Multiplier,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		&NewStructOps,
		"OmegaAttributeModifier",
		sizeof(FOmegaAttributeModifier),
		alignof(FOmegaAttributeModifier),
		Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FOmegaAttributeModifier()
	{
		if (!Z_Registration_Info_UScriptStruct_OmegaAttributeModifier.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OmegaAttributeModifier.InnerSingleton, Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OmegaAttributeModifier.InnerSingleton;
	}
	DEFINE_FUNCTION(IDataInterface_AttributeModifier::execGetModifierValues)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FOmegaAttributeModifier>*)Z_Param__Result=P_THIS->GetModifierValues_Implementation();
		P_NATIVE_END;
	}
	TArray<FOmegaAttributeModifier> IDataInterface_AttributeModifier::GetModifierValues()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetModifierValues instead.");
		DataInterface_AttributeModifier_eventGetModifierValues_Parms Parms;
		return Parms.ReturnValue;
	}
	void UDataInterface_AttributeModifier::StaticRegisterNativesUDataInterface_AttributeModifier()
	{
		UClass* Class = UDataInterface_AttributeModifier::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetModifierValues", &IDataInterface_AttributeModifier::execGetModifierValues },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FOmegaAttributeModifier, METADATA_PARAMS(nullptr, 0) }; // 2682441012
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_AttributeModifier_eventGetModifierValues_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 2682441012
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes|Modifiers" },
		{ "Comment", "//UFUNCTION(BlueprintNativeEvent, Category=\"Attributes|Modifiers\")\n//UOmegaAttribute* GetModifiedAttribute();\n" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_AttributeModifier.h" },
		{ "ToolTip", "UFUNCTION(BlueprintNativeEvent, Category=\"Attributes|Modifiers\")\nUOmegaAttribute* GetModifiedAttribute();" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_AttributeModifier, nullptr, "GetModifierValues", nullptr, nullptr, sizeof(DataInterface_AttributeModifier_eventGetModifierValues_Parms), Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataInterface_AttributeModifier);
	UClass* Z_Construct_UClass_UDataInterface_AttributeModifier_NoRegister()
	{
		return UDataInterface_AttributeModifier::StaticClass();
	}
	struct Z_Construct_UClass_UDataInterface_AttributeModifier_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataInterface_AttributeModifier_GetModifierValues, "GetModifierValues" }, // 2776543509
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_AttributeModifier.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDataInterface_AttributeModifier>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::ClassParams = {
		&UDataInterface_AttributeModifier::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataInterface_AttributeModifier()
	{
		if (!Z_Registration_Info_UClass_UDataInterface_AttributeModifier.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataInterface_AttributeModifier.OuterSingleton, Z_Construct_UClass_UDataInterface_AttributeModifier_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataInterface_AttributeModifier.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataInterface_AttributeModifier>()
	{
		return UDataInterface_AttributeModifier::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataInterface_AttributeModifier);
	static FName NAME_UDataInterface_AttributeModifier_GetModifierValues = FName(TEXT("GetModifierValues"));
	TArray<FOmegaAttributeModifier> IDataInterface_AttributeModifier::Execute_GetModifierValues(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()));
		DataInterface_AttributeModifier_eventGetModifierValues_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_AttributeModifier_GetModifierValues);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IDataInterface_AttributeModifier*)(O->GetNativeInterfaceAddress(UDataInterface_AttributeModifier::StaticClass())))
		{
			Parms.ReturnValue = I->GetModifierValues_Implementation();
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_Statics::ScriptStructInfo[] = {
		{ FOmegaAttributeModifier::StaticStruct, Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics::NewStructOps, TEXT("OmegaAttributeModifier"), &Z_Registration_Info_UScriptStruct_OmegaAttributeModifier, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOmegaAttributeModifier), 2682441012U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataInterface_AttributeModifier, UDataInterface_AttributeModifier::StaticClass, TEXT("UDataInterface_AttributeModifier"), &Z_Registration_Info_UClass_UDataInterface_AttributeModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataInterface_AttributeModifier), 2197426848U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_234460762(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

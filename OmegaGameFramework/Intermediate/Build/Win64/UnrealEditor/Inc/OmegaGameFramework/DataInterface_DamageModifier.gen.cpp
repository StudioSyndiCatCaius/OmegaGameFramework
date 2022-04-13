// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/DataInterface_DamageModifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataInterface_DamageModifier() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_DamageModifier_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_DamageModifier();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IDataInterface_DamageModifier::execModifyDamage)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_OBJECT(UCombatantComponent,Z_Param_Target);
		P_GET_OBJECT(UObject,Z_Param_Instigator);
		P_GET_PROPERTY(FFloatProperty,Z_Param_BaseDamage);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->ModifyDamage_Implementation(Z_Param_Attribute,Z_Param_Target,Z_Param_Instigator,Z_Param_BaseDamage);
		P_NATIVE_END;
	}
	float IDataInterface_DamageModifier::ModifyDamage(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ModifyDamage instead.");
		DataInterface_DamageModifier_eventModifyDamage_Parms Parms;
		return Parms.ReturnValue;
	}
	void UDataInterface_DamageModifier::StaticRegisterNativesUDataInterface_DamageModifier()
	{
		UClass* Class = UDataInterface_DamageModifier::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ModifyDamage", &IDataInterface_DamageModifier::execModifyDamage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_DamageModifier_eventModifyDamage_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_DamageModifier_eventModifyDamage_Parms, Target), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Target_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Target_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_DamageModifier_eventModifyDamage_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_DamageModifier_eventModifyDamage_Parms, BaseDamage), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_DamageModifier_eventModifyDamage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_Instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_BaseDamage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_DamageModifier.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_DamageModifier, nullptr, "ModifyDamage", nullptr, nullptr, sizeof(DataInterface_DamageModifier_eventModifyDamage_Parms), Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataInterface_DamageModifier);
	UClass* Z_Construct_UClass_UDataInterface_DamageModifier_NoRegister()
	{
		return UDataInterface_DamageModifier::StaticClass();
	}
	struct Z_Construct_UClass_UDataInterface_DamageModifier_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataInterface_DamageModifier_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataInterface_DamageModifier_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataInterface_DamageModifier_ModifyDamage, "ModifyDamage" }, // 2857800632
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataInterface_DamageModifier_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_DamageModifier.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataInterface_DamageModifier_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDataInterface_DamageModifier>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataInterface_DamageModifier_Statics::ClassParams = {
		&UDataInterface_DamageModifier::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UDataInterface_DamageModifier_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataInterface_DamageModifier_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataInterface_DamageModifier()
	{
		if (!Z_Registration_Info_UClass_UDataInterface_DamageModifier.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataInterface_DamageModifier.OuterSingleton, Z_Construct_UClass_UDataInterface_DamageModifier_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataInterface_DamageModifier.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataInterface_DamageModifier>()
	{
		return UDataInterface_DamageModifier::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataInterface_DamageModifier);
	static FName NAME_UDataInterface_DamageModifier_ModifyDamage = FName(TEXT("ModifyDamage"));
	float IDataInterface_DamageModifier::Execute_ModifyDamage(UObject* O, UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_DamageModifier::StaticClass()));
		DataInterface_DamageModifier_eventModifyDamage_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_DamageModifier_ModifyDamage);
		if (Func)
		{
			Parms.Attribute=Attribute;
			Parms.Target=Target;
			Parms.Instigator=Instigator;
			Parms.BaseDamage=BaseDamage;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IDataInterface_DamageModifier*)(O->GetNativeInterfaceAddress(UDataInterface_DamageModifier::StaticClass())))
		{
			Parms.ReturnValue = I->ModifyDamage_Implementation(Attribute,Target,Instigator,BaseDamage);
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataInterface_DamageModifier, UDataInterface_DamageModifier::StaticClass, TEXT("UDataInterface_DamageModifier"), &Z_Registration_Info_UClass_UDataInterface_DamageModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataInterface_DamageModifier), 534420572U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_2032718548(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

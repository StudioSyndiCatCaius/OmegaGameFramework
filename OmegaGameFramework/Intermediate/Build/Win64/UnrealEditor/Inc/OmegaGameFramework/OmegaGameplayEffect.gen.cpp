// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaGameplayEffect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameplayEffect() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FOmegaEffectContainer();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplayEffect_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplayEffect();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EVolumeShape();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDamageFormula_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGameplayTagsInterface_NoRegister();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OmegaEffectContainer;
class UScriptStruct* FOmegaEffectContainer::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OmegaEffectContainer.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OmegaEffectContainer.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOmegaEffectContainer, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("OmegaEffectContainer"));
	}
	return Z_Registration_Info_UScriptStruct_OmegaEffectContainer.OuterSingleton;
}
template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<FOmegaEffectContainer>()
{
	return FOmegaEffectContainer::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_EffectClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AddedTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AddedTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOmegaEffectContainer>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_EffectClass_MetaData[] = {
		{ "Category", "Effect" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_EffectClass = { "EffectClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOmegaEffectContainer, EffectClass), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_EffectClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_EffectClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_Power_MetaData[] = {
		{ "Category", "Effect" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOmegaEffectContainer, Power), METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_Power_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_Power_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_AddedTags_MetaData[] = {
		{ "Category", "Effect" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_AddedTags = { "AddedTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOmegaEffectContainer, AddedTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_AddedTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_AddedTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_EffectClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_Power,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewProp_AddedTags,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		&NewStructOps,
		"OmegaEffectContainer",
		sizeof(FOmegaEffectContainer),
		alignof(FOmegaEffectContainer),
		Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FOmegaEffectContainer()
	{
		if (!Z_Registration_Info_UScriptStruct_OmegaEffectContainer.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OmegaEffectContainer.InnerSingleton, Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OmegaEffectContainer.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnEffectTriggered_Parms
		{
			AOmegaGameplayEffect* Effect;
			float DamageValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Effect;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::NewProp_Effect = { "Effect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEffectTriggered_Parms, Effect), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::NewProp_DamageValue = { "DamageValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEffectTriggered_Parms, DamageValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::NewProp_Effect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::NewProp_DamageValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnEffectTriggered__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnEffectTriggered_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEffectLifetime;
	static UEnum* EEffectLifetime_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EEffectLifetime.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EEffectLifetime.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("EEffectLifetime"));
		}
		return Z_Registration_Info_UEnum_EEffectLifetime.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EEffectLifetime>()
	{
		return EEffectLifetime_StaticEnum();
	}
	struct Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::Enumerators[] = {
		{ "EEffectLifetime::EffectLifetime_Instant", (int64)EEffectLifetime::EffectLifetime_Instant },
		{ "EEffectLifetime::EffectLifetime_Timer", (int64)EEffectLifetime::EffectLifetime_Timer },
		{ "EEffectLifetime::EffectLifetime_OnTrigger", (int64)EEffectLifetime::EffectLifetime_OnTrigger },
		{ "EEffectLifetime::EffectLifetime_OnDestroy", (int64)EEffectLifetime::EffectLifetime_OnDestroy },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::Enum_MetaDataParams[] = {
		{ "EffectLifetime_Instant.Comment", "// Effect is instantly triggered and destruct\n" },
		{ "EffectLifetime_Instant.DisplayName", "Instant" },
		{ "EffectLifetime_Instant.Name", "EEffectLifetime::EffectLifetime_Instant" },
		{ "EffectLifetime_Instant.ToolTip", "Effect is instantly triggered and destruct" },
		{ "EffectLifetime_OnDestroy.Comment", "// Effect remains until \"Destroy Actor\" is called.\n" },
		{ "EffectLifetime_OnDestroy.DisplayName", "OnDestroy" },
		{ "EffectLifetime_OnDestroy.Name", "EEffectLifetime::EffectLifetime_OnDestroy" },
		{ "EffectLifetime_OnDestroy.ToolTip", "Effect remains until \"Destroy Actor\" is called." },
		{ "EffectLifetime_OnTrigger.Comment", "// Effect remains until Trigger\n" },
		{ "EffectLifetime_OnTrigger.DisplayName", "OnTrigger" },
		{ "EffectLifetime_OnTrigger.Name", "EEffectLifetime::EffectLifetime_OnTrigger" },
		{ "EffectLifetime_OnTrigger.ToolTip", "Effect remains until Trigger" },
		{ "EffectLifetime_Timer.Comment", "//Effect will trigger and destruct after a certain amount of timer has passed.\n" },
		{ "EffectLifetime_Timer.DisplayName", "Timer" },
		{ "EffectLifetime_Timer.Name", "EEffectLifetime::EffectLifetime_Timer" },
		{ "EffectLifetime_Timer.ToolTip", "Effect will trigger and destruct after a certain amount of timer has passed." },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		"EEffectLifetime",
		"EEffectLifetime",
		Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime()
	{
		if (!Z_Registration_Info_UEnum_EEffectLifetime.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEffectLifetime.InnerSingleton, Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EEffectLifetime.InnerSingleton;
	}
	DEFINE_FUNCTION(AOmegaGameplayEffect::execGetObjectGameplayTags)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetObjectGameplayTags_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaGameplayEffect::execGetObjectGameplayCategory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTag*)Z_Param__Result=P_THIS->GetObjectGameplayCategory_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaGameplayEffect::execCalculateDamageValue)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->CalculateDamageValue();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaGameplayEffect::execLifetimeEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LifetimeEnd();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaGameplayEffect::execTriggerEffect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TriggerEffect();
		P_NATIVE_END;
	}
	static FName NAME_AOmegaGameplayEffect_EffectApplied = FName(TEXT("EffectApplied"));
	void AOmegaGameplayEffect::EffectApplied(float DamageValue)
	{
		OmegaGameplayEffect_eventEffectApplied_Parms Parms;
		Parms.DamageValue=DamageValue;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplayEffect_EffectApplied),&Parms);
	}
	static FName NAME_AOmegaGameplayEffect_EffectBeginPlay = FName(TEXT("EffectBeginPlay"));
	void AOmegaGameplayEffect::EffectBeginPlay(UObject* Context)
	{
		OmegaGameplayEffect_eventEffectBeginPlay_Parms Parms;
		Parms.Context=Context;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplayEffect_EffectBeginPlay),&Parms);
	}
	static FName NAME_AOmegaGameplayEffect_GetObjectGameplayCategory = FName(TEXT("GetObjectGameplayCategory"));
	FGameplayTag AOmegaGameplayEffect::GetObjectGameplayCategory()
	{
		OmegaGameplayEffect_eventGetObjectGameplayCategory_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplayEffect_GetObjectGameplayCategory),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AOmegaGameplayEffect_GetObjectGameplayTags = FName(TEXT("GetObjectGameplayTags"));
	FGameplayTagContainer AOmegaGameplayEffect::GetObjectGameplayTags()
	{
		OmegaGameplayEffect_eventGetObjectGameplayTags_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplayEffect_GetObjectGameplayTags),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AOmegaGameplayEffect_LifetimeUpdated = FName(TEXT("LifetimeUpdated"));
	void AOmegaGameplayEffect::LifetimeUpdated(float TimeElapsed, float TimeRemaining)
	{
		OmegaGameplayEffect_eventLifetimeUpdated_Parms Parms;
		Parms.TimeElapsed=TimeElapsed;
		Parms.TimeRemaining=TimeRemaining;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplayEffect_LifetimeUpdated),&Parms);
	}
	void AOmegaGameplayEffect::StaticRegisterNativesAOmegaGameplayEffect()
	{
		UClass* Class = AOmegaGameplayEffect::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalculateDamageValue", &AOmegaGameplayEffect::execCalculateDamageValue },
			{ "GetObjectGameplayCategory", &AOmegaGameplayEffect::execGetObjectGameplayCategory },
			{ "GetObjectGameplayTags", &AOmegaGameplayEffect::execGetObjectGameplayTags },
			{ "LifetimeEnd", &AOmegaGameplayEffect::execLifetimeEnd },
			{ "TriggerEffect", &AOmegaGameplayEffect::execTriggerEffect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics
	{
		struct OmegaGameplayEffect_eventCalculateDamageValue_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventCalculateDamageValue_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay|Effects" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "CalculateDamageValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::OmegaGameplayEffect_eventCalculateDamageValue_Parms), Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::NewProp_DamageValue = { "DamageValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventEffectApplied_Parms, DamageValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::NewProp_DamageValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay|Effects" },
		{ "DisplayName", "Effect Triggered" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "EffectApplied", nullptr, nullptr, sizeof(OmegaGameplayEffect_eventEffectApplied_Parms), Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventEffectBeginPlay_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay|Effects" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "EffectBeginPlay", nullptr, nullptr, sizeof(OmegaGameplayEffect_eventEffectBeginPlay_Parms), Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventGetObjectGameplayCategory_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "GetObjectGameplayCategory", nullptr, nullptr, sizeof(OmegaGameplayEffect_eventGetObjectGameplayCategory_Parms), Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventGetObjectGameplayTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "GetObjectGameplayTags", nullptr, nullptr, sizeof(OmegaGameplayEffect_eventGetObjectGameplayTags_Parms), Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "LifetimeEnd", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeElapsed;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeRemaining;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::NewProp_TimeElapsed = { "TimeElapsed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventLifetimeUpdated_Parms, TimeElapsed), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::NewProp_TimeRemaining = { "TimeRemaining", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventLifetimeUpdated_Parms, TimeRemaining), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::NewProp_TimeElapsed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::NewProp_TimeRemaining,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay|Effects" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "LifetimeUpdated", nullptr, nullptr, sizeof(OmegaGameplayEffect_eventLifetimeUpdated_Parms), Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay|Effects" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "TriggerEffect", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOmegaGameplayEffect);
	UClass* Z_Construct_UClass_AOmegaGameplayEffect_NoRegister()
	{
		return AOmegaGameplayEffect::StaticClass();
	}
	struct Z_Construct_UClass_AOmegaGameplayEffect_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEffectTriggered_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEffectTriggered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombatantInstigator_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatantInstigator;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetedCombatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetedCombatant;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EffectContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseVolume_MetaData[];
#endif
		static void NewProp_bUseVolume_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseVolume;
		static const UECodeGen_Private::FBytePropertyParams NewProp_VolumeShape_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VolumeShape_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_VolumeShape;
		static const UECodeGen_Private::FBytePropertyParams NewProp_EffectLifetime_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectLifetime_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_EffectLifetime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Lifetime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Lifetime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamageFormula_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DamageFormula;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalFormula_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LocalFormula;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectCategory_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EffectCategory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EffectTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOmegaGameplayEffect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AOmegaGameplayEffect_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue, "CalculateDamageValue" }, // 747170153
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied, "EffectApplied" }, // 323038385
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay, "EffectBeginPlay" }, // 2808011313
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayCategory, "GetObjectGameplayCategory" }, // 3284987037
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_GetObjectGameplayTags, "GetObjectGameplayTags" }, // 2627080328
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeEnd, "LifetimeEnd" }, // 1651120307
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_LifetimeUpdated, "LifetimeUpdated" }, // 348646275
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_TriggerEffect, "TriggerEffect" }, // 1998201103
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OmegaGameplayEffect.h" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_OnEffectTriggered_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_OnEffectTriggered = { "OnEffectTriggered", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, OnEffectTriggered), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEffectTriggered__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_OnEffectTriggered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_OnEffectTriggered_MetaData)) }; // 501736512
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator_MetaData[] = {
		{ "Category", "General" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator = { "CombatantInstigator", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, CombatantInstigator), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetedCombatant_MetaData[] = {
		{ "Category", "General" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetedCombatant = { "TargetedCombatant", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, TargetedCombatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetedCombatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetedCombatant_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectContext_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectContext = { "EffectContext", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, EffectContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectContext_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume_MetaData[] = {
		{ "Category", "Volume" },
		{ "Comment", "//-----VOLUME-----//\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
		{ "ToolTip", "-----VOLUME-----" },
	};
#endif
	void Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume_SetBit(void* Obj)
	{
		((AOmegaGameplayEffect*)Obj)->bUseVolume = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume = { "bUseVolume", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaGameplayEffect), &Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape_MetaData[] = {
		{ "Category", "Volume" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape = { "VolumeShape", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, VolumeShape), Z_Construct_UEnum_OmegaGameFramework_EVolumeShape, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape_MetaData)) }; // 2098034709
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_MetaData[] = {
		{ "Category", "Lifetime" },
		{ "Comment", "//-----Life-----//\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
		{ "ToolTip", "-----Life-----" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime = { "EffectLifetime", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, EffectLifetime), Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_MetaData)) }; // 3324234132
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Lifetime_MetaData[] = {
		{ "Category", "Lifetime" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Lifetime = { "Lifetime", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, Lifetime), METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Lifetime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Lifetime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_DamageFormula_MetaData[] = {
		{ "Category", "Damage" },
		{ "Comment", "//-----Damage-----//\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
		{ "ToolTip", "-----Damage-----" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_DamageFormula = { "DamageFormula", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, DamageFormula), Z_Construct_UClass_UDamageFormula_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_DamageFormula_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_DamageFormula_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Power_MetaData[] = {
		{ "Category", "Damage" },
		{ "ExposeOnSpawn", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0011000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, Power), METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Power_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Power_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_LocalFormula_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_LocalFormula = { "LocalFormula", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, LocalFormula), Z_Construct_UClass_UDamageFormula_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_LocalFormula_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_LocalFormula_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectCategory_MetaData[] = {
		{ "Category", "Tags" },
		{ "Comment", "//-----Tags-----//\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
		{ "ToolTip", "-----Tags-----" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectCategory = { "EffectCategory", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, EffectCategory), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectCategory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectCategory_MetaData)) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags = { "EffectTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, EffectTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOmegaGameplayEffect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_OnEffectTriggered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetedCombatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Lifetime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_DamageFormula,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Power,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_LocalFormula,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectCategory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UGameplayTagsInterface_NoRegister, (int32)VTABLE_OFFSET(AOmegaGameplayEffect, IGameplayTagsInterface), false },  // 2162780125
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOmegaGameplayEffect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOmegaGameplayEffect>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::ClassParams = {
		&AOmegaGameplayEffect::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AOmegaGameplayEffect_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOmegaGameplayEffect()
	{
		if (!Z_Registration_Info_UClass_AOmegaGameplayEffect.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOmegaGameplayEffect.OuterSingleton, Z_Construct_UClass_AOmegaGameplayEffect_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOmegaGameplayEffect.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<AOmegaGameplayEffect>()
	{
		return AOmegaGameplayEffect::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOmegaGameplayEffect);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::EnumInfo[] = {
		{ EEffectLifetime_StaticEnum, TEXT("EEffectLifetime"), &Z_Registration_Info_UEnum_EEffectLifetime, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3324234132U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ScriptStructInfo[] = {
		{ FOmegaEffectContainer::StaticStruct, Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics::NewStructOps, TEXT("OmegaEffectContainer"), &Z_Registration_Info_UScriptStruct_OmegaEffectContainer, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOmegaEffectContainer), 158265011U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOmegaGameplayEffect, AOmegaGameplayEffect::StaticClass, TEXT("AOmegaGameplayEffect"), &Z_Registration_Info_UClass_AOmegaGameplayEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOmegaGameplayEffect), 1725998718U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_252593820(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

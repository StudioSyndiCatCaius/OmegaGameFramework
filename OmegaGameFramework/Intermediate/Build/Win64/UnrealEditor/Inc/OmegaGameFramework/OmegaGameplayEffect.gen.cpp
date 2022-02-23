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
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplayEffect_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplayEffect();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EVolumeShape();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDamageFormula_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
// End Cross Module References
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
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime_Statics::Enum_MetaDataParams[] = {
		{ "EffectLifetime_Instant.Comment", "/** Description. */" },
		{ "EffectLifetime_Instant.DisplayName", "Instant" },
		{ "EffectLifetime_Instant.Name", "EEffectLifetime::EffectLifetime_Instant" },
		{ "EffectLifetime_Instant.ToolTip", "Description." },
		{ "EffectLifetime_OnTrigger.Comment", "/** Description. */" },
		{ "EffectLifetime_OnTrigger.DisplayName", "OnTrigger" },
		{ "EffectLifetime_OnTrigger.Name", "EEffectLifetime::EffectLifetime_OnTrigger" },
		{ "EffectLifetime_OnTrigger.ToolTip", "Description." },
		{ "EffectLifetime_Timer.Comment", "/** Description. */" },
		{ "EffectLifetime_Timer.DisplayName", "Timer" },
		{ "EffectLifetime_Timer.Name", "EEffectLifetime::EffectLifetime_Timer" },
		{ "EffectLifetime_Timer.ToolTip", "Description." },
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
	DEFINE_FUNCTION(AOmegaGameplayEffect::execCalculateDamageValue)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Multiplier);
		P_GET_OBJECT(UObject,Z_Param_DamageInstigator);
		P_GET_OBJECT(UObject,Z_Param_DamageTarget);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Damage);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CalculateDamageValue(Z_Param_Multiplier,Z_Param_DamageInstigator,Z_Param_DamageTarget,Z_Param_Out_Damage);
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
	void AOmegaGameplayEffect::EffectApplied()
	{
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplayEffect_EffectApplied),NULL);
	}
	static FName NAME_AOmegaGameplayEffect_EffectBeginPlay = FName(TEXT("EffectBeginPlay"));
	void AOmegaGameplayEffect::EffectBeginPlay(UCombatantComponent* EffectInstigator, AActor* TargetedActor)
	{
		OmegaGameplayEffect_eventEffectBeginPlay_Parms Parms;
		Parms.EffectInstigator=EffectInstigator;
		Parms.TargetedActor=TargetedActor;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplayEffect_EffectBeginPlay),&Parms);
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
			{ "LifetimeEnd", &AOmegaGameplayEffect::execLifetimeEnd },
			{ "TriggerEffect", &AOmegaGameplayEffect::execTriggerEffect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics
	{
		struct OmegaGameplayEffect_eventCalculateDamageValue_Parms
		{
			float Multiplier;
			UObject* DamageInstigator;
			UObject* DamageTarget;
			float Damage;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Multiplier;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageInstigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageTarget;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_Multiplier = { "Multiplier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventCalculateDamageValue_Parms, Multiplier), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_DamageInstigator = { "DamageInstigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventCalculateDamageValue_Parms, DamageInstigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_DamageTarget = { "DamageTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventCalculateDamageValue_Parms, DamageTarget), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventCalculateDamageValue_Parms, Damage), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_Multiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_DamageInstigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_DamageTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::NewProp_Damage,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay|Effects" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "CalculateDamageValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::OmegaGameplayEffect_eventCalculateDamageValue_Parms), Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue_Statics::Function_MetaDataParams)) };
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay|Effects" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplayEffect, nullptr, "EffectApplied", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied_Statics::Function_MetaDataParams)) };
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectInstigator_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EffectInstigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetedActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_EffectInstigator_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_EffectInstigator = { "EffectInstigator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventEffectBeginPlay_Parms, EffectInstigator), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_EffectInstigator_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_EffectInstigator_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_TargetedActor = { "TargetedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayEffect_eventEffectBeginPlay_Parms, TargetedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_EffectInstigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay_Statics::NewProp_TargetedActor,
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombatantInstigator_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatantInstigator;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EffectTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EffectTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOmegaGameplayEffect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AOmegaGameplayEffect_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_CalculateDamageValue, "CalculateDamageValue" }, // 449229934
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_EffectApplied, "EffectApplied" }, // 2862743809
		{ &Z_Construct_UFunction_AOmegaGameplayEffect_EffectBeginPlay, "EffectBeginPlay" }, // 2776874715
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator = { "CombatantInstigator", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, CombatantInstigator), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetActor_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetActor_MetaData)) };
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
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime = { "EffectLifetime", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, EffectLifetime), Z_Construct_UEnum_OmegaGameFramework_EEffectLifetime, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_MetaData)) }; // 1849439467
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "Comment", "//-----Tags-----//\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplayEffect.h" },
		{ "ToolTip", "-----Tags-----" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags = { "EffectTags", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplayEffect, EffectTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOmegaGameplayEffect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_CombatantInstigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_TargetActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_bUseVolume,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_VolumeShape,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectLifetime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Lifetime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_DamageFormula,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_Power,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_LocalFormula,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplayEffect_Statics::NewProp_EffectTags,
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
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplayEffect_Statics::PropPointers),
		0,
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
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::EnumInfo[] = {
		{ EEffectLifetime_StaticEnum, TEXT("EEffectLifetime"), &Z_Registration_Info_UEnum_EEffectLifetime, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1849439467U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOmegaGameplayEffect, AOmegaGameplayEffect::StaticClass, TEXT("AOmegaGameplayEffect"), &Z_Registration_Info_UClass_AOmegaGameplayEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOmegaGameplayEffect), 1605516530U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_3317743199(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

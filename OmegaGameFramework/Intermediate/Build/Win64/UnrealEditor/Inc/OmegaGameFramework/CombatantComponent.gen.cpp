// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/CombatantComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatantComponent() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UAttributeModifierContainer_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplayEffect_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaAbility_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UEnhancedInputComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttributeSet_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFactionAffinity;
	static UEnum* EFactionAffinity_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EFactionAffinity.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EFactionAffinity.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("EFactionAffinity"));
		}
		return Z_Registration_Info_UEnum_EFactionAffinity.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EFactionAffinity>()
	{
		return EFactionAffinity_StaticEnum();
	}
	struct Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::Enumerators[] = {
		{ "NeutralAffinity", (int64)NeutralAffinity },
		{ "FriendlyAffinity", (int64)FriendlyAffinity },
		{ "HostileAffinity", (int64)HostileAffinity },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "FriendlyAffinity.DisplayName", "Friendly" },
		{ "FriendlyAffinity.Name", "FriendlyAffinity" },
		{ "HostileAffinity.DisplayName", "Hostile" },
		{ "HostileAffinity.Name", "HostileAffinity" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "NeutralAffinity.DisplayName", "Neutral" },
		{ "NeutralAffinity.Name", "NeutralAffinity" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		"EFactionAffinity",
		"EFactionAffinity",
		Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity()
	{
		if (!Z_Registration_Info_UEnum_EFactionAffinity.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFactionAffinity.InnerSingleton, Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EFactionAffinity.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnDamaged_Parms
		{
			UCombatantComponent* Combatant;
			UOmegaAttribute* Attribute;
			float FinalDamage;
			UObject* Instigator;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FinalDamage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnDamaged_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnDamaged_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_FinalDamage = { "FinalDamage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnDamaged_Parms, FinalDamage), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnDamaged_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_FinalDamage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnDamaged__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnDamaged_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnCombatantLevelChange_Parms
		{
			int32 NewLevel;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_NewLevel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::NewProp_NewLevel = { "NewLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnCombatantLevelChange_Parms, NewLevel), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::NewProp_NewLevel,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnCombatantLevelChange__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnCombatantLevelChange_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnTargetAdded_Parms
		{
			UCombatantComponent* Target;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTargetAdded_Parms, Target), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::NewProp_Target_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::NewProp_Target_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::NewProp_Target,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnTargetAdded__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnTargetAdded_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnTargetRemoved_Parms
		{
			UCombatantComponent* Target;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTargetRemoved_Parms, Target), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::NewProp_Target_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::NewProp_Target_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::NewProp_Target,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnTargetRemoved__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnTargetRemoved_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnAddedAsTarget_Parms
		{
			UCombatantComponent* Instigator;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::NewProp_Instigator_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAddedAsTarget_Parms, Instigator), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::NewProp_Instigator_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::NewProp_Instigator_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnAddedAsTarget__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnAddedAsTarget_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnRemovedAsTarget_Parms
		{
			UCombatantComponent* Instigator;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::NewProp_Instigator_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnRemovedAsTarget_Parms, Instigator), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::NewProp_Instigator_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::NewProp_Instigator_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnRemovedAsTarget__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnRemovedAsTarget_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnActiveTargetChanged_Parms
		{
			UCombatantComponent* ActiveTarget;
			bool Valid;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveTarget;
		static void NewProp_Valid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Valid;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_ActiveTarget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_ActiveTarget = { "ActiveTarget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnActiveTargetChanged_Parms, ActiveTarget), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_ActiveTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_ActiveTarget_MetaData)) };
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_Valid_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnActiveTargetChanged_Parms*)Obj)->Valid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_Valid = { "Valid", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnActiveTargetChanged_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_Valid_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_ActiveTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::NewProp_Valid,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnActiveTargetChanged__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnActiveTargetChanged_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UCombatantComponent::execClearActiveTarget)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearActiveTarget();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execSetActiveTarget)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetActiveTarget(Z_Param_Combatant);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execClearTargetList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearTargetList();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execRemoveTargetFromList)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveTargetFromList(Z_Param_Combatant);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execAddTargetsToList)
	{
		P_GET_TARRAY(UCombatantComponent*,Z_Param_Combatants);
		P_GET_UBOOL(Z_Param_bClearListFirst);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTargetsToList(Z_Param_Combatants,Z_Param_bClearListFirst);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execAddTargetToList)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTargetToList(Z_Param_Combatant);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execRemoveEffectsWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_EffectTags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveEffectsWithTags(Z_Param_EffectTags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execRemoveEffectsOfCategory)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_CategoryTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveEffectsOfCategory(Z_Param_CategoryTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetValidActiveEffects)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<AOmegaGameplayEffect*>*)Z_Param__Result=P_THIS->GetValidActiveEffects();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetActiveEffectOfClass)
	{
		P_GET_OBJECT(UClass,Z_Param_EffectClass);
		P_GET_UBOOL_REF(Z_Param_Out_bIsValid);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOmegaGameplayEffect**)Z_Param__Result=P_THIS->GetActiveEffectOfClass(Z_Param_EffectClass,Z_Param_Out_bIsValid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetEffectsOfCategory)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_CategoryTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<AOmegaGameplayEffect*>*)Z_Param__Result=P_THIS->GetEffectsOfCategory(Z_Param_CategoryTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetEffectsWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<AOmegaGameplayEffect*>*)Z_Param__Result=P_THIS->GetEffectsWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execTriggerEffectsOfCategory)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_CategoryTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TriggerEffectsOfCategory(Z_Param_CategoryTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execTriggerEffectsWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TriggerEffectsWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execCreateEffect)
	{
		P_GET_OBJECT(UClass,Z_Param_EffectClass);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Power);
		P_GET_STRUCT(FTransform,Z_Param_Location);
		P_GET_OBJECT(UCombatantComponent,Z_Param_Target);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_AddedTags);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOmegaGameplayEffect**)Z_Param__Result=P_THIS->CreateEffect(Z_Param_EffectClass,Z_Param_Power,Z_Param_Location,Z_Param_Target,Z_Param_AddedTags,Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAttributeModifiers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UObject*>*)Z_Param__Result=P_THIS->GetAttributeModifiers();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAttributeComparedValue)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_TARRAY(UObject*,Z_Param_Modifiers);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetAttributeComparedValue(Z_Param_Attribute,Z_Param_Modifiers);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execRemoveAttributeModifersWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveAttributeModifersWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execRemoveAttributeModifier)
	{
		P_GET_OBJECT(UObject,Z_Param_Modifier);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveAttributeModifier(Z_Param_Modifier);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execAddAttrbuteModifier)
	{
		P_GET_OBJECT(UObject,Z_Param_Modifier);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddAttrbuteModifier(Z_Param_Modifier);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execCreateAttributeModifier)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Increment);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Multiplier);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAttributeModifierContainer**)Z_Param__Result=P_THIS->CreateAttributeModifier(Z_Param_Attribute,Z_Param_Increment,Z_Param_Multiplier,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execSetCombatantLevel)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NewLevel);
		P_GET_UBOOL(Z_Param_ReinitializeStats);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCombatantLevel(Z_Param_NewLevel,Z_Param_ReinitializeStats);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execSetCurrentAttributeValues)
	{
		P_GET_TMAP(UOmegaAttribute*,float,Z_Param_Values);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentAttributeValues(Z_Param_Values);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetCurrentAttributeValues)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<UOmegaAttribute*,float>*)Z_Param__Result=P_THIS->GetCurrentAttributeValues();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAttributePercentage)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetAttributePercentage(Z_Param_Attribute);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAttributeBaseValue)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetAttributeBaseValue(Z_Param_Attribute);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAttributeValue)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_CurrentValue);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_MaxValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAttributeValue(Z_Param_Attribute,Z_Param_Out_CurrentValue,Z_Param_Out_MaxValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execApplyAttributeDamage)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_PROPERTY(FFloatProperty,Z_Param_BaseDamage);
		P_GET_OBJECT(UObject,Z_Param_Instigator);
		P_GET_OBJECT(UObject,Z_Param_DamageModifier);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->ApplyAttributeDamage(Z_Param_Attribute,Z_Param_BaseDamage,Z_Param_Instigator,Z_Param_DamageModifier);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execInitializeFromAsset)
	{
		P_GET_OBJECT(UObject,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitializeFromAsset(Z_Param_Asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execIsAbilityTagBlocked)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsAbilityTagBlocked(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execCancelAbilitiesWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CancelAbilitiesWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetGrantedAbilitiesWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<AOmegaAbility*>*)Z_Param__Result=P_THIS->GetGrantedAbilitiesWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetGrantedAbilities)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<AOmegaAbility*>*)Z_Param__Result=P_THIS->GetGrantedAbilities();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetActiveAbilitiesWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<AOmegaAbility*>*)Z_Param__Result=P_THIS->GetActiveAbilitiesWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetActiveAbilities)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<AOmegaAbility*>*)Z_Param__Result=P_THIS->GetActiveAbilities();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execIsAbilityActive)
	{
		P_GET_OBJECT(UClass,Z_Param_AbilityClass);
		P_GET_OBJECT_REF(AOmegaAbility,Z_Param_Out_Ability);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsAbilityActive(Z_Param_AbilityClass,Z_Param_Out_Ability);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execStopAbility)
	{
		P_GET_OBJECT(UClass,Z_Param_AbilityClass);
		P_GET_UBOOL(Z_Param_Cancel);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->StopAbility(Z_Param_AbilityClass,Z_Param_Cancel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execExecuteAbility)
	{
		P_GET_OBJECT(UClass,Z_Param_AbilityClass);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOmegaAbility**)Z_Param__Result=P_THIS->ExecuteAbility(Z_Param_AbilityClass,Z_Param_Context,Z_Param_Out_bSuccess);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAbility)
	{
		P_GET_OBJECT(UClass,Z_Param_AbilityClass);
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOmegaAbility**)Z_Param__Result=P_THIS->GetAbility(Z_Param_AbilityClass,Z_Param_Out_bSuccess);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execUngrantAbility)
	{
		P_GET_OBJECT(UClass,Z_Param_AbilityClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->UngrantAbility(Z_Param_AbilityClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGrantAbility)
	{
		P_GET_OBJECT(UClass,Z_Param_AbilityClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GrantAbility(Z_Param_AbilityClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetOwnerPlayerController)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(APlayerController**)Z_Param__Result=P_THIS->GetOwnerPlayerController();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetOwnerController)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AController**)Z_Param__Result=P_THIS->GetOwnerController();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetOwnerCharacter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ACharacter**)Z_Param__Result=P_THIS->GetOwnerCharacter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetOwnerPawn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(APawn**)Z_Param__Result=P_THIS->GetOwnerPawn();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execUpdate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Update();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execCombatantHasAllTag)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_UBOOL(Z_Param_Exact);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CombatantHasAllTag(Z_Param_Tags,Z_Param_Exact);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execCombatantHasAnyTag)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_UBOOL(Z_Param_Exact);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CombatantHasAnyTag(Z_Param_Tags,Z_Param_Exact);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execCombatantHasTag)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_Tag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CombatantHasTag(Z_Param_Tag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetCombatantTags)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetCombatantTags();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execRemoveTagsFromCombatant)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveTagsFromCombatant(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execAddTagsToCombatant)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTagsToCombatant(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execRemoveSkill)
	{
		P_GET_OBJECT(UPrimaryDataAsset,Z_Param_Skill);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveSkill(Z_Param_Skill);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execAddSkill)
	{
		P_GET_OBJECT(UPrimaryDataAsset,Z_Param_Skill);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddSkill(Z_Param_Skill);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execFilterCombatantsByAffinity)
	{
		P_GET_TARRAY(UCombatantComponent*,Z_Param_Combatants);
		P_GET_PROPERTY(FByteProperty,Z_Param_Affinity);
		P_GET_UBOOL(Z_Param_bExclude);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UCombatantComponent*>*)Z_Param__Result=P_THIS->FilterCombatantsByAffinity(Z_Param_Combatants,EFactionAffinity(Z_Param_Affinity),Z_Param_bExclude);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAffinityToCombatant)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_CheckedCombatant);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TEnumAsByte<EFactionAffinity>*)Z_Param__Result=P_THIS->GetAffinityToCombatant(Z_Param_CheckedCombatant);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetFactionTag)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTag*)Z_Param__Result=P_THIS->GetFactionTag();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAttributeLevel)
	{
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetAttributeLevel(Z_Param_Attribute);
		P_NATIVE_END;
	}
	void UCombatantComponent::StaticRegisterNativesUCombatantComponent()
	{
		UClass* Class = UCombatantComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAttrbuteModifier", &UCombatantComponent::execAddAttrbuteModifier },
			{ "AddSkill", &UCombatantComponent::execAddSkill },
			{ "AddTagsToCombatant", &UCombatantComponent::execAddTagsToCombatant },
			{ "AddTargetsToList", &UCombatantComponent::execAddTargetsToList },
			{ "AddTargetToList", &UCombatantComponent::execAddTargetToList },
			{ "ApplyAttributeDamage", &UCombatantComponent::execApplyAttributeDamage },
			{ "CancelAbilitiesWithTags", &UCombatantComponent::execCancelAbilitiesWithTags },
			{ "ClearActiveTarget", &UCombatantComponent::execClearActiveTarget },
			{ "ClearTargetList", &UCombatantComponent::execClearTargetList },
			{ "CombatantHasAllTag", &UCombatantComponent::execCombatantHasAllTag },
			{ "CombatantHasAnyTag", &UCombatantComponent::execCombatantHasAnyTag },
			{ "CombatantHasTag", &UCombatantComponent::execCombatantHasTag },
			{ "CreateAttributeModifier", &UCombatantComponent::execCreateAttributeModifier },
			{ "CreateEffect", &UCombatantComponent::execCreateEffect },
			{ "ExecuteAbility", &UCombatantComponent::execExecuteAbility },
			{ "FilterCombatantsByAffinity", &UCombatantComponent::execFilterCombatantsByAffinity },
			{ "GetAbility", &UCombatantComponent::execGetAbility },
			{ "GetActiveAbilities", &UCombatantComponent::execGetActiveAbilities },
			{ "GetActiveAbilitiesWithTags", &UCombatantComponent::execGetActiveAbilitiesWithTags },
			{ "GetActiveEffectOfClass", &UCombatantComponent::execGetActiveEffectOfClass },
			{ "GetAffinityToCombatant", &UCombatantComponent::execGetAffinityToCombatant },
			{ "GetAttributeBaseValue", &UCombatantComponent::execGetAttributeBaseValue },
			{ "GetAttributeComparedValue", &UCombatantComponent::execGetAttributeComparedValue },
			{ "GetAttributeLevel", &UCombatantComponent::execGetAttributeLevel },
			{ "GetAttributeModifiers", &UCombatantComponent::execGetAttributeModifiers },
			{ "GetAttributePercentage", &UCombatantComponent::execGetAttributePercentage },
			{ "GetAttributeValue", &UCombatantComponent::execGetAttributeValue },
			{ "GetCombatantTags", &UCombatantComponent::execGetCombatantTags },
			{ "GetCurrentAttributeValues", &UCombatantComponent::execGetCurrentAttributeValues },
			{ "GetEffectsOfCategory", &UCombatantComponent::execGetEffectsOfCategory },
			{ "GetEffectsWithTags", &UCombatantComponent::execGetEffectsWithTags },
			{ "GetFactionTag", &UCombatantComponent::execGetFactionTag },
			{ "GetGrantedAbilities", &UCombatantComponent::execGetGrantedAbilities },
			{ "GetGrantedAbilitiesWithTags", &UCombatantComponent::execGetGrantedAbilitiesWithTags },
			{ "GetOwnerCharacter", &UCombatantComponent::execGetOwnerCharacter },
			{ "GetOwnerController", &UCombatantComponent::execGetOwnerController },
			{ "GetOwnerPawn", &UCombatantComponent::execGetOwnerPawn },
			{ "GetOwnerPlayerController", &UCombatantComponent::execGetOwnerPlayerController },
			{ "GetValidActiveEffects", &UCombatantComponent::execGetValidActiveEffects },
			{ "GrantAbility", &UCombatantComponent::execGrantAbility },
			{ "InitializeFromAsset", &UCombatantComponent::execInitializeFromAsset },
			{ "IsAbilityActive", &UCombatantComponent::execIsAbilityActive },
			{ "IsAbilityTagBlocked", &UCombatantComponent::execIsAbilityTagBlocked },
			{ "RemoveAttributeModifersWithTags", &UCombatantComponent::execRemoveAttributeModifersWithTags },
			{ "RemoveAttributeModifier", &UCombatantComponent::execRemoveAttributeModifier },
			{ "RemoveEffectsOfCategory", &UCombatantComponent::execRemoveEffectsOfCategory },
			{ "RemoveEffectsWithTags", &UCombatantComponent::execRemoveEffectsWithTags },
			{ "RemoveSkill", &UCombatantComponent::execRemoveSkill },
			{ "RemoveTagsFromCombatant", &UCombatantComponent::execRemoveTagsFromCombatant },
			{ "RemoveTargetFromList", &UCombatantComponent::execRemoveTargetFromList },
			{ "SetActiveTarget", &UCombatantComponent::execSetActiveTarget },
			{ "SetCombatantLevel", &UCombatantComponent::execSetCombatantLevel },
			{ "SetCurrentAttributeValues", &UCombatantComponent::execSetCurrentAttributeValues },
			{ "StopAbility", &UCombatantComponent::execStopAbility },
			{ "TriggerEffectsOfCategory", &UCombatantComponent::execTriggerEffectsOfCategory },
			{ "TriggerEffectsWithTags", &UCombatantComponent::execTriggerEffectsWithTags },
			{ "UngrantAbility", &UCombatantComponent::execUngrantAbility },
			{ "Update", &UCombatantComponent::execUpdate },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics
	{
		struct CombatantComponent_eventAddAttrbuteModifier_Parms
		{
			UObject* Modifier;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Modifier;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::NewProp_Modifier = { "Modifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventAddAttrbuteModifier_Parms, Modifier), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventAddAttrbuteModifier_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventAddAttrbuteModifier_Parms), &Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::NewProp_Modifier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes|Modifiers" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "AddAttrbuteModifier", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::CombatantComponent_eventAddAttrbuteModifier_Parms), Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics
	{
		struct CombatantComponent_eventAddSkill_Parms
		{
			UPrimaryDataAsset* Skill;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Skill;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::NewProp_Skill = { "Skill", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventAddSkill_Parms, Skill), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::NewProp_Skill,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::Function_MetaDataParams[] = {
		{ "Category", "Skills" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "AddSkill", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::CombatantComponent_eventAddSkill_Parms), Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_AddSkill()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_AddSkill_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics
	{
		struct CombatantComponent_eventAddTagsToCombatant_Parms
		{
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventAddTagsToCombatant_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant|Tags" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "AddTagsToCombatant", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::CombatantComponent_eventAddTagsToCombatant_Parms), Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics
	{
		struct CombatantComponent_eventAddTargetsToList_Parms
		{
			TArray<UCombatantComponent*> Combatants;
			bool bClearListFirst;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatants_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatants_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Combatants;
		static void NewProp_bClearListFirst_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bClearListFirst;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_Combatants_Inner = { "Combatants", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_Combatants_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_Combatants = { "Combatants", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventAddTargetsToList_Parms, Combatants), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_Combatants_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_Combatants_MetaData)) };
	void Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_bClearListFirst_SetBit(void* Obj)
	{
		((CombatantComponent_eventAddTargetsToList_Parms*)Obj)->bClearListFirst = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_bClearListFirst = { "bClearListFirst", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventAddTargetsToList_Parms), &Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_bClearListFirst_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_Combatants_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_Combatants,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::NewProp_bClearListFirst,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "AddTargetsToList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::CombatantComponent_eventAddTargetsToList_Parms), Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_AddTargetsToList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_AddTargetsToList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics
	{
		struct CombatantComponent_eventAddTargetToList_Parms
		{
			UCombatantComponent* Combatant;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventAddTargetToList_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::NewProp_Combatant,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "AddTargetToList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::CombatantComponent_eventAddTargetToList_Parms), Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_AddTargetToList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_AddTargetToList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics
	{
		struct CombatantComponent_eventApplyAttributeDamage_Parms
		{
			UOmegaAttribute* Attribute;
			float BaseDamage;
			UObject* Instigator;
			UObject* DamageModifier;
			float ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageModifier;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventApplyAttributeDamage_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_BaseDamage = { "BaseDamage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventApplyAttributeDamage_Parms, BaseDamage), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventApplyAttributeDamage_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_DamageModifier = { "DamageModifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventApplyAttributeDamage_Parms, DamageModifier), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventApplyAttributeDamage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_BaseDamage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_Instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_DamageModifier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Instigator" },
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "ApplyAttributeDamage", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::CombatantComponent_eventApplyAttributeDamage_Parms), Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics
	{
		struct CombatantComponent_eventCancelAbilitiesWithTags_Parms
		{
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCancelAbilitiesWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "CancelAbilitiesWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::CombatantComponent_eventCancelAbilitiesWithTags_Parms), Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "ClearActiveTarget", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_ClearTargetList_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_ClearTargetList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_ClearTargetList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "ClearTargetList", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_ClearTargetList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_ClearTargetList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_ClearTargetList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_ClearTargetList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics
	{
		struct CombatantComponent_eventCombatantHasAllTag_Parms
		{
			FGameplayTagContainer Tags;
			bool Exact;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_Exact_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Exact;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCombatantHasAllTag_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_Exact_SetBit(void* Obj)
	{
		((CombatantComponent_eventCombatantHasAllTag_Parms*)Obj)->Exact = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_Exact = { "Exact", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventCombatantHasAllTag_Parms), &Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_Exact_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventCombatantHasAllTag_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventCombatantHasAllTag_Parms), &Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_Exact,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Exact" },
		{ "Category", "Combatant|Tags" },
		{ "CPP_Default_Exact", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "CombatantHasAllTag", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::CombatantComponent_eventCombatantHasAllTag_Parms), Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics
	{
		struct CombatantComponent_eventCombatantHasAnyTag_Parms
		{
			FGameplayTagContainer Tags;
			bool Exact;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_Exact_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Exact;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCombatantHasAnyTag_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_Exact_SetBit(void* Obj)
	{
		((CombatantComponent_eventCombatantHasAnyTag_Parms*)Obj)->Exact = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_Exact = { "Exact", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventCombatantHasAnyTag_Parms), &Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_Exact_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventCombatantHasAnyTag_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventCombatantHasAnyTag_Parms), &Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_Exact,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Exact" },
		{ "Category", "Combatant|Tags," },
		{ "CPP_Default_Exact", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "CombatantHasAnyTag", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::CombatantComponent_eventCombatantHasAnyTag_Parms), Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics
	{
		struct CombatantComponent_eventCombatantHasTag_Parms
		{
			FGameplayTag Tag;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCombatantHasTag_Parms, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	void Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventCombatantHasTag_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventCombatantHasTag_Parms), &Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::NewProp_Tag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant|Tags" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "CombatantHasTag", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::CombatantComponent_eventCombatantHasTag_Parms), Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_CombatantHasTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_CombatantHasTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics
	{
		struct CombatantComponent_eventCreateAttributeModifier_Parms
		{
			UOmegaAttribute* Attribute;
			float Increment;
			float Multiplier;
			FGameplayTagContainer Tags;
			UAttributeModifierContainer* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Increment;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Multiplier;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateAttributeModifier_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Increment = { "Increment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateAttributeModifier_Parms, Increment), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Multiplier = { "Multiplier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateAttributeModifier_Parms, Multiplier), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateAttributeModifier_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateAttributeModifier_Parms, ReturnValue), Z_Construct_UClass_UAttributeModifierContainer_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Increment,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Multiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Category, Tags" },
		{ "Category", "Attributes|Modifiers" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "CreateAttributeModifier", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::CombatantComponent_eventCreateAttributeModifier_Parms), Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics
	{
		struct CombatantComponent_eventCreateEffect_Parms
		{
			TSubclassOf<AOmegaGameplayEffect>  EffectClass;
			float Power;
			FTransform Location;
			UCombatantComponent* Target;
			FGameplayTagContainer AddedTags;
			UObject* Context;
			AOmegaGameplayEffect* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_EffectClass;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FStructPropertyParams NewProp_AddedTags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_EffectClass = { "EffectClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, EffectClass), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, Power), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, Location), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, Target), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Target_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Target_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_AddedTags = { "AddedTags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, AddedTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, ReturnValue), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_EffectClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Power,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_AddedTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "AddedTags, Location" },
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "CreateEffect", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::CombatantComponent_eventCreateEffect_Parms), Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_CreateEffect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics
	{
		struct CombatantComponent_eventExecuteAbility_Parms
		{
			TSubclassOf<AOmegaAbility>  AbilityClass;
			UObject* Context;
			bool bSuccess;
			AOmegaAbility* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_AbilityClass = { "AbilityClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventExecuteAbility_Parms, AbilityClass), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventExecuteAbility_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((CombatantComponent_eventExecuteAbility_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventExecuteAbility_Parms), &Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventExecuteAbility_Parms, ReturnValue), Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_AbilityClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_bSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Context" },
		{ "Category", "\xce\xa9|Ability" },
		{ "Comment", "///////Ability Activation\n" },
		{ "DisplayName", "Activate Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/Ability Activation" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "ExecuteAbility", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::CombatantComponent_eventExecuteAbility_Parms), Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_ExecuteAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_ExecuteAbility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics
	{
		struct CombatantComponent_eventFilterCombatantsByAffinity_Parms
		{
			TArray<UCombatantComponent*> Combatants;
			TEnumAsByte<EFactionAffinity> Affinity;
			bool bExclude;
			TArray<UCombatantComponent*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatants_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatants_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Combatants;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Affinity;
		static void NewProp_bExclude_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bExclude;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Combatants_Inner = { "Combatants", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Combatants_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Combatants = { "Combatants", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventFilterCombatantsByAffinity_Parms, Combatants), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Combatants_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Combatants_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Affinity = { "Affinity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventFilterCombatantsByAffinity_Parms, Affinity), Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity, METADATA_PARAMS(nullptr, 0) }; // 2251981861
	void Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_bExclude_SetBit(void* Obj)
	{
		((CombatantComponent_eventFilterCombatantsByAffinity_Parms*)Obj)->bExclude = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_bExclude = { "bExclude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventFilterCombatantsByAffinity_Parms), &Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_bExclude_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventFilterCombatantsByAffinity_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Combatants_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Combatants,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_Affinity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_bExclude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::Function_MetaDataParams[] = {
		{ "Category", "Faction" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "FilterCombatantsByAffinity", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::CombatantComponent_eventFilterCombatantsByAffinity_Parms), Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics
	{
		struct CombatantComponent_eventGetAbility_Parms
		{
			TSubclassOf<AOmegaAbility>  AbilityClass;
			bool bSuccess;
			AOmegaAbility* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityClass;
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_AbilityClass = { "AbilityClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAbility_Parms, AbilityClass), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((CombatantComponent_eventGetAbility_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventGetAbility_Parms), &Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAbility_Parms, ReturnValue), Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_AbilityClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_bSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAbility", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::CombatantComponent_eventGetAbility_Parms), Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAbility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics
	{
		struct CombatantComponent_eventGetActiveAbilities_Parms
		{
			TArray<AOmegaAbility*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetActiveAbilities_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetActiveAbilities", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::CombatantComponent_eventGetActiveAbilities_Parms), Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics
	{
		struct CombatantComponent_eventGetActiveAbilitiesWithTags_Parms
		{
			FGameplayTagContainer Tags;
			TArray<AOmegaAbility*> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetActiveAbilitiesWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetActiveAbilitiesWithTags_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetActiveAbilitiesWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::CombatantComponent_eventGetActiveAbilitiesWithTags_Parms), Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics
	{
		struct CombatantComponent_eventGetActiveEffectOfClass_Parms
		{
			TSubclassOf<AOmegaGameplayEffect>  EffectClass;
			bool bIsValid;
			AOmegaGameplayEffect* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_EffectClass;
		static void NewProp_bIsValid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_EffectClass = { "EffectClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetActiveEffectOfClass_Parms, EffectClass), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_bIsValid_SetBit(void* Obj)
	{
		((CombatantComponent_eventGetActiveEffectOfClass_Parms*)Obj)->bIsValid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventGetActiveEffectOfClass_Parms), &Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetActiveEffectOfClass_Parms, ReturnValue), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_EffectClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_bIsValid,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetActiveEffectOfClass", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::CombatantComponent_eventGetActiveEffectOfClass_Parms), Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics
	{
		struct CombatantComponent_eventGetAffinityToCombatant_Parms
		{
			UCombatantComponent* CheckedCombatant;
			TEnumAsByte<EFactionAffinity> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CheckedCombatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CheckedCombatant;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::NewProp_CheckedCombatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::NewProp_CheckedCombatant = { "CheckedCombatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAffinityToCombatant_Parms, CheckedCombatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::NewProp_CheckedCombatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::NewProp_CheckedCombatant_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAffinityToCombatant_Parms, ReturnValue), Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity, METADATA_PARAMS(nullptr, 0) }; // 2251981861
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::NewProp_CheckedCombatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::Function_MetaDataParams[] = {
		{ "Category", "Faction" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAffinityToCombatant", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::CombatantComponent_eventGetAffinityToCombatant_Parms), Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics
	{
		struct CombatantComponent_eventGetAttributeBaseValue_Parms
		{
			UOmegaAttribute* Attribute;
			float ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeBaseValue_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeBaseValue_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAttributeBaseValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::CombatantComponent_eventGetAttributeBaseValue_Parms), Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics
	{
		struct CombatantComponent_eventGetAttributeComparedValue_Parms
		{
			UOmegaAttribute* Attribute;
			TArray<UObject*> Modifiers;
			float ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Modifiers_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Modifiers;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeComparedValue_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_Modifiers_Inner = { "Modifiers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_Modifiers = { "Modifiers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeComparedValue_Parms, Modifiers), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeComparedValue_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_Modifiers_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_Modifiers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes|Modifiers" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAttributeComparedValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::CombatantComponent_eventGetAttributeComparedValue_Parms), Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics
	{
		struct CombatantComponent_eventGetAttributeLevel_Parms
		{
			UOmegaAttribute* Attribute;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeLevel_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeLevel_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Modifiers" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAttributeLevel", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::CombatantComponent_eventGetAttributeLevel_Parms), Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics
	{
		struct CombatantComponent_eventGetAttributeModifiers_Parms
		{
			TArray<UObject*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeModifiers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes|Modifiers" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAttributeModifiers", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::CombatantComponent_eventGetAttributeModifiers_Parms), Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics
	{
		struct CombatantComponent_eventGetAttributePercentage_Parms
		{
			UOmegaAttribute* Attribute;
			float ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributePercentage_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributePercentage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAttributePercentage", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::CombatantComponent_eventGetAttributePercentage_Parms), Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics
	{
		struct CombatantComponent_eventGetAttributeValue_Parms
		{
			UOmegaAttribute* Attribute;
			float CurrentValue;
			float MaxValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentValue;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeValue_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::NewProp_CurrentValue = { "CurrentValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeValue_Parms, CurrentValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::NewProp_MaxValue = { "MaxValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetAttributeValue_Parms, MaxValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::NewProp_CurrentValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::NewProp_MaxValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetAttributeValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::CombatantComponent_eventGetAttributeValue_Parms), Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetAttributeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetAttributeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics
	{
		struct CombatantComponent_eventGetCombatantTags_Parms
		{
			FGameplayTagContainer ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetCombatantTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant|Tags" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetCombatantTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::CombatantComponent_eventGetCombatantTags_Parms), Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetCombatantTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetCombatantTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics
	{
		struct CombatantComponent_eventGetCurrentAttributeValues_Parms
		{
			TMap<UOmegaAttribute*,float> ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetCurrentAttributeValues_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetCurrentAttributeValues", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::CombatantComponent_eventGetCurrentAttributeValues_Parms), Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics
	{
		struct CombatantComponent_eventGetEffectsOfCategory_Parms
		{
			FGameplayTag CategoryTag;
			TArray<AOmegaGameplayEffect*> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_CategoryTag;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::NewProp_CategoryTag = { "CategoryTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetEffectsOfCategory_Parms, CategoryTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetEffectsOfCategory_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::NewProp_CategoryTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetEffectsOfCategory", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::CombatantComponent_eventGetEffectsOfCategory_Parms), Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics
	{
		struct CombatantComponent_eventGetEffectsWithTags_Parms
		{
			FGameplayTagContainer Tags;
			TArray<AOmegaGameplayEffect*> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetEffectsWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetEffectsWithTags_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetEffectsWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::CombatantComponent_eventGetEffectsWithTags_Parms), Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics
	{
		struct CombatantComponent_eventGetFactionTag_Parms
		{
			FGameplayTag ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetFactionTag_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Faction" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetFactionTag", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::CombatantComponent_eventGetFactionTag_Parms), Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetFactionTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetFactionTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics
	{
		struct CombatantComponent_eventGetGrantedAbilities_Parms
		{
			TArray<AOmegaAbility*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetGrantedAbilities_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetGrantedAbilities", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::CombatantComponent_eventGetGrantedAbilities_Parms), Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics
	{
		struct CombatantComponent_eventGetGrantedAbilitiesWithTags_Parms
		{
			FGameplayTagContainer Tags;
			TArray<AOmegaAbility*> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetGrantedAbilitiesWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetGrantedAbilitiesWithTags_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetGrantedAbilitiesWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::CombatantComponent_eventGetGrantedAbilitiesWithTags_Parms), Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics
	{
		struct CombatantComponent_eventGetOwnerCharacter_Parms
		{
			ACharacter* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetOwnerCharacter_Parms, ReturnValue), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "Comment", "//Tries to get the owning actor as a Character.\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "Tries to get the owning actor as a Character." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetOwnerCharacter", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::CombatantComponent_eventGetOwnerCharacter_Parms), Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics
	{
		struct CombatantComponent_eventGetOwnerController_Parms
		{
			AController* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetOwnerController_Parms, ReturnValue), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "Comment", "//Tries to get the owning actor OR the owning actor's controller.\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "Tries to get the owning actor OR the owning actor's controller." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetOwnerController", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::CombatantComponent_eventGetOwnerController_Parms), Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetOwnerController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetOwnerController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics
	{
		struct CombatantComponent_eventGetOwnerPawn_Parms
		{
			APawn* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetOwnerPawn_Parms, ReturnValue), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "Comment", "//Tries to get the owning actor as a Pawn.\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "Tries to get the owning actor as a Pawn." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetOwnerPawn", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::CombatantComponent_eventGetOwnerPawn_Parms), Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics
	{
		struct CombatantComponent_eventGetOwnerPlayerController_Parms
		{
			APlayerController* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetOwnerPlayerController_Parms, ReturnValue), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "Comment", "//Tries to get the owning actor OR the owning actor's controller as a player controller.\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "Tries to get the owning actor OR the owning actor's controller as a player controller." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetOwnerPlayerController", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::CombatantComponent_eventGetOwnerPlayerController_Parms), Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics
	{
		struct CombatantComponent_eventGetValidActiveEffects_Parms
		{
			TArray<AOmegaGameplayEffect*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGetValidActiveEffects_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GetValidActiveEffects", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::CombatantComponent_eventGetValidActiveEffects_Parms), Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics
	{
		struct CombatantComponent_eventGrantAbility_Parms
		{
			TSubclassOf<AOmegaAbility>  AbilityClass;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityClass;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::NewProp_AbilityClass = { "AbilityClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventGrantAbility_Parms, AbilityClass), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventGrantAbility_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventGrantAbility_Parms), &Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::NewProp_AbilityClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "Comment", "///////Ability Possession\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/Ability Possession" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "GrantAbility", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::CombatantComponent_eventGrantAbility_Parms), Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_GrantAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_GrantAbility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics
	{
		struct CombatantComponent_eventInitializeFromAsset_Parms
		{
			UObject* Asset;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventInitializeFromAsset_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::NewProp_Asset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "Comment", "//Initializes the Combatants from an asset implementing \"DataInterface_Combatant\"\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "Initializes the Combatants from an asset implementing \"DataInterface_Combatant\"" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "InitializeFromAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::CombatantComponent_eventInitializeFromAsset_Parms), Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics
	{
		struct CombatantComponent_eventIsAbilityActive_Parms
		{
			TSubclassOf<AOmegaAbility>  AbilityClass;
			AOmegaAbility* Ability;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Ability;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_AbilityClass = { "AbilityClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventIsAbilityActive_Parms, AbilityClass), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_Ability = { "Ability", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventIsAbilityActive_Parms, Ability), Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventIsAbilityActive_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventIsAbilityActive_Parms), &Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_AbilityClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_Ability,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "IsAbilityActive", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::CombatantComponent_eventIsAbilityActive_Parms), Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_IsAbilityActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_IsAbilityActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics
	{
		struct CombatantComponent_eventIsAbilityTagBlocked_Parms
		{
			FGameplayTagContainer Tags;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventIsAbilityTagBlocked_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventIsAbilityTagBlocked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventIsAbilityTagBlocked_Parms), &Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "IsAbilityTagBlocked", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::CombatantComponent_eventIsAbilityTagBlocked_Parms), Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics
	{
		struct CombatantComponent_eventRemoveAttributeModifersWithTags_Parms
		{
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventRemoveAttributeModifersWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes|Modifiers" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "RemoveAttributeModifersWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::CombatantComponent_eventRemoveAttributeModifersWithTags_Parms), Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics
	{
		struct CombatantComponent_eventRemoveAttributeModifier_Parms
		{
			UObject* Modifier;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Modifier;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::NewProp_Modifier = { "Modifier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventRemoveAttributeModifier_Parms, Modifier), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventRemoveAttributeModifier_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventRemoveAttributeModifier_Parms), &Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::NewProp_Modifier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes|Modifiers" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "RemoveAttributeModifier", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::CombatantComponent_eventRemoveAttributeModifier_Parms), Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics
	{
		struct CombatantComponent_eventRemoveEffectsOfCategory_Parms
		{
			FGameplayTag CategoryTag;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_CategoryTag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::NewProp_CategoryTag = { "CategoryTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventRemoveEffectsOfCategory_Parms, CategoryTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::NewProp_CategoryTag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "RemoveEffectsOfCategory", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::CombatantComponent_eventRemoveEffectsOfCategory_Parms), Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics
	{
		struct CombatantComponent_eventRemoveEffectsWithTags_Parms
		{
			FGameplayTagContainer EffectTags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_EffectTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::NewProp_EffectTags = { "EffectTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventRemoveEffectsWithTags_Parms, EffectTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::NewProp_EffectTags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "RemoveEffectsWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::CombatantComponent_eventRemoveEffectsWithTags_Parms), Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics
	{
		struct CombatantComponent_eventRemoveSkill_Parms
		{
			UPrimaryDataAsset* Skill;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Skill;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::NewProp_Skill = { "Skill", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventRemoveSkill_Parms, Skill), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::NewProp_Skill,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::Function_MetaDataParams[] = {
		{ "Category", "Skills" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "RemoveSkill", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::CombatantComponent_eventRemoveSkill_Parms), Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_RemoveSkill()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_RemoveSkill_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics
	{
		struct CombatantComponent_eventRemoveTagsFromCombatant_Parms
		{
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventRemoveTagsFromCombatant_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant|Tags" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "RemoveTagsFromCombatant", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::CombatantComponent_eventRemoveTagsFromCombatant_Parms), Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics
	{
		struct CombatantComponent_eventRemoveTargetFromList_Parms
		{
			UCombatantComponent* Combatant;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventRemoveTargetFromList_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::NewProp_Combatant,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "RemoveTargetFromList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::CombatantComponent_eventRemoveTargetFromList_Parms), Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics
	{
		struct CombatantComponent_eventSetActiveTarget_Parms
		{
			UCombatantComponent* Combatant;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventSetActiveTarget_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::NewProp_Combatant,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "SetActiveTarget", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::CombatantComponent_eventSetActiveTarget_Parms), Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_SetActiveTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_SetActiveTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics
	{
		struct CombatantComponent_eventSetCombatantLevel_Parms
		{
			int32 NewLevel;
			bool ReinitializeStats;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_NewLevel;
		static void NewProp_ReinitializeStats_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReinitializeStats;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::NewProp_NewLevel = { "NewLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventSetCombatantLevel_Parms, NewLevel), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::NewProp_ReinitializeStats_SetBit(void* Obj)
	{
		((CombatantComponent_eventSetCombatantLevel_Parms*)Obj)->ReinitializeStats = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::NewProp_ReinitializeStats = { "ReinitializeStats", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventSetCombatantLevel_Parms), &Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::NewProp_ReinitializeStats_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::NewProp_NewLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::NewProp_ReinitializeStats,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "SetCombatantLevel", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::CombatantComponent_eventSetCombatantLevel_Parms), Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics
	{
		struct CombatantComponent_eventSetCurrentAttributeValues_Parms
		{
			TMap<UOmegaAttribute*,float> Values;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Values_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Values_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_Values;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::NewProp_Values_ValueProp = { "Values", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::NewProp_Values_Key_KeyProp = { "Values_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::NewProp_Values = { "Values", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventSetCurrentAttributeValues_Parms, Values), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::NewProp_Values_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::NewProp_Values_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::NewProp_Values,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "SetCurrentAttributeValues", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::CombatantComponent_eventSetCurrentAttributeValues_Parms), Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics
	{
		struct CombatantComponent_eventStopAbility_Parms
		{
			TSubclassOf<AOmegaAbility>  AbilityClass;
			bool Cancel;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityClass;
		static void NewProp_Cancel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Cancel;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_AbilityClass = { "AbilityClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventStopAbility_Parms, AbilityClass), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_Cancel_SetBit(void* Obj)
	{
		((CombatantComponent_eventStopAbility_Parms*)Obj)->Cancel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_Cancel = { "Cancel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventStopAbility_Parms), &Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_Cancel_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventStopAbility_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventStopAbility_Parms), &Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_AbilityClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_Cancel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "StopAbility", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::CombatantComponent_eventStopAbility_Parms), Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_StopAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_StopAbility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics
	{
		struct CombatantComponent_eventTriggerEffectsOfCategory_Parms
		{
			FGameplayTag CategoryTag;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_CategoryTag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::NewProp_CategoryTag = { "CategoryTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventTriggerEffectsOfCategory_Parms, CategoryTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::NewProp_CategoryTag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "TriggerEffectsOfCategory", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::CombatantComponent_eventTriggerEffectsOfCategory_Parms), Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics
	{
		struct CombatantComponent_eventTriggerEffectsWithTags_Parms
		{
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventTriggerEffectsWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "TriggerEffectsWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::CombatantComponent_eventTriggerEffectsWithTags_Parms), Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics
	{
		struct CombatantComponent_eventUngrantAbility_Parms
		{
			TSubclassOf<AOmegaAbility>  AbilityClass;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_AbilityClass;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::NewProp_AbilityClass = { "AbilityClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventUngrantAbility_Parms, AbilityClass), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CombatantComponent_eventUngrantAbility_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantComponent_eventUngrantAbility_Parms), &Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::NewProp_AbilityClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "UngrantAbility", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::CombatantComponent_eventUngrantAbility_Parms), Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_UngrantAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_UngrantAbility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantComponent_Update_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_Update_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "Comment", "////////////////////////////////////\n////////// -- General -- ////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- General --" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantComponent_Update_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantComponent, nullptr, "Update", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantComponent_Update_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantComponent_Update_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantComponent_Update()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantComponent_Update_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCombatantComponent);
	UClass* Z_Construct_UClass_UCombatantComponent_NoRegister()
	{
		return UCombatantComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCombatantComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombatantDataAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatantDataAsset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OwnerInputComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerInputComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OwnerPawn_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerPawn;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveAbilities_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveAbilities_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveAbilities;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeSet;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AttributeLevels_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeLevels_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeLevels_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AttributeLevels;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeValueCategory_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AttributeValueCategory;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentAttributeValues_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentAttributeValues_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAttributeValues_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_CurrentAttributeValues;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FactionDataAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FactionDataAsset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FactionTag_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FactionTag;
		static const UECodeGen_Private::FBytePropertyParams NewProp_FactionAffinities_ValueProp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_FactionAffinities_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FactionAffinities_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_FactionAffinities;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Skills_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Skills_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Skills;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CategoryTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CategoryTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombatantTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CombatantTags;
		static const UECodeGen_Private::FClassPropertyParams NewProp_GrantedAbilities_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GrantedAbilities_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_GrantedAbilities;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilityList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AbilityList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AbilityList;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeModifiers_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeModifiers_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AttributeModifiers;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveEffects_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveEffects_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveEffects;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TargetList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTargetIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ActiveTargetIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTargetAdded_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTargetAdded;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTargetRemoved_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTargetRemoved;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAddedAsTarget_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAddedAsTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnRemovedAsTarget_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRemovedAsTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnActiveTargetChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActiveTargetChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnDamaged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDamaged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnLevelChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLevelChanged;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCombatantComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCombatantComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCombatantComponent_AddAttrbuteModifier, "AddAttrbuteModifier" }, // 3303392493
		{ &Z_Construct_UFunction_UCombatantComponent_AddSkill, "AddSkill" }, // 3512642939
		{ &Z_Construct_UFunction_UCombatantComponent_AddTagsToCombatant, "AddTagsToCombatant" }, // 3125330227
		{ &Z_Construct_UFunction_UCombatantComponent_AddTargetsToList, "AddTargetsToList" }, // 308302298
		{ &Z_Construct_UFunction_UCombatantComponent_AddTargetToList, "AddTargetToList" }, // 374101748
		{ &Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage, "ApplyAttributeDamage" }, // 2538490696
		{ &Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags, "CancelAbilitiesWithTags" }, // 4238267565
		{ &Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget, "ClearActiveTarget" }, // 3084126101
		{ &Z_Construct_UFunction_UCombatantComponent_ClearTargetList, "ClearTargetList" }, // 2442286266
		{ &Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag, "CombatantHasAllTag" }, // 2657451620
		{ &Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag, "CombatantHasAnyTag" }, // 224070953
		{ &Z_Construct_UFunction_UCombatantComponent_CombatantHasTag, "CombatantHasTag" }, // 1833558398
		{ &Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier, "CreateAttributeModifier" }, // 27755918
		{ &Z_Construct_UFunction_UCombatantComponent_CreateEffect, "CreateEffect" }, // 130138101
		{ &Z_Construct_UFunction_UCombatantComponent_ExecuteAbility, "ExecuteAbility" }, // 4085829566
		{ &Z_Construct_UFunction_UCombatantComponent_FilterCombatantsByAffinity, "FilterCombatantsByAffinity" }, // 3621035655
		{ &Z_Construct_UFunction_UCombatantComponent_GetAbility, "GetAbility" }, // 131757977
		{ &Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities, "GetActiveAbilities" }, // 2049473885
		{ &Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags, "GetActiveAbilitiesWithTags" }, // 912999139
		{ &Z_Construct_UFunction_UCombatantComponent_GetActiveEffectOfClass, "GetActiveEffectOfClass" }, // 2829206329
		{ &Z_Construct_UFunction_UCombatantComponent_GetAffinityToCombatant, "GetAffinityToCombatant" }, // 3198139871
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributeBaseValue, "GetAttributeBaseValue" }, // 2869662190
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributeComparedValue, "GetAttributeComparedValue" }, // 3955293191
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributeLevel, "GetAttributeLevel" }, // 46597127
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers, "GetAttributeModifiers" }, // 1716009310
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage, "GetAttributePercentage" }, // 3666893914
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributeValue, "GetAttributeValue" }, // 1467730161
		{ &Z_Construct_UFunction_UCombatantComponent_GetCombatantTags, "GetCombatantTags" }, // 3993221455
		{ &Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues, "GetCurrentAttributeValues" }, // 2695110659
		{ &Z_Construct_UFunction_UCombatantComponent_GetEffectsOfCategory, "GetEffectsOfCategory" }, // 3981441843
		{ &Z_Construct_UFunction_UCombatantComponent_GetEffectsWithTags, "GetEffectsWithTags" }, // 418494803
		{ &Z_Construct_UFunction_UCombatantComponent_GetFactionTag, "GetFactionTag" }, // 3770005381
		{ &Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilities, "GetGrantedAbilities" }, // 1987952233
		{ &Z_Construct_UFunction_UCombatantComponent_GetGrantedAbilitiesWithTags, "GetGrantedAbilitiesWithTags" }, // 4272999515
		{ &Z_Construct_UFunction_UCombatantComponent_GetOwnerCharacter, "GetOwnerCharacter" }, // 3197249567
		{ &Z_Construct_UFunction_UCombatantComponent_GetOwnerController, "GetOwnerController" }, // 1953406477
		{ &Z_Construct_UFunction_UCombatantComponent_GetOwnerPawn, "GetOwnerPawn" }, // 3783073737
		{ &Z_Construct_UFunction_UCombatantComponent_GetOwnerPlayerController, "GetOwnerPlayerController" }, // 2882663086
		{ &Z_Construct_UFunction_UCombatantComponent_GetValidActiveEffects, "GetValidActiveEffects" }, // 595954158
		{ &Z_Construct_UFunction_UCombatantComponent_GrantAbility, "GrantAbility" }, // 3186015960
		{ &Z_Construct_UFunction_UCombatantComponent_InitializeFromAsset, "InitializeFromAsset" }, // 286506366
		{ &Z_Construct_UFunction_UCombatantComponent_IsAbilityActive, "IsAbilityActive" }, // 2155676305
		{ &Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked, "IsAbilityTagBlocked" }, // 4107896820
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags, "RemoveAttributeModifersWithTags" }, // 664109662
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier, "RemoveAttributeModifier" }, // 2790237392
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveEffectsOfCategory, "RemoveEffectsOfCategory" }, // 2612575530
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveEffectsWithTags, "RemoveEffectsWithTags" }, // 3233452561
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveSkill, "RemoveSkill" }, // 1503474848
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant, "RemoveTagsFromCombatant" }, // 833418412
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList, "RemoveTargetFromList" }, // 1610601646
		{ &Z_Construct_UFunction_UCombatantComponent_SetActiveTarget, "SetActiveTarget" }, // 4143946976
		{ &Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel, "SetCombatantLevel" }, // 3474819152
		{ &Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues, "SetCurrentAttributeValues" }, // 3629896199
		{ &Z_Construct_UFunction_UCombatantComponent_StopAbility, "StopAbility" }, // 2418433152
		{ &Z_Construct_UFunction_UCombatantComponent_TriggerEffectsOfCategory, "TriggerEffectsOfCategory" }, // 3356495081
		{ &Z_Construct_UFunction_UCombatantComponent_TriggerEffectsWithTags, "TriggerEffectsWithTags" }, // 1205169193
		{ &Z_Construct_UFunction_UCombatantComponent_UngrantAbility, "UngrantAbility" }, // 3541228730
		{ &Z_Construct_UFunction_UCombatantComponent_Update, "Update" }, // 641574720
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Gameplay/CombatantComponent.h" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "////////////////////////////////////\n////////// -- General -- //////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- General -- /" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset = { "CombatantDataAsset", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, CombatantDataAsset), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_DisplayName_MetaData[] = {
		{ "Category", "General" },
		{ "DisplayName", "Name" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, DisplayName), METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_DisplayName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_DisplayName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerInputComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerInputComp = { "OwnerInputComp", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OwnerInputComp), Z_Construct_UClass_UEnhancedInputComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerInputComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerInputComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerPawn_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerPawn = { "OwnerPawn", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OwnerPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerPawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerPawn_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveAbilities_Inner = { "ActiveAbilities", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveAbilities_MetaData[] = {
		{ "Comment", "////////////////////////////////////\n////////// -- Abilities -- //////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Abilities -- /" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveAbilities = { "ActiveAbilities", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, ActiveAbilities), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveAbilities_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveAbilities_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeSet_MetaData[] = {
		{ "Category", "Attributes" },
		{ "Comment", "////////////////////////////////////\n////////// -- Attributes -- //////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Attributes -- /" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, AttributeSet), Z_Construct_UClass_UOmegaAttributeSet_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeSet_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Level_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, Level), METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Level_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Level_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels_ValueProp = { "AttributeLevels", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels_Key_KeyProp = { "AttributeLevels_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels = { "AttributeLevels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, AttributeLevels), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeValueCategory_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeValueCategory = { "AttributeValueCategory", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, AttributeValueCategory), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeValueCategory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeValueCategory_MetaData)) }; // 802167388
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_ValueProp = { "CurrentAttributeValues", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_Key_KeyProp = { "CurrentAttributeValues_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues = { "CurrentAttributeValues", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, CurrentAttributeValues), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset_MetaData[] = {
		{ "Category", "Faction" },
		{ "Comment", "////////////////////////////////////\n////////// -- Faction -- //////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Faction -- /" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset = { "FactionDataAsset", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, FactionDataAsset), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag_MetaData[] = {
		{ "Category", "Faction" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag = { "FactionTag", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, FactionTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag_MetaData)) }; // 802167388
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities_ValueProp = { "FactionAffinities", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UEnum_OmegaGameFramework_EFactionAffinity, METADATA_PARAMS(nullptr, 0) }; // 2251981861
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities_Key_KeyProp = { "FactionAffinities_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities_MetaData[] = {
		{ "Category", "Faction" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities = { "FactionAffinities", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, FactionAffinities), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities_MetaData)) }; // 802167388 2251981861
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Skills_Inner = { "Skills", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Skills_MetaData[] = {
		{ "Category", "Abilities" },
		{ "Comment", "////////////////////////////////////\n////////// -- Skills -- //////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Skills -- /" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Skills = { "Skills", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, Skills), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Skills_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Skills_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CategoryTags_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "Comment", "////////////////////////////////////\n////////// -- Tags -- //////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Tags -- /" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CategoryTags = { "CategoryTags", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, CategoryTags), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CategoryTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CategoryTags_MetaData)) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantTags_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantTags = { "CombatantTags", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, CombatantTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_GrantedAbilities_Inner = { "GrantedAbilities", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_GrantedAbilities_MetaData[] = {
		{ "Category", "Abilities" },
		{ "Comment", "////////////////////////////////////\n////////// -- Ability -- ////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Ability --" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_GrantedAbilities = { "GrantedAbilities", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, GrantedAbilities), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_GrantedAbilities_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_GrantedAbilities_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AbilityList_Inner = { "AbilityList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaAbility_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AbilityList_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AbilityList = { "AbilityList", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, AbilityList), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AbilityList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AbilityList_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeModifiers_Inner = { "AttributeModifiers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeModifiers_MetaData[] = {
		{ "Comment", "///Attribute Modifiers\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "Attribute Modifiers" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeModifiers = { "AttributeModifiers", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, AttributeModifiers), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeModifiers_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeModifiers_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveEffects_Inner = { "ActiveEffects", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveEffects_MetaData[] = {
		{ "Comment", "////////////////////////////////////\n////////// -- Effects -- ////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Effects --" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveEffects = { "ActiveEffects", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, ActiveEffects), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveEffects_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveEffects_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_TargetList_Inner = { "TargetList", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_TargetList_MetaData[] = {
		{ "Category", "Target" },
		{ "Comment", "////////////////////////////////////\n////////// -- Targeting -- //////////\n///////////////////////////////////\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Targeting -- /" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_TargetList = { "TargetList", nullptr, (EPropertyFlags)0x001000800000001c, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, TargetList), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_TargetList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_TargetList_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTarget_MetaData[] = {
		{ "Category", "Target" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTarget = { "ActiveTarget", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, ActiveTarget), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTargetIndex_MetaData[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTargetIndex = { "ActiveTargetIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, ActiveTargetIndex), METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTargetIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTargetIndex_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetAdded_MetaData[] = {
		{ "Comment", "//Delegates\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "Delegates" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetAdded = { "OnTargetAdded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OnTargetAdded), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetAdded_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetAdded_MetaData)) }; // 3325339188
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetRemoved_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetRemoved = { "OnTargetRemoved", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OnTargetRemoved), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetRemoved_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetRemoved_MetaData)) }; // 3325339188
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnAddedAsTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnAddedAsTarget = { "OnAddedAsTarget", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OnAddedAsTarget), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedAsTarget__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnAddedAsTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnAddedAsTarget_MetaData)) }; // 172396703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnRemovedAsTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnRemovedAsTarget = { "OnRemovedAsTarget", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OnRemovedAsTarget), Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedAsTarget__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnRemovedAsTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnRemovedAsTarget_MetaData)) }; // 53802805
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnActiveTargetChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnActiveTargetChanged = { "OnActiveTargetChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OnActiveTargetChanged), Z_Construct_UDelegateFunction_OmegaGameFramework_OnActiveTargetChanged__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnActiveTargetChanged_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnActiveTargetChanged_MetaData)) }; // 3674517879
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnDamaged_MetaData[] = {
		{ "Comment", "//////////////////////////////////////////////////////////////////////////////////////////\n//////////______________________________DELEGATES______________________________//////////\n////////////////////////////////////////////////////////////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/______________________________DELEGATES______________________________/\n/" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnDamaged = { "OnDamaged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OnDamaged), Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnDamaged_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnDamaged_MetaData)) }; // 3739865370
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnLevelChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnLevelChanged = { "OnLevelChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, OnLevelChanged), Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnLevelChanged_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnLevelChanged_MetaData)) }; // 3404509735
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCombatantComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_DisplayName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerInputComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OwnerPawn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveAbilities_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveAbilities,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeSet,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeLevels,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeValueCategory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionAffinities,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Skills_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_Skills,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CategoryTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_GrantedAbilities_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_GrantedAbilities,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AbilityList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AbilityList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeModifiers_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_AttributeModifiers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveEffects_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveEffects,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_TargetList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_TargetList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_ActiveTargetIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetAdded,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnTargetRemoved,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnAddedAsTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnRemovedAsTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnActiveTargetChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnDamaged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_OnLevelChanged,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCombatantComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCombatantComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombatantComponent_Statics::ClassParams = {
		&UCombatantComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCombatantComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCombatantComponent()
	{
		if (!Z_Registration_Info_UClass_UCombatantComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombatantComponent.OuterSingleton, Z_Construct_UClass_UCombatantComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCombatantComponent.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UCombatantComponent>()
	{
		return UCombatantComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCombatantComponent);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::EnumInfo[] = {
		{ EFactionAffinity_StaticEnum, TEXT("EFactionAffinity"), &Z_Registration_Info_UEnum_EFactionAffinity, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2251981861U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCombatantComponent, UCombatantComponent::StaticClass, TEXT("UCombatantComponent"), &Z_Registration_Info_UClass_UCombatantComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatantComponent), 2932650218U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_3686811431(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

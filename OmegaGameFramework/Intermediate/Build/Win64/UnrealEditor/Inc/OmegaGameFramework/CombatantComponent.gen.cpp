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
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDamaged__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnCombatantLevelChange__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetAdded__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTargetRemoved__DelegateSignature();
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
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaAbility_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UEnhancedInputComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttributeSet_NoRegister();
// End Cross Module References
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
	DEFINE_FUNCTION(UCombatantComponent::execAddTargetToList)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTargetToList(Z_Param_Combatant);
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
		P_GET_OBJECT(AActor,Z_Param_Target);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_AddedTags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOmegaGameplayEffect**)Z_Param__Result=P_THIS->CreateEffect(Z_Param_EffectClass,Z_Param_Power,Z_Param_Location,Z_Param_Target,Z_Param_AddedTags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantComponent::execGetAttributeModifiers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UObject*>*)Z_Param__Result=P_THIS->GetAttributeModifiers();
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
	void UCombatantComponent::StaticRegisterNativesUCombatantComponent()
	{
		UClass* Class = UCombatantComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAttrbuteModifier", &UCombatantComponent::execAddAttrbuteModifier },
			{ "AddSkill", &UCombatantComponent::execAddSkill },
			{ "AddTagsToCombatant", &UCombatantComponent::execAddTagsToCombatant },
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
			{ "GetAbility", &UCombatantComponent::execGetAbility },
			{ "GetActiveAbilities", &UCombatantComponent::execGetActiveAbilities },
			{ "GetActiveAbilitiesWithTags", &UCombatantComponent::execGetActiveAbilitiesWithTags },
			{ "GetAttributeModifiers", &UCombatantComponent::execGetAttributeModifiers },
			{ "GetAttributePercentage", &UCombatantComponent::execGetAttributePercentage },
			{ "GetAttributeValue", &UCombatantComponent::execGetAttributeValue },
			{ "GetCombatantTags", &UCombatantComponent::execGetCombatantTags },
			{ "GetCurrentAttributeValues", &UCombatantComponent::execGetCurrentAttributeValues },
			{ "GrantAbility", &UCombatantComponent::execGrantAbility },
			{ "IsAbilityActive", &UCombatantComponent::execIsAbilityActive },
			{ "IsAbilityTagBlocked", &UCombatantComponent::execIsAbilityTagBlocked },
			{ "RemoveAttributeModifersWithTags", &UCombatantComponent::execRemoveAttributeModifersWithTags },
			{ "RemoveAttributeModifier", &UCombatantComponent::execRemoveAttributeModifier },
			{ "RemoveSkill", &UCombatantComponent::execRemoveSkill },
			{ "RemoveTagsFromCombatant", &UCombatantComponent::execRemoveTagsFromCombatant },
			{ "RemoveTargetFromList", &UCombatantComponent::execRemoveTargetFromList },
			{ "SetActiveTarget", &UCombatantComponent::execSetActiveTarget },
			{ "SetCombatantLevel", &UCombatantComponent::execSetCombatantLevel },
			{ "SetCurrentAttributeValues", &UCombatantComponent::execSetCurrentAttributeValues },
			{ "StopAbility", &UCombatantComponent::execStopAbility },
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
		{ "Comment", "////////////////////////////////////\n////////// -- Attributes -- ////////\n///////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
		{ "ToolTip", "/ -- Attributes --" },
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
			AActor* Target;
			FGameplayTagContainer AddedTags;
			AOmegaGameplayEffect* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_EffectClass;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FStructPropertyParams NewProp_AddedTags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_EffectClass = { "EffectClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, EffectClass), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, Power), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, Location), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_AddedTags = { "AddedTags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, AddedTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantComponent_eventCreateEffect_Parms, ReturnValue), Z_Construct_UClass_AOmegaGameplayEffect_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_EffectClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Power,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_AddedTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantComponent_CreateEffect_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "AddedTags, Target" },
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
		{ &Z_Construct_UFunction_UCombatantComponent_AddTargetToList, "AddTargetToList" }, // 374101748
		{ &Z_Construct_UFunction_UCombatantComponent_ApplyAttributeDamage, "ApplyAttributeDamage" }, // 2856595772
		{ &Z_Construct_UFunction_UCombatantComponent_CancelAbilitiesWithTags, "CancelAbilitiesWithTags" }, // 4238267565
		{ &Z_Construct_UFunction_UCombatantComponent_ClearActiveTarget, "ClearActiveTarget" }, // 3084126101
		{ &Z_Construct_UFunction_UCombatantComponent_ClearTargetList, "ClearTargetList" }, // 2442286266
		{ &Z_Construct_UFunction_UCombatantComponent_CombatantHasAllTag, "CombatantHasAllTag" }, // 2657451620
		{ &Z_Construct_UFunction_UCombatantComponent_CombatantHasAnyTag, "CombatantHasAnyTag" }, // 224070953
		{ &Z_Construct_UFunction_UCombatantComponent_CombatantHasTag, "CombatantHasTag" }, // 1833558398
		{ &Z_Construct_UFunction_UCombatantComponent_CreateAttributeModifier, "CreateAttributeModifier" }, // 27755918
		{ &Z_Construct_UFunction_UCombatantComponent_CreateEffect, "CreateEffect" }, // 2431000074
		{ &Z_Construct_UFunction_UCombatantComponent_ExecuteAbility, "ExecuteAbility" }, // 4085829566
		{ &Z_Construct_UFunction_UCombatantComponent_GetAbility, "GetAbility" }, // 131757977
		{ &Z_Construct_UFunction_UCombatantComponent_GetActiveAbilities, "GetActiveAbilities" }, // 2049473885
		{ &Z_Construct_UFunction_UCombatantComponent_GetActiveAbilitiesWithTags, "GetActiveAbilitiesWithTags" }, // 912999139
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributeModifiers, "GetAttributeModifiers" }, // 1716009310
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributePercentage, "GetAttributePercentage" }, // 3666893914
		{ &Z_Construct_UFunction_UCombatantComponent_GetAttributeValue, "GetAttributeValue" }, // 1467730161
		{ &Z_Construct_UFunction_UCombatantComponent_GetCombatantTags, "GetCombatantTags" }, // 3993221455
		{ &Z_Construct_UFunction_UCombatantComponent_GetCurrentAttributeValues, "GetCurrentAttributeValues" }, // 2695110659
		{ &Z_Construct_UFunction_UCombatantComponent_GrantAbility, "GrantAbility" }, // 3186015960
		{ &Z_Construct_UFunction_UCombatantComponent_IsAbilityActive, "IsAbilityActive" }, // 2155676305
		{ &Z_Construct_UFunction_UCombatantComponent_IsAbilityTagBlocked, "IsAbilityTagBlocked" }, // 4107896820
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifersWithTags, "RemoveAttributeModifersWithTags" }, // 664109662
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveAttributeModifier, "RemoveAttributeModifier" }, // 2790237392
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveSkill, "RemoveSkill" }, // 1503474848
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveTagsFromCombatant, "RemoveTagsFromCombatant" }, // 833418412
		{ &Z_Construct_UFunction_UCombatantComponent_RemoveTargetFromList, "RemoveTargetFromList" }, // 1610601646
		{ &Z_Construct_UFunction_UCombatantComponent_SetActiveTarget, "SetActiveTarget" }, // 4143946976
		{ &Z_Construct_UFunction_UCombatantComponent_SetCombatantLevel, "SetCombatantLevel" }, // 3474819152
		{ &Z_Construct_UFunction_UCombatantComponent_SetCurrentAttributeValues, "SetCurrentAttributeValues" }, // 3629896199
		{ &Z_Construct_UFunction_UCombatantComponent_StopAbility, "StopAbility" }, // 2418433152
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset = { "CombatantDataAsset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, CombatantDataAsset), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CombatantDataAsset_MetaData)) };
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset = { "FactionDataAsset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, FactionDataAsset), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag_MetaData[] = {
		{ "Category", "Faction" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag = { "FactionTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatantComponent, FactionTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag_MetaData)) }; // 802167388
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
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_CurrentAttributeValues,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionDataAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatantComponent_Statics::NewProp_FactionTag,
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
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCombatantComponent, UCombatantComponent::StaticClass, TEXT("UCombatantComponent"), &Z_Registration_Info_UClass_UCombatantComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatantComponent), 2919480634U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_2828854803(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/CombatantFunctions.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatantFunctions() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantFunctions_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantFunctions();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FOmegaEffectContainer();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCombatantFunctions::execApplyEffectFromAsset)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_GET_OBJECT(UCombatantComponent,Z_Param_Instigator);
		P_GET_OBJECT(UObject,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCombatantFunctions::ApplyEffectFromAsset(Z_Param_Combatant,Z_Param_Instigator,Z_Param_Asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantFunctions::execApplyEffectFromContainer)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_GET_OBJECT(UCombatantComponent,Z_Param_Instigator);
		P_GET_STRUCT(FOmegaEffectContainer,Z_Param_Effect);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCombatantFunctions::ApplyEffectFromContainer(Z_Param_Combatant,Z_Param_Instigator,Z_Param_Effect,Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantFunctions::execGetCombatantWithHighestAttributeValue)
	{
		P_GET_TARRAY(UCombatantComponent*,Z_Param_Combatants);
		P_GET_OBJECT(UOmegaAttribute,Z_Param_Attribute);
		P_GET_UBOOL(Z_Param_bUseCurrentValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCombatantComponent**)Z_Param__Result=UCombatantFunctions::GetCombatantWithHighestAttributeValue(Z_Param_Combatants,Z_Param_Attribute,Z_Param_bUseCurrentValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantFunctions::execFilterCombatantsByFaction)
	{
		P_GET_TARRAY(UCombatantComponent*,Z_Param_Combatants);
		P_GET_STRUCT(FGameplayTag,Z_Param_Faction);
		P_GET_UBOOL(Z_Param_bExclude);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UCombatantComponent*>*)Z_Param__Result=UCombatantFunctions::FilterCombatantsByFaction(Z_Param_Combatants,Z_Param_Faction,Z_Param_bExclude);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCombatantFunctions::execFilterCombatantsByTags)
	{
		P_GET_TARRAY(UCombatantComponent*,Z_Param_Combatants);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_UBOOL(Z_Param_bExact);
		P_GET_UBOOL(Z_Param_bExclude);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UCombatantComponent*>*)Z_Param__Result=UCombatantFunctions::FilterCombatantsByTags(Z_Param_Combatants,Z_Param_Tags,Z_Param_bExact,Z_Param_bExclude);
		P_NATIVE_END;
	}
	void UCombatantFunctions::StaticRegisterNativesUCombatantFunctions()
	{
		UClass* Class = UCombatantFunctions::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyEffectFromAsset", &UCombatantFunctions::execApplyEffectFromAsset },
			{ "ApplyEffectFromContainer", &UCombatantFunctions::execApplyEffectFromContainer },
			{ "FilterCombatantsByFaction", &UCombatantFunctions::execFilterCombatantsByFaction },
			{ "FilterCombatantsByTags", &UCombatantFunctions::execFilterCombatantsByTags },
			{ "GetCombatantWithHighestAttributeValue", &UCombatantFunctions::execGetCombatantWithHighestAttributeValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics
	{
		struct CombatantFunctions_eventApplyEffectFromAsset_Parms
		{
			UCombatantComponent* Combatant;
			UCombatantComponent* Instigator;
			UObject* Asset;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventApplyEffectFromAsset_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Combatant_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Instigator_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventApplyEffectFromAsset_Parms, Instigator), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Instigator_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Instigator_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventApplyEffectFromAsset_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::NewProp_Asset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "Comment", "//NOTE: Asset must implement \"DataInterface_OmegaEffect\".\n" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantFunctions.h" },
		{ "ToolTip", "NOTE: Asset must implement \"DataInterface_OmegaEffect\"." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantFunctions, nullptr, "ApplyEffectFromAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::CombatantFunctions_eventApplyEffectFromAsset_Parms), Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics
	{
		struct CombatantFunctions_eventApplyEffectFromContainer_Parms
		{
			UCombatantComponent* Combatant;
			UCombatantComponent* Instigator;
			FOmegaEffectContainer Effect;
			UObject* Context;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Effect;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventApplyEffectFromContainer_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Combatant_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Instigator_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventApplyEffectFromContainer_Parms, Instigator), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Instigator_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Instigator_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Effect = { "Effect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventApplyEffectFromContainer_Parms, Effect), Z_Construct_UScriptStruct_FOmegaEffectContainer, METADATA_PARAMS(nullptr, 0) }; // 158265011
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventApplyEffectFromContainer_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Effect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Context" },
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantFunctions.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantFunctions, nullptr, "ApplyEffectFromContainer", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::CombatantFunctions_eventApplyEffectFromContainer_Parms), Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics
	{
		struct CombatantFunctions_eventFilterCombatantsByFaction_Parms
		{
			TArray<UCombatantComponent*> Combatants;
			FGameplayTag Faction;
			bool bExclude;
			TArray<UCombatantComponent*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatants_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatants_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Combatants;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Faction;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Combatants_Inner = { "Combatants", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Combatants_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Combatants = { "Combatants", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventFilterCombatantsByFaction_Parms, Combatants), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Combatants_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Combatants_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Faction = { "Faction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventFilterCombatantsByFaction_Parms, Faction), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	void Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_bExclude_SetBit(void* Obj)
	{
		((CombatantFunctions_eventFilterCombatantsByFaction_Parms*)Obj)->bExclude = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_bExclude = { "bExclude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantFunctions_eventFilterCombatantsByFaction_Parms), &Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_bExclude_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventFilterCombatantsByFaction_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Combatants_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Combatants,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_Faction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_bExclude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantFunctions.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantFunctions, nullptr, "FilterCombatantsByFaction", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::CombatantFunctions_eventFilterCombatantsByFaction_Parms), Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics
	{
		struct CombatantFunctions_eventFilterCombatantsByTags_Parms
		{
			TArray<UCombatantComponent*> Combatants;
			FGameplayTagContainer Tags;
			bool bExact;
			bool bExclude;
			TArray<UCombatantComponent*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatants_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatants_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Combatants;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_bExact_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bExact;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Combatants_Inner = { "Combatants", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Combatants_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Combatants = { "Combatants", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventFilterCombatantsByTags_Parms, Combatants), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Combatants_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Combatants_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventFilterCombatantsByTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExact_SetBit(void* Obj)
	{
		((CombatantFunctions_eventFilterCombatantsByTags_Parms*)Obj)->bExact = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExact = { "bExact", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantFunctions_eventFilterCombatantsByTags_Parms), &Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExact_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExclude_SetBit(void* Obj)
	{
		((CombatantFunctions_eventFilterCombatantsByTags_Parms*)Obj)->bExclude = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExclude = { "bExclude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantFunctions_eventFilterCombatantsByTags_Parms), &Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExclude_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventFilterCombatantsByTags_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Combatants_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Combatants,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExact,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_bExclude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantFunctions.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantFunctions, nullptr, "FilterCombatantsByTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::CombatantFunctions_eventFilterCombatantsByTags_Parms), Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics
	{
		struct CombatantFunctions_eventGetCombatantWithHighestAttributeValue_Parms
		{
			TArray<UCombatantComponent*> Combatants;
			UOmegaAttribute* Attribute;
			bool bUseCurrentValue;
			UCombatantComponent* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatants_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatants_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Combatants;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Attribute;
		static void NewProp_bUseCurrentValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCurrentValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Combatants_Inner = { "Combatants", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Combatants_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Combatants = { "Combatants", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventGetCombatantWithHighestAttributeValue_Parms, Combatants), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Combatants_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Combatants_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Attribute = { "Attribute", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventGetCombatantWithHighestAttributeValue_Parms, Attribute), Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_bUseCurrentValue_SetBit(void* Obj)
	{
		((CombatantFunctions_eventGetCombatantWithHighestAttributeValue_Parms*)Obj)->bUseCurrentValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_bUseCurrentValue = { "bUseCurrentValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CombatantFunctions_eventGetCombatantWithHighestAttributeValue_Parms), &Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_bUseCurrentValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CombatantFunctions_eventGetCombatantWithHighestAttributeValue_Parms, ReturnValue), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Combatants_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Combatants,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_Attribute,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_bUseCurrentValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantFunctions.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatantFunctions, nullptr, "GetCombatantWithHighestAttributeValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::CombatantFunctions_eventGetCombatantWithHighestAttributeValue_Parms), Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCombatantFunctions);
	UClass* Z_Construct_UClass_UCombatantFunctions_NoRegister()
	{
		return UCombatantFunctions::StaticClass();
	}
	struct Z_Construct_UClass_UCombatantFunctions_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCombatantFunctions_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCombatantFunctions_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromAsset, "ApplyEffectFromAsset" }, // 842161369
		{ &Z_Construct_UFunction_UCombatantFunctions_ApplyEffectFromContainer, "ApplyEffectFromContainer" }, // 1812370466
		{ &Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByFaction, "FilterCombatantsByFaction" }, // 2915552871
		{ &Z_Construct_UFunction_UCombatantFunctions_FilterCombatantsByTags, "FilterCombatantsByTags" }, // 1554305917
		{ &Z_Construct_UFunction_UCombatantFunctions_GetCombatantWithHighestAttributeValue, "GetCombatantWithHighestAttributeValue" }, // 3875602986
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatantFunctions_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Gameplay/CombatantFunctions.h" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatantFunctions.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCombatantFunctions_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCombatantFunctions>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombatantFunctions_Statics::ClassParams = {
		&UCombatantFunctions::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCombatantFunctions_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatantFunctions_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCombatantFunctions()
	{
		if (!Z_Registration_Info_UClass_UCombatantFunctions.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombatantFunctions.OuterSingleton, Z_Construct_UClass_UCombatantFunctions_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCombatantFunctions.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UCombatantFunctions>()
	{
		return UCombatantFunctions::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCombatantFunctions);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCombatantFunctions, UCombatantFunctions::StaticClass, TEXT("UCombatantFunctions"), &Z_Registration_Info_UClass_UCombatantFunctions, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatantFunctions), 3772269915U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_3881398484(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

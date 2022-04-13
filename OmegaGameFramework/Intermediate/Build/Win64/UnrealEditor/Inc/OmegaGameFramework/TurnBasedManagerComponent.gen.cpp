// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/TurnBased/TurnBasedManagerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTurnBasedManagerComponent() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UTurnBasedManagerComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UTurnBasedManagerComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UTurnManagerBase_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnTurnStart_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTurnStart_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTurnStart_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTurnStart_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnTurnStart__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnTurnStart_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnTurnEnd_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTurnEnd_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTurnEnd_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnTurnEnd_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnTurnEnd__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnTurnEnd_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms
		{
			UCombatantComponent* Combatant;
			int32 Index;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnAddedToTurnOrder__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnRemovedFromTurnOrder_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnRemovedFromTurnOrder_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnRemovedFromTurnOrder_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnRemovedFromTurnOrder_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnRemovedFromTurnOrder__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnRemovedFromTurnOrder_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execClearRegisteredCombatants)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearRegisteredCombatants(Z_Param_Combatant,Z_Param_Flag,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execUnregisterCombatant)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnregisterCombatant(Z_Param_Combatant,Z_Param_Flag,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execRegisterCombatant)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RegisterCombatant(Z_Param_Combatant,Z_Param_Flag,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execClearTurnOrder)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearTurnOrder(Z_Param_Flag,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execNextTurn)
	{
		P_GET_UBOOL(Z_Param_bGenerateIfEmpty);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->NextTurn(Z_Param_bGenerateIfEmpty,Z_Param_Flag,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execGenerateTurnOrder)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UCombatantComponent*>*)Z_Param__Result=P_THIS->GenerateTurnOrder();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execRemoveFromTurnOrder)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveFromTurnOrder(Z_Param_Combatant,Z_Param_Flag,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execAddToTurnOrder)
	{
		P_GET_OBJECT(UCombatantComponent,Z_Param_Combatant);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddToTurnOrder(Z_Param_Combatant,Z_Param_Flag,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UTurnBasedManagerComponent::execGetActiveTurnMember)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCombatantComponent**)Z_Param__Result=P_THIS->GetActiveTurnMember();
		P_NATIVE_END;
	}
	void UTurnBasedManagerComponent::StaticRegisterNativesUTurnBasedManagerComponent()
	{
		UClass* Class = UTurnBasedManagerComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddToTurnOrder", &UTurnBasedManagerComponent::execAddToTurnOrder },
			{ "ClearRegisteredCombatants", &UTurnBasedManagerComponent::execClearRegisteredCombatants },
			{ "ClearTurnOrder", &UTurnBasedManagerComponent::execClearTurnOrder },
			{ "GenerateTurnOrder", &UTurnBasedManagerComponent::execGenerateTurnOrder },
			{ "GetActiveTurnMember", &UTurnBasedManagerComponent::execGetActiveTurnMember },
			{ "NextTurn", &UTurnBasedManagerComponent::execNextTurn },
			{ "RegisterCombatant", &UTurnBasedManagerComponent::execRegisterCombatant },
			{ "RemoveFromTurnOrder", &UTurnBasedManagerComponent::execRemoveFromTurnOrder },
			{ "UnregisterCombatant", &UTurnBasedManagerComponent::execUnregisterCombatant },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics
	{
		struct TurnBasedManagerComponent_eventAddToTurnOrder_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventAddToTurnOrder_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventAddToTurnOrder_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventAddToTurnOrder_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "AddToTurnOrder", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::TurnBasedManagerComponent_eventAddToTurnOrder_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics
	{
		struct TurnBasedManagerComponent_eventClearRegisteredCombatants_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventClearRegisteredCombatants_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventClearRegisteredCombatants_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventClearRegisteredCombatants_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "Comment", "//Empties all registered combatants from the list\n" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
		{ "ToolTip", "Empties all registered combatants from the list" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "ClearRegisteredCombatants", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::TurnBasedManagerComponent_eventClearRegisteredCombatants_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics
	{
		struct TurnBasedManagerComponent_eventClearTurnOrder_Parms
		{
			FString Flag;
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventClearTurnOrder_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventClearTurnOrder_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "ClearTurnOrder", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::TurnBasedManagerComponent_eventClearTurnOrder_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics
	{
		struct TurnBasedManagerComponent_eventGenerateTurnOrder_Parms
		{
			TArray<UCombatantComponent*> ReturnValue;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventGenerateTurnOrder_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::Function_MetaDataParams[] = {
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "GenerateTurnOrder", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::TurnBasedManagerComponent_eventGenerateTurnOrder_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics
	{
		struct TurnBasedManagerComponent_eventGetActiveTurnMember_Parms
		{
			UCombatantComponent* ReturnValue;
		};
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventGetActiveTurnMember_Parms, ReturnValue), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::Function_MetaDataParams[] = {
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "GetActiveTurnMember", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::TurnBasedManagerComponent_eventGetActiveTurnMember_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics
	{
		struct TurnBasedManagerComponent_eventNextTurn_Parms
		{
			bool bGenerateIfEmpty;
			FString Flag;
			FGameplayTagContainer Tags;
			bool ReturnValue;
		};
		static void NewProp_bGenerateIfEmpty_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenerateIfEmpty;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_bGenerateIfEmpty_SetBit(void* Obj)
	{
		((TurnBasedManagerComponent_eventNextTurn_Parms*)Obj)->bGenerateIfEmpty = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_bGenerateIfEmpty = { "bGenerateIfEmpty", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(TurnBasedManagerComponent_eventNextTurn_Parms), &Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_bGenerateIfEmpty_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventNextTurn_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventNextTurn_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TurnBasedManagerComponent_eventNextTurn_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(TurnBasedManagerComponent_eventNextTurn_Parms), &Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_bGenerateIfEmpty,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "NextTurn", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::TurnBasedManagerComponent_eventNextTurn_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics
	{
		struct TurnBasedManagerComponent_eventRegisterCombatant_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventRegisterCombatant_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventRegisterCombatant_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventRegisterCombatant_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "RegisterCombatant", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::TurnBasedManagerComponent_eventRegisterCombatant_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics
	{
		struct TurnBasedManagerComponent_eventRemoveFromTurnOrder_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventRemoveFromTurnOrder_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventRemoveFromTurnOrder_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventRemoveFromTurnOrder_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "RemoveFromTurnOrder", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::TurnBasedManagerComponent_eventRemoveFromTurnOrder_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics
	{
		struct TurnBasedManagerComponent_eventUnregisterCombatant_Parms
		{
			UCombatantComponent* Combatant;
			FString Flag;
			FGameplayTagContainer Tags;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventUnregisterCombatant_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Combatant_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventUnregisterCombatant_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TurnBasedManagerComponent_eventUnregisterCombatant_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "Comment", "//Removes from list of combatants. Also remove form turn order if in.\n" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
		{ "ToolTip", "Removes from list of combatants. Also remove form turn order if in." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTurnBasedManagerComponent, nullptr, "UnregisterCombatant", nullptr, nullptr, sizeof(Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::TurnBasedManagerComponent_eventUnregisterCombatant_Parms), Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTurnBasedManagerComponent);
	UClass* Z_Construct_UClass_UTurnBasedManagerComponent_NoRegister()
	{
		return UTurnBasedManagerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UTurnBasedManagerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnManagerClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_TurnManagerClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnManager;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnOrder_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnOrder_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TurnOrder;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RegisteredCombatants_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RegisteredCombatants_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RegisteredCombatants;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTurnStart_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTurnStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTurnEnd_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTurnEnd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAddedToTurnOrder_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAddedToTurnOrder;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnRemovedFromTurnOrder_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRemovedFromTurnOrder;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTurnBasedManagerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UTurnBasedManagerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_AddToTurnOrder, "AddToTurnOrder" }, // 4165365971
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_ClearRegisteredCombatants, "ClearRegisteredCombatants" }, // 3107392568
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_ClearTurnOrder, "ClearTurnOrder" }, // 4292612505
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_GenerateTurnOrder, "GenerateTurnOrder" }, // 1521449818
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_GetActiveTurnMember, "GetActiveTurnMember" }, // 3644922752
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_NextTurn, "NextTurn" }, // 1664437268
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_RegisterCombatant, "RegisterCombatant" }, // 2145311683
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_RemoveFromTurnOrder, "RemoveFromTurnOrder" }, // 3830502173
		{ &Z_Construct_UFunction_UTurnBasedManagerComponent_UnregisterCombatant, "UnregisterCombatant" }, // 4053203675
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Gameplay/TurnBased/TurnBasedManagerComponent.h" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManagerClass_MetaData[] = {
		{ "Category", "Turn" },
		{ "Comment", "///////////////\n///// Turn ////\n//////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
		{ "ToolTip", "Turn /" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManagerClass = { "TurnManagerClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, TurnManagerClass), Z_Construct_UClass_UTurnManagerBase_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManagerClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManagerClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManager = { "TurnManager", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, TurnManager), Z_Construct_UClass_UTurnManagerBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManager_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnOrder_Inner = { "TurnOrder", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnOrder_MetaData[] = {
		{ "Category", "TurnBased" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnOrder = { "TurnOrder", nullptr, (EPropertyFlags)0x001000800000001c, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, TurnOrder), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnOrder_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnOrder_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_RegisteredCombatants_Inner = { "RegisteredCombatants", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_RegisteredCombatants_MetaData[] = {
		{ "Category", "TurnBased" },
		{ "Comment", "///////////////\n///// Combatants ////\n//////////////\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
		{ "ToolTip", "Combatants /" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_RegisteredCombatants = { "RegisteredCombatants", nullptr, (EPropertyFlags)0x001000800000001c, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, RegisteredCombatants), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_RegisteredCombatants_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_RegisteredCombatants_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnStart_MetaData[] = {
		{ "Comment", "///////////////\n///// Delegates ////\n//////////////\n" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
		{ "ToolTip", "Delegates /" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnStart = { "OnTurnStart", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, OnTurnStart), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnStart__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnStart_MetaData)) }; // 3960912703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnEnd_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnEnd = { "OnTurnEnd", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, OnTurnEnd), Z_Construct_UDelegateFunction_OmegaGameFramework_OnTurnEnd__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnEnd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnEnd_MetaData)) }; // 1474866248
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnAddedToTurnOrder_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnAddedToTurnOrder = { "OnAddedToTurnOrder", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, OnAddedToTurnOrder), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAddedToTurnOrder__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnAddedToTurnOrder_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnAddedToTurnOrder_MetaData)) }; // 2007004275
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnRemovedFromTurnOrder_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/TurnBasedManagerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnRemovedFromTurnOrder = { "OnRemovedFromTurnOrder", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTurnBasedManagerComponent, OnRemovedFromTurnOrder), Z_Construct_UDelegateFunction_OmegaGameFramework_OnRemovedFromTurnOrder__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnRemovedFromTurnOrder_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnRemovedFromTurnOrder_MetaData)) }; // 730209577
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTurnBasedManagerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManagerClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnManager,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnOrder_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_TurnOrder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_RegisteredCombatants_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_RegisteredCombatants,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnTurnEnd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnAddedToTurnOrder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTurnBasedManagerComponent_Statics::NewProp_OnRemovedFromTurnOrder,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTurnBasedManagerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTurnBasedManagerComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTurnBasedManagerComponent_Statics::ClassParams = {
		&UTurnBasedManagerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UTurnBasedManagerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTurnBasedManagerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTurnBasedManagerComponent()
	{
		if (!Z_Registration_Info_UClass_UTurnBasedManagerComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTurnBasedManagerComponent.OuterSingleton, Z_Construct_UClass_UTurnBasedManagerComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTurnBasedManagerComponent.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UTurnBasedManagerComponent>()
	{
		return UTurnBasedManagerComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTurnBasedManagerComponent);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTurnBasedManagerComponent, UTurnBasedManagerComponent::StaticClass, TEXT("UTurnBasedManagerComponent"), &Z_Registration_Info_UClass_UTurnBasedManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTurnBasedManagerComponent), 3061022291U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_1997758249(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

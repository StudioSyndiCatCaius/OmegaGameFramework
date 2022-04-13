// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/DataInterface_Combatant.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataInterface_Combatant() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_Combatant_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_Combatant();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
// End Cross Module References
	TMap<UOmegaAttribute*,int32> IDataInterface_Combatant::OverrideAttributeLevels(UCombatantComponent* Combatant, bool& bOverride)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OverrideAttributeLevels instead.");
		DataInterface_Combatant_eventOverrideAttributeLevels_Parms Parms;
		return Parms.ReturnValue;
	}
	FGameplayTag IDataInterface_Combatant::OverrideAttributeValueCategory(UCombatantComponent* Combatant, bool& bOverride)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OverrideAttributeValueCategory instead.");
		DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms Parms;
		return Parms.ReturnValue;
	}
	int32 IDataInterface_Combatant::OverrideCombatantLevel(UCombatantComponent* Combatant, bool& bOverride)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OverrideCombatantLevel instead.");
		DataInterface_Combatant_eventOverrideCombatantLevel_Parms Parms;
		return Parms.ReturnValue;
	}
	TMap<UOmegaAttribute*,float> IDataInterface_Combatant::OverrideCurrentAttributeValues(UCombatantComponent* Combatant, bool& bOverride)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OverrideCurrentAttributeValues instead.");
		DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms Parms;
		return Parms.ReturnValue;
	}
	void UDataInterface_Combatant::StaticRegisterNativesUDataInterface_Combatant()
	{
	}
	struct Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static void NewProp_bOverride_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideAttributeLevels_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_Combatant_MetaData)) };
	void Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_bOverride_SetBit(void* Obj)
	{
		((DataInterface_Combatant_eventOverrideAttributeLevels_Parms*)Obj)->bOverride = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_bOverride = { "bOverride", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataInterface_Combatant_eventOverrideAttributeLevels_Parms), &Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_bOverride_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideAttributeLevels_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_bOverride,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_Combatant, nullptr, "OverrideAttributeLevels", nullptr, nullptr, sizeof(DataInterface_Combatant_eventOverrideAttributeLevels_Parms), Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static void NewProp_bOverride_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_Combatant_MetaData)) };
	void Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_bOverride_SetBit(void* Obj)
	{
		((DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms*)Obj)->bOverride = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_bOverride = { "bOverride", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms), &Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_bOverride_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_bOverride,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_Combatant, nullptr, "OverrideAttributeValueCategory", nullptr, nullptr, sizeof(DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms), Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static void NewProp_bOverride_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideCombatantLevel_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_Combatant_MetaData)) };
	void Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_bOverride_SetBit(void* Obj)
	{
		((DataInterface_Combatant_eventOverrideCombatantLevel_Parms*)Obj)->bOverride = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_bOverride = { "bOverride", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataInterface_Combatant_eventOverrideCombatantLevel_Parms), &Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_bOverride_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideCombatantLevel_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_bOverride,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_Combatant, nullptr, "OverrideCombatantLevel", nullptr, nullptr, sizeof(DataInterface_Combatant_eventOverrideCombatantLevel_Parms), Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Combatant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Combatant;
		static void NewProp_bOverride_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_Combatant_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_Combatant = { "Combatant", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms, Combatant), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_Combatant_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_Combatant_MetaData)) };
	void Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_bOverride_SetBit(void* Obj)
	{
		((DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms*)Obj)->bOverride = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_bOverride = { "bOverride", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms), &Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_bOverride_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaAttribute_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_Combatant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_bOverride,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combatant" },
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_Combatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_Combatant, nullptr, "OverrideCurrentAttributeValues", nullptr, nullptr, sizeof(DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms), Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataInterface_Combatant);
	UClass* Z_Construct_UClass_UDataInterface_Combatant_NoRegister()
	{
		return UDataInterface_Combatant::StaticClass();
	}
	struct Z_Construct_UClass_UDataInterface_Combatant_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataInterface_Combatant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataInterface_Combatant_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeLevels, "OverrideAttributeLevels" }, // 1358573369
		{ &Z_Construct_UFunction_UDataInterface_Combatant_OverrideAttributeValueCategory, "OverrideAttributeValueCategory" }, // 3711546089
		{ &Z_Construct_UFunction_UDataInterface_Combatant_OverrideCombatantLevel, "OverrideCombatantLevel" }, // 3291825491
		{ &Z_Construct_UFunction_UDataInterface_Combatant_OverrideCurrentAttributeValues, "OverrideCurrentAttributeValues" }, // 823806789
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataInterface_Combatant_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/DataInterface_Combatant.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataInterface_Combatant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDataInterface_Combatant>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataInterface_Combatant_Statics::ClassParams = {
		&UDataInterface_Combatant::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UDataInterface_Combatant_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataInterface_Combatant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataInterface_Combatant()
	{
		if (!Z_Registration_Info_UClass_UDataInterface_Combatant.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataInterface_Combatant.OuterSingleton, Z_Construct_UClass_UDataInterface_Combatant_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataInterface_Combatant.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataInterface_Combatant>()
	{
		return UDataInterface_Combatant::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataInterface_Combatant);
	static FName NAME_UDataInterface_Combatant_OverrideAttributeLevels = FName(TEXT("OverrideAttributeLevels"));
	TMap<UOmegaAttribute*,int32> IDataInterface_Combatant::Execute_OverrideAttributeLevels(UObject* O, UCombatantComponent* Combatant, bool& bOverride)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()));
		DataInterface_Combatant_eventOverrideAttributeLevels_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_Combatant_OverrideAttributeLevels);
		if (Func)
		{
			Parms.Combatant=Combatant;
			Parms.bOverride=bOverride;
			O->ProcessEvent(Func, &Parms);
			bOverride=Parms.bOverride;
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UDataInterface_Combatant_OverrideAttributeValueCategory = FName(TEXT("OverrideAttributeValueCategory"));
	FGameplayTag IDataInterface_Combatant::Execute_OverrideAttributeValueCategory(UObject* O, UCombatantComponent* Combatant, bool& bOverride)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()));
		DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_Combatant_OverrideAttributeValueCategory);
		if (Func)
		{
			Parms.Combatant=Combatant;
			Parms.bOverride=bOverride;
			O->ProcessEvent(Func, &Parms);
			bOverride=Parms.bOverride;
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UDataInterface_Combatant_OverrideCombatantLevel = FName(TEXT("OverrideCombatantLevel"));
	int32 IDataInterface_Combatant::Execute_OverrideCombatantLevel(UObject* O, UCombatantComponent* Combatant, bool& bOverride)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()));
		DataInterface_Combatant_eventOverrideCombatantLevel_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_Combatant_OverrideCombatantLevel);
		if (Func)
		{
			Parms.Combatant=Combatant;
			Parms.bOverride=bOverride;
			O->ProcessEvent(Func, &Parms);
			bOverride=Parms.bOverride;
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UDataInterface_Combatant_OverrideCurrentAttributeValues = FName(TEXT("OverrideCurrentAttributeValues"));
	TMap<UOmegaAttribute*,float> IDataInterface_Combatant::Execute_OverrideCurrentAttributeValues(UObject* O, UCombatantComponent* Combatant, bool& bOverride)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_Combatant::StaticClass()));
		DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_Combatant_OverrideCurrentAttributeValues);
		if (Func)
		{
			Parms.Combatant=Combatant;
			Parms.bOverride=bOverride;
			O->ProcessEvent(Func, &Parms);
			bOverride=Parms.bOverride;
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataInterface_Combatant, UDataInterface_Combatant::StaticClass, TEXT("UDataInterface_Combatant"), &Z_Registration_Info_UClass_UDataInterface_Combatant, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataInterface_Combatant), 4016302655U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_2225357784(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

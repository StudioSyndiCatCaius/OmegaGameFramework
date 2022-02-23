// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Preferences/GamePreferenceSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamePreferenceSubsystem() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceBool_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceFloat_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceString_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceTag_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceSubsystem_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveSubsystem_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnPrefernceBoolUpdated_Parms
		{
			UGamePreferenceBool* Preference;
			bool bValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static void NewProp_bValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnPrefernceBoolUpdated_Parms, Preference), Z_Construct_UClass_UGamePreferenceBool_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnPrefernceBoolUpdated_Parms*)Obj)->bValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnPrefernceBoolUpdated_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnPrefernceBoolUpdated__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnPrefernceBoolUpdated_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnPrefernceFloatUpdated_Parms
		{
			UGamePreferenceFloat* Preference;
			float Value;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnPrefernceFloatUpdated_Parms, Preference), Z_Construct_UClass_UGamePreferenceFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnPrefernceFloatUpdated_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnPrefernceFloatUpdated__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnPrefernceFloatUpdated_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnPrefernceStringUpdated_Parms
		{
			UGamePreferenceString* Preference;
			FString bValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FStrPropertyParams NewProp_bValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnPrefernceStringUpdated_Parms, Preference), Z_Construct_UClass_UGamePreferenceString_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnPrefernceStringUpdated_Parms, bValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnPrefernceStringUpdated__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnPrefernceStringUpdated_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnPrefernceTagUpdated_Parms
		{
			UGamePreferenceTag* Preference;
			FGameplayTag Value;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnPrefernceTagUpdated_Parms, Preference), Z_Construct_UClass_UGamePreferenceTag_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnPrefernceTagUpdated_Parms, Value), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnPrefernceTagUpdated__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnPrefernceTagUpdated_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execSetGamePreferenceTag)
	{
		P_GET_OBJECT(UGamePreferenceTag,Z_Param_Preference);
		P_GET_STRUCT(FGameplayTag,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGamePreferenceTag(Z_Param_Preference,Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execGetGamePreferenceTag)
	{
		P_GET_OBJECT(UGamePreferenceTag,Z_Param_Preference);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTag*)Z_Param__Result=P_THIS->GetGamePreferenceTag(Z_Param_Preference);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execSetGamePreferenceString)
	{
		P_GET_OBJECT(UGamePreferenceString,Z_Param_Preference);
		P_GET_PROPERTY(FStrProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGamePreferenceString(Z_Param_Preference,Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execGetGamePreferenceString)
	{
		P_GET_OBJECT(UGamePreferenceString,Z_Param_Preference);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetGamePreferenceString(Z_Param_Preference);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execSetGamePreferenceFloat)
	{
		P_GET_OBJECT(UGamePreferenceFloat,Z_Param_Preference);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGamePreferenceFloat(Z_Param_Preference,Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execGetGamePreferenceFloat)
	{
		P_GET_OBJECT(UGamePreferenceFloat,Z_Param_Preference);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetGamePreferenceFloat(Z_Param_Preference);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execSetGamePreferenceBool)
	{
		P_GET_OBJECT(UGamePreferenceBool,Z_Param_Preference);
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGamePreferenceBool(Z_Param_Preference,Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execGetGamePreferenceBool)
	{
		P_GET_OBJECT(UGamePreferenceBool,Z_Param_Preference);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetGamePreferenceBool(Z_Param_Preference);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreferenceSubsystem::execGetSaveSubsystem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UOmegaSaveSubsystem**)Z_Param__Result=P_THIS->GetSaveSubsystem();
		P_NATIVE_END;
	}
	void UGamePreferenceSubsystem::StaticRegisterNativesUGamePreferenceSubsystem()
	{
		UClass* Class = UGamePreferenceSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetGamePreferenceBool", &UGamePreferenceSubsystem::execGetGamePreferenceBool },
			{ "GetGamePreferenceFloat", &UGamePreferenceSubsystem::execGetGamePreferenceFloat },
			{ "GetGamePreferenceString", &UGamePreferenceSubsystem::execGetGamePreferenceString },
			{ "GetGamePreferenceTag", &UGamePreferenceSubsystem::execGetGamePreferenceTag },
			{ "GetSaveSubsystem", &UGamePreferenceSubsystem::execGetSaveSubsystem },
			{ "SetGamePreferenceBool", &UGamePreferenceSubsystem::execSetGamePreferenceBool },
			{ "SetGamePreferenceFloat", &UGamePreferenceSubsystem::execSetGamePreferenceFloat },
			{ "SetGamePreferenceString", &UGamePreferenceSubsystem::execSetGamePreferenceString },
			{ "SetGamePreferenceTag", &UGamePreferenceSubsystem::execSetGamePreferenceTag },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics
	{
		struct GamePreferenceSubsystem_eventGetGamePreferenceBool_Parms
		{
			UGamePreferenceBool* Preference;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetGamePreferenceBool_Parms, Preference), Z_Construct_UClass_UGamePreferenceBool_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GamePreferenceSubsystem_eventGetGamePreferenceBool_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GamePreferenceSubsystem_eventGetGamePreferenceBool_Parms), &Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "Comment", "//Bool\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
		{ "ToolTip", "Bool" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "GetGamePreferenceBool", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::GamePreferenceSubsystem_eventGetGamePreferenceBool_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics
	{
		struct GamePreferenceSubsystem_eventGetGamePreferenceFloat_Parms
		{
			UGamePreferenceFloat* Preference;
			float ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetGamePreferenceFloat_Parms, Preference), Z_Construct_UClass_UGamePreferenceFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetGamePreferenceFloat_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "Comment", "//Float\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
		{ "ToolTip", "Float" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "GetGamePreferenceFloat", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::GamePreferenceSubsystem_eventGetGamePreferenceFloat_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics
	{
		struct GamePreferenceSubsystem_eventGetGamePreferenceString_Parms
		{
			UGamePreferenceString* Preference;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetGamePreferenceString_Parms, Preference), Z_Construct_UClass_UGamePreferenceString_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetGamePreferenceString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "Comment", "//String\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
		{ "ToolTip", "String" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "GetGamePreferenceString", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::GamePreferenceSubsystem_eventGetGamePreferenceString_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics
	{
		struct GamePreferenceSubsystem_eventGetGamePreferenceTag_Parms
		{
			UGamePreferenceTag* Preference;
			FGameplayTag ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetGamePreferenceTag_Parms, Preference), Z_Construct_UClass_UGamePreferenceTag_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetGamePreferenceTag_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "Comment", "//Tag\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
		{ "ToolTip", "Tag" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "GetGamePreferenceTag", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::GamePreferenceSubsystem_eventGetGamePreferenceTag_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics
	{
		struct GamePreferenceSubsystem_eventGetSaveSubsystem_Parms
		{
			UOmegaSaveSubsystem* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventGetSaveSubsystem_Parms, ReturnValue), Z_Construct_UClass_UOmegaSaveSubsystem_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//UPROPERTY()\n//UOmegaSaveSubsystem* SaveSubsystemRef;\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
		{ "ToolTip", "UPROPERTY()\nUOmegaSaveSubsystem* SaveSubsystemRef;" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "GetSaveSubsystem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::GamePreferenceSubsystem_eventGetSaveSubsystem_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics
	{
		struct GamePreferenceSubsystem_eventSetGamePreferenceBool_Parms
		{
			UGamePreferenceBool* Preference;
			bool bValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static void NewProp_bValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventSetGamePreferenceBool_Parms, Preference), Z_Construct_UClass_UGamePreferenceBool_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((GamePreferenceSubsystem_eventSetGamePreferenceBool_Parms*)Obj)->bValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GamePreferenceSubsystem_eventSetGamePreferenceBool_Parms), &Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "SetGamePreferenceBool", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::GamePreferenceSubsystem_eventSetGamePreferenceBool_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics
	{
		struct GamePreferenceSubsystem_eventSetGamePreferenceFloat_Parms
		{
			UGamePreferenceFloat* Preference;
			float Value;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventSetGamePreferenceFloat_Parms, Preference), Z_Construct_UClass_UGamePreferenceFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventSetGamePreferenceFloat_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "SetGamePreferenceFloat", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::GamePreferenceSubsystem_eventSetGamePreferenceFloat_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics
	{
		struct GamePreferenceSubsystem_eventSetGamePreferenceString_Parms
		{
			UGamePreferenceString* Preference;
			FString Value;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventSetGamePreferenceString_Parms, Preference), Z_Construct_UClass_UGamePreferenceString_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventSetGamePreferenceString_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::NewProp_Value_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "SetGamePreferenceString", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::GamePreferenceSubsystem_eventSetGamePreferenceString_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics
	{
		struct GamePreferenceSubsystem_eventSetGamePreferenceTag_Parms
		{
			UGamePreferenceTag* Preference;
			FGameplayTag Value;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventSetGamePreferenceTag_Parms, Preference), Z_Construct_UClass_UGamePreferenceTag_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreferenceSubsystem_eventSetGamePreferenceTag_Parms, Value), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Omega|GamePreferences" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreferenceSubsystem, nullptr, "SetGamePreferenceTag", nullptr, nullptr, sizeof(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::GamePreferenceSubsystem_eventSetGamePreferenceTag_Parms), Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGamePreferenceSubsystem);
	UClass* Z_Construct_UClass_UGamePreferenceSubsystem_NoRegister()
	{
		return UGamePreferenceSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UGamePreferenceSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBoolPropertyParams NewProp_BoolPrefs_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoolPrefs_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoolPrefs_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_BoolPrefs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnBoolPreferenceUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBoolPreferenceUpdated;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FloatPrefs_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FloatPrefs_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FloatPrefs_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_FloatPrefs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFloatPreferenceUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFloatPreferenceUpdated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnStringPreferenceUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStringPreferenceUpdated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTagPreferenceUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTagPreferenceUpdated;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGamePreferenceSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGamePreferenceSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceBool, "GetGamePreferenceBool" }, // 1077595735
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceFloat, "GetGamePreferenceFloat" }, // 1994674527
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceString, "GetGamePreferenceString" }, // 3162942779
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_GetGamePreferenceTag, "GetGamePreferenceTag" }, // 3187887426
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_GetSaveSubsystem, "GetSaveSubsystem" }, // 841820048
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceBool, "SetGamePreferenceBool" }, // 3980319289
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceFloat, "SetGamePreferenceFloat" }, // 4113281099
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceString, "SetGamePreferenceString" }, // 2868227919
		{ &Z_Construct_UFunction_UGamePreferenceSubsystem_SetGamePreferenceTag, "SetGamePreferenceTag" }, // 3191537372
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Preferences/GamePreferenceSubsystem.h" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs_ValueProp = { "BoolPrefs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs_Key_KeyProp = { "BoolPrefs_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGamePreferenceBool_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs_MetaData[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs = { "BoolPrefs", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceSubsystem, BoolPrefs), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnBoolPreferenceUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnBoolPreferenceUpdated = { "OnBoolPreferenceUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceSubsystem, OnBoolPreferenceUpdated), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceBoolUpdated__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnBoolPreferenceUpdated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnBoolPreferenceUpdated_MetaData)) }; // 274877447
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs_ValueProp = { "FloatPrefs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs_Key_KeyProp = { "FloatPrefs_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGamePreferenceFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs_MetaData[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs = { "FloatPrefs", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceSubsystem, FloatPrefs), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnFloatPreferenceUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnFloatPreferenceUpdated = { "OnFloatPreferenceUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceSubsystem, OnFloatPreferenceUpdated), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceFloatUpdated__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnFloatPreferenceUpdated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnFloatPreferenceUpdated_MetaData)) }; // 509800472
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnStringPreferenceUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnStringPreferenceUpdated = { "OnStringPreferenceUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceSubsystem, OnStringPreferenceUpdated), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceStringUpdated__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnStringPreferenceUpdated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnStringPreferenceUpdated_MetaData)) }; // 3925657727
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnTagPreferenceUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Public/Preferences/GamePreferenceSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnTagPreferenceUpdated = { "OnTagPreferenceUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceSubsystem, OnTagPreferenceUpdated), Z_Construct_UDelegateFunction_OmegaGameFramework_OnPrefernceTagUpdated__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnTagPreferenceUpdated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnTagPreferenceUpdated_MetaData)) }; // 4249874352
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGamePreferenceSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_BoolPrefs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnBoolPreferenceUpdated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_FloatPrefs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnFloatPreferenceUpdated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnStringPreferenceUpdated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceSubsystem_Statics::NewProp_OnTagPreferenceUpdated,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGamePreferenceSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGamePreferenceSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGamePreferenceSubsystem_Statics::ClassParams = {
		&UGamePreferenceSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGamePreferenceSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGamePreferenceSubsystem()
	{
		if (!Z_Registration_Info_UClass_UGamePreferenceSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGamePreferenceSubsystem.OuterSingleton, Z_Construct_UClass_UGamePreferenceSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGamePreferenceSubsystem.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UGamePreferenceSubsystem>()
	{
		return UGamePreferenceSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGamePreferenceSubsystem);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGamePreferenceSubsystem, UGamePreferenceSubsystem::StaticClass, TEXT("UGamePreferenceSubsystem"), &Z_Registration_Info_UClass_UGamePreferenceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGamePreferenceSubsystem), 949429563U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_4133352366(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

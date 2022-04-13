// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaGameplaySystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameplaySystem() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGameplaySystemAbilityRules();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaAbility_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplaySystem_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplaySystem();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceBool_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceFloat_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameplaySubsystem_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UHUDLayer_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveInterface_NoRegister();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules;
class UScriptStruct* FGameplaySystemAbilityRules::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("GameplaySystemAbilityRules"));
	}
	return Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules.OuterSingleton;
}
template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<FGameplaySystemAbilityRules>()
{
	return FGameplaySystemAbilityRules::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GrantedAbilities_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_GrantedAbilities;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AcceptedCategories_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AcceptedCategories;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AcceptedTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AcceptedTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameplaySystemAbilityRules>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_GrantedAbilities_MetaData[] = {
		{ "Category", "GameplaySystemRules" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_GrantedAbilities = { "GrantedAbilities", nullptr, (EPropertyFlags)0x0014000000000004, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameplaySystemAbilityRules, GrantedAbilities), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_GrantedAbilities_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_GrantedAbilities_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedCategories_MetaData[] = {
		{ "Category", "GameplaySystemRules" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedCategories = { "AcceptedCategories", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameplaySystemAbilityRules, AcceptedCategories), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedCategories_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedCategories_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedTags_MetaData[] = {
		{ "Category", "GameplaySystemRules" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedTags = { "AcceptedTags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGameplaySystemAbilityRules, AcceptedTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_GrantedAbilities,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedCategories,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewProp_AcceptedTags,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		&NewStructOps,
		"GameplaySystemAbilityRules",
		sizeof(FGameplaySystemAbilityRules),
		alignof(FGameplaySystemAbilityRules),
		Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGameplaySystemAbilityRules()
	{
		if (!Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules.InnerSingleton, Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnShutdown_Parms
		{
			FString Flag;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnShutdown_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::NewProp_Flag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnShutdown__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnShutdown_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(AOmegaGameplaySystem::execShutdown)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Shutdown(Z_Param_Flag);
		P_NATIVE_END;
	}
	static FName NAME_AOmegaGameplaySystem_GamePreferenceUpdatedBool = FName(TEXT("GamePreferenceUpdatedBool"));
	void AOmegaGameplaySystem::GamePreferenceUpdatedBool(UGamePreferenceBool* Preference, bool Value)
	{
		OmegaGameplaySystem_eventGamePreferenceUpdatedBool_Parms Parms;
		Parms.Preference=Preference;
		Parms.Value=Value ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplaySystem_GamePreferenceUpdatedBool),&Parms);
	}
	static FName NAME_AOmegaGameplaySystem_GamePreferenceUpdatedFloat = FName(TEXT("GamePreferenceUpdatedFloat"));
	void AOmegaGameplaySystem::GamePreferenceUpdatedFloat(UGamePreferenceFloat* Preference, float Value)
	{
		OmegaGameplaySystem_eventGamePreferenceUpdatedFloat_Parms Parms;
		Parms.Preference=Preference;
		Parms.Value=Value;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplaySystem_GamePreferenceUpdatedFloat),&Parms);
	}
	static FName NAME_AOmegaGameplaySystem_OnActiveGameSaved = FName(TEXT("OnActiveGameSaved"));
	bool AOmegaGameplaySystem::OnActiveGameSaved()
	{
		OmegaGameplaySystem_eventOnActiveGameSaved_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplaySystem_OnActiveGameSaved),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_AOmegaGameplaySystem_SystemActivated = FName(TEXT("SystemActivated"));
	void AOmegaGameplaySystem::SystemActivated(UObject* Context, const FString& Flag)
	{
		OmegaGameplaySystem_eventSystemActivated_Parms Parms;
		Parms.Context=Context;
		Parms.Flag=Flag;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplaySystem_SystemActivated),&Parms);
	}
	static FName NAME_AOmegaGameplaySystem_SystemShutdown = FName(TEXT("SystemShutdown"));
	void AOmegaGameplaySystem::SystemShutdown(const FString& Flag)
	{
		OmegaGameplaySystem_eventSystemShutdown_Parms Parms;
		Parms.Flag=Flag;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaGameplaySystem_SystemShutdown),&Parms);
	}
	void AOmegaGameplaySystem::StaticRegisterNativesAOmegaGameplaySystem()
	{
		UClass* Class = AOmegaGameplaySystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Shutdown", &AOmegaGameplaySystem::execShutdown },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySystem_eventGamePreferenceUpdatedBool_Parms, Preference), Z_Construct_UClass_UGamePreferenceBool_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((OmegaGameplaySystem_eventGamePreferenceUpdatedBool_Parms*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaGameplaySystem_eventGamePreferenceUpdatedBool_Parms), &Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|GamePreferences" },
		{ "Comment", "////////////////////////////////////\n////////////--Preferences--/////////////\n////////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ToolTip", "--Preferences--/" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplaySystem, nullptr, "GamePreferenceUpdatedBool", nullptr, nullptr, sizeof(OmegaGameplaySystem_eventGamePreferenceUpdatedBool_Parms), Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preference;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::NewProp_Preference = { "Preference", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySystem_eventGamePreferenceUpdatedFloat_Parms, Preference), Z_Construct_UClass_UGamePreferenceFloat_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySystem_eventGamePreferenceUpdatedFloat_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::NewProp_Preference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|GamePreferences" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplaySystem, nullptr, "GamePreferenceUpdatedFloat", nullptr, nullptr, sizeof(OmegaGameplaySystem_eventGamePreferenceUpdatedFloat_Parms), Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaGameplaySystem_eventOnActiveGameSaved_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaGameplaySystem_eventOnActiveGameSaved_Parms), &Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|GamePreferences" },
		{ "Comment", "////////////////////////////////////\n////////////--Save--/////////////\n////////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ToolTip", "--Save--/" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplaySystem, nullptr, "OnActiveGameSaved", nullptr, nullptr, sizeof(OmegaGameplaySystem_eventOnActiveGameSaved_Parms), Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics
	{
		struct OmegaGameplaySystem_eventShutdown_Parms
		{
			FString Flag;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySystem_eventShutdown_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::NewProp_Flag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay" },
		{ "Comment", "//Will shut down this gameplay system//\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ToolTip", "Will shut down this gameplay system" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplaySystem, nullptr, "Shutdown", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::OmegaGameplaySystem_eventShutdown_Parms), Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Flag_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySystem_eventSystemActivated_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::NewProp_Flag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySystem_eventSystemActivated_Parms, Flag), METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::NewProp_Flag_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::NewProp_Flag_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::NewProp_Flag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//**Start & End***//\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ToolTip", "/Start & End**/" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplaySystem, nullptr, "SystemActivated", nullptr, nullptr, sizeof(OmegaGameplaySystem_eventSystemActivated_Parms), Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Flag_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::NewProp_Flag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySystem_eventSystemShutdown_Parms, Flag), METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::NewProp_Flag_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::NewProp_Flag_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::NewProp_Flag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaGameplaySystem, nullptr, "SystemShutdown", nullptr, nullptr, sizeof(OmegaGameplaySystem_eventSystemShutdown_Parms), Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOmegaGameplaySystem);
	UClass* Z_Construct_UClass_AOmegaGameplaySystem_NoRegister()
	{
		return AOmegaGameplaySystem::StaticClass();
	}
	struct Z_Construct_UClass_AOmegaGameplaySystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubsysRef_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SubsysRef;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContextObject_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TempFlag_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_TempFlag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSystemShutdown_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSystemShutdown;
		static const UECodeGen_Private::FClassPropertyParams NewProp_AddedPlayerWidgets_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AddedPlayerWidgets_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AddedPlayerWidgets;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AddPlayerInputMapping_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AddPlayerInputMapping_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AddPlayerInputMapping;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActivePlayerWidgets_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActivePlayerWidgets_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActivePlayerWidgets;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOmegaGameplaySystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AOmegaGameplaySystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedBool, "GamePreferenceUpdatedBool" }, // 836099030
		{ &Z_Construct_UFunction_AOmegaGameplaySystem_GamePreferenceUpdatedFloat, "GamePreferenceUpdatedFloat" }, // 3852790104
		{ &Z_Construct_UFunction_AOmegaGameplaySystem_OnActiveGameSaved, "OnActiveGameSaved" }, // 3097981989
		{ &Z_Construct_UFunction_AOmegaGameplaySystem_Shutdown, "Shutdown" }, // 3376771317
		{ &Z_Construct_UFunction_AOmegaGameplaySystem_SystemActivated, "SystemActivated" }, // 1152083120
		{ &Z_Construct_UFunction_AOmegaGameplaySystem_SystemShutdown, "SystemShutdown" }, // 3160371238
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Info Rendering MovementReplication Actor Collision" },
		{ "IncludePath", "OmegaGameplaySystem.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ShortTooltip", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_SubsysRef_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_SubsysRef = { "SubsysRef", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplaySystem, SubsysRef), Z_Construct_UClass_UOmegaGameplaySubsystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_SubsysRef_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_SubsysRef_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ContextObject_MetaData[] = {
		{ "Category", "\xce\xa9|Gameplay" },
		{ "Comment", "//Context Object//\n" },
		{ "ExposeOnSpawn", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ToolTip", "Context Object" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ContextObject = { "ContextObject", nullptr, (EPropertyFlags)0x0011000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplaySystem, ContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ContextObject_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_TempFlag_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_TempFlag = { "TempFlag", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplaySystem, TempFlag), METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_TempFlag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_TempFlag_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_OnSystemShutdown_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_OnSystemShutdown = { "OnSystemShutdown", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplaySystem, OnSystemShutdown), Z_Construct_UDelegateFunction_OmegaGameFramework_OnShutdown__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_OnSystemShutdown_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_OnSystemShutdown_MetaData)) }; // 431588392
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddedPlayerWidgets_Inner = { "AddedPlayerWidgets", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UHUDLayer_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddedPlayerWidgets_MetaData[] = {
		{ "Category", "Player" },
		{ "Comment", "////////////////////////////////////\n////////////--PLAYER--/////////////\n////////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ToolTip", "--PLAYER--/" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddedPlayerWidgets = { "AddedPlayerWidgets", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplaySystem, AddedPlayerWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddedPlayerWidgets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddedPlayerWidgets_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddPlayerInputMapping_Inner = { "AddPlayerInputMapping", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddPlayerInputMapping_MetaData[] = {
		{ "Category", "Player" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddPlayerInputMapping = { "AddPlayerInputMapping", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplaySystem, AddPlayerInputMapping), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddPlayerInputMapping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddPlayerInputMapping_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ActivePlayerWidgets_Inner = { "ActivePlayerWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UHUDLayer_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ActivePlayerWidgets_MetaData[] = {
		{ "Comment", "//UPROPERTY(EditDefaultsOnly, Category = \"Gameplay\")\n//TArray<FGameplaySystemAbilityRules> GrantedAbilties;\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySystem.h" },
		{ "ToolTip", "UPROPERTY(EditDefaultsOnly, Category = \"Gameplay\")\nTArray<FGameplaySystemAbilityRules> GrantedAbilties;" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ActivePlayerWidgets = { "ActivePlayerWidgets", nullptr, (EPropertyFlags)0x0010008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaGameplaySystem, ActivePlayerWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ActivePlayerWidgets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ActivePlayerWidgets_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOmegaGameplaySystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_SubsysRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_TempFlag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_OnSystemShutdown,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddedPlayerWidgets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddedPlayerWidgets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddPlayerInputMapping_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_AddPlayerInputMapping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ActivePlayerWidgets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaGameplaySystem_Statics::NewProp_ActivePlayerWidgets,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UOmegaSaveInterface_NoRegister, (int32)VTABLE_OFFSET(AOmegaGameplaySystem, IOmegaSaveInterface), false },  // 1733132305
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOmegaGameplaySystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOmegaGameplaySystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOmegaGameplaySystem_Statics::ClassParams = {
		&AOmegaGameplaySystem::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AOmegaGameplaySystem_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AOmegaGameplaySystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaGameplaySystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOmegaGameplaySystem()
	{
		if (!Z_Registration_Info_UClass_AOmegaGameplaySystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOmegaGameplaySystem.OuterSingleton, Z_Construct_UClass_AOmegaGameplaySystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOmegaGameplaySystem.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<AOmegaGameplaySystem>()
	{
		return AOmegaGameplaySystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOmegaGameplaySystem);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_Statics::ScriptStructInfo[] = {
		{ FGameplaySystemAbilityRules::StaticStruct, Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics::NewStructOps, TEXT("GameplaySystemAbilityRules"), &Z_Registration_Info_UScriptStruct_GameplaySystemAbilityRules, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameplaySystemAbilityRules), 2409136945U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOmegaGameplaySystem, AOmegaGameplaySystem::StaticClass, TEXT("AOmegaGameplaySystem"), &Z_Registration_Info_UClass_AOmegaGameplaySystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOmegaGameplaySystem), 1958770415U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_1190908625(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

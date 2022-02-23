// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaGameManager.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameManager() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameMode_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameManager_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameManager();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameplayModule_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameSettings_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnGlobalEvent_Parms
		{
			FName Event;
			UObject* Instigator;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_Event;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnGlobalEvent_Parms, Event), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnGlobalEvent_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::NewProp_Event,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnGlobalEvent__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnGlobalEvent_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnNewLevel_Parms
		{
			FString LevelName;
			AOmegaGameMode* GameMode;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_LevelName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GameMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::NewProp_LevelName = { "LevelName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnNewLevel_Parms, LevelName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::NewProp_GameMode = { "GameMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnNewLevel_Parms, GameMode), Z_Construct_UClass_AOmegaGameMode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::NewProp_LevelName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::NewProp_GameMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnNewLevel__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnNewLevel_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UOmegaGameManager::execGetGameplayModules)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UOmegaGameplayModule*>*)Z_Param__Result=P_THIS->GetGameplayModules();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameManager::execGetGameplayModule)
	{
		P_GET_OBJECT(UClass,Z_Param_Module);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UOmegaGameplayModule**)Z_Param__Result=P_THIS->GetGameplayModule(Z_Param_Module);
		P_NATIVE_END;
	}
	void UOmegaGameManager::StaticRegisterNativesUOmegaGameManager()
	{
		UClass* Class = UOmegaGameManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetGameplayModule", &UOmegaGameManager::execGetGameplayModule },
			{ "GetGameplayModules", &UOmegaGameManager::execGetGameplayModules },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics
	{
		struct OmegaGameManager_eventGetGameplayModule_Parms
		{
			TSubclassOf<UOmegaGameplayModule>  Module;
			UOmegaGameplayModule* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_Module;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::NewProp_Module = { "Module", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameManager_eventGetGameplayModule_Parms, Module), Z_Construct_UClass_UOmegaGameplayModule_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameManager_eventGetGameplayModule_Parms, ReturnValue), Z_Construct_UClass_UOmegaGameplayModule_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::NewProp_Module,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|GameplayModules" },
		{ "CompactNodeTitle", "Gameplay Module" },
		{ "DeterminesOutputType", "Module" },
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameManager, nullptr, "GetGameplayModule", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::OmegaGameManager_eventGetGameplayModule_Parms), Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics
	{
		struct OmegaGameManager_eventGetGameplayModules_Parms
		{
			TArray<UOmegaGameplayModule*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaGameplayModule_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameManager_eventGetGameplayModules_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|GameplayModules" },
		{ "CompactNodeTitle", "Gameplay Modules" },
		{ "DeterminesOutputType", "Module" },
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameManager, nullptr, "GetGameplayModules", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::OmegaGameManager_eventGetGameplayModules_Parms), Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaGameManager);
	UClass* Z_Construct_UClass_UOmegaGameManager_NoRegister()
	{
		return UOmegaGameManager::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaGameManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomGameSettings_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CustomGameSettings;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveModules_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveModules_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveModules;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGlobalEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGlobalEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnNewLevel_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnNewLevel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaGameManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaGameManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaGameManager_GetGameplayModule, "GetGameplayModule" }, // 3419576126
		{ &Z_Construct_UFunction_UOmegaGameManager_GetGameplayModules, "GetGameplayModules" }, // 2575162560
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameManager_Statics::Class_MetaDataParams[] = {
		{ "Category", "OmegaSubsystems|Instance" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OmegaGameManager.h" },
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_CustomGameSettings_MetaData[] = {
		{ "Category", "\xce\xa9|Settings" },
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_CustomGameSettings = { "CustomGameSettings", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameManager, CustomGameSettings), Z_Construct_UClass_UOmegaGameSettings_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_CustomGameSettings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_CustomGameSettings_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_ActiveModules_Inner = { "ActiveModules", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaGameplayModule_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_ActiveModules_MetaData[] = {
		{ "Comment", "///GAMEPLAY MODULES\n///\n" },
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
		{ "ToolTip", "GAMEPLAY MODULES" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_ActiveModules = { "ActiveModules", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameManager, ActiveModules), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_ActiveModules_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_ActiveModules_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnGlobalEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnGlobalEvent = { "OnGlobalEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameManager, OnGlobalEvent), Z_Construct_UDelegateFunction_OmegaGameFramework_OnGlobalEvent__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnGlobalEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnGlobalEvent_MetaData)) }; // 3613166421
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnNewLevel_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaGameManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnNewLevel = { "OnNewLevel", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameManager, OnNewLevel), Z_Construct_UDelegateFunction_OmegaGameFramework_OnNewLevel__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnNewLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnNewLevel_MetaData)) }; // 1120588450
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaGameManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_CustomGameSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_ActiveModules_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_ActiveModules,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnGlobalEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameManager_Statics::NewProp_OnNewLevel,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaGameManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaGameManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaGameManager_Statics::ClassParams = {
		&UOmegaGameManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaGameManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameManager_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaGameManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaGameManager()
	{
		if (!Z_Registration_Info_UClass_UOmegaGameManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaGameManager.OuterSingleton, Z_Construct_UClass_UOmegaGameManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaGameManager.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaGameManager>()
	{
		return UOmegaGameManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaGameManager);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaGameManager, UOmegaGameManager::StaticClass, TEXT("UOmegaGameManager"), &Z_Registration_Info_UClass_UOmegaGameManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaGameManager), 632617297U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_1044290917(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

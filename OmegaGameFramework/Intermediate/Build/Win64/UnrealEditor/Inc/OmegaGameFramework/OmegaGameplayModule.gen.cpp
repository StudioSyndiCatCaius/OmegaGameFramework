// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/OmegaGameplayModule.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameplayModule() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameplayModule_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameplayModule();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGame_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameMode_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplaySystem_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UOmegaGameplayModule::execGameFileSaved)
	{
		P_GET_OBJECT(UOmegaSaveGame,Z_Param_SaveFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GameFileSaved_Implementation(Z_Param_SaveFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameplayModule::execGetGameInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UGameInstance**)Z_Param__Result=P_THIS->GetGameInstance();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameplayModule::execNative_Initialize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Native_Initialize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameplayModule::execNative_OnLevelOpened)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_LevelName);
		P_GET_OBJECT(AOmegaGameMode,Z_Param_GameMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Native_OnLevelOpened(Z_Param_LevelName,Z_Param_GameMode);
		P_NATIVE_END;
	}
	static FName NAME_UOmegaGameplayModule_GameFileSaved = FName(TEXT("GameFileSaved"));
	bool UOmegaGameplayModule::GameFileSaved(UOmegaSaveGame* SaveFile)
	{
		OmegaGameplayModule_eventGameFileSaved_Parms Parms;
		Parms.SaveFile=SaveFile;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaGameplayModule_GameFileSaved),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_UOmegaGameplayModule_GameFileStarted = FName(TEXT("GameFileStarted"));
	void UOmegaGameplayModule::GameFileStarted(UOmegaSaveGame* SaveFile)
	{
		OmegaGameplayModule_eventGameFileStarted_Parms Parms;
		Parms.SaveFile=SaveFile;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaGameplayModule_GameFileStarted),&Parms);
	}
	static FName NAME_UOmegaGameplayModule_Initialized = FName(TEXT("Initialized"));
	void UOmegaGameplayModule::Initialized()
	{
		ProcessEvent(FindFunctionChecked(NAME_UOmegaGameplayModule_Initialized),NULL);
	}
	static FName NAME_UOmegaGameplayModule_OnGlobalEvent = FName(TEXT("OnGlobalEvent"));
	void UOmegaGameplayModule::OnGlobalEvent(FName Event, UObject* Instigator)
	{
		OmegaGameplayModule_eventOnGlobalEvent_Parms Parms;
		Parms.Event=Event;
		Parms.Instigator=Instigator;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaGameplayModule_OnGlobalEvent),&Parms);
	}
	static FName NAME_UOmegaGameplayModule_OnLevelOpened = FName(TEXT("OnLevelOpened"));
	void UOmegaGameplayModule::OnLevelOpened(const FString& LevelName, AOmegaGameMode* GameMode)
	{
		OmegaGameplayModule_eventOnLevelOpened_Parms Parms;
		Parms.LevelName=LevelName;
		Parms.GameMode=GameMode;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaGameplayModule_OnLevelOpened),&Parms);
	}
	static FName NAME_UOmegaGameplayModule_Shutdown = FName(TEXT("Shutdown"));
	void UOmegaGameplayModule::Shutdown()
	{
		ProcessEvent(FindFunctionChecked(NAME_UOmegaGameplayModule_Shutdown),NULL);
	}
	void UOmegaGameplayModule::StaticRegisterNativesUOmegaGameplayModule()
	{
		UClass* Class = UOmegaGameplayModule::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GameFileSaved", &UOmegaGameplayModule::execGameFileSaved },
			{ "GetGameInstance", &UOmegaGameplayModule::execGetGameInstance },
			{ "Native_Initialize", &UOmegaGameplayModule::execNative_Initialize },
			{ "Native_OnLevelOpened", &UOmegaGameplayModule::execNative_OnLevelOpened },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveFile;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::NewProp_SaveFile = { "SaveFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventGameFileSaved_Parms, SaveFile), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaGameplayModule_eventGameFileSaved_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaGameplayModule_eventGameFileSaved_Parms), &Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::NewProp_SaveFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayModule" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "GameFileSaved", nullptr, nullptr, sizeof(OmegaGameplayModule_eventGameFileSaved_Parms), Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveFile;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::NewProp_SaveFile = { "SaveFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventGameFileStarted_Parms, SaveFile), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::NewProp_SaveFile,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayModule" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "GameFileStarted", nullptr, nullptr, sizeof(OmegaGameplayModule_eventGameFileStarted_Parms), Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics
	{
		struct OmegaGameplayModule_eventGetGameInstance_Parms
		{
			UGameInstance* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventGetGameInstance_Parms, ReturnValue), Z_Construct_UClass_UGameInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "GetGameInstance", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::OmegaGameplayModule_eventGetGameInstance_Parms), Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_Initialized_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_Initialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayModule" },
		{ "Comment", "//Functions\n" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
		{ "ToolTip", "Functions" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_Initialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "Initialized", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_Initialized_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_Initialized_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_Initialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_Initialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "Native_Initialize", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics
	{
		struct OmegaGameplayModule_eventNative_OnLevelOpened_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::NewProp_LevelName = { "LevelName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventNative_OnLevelOpened_Parms, LevelName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::NewProp_GameMode = { "GameMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventNative_OnLevelOpened_Parms, GameMode), Z_Construct_UClass_AOmegaGameMode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::NewProp_LevelName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::NewProp_GameMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "Native_OnLevelOpened", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::OmegaGameplayModule_eventNative_OnLevelOpened_Parms), Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_Event;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventOnGlobalEvent_Parms, Event), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventOnGlobalEvent_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::NewProp_Event,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "OnGlobalEvent", nullptr, nullptr, sizeof(OmegaGameplayModule_eventOnGlobalEvent_Parms), Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LevelName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LevelName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GameMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::NewProp_LevelName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::NewProp_LevelName = { "LevelName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventOnLevelOpened_Parms, LevelName), METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::NewProp_LevelName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::NewProp_LevelName_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::NewProp_GameMode = { "GameMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplayModule_eventOnLevelOpened_Parms, GameMode), Z_Construct_UClass_AOmegaGameMode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::NewProp_LevelName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::NewProp_GameMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "OnLevelOpened", nullptr, nullptr, sizeof(OmegaGameplayModule_eventOnLevelOpened_Parms), Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplayModule_Shutdown_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplayModule_Shutdown_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayModule" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplayModule_Shutdown_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplayModule, nullptr, "Shutdown", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplayModule_Shutdown_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplayModule_Shutdown_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplayModule_Shutdown()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplayModule_Shutdown_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaGameplayModule);
	UClass* Z_Construct_UClass_UOmegaGameplayModule_NoRegister()
	{
		return UOmegaGameplayModule::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaGameplayModule_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldPrivate_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldPrivate;
		static const UECodeGen_Private::FClassPropertyParams NewProp_AutoGameplaySystems_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoGameplaySystems_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AutoGameplaySystems;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaGameplayModule_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaGameplayModule_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaGameplayModule_GameFileSaved, "GameFileSaved" }, // 3657907078
		{ &Z_Construct_UFunction_UOmegaGameplayModule_GameFileStarted, "GameFileStarted" }, // 3485049218
		{ &Z_Construct_UFunction_UOmegaGameplayModule_GetGameInstance, "GetGameInstance" }, // 3665139863
		{ &Z_Construct_UFunction_UOmegaGameplayModule_Initialized, "Initialized" }, // 2506342852
		{ &Z_Construct_UFunction_UOmegaGameplayModule_Native_Initialize, "Native_Initialize" }, // 4213076474
		{ &Z_Construct_UFunction_UOmegaGameplayModule_Native_OnLevelOpened, "Native_OnLevelOpened" }, // 2353251439
		{ &Z_Construct_UFunction_UOmegaGameplayModule_OnGlobalEvent, "OnGlobalEvent" }, // 4236476431
		{ &Z_Construct_UFunction_UOmegaGameplayModule_OnLevelOpened, "OnLevelOpened" }, // 1548655956
		{ &Z_Construct_UFunction_UOmegaGameplayModule_Shutdown, "Shutdown" }, // 3642834684
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameplayModule_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Gameplay/OmegaGameplayModule.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_WorldPrivate_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_WorldPrivate = { "WorldPrivate", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameplayModule, WorldPrivate), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_WorldPrivate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_WorldPrivate_MetaData)) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_AutoGameplaySystems_Inner = { "AutoGameplaySystems", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_AutoGameplaySystems_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "//Properties\n" },
		{ "ModuleRelativePath", "Public/Gameplay/OmegaGameplayModule.h" },
		{ "ToolTip", "Properties" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_AutoGameplaySystems = { "AutoGameplaySystems", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameplayModule, AutoGameplaySystems), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_AutoGameplaySystems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_AutoGameplaySystems_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaGameplayModule_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_WorldPrivate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_AutoGameplaySystems_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameplayModule_Statics::NewProp_AutoGameplaySystems,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaGameplayModule_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaGameplayModule>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaGameplayModule_Statics::ClassParams = {
		&UOmegaGameplayModule::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaGameplayModule_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplayModule_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaGameplayModule_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplayModule_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaGameplayModule()
	{
		if (!Z_Registration_Info_UClass_UOmegaGameplayModule.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaGameplayModule.OuterSingleton, Z_Construct_UClass_UOmegaGameplayModule_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaGameplayModule.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaGameplayModule>()
	{
		return UOmegaGameplayModule::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaGameplayModule);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaGameplayModule, UOmegaGameplayModule::StaticClass, TEXT("UOmegaGameplayModule"), &Z_Registration_Info_UClass_UOmegaGameplayModule, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaGameplayModule), 461698831U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_2874142348(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

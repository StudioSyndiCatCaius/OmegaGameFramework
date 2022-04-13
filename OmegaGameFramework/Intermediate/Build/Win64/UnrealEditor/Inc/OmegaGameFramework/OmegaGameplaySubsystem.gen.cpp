// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaGameplaySubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameplaySubsystem() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameplaySubsystem_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameplaySubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaGameplaySystem_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UOmegaGameplaySubsystem::execNativeRemoveSystem)
	{
		P_GET_OBJECT(AOmegaGameplaySystem,Z_Param_System);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NativeRemoveSystem(Z_Param_System);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameplaySubsystem::execGetAllCombatants)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UCombatantComponent*>*)Z_Param__Result=P_THIS->GetAllCombatants();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameplaySubsystem::execGetGameplaySystem)
	{
		P_GET_OBJECT(UClass,Z_Param_Class);
		P_GET_UBOOL_REF(Z_Param_Out_bIsActive);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOmegaGameplaySystem**)Z_Param__Result=P_THIS->GetGameplaySystem(Z_Param_Class,Z_Param_Out_bIsActive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameplaySubsystem::execShutdownGameplaySystem)
	{
		P_GET_OBJECT(UClass,Z_Param_Class);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ShutdownGameplaySystem(Z_Param_Class,Z_Param_Flag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaGameplaySubsystem::execActivateGameplaySystem)
	{
		P_GET_OBJECT(UClass,Z_Param_Class);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AOmegaGameplaySystem**)Z_Param__Result=P_THIS->ActivateGameplaySystem(Z_Param_Class,Z_Param_Context,Z_Param_Flag);
		P_NATIVE_END;
	}
	void UOmegaGameplaySubsystem::StaticRegisterNativesUOmegaGameplaySubsystem()
	{
		UClass* Class = UOmegaGameplaySubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActivateGameplaySystem", &UOmegaGameplaySubsystem::execActivateGameplaySystem },
			{ "GetAllCombatants", &UOmegaGameplaySubsystem::execGetAllCombatants },
			{ "GetGameplaySystem", &UOmegaGameplaySubsystem::execGetGameplaySystem },
			{ "NativeRemoveSystem", &UOmegaGameplaySubsystem::execNativeRemoveSystem },
			{ "ShutdownGameplaySystem", &UOmegaGameplaySubsystem::execShutdownGameplaySystem },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics
	{
		struct OmegaGameplaySubsystem_eventActivateGameplaySystem_Parms
		{
			TSubclassOf<AOmegaGameplaySystem>  Class;
			UObject* Context;
			FString Flag;
			AOmegaGameplaySystem* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventActivateGameplaySystem_Parms, Class), Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventActivateGameplaySystem_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventActivateGameplaySystem_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventActivateGameplaySystem_Parms, ReturnValue), Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_Class,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Context, Flag" },
		{ "Category", "\xce\xa9|Gameplay" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplaySubsystem, nullptr, "ActivateGameplaySystem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::OmegaGameplaySubsystem_eventActivateGameplaySystem_Parms), Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics
	{
		struct OmegaGameplaySubsystem_eventGetAllCombatants_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventGetAllCombatants_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplaySubsystem, nullptr, "GetAllCombatants", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::OmegaGameplaySubsystem_eventGetAllCombatants_Parms), Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics
	{
		struct OmegaGameplaySubsystem_eventGetGameplaySystem_Parms
		{
			TSubclassOf<AOmegaGameplaySystem>  Class;
			bool bIsActive;
			AOmegaGameplaySystem* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
		static void NewProp_bIsActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventGetGameplaySystem_Parms, Class), Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_bIsActive_SetBit(void* Obj)
	{
		((OmegaGameplaySubsystem_eventGetGameplaySystem_Parms*)Obj)->bIsActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaGameplaySubsystem_eventGetGameplaySystem_Parms), &Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_bIsActive_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventGetGameplaySystem_Parms, ReturnValue), Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_Class,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_bIsActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Gameplay" },
		{ "DeterminesOutputType", "Class" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplaySubsystem, nullptr, "GetGameplaySystem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::OmegaGameplaySubsystem_eventGetGameplaySystem_Parms), Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics
	{
		struct OmegaGameplaySubsystem_eventNativeRemoveSystem_Parms
		{
			AOmegaGameplaySystem* System;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_System;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::NewProp_System = { "System", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventNativeRemoveSystem_Parms, System), Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::NewProp_System,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplaySubsystem, nullptr, "NativeRemoveSystem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::OmegaGameplaySubsystem_eventNativeRemoveSystem_Parms), Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics
	{
		struct OmegaGameplaySubsystem_eventShutdownGameplaySystem_Parms
		{
			TSubclassOf<AOmegaGameplaySystem>  Class;
			FString Flag;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventShutdownGameplaySystem_Parms, Class), Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameplaySubsystem_eventShutdownGameplaySystem_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaGameplaySubsystem_eventShutdownGameplaySystem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaGameplaySubsystem_eventShutdownGameplaySystem_Parms), &Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_Class,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Context, Flag" },
		{ "Category", "\xce\xa9|Gameplay" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameplaySubsystem, nullptr, "ShutdownGameplaySystem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::OmegaGameplaySubsystem_eventShutdownGameplaySystem_Parms), Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaGameplaySubsystem);
	UClass* Z_Construct_UClass_UOmegaGameplaySubsystem_NoRegister()
	{
		return UOmegaGameplaySubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaGameplaySubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveCombatants_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveCombatants_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveCombatants;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveSystems_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveSystems_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveSystems;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaGameplaySubsystem_ActivateGameplaySystem, "ActivateGameplaySystem" }, // 2246722047
		{ &Z_Construct_UFunction_UOmegaGameplaySubsystem_GetAllCombatants, "GetAllCombatants" }, // 1886968036
		{ &Z_Construct_UFunction_UOmegaGameplaySubsystem_GetGameplaySystem, "GetGameplaySystem" }, // 1942441813
		{ &Z_Construct_UFunction_UOmegaGameplaySubsystem_NativeRemoveSystem, "NativeRemoveSystem" }, // 2510642486
		{ &Z_Construct_UFunction_UOmegaGameplaySubsystem_ShutdownGameplaySystem, "ShutdownGameplaySystem" }, // 1343041479
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OmegaGameplaySubsystem.h" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveCombatants_Inner = { "ActiveCombatants", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveCombatants_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveCombatants = { "ActiveCombatants", nullptr, (EPropertyFlags)0x0010008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameplaySubsystem, ActiveCombatants), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveCombatants_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveCombatants_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveSystems_Inner = { "ActiveSystems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AOmegaGameplaySystem_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveSystems_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaGameplaySubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveSystems = { "ActiveSystems", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaGameplaySubsystem, ActiveSystems), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveSystems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveSystems_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveCombatants_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveCombatants,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveSystems_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::NewProp_ActiveSystems,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaGameplaySubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::ClassParams = {
		&UOmegaGameplaySubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaGameplaySubsystem()
	{
		if (!Z_Registration_Info_UClass_UOmegaGameplaySubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaGameplaySubsystem.OuterSingleton, Z_Construct_UClass_UOmegaGameplaySubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaGameplaySubsystem.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaGameplaySubsystem>()
	{
		return UOmegaGameplaySubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaGameplaySubsystem);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaGameplaySubsystem, UOmegaGameplaySubsystem::StaticClass, TEXT("UOmegaGameplaySubsystem"), &Z_Registration_Info_UClass_UOmegaGameplaySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaGameplaySubsystem), 59844250U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySubsystem_h_2279292271(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

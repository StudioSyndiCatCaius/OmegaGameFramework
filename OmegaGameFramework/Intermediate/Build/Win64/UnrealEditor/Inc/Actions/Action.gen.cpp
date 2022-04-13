// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Public/Action.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAction() {}
// Cross Module References
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_Actions();
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature();
	ACTIONS_API UEnum* Z_Construct_UEnum_Actions_EActionState();
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature();
	ACTIONS_API UFunction* Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature();
	ACTIONS_API UClass* Z_Construct_UClass_UAction_NoRegister();
	ACTIONS_API UClass* Z_Construct_UClass_UAction();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Actions, nullptr, "OnSucess__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Actions, nullptr, "OnFailure__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EActionState;
	static UEnum* EActionState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EActionState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EActionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Actions_EActionState, Z_Construct_UPackage__Script_Actions(), TEXT("EActionState"));
		}
		return Z_Registration_Info_UEnum_EActionState.OuterSingleton;
	}
	template<> ACTIONS_API UEnum* StaticEnum<EActionState>()
	{
		return EActionState_StaticEnum();
	}
	struct Z_Construct_UEnum_Actions_EActionState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Actions_EActionState_Statics::Enumerators[] = {
		{ "EActionState::Preparing", (int64)EActionState::Preparing },
		{ "EActionState::Running", (int64)EActionState::Running },
		{ "EActionState::Success", (int64)EActionState::Success },
		{ "EActionState::Failure", (int64)EActionState::Failure },
		{ "EActionState::Cancelled", (int64)EActionState::Cancelled },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Actions_EActionState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Cancelled.Hidden", "" },
		{ "Cancelled.Name", "EActionState::Cancelled" },
		{ "Comment", "/**\n * Result of a node execution\n */" },
		{ "Failure.Name", "EActionState::Failure" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "Preparing.Hidden", "" },
		{ "Preparing.Name", "EActionState::Preparing" },
		{ "Running.Hidden", "" },
		{ "Running.Name", "EActionState::Running" },
		{ "Success.Name", "EActionState::Success" },
		{ "ToolTip", "Result of a node execution" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Actions_EActionState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Actions,
		nullptr,
		"EActionState",
		"EActionState",
		Z_Construct_UEnum_Actions_EActionState_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Actions_EActionState_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_Actions_EActionState_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Actions_EActionState_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Actions_EActionState()
	{
		if (!Z_Registration_Info_UEnum_EActionState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EActionState.InnerSingleton, Z_Construct_UEnum_Actions_EActionState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EActionState.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Actions, nullptr, "ActionActivatedDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics
	{
		struct _Script_Actions_eventActionFinishedDelegate_Parms
		{
			EActionState Reason;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Actions_eventActionFinishedDelegate_Parms, Reason), Z_Construct_UEnum_Actions_EActionState, METADATA_PARAMS(Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::NewProp_Reason_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::NewProp_Reason_MetaData)) }; // 841316052
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::NewProp_Reason_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::NewProp_Reason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Actions, nullptr, "ActionFinishedDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::_Script_Actions_eventActionFinishedDelegate_Parms), Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UAction::execGetOwnerComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UActorComponent**)Z_Param__Result=P_THIS->GetOwnerComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execGetOwnerActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->GetOwnerActor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execGetOwner)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=P_THIS->GetOwner();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execGetTickRate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetTickRate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execGetParentAction)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAction**)Z_Param__Result=P_THIS->GetParentAction();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execGetParent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(const UObject**)Z_Param__Result=P_THIS->GetParent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execGetState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EActionState*)Z_Param__Result=P_THIS->GetState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execFailed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Failed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execSucceeded)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Succeeded();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execIsRunning)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsRunning();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execReceiveCanActivate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ReceiveCanActivate_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execFail)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Error);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Fail(Z_Param_Error);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execSucceed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Succeed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UAction::execActivate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Activate();
		P_NATIVE_END;
	}
	static FName NAME_UAction_ReceiveActivate = FName(TEXT("ReceiveActivate"));
	void UAction::ReceiveActivate()
	{
		ProcessEvent(FindFunctionChecked(NAME_UAction_ReceiveActivate),NULL);
	}
	static FName NAME_UAction_ReceiveCanActivate = FName(TEXT("ReceiveCanActivate"));
	bool UAction::ReceiveCanActivate()
	{
		Action_eventReceiveCanActivate_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UAction_ReceiveCanActivate),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_UAction_ReceiveCancel = FName(TEXT("ReceiveCancel"));
	void UAction::ReceiveCancel()
	{
		ProcessEvent(FindFunctionChecked(NAME_UAction_ReceiveCancel),NULL);
	}
	static FName NAME_UAction_ReceiveFinished = FName(TEXT("ReceiveFinished"));
	void UAction::ReceiveFinished(const EActionState Reason)
	{
		Action_eventReceiveFinished_Parms Parms;
		Parms.Reason=Reason;
		ProcessEvent(FindFunctionChecked(NAME_UAction_ReceiveFinished),&Parms);
	}
	static FName NAME_UAction_ReceiveTick = FName(TEXT("ReceiveTick"));
	void UAction::ReceiveTick(float DeltaTime)
	{
		Action_eventReceiveTick_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		ProcessEvent(FindFunctionChecked(NAME_UAction_ReceiveTick),&Parms);
	}
	void UAction::StaticRegisterNativesUAction()
	{
		UClass* Class = UAction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Activate", &UAction::execActivate },
			{ "Fail", &UAction::execFail },
			{ "Failed", &UAction::execFailed },
			{ "GetOwner", &UAction::execGetOwner },
			{ "GetOwnerActor", &UAction::execGetOwnerActor },
			{ "GetOwnerComponent", &UAction::execGetOwnerComponent },
			{ "GetParent", &UAction::execGetParent },
			{ "GetParentAction", &UAction::execGetParentAction },
			{ "GetState", &UAction::execGetState },
			{ "GetTickRate", &UAction::execGetTickRate },
			{ "IsRunning", &UAction::execIsRunning },
			{ "ReceiveCanActivate", &UAction::execReceiveCanActivate },
			{ "Succeed", &UAction::execSucceed },
			{ "Succeeded", &UAction::execSucceeded },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAction_Activate_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_Activate_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "GameplayAction" },
		{ "Comment", "/** Called to active an action if not already. */" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Called to active an action if not already." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_Activate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "Activate", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_Activate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Activate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_Activate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_Activate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_Fail_Statics
	{
		struct Action_eventFail_Parms
		{
			FName Error;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_Error;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UAction_Fail_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventFail_Parms, Error), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_Fail_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_Fail_Statics::NewProp_Error,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_Fail_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "CPP_Default_Error", "None" },
		{ "KeyWords", "Finish" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_Fail_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "Fail", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_Fail_Statics::Action_eventFail_Parms), Z_Construct_UFunction_UAction_Fail_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Fail_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_Fail_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Fail_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_Fail()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_Fail_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_Failed_Statics
	{
		struct Action_eventFailed_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAction_Failed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Action_eventFailed_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAction_Failed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Action_eventFailed_Parms), &Z_Construct_UFunction_UAction_Failed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_Failed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_Failed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_Failed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_Failed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "Failed", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_Failed_Statics::Action_eventFailed_Parms), Z_Construct_UFunction_UAction_Failed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Failed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_Failed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Failed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_Failed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_Failed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetOwner_Statics
	{
		struct Action_eventGetOwner_Parms
		{
			UObject* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAction_GetOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetOwner_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetOwner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "Comment", "/** @return the object that executes the root action */" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "@return the object that executes the root action" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetOwner", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_GetOwner_Statics::Action_eventGetOwner_Parms), Z_Construct_UFunction_UAction_GetOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_GetOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetOwnerActor_Statics
	{
		struct Action_eventGetOwnerActor_Parms
		{
			AActor* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAction_GetOwnerActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetOwnerActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetOwnerActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetOwnerActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetOwnerActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "Comment", "/** @return the actor if any that executes the root action */" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "@return the actor if any that executes the root action" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetOwnerActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetOwnerActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_GetOwnerActor_Statics::Action_eventGetOwnerActor_Parms), Z_Construct_UFunction_UAction_GetOwnerActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetOwnerActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetOwnerActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetOwnerActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetOwnerActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_GetOwnerActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetOwnerComponent_Statics
	{
		struct Action_eventGetOwnerComponent_Parms
		{
			UActorComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetOwnerComponent_Parms, ReturnValue), Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "Comment", "/** @return the component if any that executes the root action */" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "@return the component if any that executes the root action" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetOwnerComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::Action_eventGetOwnerComponent_Parms), Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetOwnerComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_GetOwnerComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetParent_Statics
	{
		struct Action_eventGetParent_Parms
		{
			const UObject* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetParent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAction_GetParent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetParent_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetParent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetParent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetParent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetParent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetParent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetParent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetParent", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_GetParent_Statics::Action_eventGetParent_Parms), Z_Construct_UFunction_UAction_GetParent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetParent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetParent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetParent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetParent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_GetParent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetParentAction_Statics
	{
		struct Action_eventGetParentAction_Parms
		{
			UAction* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAction_GetParentAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetParentAction_Parms, ReturnValue), Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetParentAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetParentAction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetParentAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetParentAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetParentAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_GetParentAction_Statics::Action_eventGetParentAction_Parms), Z_Construct_UFunction_UAction_GetParentAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetParentAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetParentAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetParentAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetParentAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_GetParentAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetState_Statics
	{
		struct Action_eventGetState_Parms
		{
			EActionState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAction_GetState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAction_GetState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetState_Parms, ReturnValue), Z_Construct_UEnum_Actions_EActionState, METADATA_PARAMS(nullptr, 0) }; // 841316052
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetState", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_GetState_Statics::Action_eventGetState_Parms), Z_Construct_UFunction_UAction_GetState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_GetState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetTickRate_Statics
	{
		struct Action_eventGetTickRate_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAction_GetTickRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetTickRate_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetTickRate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetTickRate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetTickRate_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetTickRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetTickRate", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_GetTickRate_Statics::Action_eventGetTickRate_Parms), Z_Construct_UFunction_UAction_GetTickRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetTickRate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetTickRate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_GetTickRate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetTickRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_GetTickRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_IsRunning_Statics
	{
		struct Action_eventIsRunning_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAction_IsRunning_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Action_eventIsRunning_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAction_IsRunning_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Action_eventIsRunning_Parms), &Z_Construct_UFunction_UAction_IsRunning_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_IsRunning_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_IsRunning_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_IsRunning_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_IsRunning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "IsRunning", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_IsRunning_Statics::Action_eventIsRunning_Parms), Z_Construct_UFunction_UAction_IsRunning_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_IsRunning_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_IsRunning_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_IsRunning_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_IsRunning()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_IsRunning_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_ReceiveActivate_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_ReceiveActivate_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Called when this action is activated */" },
		{ "DisplayName", "Activate" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Called when this action is activated" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_ReceiveActivate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "ReceiveActivate", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_ReceiveActivate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveActivate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_ReceiveActivate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_ReceiveActivate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Action_eventReceiveCanActivate_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Action_eventReceiveCanActivate_Parms), &Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Event called to check if an action can activate. */" },
		{ "DisplayName", "Can Activate" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Event called to check if an action can activate." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "ReceiveCanActivate", nullptr, nullptr, sizeof(Action_eventReceiveCanActivate_Parms), Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_ReceiveCanActivate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_ReceiveCanActivate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_ReceiveCancel_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_ReceiveCancel_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Called when this action cancels */" },
		{ "DisplayName", "Cancelled" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Called when this action cancels" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_ReceiveCancel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "ReceiveCancel", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_ReceiveCancel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveCancel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_ReceiveCancel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_ReceiveCancel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_ReceiveFinished_Statics
	{
		static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UAction_ReceiveFinished_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_ReceiveFinished_Statics::NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UAction_ReceiveFinished_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventReceiveFinished_Parms, Reason), Z_Construct_UEnum_Actions_EActionState, METADATA_PARAMS(Z_Construct_UFunction_UAction_ReceiveFinished_Statics::NewProp_Reason_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveFinished_Statics::NewProp_Reason_MetaData)) }; // 841316052
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_ReceiveFinished_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_ReceiveFinished_Statics::NewProp_Reason_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_ReceiveFinished_Statics::NewProp_Reason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_ReceiveFinished_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Called when this action finishes */" },
		{ "DisplayName", "Finished" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Called when this action finishes" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_ReceiveFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "ReceiveFinished", nullptr, nullptr, sizeof(Action_eventReceiveFinished_Parms), Z_Construct_UFunction_UAction_ReceiveFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveFinished_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_ReceiveFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_ReceiveFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_ReceiveFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_ReceiveTick_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UAction_ReceiveTick_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventReceiveTick_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_ReceiveTick_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_ReceiveTick_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_ReceiveTick_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Called when tick is received based on TickRate */" },
		{ "DisplayName", "Tick" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Called when tick is received based on TickRate" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_ReceiveTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "ReceiveTick", nullptr, nullptr, sizeof(Action_eventReceiveTick_Parms), Z_Construct_UFunction_UAction_ReceiveTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveTick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_ReceiveTick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_ReceiveTick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_ReceiveTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_ReceiveTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_Succeed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_Succeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "KeyWords", "Finish" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_Succeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "Succeed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_Succeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Succeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_Succeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_Succeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_Succeeded_Statics
	{
		struct Action_eventSucceeded_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAction_Succeeded_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Action_eventSucceeded_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAction_Succeeded_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Action_eventSucceeded_Parms), &Z_Construct_UFunction_UAction_Succeeded_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_Succeeded_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_Succeeded_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_Succeeded_Statics::Function_MetaDataParams[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_Succeeded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "Succeeded", nullptr, nullptr, sizeof(Z_Construct_UFunction_UAction_Succeeded_Statics::Action_eventSucceeded_Parms), Z_Construct_UFunction_UAction_Succeeded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Succeeded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_Succeeded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UAction_Succeeded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_Succeeded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAction_Succeeded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAction);
	UClass* Z_Construct_UClass_UAction_NoRegister()
	{
		return UAction::StaticClass();
	}
	struct Z_Construct_UClass_UAction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bWantsToTick_MetaData[];
#endif
		static void NewProp_bWantsToTick_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWantsToTick;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NodeColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CategoryTag_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CategoryTag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActionTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ActionTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSuccess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFailure_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFailure;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TickRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TickRate;
		static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChildrenActions_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChildrenActions_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_ChildrenActions;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnActivationDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActivationDelegate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFinishedDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFinishedDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Actions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAction_Activate, "Activate" }, // 3070426429
		{ &Z_Construct_UFunction_UAction_Fail, "Fail" }, // 766732630
		{ &Z_Construct_UFunction_UAction_Failed, "Failed" }, // 2223395773
		{ &Z_Construct_UFunction_UAction_GetOwner, "GetOwner" }, // 3120710543
		{ &Z_Construct_UFunction_UAction_GetOwnerActor, "GetOwnerActor" }, // 3337808349
		{ &Z_Construct_UFunction_UAction_GetOwnerComponent, "GetOwnerComponent" }, // 1148015171
		{ &Z_Construct_UFunction_UAction_GetParent, "GetParent" }, // 3284778695
		{ &Z_Construct_UFunction_UAction_GetParentAction, "GetParentAction" }, // 3899610546
		{ &Z_Construct_UFunction_UAction_GetState, "GetState" }, // 3843836622
		{ &Z_Construct_UFunction_UAction_GetTickRate, "GetTickRate" }, // 2396968336
		{ &Z_Construct_UFunction_UAction_IsRunning, "IsRunning" }, // 2455209816
		{ &Z_Construct_UFunction_UAction_ReceiveActivate, "ReceiveActivate" }, // 3281868764
		{ &Z_Construct_UFunction_UAction_ReceiveCanActivate, "ReceiveCanActivate" }, // 509025984
		{ &Z_Construct_UFunction_UAction_ReceiveCancel, "ReceiveCancel" }, // 2139105872
		{ &Z_Construct_UFunction_UAction_ReceiveFinished, "ReceiveFinished" }, // 182418867
		{ &Z_Construct_UFunction_UAction_ReceiveTick, "ReceiveTick" }, // 3671499498
		{ &Z_Construct_UFunction_UAction_Succeed, "Succeed" }, // 1430087454
		{ &Z_Construct_UFunction_UAction_Succeeded, "Succeeded" }, // 3590438978
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n *\n */" },
		{ "DisplayName", "Gameplay Action" },
		{ "ExposedAsyncProxy", "" },
		{ "IncludePath", "Action.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_bWantsToTick_MetaData[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	void Z_Construct_UClass_UAction_Statics::NewProp_bWantsToTick_SetBit(void* Obj)
	{
		((UAction*)Obj)->bWantsToTick = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_bWantsToTick = { "bWantsToTick", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UAction), &Z_Construct_UClass_UAction_Statics::NewProp_bWantsToTick_SetBit, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_bWantsToTick_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_bWantsToTick_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_NodeColor_MetaData[] = {
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_NodeColor = { "NodeColor", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, NodeColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_NodeColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_NodeColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_CategoryTag_MetaData[] = {
		{ "Category", "Tags" },
		{ "Comment", "//Tags\n" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Tags" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_CategoryTag = { "CategoryTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, CategoryTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_CategoryTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_CategoryTag_MetaData)) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_ActionTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_ActionTags = { "ActionTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, ActionTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_ActionTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_ActionTags_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_OnSuccess_MetaData[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAction_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, OnSuccess), Z_Construct_UDelegateFunction_Actions_OnSucess__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_OnSuccess_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_OnSuccess_MetaData)) }; // 4243302461
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_OnFailure_MetaData[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAction_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, OnFailure), Z_Construct_UDelegateFunction_Actions_OnFailure__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_OnFailure_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_OnFailure_MetaData)) }; // 3239514199
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_TickRate_MetaData[] = {
		{ "BlueprintGetter", "GetTickRate" },
		{ "Category", "Action" },
		{ "Comment", "//Tick length in seconds. 0 is default tick rate\n" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Tick length in seconds. 0 is default tick rate" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_TickRate = { "TickRate", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, TickRate), METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_TickRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_TickRate_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UAction_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_State_MetaData[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, State), Z_Construct_UEnum_Actions_EActionState, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_State_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_State_MetaData)) }; // 841316052
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_ChildrenActions_ElementProp = { "ChildrenActions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_ChildrenActions_MetaData[] = {
		{ "ModuleRelativePath", "Public/Action.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UAction_Statics::NewProp_ChildrenActions = { "ChildrenActions", nullptr, (EPropertyFlags)0x0040000001000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, ChildrenActions), METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_ChildrenActions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_ChildrenActions_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_OnActivationDelegate_MetaData[] = {
		{ "Comment", "/** Delegates */// Notify when the action is activated\n" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Delegates // Notify when the action is activated" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAction_Statics::NewProp_OnActivationDelegate = { "OnActivationDelegate", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, OnActivationDelegate), Z_Construct_UDelegateFunction_Actions_ActionActivatedDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_OnActivationDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_OnActivationDelegate_MetaData)) }; // 817274533
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::NewProp_OnFinishedDelegate_MetaData[] = {
		{ "Comment", "// Notify when the action finished\n" },
		{ "ModuleRelativePath", "Public/Action.h" },
		{ "ToolTip", "Notify when the action finished" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAction_Statics::NewProp_OnFinishedDelegate = { "OnFinishedDelegate", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAction, OnFinishedDelegate), Z_Construct_UDelegateFunction_Actions_ActionFinishedDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::NewProp_OnFinishedDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::NewProp_OnFinishedDelegate_MetaData)) }; // 275687730
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_bWantsToTick,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_NodeColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_CategoryTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_ActionTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_OnSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_OnFailure,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_TickRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_State_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_ChildrenActions_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_ChildrenActions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_OnActivationDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAction_Statics::NewProp_OnFinishedDelegate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAction_Statics::ClassParams = {
		&UAction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UAction_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::PropPointers),
		0,
		0x009010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAction()
	{
		if (!Z_Registration_Info_UClass_UAction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAction.OuterSingleton, Z_Construct_UClass_UAction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAction.OuterSingleton;
	}
	template<> ACTIONS_API UClass* StaticClass<UAction>()
	{
		return UAction::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAction);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_Statics::EnumInfo[] = {
		{ EActionState_StaticEnum, TEXT("EActionState"), &Z_Registration_Info_UEnum_EActionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 841316052U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAction, UAction::StaticClass, TEXT("UAction"), &Z_Registration_Info_UClass_UAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAction), 3286409307U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_3170490920(TEXT("/Script/Actions"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

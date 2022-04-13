// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaAbility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaAbility() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaAbility_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaAbility();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UInputReceiverComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnAbilityEnd_Parms
		{
			bool bCancelled;
		};
		static void NewProp_bCancelled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCancelled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::NewProp_bCancelled_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnAbilityEnd_Parms*)Obj)->bCancelled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::NewProp_bCancelled = { "bCancelled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnAbilityEnd_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::NewProp_bCancelled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::NewProp_bCancelled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//\n// \n// Delegates\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "Delegates" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnAbilityEnd__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnAbilityEnd_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAbilityActivateInput;
	static UEnum* EAbilityActivateInput_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EAbilityActivateInput.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EAbilityActivateInput.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("EAbilityActivateInput"));
		}
		return Z_Registration_Info_UEnum_EAbilityActivateInput.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EAbilityActivateInput>()
	{
		return EAbilityActivateInput_StaticEnum();
	}
	struct Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::Enumerators[] = {
		{ "EAbilityActivateInput::AbilityActivateOn_Started", (int64)EAbilityActivateInput::AbilityActivateOn_Started },
		{ "EAbilityActivateInput::AbilityActivateOn_Triggered", (int64)EAbilityActivateInput::AbilityActivateOn_Triggered },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::Enum_MetaDataParams[] = {
		{ "AbilityActivateOn_Started.Comment", "/** Description. */" },
		{ "AbilityActivateOn_Started.DisplayName", "Started" },
		{ "AbilityActivateOn_Started.Name", "EAbilityActivateInput::AbilityActivateOn_Started" },
		{ "AbilityActivateOn_Started.ToolTip", "Description." },
		{ "AbilityActivateOn_Triggered.Comment", "/** Description. */" },
		{ "AbilityActivateOn_Triggered.DisplayName", "Triggered" },
		{ "AbilityActivateOn_Triggered.Name", "EAbilityActivateInput::AbilityActivateOn_Triggered" },
		{ "AbilityActivateOn_Triggered.ToolTip", "Description." },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		"EAbilityActivateInput",
		"EAbilityActivateInput",
		Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput()
	{
		if (!Z_Registration_Info_UEnum_EAbilityActivateInput.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAbilityActivateInput.InnerSingleton, Z_Construct_UEnum_OmegaGameFramework_EAbilityActivateInput_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EAbilityActivateInput.InnerSingleton;
	}
	DEFINE_FUNCTION(AOmegaAbility::execRecieveFinish)
	{
		P_GET_UBOOL(Z_Param_bCancel);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RecieveFinish(Z_Param_bCancel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execRemoveBlockedAbilityTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_RemovedTags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveBlockedAbilityTags(Z_Param_RemovedTags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execAddBlockedAbilityTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_AddedTags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddBlockedAbilityTags(Z_Param_AddedTags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execGetAbilityOwnerMesh)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USkeletalMeshComponent**)Z_Param__Result=P_THIS->GetAbilityOwnerMesh();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execGetAbilityOwnerCharacterMoveComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCharacterMovementComponent**)Z_Param__Result=P_THIS->GetAbilityOwnerCharacterMoveComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execGetAbilityOwnerCharacter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ACharacter**)Z_Param__Result=P_THIS->GetAbilityOwnerCharacter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execCancelAbility)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CancelAbility();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execCompleteAbility)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CompleteAbility();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execSetInputEnabledForOwner)
	{
		P_GET_UBOOL(Z_Param_Enabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetInputEnabledForOwner(Z_Param_Enabled);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execCanActivate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanActivate_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execNative_Trigger)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Native_Trigger();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execNative_Execute)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Native_Execute();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AOmegaAbility::execExecute)
	{
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Execute(Z_Param_Context);
		P_NATIVE_END;
	}
	static FName NAME_AOmegaAbility_AbilityActivated = FName(TEXT("AbilityActivated"));
	void AOmegaAbility::AbilityActivated(UObject* Context)
	{
		OmegaAbility_eventAbilityActivated_Parms Parms;
		Parms.Context=Context;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaAbility_AbilityActivated),&Parms);
	}
	static FName NAME_AOmegaAbility_AbilityFinished = FName(TEXT("AbilityFinished"));
	void AOmegaAbility::AbilityFinished(bool Cancelled)
	{
		OmegaAbility_eventAbilityFinished_Parms Parms;
		Parms.Cancelled=Cancelled ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaAbility_AbilityFinished),&Parms);
	}
	static FName NAME_AOmegaAbility_ActivatedTick = FName(TEXT("ActivatedTick"));
	void AOmegaAbility::ActivatedTick(float DeltaTime)
	{
		OmegaAbility_eventActivatedTick_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaAbility_ActivatedTick),&Parms);
	}
	static FName NAME_AOmegaAbility_CanActivate = FName(TEXT("CanActivate"));
	bool AOmegaAbility::CanActivate()
	{
		OmegaAbility_eventCanActivate_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AOmegaAbility_CanActivate),&Parms);
		return !!Parms.ReturnValue;
	}
	void AOmegaAbility::StaticRegisterNativesAOmegaAbility()
	{
		UClass* Class = AOmegaAbility::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddBlockedAbilityTags", &AOmegaAbility::execAddBlockedAbilityTags },
			{ "CanActivate", &AOmegaAbility::execCanActivate },
			{ "CancelAbility", &AOmegaAbility::execCancelAbility },
			{ "CompleteAbility", &AOmegaAbility::execCompleteAbility },
			{ "Execute", &AOmegaAbility::execExecute },
			{ "GetAbilityOwnerCharacter", &AOmegaAbility::execGetAbilityOwnerCharacter },
			{ "GetAbilityOwnerCharacterMoveComponent", &AOmegaAbility::execGetAbilityOwnerCharacterMoveComponent },
			{ "GetAbilityOwnerMesh", &AOmegaAbility::execGetAbilityOwnerMesh },
			{ "Native_Execute", &AOmegaAbility::execNative_Execute },
			{ "Native_Trigger", &AOmegaAbility::execNative_Trigger },
			{ "RecieveFinish", &AOmegaAbility::execRecieveFinish },
			{ "RemoveBlockedAbilityTags", &AOmegaAbility::execRemoveBlockedAbilityTags },
			{ "SetInputEnabledForOwner", &AOmegaAbility::execSetInputEnabledForOwner },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventAbilityActivated_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//**Start & End***//\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "/Start & End**/" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "AbilityActivated", nullptr, nullptr, sizeof(OmegaAbility_eventAbilityActivated_Parms), Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_AbilityActivated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_AbilityActivated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics
	{
		static void NewProp_Cancelled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Cancelled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::NewProp_Cancelled_SetBit(void* Obj)
	{
		((OmegaAbility_eventAbilityFinished_Parms*)Obj)->Cancelled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::NewProp_Cancelled = { "Cancelled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaAbility_eventAbilityFinished_Parms), &Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::NewProp_Cancelled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::NewProp_Cancelled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "AbilityFinished", nullptr, nullptr, sizeof(OmegaAbility_eventAbilityFinished_Parms), Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_AbilityFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_AbilityFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventActivatedTick_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "ActivatedTick", nullptr, nullptr, sizeof(OmegaAbility_eventActivatedTick_Parms), Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_ActivatedTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_ActivatedTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics
	{
		struct OmegaAbility_eventAddBlockedAbilityTags_Parms
		{
			FGameplayTagContainer AddedTags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_AddedTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::NewProp_AddedTags = { "AddedTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventAddBlockedAbilityTags_Parms, AddedTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::NewProp_AddedTags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability|Tags" },
		{ "Comment", "///TAGS///\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "TAGS" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "AddBlockedAbilityTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::OmegaAbility_eventAddBlockedAbilityTags_Parms), Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaAbility_eventCanActivate_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaAbility_eventCanActivate_Parms), &Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "CanActivate", nullptr, nullptr, sizeof(OmegaAbility_eventCanActivate_Parms), Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_CanActivate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_CanActivate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_CancelAbility_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_CancelAbility_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "Comment", "//Cancels and Destroys this Ability.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "Cancels and Destroys this Ability." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_CancelAbility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "CancelAbility", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_CancelAbility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_CancelAbility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_CancelAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_CancelAbility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_CompleteAbility_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_CompleteAbility_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "Comment", "//**Callable***//\n//Completes and Destroys this Ability.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "/Callable**/\nCompletes and Destroys this Ability." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_CompleteAbility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "CompleteAbility", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_CompleteAbility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_CompleteAbility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_CompleteAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_CompleteAbility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_Execute_Statics
	{
		struct OmegaAbility_eventExecute_Parms
		{
			UObject* Context;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaAbility_Execute_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventExecute_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_Execute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_Execute_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_Execute_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "DisplayName", "Activate" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_Execute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "Execute", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_Execute_Statics::OmegaAbility_eventExecute_Parms), Z_Construct_UFunction_AOmegaAbility_Execute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_Execute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_Execute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_Execute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_Execute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_Execute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics
	{
		struct OmegaAbility_eventGetAbilityOwnerCharacter_Parms
		{
			ACharacter* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventGetAbilityOwnerCharacter_Parms, ReturnValue), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability|Owner" },
		{ "Comment", "//Owner Gets//\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "Owner Gets" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "GetAbilityOwnerCharacter", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::OmegaAbility_eventGetAbilityOwnerCharacter_Parms), Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics
	{
		struct OmegaAbility_eventGetAbilityOwnerCharacterMoveComponent_Parms
		{
			UCharacterMovementComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventGetAbilityOwnerCharacterMoveComponent_Parms, ReturnValue), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability|Owner" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "GetAbilityOwnerCharacterMoveComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::OmegaAbility_eventGetAbilityOwnerCharacterMoveComponent_Parms), Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics
	{
		struct OmegaAbility_eventGetAbilityOwnerMesh_Parms
		{
			USkeletalMeshComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventGetAbilityOwnerMesh_Parms, ReturnValue), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability|Owner" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "GetAbilityOwnerMesh", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::OmegaAbility_eventGetAbilityOwnerMesh_Parms), Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_Native_Execute_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_Native_Execute_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_Native_Execute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "Native_Execute", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_Native_Execute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_Native_Execute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_Native_Execute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_Native_Execute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_Native_Trigger_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_Native_Trigger_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_Native_Trigger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "Native_Trigger", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_Native_Trigger_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_Native_Trigger_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_Native_Trigger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_Native_Trigger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics
	{
		struct OmegaAbility_eventRecieveFinish_Parms
		{
			bool bCancel;
		};
		static void NewProp_bCancel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCancel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::NewProp_bCancel_SetBit(void* Obj)
	{
		((OmegaAbility_eventRecieveFinish_Parms*)Obj)->bCancel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::NewProp_bCancel = { "bCancel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaAbility_eventRecieveFinish_Parms), &Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::NewProp_bCancel_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::NewProp_bCancel,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "RecieveFinish", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::OmegaAbility_eventRecieveFinish_Parms), Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_RecieveFinish()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_RecieveFinish_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics
	{
		struct OmegaAbility_eventRemoveBlockedAbilityTags_Parms
		{
			FGameplayTagContainer RemovedTags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RemovedTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::NewProp_RemovedTags = { "RemovedTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAbility_eventRemoveBlockedAbilityTags_Parms, RemovedTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::NewProp_RemovedTags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Ability|Tags" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "RemoveBlockedAbilityTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::OmegaAbility_eventRemoveBlockedAbilityTags_Parms), Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics
	{
		struct OmegaAbility_eventSetInputEnabledForOwner_Parms
		{
			bool Enabled;
			bool ReturnValue;
		};
		static void NewProp_Enabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enabled;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_Enabled_SetBit(void* Obj)
	{
		((OmegaAbility_eventSetInputEnabledForOwner_Parms*)Obj)->Enabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_Enabled = { "Enabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaAbility_eventSetInputEnabledForOwner_Parms), &Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_Enabled_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaAbility_eventSetInputEnabledForOwner_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaAbility_eventSetInputEnabledForOwner_Parms), &Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_Enabled,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOmegaAbility, nullptr, "SetInputEnabledForOwner", nullptr, nullptr, sizeof(Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::OmegaAbility_eventSetInputEnabledForOwner_Parms), Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOmegaAbility);
	UClass* Z_Construct_UClass_AOmegaAbility_NoRegister()
	{
		return AOmegaAbility::StaticClass();
	}
	struct Z_Construct_UClass_AOmegaAbility_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsActive_MetaData[];
#endif
		static void NewProp_bIsActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultInputReceiver_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultInputReceiver;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bActivateOnStarted_MetaData[];
#endif
		static void NewProp_bActivateOnStarted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bActivateOnStarted;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bActivateOnTriggered_MetaData[];
#endif
		static void NewProp_bActivateOnTriggered_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bActivateOnTriggered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bFinishOnInputComplete_MetaData[];
#endif
		static void NewProp_bFinishOnInputComplete_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFinishOnInputComplete;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bFinishOnInputCancel_MetaData[];
#endif
		static void NewProp_bFinishOnInputCancel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFinishOnInputCancel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsKilling_MetaData[];
#endif
		static void NewProp_bIsKilling_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsKilling;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContextObject_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombatantOwner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatantOwner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAbilityFinished_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAbilityFinished;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Singleton_MetaData[];
#endif
		static void NewProp_Singleton_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Singleton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AbilityTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AbilityTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CancelAbilities_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CancelAbilities;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BlockAbilities_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_BlockAbilities;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RequiredOwnerTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RequiredOwnerTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RestrictedOwnerTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RestrictedOwnerTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOmegaAbility_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AOmegaAbility_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AOmegaAbility_AbilityActivated, "AbilityActivated" }, // 2545007344
		{ &Z_Construct_UFunction_AOmegaAbility_AbilityFinished, "AbilityFinished" }, // 4231418627
		{ &Z_Construct_UFunction_AOmegaAbility_ActivatedTick, "ActivatedTick" }, // 815709741
		{ &Z_Construct_UFunction_AOmegaAbility_AddBlockedAbilityTags, "AddBlockedAbilityTags" }, // 1127787544
		{ &Z_Construct_UFunction_AOmegaAbility_CanActivate, "CanActivate" }, // 2405343625
		{ &Z_Construct_UFunction_AOmegaAbility_CancelAbility, "CancelAbility" }, // 510797189
		{ &Z_Construct_UFunction_AOmegaAbility_CompleteAbility, "CompleteAbility" }, // 2293416012
		{ &Z_Construct_UFunction_AOmegaAbility_Execute, "Execute" }, // 2797005624
		{ &Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacter, "GetAbilityOwnerCharacter" }, // 1196398264
		{ &Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerCharacterMoveComponent, "GetAbilityOwnerCharacterMoveComponent" }, // 2141194452
		{ &Z_Construct_UFunction_AOmegaAbility_GetAbilityOwnerMesh, "GetAbilityOwnerMesh" }, // 271748481
		{ &Z_Construct_UFunction_AOmegaAbility_Native_Execute, "Native_Execute" }, // 2076852108
		{ &Z_Construct_UFunction_AOmegaAbility_Native_Trigger, "Native_Trigger" }, // 3033811769
		{ &Z_Construct_UFunction_AOmegaAbility_RecieveFinish, "RecieveFinish" }, // 3604087834
		{ &Z_Construct_UFunction_AOmegaAbility_RemoveBlockedAbilityTags, "RemoveBlockedAbilityTags" }, // 3856157956
		{ &Z_Construct_UFunction_AOmegaAbility_SetInputEnabledForOwner, "SetInputEnabledForOwner" }, // 2680708020
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OmegaAbility.h" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsActive_MetaData[] = {
		{ "Category", "\xce\xa9|Ability" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	void Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsActive_SetBit(void* Obj)
	{
		((AOmegaAbility*)Obj)->bIsActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaAbility), &Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsActive_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_DefaultInputReceiver_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "//### Input ###//\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "### Input ###" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_DefaultInputReceiver = { "DefaultInputReceiver", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, DefaultInputReceiver), Z_Construct_UClass_UInputReceiverComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_DefaultInputReceiver_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_DefaultInputReceiver_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnStarted_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	void Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnStarted_SetBit(void* Obj)
	{
		((AOmegaAbility*)Obj)->bActivateOnStarted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnStarted = { "bActivateOnStarted", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaAbility), &Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnStarted_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnStarted_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnStarted_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnTriggered_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	void Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnTriggered_SetBit(void* Obj)
	{
		((AOmegaAbility*)Obj)->bActivateOnTriggered = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnTriggered = { "bActivateOnTriggered", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaAbility), &Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnTriggered_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnTriggered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnTriggered_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputComplete_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	void Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputComplete_SetBit(void* Obj)
	{
		((AOmegaAbility*)Obj)->bFinishOnInputComplete = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputComplete = { "bFinishOnInputComplete", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaAbility), &Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputComplete_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputComplete_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputComplete_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputCancel_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	void Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputCancel_SetBit(void* Obj)
	{
		((AOmegaAbility*)Obj)->bFinishOnInputCancel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputCancel = { "bFinishOnInputCancel", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaAbility), &Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputCancel_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputCancel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputCancel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsKilling_MetaData[] = {
		{ "Comment", "//### Properties ###//\n// \n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "### Properties ###" },
	};
#endif
	void Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsKilling_SetBit(void* Obj)
	{
		((AOmegaAbility*)Obj)->bIsKilling = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsKilling = { "bIsKilling", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaAbility), &Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsKilling_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsKilling_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsKilling_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_ContextObject_MetaData[] = {
		{ "Category", "Ability" },
		{ "Comment", "//Context Object//\n" },
		{ "DisplayName", "Ability Context" },
		{ "ExposeOnSpawn", "true" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "Context Object" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_ContextObject = { "ContextObject", nullptr, (EPropertyFlags)0x0011000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, ContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_ContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_ContextObject_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CombatantOwner_MetaData[] = {
		{ "Category", "Owner" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CombatantOwner = { "CombatantOwner", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, CombatantOwner), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CombatantOwner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CombatantOwner_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_OnAbilityFinished_MetaData[] = {
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_OnAbilityFinished = { "OnAbilityFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, OnAbilityFinished), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAbilityEnd__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_OnAbilityFinished_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_OnAbilityFinished_MetaData)) }; // 2134384024
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_Singleton_MetaData[] = {
		{ "Category", "Ability" },
		{ "Comment", "//Only one instance of this ability is allowed to run on this Owner at a time.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "Only one instance of this ability is allowed to run on this Owner at a time." },
	};
#endif
	void Z_Construct_UClass_AOmegaAbility_Statics::NewProp_Singleton_SetBit(void* Obj)
	{
		((AOmegaAbility*)Obj)->Singleton = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_Singleton = { "Singleton", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AOmegaAbility), &Z_Construct_UClass_AOmegaAbility_Statics::NewProp_Singleton_SetBit, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_Singleton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_Singleton_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_AbilityTags_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "Comment", "//GameplayTags//\n//Tags assosiated with this ability.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "GameplayTags\nTags assosiated with this ability." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_AbilityTags = { "AbilityTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, AbilityTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_AbilityTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_AbilityTags_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CancelAbilities_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "Comment", "//Cancel any of the owner's active abilities with any of these tags.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "Cancel any of the owner's active abilities with any of these tags." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CancelAbilities = { "CancelAbilities", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, CancelAbilities), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CancelAbilities_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CancelAbilities_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_BlockAbilities_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "Comment", "//Prevent any abilites with any of these tags from being activated by the owner until this ability finishes.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "Prevent any abilites with any of these tags from being activated by the owner until this ability finishes." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_BlockAbilities = { "BlockAbilities", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, BlockAbilities), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_BlockAbilities_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_BlockAbilities_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RequiredOwnerTags_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "Comment", "//The Owner Must have these gameplay tags for this ability to activate.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "The Owner Must have these gameplay tags for this ability to activate." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RequiredOwnerTags = { "RequiredOwnerTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, RequiredOwnerTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RequiredOwnerTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RequiredOwnerTags_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RestrictedOwnerTags_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "Comment", "//The Owner must NOT have ANY of these gameplay tags in order for this ability to activate.\n" },
		{ "ModuleRelativePath", "Public/OmegaAbility.h" },
		{ "ToolTip", "The Owner must NOT have ANY of these gameplay tags in order for this ability to activate." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RestrictedOwnerTags = { "RestrictedOwnerTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOmegaAbility, RestrictedOwnerTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RestrictedOwnerTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RestrictedOwnerTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOmegaAbility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_DefaultInputReceiver,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnStarted,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bActivateOnTriggered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputComplete,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bFinishOnInputCancel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_bIsKilling,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_ContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CombatantOwner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_OnAbilityFinished,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_Singleton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_AbilityTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_CancelAbilities,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_BlockAbilities,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RequiredOwnerTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOmegaAbility_Statics::NewProp_RestrictedOwnerTags,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOmegaAbility_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOmegaAbility>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOmegaAbility_Statics::ClassParams = {
		&AOmegaAbility::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AOmegaAbility_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AOmegaAbility_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaAbility_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOmegaAbility()
	{
		if (!Z_Registration_Info_UClass_AOmegaAbility.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOmegaAbility.OuterSingleton, Z_Construct_UClass_AOmegaAbility_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOmegaAbility.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<AOmegaAbility>()
	{
		return AOmegaAbility::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOmegaAbility);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_Statics::EnumInfo[] = {
		{ EAbilityActivateInput_StaticEnum, TEXT("EAbilityActivateInput"), &Z_Registration_Info_UEnum_EAbilityActivateInput, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4155278396U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOmegaAbility, AOmegaAbility::StaticClass, TEXT("AOmegaAbility"), &Z_Registration_Info_UClass_AOmegaAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOmegaAbility), 2210509182U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_2791762739(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

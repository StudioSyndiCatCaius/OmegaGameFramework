// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Data/DataAssetCollectionComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataAssetCollectionComponent() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataAssetCollectionComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataAssetCollectionComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnAssetAdded_Parms
		{
			UDataAsset* Asset;
			int32 Amount;
			bool IsFull;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
		static void NewProp_IsFull_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsFull;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAssetAdded_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAssetAdded_Parms, Amount), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_IsFull_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnAssetAdded_Parms*)Obj)->IsFull = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_IsFull = { "IsFull", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnAssetAdded_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_IsFull_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_Amount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::NewProp_IsFull,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnAssetAdded__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnAssetAdded_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnAssetRemoved_Parms
		{
			UDataAsset* Asset;
			int32 Amount;
			bool IsEmpty;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
		static void NewProp_IsEmpty_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsEmpty;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAssetRemoved_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnAssetRemoved_Parms, Amount), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_IsEmpty_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnAssetRemoved_Parms*)Obj)->IsEmpty = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_IsEmpty = { "IsEmpty", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnAssetRemoved_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_IsEmpty_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_Amount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::NewProp_IsEmpty,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnAssetRemoved__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnAssetRemoved_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execGetCollectionMap)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<UDataAsset*,int32>*)Z_Param__Result=P_THIS->GetCollectionMap();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execSetCollectionMap)
	{
		P_GET_TMAP(UDataAsset*,int32,Z_Param_Map);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCollectionMap(Z_Param_Map);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execGetCollectionAsArray)
	{
		P_GET_OBJECT(UDataAsset,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UDataAsset*>*)Z_Param__Result=P_THIS->GetCollectionAsArray(Z_Param_Asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execGetAssetNumberTotal)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetAssetNumberTotal();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execGetAssetNumberOfType)
	{
		P_GET_OBJECT(UDataAsset,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetAssetNumberOfType(Z_Param_Asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execRemoveAsset)
	{
		P_GET_OBJECT(UDataAsset,Z_Param_Asset);
		P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveAsset(Z_Param_Asset,Z_Param_Amount);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execAddAsset)
	{
		P_GET_OBJECT(UDataAsset,Z_Param_Asset);
		P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddAsset(Z_Param_Asset,Z_Param_Amount);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execNativeRemoveAsset)
	{
		P_GET_OBJECT(UDataAsset,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->NativeRemoveAsset(Z_Param_Asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataAssetCollectionComponent::execNativeAddAsset)
	{
		P_GET_OBJECT(UDataAsset,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->NativeAddAsset(Z_Param_Asset);
		P_NATIVE_END;
	}
	void UDataAssetCollectionComponent::StaticRegisterNativesUDataAssetCollectionComponent()
	{
		UClass* Class = UDataAssetCollectionComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAsset", &UDataAssetCollectionComponent::execAddAsset },
			{ "GetAssetNumberOfType", &UDataAssetCollectionComponent::execGetAssetNumberOfType },
			{ "GetAssetNumberTotal", &UDataAssetCollectionComponent::execGetAssetNumberTotal },
			{ "GetCollectionAsArray", &UDataAssetCollectionComponent::execGetCollectionAsArray },
			{ "GetCollectionMap", &UDataAssetCollectionComponent::execGetCollectionMap },
			{ "NativeAddAsset", &UDataAssetCollectionComponent::execNativeAddAsset },
			{ "NativeRemoveAsset", &UDataAssetCollectionComponent::execNativeRemoveAsset },
			{ "RemoveAsset", &UDataAssetCollectionComponent::execRemoveAsset },
			{ "SetCollectionMap", &UDataAssetCollectionComponent::execSetCollectionMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics
	{
		struct DataAssetCollectionComponent_eventAddAsset_Parms
		{
			UDataAsset* Asset;
			int32 Amount;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventAddAsset_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventAddAsset_Parms, Amount), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::NewProp_Amount,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Data" },
		{ "CPP_Default_Amount", "1" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "AddAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::DataAssetCollectionComponent_eventAddAsset_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics
	{
		struct DataAssetCollectionComponent_eventGetAssetNumberOfType_Parms
		{
			UDataAsset* Asset;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventGetAssetNumberOfType_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventGetAssetNumberOfType_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Data" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "GetAssetNumberOfType", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::DataAssetCollectionComponent_eventGetAssetNumberOfType_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics
	{
		struct DataAssetCollectionComponent_eventGetAssetNumberTotal_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventGetAssetNumberTotal_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Data" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "GetAssetNumberTotal", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::DataAssetCollectionComponent_eventGetAssetNumberTotal_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics
	{
		struct DataAssetCollectionComponent_eventGetCollectionAsArray_Parms
		{
			UDataAsset* Asset;
			TArray<UDataAsset*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventGetCollectionAsArray_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventGetCollectionAsArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Data" },
		{ "DeterminesOutputType", "Asset" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "GetCollectionAsArray", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::DataAssetCollectionComponent_eventGetCollectionAsArray_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics
	{
		struct DataAssetCollectionComponent_eventGetCollectionMap_Parms
		{
			TMap<UDataAsset*,int32> ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventGetCollectionMap_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Data" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "GetCollectionMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::DataAssetCollectionComponent_eventGetCollectionMap_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics
	{
		struct DataAssetCollectionComponent_eventNativeAddAsset_Parms
		{
			UDataAsset* Asset;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventNativeAddAsset_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DataAssetCollectionComponent_eventNativeAddAsset_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataAssetCollectionComponent_eventNativeAddAsset_Parms), &Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "NativeAddAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::DataAssetCollectionComponent_eventNativeAddAsset_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics
	{
		struct DataAssetCollectionComponent_eventNativeRemoveAsset_Parms
		{
			UDataAsset* Asset;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventNativeRemoveAsset_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DataAssetCollectionComponent_eventNativeRemoveAsset_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataAssetCollectionComponent_eventNativeRemoveAsset_Parms), &Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "NativeRemoveAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::DataAssetCollectionComponent_eventNativeRemoveAsset_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics
	{
		struct DataAssetCollectionComponent_eventRemoveAsset_Parms
		{
			UDataAsset* Asset;
			int32 Amount;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventRemoveAsset_Parms, Asset), Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventRemoveAsset_Parms, Amount), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::NewProp_Amount,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Data" },
		{ "CPP_Default_Amount", "1" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "RemoveAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::DataAssetCollectionComponent_eventRemoveAsset_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics
	{
		struct DataAssetCollectionComponent_eventSetCollectionMap_Parms
		{
			TMap<UDataAsset*,int32> Map;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Map_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Map_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_Map;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::NewProp_Map_ValueProp = { "Map", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::NewProp_Map_Key_KeyProp = { "Map_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::NewProp_Map = { "Map", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataAssetCollectionComponent_eventSetCollectionMap_Parms, Map), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::NewProp_Map_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::NewProp_Map_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::NewProp_Map,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Data" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataAssetCollectionComponent, nullptr, "SetCollectionMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::DataAssetCollectionComponent_eventSetCollectionMap_Parms), Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataAssetCollectionComponent);
	UClass* Z_Construct_UClass_UDataAssetCollectionComponent_NoRegister()
	{
		return UDataAssetCollectionComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDataAssetCollectionComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CollectionMap_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CollectionMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollectionMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_CollectionMap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAssetAdded_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAssetAdded;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAssetRemoved_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAssetRemoved;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataAssetCollectionComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataAssetCollectionComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_AddAsset, "AddAsset" }, // 3221784058
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberOfType, "GetAssetNumberOfType" }, // 374112819
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_GetAssetNumberTotal, "GetAssetNumberTotal" }, // 3283326381
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionAsArray, "GetCollectionAsArray" }, // 2767340151
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_GetCollectionMap, "GetCollectionMap" }, // 3421989957
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_NativeAddAsset, "NativeAddAsset" }, // 1177440437
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_NativeRemoveAsset, "NativeRemoveAsset" }, // 1983364627
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_RemoveAsset, "RemoveAsset" }, // 866366291
		{ &Z_Construct_UFunction_UDataAssetCollectionComponent_SetCollectionMap, "SetCollectionMap" }, // 628766043
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataAssetCollectionComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Data/DataAssetCollectionComponent.h" },
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap_ValueProp = { "CollectionMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap_Key_KeyProp = { "CollectionMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap = { "CollectionMap", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataAssetCollectionComponent, CollectionMap), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetAdded_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetAdded = { "OnAssetAdded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataAssetCollectionComponent, OnAssetAdded), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetAdded__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetAdded_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetAdded_MetaData)) }; // 3241307833
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetRemoved_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/DataAssetCollectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetRemoved = { "OnAssetRemoved", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataAssetCollectionComponent, OnAssetRemoved), Z_Construct_UDelegateFunction_OmegaGameFramework_OnAssetRemoved__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetRemoved_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetRemoved_MetaData)) }; // 232753250
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDataAssetCollectionComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_CollectionMap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetAdded,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataAssetCollectionComponent_Statics::NewProp_OnAssetRemoved,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataAssetCollectionComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDataAssetCollectionComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataAssetCollectionComponent_Statics::ClassParams = {
		&UDataAssetCollectionComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDataAssetCollectionComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataAssetCollectionComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataAssetCollectionComponent()
	{
		if (!Z_Registration_Info_UClass_UDataAssetCollectionComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataAssetCollectionComponent.OuterSingleton, Z_Construct_UClass_UDataAssetCollectionComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataAssetCollectionComponent.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataAssetCollectionComponent>()
	{
		return UDataAssetCollectionComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataAssetCollectionComponent);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataAssetCollectionComponent, UDataAssetCollectionComponent::StaticClass, TEXT("UDataAssetCollectionComponent"), &Z_Registration_Info_UClass_UDataAssetCollectionComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataAssetCollectionComponent), 1121874025U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_2706295531(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/Equipment/EquipmentComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEquipmentComponent() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEquipmentComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEquipmentComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnItemEquipped_Parms
		{
			UPrimaryDataAsset* Item;
			FString Slot;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnItemEquipped_Parms, Item), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnItemEquipped_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::NewProp_Item,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnItemEquipped__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnItemEquipped_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnItemUnequipped_Parms
		{
			UPrimaryDataAsset* Item;
			FString Slot;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnItemUnequipped_Parms, Item), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnItemUnequipped_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::NewProp_Item,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnItemUnequipped__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnItemUnequipped_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UEquipmentComponent::execGetEquipmentInSlot)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Slot);
		P_GET_UBOOL_REF(Z_Param_Out_bValidItem);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPrimaryDataAsset**)Z_Param__Result=P_THIS->GetEquipmentInSlot(Z_Param_Slot,Z_Param_Out_bValidItem);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEquipmentComponent::execUnequipSlot)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->UnequipSlot(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEquipmentComponent::execEquipItem)
	{
		P_GET_OBJECT(UPrimaryDataAsset,Z_Param_Item);
		P_GET_PROPERTY(FStrProperty,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->EquipItem(Z_Param_Item,Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEquipmentComponent::execSetEquipment)
	{
		P_GET_TMAP(FString,UPrimaryDataAsset*,Z_Param_Equipment);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEquipment(Z_Param_Equipment);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEquipmentComponent::execGetEquipment)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FString,UPrimaryDataAsset*>*)Z_Param__Result=P_THIS->GetEquipment();
		P_NATIVE_END;
	}
	void UEquipmentComponent::StaticRegisterNativesUEquipmentComponent()
	{
		UClass* Class = UEquipmentComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EquipItem", &UEquipmentComponent::execEquipItem },
			{ "GetEquipment", &UEquipmentComponent::execGetEquipment },
			{ "GetEquipmentInSlot", &UEquipmentComponent::execGetEquipmentInSlot },
			{ "SetEquipment", &UEquipmentComponent::execSetEquipment },
			{ "UnequipSlot", &UEquipmentComponent::execUnequipSlot },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics
	{
		struct EquipmentComponent_eventEquipItem_Parms
		{
			UPrimaryDataAsset* Item;
			FString Slot;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Slot;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EquipmentComponent_eventEquipItem_Parms, Item), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EquipmentComponent_eventEquipItem_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EquipmentComponent_eventEquipItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EquipmentComponent_eventEquipItem_Parms), &Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_Item,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEquipmentComponent, nullptr, "EquipItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::EquipmentComponent_eventEquipItem_Parms), Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEquipmentComponent_EquipItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentComponent_EquipItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics
	{
		struct EquipmentComponent_eventGetEquipment_Parms
		{
			TMap<FString,UPrimaryDataAsset*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EquipmentComponent_eventGetEquipment_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
		{ "CompactNodeTitle", "Equipment" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEquipmentComponent, nullptr, "GetEquipment", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::EquipmentComponent_eventGetEquipment_Parms), Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEquipmentComponent_GetEquipment()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentComponent_GetEquipment_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics
	{
		struct EquipmentComponent_eventGetEquipmentInSlot_Parms
		{
			FString Slot;
			bool bValidItem;
			UPrimaryDataAsset* ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Slot;
		static void NewProp_bValidItem_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bValidItem;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EquipmentComponent_eventGetEquipmentInSlot_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_bValidItem_SetBit(void* Obj)
	{
		((EquipmentComponent_eventGetEquipmentInSlot_Parms*)Obj)->bValidItem = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_bValidItem = { "bValidItem", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EquipmentComponent_eventGetEquipmentInSlot_Parms), &Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_bValidItem_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EquipmentComponent_eventGetEquipmentInSlot_Parms, ReturnValue), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_bValidItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEquipmentComponent, nullptr, "GetEquipmentInSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::EquipmentComponent_eventGetEquipmentInSlot_Parms), Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics
	{
		struct EquipmentComponent_eventSetEquipment_Parms
		{
			TMap<FString,UPrimaryDataAsset*> Equipment;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Equipment_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Equipment_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_Equipment;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::NewProp_Equipment_ValueProp = { "Equipment", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::NewProp_Equipment_Key_KeyProp = { "Equipment_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::NewProp_Equipment = { "Equipment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EquipmentComponent_eventSetEquipment_Parms, Equipment), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::NewProp_Equipment_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::NewProp_Equipment_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::NewProp_Equipment,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEquipmentComponent, nullptr, "SetEquipment", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::EquipmentComponent_eventSetEquipment_Parms), Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEquipmentComponent_SetEquipment()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentComponent_SetEquipment_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics
	{
		struct EquipmentComponent_eventUnequipSlot_Parms
		{
			FString Slot;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Slot;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EquipmentComponent_eventUnequipSlot_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((EquipmentComponent_eventUnequipSlot_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EquipmentComponent_eventUnequipSlot_Parms), &Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEquipmentComponent, nullptr, "UnequipSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::EquipmentComponent_eventUnequipSlot_Parms), Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEquipmentComponent_UnequipSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentComponent_UnequipSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEquipmentComponent);
	UClass* Z_Construct_UClass_UEquipmentComponent_NoRegister()
	{
		return UEquipmentComponent::StaticClass();
	}
	struct Z_Construct_UClass_UEquipmentComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EquippedItems_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_EquippedItems_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EquippedItems_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_EquippedItems;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AcceptedItemTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AcceptedItemTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RejectedItemTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RejectedItemTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnItemEquipped_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemEquipped;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnItemUnequipped_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemUnequipped;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEquipmentComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UEquipmentComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEquipmentComponent_EquipItem, "EquipItem" }, // 2614235052
		{ &Z_Construct_UFunction_UEquipmentComponent_GetEquipment, "GetEquipment" }, // 1674207378
		{ &Z_Construct_UFunction_UEquipmentComponent_GetEquipmentInSlot, "GetEquipmentInSlot" }, // 1541468839
		{ &Z_Construct_UFunction_UEquipmentComponent_SetEquipment, "SetEquipment" }, // 1462836364
		{ &Z_Construct_UFunction_UEquipmentComponent_UnequipSlot, "UnequipSlot" }, // 283686111
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Gameplay/Equipment/EquipmentComponent.h" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems_ValueProp = { "EquippedItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems_Key_KeyProp = { "EquippedItems_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems = { "EquippedItems", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentComponent, EquippedItems), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_AcceptedItemTags_MetaData[] = {
		{ "Category", "Equipment" },
		{ "Comment", "//Determines what assets can be accepted. Blank will accept all.\n" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
		{ "ToolTip", "Determines what assets can be accepted. Blank will accept all." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_AcceptedItemTags = { "AcceptedItemTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentComponent, AcceptedItemTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_AcceptedItemTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_AcceptedItemTags_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_RejectedItemTags_MetaData[] = {
		{ "Category", "Equipment" },
		{ "Comment", "//Determines what assets can be accepted. Blank will reject none.\n" },
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
		{ "ToolTip", "Determines what assets can be accepted. Blank will reject none." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_RejectedItemTags = { "RejectedItemTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentComponent, RejectedItemTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_RejectedItemTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_RejectedItemTags_MetaData)) }; // 506667518
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemEquipped_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemEquipped = { "OnItemEquipped", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentComponent, OnItemEquipped), Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemEquipped__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemEquipped_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemEquipped_MetaData)) }; // 2143692233
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemUnequipped_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/Equipment/EquipmentComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemUnequipped = { "OnItemUnequipped", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEquipmentComponent, OnItemUnequipped), Z_Construct_UDelegateFunction_OmegaGameFramework_OnItemUnequipped__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemUnequipped_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemUnequipped_MetaData)) }; // 245409923
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEquipmentComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_EquippedItems,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_AcceptedItemTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_RejectedItemTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemEquipped,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentComponent_Statics::NewProp_OnItemUnequipped,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEquipmentComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEquipmentComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEquipmentComponent_Statics::ClassParams = {
		&UEquipmentComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEquipmentComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UEquipmentComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEquipmentComponent()
	{
		if (!Z_Registration_Info_UClass_UEquipmentComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEquipmentComponent.OuterSingleton, Z_Construct_UClass_UEquipmentComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEquipmentComponent.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UEquipmentComponent>()
	{
		return UEquipmentComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEquipmentComponent);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEquipmentComponent, UEquipmentComponent::StaticClass, TEXT("UEquipmentComponent"), &Z_Registration_Info_UClass_UEquipmentComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEquipmentComponent), 3501086596U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_427369899(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

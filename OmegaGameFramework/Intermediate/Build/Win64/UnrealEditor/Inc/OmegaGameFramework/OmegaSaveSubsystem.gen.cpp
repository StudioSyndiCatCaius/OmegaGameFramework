// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Save/OmegaSaveSubsystem.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaSaveSubsystem() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveSubsystem_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGame_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveBase_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagQuery();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGlobal_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELevelOpenType;
	static UEnum* ELevelOpenType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ELevelOpenType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ELevelOpenType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("ELevelOpenType"));
		}
		return Z_Registration_Info_UEnum_ELevelOpenType.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<ELevelOpenType>()
	{
		return ELevelOpenType_StaticEnum();
	}
	struct Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::Enumerators[] = {
		{ "ELevelOpenType::LvlOp_None", (int64)ELevelOpenType::LvlOp_None },
		{ "ELevelOpenType::LvlOp_Save", (int64)ELevelOpenType::LvlOp_Save },
		{ "ELevelOpenType::LvlOp_Custom", (int64)ELevelOpenType::LvlOp_Custom },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::Enum_MetaDataParams[] = {
		{ "LvlOp_Custom.DisplayName", "Custom" },
		{ "LvlOp_Custom.Name", "ELevelOpenType::LvlOp_Custom" },
		{ "LvlOp_None.DisplayName", "N/A" },
		{ "LvlOp_None.Name", "ELevelOpenType::LvlOp_None" },
		{ "LvlOp_Save.DisplayName", "Saved" },
		{ "LvlOp_Save.Name", "ELevelOpenType::LvlOp_Save" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		"ELevelOpenType",
		"ELevelOpenType",
		Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType()
	{
		if (!Z_Registration_Info_UEnum_ELevelOpenType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELevelOpenType.InnerSingleton, Z_Construct_UEnum_OmegaGameFramework_ELevelOpenType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ELevelOpenType.InnerSingleton;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execIsDataAssetInSaveCollection)
	{
		P_GET_OBJECT(UPrimaryDataAsset,Z_Param_Asset);
		P_GET_UBOOL(Z_Param_bGlobal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsDataAssetInSaveCollection(Z_Param_Asset,Z_Param_bGlobal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execRemoveDataAssetFromSaveCollection)
	{
		P_GET_OBJECT(UPrimaryDataAsset,Z_Param_Asset);
		P_GET_UBOOL(Z_Param_bGlobal);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveDataAssetFromSaveCollection(Z_Param_Asset,Z_Param_bGlobal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execAddDataAssetToSaveCollection)
	{
		P_GET_OBJECT(UPrimaryDataAsset,Z_Param_Asset);
		P_GET_UBOOL(Z_Param_bGlobal);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddDataAssetToSaveCollection(Z_Param_Asset,Z_Param_bGlobal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execRemoveSavedActorTags)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveSavedActorTags(Z_Param_Actor,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execAddSavedActorTags)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddSavedActorTags(Z_Param_Actor,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execSetSavedActorState)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_GET_STRUCT(FGameplayTag,Z_Param_StateTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSavedActorState(Z_Param_Actor,Z_Param_StateTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execSaveTagsMatchQuery)
	{
		P_GET_STRUCT(FGameplayTagQuery,Z_Param_Query);
		P_GET_UBOOL(Z_Param_Global);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SaveTagsMatchQuery(Z_Param_Query,Z_Param_Global);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execGetStoryTags)
	{
		P_GET_UBOOL(Z_Param_Global);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetStoryTags(Z_Param_Global);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execRemoveStoryTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_UBOOL(Z_Param_Global);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveStoryTags(Z_Param_Tags,Z_Param_Global);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execAddStoryTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_UBOOL(Z_Param_Global);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddStoryTags(Z_Param_Tags,Z_Param_Global);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execSetStoryState)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_StateTag);
		P_GET_UBOOL(Z_Param_Global);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetStoryState(Z_Param_StateTag,Z_Param_Global);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execGetSaveObject)
	{
		P_GET_UBOOL(Z_Param_Global);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UOmegaSaveBase**)Z_Param__Result=P_THIS->GetSaveObject(Z_Param_Global);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execStartGame)
	{
		P_GET_OBJECT(UOmegaSaveGame,Z_Param_GameData);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartGame(Z_Param_GameData,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execCreateNewGame)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UOmegaSaveGame**)Z_Param__Result=P_THIS->CreateNewGame();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execSaveActiveGame)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Slot);
		P_GET_UBOOL_REF(Z_Param_Out_Success);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveActiveGame(Z_Param_Slot,Z_Param_Out_Success);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execLoadGame)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Slot);
		P_GET_UBOOL_REF(Z_Param_Out_Success);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UOmegaSaveGame**)Z_Param__Result=P_THIS->LoadGame(Z_Param_Slot,Z_Param_Out_Success);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execGetSaveSlotList)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_FirstIndex);
		P_GET_PROPERTY(FIntProperty,Z_Param_LastIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UOmegaSaveGame*>*)Z_Param__Result=P_THIS->GetSaveSlotList(Z_Param_FirstIndex,Z_Param_LastIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaSaveSubsystem::execGetSaveSlotName)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Slot);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetSaveSlotName(Z_Param_Slot,Z_Param_Out_OutName);
		P_NATIVE_END;
	}
	void UOmegaSaveSubsystem::StaticRegisterNativesUOmegaSaveSubsystem()
	{
		UClass* Class = UOmegaSaveSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddDataAssetToSaveCollection", &UOmegaSaveSubsystem::execAddDataAssetToSaveCollection },
			{ "AddSavedActorTags", &UOmegaSaveSubsystem::execAddSavedActorTags },
			{ "AddStoryTags", &UOmegaSaveSubsystem::execAddStoryTags },
			{ "CreateNewGame", &UOmegaSaveSubsystem::execCreateNewGame },
			{ "GetSaveObject", &UOmegaSaveSubsystem::execGetSaveObject },
			{ "GetSaveSlotList", &UOmegaSaveSubsystem::execGetSaveSlotList },
			{ "GetSaveSlotName", &UOmegaSaveSubsystem::execGetSaveSlotName },
			{ "GetStoryTags", &UOmegaSaveSubsystem::execGetStoryTags },
			{ "IsDataAssetInSaveCollection", &UOmegaSaveSubsystem::execIsDataAssetInSaveCollection },
			{ "LoadGame", &UOmegaSaveSubsystem::execLoadGame },
			{ "RemoveDataAssetFromSaveCollection", &UOmegaSaveSubsystem::execRemoveDataAssetFromSaveCollection },
			{ "RemoveSavedActorTags", &UOmegaSaveSubsystem::execRemoveSavedActorTags },
			{ "RemoveStoryTags", &UOmegaSaveSubsystem::execRemoveStoryTags },
			{ "SaveActiveGame", &UOmegaSaveSubsystem::execSaveActiveGame },
			{ "SaveTagsMatchQuery", &UOmegaSaveSubsystem::execSaveTagsMatchQuery },
			{ "SetSavedActorState", &UOmegaSaveSubsystem::execSetSavedActorState },
			{ "SetStoryState", &UOmegaSaveSubsystem::execSetStoryState },
			{ "StartGame", &UOmegaSaveSubsystem::execStartGame },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics
	{
		struct OmegaSaveSubsystem_eventAddDataAssetToSaveCollection_Parms
		{
			UPrimaryDataAsset* Asset;
			bool bGlobal;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_bGlobal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGlobal;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventAddDataAssetToSaveCollection_Parms, Asset), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::NewProp_bGlobal_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventAddDataAssetToSaveCollection_Parms*)Obj)->bGlobal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::NewProp_bGlobal = { "bGlobal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventAddDataAssetToSaveCollection_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::NewProp_bGlobal_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::NewProp_bGlobal,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "Comment", "//DataAssets\n" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
		{ "ToolTip", "DataAssets" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "AddDataAssetToSaveCollection", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::OmegaSaveSubsystem_eventAddDataAssetToSaveCollection_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics
	{
		struct OmegaSaveSubsystem_eventAddSavedActorTags_Parms
		{
			AActor* Actor;
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventAddSavedActorTags_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventAddSavedActorTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "AddSavedActorTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::OmegaSaveSubsystem_eventAddSavedActorTags_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics
	{
		struct OmegaSaveSubsystem_eventAddStoryTags_Parms
		{
			FGameplayTagContainer Tags;
			bool Global;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_Global_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Global;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventAddStoryTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::NewProp_Global_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventAddStoryTags_Parms*)Obj)->Global = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::NewProp_Global = { "Global", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventAddStoryTags_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::NewProp_Global_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::NewProp_Global,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "DisplayName", "Add Save Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "AddStoryTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::OmegaSaveSubsystem_eventAddStoryTags_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics
	{
		struct OmegaSaveSubsystem_eventCreateNewGame_Parms
		{
			UOmegaSaveGame* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventCreateNewGame_Parms, ReturnValue), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "CreateNewGame", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::OmegaSaveSubsystem_eventCreateNewGame_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics
	{
		struct OmegaSaveSubsystem_eventGetSaveObject_Parms
		{
			bool Global;
			UOmegaSaveBase* ReturnValue;
		};
		static void NewProp_Global_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Global;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::NewProp_Global_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventGetSaveObject_Parms*)Obj)->Global = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::NewProp_Global = { "Global", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventGetSaveObject_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::NewProp_Global_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventGetSaveObject_Parms, ReturnValue), Z_Construct_UClass_UOmegaSaveBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::NewProp_Global,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "GetSaveObject", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::OmegaSaveSubsystem_eventGetSaveObject_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics
	{
		struct OmegaSaveSubsystem_eventGetSaveSlotList_Parms
		{
			int32 FirstIndex;
			int32 LastIndex;
			TArray<UOmegaSaveGame*> ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_FirstIndex;
		static const UECodeGen_Private::FIntPropertyParams NewProp_LastIndex;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_FirstIndex = { "FirstIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventGetSaveSlotList_Parms, FirstIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_LastIndex = { "LastIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventGetSaveSlotList_Parms, LastIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventGetSaveSlotList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_FirstIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_LastIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad" },
		{ "CPP_Default_LastIndex", "1" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "GetSaveSlotList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::OmegaSaveSubsystem_eventGetSaveSlotList_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics
	{
		struct OmegaSaveSubsystem_eventGetSaveSlotName_Parms
		{
			int32 Slot;
			FString OutName;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Slot;
		static const UECodeGen_Private::FStrPropertyParams NewProp_OutName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventGetSaveSlotName_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::NewProp_OutName = { "OutName", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventGetSaveSlotName_Parms, OutName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::NewProp_OutName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "GetSaveSlotName", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::OmegaSaveSubsystem_eventGetSaveSlotName_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics
	{
		struct OmegaSaveSubsystem_eventGetStoryTags_Parms
		{
			bool Global;
			FGameplayTagContainer ReturnValue;
		};
		static void NewProp_Global_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Global;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::NewProp_Global_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventGetStoryTags_Parms*)Obj)->Global = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::NewProp_Global = { "Global", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventGetStoryTags_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::NewProp_Global_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventGetStoryTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::NewProp_Global,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "DisplayName", "Get Active Save Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "GetStoryTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::OmegaSaveSubsystem_eventGetStoryTags_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics
	{
		struct OmegaSaveSubsystem_eventIsDataAssetInSaveCollection_Parms
		{
			UPrimaryDataAsset* Asset;
			bool bGlobal;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_bGlobal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGlobal;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventIsDataAssetInSaveCollection_Parms, Asset), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_bGlobal_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventIsDataAssetInSaveCollection_Parms*)Obj)->bGlobal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_bGlobal = { "bGlobal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventIsDataAssetInSaveCollection_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_bGlobal_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventIsDataAssetInSaveCollection_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventIsDataAssetInSaveCollection_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_bGlobal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "IsDataAssetInSaveCollection", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::OmegaSaveSubsystem_eventIsDataAssetInSaveCollection_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics
	{
		struct OmegaSaveSubsystem_eventLoadGame_Parms
		{
			int32 Slot;
			bool Success;
			UOmegaSaveGame* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Slot;
		static void NewProp_Success_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventLoadGame_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventLoadGame_Parms*)Obj)->Success = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventLoadGame_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_Success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventLoadGame_Parms, ReturnValue), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_Success,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "LoadGame", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::OmegaSaveSubsystem_eventLoadGame_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics
	{
		struct OmegaSaveSubsystem_eventRemoveDataAssetFromSaveCollection_Parms
		{
			UPrimaryDataAsset* Asset;
			bool bGlobal;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_bGlobal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGlobal;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventRemoveDataAssetFromSaveCollection_Parms, Asset), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::NewProp_bGlobal_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventRemoveDataAssetFromSaveCollection_Parms*)Obj)->bGlobal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::NewProp_bGlobal = { "bGlobal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventRemoveDataAssetFromSaveCollection_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::NewProp_bGlobal_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::NewProp_bGlobal,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "RemoveDataAssetFromSaveCollection", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::OmegaSaveSubsystem_eventRemoveDataAssetFromSaveCollection_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics
	{
		struct OmegaSaveSubsystem_eventRemoveSavedActorTags_Parms
		{
			AActor* Actor;
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventRemoveSavedActorTags_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventRemoveSavedActorTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "RemoveSavedActorTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::OmegaSaveSubsystem_eventRemoveSavedActorTags_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics
	{
		struct OmegaSaveSubsystem_eventRemoveStoryTags_Parms
		{
			FGameplayTagContainer Tags;
			bool Global;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_Global_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Global;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventRemoveStoryTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::NewProp_Global_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventRemoveStoryTags_Parms*)Obj)->Global = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::NewProp_Global = { "Global", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventRemoveStoryTags_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::NewProp_Global_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::NewProp_Global,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "DisplayName", "Remove Save Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "RemoveStoryTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::OmegaSaveSubsystem_eventRemoveStoryTags_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics
	{
		struct OmegaSaveSubsystem_eventSaveActiveGame_Parms
		{
			int32 Slot;
			bool Success;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Slot;
		static void NewProp_Success_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventSaveActiveGame_Parms, Slot), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventSaveActiveGame_Parms*)Obj)->Success = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventSaveActiveGame_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::NewProp_Success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::NewProp_Success,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "SaveActiveGame", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::OmegaSaveSubsystem_eventSaveActiveGame_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics
	{
		struct OmegaSaveSubsystem_eventSaveTagsMatchQuery_Parms
		{
			FGameplayTagQuery Query;
			bool Global;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Query;
		static void NewProp_Global_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Global;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_Query = { "Query", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventSaveTagsMatchQuery_Parms, Query), Z_Construct_UScriptStruct_FGameplayTagQuery, METADATA_PARAMS(nullptr, 0) }; // 2452190958
	void Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_Global_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventSaveTagsMatchQuery_Parms*)Obj)->Global = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_Global = { "Global", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventSaveTagsMatchQuery_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_Global_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventSaveTagsMatchQuery_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventSaveTagsMatchQuery_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_Query,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_Global,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "SaveTagsMatchQuery", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::OmegaSaveSubsystem_eventSaveTagsMatchQuery_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics
	{
		struct OmegaSaveSubsystem_eventSetSavedActorState_Parms
		{
			AActor* Actor;
			FGameplayTag StateTag;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_StateTag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventSetSavedActorState_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::NewProp_StateTag = { "StateTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventSetSavedActorState_Parms, StateTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::NewProp_StateTag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "SetSavedActorState", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::OmegaSaveSubsystem_eventSetSavedActorState_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics
	{
		struct OmegaSaveSubsystem_eventSetStoryState_Parms
		{
			FGameplayTag StateTag;
			bool Global;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_StateTag;
		static void NewProp_Global_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Global;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::NewProp_StateTag = { "StateTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventSetStoryState_Parms, StateTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	void Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::NewProp_Global_SetBit(void* Obj)
	{
		((OmegaSaveSubsystem_eventSetStoryState_Parms*)Obj)->Global = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::NewProp_Global = { "Global", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaSaveSubsystem_eventSetStoryState_Parms), &Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::NewProp_Global_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::NewProp_StateTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::NewProp_Global,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|SaveLoad|Tags" },
		{ "Comment", "//GameplayTags\n" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
		{ "ToolTip", "GameplayTags" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "SetStoryState", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::OmegaSaveSubsystem_eventSetStoryState_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics
	{
		struct OmegaSaveSubsystem_eventStartGame_Parms
		{
			UOmegaSaveGame* GameData;
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GameData;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::NewProp_GameData = { "GameData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventStartGame_Parms, GameData), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveSubsystem_eventStartGame_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::NewProp_GameData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Tags" },
		{ "Category", "\xce\xa9|SaveLoad" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveSubsystem, nullptr, "StartGame", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::OmegaSaveSubsystem_eventStartGame_Parms), Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaSaveSubsystem);
	UClass* Z_Construct_UClass_UOmegaSaveSubsystem_NoRegister()
	{
		return UOmegaSaveSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaSaveSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveSaveData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveSaveData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobalSaveData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GlobalSaveData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaSaveSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaSaveSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_AddDataAssetToSaveCollection, "AddDataAssetToSaveCollection" }, // 4138874853
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_AddSavedActorTags, "AddSavedActorTags" }, // 1799534760
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_AddStoryTags, "AddStoryTags" }, // 2916070800
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_CreateNewGame, "CreateNewGame" }, // 890407134
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveObject, "GetSaveObject" }, // 4287821553
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotList, "GetSaveSlotList" }, // 1201603618
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_GetSaveSlotName, "GetSaveSlotName" }, // 1054279157
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_GetStoryTags, "GetStoryTags" }, // 1654079656
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_IsDataAssetInSaveCollection, "IsDataAssetInSaveCollection" }, // 4161452446
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_LoadGame, "LoadGame" }, // 2574351601
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveDataAssetFromSaveCollection, "RemoveDataAssetFromSaveCollection" }, // 2945668834
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveSavedActorTags, "RemoveSavedActorTags" }, // 436385504
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_RemoveStoryTags, "RemoveStoryTags" }, // 2643794514
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_SaveActiveGame, "SaveActiveGame" }, // 271735889
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_SaveTagsMatchQuery, "SaveTagsMatchQuery" }, // 3582083252
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_SetSavedActorState, "SetSavedActorState" }, // 3678372957
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_SetStoryState, "SetStoryState" }, // 1579966748
		{ &Z_Construct_UFunction_UOmegaSaveSubsystem_StartGame, "StartGame" }, // 2971530465
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveSubsystem_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "OmegaSaveSubsystem" },
		{ "IncludePath", "Save/OmegaSaveSubsystem.h" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_ActiveSaveData_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_ActiveSaveData = { "ActiveSaveData", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveSubsystem, ActiveSaveData), Z_Construct_UClass_UOmegaSaveGame_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_ActiveSaveData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_ActiveSaveData_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_GlobalSaveData_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_GlobalSaveData = { "GlobalSaveData", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveSubsystem, GlobalSaveData), Z_Construct_UClass_UOmegaSaveGlobal_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_GlobalSaveData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_GlobalSaveData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaSaveSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_ActiveSaveData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveSubsystem_Statics::NewProp_GlobalSaveData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaSaveSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaSaveSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaSaveSubsystem_Statics::ClassParams = {
		&UOmegaSaveSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaSaveSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveSubsystem_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaSaveSubsystem()
	{
		if (!Z_Registration_Info_UClass_UOmegaSaveSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaSaveSubsystem.OuterSingleton, Z_Construct_UClass_UOmegaSaveSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaSaveSubsystem.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaSaveSubsystem>()
	{
		return UOmegaSaveSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaSaveSubsystem);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_Statics::EnumInfo[] = {
		{ ELevelOpenType_StaticEnum, TEXT("ELevelOpenType"), &Z_Registration_Info_UEnum_ELevelOpenType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2951514125U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaSaveSubsystem, UOmegaSaveSubsystem::StaticClass, TEXT("UOmegaSaveSubsystem"), &Z_Registration_Info_UClass_UOmegaSaveSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaSaveSubsystem), 3855080721U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_3909722578(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

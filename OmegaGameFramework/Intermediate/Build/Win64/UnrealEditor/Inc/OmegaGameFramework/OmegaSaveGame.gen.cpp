// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Save/OmegaSaveGame.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaSaveGame() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGame_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGame();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveBase();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTimecode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static FName NAME_UOmegaSaveGame_GetDisplayName = FName(TEXT("GetDisplayName"));
	FText UOmegaSaveGame::GetDisplayName()
	{
		OmegaSaveGame_eventGetDisplayName_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaSaveGame_GetDisplayName),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UOmegaSaveGame_OnGameStarted = FName(TEXT("OnGameStarted"));
	void UOmegaSaveGame::OnGameStarted(FGameplayTagContainer Tags)
	{
		OmegaSaveGame_eventOnGameStarted_Parms Parms;
		Parms.Tags=Tags;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaSaveGame_OnGameStarted),&Parms);
	}
	void UOmegaSaveGame::StaticRegisterNativesUOmegaSaveGame()
	{
	}
	struct Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics
	{
		static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveGame_eventGetDisplayName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveGame, nullptr, "GetDisplayName", nullptr, nullptr, sizeof(OmegaSaveGame_eventGetDisplayName_Parms), Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaSaveGame_eventOnGameStarted_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaSaveGame, nullptr, "OnGameStarted", nullptr, nullptr, sizeof(OmegaSaveGame_eventOnGameStarted_Parms), Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaSaveGame);
	UClass* Z_Construct_UClass_UOmegaSaveGame_NoRegister()
	{
		return UOmegaSaveGame::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaSaveGame_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedPlaytime_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedPlaytime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveLevelName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ActiveLevelName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedPlayerTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedPlayerTransform;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ActorStates_ValueProp;
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ActorStates_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActorStates_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_ActorStates;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ActorTags_ValueProp;
		static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ActorTags_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActorTags_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_ActorTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaSaveGame_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UOmegaSaveBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaSaveGame_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaSaveGame_GetDisplayName, "GetDisplayName" }, // 3058725624
		{ &Z_Construct_UFunction_UOmegaSaveGame_OnGameStarted, "OnGameStarted" }, // 3878169437
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGame_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Save/OmegaSaveGame.h" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlaytime_MetaData[] = {
		{ "Category", "Playtime" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlaytime = { "SavedPlaytime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGame, SavedPlaytime), Z_Construct_UScriptStruct_FTimecode, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlaytime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlaytime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActiveLevelName_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActiveLevelName = { "ActiveLevelName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGame, ActiveLevelName), METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActiveLevelName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActiveLevelName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlayerTransform_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlayerTransform = { "SavedPlayerTransform", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGame, SavedPlayerTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlayerTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlayerTransform_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates_ValueProp = { "ActorStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates_Key_KeyProp = { "ActorStates_Key", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates = { "ActorStates", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGame, ActorStates), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates_MetaData)) }; // 802167388
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags_ValueProp = { "ActorTags", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags_Key_KeyProp = { "ActorTags_Key", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGame.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags = { "ActorTags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaSaveGame, ActorTags), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaSaveGame_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlaytime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActiveLevelName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_SavedPlayerTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorStates,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaSaveGame_Statics::NewProp_ActorTags,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaSaveGame_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaSaveGame>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaSaveGame_Statics::ClassParams = {
		&UOmegaSaveGame::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaSaveGame_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGame_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGame_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGame_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaSaveGame()
	{
		if (!Z_Registration_Info_UClass_UOmegaSaveGame.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaSaveGame.OuterSingleton, Z_Construct_UClass_UOmegaSaveGame_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaSaveGame.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaSaveGame>()
	{
		return UOmegaSaveGame::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaSaveGame);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaSaveGame, UOmegaSaveGame::StaticClass, TEXT("UOmegaSaveGame"), &Z_Registration_Info_UClass_UOmegaSaveGame, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaSaveGame), 146657661U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_2046955945(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

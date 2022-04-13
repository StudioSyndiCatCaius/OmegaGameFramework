// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorInterface_TurnOrderCombatant() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UActorInterface_TurnOrderCombatant_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UActorInterface_TurnOrderCombatant();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UTurnBasedManagerComponent_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
// End Cross Module References
	void IActorInterface_TurnOrderCombatant::OnAddedToTurnOrder(UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnAddedToTurnOrder instead.");
	}
	void IActorInterface_TurnOrderCombatant::OnRemovedFromTurnOrder(UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnRemovedFromTurnOrder instead.");
	}
	void IActorInterface_TurnOrderCombatant::OnTurnBegin(UTurnBasedManagerComponent* TurnManager)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnTurnBegin instead.");
	}
	void IActorInterface_TurnOrderCombatant::OnTurnEnd(UTurnBasedManagerComponent* TurnManager)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnTurnEnd instead.");
	}
	void UActorInterface_TurnOrderCombatant::StaticRegisterNativesUActorInterface_TurnOrderCombatant()
	{
	}
	struct Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnManager;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_TurnManager_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_TurnManager = { "TurnManager", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnAddedToTurnOrder_Parms, TurnManager), Z_Construct_UClass_UTurnBasedManagerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_TurnManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_TurnManager_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnAddedToTurnOrder_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnAddedToTurnOrder_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_TurnManager,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActorInterface_TurnOrderCombatant, nullptr, "OnAddedToTurnOrder", nullptr, nullptr, sizeof(ActorInterface_TurnOrderCombatant_eventOnAddedToTurnOrder_Parms), Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnManager;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_TurnManager_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_TurnManager = { "TurnManager", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnRemovedFromTurnOrder_Parms, TurnManager), Z_Construct_UClass_UTurnBasedManagerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_TurnManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_TurnManager_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnRemovedFromTurnOrder_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnRemovedFromTurnOrder_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_TurnManager,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag, Tags" },
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActorInterface_TurnOrderCombatant, nullptr, "OnRemovedFromTurnOrder", nullptr, nullptr, sizeof(ActorInterface_TurnOrderCombatant_eventOnRemovedFromTurnOrder_Parms), Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnManager;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::NewProp_TurnManager_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::NewProp_TurnManager = { "TurnManager", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnTurnBegin_Parms, TurnManager), Z_Construct_UClass_UTurnBasedManagerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::NewProp_TurnManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::NewProp_TurnManager_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::NewProp_TurnManager,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::Function_MetaDataParams[] = {
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActorInterface_TurnOrderCombatant, nullptr, "OnTurnBegin", nullptr, nullptr, sizeof(ActorInterface_TurnOrderCombatant_eventOnTurnBegin_Parms), Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnManager;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::NewProp_TurnManager_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::NewProp_TurnManager = { "TurnManager", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ActorInterface_TurnOrderCombatant_eventOnTurnEnd_Parms, TurnManager), Z_Construct_UClass_UTurnBasedManagerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::NewProp_TurnManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::NewProp_TurnManager_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::NewProp_TurnManager,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::Function_MetaDataParams[] = {
		{ "Category", "TurnBased" },
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UActorInterface_TurnOrderCombatant, nullptr, "OnTurnEnd", nullptr, nullptr, sizeof(ActorInterface_TurnOrderCombatant_eventOnTurnEnd_Parms), Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UActorInterface_TurnOrderCombatant);
	UClass* Z_Construct_UClass_UActorInterface_TurnOrderCombatant_NoRegister()
	{
		return UActorInterface_TurnOrderCombatant::StaticClass();
	}
	struct Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder, "OnAddedToTurnOrder" }, // 244723015
		{ &Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder, "OnRemovedFromTurnOrder" }, // 3516999790
		{ &Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnBegin, "OnTurnBegin" }, // 611106376
		{ &Z_Construct_UFunction_UActorInterface_TurnOrderCombatant_OnTurnEnd, "OnTurnEnd" }, // 472358004
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/TurnBased/ActorInterface_TurnOrderCombatant.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IActorInterface_TurnOrderCombatant>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::ClassParams = {
		&UActorInterface_TurnOrderCombatant::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000040A1u,
		METADATA_PARAMS(Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActorInterface_TurnOrderCombatant()
	{
		if (!Z_Registration_Info_UClass_UActorInterface_TurnOrderCombatant.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActorInterface_TurnOrderCombatant.OuterSingleton, Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UActorInterface_TurnOrderCombatant.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UActorInterface_TurnOrderCombatant>()
	{
		return UActorInterface_TurnOrderCombatant::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActorInterface_TurnOrderCombatant);
	static FName NAME_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder = FName(TEXT("OnAddedToTurnOrder"));
	void IActorInterface_TurnOrderCombatant::Execute_OnAddedToTurnOrder(UObject* O, UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UActorInterface_TurnOrderCombatant::StaticClass()));
		ActorInterface_TurnOrderCombatant_eventOnAddedToTurnOrder_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UActorInterface_TurnOrderCombatant_OnAddedToTurnOrder);
		if (Func)
		{
			Parms.TurnManager=TurnManager;
			Parms.Flag=Flag;
			Parms.Tags=Tags;
			O->ProcessEvent(Func, &Parms);
			Flag=Parms.Flag;
		}
	}
	static FName NAME_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder = FName(TEXT("OnRemovedFromTurnOrder"));
	void IActorInterface_TurnOrderCombatant::Execute_OnRemovedFromTurnOrder(UObject* O, UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UActorInterface_TurnOrderCombatant::StaticClass()));
		ActorInterface_TurnOrderCombatant_eventOnRemovedFromTurnOrder_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UActorInterface_TurnOrderCombatant_OnRemovedFromTurnOrder);
		if (Func)
		{
			Parms.TurnManager=TurnManager;
			Parms.Flag=Flag;
			Parms.Tags=Tags;
			O->ProcessEvent(Func, &Parms);
			Flag=Parms.Flag;
		}
	}
	static FName NAME_UActorInterface_TurnOrderCombatant_OnTurnBegin = FName(TEXT("OnTurnBegin"));
	void IActorInterface_TurnOrderCombatant::Execute_OnTurnBegin(UObject* O, UTurnBasedManagerComponent* TurnManager)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UActorInterface_TurnOrderCombatant::StaticClass()));
		ActorInterface_TurnOrderCombatant_eventOnTurnBegin_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UActorInterface_TurnOrderCombatant_OnTurnBegin);
		if (Func)
		{
			Parms.TurnManager=TurnManager;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UActorInterface_TurnOrderCombatant_OnTurnEnd = FName(TEXT("OnTurnEnd"));
	void IActorInterface_TurnOrderCombatant::Execute_OnTurnEnd(UObject* O, UTurnBasedManagerComponent* TurnManager)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UActorInterface_TurnOrderCombatant::StaticClass()));
		ActorInterface_TurnOrderCombatant_eventOnTurnEnd_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UActorInterface_TurnOrderCombatant_OnTurnEnd);
		if (Func)
		{
			Parms.TurnManager=TurnManager;
			O->ProcessEvent(Func, &Parms);
		}
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UActorInterface_TurnOrderCombatant, UActorInterface_TurnOrderCombatant::StaticClass, TEXT("UActorInterface_TurnOrderCombatant"), &Z_Registration_Info_UClass_UActorInterface_TurnOrderCombatant, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActorInterface_TurnOrderCombatant), 3117493588U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_2350328772(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

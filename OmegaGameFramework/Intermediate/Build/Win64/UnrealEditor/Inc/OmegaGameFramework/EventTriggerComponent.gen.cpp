// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Event/EventTriggerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEventTriggerComponent() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEventTriggerComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEventTriggerComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UEventTriggerComponent::execTriggerGlobalEvent)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Event);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TriggerGlobalEvent(Z_Param_Event);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEventTriggerComponent::execTriggerLocalEvent)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Event);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TriggerLocalEvent(Z_Param_Event);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEventTriggerComponent::execNative_TriggerEvent)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Event);
		P_GET_OBJECT(UObject,Z_Param_Instigator);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Native_TriggerEvent(Z_Param_Event,Z_Param_Instigator);
		P_NATIVE_END;
	}
	void UEventTriggerComponent::StaticRegisterNativesUEventTriggerComponent()
	{
		UClass* Class = UEventTriggerComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Native_TriggerEvent", &UEventTriggerComponent::execNative_TriggerEvent },
			{ "TriggerGlobalEvent", &UEventTriggerComponent::execTriggerGlobalEvent },
			{ "TriggerLocalEvent", &UEventTriggerComponent::execTriggerLocalEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics
	{
		struct EventTriggerComponent_eventNative_TriggerEvent_Parms
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
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EventTriggerComponent_eventNative_TriggerEvent_Parms, Event), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EventTriggerComponent_eventNative_TriggerEvent_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::NewProp_Event,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::NewProp_Instigator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Event/EventTriggerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEventTriggerComponent, nullptr, "Native_TriggerEvent", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::EventTriggerComponent_eventNative_TriggerEvent_Parms), Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics
	{
		struct EventTriggerComponent_eventTriggerGlobalEvent_Parms
		{
			FName Event;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_Event;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EventTriggerComponent_eventTriggerGlobalEvent_Parms, Event), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::NewProp_Event,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/Event/EventTriggerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEventTriggerComponent, nullptr, "TriggerGlobalEvent", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::EventTriggerComponent_eventTriggerGlobalEvent_Parms), Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics
	{
		struct EventTriggerComponent_eventTriggerLocalEvent_Parms
		{
			FName Event;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_Event;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EventTriggerComponent_eventTriggerLocalEvent_Parms, Event), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::NewProp_Event,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/Event/EventTriggerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEventTriggerComponent, nullptr, "TriggerLocalEvent", nullptr, nullptr, sizeof(Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::EventTriggerComponent_eventTriggerLocalEvent_Parms), Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEventTriggerComponent);
	UClass* Z_Construct_UClass_UEventTriggerComponent_NoRegister()
	{
		return UEventTriggerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UEventTriggerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LocalListeningActors_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalListeningActors_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_LocalListeningActors;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEventTriggerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UEventTriggerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEventTriggerComponent_Native_TriggerEvent, "Native_TriggerEvent" }, // 1269229825
		{ &Z_Construct_UFunction_UEventTriggerComponent_TriggerGlobalEvent, "TriggerGlobalEvent" }, // 3079808740
		{ &Z_Construct_UFunction_UEventTriggerComponent_TriggerLocalEvent, "TriggerLocalEvent" }, // 1332423535
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventTriggerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Event/EventTriggerComponent.h" },
		{ "ModuleRelativePath", "Public/Event/EventTriggerComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEventTriggerComponent_Statics::NewProp_LocalListeningActors_Inner = { "LocalListeningActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventTriggerComponent_Statics::NewProp_LocalListeningActors_MetaData[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/Event/EventTriggerComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEventTriggerComponent_Statics::NewProp_LocalListeningActors = { "LocalListeningActors", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEventTriggerComponent, LocalListeningActors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEventTriggerComponent_Statics::NewProp_LocalListeningActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEventTriggerComponent_Statics::NewProp_LocalListeningActors_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEventTriggerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventTriggerComponent_Statics::NewProp_LocalListeningActors_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventTriggerComponent_Statics::NewProp_LocalListeningActors,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEventTriggerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEventTriggerComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEventTriggerComponent_Statics::ClassParams = {
		&UEventTriggerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEventTriggerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEventTriggerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UEventTriggerComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEventTriggerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEventTriggerComponent()
	{
		if (!Z_Registration_Info_UClass_UEventTriggerComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEventTriggerComponent.OuterSingleton, Z_Construct_UClass_UEventTriggerComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEventTriggerComponent.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UEventTriggerComponent>()
	{
		return UEventTriggerComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEventTriggerComponent);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_EventTriggerComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_EventTriggerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEventTriggerComponent, UEventTriggerComponent::StaticClass, TEXT("UEventTriggerComponent"), &Z_Registration_Info_UClass_UEventTriggerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEventTriggerComponent), 4077594891U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_EventTriggerComponent_h_44452154(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_EventTriggerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_EventTriggerComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

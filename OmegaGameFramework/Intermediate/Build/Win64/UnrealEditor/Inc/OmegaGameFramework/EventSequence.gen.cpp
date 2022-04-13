// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Event/Sequence/EventSequence.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEventSequence() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEventSequence_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEventSequence();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UEventSequenceNode_NoRegister();
// End Cross Module References
	void UEventSequence::StaticRegisterNativesUEventSequence()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEventSequence);
	UClass* Z_Construct_UClass_UEventSequence_NoRegister()
	{
		return UEventSequence::StaticClass();
	}
	struct Z_Construct_UClass_UEventSequence_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_EventsOnBegin_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventsOnBegin_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_EventsOnBegin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SequenceNodes_Inner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SequenceNodes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SequenceNodes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SequenceNodes;
		static const UECodeGen_Private::FNamePropertyParams NewProp_EventsOnEnd_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventsOnEnd_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_EventsOnEnd;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEventSequence_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventSequence_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Event/Sequence/EventSequence.h" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequence.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnBegin_Inner = { "EventsOnBegin", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnBegin_MetaData[] = {
		{ "Category", "EventSequence" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequence.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnBegin = { "EventsOnBegin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEventSequence, EventsOnBegin), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnBegin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnBegin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_Inner_MetaData[] = {
		{ "Category", "EventSequence" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequence.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_Inner = { "SequenceNodes", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UEventSequenceNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_Inner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_Inner_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_MetaData[] = {
		{ "Category", "EventSequence" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequence.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes = { "SequenceNodes", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEventSequence, SequenceNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_MetaData)) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnEnd_Inner = { "EventsOnEnd", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnEnd_MetaData[] = {
		{ "Category", "EventSequence" },
		{ "ModuleRelativePath", "Public/Event/Sequence/EventSequence.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnEnd = { "EventsOnEnd", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEventSequence, EventsOnEnd), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnEnd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnEnd_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEventSequence_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnBegin_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnBegin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventSequence_Statics::NewProp_SequenceNodes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnEnd_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEventSequence_Statics::NewProp_EventsOnEnd,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEventSequence_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEventSequence>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEventSequence_Statics::ClassParams = {
		&UEventSequence::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UEventSequence_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequence_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UEventSequence_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEventSequence_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEventSequence()
	{
		if (!Z_Registration_Info_UClass_UEventSequence.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEventSequence.OuterSingleton, Z_Construct_UClass_UEventSequence_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEventSequence.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UEventSequence>()
	{
		return UEventSequence::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEventSequence);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequence_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequence_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEventSequence, UEventSequence::StaticClass, TEXT("UEventSequence"), &Z_Registration_Info_UClass_UEventSequence, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEventSequence), 4196831917U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequence_h_2322111192(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequence_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_Sequence_EventSequence_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Widget/HUDLayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHUDLayer() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UHUDLayer_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UHUDLayer();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
// End Cross Module References
	static FName NAME_UHUDLayer_LayerAdded = FName(TEXT("LayerAdded"));
	void UHUDLayer::LayerAdded(APlayerController* OwningPlayer, UObject* Context)
	{
		HUDLayer_eventLayerAdded_Parms Parms;
		Parms.OwningPlayer=OwningPlayer;
		Parms.Context=Context;
		ProcessEvent(FindFunctionChecked(NAME_UHUDLayer_LayerAdded),&Parms);
	}
	void UHUDLayer::StaticRegisterNativesUHUDLayer()
	{
	}
	struct Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningPlayer;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::NewProp_OwningPlayer = { "OwningPlayer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HUDLayer_eventLayerAdded_Parms, OwningPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HUDLayer_eventLayerAdded_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::NewProp_OwningPlayer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Public/Widget/HUDLayer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHUDLayer, nullptr, "LayerAdded", nullptr, nullptr, sizeof(HUDLayer_eventLayerAdded_Parms), Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHUDLayer_LayerAdded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHUDLayer_LayerAdded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHUDLayer);
	UClass* Z_Construct_UClass_UHUDLayer_NoRegister()
	{
		return UHUDLayer::StaticClass();
	}
	struct Z_Construct_UClass_UHUDLayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HUDTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HUDTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHUDLayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHUDLayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHUDLayer_LayerAdded, "LayerAdded" }, // 253401255
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHUDLayer_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideFunctions", "Construct Destruct" },
		{ "IncludePath", "Widget/HUDLayer.h" },
		{ "ModuleRelativePath", "Public/Widget/HUDLayer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHUDLayer_Statics::NewProp_HUDTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "Comment", "//UFUNCTION(BlueprintImplementableEvent)\n//void LayerRemoved();\n" },
		{ "ModuleRelativePath", "Public/Widget/HUDLayer.h" },
		{ "ToolTip", "UFUNCTION(BlueprintImplementableEvent)\nvoid LayerRemoved();" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHUDLayer_Statics::NewProp_HUDTags = { "HUDTags", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHUDLayer, HUDTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UHUDLayer_Statics::NewProp_HUDTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHUDLayer_Statics::NewProp_HUDTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHUDLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHUDLayer_Statics::NewProp_HUDTags,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHUDLayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHUDLayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHUDLayer_Statics::ClassParams = {
		&UHUDLayer::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UHUDLayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UHUDLayer_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UHUDLayer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHUDLayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHUDLayer()
	{
		if (!Z_Registration_Info_UClass_UHUDLayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHUDLayer.OuterSingleton, Z_Construct_UClass_UHUDLayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHUDLayer.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UHUDLayer>()
	{
		return UHUDLayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHUDLayer);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_HUDLayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_HUDLayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHUDLayer, UHUDLayer::StaticClass, TEXT("UHUDLayer"), &Z_Registration_Info_UClass_UHUDLayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHUDLayer), 3165215596U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_HUDLayer_h_1812317813(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_HUDLayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_HUDLayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

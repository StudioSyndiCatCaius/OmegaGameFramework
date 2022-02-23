// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaGameFrameworkBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameFrameworkBPLibrary() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameFrameworkBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	UMG_API UEnum* Z_Construct_UEnum_UMG_ESlateVisibility();
// End Cross Module References
	DEFINE_FUNCTION(UOmegaGameFrameworkBPLibrary::execSetWidgetVisibilityWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_ENUM(ESlateVisibility,Z_Param_Visibility);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetWidgetVisibilityWithTags(Z_Param_Tags,ESlateVisibility(Z_Param_Visibility));
		P_NATIVE_END;
	}
	void UOmegaGameFrameworkBPLibrary::StaticRegisterNativesUOmegaGameFrameworkBPLibrary()
	{
		UClass* Class = UOmegaGameFrameworkBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetWidgetVisibilityWithTags", &UOmegaGameFrameworkBPLibrary::execSetWidgetVisibilityWithTags },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics
	{
		struct OmegaGameFrameworkBPLibrary_eventSetWidgetVisibilityWithTags_Parms
		{
			FGameplayTagContainer Tags;
			ESlateVisibility Visibility;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Visibility_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Visibility;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameFrameworkBPLibrary_eventSetWidgetVisibilityWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::NewProp_Visibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::NewProp_Visibility = { "Visibility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaGameFrameworkBPLibrary_eventSetWidgetVisibilityWithTags_Parms, Visibility), Z_Construct_UEnum_UMG_ESlateVisibility, METADATA_PARAMS(nullptr, 0) }; // 2244982430
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::NewProp_Visibility_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::NewProp_Visibility,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widgets" },
		{ "Comment", "/*UFUNCTION(BlueprintPure, Category = \"\xce\xa9|Gameplay\", meta = (DeterminesOutputType = \"Class\", CompactNodeTitle = \"Gameplay System\"))\n\x09static AOmegaGameplaySystem* GetGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive);\n\x09*\n\x09UFUNCTION(BlueprintPure, Category = \"\xce\xa9|Assets\")\n\x09static TArray<UObject*> FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag Category);\n\n\x09UFUNCTION(BlueprintPure, Category = \"\xce\xa9|Assets\")\n\x09static TArray<UObject*> FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer Category);*/" },
		{ "ModuleRelativePath", "Public/OmegaGameFrameworkBPLibrary.h" },
		{ "ToolTip", "UFUNCTION(BlueprintPure, Category = \"\xce\xa9|Gameplay\", meta = (DeterminesOutputType = \"Class\", CompactNodeTitle = \"Gameplay System\"))\n       static AOmegaGameplaySystem* GetGameplaySystem(class TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive);\n       *\n       UFUNCTION(BlueprintPure, Category = \"\xce\xa9|Assets\")\n       static TArray<UObject*> FilterObjectsByCategoryTag(TArray<UObject*> Assets, FGameplayTag Category);\n\n       UFUNCTION(BlueprintPure, Category = \"\xce\xa9|Assets\")\n       static TArray<UObject*> FilterObjectsByGameplayTags(TArray<UObject*> Assets, FGameplayTagContainer Category);" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaGameFrameworkBPLibrary, nullptr, "SetWidgetVisibilityWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::OmegaGameFrameworkBPLibrary_eventSetWidgetVisibilityWithTags_Parms), Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaGameFrameworkBPLibrary);
	UClass* Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_NoRegister()
	{
		return UOmegaGameFrameworkBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaGameFrameworkBPLibrary_SetWidgetVisibilityWithTags, "SetWidgetVisibilityWithTags" }, // 1602031833
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
		{ "IncludePath", "OmegaGameFrameworkBPLibrary.h" },
		{ "ModuleRelativePath", "Public/OmegaGameFrameworkBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaGameFrameworkBPLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::ClassParams = {
		&UOmegaGameFrameworkBPLibrary::StaticClass,
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
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaGameFrameworkBPLibrary()
	{
		if (!Z_Registration_Info_UClass_UOmegaGameFrameworkBPLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaGameFrameworkBPLibrary.OuterSingleton, Z_Construct_UClass_UOmegaGameFrameworkBPLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaGameFrameworkBPLibrary.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaGameFrameworkBPLibrary>()
	{
		return UOmegaGameFrameworkBPLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaGameFrameworkBPLibrary);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameFrameworkBPLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameFrameworkBPLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaGameFrameworkBPLibrary, UOmegaGameFrameworkBPLibrary::StaticClass, TEXT("UOmegaGameFrameworkBPLibrary"), &Z_Registration_Info_UClass_UOmegaGameFrameworkBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaGameFrameworkBPLibrary), 1062649937U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameFrameworkBPLibrary_h_3203470945(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameFrameworkBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameFrameworkBPLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

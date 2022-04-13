// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Widget/MenuHandlerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMenuHandlerComponent() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UMenuHandlerComponent_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UMenuHandlerComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UMenu_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UMenuHandlerComponent::execOpenMenu)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OpenMenu(Z_Param_Tags);
		P_NATIVE_END;
	}
	void UMenuHandlerComponent::StaticRegisterNativesUMenuHandlerComponent()
	{
		UClass* Class = UMenuHandlerComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OpenMenu", &UMenuHandlerComponent::execOpenMenu },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics
	{
		struct MenuHandlerComponent_eventOpenMenu_Parms
		{
			FGameplayTagContainer Tags;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MenuHandlerComponent_eventOpenMenu_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MenuHandlerComponent_eventOpenMenu_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MenuHandlerComponent_eventOpenMenu_Parms), &Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "Menu" },
		{ "ModuleRelativePath", "Public/Widget/MenuHandlerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuHandlerComponent, nullptr, "OpenMenu", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::MenuHandlerComponent_eventOpenMenu_Parms), Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMenuHandlerComponent);
	UClass* Z_Construct_UClass_UMenuHandlerComponent_NoRegister()
	{
		return UMenuHandlerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMenuHandlerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MenuClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_MenuClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MenuObject_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MenuObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMenuHandlerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMenuHandlerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMenuHandlerComponent_OpenMenu, "OpenMenu" }, // 1347188884
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuHandlerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Widget/MenuHandlerComponent.h" },
		{ "ModuleRelativePath", "Public/Widget/MenuHandlerComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuClass_MetaData[] = {
		{ "Category", "Menu" },
		{ "ModuleRelativePath", "Public/Widget/MenuHandlerComponent.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuClass = { "MenuClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMenuHandlerComponent, MenuClass), Z_Construct_UClass_UMenu_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuObject_MetaData[] = {
		{ "Category", "Menu" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/MenuHandlerComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuObject = { "MenuObject", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMenuHandlerComponent, MenuObject), Z_Construct_UClass_UMenu_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuObject_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMenuHandlerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuHandlerComponent_Statics::NewProp_MenuObject,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMenuHandlerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMenuHandlerComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMenuHandlerComponent_Statics::ClassParams = {
		&UMenuHandlerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMenuHandlerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMenuHandlerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMenuHandlerComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMenuHandlerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMenuHandlerComponent()
	{
		if (!Z_Registration_Info_UClass_UMenuHandlerComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMenuHandlerComponent.OuterSingleton, Z_Construct_UClass_UMenuHandlerComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMenuHandlerComponent.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UMenuHandlerComponent>()
	{
		return UMenuHandlerComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMenuHandlerComponent);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_MenuHandlerComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_MenuHandlerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMenuHandlerComponent, UMenuHandlerComponent::StaticClass, TEXT("UMenuHandlerComponent"), &Z_Registration_Info_UClass_UMenuHandlerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMenuHandlerComponent), 487817682U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_MenuHandlerComponent_h_4068331123(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_MenuHandlerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_MenuHandlerComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

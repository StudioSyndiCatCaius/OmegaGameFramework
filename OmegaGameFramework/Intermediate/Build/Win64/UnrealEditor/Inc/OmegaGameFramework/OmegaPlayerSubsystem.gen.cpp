// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Player/OmegaPlayerSubsystem.h"
#include "Engine/Classes/Engine/LocalPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaPlayerSubsystem() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UMenu_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaPlayerSubsystem_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaPlayerSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_ULocalPlayerSubsystem();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UHUDLayer_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UMG_API UEnum* Z_Construct_UEnum_UMG_ESlateVisibility();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventMenuOpened_Parms
		{
			UMenu* Menu;
			FGameplayTagContainer Tags;
			bool FirstMenu;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Menu_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Menu;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_FirstMenu_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_FirstMenu;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_Menu_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_Menu = { "Menu", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventMenuOpened_Parms, Menu), Z_Construct_UClass_UMenu_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_Menu_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_Menu_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventMenuOpened_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_FirstMenu_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventMenuOpened_Parms*)Obj)->FirstMenu = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_FirstMenu = { "FirstMenu", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventMenuOpened_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_FirstMenu_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_Menu,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::NewProp_FirstMenu,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "MenuOpened__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::_Script_OmegaGameFramework_eventMenuOpened_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventMenuClosed_Parms
		{
			UMenu* Menu;
			FGameplayTagContainer Tags;
			bool LastMenu;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Menu_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Menu;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_LastMenu_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_LastMenu;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_Menu_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_Menu = { "Menu", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventMenuClosed_Parms, Menu), Z_Construct_UClass_UMenu_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_Menu_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_Menu_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventMenuClosed_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_LastMenu_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventMenuClosed_Parms*)Obj)->LastMenu = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_LastMenu = { "LastMenu", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventMenuClosed_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_LastMenu_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_Menu,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::NewProp_LastMenu,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "MenuClosed__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::_Script_OmegaGameFramework_eventMenuClosed_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "ClearHoveredWidgets__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execSetHUDVisibilityWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_ENUM(ESlateVisibility,Z_Param_Visibility);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHUDVisibilityWithTags(Z_Param_Tags,ESlateVisibility(Z_Param_Visibility));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execRemoveAllHudLayers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveAllHudLayers();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execRemoveHUDLayersWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveHUDLayersWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execGetHUDLayersWithTags)
	{
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UHUDLayer*>*)Z_Param__Result=P_THIS->GetHUDLayersWithTags(Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execGetHUDLayers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UHUDLayer*>*)Z_Param__Result=P_THIS->GetHUDLayers();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execRemoveHUDLayer)
	{
		P_GET_OBJECT(UHUDLayer,Z_Param_Layer);
		P_GET_PROPERTY(FStrProperty,Z_Param_Flag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveHUDLayer(Z_Param_Layer,Z_Param_Flag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execAddHUDLayer)
	{
		P_GET_OBJECT(UClass,Z_Param_LayerClass);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_GET_PROPERTY(FIntProperty,Z_Param_LayerIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UHUDLayer**)Z_Param__Result=P_THIS->AddHUDLayer(Z_Param_LayerClass,Z_Param_Context,Z_Param_LayerIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execCanInterfaceInput)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanInterfaceInput();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execInputTag)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_Tag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputTag(Z_Param_Tag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execInputPage)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Axis);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputPage(Z_Param_Axis);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execInputNavigate)
	{
		P_GET_STRUCT(FVector2D,Z_Param_Axis);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputNavigate(Z_Param_Axis);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execInputCancel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputCancel();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execInputConfirm)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputConfirm();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execRemoveMenuFromActiveList)
	{
		P_GET_OBJECT(UMenu,Z_Param_Menu);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveMenuFromActiveList(Z_Param_Menu);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execClearControlWidget)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearControlWidget();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execSetControlWidget)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_Widget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetControlWidget(Z_Param_Widget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execCloseAllMenus)
	{
		P_GET_OBJECT(AActor,Z_Param_DestroyedActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseAllMenus(Z_Param_DestroyedActor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execGetMenu)
	{
		P_GET_OBJECT(UClass,Z_Param_MenuClass);
		P_GET_UBOOL_REF(Z_Param_Out_bIsValid);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UMenu**)Z_Param__Result=P_THIS->GetMenu(Z_Param_MenuClass,Z_Param_Out_bIsValid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execCloseMenu)
	{
		P_GET_OBJECT(UClass,Z_Param_MenuClass);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CloseMenu(Z_Param_MenuClass,Z_Param_Tags);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaPlayerSubsystem::execOpenMenu)
	{
		P_GET_OBJECT(UClass,Z_Param_MenuClass);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_GET_STRUCT(FGameplayTagContainer,Z_Param_Tags);
		P_GET_UBOOL(Z_Param_AutoFocus);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UMenu**)Z_Param__Result=P_THIS->OpenMenu(Z_Param_MenuClass,Z_Param_Context,Z_Param_Tags,Z_Param_AutoFocus);
		P_NATIVE_END;
	}
	void UOmegaPlayerSubsystem::StaticRegisterNativesUOmegaPlayerSubsystem()
	{
		UClass* Class = UOmegaPlayerSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddHUDLayer", &UOmegaPlayerSubsystem::execAddHUDLayer },
			{ "CanInterfaceInput", &UOmegaPlayerSubsystem::execCanInterfaceInput },
			{ "ClearControlWidget", &UOmegaPlayerSubsystem::execClearControlWidget },
			{ "CloseAllMenus", &UOmegaPlayerSubsystem::execCloseAllMenus },
			{ "CloseMenu", &UOmegaPlayerSubsystem::execCloseMenu },
			{ "GetHUDLayers", &UOmegaPlayerSubsystem::execGetHUDLayers },
			{ "GetHUDLayersWithTags", &UOmegaPlayerSubsystem::execGetHUDLayersWithTags },
			{ "GetMenu", &UOmegaPlayerSubsystem::execGetMenu },
			{ "InputCancel", &UOmegaPlayerSubsystem::execInputCancel },
			{ "InputConfirm", &UOmegaPlayerSubsystem::execInputConfirm },
			{ "InputNavigate", &UOmegaPlayerSubsystem::execInputNavigate },
			{ "InputPage", &UOmegaPlayerSubsystem::execInputPage },
			{ "InputTag", &UOmegaPlayerSubsystem::execInputTag },
			{ "OpenMenu", &UOmegaPlayerSubsystem::execOpenMenu },
			{ "RemoveAllHudLayers", &UOmegaPlayerSubsystem::execRemoveAllHudLayers },
			{ "RemoveHUDLayer", &UOmegaPlayerSubsystem::execRemoveHUDLayer },
			{ "RemoveHUDLayersWithTags", &UOmegaPlayerSubsystem::execRemoveHUDLayersWithTags },
			{ "RemoveMenuFromActiveList", &UOmegaPlayerSubsystem::execRemoveMenuFromActiveList },
			{ "SetControlWidget", &UOmegaPlayerSubsystem::execSetControlWidget },
			{ "SetHUDVisibilityWithTags", &UOmegaPlayerSubsystem::execSetHUDVisibilityWithTags },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics
	{
		struct OmegaPlayerSubsystem_eventAddHUDLayer_Parms
		{
			TSubclassOf<UHUDLayer>  LayerClass;
			UObject* Context;
			int32 LayerIndex;
			UHUDLayer* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_LayerClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FIntPropertyParams NewProp_LayerIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_LayerClass = { "LayerClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventAddHUDLayer_Parms, LayerClass), Z_Construct_UClass_UHUDLayer_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventAddHUDLayer_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_LayerIndex = { "LayerIndex", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventAddHUDLayer_Parms, LayerIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventAddHUDLayer_Parms, ReturnValue), Z_Construct_UClass_UHUDLayer_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_LayerClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_LayerIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "LayerIndex, Context" },
		{ "Category", "\xce\xa9|Widget|HUD" },
		{ "Comment", "////////////////////////\n/////////HUD/////////\n//////////////////////\n" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
		{ "ToolTip", "HUD\n/" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "AddHUDLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::OmegaPlayerSubsystem_eventAddHUDLayer_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics
	{
		struct OmegaPlayerSubsystem_eventCanInterfaceInput_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaPlayerSubsystem_eventCanInterfaceInput_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaPlayerSubsystem_eventCanInterfaceInput_Parms), &Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "CanInterfaceInput", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::OmegaPlayerSubsystem_eventCanInterfaceInput_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Menu" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "ClearControlWidget", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics
	{
		struct OmegaPlayerSubsystem_eventCloseAllMenus_Parms
		{
			AActor* DestroyedActor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DestroyedActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::NewProp_DestroyedActor = { "DestroyedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventCloseAllMenus_Parms, DestroyedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::NewProp_DestroyedActor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "CloseAllMenus", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::OmegaPlayerSubsystem_eventCloseAllMenus_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics
	{
		struct OmegaPlayerSubsystem_eventCloseMenu_Parms
		{
			TSubclassOf<UMenu>  MenuClass;
			FGameplayTagContainer Tags;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_MenuClass;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_MenuClass = { "MenuClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventCloseMenu_Parms, MenuClass), Z_Construct_UClass_UMenu_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventCloseMenu_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaPlayerSubsystem_eventCloseMenu_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaPlayerSubsystem_eventCloseMenu_Parms), &Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_MenuClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Menu" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "CloseMenu", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::OmegaPlayerSubsystem_eventCloseMenu_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics
	{
		struct OmegaPlayerSubsystem_eventGetHUDLayers_Parms
		{
			TArray<UHUDLayer*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UHUDLayer_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventGetHUDLayers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|HUD" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "GetHUDLayers", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::OmegaPlayerSubsystem_eventGetHUDLayers_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics
	{
		struct OmegaPlayerSubsystem_eventGetHUDLayersWithTags_Parms
		{
			FGameplayTagContainer Tags;
			TArray<UHUDLayer*> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventGetHUDLayersWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UHUDLayer_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventGetHUDLayersWithTags_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|HUD" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "GetHUDLayersWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::OmegaPlayerSubsystem_eventGetHUDLayersWithTags_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics
	{
		struct OmegaPlayerSubsystem_eventGetMenu_Parms
		{
			TSubclassOf<UMenu>  MenuClass;
			bool bIsValid;
			UMenu* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_MenuClass;
		static void NewProp_bIsValid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_MenuClass = { "MenuClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventGetMenu_Parms, MenuClass), Z_Construct_UClass_UMenu_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_bIsValid_SetBit(void* Obj)
	{
		((OmegaPlayerSubsystem_eventGetMenu_Parms*)Obj)->bIsValid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaPlayerSubsystem_eventGetMenu_Parms), &Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventGetMenu_Parms, ReturnValue), Z_Construct_UClass_UMenu_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_MenuClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_bIsValid,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Menu" },
		{ "DeterminesOutputType", "MenuClass" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "GetMenu", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::OmegaPlayerSubsystem_eventGetMenu_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Input" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "InputCancel", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Input" },
		{ "Comment", "//Menu Input\n" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
		{ "ToolTip", "Menu Input" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "InputConfirm", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics
	{
		struct OmegaPlayerSubsystem_eventInputNavigate_Parms
		{
			FVector2D Axis;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Axis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventInputNavigate_Parms, Axis), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::NewProp_Axis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Input" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "InputNavigate", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::OmegaPlayerSubsystem_eventInputNavigate_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics
	{
		struct OmegaPlayerSubsystem_eventInputPage_Parms
		{
			float Axis;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Axis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventInputPage_Parms, Axis), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::NewProp_Axis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Input" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "InputPage", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::OmegaPlayerSubsystem_eventInputPage_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics
	{
		struct OmegaPlayerSubsystem_eventInputTag_Parms
		{
			FGameplayTag Tag;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventInputTag_Parms, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::NewProp_Tag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Input" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "InputTag", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::OmegaPlayerSubsystem_eventInputTag_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics
	{
		struct OmegaPlayerSubsystem_eventOpenMenu_Parms
		{
			TSubclassOf<UMenu>  MenuClass;
			UObject* Context;
			FGameplayTagContainer Tags;
			bool AutoFocus;
			UMenu* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_MenuClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static void NewProp_AutoFocus_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_AutoFocus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_MenuClass = { "MenuClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventOpenMenu_Parms, MenuClass), Z_Construct_UClass_UMenu_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventOpenMenu_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventOpenMenu_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	void Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_AutoFocus_SetBit(void* Obj)
	{
		((OmegaPlayerSubsystem_eventOpenMenu_Parms*)Obj)->AutoFocus = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_AutoFocus = { "AutoFocus", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaPlayerSubsystem_eventOpenMenu_Parms), &Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_AutoFocus_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventOpenMenu_Parms, ReturnValue), Z_Construct_UClass_UMenu_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_MenuClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_AutoFocus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Context, Flag, AutoFocus" },
		{ "Category", "\xce\xa9|Widget|Menu" },
		{ "Comment", "////////////////////////\n/////////Menus/////////\n//////////////////////\n" },
		{ "CPP_Default_AutoFocus", "true" },
		{ "DeterminesOutputType", "MenuClass" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
		{ "ToolTip", "Menus\n/" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "OpenMenu", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::OmegaPlayerSubsystem_eventOpenMenu_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|HUD" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "RemoveAllHudLayers", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics
	{
		struct OmegaPlayerSubsystem_eventRemoveHUDLayer_Parms
		{
			UHUDLayer* Layer;
			FString Flag;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Layer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Layer;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Flag;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_Layer_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_Layer = { "Layer", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventRemoveHUDLayer_Parms, Layer), Z_Construct_UClass_UHUDLayer_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_Layer_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_Layer_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventRemoveHUDLayer_Parms, Flag), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OmegaPlayerSubsystem_eventRemoveHUDLayer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OmegaPlayerSubsystem_eventRemoveHUDLayer_Parms), &Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_Layer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_Flag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "Flag" },
		{ "Category", "\xce\xa9|Widget|HUD" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "RemoveHUDLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::OmegaPlayerSubsystem_eventRemoveHUDLayer_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics
	{
		struct OmegaPlayerSubsystem_eventRemoveHUDLayersWithTags_Parms
		{
			FGameplayTagContainer Tags;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventRemoveHUDLayersWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::NewProp_Tags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|HUD" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "RemoveHUDLayersWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::OmegaPlayerSubsystem_eventRemoveHUDLayersWithTags_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics
	{
		struct OmegaPlayerSubsystem_eventRemoveMenuFromActiveList_Parms
		{
			UMenu* Menu;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Menu_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Menu;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::NewProp_Menu_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::NewProp_Menu = { "Menu", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventRemoveMenuFromActiveList_Parms, Menu), Z_Construct_UClass_UMenu_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::NewProp_Menu_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::NewProp_Menu_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::NewProp_Menu,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "RemoveMenuFromActiveList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::OmegaPlayerSubsystem_eventRemoveMenuFromActiveList_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics
	{
		struct OmegaPlayerSubsystem_eventSetControlWidget_Parms
		{
			UUserWidget* Widget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Widget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::NewProp_Widget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventSetControlWidget_Parms, Widget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::NewProp_Widget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::NewProp_Widget_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::NewProp_Widget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|Menu" },
		{ "Comment", "//Which Menu is this player current inputing into.\n" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
		{ "ToolTip", "Which Menu is this player current inputing into." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "SetControlWidget", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::OmegaPlayerSubsystem_eventSetControlWidget_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics
	{
		struct OmegaPlayerSubsystem_eventSetHUDVisibilityWithTags_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventSetHUDVisibilityWithTags_Parms, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::NewProp_Visibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::NewProp_Visibility = { "Visibility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaPlayerSubsystem_eventSetHUDVisibilityWithTags_Parms, Visibility), Z_Construct_UEnum_UMG_ESlateVisibility, METADATA_PARAMS(nullptr, 0) }; // 2244982430
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::NewProp_Visibility_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::NewProp_Visibility,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|HUD" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaPlayerSubsystem, nullptr, "SetHUDVisibilityWithTags", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::OmegaPlayerSubsystem_eventSetHUDVisibilityWithTags_Parms), Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaPlayerSubsystem);
	UClass* Z_Construct_UClass_UOmegaPlayerSubsystem_NoRegister()
	{
		return UOmegaPlayerSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaPlayerSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OpenMenus_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OpenMenus_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OpenMenus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FocusMenu_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FocusMenu;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnMenuOpened_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMenuOpened;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnMenuClosed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMenuClosed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParentPlayerController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentPlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ClearHoveredWidgets_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_ClearHoveredWidgets;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULocalPlayerSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_AddHUDLayer, "AddHUDLayer" }, // 3149628113
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_CanInterfaceInput, "CanInterfaceInput" }, // 55566588
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_ClearControlWidget, "ClearControlWidget" }, // 2090550076
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseAllMenus, "CloseAllMenus" }, // 1034638829
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_CloseMenu, "CloseMenu" }, // 1204715891
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayers, "GetHUDLayers" }, // 862811132
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_GetHUDLayersWithTags, "GetHUDLayersWithTags" }, // 3969443957
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_GetMenu, "GetMenu" }, // 731175582
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_InputCancel, "InputCancel" }, // 4274314896
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_InputConfirm, "InputConfirm" }, // 853212215
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_InputNavigate, "InputNavigate" }, // 2713840902
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_InputPage, "InputPage" }, // 3477390606
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_InputTag, "InputTag" }, // 922859465
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_OpenMenu, "OpenMenu" }, // 2513842506
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveAllHudLayers, "RemoveAllHudLayers" }, // 1831870565
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayer, "RemoveHUDLayer" }, // 3507108869
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveHUDLayersWithTags, "RemoveHUDLayersWithTags" }, // 1444970374
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_RemoveMenuFromActiveList, "RemoveMenuFromActiveList" }, // 782077438
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_SetControlWidget, "SetControlWidget" }, // 497712483
		{ &Z_Construct_UFunction_UOmegaPlayerSubsystem_SetHUDVisibilityWithTags, "SetHUDVisibilityWithTags" }, // 956997564
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Player/OmegaPlayerSubsystem.h" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OpenMenus_Inner = { "OpenMenus", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UMenu_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OpenMenus_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OpenMenus = { "OpenMenus", nullptr, (EPropertyFlags)0x0010008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaPlayerSubsystem, OpenMenus), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OpenMenus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OpenMenus_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_FocusMenu_MetaData[] = {
		{ "Category", "Widget" },
		{ "DisplayName", "Control Widget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_FocusMenu = { "FocusMenu", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaPlayerSubsystem, FocusMenu), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_FocusMenu_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_FocusMenu_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuOpened_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuOpened = { "OnMenuOpened", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaPlayerSubsystem, OnMenuOpened), Z_Construct_UDelegateFunction_OmegaGameFramework_MenuOpened__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuOpened_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuOpened_MetaData)) }; // 2181357432
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuClosed_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuClosed = { "OnMenuClosed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaPlayerSubsystem, OnMenuClosed), Z_Construct_UDelegateFunction_OmegaGameFramework_MenuClosed__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuClosed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuClosed_MetaData)) }; // 1858352048
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ParentPlayerController_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ParentPlayerController = { "ParentPlayerController", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaPlayerSubsystem, ParentPlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ParentPlayerController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ParentPlayerController_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ClearHoveredWidgets_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/OmegaPlayerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ClearHoveredWidgets = { "ClearHoveredWidgets", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaPlayerSubsystem, ClearHoveredWidgets), Z_Construct_UDelegateFunction_OmegaGameFramework_ClearHoveredWidgets__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ClearHoveredWidgets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ClearHoveredWidgets_MetaData)) }; // 2775909238
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OpenMenus_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OpenMenus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_FocusMenu,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuOpened,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_OnMenuClosed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ParentPlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::NewProp_ClearHoveredWidgets,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaPlayerSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::ClassParams = {
		&UOmegaPlayerSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaPlayerSubsystem()
	{
		if (!Z_Registration_Info_UClass_UOmegaPlayerSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaPlayerSubsystem.OuterSingleton, Z_Construct_UClass_UOmegaPlayerSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaPlayerSubsystem.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaPlayerSubsystem>()
	{
		return UOmegaPlayerSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaPlayerSubsystem);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaPlayerSubsystem, UOmegaPlayerSubsystem::StaticClass, TEXT("UOmegaPlayerSubsystem"), &Z_Registration_Info_UClass_UOmegaPlayerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaPlayerSubsystem), 2322845642U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_2881794772(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

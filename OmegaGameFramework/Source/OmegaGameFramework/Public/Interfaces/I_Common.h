// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_Bitflag.h"
#include "Types/Struct_CustomNamedList.h"
#include "I_Common.generated.h"

UINTERFACE(MinimalAPI)
class UDataInterface_ObjectHierarchy : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ObjectHierarchy
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="ΩI|Hierarchy",DisplayName="Hierarchy - Get Children")
	TArray<UObject*> GetObject_Children() const;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="ΩI|Hierarchy",DisplayName="Hierarchy - Get Parent")
	UObject* GetObject_Parent() const;
};




// ===================================================================================================================
// General Info
// ===================================================================================================================


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_General : public UInterface
{
	GENERATED_BODY()

public:
	static FText GetObjectName(UObject* obj,FGameplayTag Tag=FGameplayTag());
	static FText GetObjectDesc(UObject* obj,FGameplayTag Tag=FGameplayTag());
	static FSlateBrush GetObjectIcon(UObject* obj,FGameplayTag Tag=FGameplayTag());
	static FString GetObjectLabel(UObject* obj);
	static FGameplayTag GetGCategory(UObject* o);
	static FGameplayTagContainer GetGTags(UObject* o);
};


class OMEGAGAMEFRAMEWORK_API IDataInterface_General
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", meta=(AdvancedDisplay="Context"),DisplayName="General - Get Texts")
	void GetGeneralDataText (FGameplayTag Tag, FText& Name, FText& Description);
	
	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", meta=(AdvancedDisplay="Context"),DisplayName="General - Get Imaged")
	void GetGeneralDataImages (FGameplayTag Tag,class UTexture2D*& Texture,class UMaterialInterface*& Material,FSlateBrush& Brush);
	
	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", meta=(CompactNodeTitle="Color"),DisplayName="General - Get Color")
	void GetGeneralAssetColor(FGameplayTag Tag,FLinearColor& Color);
	
	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", meta=(CompactNodeTitle="General Label"),DisplayName="General - Get Label")
	void GetGeneralAssetLabel(FString& Label);

	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", DisplayName="Tags - Get Category") FGameplayTag GetObjectGameplayCategory();
	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", DisplayName="Tags - Get Tags") FGameplayTagContainer GetObjectGameplayTags();
	
	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", DisplayName="Tag - Event") void Tag_Event(FGameplayTag Event, FOmegaCommonMeta meta);
	UFUNCTION(BlueprintNativeEvent, Category = "ΩI|General", DisplayName="Tag - Query") bool Tag_Query(FGameplayTag Query, FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|General") void GetMetaConfig(FOmegaBitflagsBase& bitflags,FGuid& guid, int32& seed,FOmegaClassNamedLists& named_lists);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|General") FOmegaBitmaskEditorData Bitflags_Override(bool& bOverride);
};






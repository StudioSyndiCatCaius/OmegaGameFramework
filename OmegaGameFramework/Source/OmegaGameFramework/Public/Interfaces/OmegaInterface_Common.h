// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "OmegaInterface_Common.generated.h"

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
	static FText GetObjectName(UObject* obj);
	static FText GetObjectDesc(UObject* obj);
};


class OMEGAGAMEFRAMEWORK_API IDataInterface_General
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ΩI|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Texts"), DisplayName="General - Get Text")
	void GetGeneralDataText (const FString& Label, const class UObject* Context, FText& Name, FText& Description);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ΩI|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Images"), DisplayName="General - Get Images")
	void GetGeneralDataImages (const FString& Label, const class UObject* Context,class UTexture2D*& Texture,class UMaterialInterface*& Material,FSlateBrush& Brush);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ΩI|General", meta=(CompactNodeTitle="Color"), DisplayName="General - Get Color")
	void GetGeneralAssetColor(FLinearColor& Color);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ΩI|General", meta=(CompactNodeTitle="General Label"), DisplayName="General - Get Label")
	void GetGeneralAssetLabel(FString& Label);

};


inline FText UDataInterface_General::GetObjectName(UObject* obj)
{
	FText out_name;
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText out_desc;
		IDataInterface_General::Execute_GetGeneralDataText(obj,"",nullptr,out_name,out_desc);
	}
	return out_name;
}

inline FText UDataInterface_General::GetObjectDesc(UObject* obj)
{
	FText out;
	if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		FText out_desc;
		IDataInterface_General::Execute_GetGeneralDataText(obj,"",nullptr,out_desc,out);
	}
	return out;
}


UINTERFACE(MinimalAPI)
class UDataInterface_GUID : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_GUID
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|GUID",DisplayName="GUID - Get")
	FGuid GetObjectGuid() const;
};


// ===================================================================================================================
// Tags Interface
// ===================================================================================================================
UINTERFACE(MinimalAPI)
class UGameplayTagsInterface : public UInterface
{
	GENERATED_BODY()
public:
	static FGameplayTag GetGCategory(UObject* o);
	static FGameplayTagContainer GetGTags(UObject* o);
	
};

class OMEGAGAMEFRAMEWORK_API IGameplayTagsInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ΩI|General", DisplayName="Tags - Get Category")
	FGameplayTag GetObjectGameplayCategory();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ΩI|General", DisplayName="Tags - Get Tags")
	FGameplayTagContainer GetObjectGameplayTags();

};

inline FGameplayTag UGameplayTagsInterface::GetGCategory(UObject* o)
{
	if(o && o->GetClass()->ImplementsInterface(StaticClass()))
	{
		return IGameplayTagsInterface::Execute_GetObjectGameplayCategory(o);
	}
	return FGameplayTag();
}

inline FGameplayTagContainer UGameplayTagsInterface::GetGTags(UObject* o)
{
	if(o && o->GetClass()->ImplementsInterface(StaticClass()))
	{
		return IGameplayTagsInterface::Execute_GetObjectGameplayTags(o);
	}
	return FGameplayTagContainer();
}

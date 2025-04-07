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
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Omega|GUID")
	TArray<UObject*> GetObject_Children() const;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="Omega|GUID")
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
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Texts"))
	void GetGeneralDataText (const FString& Label, const class UObject* Context, FText& Name, FText& Description);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Images"))
	void GetGeneralDataImages (const FString& Label, const class UObject* Context,class UTexture2D*& Texture,class UMaterialInterface*& Material,FSlateBrush& Brush);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(CompactNodeTitle="Color"))
	void GetGeneralAssetColor(FLinearColor& Color);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(CompactNodeTitle="General Label"))
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
	
	UFUNCTION(BlueprintNativeEvent,Category="Omega|GUID")
	FGuid GetObjectGuid() const;
};


// ===================================================================================================================
// Tags Interface
// ===================================================================================================================
UINTERFACE(MinimalAPI)
class UGameplayTagsInterface : public UInterface { GENERATED_BODY() };

class OMEGAGAMEFRAMEWORK_API IGameplayTagsInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTag GetObjectGameplayCategory();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
	FGameplayTagContainer GetObjectGameplayTags();

};


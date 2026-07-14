// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_ActorRelatives.h"
#include "Types/Struct_Bitflag.h"
#include "Types/Struct_CustomNamedList.h"
#include "I_Common.generated.h"

class UNiagaraSystem;

UINTERFACE(MinimalAPI)
class UDataInterface_ObjectHierarchy : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_ObjectHierarchy
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|Hierarchy",DisplayName="Hierarchy - Get Children")
	TArray<UObject*> GetObject_Children() const;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable,Category="♎I|Hierarchy",DisplayName="Hierarchy - Get Parent")
	UObject* GetObject_Parent() const;
};


// ===================================================================================================================
// General Info
// ===================================================================================================================

USTRUCT(BlueprintType)
struct OMEGAGAMEFRAMEWORK_API FOmegaObjectGeneralMetaconfig
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meta") FOmegaBitflagsBase bitflags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meta") FGuid guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meta") int32 seed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meta") FOmegaClassNamedLists named_lists;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meta") FOmegaActorRelatives relative_assets;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meta") int32 GenericLevel = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Meta") TEnumAsByte<EOmegaStarRank> StarRank = TEnumAsByte<EOmegaStarRank>(0);
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_General : public UInterface
{
	GENERATED_BODY()

public:
	static FText GetObjectName(UObject* obj, FGameplayTag Tag=FGameplayTag());
	static FText GetObjectDesc(UObject* obj, FGameplayTag Tag=FGameplayTag());
	static FSlateBrush GetObjectIcon(UObject* obj, FGameplayTag Tag=FGameplayTag());
	static FString GetObjectLabel(UObject* obj);
	static FLinearColor GetObjectColor(UObject* obj, FGameplayTag Tag=FGameplayTag());
	static FGameplayTagContainer GetGTags(UObject* o);
	static FGameplayTag GetGCategory(UObject* o);
};

class OMEGAGAMEFRAMEWORK_API IDataInterface_General
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="General - Get Config")
	void GetGeneralDataText(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig);

	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="General - Get GameplayTags")
	void GetObjectGameplayTags(FGameplayTag& CategoryTag, FGameplayTagContainer& GameplayTags);

	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="Tag - Event") void Tag_Event(FGameplayTag Event, FOmegaCommonMeta meta);
	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="Tag - Query") bool Tag_Query(FGameplayTag Query, FOmegaCommonMeta meta);
	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="Tag - Utility") float Tag_Utility(FGameplayTag Query, FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="Param - Float") float Param_Float(FGameplayTag Param);
	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="Param - Int") int32 Param_Int(FGameplayTag Param);
	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="Param - String") FString Param_String(FGameplayTag Param);
	UFUNCTION(BlueprintNativeEvent, Category = "♎I|General", DisplayName="Param - Object") UObject* Param_Asset(FGameplayTag Param);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="♎I|General") FOmegaBitmaskEditorData Bitflags_Override(bool& bOverride);
};

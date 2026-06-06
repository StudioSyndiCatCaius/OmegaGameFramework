// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Interfaces/I_Common.h"
#include "GameplayTagContainer.h"
#include "LuaCode.h"
#include "LuaInterface.h"
#include "Interfaces/I_ObjectTraits.h"
#include "Functions/F_SoftProperty.h"
#include "Interfaces/I_DataAsset.h"
#include "Types/Struct_ActorRelatives.h"
#include "Types/Struct_CustomNamedList.h"
#include "GeneralDataObject.generated.h"


#define OMACRO_ADDPARAMS_GENERAL() \
virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override \
{ Name=DisplayName; Description=DisplayDescription; iconBrush=Icon; Color=color; if(!CustomLabel.IsEmpty()){Label=CustomLabel;}else{Label=GetName();} MetaConfig.guid=Guid; }; \
virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override \
{ OutCategoryTag=CategoryTag; OutGameplayTags=GameplayTags; }; \


USTRUCT(BlueprintType)
struct FCustomAssetData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Data");
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Data");
	FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Data");
	FString Label;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Data");
	UTexture2D* Texture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Data");
	FLinearColor Color = FLinearColor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Data");
	FGameplayTagContainer Tags;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UGeneralDataObject : public UObject, public IDataInterface_General
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
	FCustomAssetData CustomData;

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override
	{
		Name=CustomData.DisplayName;
		Description=CustomData.Description;
		iconBrush.SetResourceObject(CustomData.Texture);
		Color=CustomData.Color;
		Label=CustomData.Label;
	};
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override {};

};


UCLASS(Blueprintable,BlueprintType,Abstract,Const,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaInstancableObject : public UObject
{
	GENERATED_BODY()
public:
};

UCLASS(meta=(ShowWorldContextPin,DisallowCreateNew),EditInlineNew,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaMinimalDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDataAsset : public UOmegaMinimalDataAsset, public IDataInterface_General, public ILuaInterface
{
	GENERATED_BODY()
public:
	UOmegaDataAsset();
	FColor asset_color=FColor::Red;
	
	UPROPERTY() FLuaValue LuaData;
	UPROPERTY() FName LuaKey;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Icon") FSlateBrush Icon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Description") FText DisplayDescription;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Color") FLinearColor color=FLinearColor::White;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="🏷️Category") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="🏷️Tags") FGameplayTagContainer GameplayTags;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) FString CustomLabel;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="General",AdvancedDisplay) FGuid Guid;
	
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	virtual auto GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag,
	                                                  FGameplayTagContainer& OutGameplayTags) -> void override;
	
	UFUNCTION(BlueprintNativeEvent,Category="Editor") bool UseIconAsThumbnail();
	
	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field) override;
	virtual void SetKey_Implementation(FLuaValue Key) override;
	virtual FLuaValue GetValue_Implementation(const FString& Field) override { return LuaData; };
	virtual FLuaValue GetKey_Implementation() override { return FLuaValue(LuaKey.ToString()); };
	
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaDemoDataAsset : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Metaconfig") FOmegaClassNamedLists NamedLists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Metaconfig") FOmegaBitflagsBase Flags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Metaconfig") FOmegaActorRelatives RelativeAssets;
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Demo Meta",AdvancedDisplay) FOmegaLuaCode LuaCode;
	
};
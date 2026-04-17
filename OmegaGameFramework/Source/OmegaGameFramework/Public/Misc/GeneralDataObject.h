// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "GameplayTagContainer.h"
#include "LuaCode.h"
#include "LuaInterface.h"
#include "Interfaces/I_ObjectTraits.h"
#include "Functions/F_SoftProperty.h"
#include "Interfaces/I_AssetThumbnail.h"
#include "Interfaces/I_DataAsset.h"
#include "Types/Struct_CustomNamedList.h"
#include "GeneralDataObject.generated.h"


#define OMACRO_ADDPARAMS_GENERAL() \
virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override \
{ Name=DisplayName; Description=DisplayDescription; }; \
virtual void GetGeneralDataImages_Implementation(FGameplayTag Tag, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override \
{ Brush=Icon; }; \
virtual void GetGeneralAssetLabel_Implementation(FString& Label) override { if(!CustomLabel.IsEmpty()) {Label=CustomLabel; return; } Label=GetName(); return; }; \
virtual FGameplayTag GetObjectGameplayCategory_Implementation() override { return CategoryTag; }; \
virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return  GameplayTags; }; \


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

	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override
	{
		Name=CustomData.DisplayName, Description=CustomData.Description;
	};
	virtual void GetGeneralDataImages_Implementation(FGameplayTag Tag, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush) override
	{
		Brush.SetResourceObject(CustomData.Texture);
	};
	virtual void GetGeneralAssetColor_Implementation(FGameplayTag Tag, FLinearColor& Color) override
	{
		Color=CustomData.Color;
	};

	virtual void GetGeneralAssetLabel_Implementation(FString& Label);

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
class OMEGAGAMEFRAMEWORK_API UOmegaDataAsset : public UOmegaMinimalDataAsset, public IDataInterface_General, public IDataInterface_AssetThumbnail,
																			public ILuaInterface, public IDataInterface_DataAsset
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

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="🏷️Category") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="🏷️Tags") FGameplayTagContainer GameplayTags;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) FString CustomLabel;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="General",AdvancedDisplay) FGuid Guid;
	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists) override;
	
	OMACRO_ADDPARAMS_GENERAL();
	
	UFUNCTION(BlueprintNativeEvent,Category="Editor") bool UseIconAsThumbnail();

	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field) override;
	virtual void SetKey_Implementation(FLuaValue Key) override;
	virtual FLuaValue GetValue_Implementation(const FString& Field) override { return LuaData; };
	virtual FLuaValue GetKey_Implementation() override { return FLuaValue(LuaKey.ToString()); };
	
	virtual FLinearColor GetThumbnailBack_Tint_Implementation() override { return FLinearColor::Gray; };
	virtual FSlateBrush GetThumbnail_Brush_Implementation() override { return Icon;};
	virtual FText GetThumbnail_Text_Implementation() override { return DisplayName;};
	virtual UPrimaryDataAsset* GetDataAsset_Named_Implementation(FName name) override;
	virtual FColor GetThumbnail_Color_Implementation() override { return asset_color; };
};

UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaDemoDataAsset : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Demo Meta") FOmegaClassNamedLists NamedLists;
	virtual void GetMetaConfig_Implementation(FOmegaBitflagsBase& bitflags, FGuid& guid, int32& seed, FOmegaClassNamedLists& named_lists) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Demo Meta") FOmegaBitflagsBase Flags;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Demo Meta",AdvancedDisplay) FOmegaLuaCode LuaCode;
	
};
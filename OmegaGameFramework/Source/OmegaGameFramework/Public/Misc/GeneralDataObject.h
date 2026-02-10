// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "GameplayTagContainer.h"
#include "LuaInterface.h"
#include "Interfaces/I_ObjectTraits.h"
#include "Functions/F_SoftProperty.h"
#include "Interfaces/I_AssetThumbnail.h"
#include "Interfaces/I_BitFlag.h"
#include "Interfaces/I_DataAsset.h"
#include "Interfaces/I_NamedLists.h"
#include "Types/Struct_CustomNamedList.h"
#include "GeneralDataObject.generated.h"


#define OMACRO_ADDPARAMS_GENERAL() \
virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override \
{ Name=DisplayName; Description=DisplayDescription; }; \
virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override \
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

	//DataInterface

	//Texts
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralDataText(const FString& Label, const class UObject* Context, FText& Name, FText& Description);
	virtual void GetGeneralDataText_Implementation(const FString& Label, const class UObject* Context, FText& Name, FText& Description);

	//Images
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralDataImages(const FString& Label, const class UObject* Context, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush);
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const class UObject* Context, class UTexture2D*& Texture, class UMaterialInterface*& Material, FSlateBrush& Brush);

	//Color
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralAssetColor(FLinearColor& Color);
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color);

	//AssetLabel
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralAssetLabel(FString& Label);
	virtual void GetGeneralAssetLabel_Implementation(FString& Label);

};


UCLASS(Blueprintable,BlueprintType,Abstract,Const,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaInstancableObject : public UObject
{
	GENERATED_BODY()

public:
	
};
UCLASS(meta=(ShowWorldContextPin,DisallowCreateNew),EditInlineNew)
class OMEGAGAMEFRAMEWORK_API UOmegaDataAsset : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataInterface_AssetThumbnail,
																			public IDataInterface_GUID, public IDataInterface_Traits,
																			public IOmegaSoftPropertyInterface , public ILuaInterface, public IDataInterface_DataAsset,
																			public IDataInterface_NamedLists
{
	GENERATED_BODY()
public:
	UOmegaDataAsset();

	UPROPERTY() FLuaValue LuaData;
	UPROPERTY() FName LuaKey;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Icon") FSlateBrush Icon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Description") FText DisplayDescription;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General") FGameplayTagContainer GameplayTags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General") FOmegaBitflagsBase Flags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General") FOmegaClassNamedLists NamedLists;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) TArray<FName> Metatags;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="General",AdvancedDisplay) FGuid Guid;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) int32 AssetSeed=-1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) FString CustomLabel;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) TMap<FName,FString> ExtraParams;
	OMACRO_ADDPARAMS_GENERAL();
	
	virtual FGuid GetObjectGuid_Implementation() { return Guid; }
	virtual TMap<FName, FString> GetSoftPropertyMap_Implementation() override { return ExtraParams; };
	virtual FString GetSoftProperty_Implementation(FName Property) override;
	virtual TArray<FName> GetMetatags_Implementation() override;
	virtual FOmegaClassNamedLists GetClassNamedLists_Implementation() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,AdvancedDisplay,Category="General") TArray<UOmegaObjectTrait*> Traits;
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override { return Traits; };
	//virtual// void SetTraits_Implementation(TArray<UOmegaObjectTrait*> NewTraits) override{ Traits=NewTraits; };
	
	UFUNCTION(BlueprintNativeEvent,Category="Editor") bool UseIconAsThumbnail();

	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field) override;
	virtual void SetKey_Implementation(FLuaValue Key) override;
	virtual FLuaValue GetValue_Implementation(const FString& Field) override { return LuaData; };
	virtual FLuaValue GetKey_Implementation() override { return FLuaValue(LuaKey.ToString()); };
	
	virtual FLinearColor GetThumbnailBack_Tint_Implementation() override { return FLinearColor::Gray; };
	virtual FSlateBrush GetThumbnail_Brush_Implementation() override { return Icon;};
	virtual FText GetThumbnail_Text_Implementation() override { return DisplayName;};
	virtual UPrimaryDataAsset* GetDataAsset_Named_Implementation(FName name) override;
};
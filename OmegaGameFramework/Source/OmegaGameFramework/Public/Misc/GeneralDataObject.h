// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "GameplayTagContainer.h"
#include "LuaObject.h"
#include "Misc/OmegaAttribute.h"
#include "GeneralDataObject.generated.h"


#define OMACRO_ADDPARAMS_GENERAL() \
virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override \
{ Name=DisplayName; Description=DisplayDescription; }; \
virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override \
{ Brush=Icon; }; \
virtual void GetGeneralAssetLabel_Implementation(FString& Label) override { if(!CustomLabel.IsEmpty()) {Label=CustomLabel; return; } Label=GetName(); return; }; \
virtual FGameplayTag GetObjectGameplayCategory_Implementation() override { return CategoryTag; }; \
virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override { return  GameplayTags; }; \

#define OMACRO_INSTALL_QUEUEDQUERY() \
if(UOmegaSubsystem_QueuedQuery* REF_QuerySubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueuedQuery>()) \
{ \
	REF_QuerySubsystem->SetQueuedQuerySourceRegistered(this,true); \
} \







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


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLuaBaseObject : public ULuaObject, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly,Category="FieldNames") FString Param_AttributeMods="attributes";

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDataAsset : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",meta=(MultiLine),DisplayName="Icon") FSlateBrush Icon;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",meta=(MultiLine),DisplayName="Description") FText DisplayDescription;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General",AdvancedDisplay) FString CustomLabel;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="General") FGameplayTagContainer GameplayTags;
	OMACRO_ADDPARAMS_GENERAL();
	
public:

};
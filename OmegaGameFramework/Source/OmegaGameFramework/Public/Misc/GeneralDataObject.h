// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "GameplayTagContainer.h"
#include "LuaObject.h"
#include "Functions/OmegaFunctions_ObjectTraits.h"
#include "Interfaces/OmegaInterface_AssetThumbnail.h"
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


UCLASS(Blueprintable,BlueprintType,Abstract,Const,EditInlineNew,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaInstancableObject : public UObject
{
	GENERATED_BODY()

public:
	
};

UCLASS(meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaDataAsset : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface, public IDataInterface_AssetThumbnail,
																			public IDataInterface_GUID, public IDataInterface_ObjectHierarchy, public IDataInterface_Traits
{
	GENERATED_BODY()
public:
	UOmegaDataAsset();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Icon") FSlateBrush Icon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Description") FText DisplayDescription;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General") FGameplayTagContainer GameplayTags;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="General",AdvancedDisplay) FGuid Guid;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) FString CustomLabel;
	OMACRO_ADDPARAMS_GENERAL();
	
	virtual FGuid GetObjectGuid_Implementation() { return Guid; }

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="General",AdvancedDisplay) TArray<UOmegaObjectTrait*> Traits;
	virtual TArray<UOmegaObjectTrait*> GetTraits_Implementation() override { return Traits; };
	//virtual// void SetTraits_Implementation(TArray<UOmegaObjectTrait*> NewTraits) override{ Traits=NewTraits; };
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) UPrimaryDataAsset* ParentAsset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) TArray<UPrimaryDataAsset*> ChildAssets;

	virtual UObject* GetObject_Parent_Implementation() const override;
	virtual TArray<UObject*> GetObject_Children_Implementation() const override;
	
	UFUNCTION(BlueprintNativeEvent,Category="DataAsset") bool UseIconAsThumbnail();

	virtual FSlateBrush GetThumbnail_Brush_Implementation() override { return Icon;};
	virtual FText GetThumbnail_Text_Implementation() override { return DisplayName;};
};
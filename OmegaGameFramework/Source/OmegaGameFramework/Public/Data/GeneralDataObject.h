// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataInterface_General.h"

#include "GeneralDataObject.generated.h"

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
	UTexture2D* Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Data");
	FLinearColor Color;
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

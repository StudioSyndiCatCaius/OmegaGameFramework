// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Styling/SlateBrush.h"
#include "DataInterface_General.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDataInterface_General : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IDataInterface_General
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//Texts
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Texts"))
	void GetGeneralDataText
		(
			const FString& Label, const class UObject* Context, 
			FText& Name, 
			FText& Description
		);

	//Images
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(AdvancedDisplay="Context", CompactNodeTitle="General Images"))
		void GetGeneralDataImages
		(
			const FString& Label, const class UObject* Context,
			class UTexture2D*& Texture,
			class UMaterialInterface*& Material,
			FSlateBrush& Brush
		);

	//Color
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(CompactNodeTitle="Color"))
		void GetGeneralAssetColor
		(
			FLinearColor& Color
		);

	//AssetLabel
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General", meta=(CompactNodeTitle="General Label"))
		void GetGeneralAssetLabel
		(
			FString& Label
		);



};

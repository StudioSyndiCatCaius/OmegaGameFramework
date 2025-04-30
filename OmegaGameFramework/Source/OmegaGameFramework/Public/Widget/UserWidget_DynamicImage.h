// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "UserWidget_DynamicImage.generated.h"



UCLASS(Abstract)
class OMEGAGAMEFRAMEWORK_API UDynamicImage_Widget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativePreConstruct() override;
	//void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent,Category="DynamicImage")
	USizeBox* GetWidget_SizeBox();
	UFUNCTION(BlueprintImplementableEvent,Category="DynamicImage")
	UImage* GetWidget_Image();

	UPROPERTY(EditAnywhere,Category="DynamicImage") UTexture* ImageTexture;
	UPROPERTY(EditAnywhere,Category="DynamicImage") FName ImageParamName;
	UPROPERTY(EditAnywhere,Category="DynamicImage") UMaterialInterface* ImageMaterial;
	
	UPROPERTY(EditAnywhere,Category="DynamicImage") FVector2D Size_Default;
	UPROPERTY(EditAnywhere,Category="DynamicImage") FVector2D Size_Min;
	UPROPERTY(EditAnywhere,Category="DynamicImage") FVector2D Size_Max;
	
	UPROPERTY(EditAnywhere,Category="DynamicImage") TMap<FName,float> MaterialParams_scalar;
	UPROPERTY(EditAnywhere,Category="DynamicImage") TMap<FName,FLinearColor> MaterialParams_vector;
};

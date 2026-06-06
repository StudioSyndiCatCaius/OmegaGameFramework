// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "Types/Struct_Material.h"
#include "WG_DynamicImage.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UDynamicImage_Widget : public UImage
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicImage")
	UMaterialInterface* Material = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicImage")
	FOmegaDynamicMaterialParams MaterialParams;

	UFUNCTION(BlueprintCallable, Category="DynamicImage")
	void RefreshDynamicMaterial();

	virtual void SynchronizeProperties() override;
};

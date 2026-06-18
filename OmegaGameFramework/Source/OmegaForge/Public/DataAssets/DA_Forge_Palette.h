// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Forge_Palette.generated.h"

class UOmegaForgePlacable;

UCLASS()
class OMEGAFORGE_API UOmegaForgePallete : public UOmegaMinimalDataAsset
{
	GENERATED_BODY()
	
	public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Placables")
	TArray<UOmegaForgePlacable*> Placables_Literal;
};

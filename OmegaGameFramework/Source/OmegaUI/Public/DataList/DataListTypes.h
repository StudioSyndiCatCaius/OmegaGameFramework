// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterDataList.h"
#include "UObject/Object.h"
#include "DataListTypes.generated.h"


UCLASS(DisplayName="List Type (List)", CollapseCategories)
class OMEGAUI_API UDataListType_List : public UDataListType
{
	GENERATED_BODY()
};

UCLASS(DisplayName="List Type (Tree)", CollapseCategories)
class OMEGAUI_API UDataListType_Tree : public UDataListType
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="List")
	TEnumAsByte<EOrientation> Orientation;
	
	
};

UCLASS(DisplayName="List Type (Tile)", CollapseCategories)
class OMEGAUI_API UDataListType_Tile: public UDataListType
{
	GENERATED_BODY()
};

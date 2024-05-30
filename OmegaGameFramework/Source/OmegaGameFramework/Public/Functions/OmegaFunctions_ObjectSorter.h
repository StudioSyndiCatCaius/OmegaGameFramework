// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_ObjectSorter.generated.h"

UCLASS()
class UOmegaObjectSorterFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Omega|ObjectSorter", meta=(DeterminesOutputType=OutputClass, AdvancedDisplay="OutputClass"))
	static TArray<UObject*> SortObjectArray(TArray<UObject*> InObjects, UOmegaObjectSorterAsset* Sorter, TSubclassOf<UObject> OutputClass, UObject* Context=nullptr);
	
};

UCLASS(EditInlineNew, Blueprintable, BlueprintType, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaObjectSorterClass : public UObject
{
	GENERATED_BODY()

public:
	
	//Filters out unwanted objects before passing them into the Sorter
	UFUNCTION(BlueprintNativeEvent,Category="Omega|ObjectSorter")
	TArray<UObject*> FilterObjects(const TArray<UObject*>& InObjects, UObject* Context);

	
	//Test if the CheckedObject should be placed about ComparedObject in the output array.
	UFUNCTION(BlueprintImplementableEvent,Category="Omega|ObjectSorter")
	bool ShouldCheckedObjectSortFirst(UObject* CheckedObject, UObject* ComparedObject, UObject* Context);

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaObjectSorterAsset : public UPrimaryDataAsset, public IDataInterface_General
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category="Sorter", DisplayName="Name")
	FText SorterName;
	UPROPERTY(EditDefaultsOnly, Category="Sorter", DisplayName="Icon")
	FSlateBrush SorterIcon;
	UPROPERTY(EditDefaultsOnly, Category="Sorter", DisplayName="Description")
	FText SorterDescription;
	UPROPERTY(EditDefaultsOnly, Category="Sorter", DisplayName="Label")
	FString SorterLabel;
	
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Sorter", DisplayName="Name")
	UOmegaObjectSorterClass* SorterScript;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	                                               FText& Description) override
	{
		Name = SorterName;
		Description = SorterDescription;
	}

	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture,
	                                                 UMaterialInterface*& Material, FSlateBrush& Brush) override
	{
		Brush = SorterIcon;
	}

	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override
	{
		Label = SorterLabel;
	}
};

//------------------------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------------------------



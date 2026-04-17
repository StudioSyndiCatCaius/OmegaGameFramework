// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once
#include "Curves/CurveVector.h"
#include "Widget/DataWidget.h"


#include "script_dataWidgetTraits.generated.h"

UCLASS(DisplayName="💠 Widget Trait - General")
class OMEGADEMO_API UDataWidgetTrait_General : public UDataWidgetTraits
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Trait") UOmegaSlateStyle_Text* Style_Name;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Trait") UOmegaSlateStyle_Text* Style_Description;
	
	virtual void OnInit_Implementation(UDataWidget* Widget) const override;
};

UCLASS(DisplayName="💠 Widget Trait - Curve Offset")
class OMEGADEMO_API UDataWidgetTrait_CurveOffset : public UDataWidgetTraits
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "List")
	FRuntimeVectorCurve EntryLayoutCurve;
	
	virtual void OnAddedToList_Implementation(UDataWidget* Widget, UDataList* List, int32 index) const override;
};



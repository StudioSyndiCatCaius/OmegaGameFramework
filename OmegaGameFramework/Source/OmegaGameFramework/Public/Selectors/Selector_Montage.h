// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "Selector_Montage.generated.h"


UCLASS(Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaSelector_Montage : public UOmegaInstancableObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Selector")
	UAnimMontage* GetMontage(UObject* Context) const;
};


USTRUCT(BlueprintType)
struct FOmegaSelect_Montage
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Selector")
	UOmegaSelector_Montage* Selector=nullptr;
	
};




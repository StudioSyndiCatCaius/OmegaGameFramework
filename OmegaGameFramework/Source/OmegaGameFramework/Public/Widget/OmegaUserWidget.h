// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OmegaUserWidget.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//---------------------------------------------------------------------------------------------//
	//	State
	//---------------------------------------------------------------------------------------------//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OmegaWidget")
	TArray<UPrimaryDataAsset*> Traits;

	UFUNCTION(BlueprintCallable,Category="Traits")
	void SetTraitActive(UPrimaryDataAsset* Subscript, bool Active)
	{
		if(Active && !Traits.Contains(Subscript))
		{
			Traits.AddUnique(Subscript);
		}
		if(!Active && Traits.Contains(Subscript))
		{
			Traits.Remove(Subscript);
		}
	};
	
	UFUNCTION(BlueprintPure,Category="Traits")
	bool HasTrait(UPrimaryDataAsset* Subscript) const { return Traits.Contains(Subscript); }
	
	//---------------------------------------------------------------------------------------------//
	//	Tags
	//---------------------------------------------------------------------------------------------//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OmegaWidget")
	TArray<FName> WidgetTags;
	
	UFUNCTION(BlueprintCallable, Category="Tags")
	void SetWidgetTagActive(FName Tag, bool bActive)
	{
		if(bActive)
		{
			WidgetTags.AddUnique(Tag);
		}
		else
		{
			if(WidgetTags.Contains(Tag))
			{
				WidgetTags.Remove(Tag);
			}
		}
	};
	
	UFUNCTION(BlueprintPure, Category="Tags")
	bool WidgetHasTag(FName Tag) const
	{
		return WidgetTags.Contains(Tag);
	};

};

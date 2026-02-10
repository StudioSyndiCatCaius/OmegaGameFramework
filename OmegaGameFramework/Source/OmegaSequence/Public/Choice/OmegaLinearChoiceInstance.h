// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OmegaLinearChoice.h"
#include "Actors/Actor_ChoiceBase.h"
#include "Interfaces/I_BitFlag.h"
#include "Interfaces/I_NamedLists.h"
#include "Types/Struct_CustomNamedList.h"
#include "OmegaLinearChoiceInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChoiceSelected, UOmegaLinearChoice*, Choice, int32, SelectedChoice);

USTRUCT(BlueprintType)
struct FOmegaLinearChoices
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="LinearEvents", instanced, EditAnywhere)
	TArray<class UOmegaLinearChoice*> Choices;

	UPROPERTY() FOmegaBitflagsBase flags;
	UPROPERTY() FOmegaClassNamedLists NamedLists;
};

UCLASS()
class OMEGASEQUENCE_API AOmegaLinearChoiceInstance : public AOmegaActor_ChoiceBASE, public IDataInterface_BitFlag, public IDataInterface_NamedLists
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOmegaLinearChoices ChoiceData;
	
	UPROPERTY(BlueprintAssignable)
	FOnChoiceSelected OnChoiceSelected;
	
	UFUNCTION(BlueprintCallable, Category="LinearChoice")
	bool SelectChoice(int32 Index);

	UFUNCTION(BlueprintPure, Category="LinearChoice")
	TArray<UOmegaLinearChoice*> GetChoices();
	
	virtual FOmegaBitflagsBase Bitflags_Get_Implementation() override { return ChoiceData.flags; };
	virtual FOmegaClassNamedLists GetClassNamedLists_Implementation() override { return ChoiceData.NamedLists; };
};

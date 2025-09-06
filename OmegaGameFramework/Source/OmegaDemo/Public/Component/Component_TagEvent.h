// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Functions/OmegaFunctions_TagEvent.h"
#include "Component_TagEvent.generated.h"


class UOmegaSaveGame;

UCLASS(ClassGroup=("TagEvent"),Abstract)
class OMEGADEMO_API UComponent_TagEvent : public UActorComponent, public IActorTagEventInterface
{
	GENERATED_BODY()

public:

	UOmegaSaveGame* L_GetSave() const;
	bool L_SaveBool_Get(const FString& name) const;
	void L_SaveBool_Set(const FString& name, bool val) const;
	//virtual void OnTagEvent_Implementation(FGameplayTag Event) override;
};
/*

//Destroys this actor when a tag event is triggered
UCLASS(meta=(BlueprintSpawnableComponent))
class OMEGADEMO_API UTagEventComponent_Destroy : public UComponent_TagEvent
{
	GENERATED_BODY()

	const FString var_nam="_dead";

public:
	virtual void BeginPlay() override;
	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;

	
	//Tag Event to trigger destruction
	UPROPERTY(EditAnywhere,Category="TagEvent")
	FGameplayTag TagEvent;
	
	UPROPERTY(EditAnywhere,Category="TagEvent")
	bool SaveState;

};
*/
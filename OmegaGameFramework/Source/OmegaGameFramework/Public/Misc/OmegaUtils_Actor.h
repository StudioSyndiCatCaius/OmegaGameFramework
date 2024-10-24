// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OmegaUtils_Actor.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaActorSelectorData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Instanced,Category="Actor Selector")
	UOmegaActorSelector* Selector;
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorUtilFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="Actor Selector", meta=(WorldContext="WorldContextObject"))
	static AActor* GetSelectedActor(UObject* WorldContextObject, FOmegaActorSelectorData selectorData);
	
	UFUNCTION(BlueprintCallable,Category="Actor Selector", meta=(WorldContext="WorldContextObject"))
    static TArray<AActor*> GetSelectedActors(UObject* WorldContextObject, FOmegaActorSelectorData selectorData);
};

UCLASS(Blueprintable,EditInlineNew,Abstract,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaActorSelector : public UObject
{
	GENERATED_BODY()

	virtual UWorld* GetWorld() const override;
	UFUNCTION() virtual UGameInstance* GetGameInstance() const;
	
	UOmegaActorSelector(const FObjectInitializer& ObjectInitializer);
	UPROPERTY(Transient) UWorld* WorldPrivate = nullptr;
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Actor Selector")
	TArray<AActor*> GetActors();
	
	UFUNCTION() AActor* Private_GetActor(UWorld* WorldContext);
	
	UFUNCTION() TArray<AActor*> Private_GetActorList(UWorld* WorldContext);
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "GameplayTagContainer.h"
#include "JsonObjectWrapper.h"
#include "Components/ActorComponent.h"
#include "SubscriptComponent.generated.h"


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API USubscriptComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//USubscriptComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Default")
	TArray<USubscript*> Subscripts;

	UPROPERTY(BlueprintReadWrite, Category="Default")
	FJsonObjectWrapper SubscriptData;

	
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, Abstract, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API USubscript : public UObject
{
	GENERATED_BODY()

public:	

	USubscript();
	
	UPROPERTY()
	USubscriptComponent* OwnerComp = nullptr;
	
	UFUNCTION(BlueprintPure, Category="Subscript")
	AActor* GetOwningActor() const;

	UFUNCTION(BlueprintPure, Category="Subscript")
	USubscriptComponent* GetOwningComponent() const;

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnBeginPlay() const;

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnEndPlay() const;

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void Tick(float Delta) const;
	
};
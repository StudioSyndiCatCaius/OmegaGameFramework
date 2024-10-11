// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "GameplayTagContainer.h"
#include "JsonObjectWrapper.h"
#include "LuaValue.h"
#include "Components/ActorComponent.h"
#include "Component_Subscript.generated.h"


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API USubscriptComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY() TMap<FName,FVector> param_data;

public:
	// Sets default values for this component's properties
	USubscriptComponent();

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

	// Params
	UFUNCTION(BlueprintCallable,Category="Subscript|Params") void SetSubscriptParam_Float(FName Param, float value);
	UFUNCTION(BlueprintCallable,Category="Subscript|Params") float GetSubscriptParam_Float(FName Param);

	UFUNCTION(BlueprintCallable,Category="Subscript|Params") void SetSubscriptParam_Int32(FName Param, int32 value);
	UFUNCTION(BlueprintCallable,Category="Subscript|Params") int32 GetSubscriptParam_Int32(FName Param);

	UFUNCTION(BlueprintCallable,Category="Subscript|Params") void SetSubscriptParam_Bool(FName Param, bool value);
	UFUNCTION(BlueprintCallable,Category="Subscript|Params") bool GetSubscriptParam_Bool(FName Param);
};

UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, Abstract, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API USubscript : public UObject
{
	GENERATED_BODY()

public:	

	USubscript();
	
	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnBeginPlay(USubscriptComponent* OwningComponent) const;

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void OnEndPlay(USubscriptComponent* OwningComponent) const;

	UFUNCTION(BlueprintNativeEvent, Category="Subscript")
	void Tick(float Delta,USubscriptComponent* OwningComponent) const;
	
};
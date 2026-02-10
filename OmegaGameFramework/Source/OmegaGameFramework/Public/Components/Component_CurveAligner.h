// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveVector.h"
#include "Component_CurveAligner.generated.h"

class UOmegaSaveSubsystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCurveAligner_ActorRegister, UCurveAlignerComponent*, Component, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCurveAligner_ActorUnregister, UCurveAlignerComponent*, Component, AActor*, Actor);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UCurveAlignerComponent : public USceneComponent
{
	GENERATED_BODY()

	TArray<AActor*> CleanArray() const;

public:
	UCurveAlignerComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(VisibleInstanceOnly,Category="CurveAligner") TArray<AActor*> REF_Actors;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") UCurveVector* Offset_Curve;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") float Offset_InterpTime=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") FVector Offset_Scale=FVector::One();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") UCurveVector* Rotate_Curve;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") float Rotate_InterpTime=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") FVector Rotate_Scale=FVector::One();
	
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") FGameplayTagContainer TagEvents_OnRegister;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CurveAligner") FGameplayTagContainer TagEvents_OnUnRegister;

	UPROPERTY(BlueprintAssignable) FCurveAligner_ActorRegister OnActorRegistered;
	UPROPERTY(BlueprintAssignable) FCurveAligner_ActorUnregister OnActorUnregistered;

	UFUNCTION(BlueprintCallable,Category="Actors")
	void SetActorRegistered(AActor* Actor, bool is_registered);
	
	UFUNCTION(BlueprintCallable,Category="Actors")
	void SetActorsRegistered(TArray<AActor*> Actors, bool is_registered);
protected:

	
public:

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UGridManagerComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGridManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Manager")
	int32 X;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Manager")
	int32 Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Manager")
	int32 Z;

	UPROPERTY(BlueprintReadOnly, Category="Grid Manager")
	TArray<FIntVector> Coords;

	UPROPERTY(EditAnywhere, Category="Grid Manager")
	TSubclassOf<AActor> GridTileClass;
	
	UFUNCTION(BlueprintCallable, Category="Grid Manager")
	bool BuildGrid();
};

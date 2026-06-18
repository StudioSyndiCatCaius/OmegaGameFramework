// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structs/Struct_LevelData.h"
#include "comp_LevelEditor.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAFORGE_API UOmegaForgeComponent_LevelEditor : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	UOmegaForgeComponent_LevelEditor();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY() FOmegaForge_LevelData Level_Data;
	
	UPROPERTY() TArray<AActor*> Level_Actors;
	
	
	UFUNCTION(BlueprintCallable,Category="LevelEditor")
	void CustomLevel_Load(FOmegaForge_LevelData LevelData);
	
	
	UFUNCTION(BlueprintCallable,Category="LevelEditor")
	void CustomLevel_Save(FOmegaForge_LevelData LevelData);
	
	UFUNCTION(BlueprintCallable,Category="LevelEditor")
	void CustomLevel_Unload(FOmegaForge_LevelData LevelData);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "Actor_Tool.generated.h"

class AOmegaGameplayCue;
class USkeletalMeshComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaToolActor : public AActor
{
	GENERATED_BODY()
	
	float f_recoilDur;
	bool b_isActive;
	
protected:
	AOmegaToolActor();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
public:
	
	//Time between Triggers during activation State
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🗡️Tool") float RecoilTile=0.1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="🗡️Tool") FName SkeletalMeshTag="ToolHolder";
	
	UFUNCTION(BlueprintPure,Category="Omega Tool") USkeletalMeshComponent* GetToolOwnerSkeletalMesh();
	
	UFUNCTION(BlueprintCallable,Category="Omega Tool") bool SetToolActive(bool bActive);
	UFUNCTION(BlueprintPure,Category="Omega Tool") bool IsToolActive() const { return b_isActive; };
	
	UFUNCTION(BlueprintImplementableEvent,Category="Omega Tool",DisplayName="On Tool Activate") void K2_OnActivate(bool bActivated);
	UFUNCTION(BlueprintImplementableEvent,Category="Omega Tool",DisplayName="On Tool Trigger") void K2_OnTrigger();
	UFUNCTION(BlueprintImplementableEvent,Category="Omega Tool",DisplayName="On Active Tick") void K2_ActiveTick(float DeltaTime);
};

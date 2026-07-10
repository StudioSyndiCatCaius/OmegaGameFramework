// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Environment.h"
#include "Misc/GeneralDataObject.h"
#include "DA_DemoEnvironment.generated.h"

// An environemnt class with minimal variables to be both easier to edit AND far cheaper on performance 
UCLASS(DisplayName="♎Demo - Environment (Easy)")
class OMEGADEMO_API UOAsset_EasyEnvironment : public UOmegaMinimalDataAsset, public IDataInterface_Environment
{
	GENERATED_BODY()
public:
	UOAsset_EasyEnvironment();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sun") FLinearColor SunColor=FLinearColor(1,1,1);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sun") float SunIntensity=5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sun") FRotator SunRotation=FRotator(0,0,0);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sky",AdvancedDisplay) TObjectPtr<UStaticMesh> SkyMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sky") TObjectPtr<UMaterialInterface> SkyMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sky") FLinearColor SkyColor=FLinearColor(0.2,0.2,0.2);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sky") float SkyIntensity=1.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sky") FLinearColor FogColor=FLinearColor(1,1,1,1);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sky") float FogDensity=0.02;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sky") float FogFalloff=0.3;
	
	virtual FOmegaEnvironmentConfig Environment_GetConfig_Implementation(AOmegaActorEnvironment* Actor) override;
	virtual int32 Environment_OnInit_Implementation(AOmegaActorEnvironment* Actor) override;
};

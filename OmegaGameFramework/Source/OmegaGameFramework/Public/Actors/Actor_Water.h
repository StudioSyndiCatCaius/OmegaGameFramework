// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Combatant.h"
#include "Components/PostProcessComponent.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Functions/OmegaFunctions_ScriptedEffects.h"
#include "GameFramework/Actor.h"
#include "Actor_Water.generated.h"

class UOmegaScriptedEffect;
class UBoxComponent;
class UPostProcessComponent;
class USplineMeshComponent;
class USplineComponent;

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaWater_Config
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Water")
	float Depth=100;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaWater_Style : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UMaterialInterface* Material_Plane;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UMaterialInterface* Material_River;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	FPostProcessSettings PostProcessSettings;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
	TArray<UOmegaWater_Style*> Inherited_Effects;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
    FActorModifiers ActorModifiers_OnOverlap;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Effects")
	FActorModifiers ActorModifiers_OnUnOverlap;
	
	void ApplyTo_Component(UPrimitiveComponent* comp, uint8 type,UPostProcessComponent* pp)
	{
		if(comp)
		{
			UMaterialInterface* _inMat = nullptr;
			if(type==0) { _inMat=Material_Plane; }
			if(type==1) { _inMat=Material_River; }
			if(_inMat)
			{
				comp->SetMaterial(0,_inMat);
			}
			if(pp)
			{
				pp->Settings=PostProcessSettings;
			}
		}
	}
	
	void OnOverlap_Start(AActor* OverlapTarget)
	{
		if(OverlapTarget)
		{
			ActorModifiers_OnOverlap.ApplyMods(OverlapTarget);
			for(auto* i : Inherited_Effects)
			{
				if(i) { i->OnOverlap_Start(OverlapTarget); }
			}
		}
	}
	
	void OnOverlap_End(AActor* OverlapTarget)
	{
		if(OverlapTarget)
		{
			ActorModifiers_OnUnOverlap.ApplyMods(OverlapTarget);
			for(auto* i : Inherited_Effects)
			{
				if(i) { i->OnOverlap_End(OverlapTarget); }
			}
		}
	}
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaWater_Plane : public AActor
{
	GENERATED_BODY()

public:
	AOmegaWater_Plane();
	
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* Mesh;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UStaticMeshComponent* Mesh_Surface;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UPostProcessComponent* PostProcess;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UBoxComponent* PostProcess_Range;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UOmegaWater_Style* Style;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	FOmegaWater_Config Config;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,AdvancedDisplay,Category="Water",meta=(MakeEditWidget))
	FVector Depth=FVector(0,0,-100);
	UPROPERTY(VisibleInstanceOnly,BlueprintReadOnly,Category="Water")
	TArray<AActor*> OverlappedActors;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaWater_River : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY() TArray<USplineMeshComponent*> RiverMeshes;
	
	AOmegaWater_River();
	
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") USplineComponent* Spline;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UPostProcessComponent* PostProcess;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Water")
	UOmegaWater_Style* Style;
};

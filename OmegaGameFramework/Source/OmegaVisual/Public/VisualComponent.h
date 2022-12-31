// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/MeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "VisualComponent.generated.h"

class UMeshComponent;

UCLASS(Abstract, Blueprintable)
class OMEGAVISUAL_API UVisualComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UVisualComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Mesh")
	void ClearDynamicMaterials();
	
	UFUNCTION(BlueprintCallable, Category="Mesh")
	void RegisterMesh(UMeshComponent* Mesh, bool ClearMaterialsFirst);

	UPROPERTY()
	TArray<UMaterialInstanceDynamic*> Local_DynaMats;
	
	UFUNCTION(BlueprintPure, Category="Mesh")
	const TArray<UMaterialInstanceDynamic*> GetRegisteredDynamicMaterials();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Mesh")
	void OnMeshRegistered(UMeshComponent* MeshComponent);

	
};

inline void UVisualComponent::ClearDynamicMaterials()
{
	Local_DynaMats.Empty();
}

inline void UVisualComponent::RegisterMesh(UMeshComponent* Mesh, bool ClearMaterialsFirst)
{
	if(ClearMaterialsFirst)
	{
		ClearDynamicMaterials();
	}
	
	if(Mesh)
	{
		for (int i = 0; i < (Mesh->GetMaterials().Num()-1); ++i)
		{
			UMaterialInstanceDynamic* TempMatInst = Mesh->CreateDynamicMaterialInstance(i);
			Local_DynaMats.Add(TempMatInst);
		}
		OnMeshRegistered(Mesh);
	}
}

inline const TArray<UMaterialInstanceDynamic*> UVisualComponent::GetRegisteredDynamicMaterials()
{
	
	return Local_DynaMats;
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Subsystems/Subsystem_Actors.h"
#include "Component_Interactable.generated.h"

class AOmegaGameplaySystem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOmegaComponent_Interactable_Delegate,UOmegaComponent_Interactable*,Component);

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaComponent_Interactable : public UActorComponent, public IActorInterface_Interactable
{
	GENERATED_BODY()
	
	TSubclassOf<AOmegaGameplaySystem> GetContext_System(FGameplayTag Tag) const;
	
	UFUNCTION() void OnInteractSystemEnded(UObject* Context, FString Flag);
	
public:
	UOmegaComponent_Interactable();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable) FOmegaComponent_Interactable_Delegate OnInteractionBegin;
	UPROPERTY(BlueprintAssignable) FOmegaComponent_Interactable_Delegate OnInteractionEnd;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Interactable") TSubclassOf<AOmegaGameplaySystem> OverrideSystem;

	virtual void OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag, FOmegaCommonMeta Context) override;
};

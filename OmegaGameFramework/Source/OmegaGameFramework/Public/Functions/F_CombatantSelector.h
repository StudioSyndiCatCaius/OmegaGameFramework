// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_CombatantSelector.generated.h"

class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatantSelectorEvent,UCombatantSelector*, Selector);

UCLASS(Blueprintable,BlueprintType,Abstract,CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UCombatantSelector : public UObject
{
	GENERATED_BODY()
	bool b_blocktargetUpdate=false;
	
	void L_UpdateTargets();

public:
	
	UPROPERTY(BlueprintAssignable) FOnCombatantSelectorEvent OnSelector_TargetsUpdated;
	UPROPERTY(BlueprintAssignable) FOnCombatantSelectorEvent OnSelector_Finalized;
	UPROPERTY(BlueprintAssignable) FOnCombatantSelectorEvent OnSelector_Cancelled;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Selector") UCombatantComponent* Instigator;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Selector") TArray<UCombatantComponent*> InputTargets;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Selector") TArray<UCombatantComponent*> ActiveTargets;

	UFUNCTION(BlueprintCallable,Category="Selector")
	void SetSelectorTargetActive(UCombatantComponent* Target, bool bActive);
	
	UFUNCTION(BlueprintCallable,Category="Selector")
	void SetSelectorTargetsActive(TArray<UCombatantComponent*> Targets, bool bActive);
	
	UFUNCTION(BlueprintCallable,Category="Selector")
	void Refresh();
	
	UFUNCTION(BlueprintCallable,Category="Selector")
	void SelectorEvent(FGameplayTag Event);
	
	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	void OnSelectorEvent(FGameplayTag Event);
	
	UFUNCTION(BlueprintCallable,Category="Selector")
	void FinalizeAndComplete();
	
	UFUNCTION(BlueprintCallable,Category="Selector")
	void CancelSelector();
	
	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	void OnSelectorBegin();
	
	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	void OnSelectorCancelled();
	
	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	TArray<UCombatantComponent*> OnFinalizeTargets(const TArray<UCombatantComponent*> & Targets) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Selector")
	bool IsTargetValid(UCombatantComponent* Target) const;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_CombatantSelector : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaCombatantSelectorAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable) FOnCombatantSelectorEvent TargetsUpdated;
	UPROPERTY(BlueprintAssignable) FOnCombatantSelectorEvent Finalized;
	UPROPERTY(BlueprintAssignable) FOnCombatantSelectorEvent Cancelled;

	UPROPERTY() UCombatantSelector* LocalSelector;
	UPROPERTY() UCombatantComponent* LocalInstigator;
	UPROPERTY() TArray<UCombatantComponent*> LocalInputTargets;
	UPROPERTY() TSubclassOf<UCombatantSelector> LocalSelectorClass;

	UFUNCTION() void Local_TargetsUpdated(UCombatantSelector* Selector);
	UFUNCTION() void Local_Finalized(UCombatantSelector* Selector);
	UFUNCTION() void Local_Cancelled(UCombatantSelector* Selector);

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly), Category="Omega|AsyncGameplayTasks",DisplayName="Ω🔷 Run Combatant Selector")
	static UOmegaCombatantSelectorAsync* RunCombatantSelector(TSubclassOf<UCombatantSelector> Selector,
		UCombatantComponent* Instigator, TArray<UCombatantComponent*> InputTargets);
};

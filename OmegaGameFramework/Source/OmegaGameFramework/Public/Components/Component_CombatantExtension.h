// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/Component_Combatant.h"
#include "Interfaces/I_Skill.h"
#include "Interfaces/I_Combatant.h"
#include "Component_CombatantExtension.generated.h"


UCLASS( ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, Abstract)
class OMEGAGAMEFRAMEWORK_API UCombatantExtensionComponent : public UActorComponent, public IDataInterface_AttributeModifier, public  IDataInterface_DamageModifier, public IDataInterface_SkillSource
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatantExtensionComponent();

protected:
	// Called when the game starts
	
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category="Combatant")
	bool bIsAttributeModifier;
	UPROPERTY(EditDefaultsOnly, Category="Combatant")
	bool bIsDamageModifier;
	UPROPERTY(EditDefaultsOnly, Category="Combatant")
	bool bIsSkillSource;
	
	UPROPERTY(BlueprintReadOnly, Category="Combatant", DisplayName="Combatant")
	UCombatantComponent* CombatantRef = nullptr;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCombatantSetup(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintCallable,Category="Combatant")
	void SetCombatant(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintCallable,Category="Combatant")
	void ClearCombatant();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnAttributeDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnCombatantNotify(UCombatantComponent* OwningCombatant, FName Notify, const FString& Flag);
};

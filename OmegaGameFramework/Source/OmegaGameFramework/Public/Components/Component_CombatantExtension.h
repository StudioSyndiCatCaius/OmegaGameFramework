// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/Component_Combatant.h"
#include "Interfaces/I_Skill.h"
#include "Interfaces/I_Combatant.h"
#include "Component_CombatantExtension.generated.h"


// Abstract base for modular combatant extensions. Attach alongside UCombatantComponent to add attribute, damage, or skill modifiers without subclassing.
UCLASS( ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, Abstract)
class OMEGAGAMEFRAMEWORK_API UCombatantExtensionComponent : public UActorComponent, public IDataInterface_Combatant
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

	// When true, this component registers itself as an attribute modifier source on the linked combatant.
	UPROPERTY(EditDefaultsOnly, Category="Combatant")
	bool bIsAttributeModifier;
	// When true, this component registers itself as a damage modifier source on the linked combatant.
	UPROPERTY(EditDefaultsOnly, Category="Combatant")
	bool bIsDamageModifier;
	// When true, this component registers itself as a skill source on the linked combatant.
	UPROPERTY(EditDefaultsOnly, Category="Combatant")
	bool bIsSkillSource;

	// The combatant this extension is currently linked to.
	UPROPERTY(BlueprintReadOnly, Category="Combatant", DisplayName="Combatant")
	UCombatantComponent* CombatantRef = nullptr;

	// Called once when this extension is linked to a combatant, useful for initial setup.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega")
	void OnCombatantSetup(UCombatantComponent* Combatant);

	// Links this extension to the given combatant, registering it as a modifier/skill source as configured.
	UFUNCTION(BlueprintCallable,Category="Combatant")
	void SetCombatant(UCombatantComponent* Combatant);

	// Unlinks this extension from its current combatant and deregisters it as a source.
	UFUNCTION(BlueprintCallable,Category="Combatant")
	void ClearCombatant();

	// Called when the linked combatant takes attribute damage.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega")
	void OnAttributeDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit);

	// Called when the linked combatant receives a named notify.
	UFUNCTION(BlueprintImplementableEvent, Category="Omega")
	void OnCombatantNotify(UCombatantComponent* OwningCombatant, FName Notify, const FString& Flag);
};

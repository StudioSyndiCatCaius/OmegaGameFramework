// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_ActorIdentity.h"
#include "Functions/OmegaFunctions_Actor.h"
#include "Functions/OmegaFunctions_Combatant.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Misc/GeneralDataObject.h"
#include "Types/Struct_CombatantSource.h"
#include "DA_ActorIdentity.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOAsset_ActorIdentity : public UOmegaDataAsset, public IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()
public:
	virtual bool OnIdentityInit_Implementation(AActor* Actor, UActorIdentityComponent* Component) override;
	virtual bool OnActorConstruction_Implementation(AActor* Actor, UActorIdentityComponent* Component) override;
	virtual bool OnActorBeginPlay_Implementation(AActor* Actor, UActorIdentityComponent* Component) override;
	virtual bool OnActorTagEvent_Implementation(AActor* Actor, UActorIdentityComponent* Component, FGameplayTag Event) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") FOmegaActorModifierSet Mods_Init;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") FOmegaActorModifierSet Mods_Construct;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") FOmegaActorModifierSet Mods_BeginPlay;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") TMap<FGameplayTag,FOmegaActorModifierSet> Mods_TagEvent;
	
};

inline bool UOAsset_ActorIdentity::OnIdentityInit_Implementation(AActor* Actor, UActorIdentityComponent* Component)
{
	if(Actor) { return Mods_Init.Apply(Actor); } return false;
}

inline bool UOAsset_ActorIdentity::OnActorConstruction_Implementation(AActor* Actor, UActorIdentityComponent* Component)
{
	if(Actor) { return Mods_Construct.Apply(Actor); } return false;
}

inline bool UOAsset_ActorIdentity::OnActorBeginPlay_Implementation(AActor* Actor, UActorIdentityComponent* Component)
{
	if(Actor) { return Mods_BeginPlay.Apply(Actor); } return false;
}

inline bool UOAsset_ActorIdentity::OnActorTagEvent_Implementation(AActor* Actor, UActorIdentityComponent* Component,
	FGameplayTag Event)
{
	if(Actor && Mods_TagEvent.Contains(Event)) { return Mods_TagEvent[Event].Apply(Actor); } return false;
}

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOAsset_CombatantIdentity : public UOAsset_ActorIdentity, public IDataInterface_SkillSource, public IDataInterface_AttributeModifier, public IDataInterface_DamageModifier
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat",DisplayName="Combat Sources") FOmegaCombatantSources Sources;
	
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override; 
};

inline TArray<FOmegaAttributeModifier> UOAsset_CombatantIdentity::GetModifierValues_Implementation(
	UCombatantComponent* CombatantComponent)
{
	return Sources.GetAttributeMods(CombatantComponent);
}

inline float UOAsset_CombatantIdentity::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UObject* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	return Sources.GetDamageMods(Attribute,Target,Instigator,BaseDamage,DamageType,Context);
}

inline TArray<UPrimaryDataAsset*> UOAsset_CombatantIdentity::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	return Sources.GetSkills(Combatant);
}

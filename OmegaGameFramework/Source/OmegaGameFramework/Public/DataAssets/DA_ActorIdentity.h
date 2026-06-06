// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_GameplayActor.h"
#include "Functions/F_Actor.h"
#include "Functions/F_Combatant.h"
#include "Interfaces/I_Combatant.h"
#include "Misc/GeneralDataObject.h"
#include "DA_ActorIdentity.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOAsset_ActorIdentity : public UOmegaDataAsset, public IDataInterface_ActorIdentitySource
{
	GENERATED_BODY()
public:
	virtual bool OnIdentityInit_Implementation(AActor* Actor, UGameplayActorComponent* Component) override;
	virtual bool OnActorConstruction_Implementation(AActor* Actor, UGameplayActorComponent* Component) override;
	virtual bool OnActorBeginPlay_Implementation(AActor* Actor, UGameplayActorComponent* Component) override;
	virtual bool OnActorTagEvent_Implementation(AActor* Actor, UGameplayActorComponent* Component, FGameplayTag Event) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") FActorModifiers Mods_Init;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") FActorModifiers Mods_Construct;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") FActorModifiers Mods_BeginPlay;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor") TMap<FGameplayTag,FActorModifiers> Mods_TagEvent;
	
};

inline bool UOAsset_ActorIdentity::OnIdentityInit_Implementation(AActor* Actor, UGameplayActorComponent* Component)
{
	if(Actor) { Mods_Init.ApplyMods(Actor); } return false;
}

inline bool UOAsset_ActorIdentity::OnActorConstruction_Implementation(AActor* Actor, UGameplayActorComponent* Component)
{
	if(Actor) { Mods_Construct.ApplyMods(Actor); } return false;
}

inline bool UOAsset_ActorIdentity::OnActorBeginPlay_Implementation(AActor* Actor, UGameplayActorComponent* Component)
{
	if(Actor) { Mods_BeginPlay.ApplyMods(Actor); } return false;
}

inline bool UOAsset_ActorIdentity::OnActorTagEvent_Implementation(AActor* Actor, UGameplayActorComponent* Component,
	FGameplayTag Event)
{
	if(Actor && Mods_TagEvent.Contains(Event)) { Mods_TagEvent[Event].ApplyMods(Actor); } return false;
}

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOAsset_CombatantIdentity : public UOAsset_ActorIdentity, public IDataInterface_Combatant
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant", meta=(ShowOnlyInnerProperties))
	FOmegaScripted_CombatantModifiers Modifiers;
	virtual FOmegaScripted_CombatantModifiers Combatant_GetScriptedModifiers_Implementation() override { return Modifiers; };
};


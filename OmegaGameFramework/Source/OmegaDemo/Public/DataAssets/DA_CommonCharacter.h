// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Components/Component_ActorIdentity.h"
#include "DataAssets/DA_AssetLib.h"
#include "DataAssets/DA_CombatSource.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Interfaces/OmegaInterface_Skill.h"

#include "Misc/GeneralDataObject.h"
#include "DA_CommonCharacter.generated.h"

class AOmegaSkin;
class UOmegaFaction;
class UEquipmentSlot;

UCLASS(Blueprintable, BlueprintType)
class OMEGADEMO_API UOAsset_CommonCharacter : public UOAsset_CombatSource, public IDataInterface_FlowAsset,
											public IDataInterface_ActorIdentitySource, public IDataInterface_ContextSlate	
																		
{
	GENERATED_BODY()
public:

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Icon")
	TMap<FGameplayTag,FSlateBrush> TaggedIcon;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Flags")
	bool Auto_SetCombatantSource;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	FComponentMod_SkeletalMesh Mesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	UOmegaAssetLibrary_Sound* Library_Sound;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	UOmegaAssetLibrary_Animation* Library_Animation;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Character")
	UFlowAsset* FlowAsset;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	int32 Level=1;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	TMap<UOmegaAttribute*,float> Attribute_Overrides;

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadOnly,Category="Character")
	TArray<UActorModifierScript*> ActorModifiers_OnInit;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character")
	TMap<FGameplayTag,FActorModifiers> ActorModifiers_OnTagEvent;
	
	// Function
	virtual FSlateBrush GetContextAV_SlateBrush_Implementation(FGameplayTag ID) override
	{
		if(TaggedIcon.Contains(ID)) { return TaggedIcon[ID]; } return  FSlateBrush();	
	}
	
	virtual UFlowAsset* GetFlowAsset_Implementation(FGameplayTag Tag) override {return FlowAsset;};
	virtual bool OnIdentityInit_Implementation(AActor* Actor, UActorIdentityComponent* Component) override;
	virtual bool OnActorTagEvent_Implementation(AActor* Actor, UActorIdentityComponent* Component, FGameplayTag Event) override;
};

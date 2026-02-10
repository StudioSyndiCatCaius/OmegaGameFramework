// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonCharacter.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Assets.h"
#include "Functions/F_Assets.h"
#include "Actors/Actor_Character.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Combatant.h"
#include "GameFramework/Character.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"


class UOmegaSettings;

void UOAsset_CommonCharacter::L_Init(AActor* a, bool init)
{
	if(a)
	{
		
		if(ULevelingComponent* c=Cast<ULevelingComponent>(a->GetComponentByClass(ULevelingComponent::StaticClass())))
		{
			
		}
		if(UCombatantComponent* c=Cast<UCombatantComponent>(a->GetComponentByClass(UCombatantComponent::StaticClass())))
		{
			
		}
		if(UEquipmentComponent* c=Cast<UEquipmentComponent>(a->GetComponentByClass(UEquipmentComponent::StaticClass())))
		{
			
		}
		if(UDataAssetCollectionComponent* c=Cast<UDataAssetCollectionComponent>(a->GetComponentByClass(UDataAssetCollectionComponent::StaticClass())))
		{
			
		}
	}
}

TArray<FName> UOAsset_CommonCharacter::opts_attributes() const
{
	OGF_NAMED_ASSET_LIST(Named_Attributes)
}

TArray<FName> UOAsset_CommonCharacter::opts_equipSlot() const
{
	OGF_NAMED_ASSET_LIST(Named_EquipSlots)
}


bool UOAsset_CommonCharacter::OnIdentityInit_Implementation(AActor* Actor, UActorIdentityComponent* Component)
{
	if(ACharacter* c=Cast<ACharacter>(Actor))
	{
		if(Appearance_Preset) { Appearance_Preset->Apply(c); }
		else if(Appearance_Custom) { Appearance_Custom->Apply(c); }
	}
	if(AOmegaBaseCharacter* c=Cast<AOmegaBaseCharacter>(Actor))
	{
		if(AssetSeed>-1)
		{
			c->Seed=AssetSeed;
		}
	}
	L_Init(Actor,true);
	return false;
}

bool UOAsset_CommonCharacter::OnIdentityUninit_Implementation(AActor* Actor, UActorIdentityComponent* Component)
{
	L_Init(Actor,false);
	return true;
}

TArray<UPrimaryDataAsset*> UOAsset_CommonCharacter::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	return Skills;
}

TMap<UEquipmentSlot*, UPrimaryDataAsset*> UOAsset_CommonCharacter::GetEquipment_Implementation()
{
	return UOmegaFunctions_Asset::ConvNamed_Equipment(Equipment);
}


UOAsset_Appearance* UOAsset_CommonCharacter::GetAppearanceAsset_Implementation()
{
	return GetAppearance();
}

void UOAsset_CommonCharacter::SetValue_Implementation(FLuaValue Value, const FString& Field)
{
	Super::SetValue_Implementation(Value, Field);
	
}

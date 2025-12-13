// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonCharacter.h"

#include "OmegaDemo_Functions.h"
#include "OmegaSettings_Assets.h"
#include "Actors/Actor_Character.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Combatant.h"
#include "GameFramework/Character.h"
#include "Misc/OmegaUtils_Methods.h"


void UOAsset_CommonCharacter::L_Init(AActor* a, bool init)
{
	if(a)
	{
		UOmegaSettings_Assets* set=UOmegaSettings_AssetsFunctions::GetCurrentAssetSettings();
		
		if(ULevelingComponent* c=Cast<ULevelingComponent>(a->GetComponentByClass(ULevelingComponent::StaticClass())))
		{
			if(Autoset_Level) { c->SetLevel(Level); }
		}
		if(UCombatantComponent* c=Cast<UCombatantComponent>(a->GetComponentByClass(UCombatantComponent::StaticClass())))
		{
			if(AutoSet_Combatant)
			{
				//c->OverrideMaxAttributes=OGF_Assets::NamedAttributes_ToFloat(Attribute_Overrides);
				c->SetMasterDataSourceActive(this,init);
				if(init)
				{
					if(Gambit) { c->DefaultGambit;}
					c->DamageTypeReactions=DamageReactions;
				}
			}
		}
		if(UEquipmentComponent* c=Cast<UEquipmentComponent>(a->GetComponentByClass(UEquipmentComponent::StaticClass())))
		{
			if(AutoSet_Equipment)
			{
				if(Equipment_AsSource)
				{
					if(init)
					{
						c->Sources.AddUnique(this);
					}
					else if(c->Sources.Contains(this))
					{
						c->Sources.Remove(this);
					}
				}
				else
				{
					if(set)
					{
						c->SetEquipment(set->Conv_NamedEquipment(Equipment));
					}
				}
			}
		}
		if(UDataAssetCollectionComponent* c=Cast<UDataAssetCollectionComponent>(a->GetComponentByClass(UDataAssetCollectionComponent::StaticClass())))
		{
			if(Autoset_Inventory)
			{
				if(Inventory_AsSource)
				{
					if(init)
					{
						c->InventorySources.AddUnique(this);
					}
					else if(c->InventorySources.Contains(this))
					{
						c->InventorySources.Remove(this);
					}
				}
				else
				{
					c->SetCollectionMap(Inventory);
				}
			}
		}
	}
}

TArray<FName> UOAsset_CommonCharacter::opts_attributes() const
{
	return UOmegaDemoFunctions::GetAssetKeys_Attributes();
}

TArray<FName> UOAsset_CommonCharacter::opts_equipSlot() const
{
	return UOmegaDemoFunctions::GetAssetKeys_EquipSlots();
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
		if(Seed>-1)
		{
			c->Seed=Seed;
		}
	}
	L_Init(Actor,true);
	return Super::OnIdentityInit_Implementation(Actor, Component);
}

bool UOAsset_CommonCharacter::OnIdentityUninit_Implementation(AActor* Actor, UActorIdentityComponent* Component)
{
	L_Init(Actor,false);
	return true;
}

TArray<UPrimaryDataAsset*> UOAsset_CommonCharacter::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	TArray<UPrimaryDataAsset*> sk=Super::GetSkills_Implementation(Combatant);
	sk.Append(Skills);
	return sk;
}

UOAsset_CommonRace* UOAsset_CommonCharacter::GetRace() const
{
	return Race;
}

UOAsset_Appearance* UOAsset_CommonCharacter::GetAppearanceAsset_Implementation()
{
	return GetAppearance();
}

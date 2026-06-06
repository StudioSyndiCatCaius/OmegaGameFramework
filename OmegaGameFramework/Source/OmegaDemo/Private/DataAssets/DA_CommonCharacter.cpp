// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonCharacter.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Constants.h"
#include "Functions/F_Assets.h"
#include "Actors/Actor_Character.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_Leveling.h"
#include "Functions/F_Constants.h"
#include "GameFramework/Character.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"


class UOmegaSettings;

void UOAsset_CommonCharacter::L_Init(AActor* a, bool init)
{
	if(a)
	{
		if(UCombatantComponent* c=Cast<UCombatantComponent>(a->GetComponentByClass(UCombatantComponent::StaticClass())))
		{
			
		}
	}
}

TArray<FName> UOAsset_CommonCharacter::opts_attributes() const
{
	OGF_NAMED_ASSET_LIST(Constant_Attributes)
}

TArray<FName> UOAsset_CommonCharacter::opts_equipSlot() const
{
	OGF_NAMED_ASSET_LIST(Constant_EquipSlots)
}

TArray<FName> UOAsset_CommonCharacter::opts_xp() const
{
	OGF_NAMED_ASSET_LIST(Constant_Leveling)
}


bool UOAsset_CommonCharacter::OnIdentityInit_Implementation(AActor* Actor, UGameplayActorComponent* Component)
{
	if(ACharacter* c=Cast<ACharacter>(Actor))
	{
		if(Appearance_Preset) { Appearance_Preset->Apply(c); }
		else if(Appearance_Custom) { Appearance_Custom->Apply(c); }
	}
	if(AOmegaBaseCharacter* c=Cast<AOmegaBaseCharacter>(Actor))
	{
		//if(AssetSeed>-1)
		//{
		//	c->Seed=AssetSeed;
		//}
	}
	L_Init(Actor,true);
	return false;
}

bool UOAsset_CommonCharacter::OnIdentityUninit_Implementation(AActor* Actor, UGameplayActorComponent* Component)
{
	L_Init(Actor,false);
	return true;
}

TArray<UPrimaryDataAsset*> UOAsset_CommonCharacter::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	TArray<UPrimaryDataAsset*> out;
	for (const TScriptInterface<IDataInterface_Skill>& Skill : Skills)
	{
		if (UPrimaryDataAsset* Asset = Cast<UPrimaryDataAsset>(Skill.GetObject()))
		{
			out.Add(Asset);
		}
	}
	return out;
}

TMap<UPrimaryDataAsset*, int32> UOAsset_CommonCharacter::GetInventory_Implementation()
{
	return Inventory;
}

TMap<UEquipmentSlot*, UPrimaryDataAsset*> UOAsset_CommonCharacter::GetEquipment_Implementation()
{
	return GetCharacterEquipment();
}

void UOAsset_CommonCharacter::ApplyInitialsToCombatant(UCombatantComponent* Combatant)
{
	if (Combatant)
	{
		Combatant->Equipment_SetAll(GetCharacterEquipment());
		TArray<FName> lvlasset;
		XpLevels.GetKeys(lvlasset);
		for (FName Name : lvlasset)
		{
			if (UOmegaLevelingAsset* lvla=GetMutableDefault<UOmegaSettings_Constants>()->Constant_Leveling.FindOrAdd(Name).LoadSynchronous())
			{
				Combatant->XP_SetLevel(lvla,XpLevels[Name]);
			}
		}
		Combatant->Inventory_Set(Inventory);
	}
}

TMap<UEquipmentSlot*, UPrimaryDataAsset*> UOAsset_CommonCharacter::GetCharacterEquipment()
{
	TMap<FName, UPrimaryDataAsset*> EquipmentAssets;
	for (const auto& Pair : Equipment)
	{
		if (UPrimaryDataAsset* Asset = Cast<UPrimaryDataAsset>(Pair.Value.GetObject()))
		{
			EquipmentAssets.Add(Pair.Key, Asset);
		}
	}
	return UOmegaFunctions_Asset::ConvNamed_Equipment(EquipmentAssets);
}



TMap<UOmegaAttribute*, float> UOAsset_CommonCharacter::GetAttributes()
{
	TMap<UOmegaAttribute*, float> out;
	TArray<FName> nams;
	Attributes.GetKeys(nams);
	for (FName Name : nams)
	{
		if (UOmegaAttribute* att = UOmegaFunctions_Constants::Attribute(Name))
		{
			out.Add(att,Attributes[Name]);
		}
	}
	
	return out;
}


UOAsset_Appearance* UOAsset_CommonCharacter::GetAppearanceAsset_Implementation()
{
	return GetAppearance();
}

void UOAsset_CommonCharacter::SetValue_Implementation(FLuaValue Value, const FString& Field)
{
	Super::SetValue_Implementation(Value, Field);
	
}

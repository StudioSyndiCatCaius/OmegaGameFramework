// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_InventoryBox.h"

#include "LuaConst.h"
#include "LuaSubsystem.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_Saveable.h"
#include "Functions/F_Save.h"
#include "Misc/OmegaUtils_Methods.h"



void AOmegaInventoryBox::L_AssetChange(UPrimaryDataAsset* Asset, int32 Amount, bool IsFull)
{
	//Saveable->SetEntityData(e);
}

void AOmegaInventoryBox::BeginPlay()
{
	/*
	if(Saveable->GetSaveParam_Bool("init") && bSaveInventory)
	{

	}
	else
	{
		Combatant->Inventory_Set(Items);
		for(auto* a : Bulk_Items)
		{
			if(a)
			{
				Combatant->Inventory_Add(a,Bulk_Amount);
			}
		}
		if(bSaveInventory)
		{
			Saveable->SetSaveParam_Bool("init",true);
		}
	}
	*/
}

AOmegaInventoryBox::AOmegaInventoryBox()
{
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Inventory");
//	Combatant->OnAssetAdded.AddDynamic(this,&AOmegaInventoryBox::L_AssetChange);
}

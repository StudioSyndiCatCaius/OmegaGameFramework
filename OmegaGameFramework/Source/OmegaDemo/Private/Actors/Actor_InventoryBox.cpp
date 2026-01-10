// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_InventoryBox.h"

#include "LuaConst.h"
#include "LuaSubsystem.h"
#include "Components/Component_ActorConfig.h"
#include "Components/Component_Inventory.h"
#include "Components/Component_Saveable.h"
#include "Functions/F_Save.h"
#include "Misc/OmegaUtils_Methods.h"



void AOmegaInventoryBox::L_AssetChange(UPrimaryDataAsset* Asset, int32 Amount, bool IsFull)
{
	FOmegaEntity e=Saveable->GetEntityData();
	e.Inventory=Inventory->GetCollectionMap(1,false);
	Saveable->SetEntityData(e);
}

void AOmegaInventoryBox::BeginPlay()
{
	if(Saveable->GetSaveParam_Bool("init") && bSaveInventory)
	{
		FOmegaEntity e=Saveable->GetEntityData();
		Inventory->SetCollectionMap(e.Inventory);
	}
	else
	{
		Inventory->SetCollectionMap(Items);
		for(auto* a : Bulk_Items)
		{
			if(a)
			{
				Inventory->AddAsset(a,Bulk_Amount);
			}
		}
		if(bSaveInventory)
		{
			Saveable->SetSaveParam_Bool("init",true);
		}
	}
}

AOmegaInventoryBox::AOmegaInventoryBox()
{
	Inventory=CreateOptionalDefaultSubobject<UDataAssetCollectionComponent>("Inventory");
	Inventory->OnAssetAdded.AddDynamic(this,&AOmegaInventoryBox::L_AssetChange);
}

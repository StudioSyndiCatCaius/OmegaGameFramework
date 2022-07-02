// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataItem.h"


TArray<UOmegaDataTrait*> UOmegaDataItem::GetAllValidTraits()
{
	TArray<UOmegaDataTrait*> OutTraits;
	
	for(auto* TempTrait : Traits)
	{
		if(TempTrait)
		{
			OutTraits.Add(TempTrait);
		}
	}
	for(auto* TempTraitCol : TraitCollections)
	{
		for(auto* TempTrait : TempTraitCol->Traits)
		{
			if(TempTrait)
			{
				OutTraits.Add(TempTrait);
			}
		}
	}
	return OutTraits;
}

UOmegaDataTrait* UOmegaDataItem::GetTraitByType(TSubclassOf<UOmegaDataTrait> Class)
{
	for(auto* TempTrait : GetAllValidTraits())
	{

		if(TempTrait->GetClass()->IsChildOf(Class))
		{
			return TempTrait;
		}
	}
	return nullptr;
}

TArray<UOmegaDataTrait*> UOmegaDataItem::GetTraitsByType(TSubclassOf<UOmegaDataTrait> Class)
{
	TArray<UOmegaDataTrait*> OutTraits;

	for(auto* TempTrait : GetAllValidTraits())
	{
		if(TempTrait->GetClass()->IsChildOf(Class))
		{
			OutTraits.Add(TempTrait);
		}
	}

	return OutTraits;
}

void UOmegaDataItem::ApplyTraitsToActor(AActor* Actor, FString Flag, FGameplayTagContainer Tags)
{
	if(!Actor)
	{
		return;
	}
		
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->AppliedToActor(Actor, Flag, Tags);
	}
	
}

void UOmegaDataItem::ApplyTraitsToWidget(UUserWidget* Widget, FString Flag, FGameplayTagContainer Tags)
{
	if(!Widget)
	{
		return;
	}
		
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->AppliedToWidget(Widget, Flag, Tags);
	}
}

UOmegaDataTrait* UOmegaDataItem::GetTraitWithInterface(TSubclassOf<UInterface> Interface)
{
	for(auto* TempTrait : GetAllValidTraits())
	{
		if(TempTrait->GetClass()->ImplementsInterface(Interface))
		{
			return TempTrait;
		}
	}
	return nullptr;
}

TArray<UOmegaDataTrait*> UOmegaDataItem::GetTraitsWithInterface(TSubclassOf<UInterface> Interface)
{
	TArray<UOmegaDataTrait*> OutTraits;
	for(auto* TempTrait : GetAllValidTraits())
	{
		if(TempTrait->GetClass()->ImplementsInterface(Interface))
		{
			OutTraits.Add(TempTrait);
		}
	}
	return OutTraits;
}

///////////////////////
/// DATA INTERFACES
///////////////////////

//Tags

FGameplayTag UOmegaDataItem::GetObjectGameplayCategory_Implementation()
{
	return GameplayCategory;
}

FGameplayTagContainer UOmegaDataItem::GetObjectGameplayTags_Implementation()
{
	return GameplayTags;
}

//General
void UOmegaDataItem::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description)
{
	
	FString TempName = DisplayName.ToString();
	FString TempDesc = DisplayDescription.ToString();
	
	for(auto* TempTrait : GetAllValidTraits())
	{
		if(TempTrait) //Apend Trait Names
		{
			FString InText = TempTrait->AppendedItemName().ToString();
			TempName = TempName.Append(InText);
		}
		if(TempTrait) //Apend Trait Descriptions
		{
			FString InText = TempTrait->AppendedItemDescription().ToString();
			TempDesc = TempDesc.Append(InText);
		}
	}
	
	Name = FText::FromString(TempName);
	Description = FText::FromString(TempDesc);
}

void UOmegaDataItem::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = Icon;
}

int32 UOmegaDataItem::GetMaxCollectionNumber_Implementation()
{
	return MaxCollectionAmount;
}


//-------------------------------
// PROPERTIES
//-------------------------------
/*
bool UOmegaDataItem::GetItemProperty_Bool(const FString& Property)
{
	bool ValidProp = false;
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->BindTraitProperty_Bool(Property, ValidProp);
		if(ValidProp)
		{
			return TempTrait->BindTraitProperty_Bool(Property, ValidProp);
		}
	}
	return false;
}

int32 UOmegaDataItem::GetItemProperty_Int(const FString& Property)
{
	bool ValidProp = false;
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->BindTraitProperty_Int(Property, ValidProp);
		if(ValidProp)
		{
			return TempTrait->BindTraitProperty_Int(Property, ValidProp);
		}
	}
	return false;
}

float UOmegaDataItem::GetItemProperty_Float(const FString& Property)
{
	bool ValidProp = false;
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->BindTraitProperty_Float(Property, ValidProp);
		if(ValidProp)
		{
			return TempTrait->BindTraitProperty_Float(Property, ValidProp);
		}
	}
	return false;
}

FString UOmegaDataItem::GetItemProperty_String(const FString& Property)
{
	bool ValidProp = false;
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->BindTraitProperty_String(Property, ValidProp);
		if(ValidProp)
		{
			return TempTrait->BindTraitProperty_String(Property, ValidProp);
		}
	}
	return "";
}

UPrimaryDataAsset* UOmegaDataItem::GetItemProperty_Asset(const FString& Property)
{
	bool ValidProp = false;
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->BindTraitProperty_Asset(Property, ValidProp);
		if(ValidProp)
		{
			return TempTrait->BindTraitProperty_Asset(Property, ValidProp);
		}
	}
	return nullptr;
}

UOmegaDataItem* UOmegaDataItem::GetItemProperty_Item(const FString& Property)
{
	bool ValidProp = false;
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->BindTraitProperty_Item(Property, ValidProp);
		if(ValidProp)
		{
			return TempTrait->BindTraitProperty_Item(Property, ValidProp);
		}
	}
	return nullptr;
}
*/

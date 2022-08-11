// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataItem.h"


bool UOmegaDataItem::AreTagsAccepted(const FString& Query, FGameplayTagContainer Tags)
{
	if(TagQueries.Contains(Query))
	{
		return Tags.MatchesQuery(TagQueries.FindOrAdd(Query));
	}
	return true;
}

bool UOmegaDataItem::IsObjectAccepted(const FString& Query, UObject* Object)
{
	FGameplayTagContainer TagsToCheck;
	if(Object && Object->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
	{
		TagsToCheck = IGameplayTagsInterface::Execute_GetObjectGameplayTags(Object);
	}
	return AreTagsAccepted(Query, TagsToCheck);
}

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
	FGameplayTagContainer OutTags = GameplayTags;
	for(auto* TempTrait : GetAllValidTraits())
	{
		OutTags.AppendTags(TempTrait->AppendedItemTags());
	}
	return OutTags;
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

TArray<FOmegaAttributeModifier> UOmegaDataItem::GetModifierValues_Implementation()
{
	TArray<FOmegaAttributeModifier> OutMods;
	for(auto* TempTrait : GetAllValidTraits())
	{
		if(TempTrait->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			OutMods.Append(IDataInterface_AttributeModifier::Execute_GetModifierValues(TempTrait));
		}
	}
	return OutMods;
}

//PROPETIES


UObject* UOmegaDataItem::GetSoftProperty_Object_Implementation(const FString& Property)
{
	bool ValidProp = false;
	for(auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->BindTraitProperty_Object(Property, ValidProp);
		if(ValidProp)
		{
			return TempTrait->BindTraitProperty_Object(Property, ValidProp);
		}
	}
	return nullptr;
}

FString UOmegaDataItem::GetSoftProperty_String_Implementation(const FString& Property)
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

float UOmegaDataItem::GetSoftProperty_Float_Implementation(const FString& Property)
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

int32 UOmegaDataItem::GetSoftProperty_Int32_Implementation(const FString& Property)
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

bool UOmegaDataItem::GetSoftProperty_Bool_Implementation(const FString& Property)
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




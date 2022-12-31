// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataItem.h"
#include "Gameplay/Combatant/DataInterface_SkillSource.h"
#include "OmegaGameplayEffect.h"

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

UOmegaDataTrait* UOmegaDataItem::GetTraitByLabel(const FString& Label)
{
	for(auto* TempTrait : GetAllValidTraits())
	{

		if(TempTrait->TraitLabel == Label)
		{
			return TempTrait;
		}
	}
	return nullptr;
}

TArray<UOmegaDataTrait*> UOmegaDataItem::GetTraitsByLabel(const FString& Label)
{
	TArray<UOmegaDataTrait*> OutTraits;

	for(auto* TempTrait : GetAllValidTraits())
	{
		if(TempTrait->TraitLabel == Label)
		{
			OutTraits.Add(TempTrait);
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

TArray<UOmegaDataTrait*> UOmegaDataItem::GetTraitsWithInterface(const UClass* Interface)
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

//---------------------------------------------------------------------------------------------------------------------------------------//
//Gameplay Tags
//---------------------------------------------------------------------------------------------------------------------------------------//

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

//---------------------------------------------------------------------------------------------------------------------------------------//
//General
//---------------------------------------------------------------------------------------------------------------------------------------//
void UOmegaDataItem::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description)
{
	if(!Label.IsEmpty() && GetTraitByLabel(Label)) //Try and override data from trait
	{
		IDataInterface_General::Execute_GetGeneralDataText(GetTraitByLabel(Label), Label, Context, Name, Description);
	}
	else //Use default data
	{
		// Set Initial Name and Desc
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
}

void UOmegaDataItem::GetGeneralAssetLabel_Implementation(FString& Label)
{
	if(CustomLabel.IsEmpty())
	{
		Label = DisplayName.ToString();
	}
	Label = CustomLabel;
}

void UOmegaDataItem::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
                                                         UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(!Label.IsEmpty() && GetTraitByLabel(Label)) //Try and override data from trait
		{
			IDataInterface_General::Execute_GetGeneralDataImages(GetTraitByLabel(Label), Label, Context, Texture, Material, Brush);
		}
	else //Use default data
	{
		Brush = Icon;
	}
	
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

TArray<FOmegaEffectContainer> UOmegaDataItem::GetOmegaEffects_Implementation()
{
	TArray<FOmegaEffectContainer> OutEffects;
	
	for(auto* TempTrait : GetTraitsWithInterface(UDataInterface_OmegaEffect::StaticClass()))
	{
		OutEffects.Append(IDataInterface_OmegaEffect::Execute_GetOmegaEffects(TempTrait));
	}
	return OutEffects;
}

TArray<UPrimaryDataAsset*> UOmegaDataItem::GetSkills_Implementation()
{
	TArray<UPrimaryDataAsset*> OutSkills;
	
	for(auto* TempTrait : GetTraitsWithInterface(UDataInterface_SkillSource::StaticClass()))
	{
		OutSkills.Append(IDataInterface_SkillSource::Execute_GetSkills(TempTrait));
	}
	return OutSkills;
}


TMap<FString, FString> UOmegaDataItem::DEBUG_GetProperties()
{
	TMap<FString, FString> LocalStrings;
	GetNativePropertyValues(LocalStrings, EPropertyPortFlags::PPF_DebugDump);
	return LocalStrings;
}

FString UOmegaDataItem::Local_GetItemProperty(const FString& Property)
{
	TMap<FString, FString> LocalStrings;
	for(const auto* TempTrait : GetAllValidTraits())
	{
		TempTrait->GetNativePropertyValues(LocalStrings, 0x00000800);
		if(LocalStrings.Contains(Property))
		{
			return LocalStrings.FindOrAdd(Property);
		}
	}
	return "";
}

TArray<FString> UOmegaDataItem::Local_GetItemPropertyList(const FString& Property)
{
	TArray<FString> OutProps;

	return OutProps;
}

FString UOmegaDataItem::GetItemProperty_String(const FString& Property)
{
	return Local_GetItemProperty(Property);
}





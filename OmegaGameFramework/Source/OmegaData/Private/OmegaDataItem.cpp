// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataItem.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "LuaObject.h"
#include "LuaInterface.h"
#include "Interfaces/OmegaInterface_Combatant.h"
#include "Actors/Actor_GameplayEffect.h"
#include "Functions/OmegaFunctions_Common.h"



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
		if(TempTraitCol)
		{
			for(auto* TempTrait : TempTraitCol->Traits)
			{
				if(TempTrait)
				{
					OutTraits.Add(TempTrait);
				}
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
		if(TempTrait)
		{
			TempTrait->AppliedToActor(Actor, Flag, Tags);
			for(auto* TempComp : Actor->GetComponents())
			{
				if(TempComp)
				{
					TempTrait->AppliedToComponent(TempComp, Flag, Tags);
				}
			}
		}
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

//############################################################################################################
// Lua
//############################################################################################################
FLuaValue UOmegaDataItem::GetKey_Implementation()
{
	FString S_label;
	GetGeneralAssetLabel_Implementation(S_label);
	return ULuaBlueprintFunctionLibrary::Conv_StringToLuaValue(S_label);
}

FLuaValue UOmegaDataItem::GetValue_Implementation(const FString& Field)
{
	return lua_val;
}

void UOmegaDataItem::SetValue_Implementation(FLuaValue Value, const FString& Field)
{
	lua_val=Value;
}


//############################################################################################################
// Gamepaly Tags
//############################################################################################################

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

//############################################################################################################
// General Data
//############################################################################################################
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
		Label = GetName();
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
	//OutEffects = Effects;
	
	for(auto* TempTrait : GetTraitsWithInterface(UDataInterface_OmegaEffect::StaticClass()))
	{
		OutEffects.Append(IDataInterface_OmegaEffect::Execute_GetOmegaEffects(TempTrait));
	}
	return OutEffects;
}

TArray<UPrimaryDataAsset*> UOmegaDataItem::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	TArray<UPrimaryDataAsset*> OutSkills;
	
	for(auto* TempTrait : GetTraitsWithInterface(UDataInterface_SkillSource::StaticClass()))
	{
		OutSkills.Append(IDataInterface_SkillSource::Execute_GetSkills(TempTrait,Combatant));
	}
	return OutSkills;
}

//############################################################################################################
// Soft properties
//############################################################################################################

FString UOmegaDataItem::GetSoftProperty_Implementation(const FString& Property)
{
	FString OutVal;
	
	for(auto* TempTrait : GetTraitsWithInterface(UOmegaSoftPropertyInterface::StaticClass()))
	{
		FString TempVal = IOmegaSoftPropertyInterface::Execute_GetSoftProperty(TempTrait, Property);
		if(!TempVal.IsEmpty())
		{
			OutVal = TempVal;
		}
	}
	return OutVal;
}

TMap<FString, FString> UOmegaDataItem::GetSoftPropertyMap_Implementation()
{
	TMap<FString, FString> OutVal;
	for(auto* TempTrait : GetTraitsWithInterface(UOmegaSoftPropertyInterface::StaticClass()))
	{
		OutVal.Append(IOmegaSoftPropertyInterface::Execute_GetSoftPropertyMap(TempTrait));
	}
	return OutVal;
}

//############################################################################################################
// ASSET DISPLAY
//############################################################################################################


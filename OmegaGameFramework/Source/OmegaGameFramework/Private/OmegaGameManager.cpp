// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaGameManager.h"


#include "Actors/OmegaGameplaySystem.h"
#include "DataAssets/DA_DamageType.h"
#include "Types/Struct_Message.h"


bool UOmegaGameManager::FlowNode_CanPlay_Implementation(UObject* Node, FName Input) const
{
	return true;
}

float UOmegaGameManager::Combatant_ModifyDamage_PreMod_Implementation(
	UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage,
	UOmegaDamageType* DamageType, UObject* Context) const
{
	return BaseDamage;
}

float UOmegaGameManager::Combatant_ModifyDamage_PostMod_Implementation(
	UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage,
	UOmegaDamageType* DamageType, UObject* Context) const
{
	return BaseDamage;
}


void FOmegaGameplaySystemConfig::ValidateTemplates(UObject* outer)
{
	// Template exists but class changed or cleared
	if (SystemTemplate)
	{
		if (!SystemClass || SystemTemplate->GetClass() != SystemClass)
		{
			SystemTemplate->MarkAsGarbage();
			SystemTemplate = nullptr;
		}
	}

	// Need new template
	if (SystemClass && !SystemTemplate)
	{
		SystemTemplate = NewObject<AOmegaGameplaySystem>(
			outer,
			SystemClass,
			NAME_None,
			RF_ArchetypeObject | RF_Transactional | RF_Public
		);
	}
}

AOmegaGameplaySystem* FOmegaGameplaySystemConfig::GetConfigTemplate_System(
	TArray<FOmegaGameplaySystemConfig> configList, TSubclassOf<AOmegaGameplaySystem> system_class)
{
	if (system_class)
	{
		for (auto a : configList)
		{
			if (a.SystemTemplate && a.SystemTemplate->GetClass()==system_class)
			{
				return a.SystemTemplate;
			}
		}
	}
	return nullptr;
}

void UOmegaGameManager::WorldInit(UWorld* World) const
{
	
	OnWorldInit(World);
}

TArray<FString> UOmegaGameManager::GetPathsFromAssetName(TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> paths,
	const FString& AssetName, TSubclassOf<UObject> Class)
{
	
	TArray<FString> out;
	if(paths.Contains(Class))
	{
		FOmegaSortedClassPathData sort_data=paths[Class];
		for (FString temp_string : sort_data.AssetPaths)
		{
			FString new_asset_name=sort_data.AssetPrefex+AssetName+sort_data.AssetSuffex;
			FString new_path=temp_string+'/'+new_asset_name+'.'+new_asset_name;
			new_path=new_path.Replace(TEXT("//"),TEXT("/"));
			new_path=new_path.Replace(TEXT("///"),TEXT("/"));
			out.Add(new_path);
		}
	}

	return out;
}



#if WITH_EDITOR
void UOmegaGameManager::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	Super::PostEditChangeChainProperty(PropertyChangedEvent);

	// Get the root property name
	const FName PropertyName = PropertyChangedEvent.PropertyChain.GetHead()->GetValue()->GetFName();

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UOmegaGameManager, System_Config))
	{
		ValidateTemplates();
	}
}
#endif

void UOmegaGameManager::ValidateTemplates()
{
	for (FOmegaGameplaySystemConfig& Config : System_Config)
	{
		Config.ValidateTemplates(this);
	}
}



void UOmegaGameManager::OnGlobalEvent_Tagged_Implementation(UGameInstance* GameInstance, FGameplayTag Event,
                                                            UObject* context, FOmegaCommonMeta meta) const
{
}

void UOmegaGameManager::OnGlobalEvent_Named_Implementation(UGameInstance* GameInstance, FName Event, UObject* context,
                                                        FOmegaCommonMeta meta) const
{
}


FSlateBrush UOmegaGameManager::Message_GetPortrait_Implementation(UObject* WorldContext,
                                                               const UOmegaGameplayMessage* Message) const
{
	if (Message)
	{
		return Message->meta.Brush;
	}
	return FSlateBrush();
}


USoundBase* UOmegaGameManager::Localization_GetClipFromPath_Implementation(UObject* WorldContext, const FString& subpath,
	const FString& file) const
{
	return nullptr;
}



FText UOmegaGameManager::Text_PostGameplayFormat_Implementation(const FText& Text, FGameplayTag Tag,
                                                                   FOmegaCommonMeta meta, UObject* WorldContext) const
{
	return Text;
}


FText UOmegaGameManager::Text_PreGameplayFormat_Implementation(const FText& Text, FGameplayTag Tag,
                                                                  FOmegaCommonMeta meta, UObject* WorldContext) const
{
	return Text;
}



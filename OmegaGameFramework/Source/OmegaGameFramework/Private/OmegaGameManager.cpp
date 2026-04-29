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

bool UOmegaGameManager::ActorGroup_AllowActor_Implementation(AActor* Actor, FGameplayTag GroupTag) const
{
	return true;
}

TArray<AActor*> UOmegaGameManager::ActorGroup_Filter_Implementation(const UObject* WorldContext,FGameplayTag GroupTag, const TArray<AActor*>& InitialGroupActors) const
{
	return InitialGroupActors;
}

bool UOmegaGameManager::Actor_CanSetTagTarget_Implementation(AActor* Instigator, AActor* Target, FGameplayTag Tag) const
{
	return true;
}


TArray<FName> UOmegaGameManager::L_GetGlobalParamKeys(EOmegaGlobalParamTarget Target, uint8 type) const
{
	TArray<FName> out_bools, out_ints, out_da;
	Globals_GetParamKeys(Target,out_bools,out_ints,out_da);
	if (type==0) { return out_bools; }
	if (type==1) { return out_ints; }
	if (type==2) {return out_da; }
	return TArray<FName>();
}

TArray<FName> UOmegaGameManager::L_GetCombatantParamKeys(UCombatantComponent* Target, uint8 type) const
{
	
	TArray<FName> out_bools, out_ints;
	Combatant_GetParamKeys(Target,out_bools,out_ints);
	if (type==0) { return out_bools; }
	if (type==1) { return out_ints; }
	return TArray<FName>();
}

USoundBase* UOmegaGameManager::Localization_GetClipFromPath_Implementation(UObject* WorldContext, const FString& subpath,
	const FString& file) const
{
	return nullptr;
}


/*
void UOmegaGameCore::GetActorInstanceMetaParams_Implementation(AActor* Actor, TArray<FName>& OutBoolParams,
                                                               TArray<FName>& OutIntParams, TArray<FName>& OutFloatParams, TArray<FName>& OutStringParams,
                                                               TArray<FName>& OutDataAssetParams, TArray<FName>& OutActorParams) const
{
}
*/


float UOmegaGameManager::Attribute_GetMaxValue_Implementation(UCombatantComponent* Combatant,
                                                           UOmegaAttribute* Attribute, int32 AttributeRank, float BaseValue) const
{
	return BaseValue;
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



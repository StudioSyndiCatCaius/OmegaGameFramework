// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaGameCore.h"


#include "Misc/OmegaDamageType.h"


bool UOmegaGameCore::FlowNode_CanPlay_Implementation(UObject* Node, FName Input) const
{
	return true;
}

float UOmegaGameCore::Combatant_ModifyDamage_PreMod_Implementation(
	UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage,
	UOmegaDamageType* DamageType, UObject* Context) const
{
	return BaseDamage;
}

float UOmegaGameCore::Combatant_ModifyDamage_PostMod_Implementation(
	UOmegaAttribute* Attribute, UCombatantComponent* Target, UCombatantComponent* Instigator, float BaseDamage,
	UOmegaDamageType* DamageType, UObject* Context) const
{
	return BaseDamage;
}

void UOmegaGameCore::WorldInit(UWorld* World) const
{
	OnWorldInit(World);
}

TArray<FString> UOmegaGameCore::GetPathsFromAssetName(TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> paths,
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

void UOmegaGameCore::GetActorInstanceMetaParams_Implementation(AActor* Actor, TArray<FName>& OutBoolParams,
	TArray<FName>& OutIntParams, TArray<FName>& OutFloatParams, TArray<FName>& OutStringParams,
	TArray<FName>& OutDataAssetParams, TArray<FName>& OutActorParams) const
{
}

bool UOmegaGameCore::Quest_CanStart_Implementation(UOmegaQuest* Quest, UOmegaQuestSubsystem* subsytem) const
{
	return true;
}

float UOmegaGameCore::Attribute_GetMaxValue_Implementation(UCombatantComponent* Combatant,
                                                           UOmegaAttribute* Attribute, int32 AttributeRank, float BaseValue) const
{
	return BaseValue;
}


FText UOmegaGameCore::Text_PostGameplayFormat_Implementation(const FText& Text, FGameplayTag Tag,
                                                                   FOmegaCommonMeta meta, UObject* WorldContext) const
{
	return Text;
}


FText UOmegaGameCore::Text_PreGameplayFormat_Implementation(const FText& Text, FGameplayTag Tag,
                                                                  FOmegaCommonMeta meta, UObject* WorldContext) const
{
	return Text;
}



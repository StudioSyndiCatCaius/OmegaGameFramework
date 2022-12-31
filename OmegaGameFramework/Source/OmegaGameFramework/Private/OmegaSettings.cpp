// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaSettings.h"

#include "NativeGameplayTags.h"

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Player,"Combat.Faction.Player");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Enemy,"Combat.Faction.Enemy");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Active,"Combat.Skill.Active");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Passive,"Combat.Skill.Passive");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Damage,"Combat.Effect.Damage");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Heal,"Combat.Effect.Heal");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Buff,"Combat.Effect.Buff");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Debuff,"Combat.Effect.Debuff");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Ailment,"Combat.Effect.Ailment");


UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Item_Consumable,"Item.Consumable");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Item_Key,"Item.Key");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Item_Equipment_Weapon,"Item.Equipment.Weapon");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Item_Equipment_Armor,"Item.Equipment.Armor");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Item_Equipment_Belt,"Item.Equipment.Belts");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Item_Equipment_Legs,"Item.Equipment.Legs");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Item_Equipment_Accessory,"Item.Equipment.Accessory");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Sex_Male,"Character.Sex.Male");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Sex_Female,"Character.Sex.Female");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Age_Child,"Character.Age.Infant");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Age_Teen,"Character.Age.Teen");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Age_Adult,"Character.Age.Adult");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Age_Old,"Character.Age.Old");


UOmegaSettings::UOmegaSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

TArray<TSubclassOf<UOmegaGameplayModule>> UOmegaSettings::GetGameplayModuleClasses() const
{
	TArray<TSubclassOf<UOmegaGameplayModule>> ModuleClasses;
	for(FSoftClassPath TempPath : RegisteredGameplayModules)
	{
		UClass* const LocalClass = TempPath.IsValid() ? LoadObject<UClass>(NULL, *TempPath.ToString()) : nullptr;
		ModuleClasses.Add(LocalClass);
	}
	return ModuleClasses;
}

UClass* UOmegaSettings::GetOmegaGameSaveClass() const
{
	UClass* const LocalSaveClass = GameSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GameSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGame::StaticClass();
}

UClass* UOmegaSettings::GetOmegaGlobalSaveClass() const
{
	UClass* const LocalSaveClass = GlobalSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GlobalSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGlobal::StaticClass();
}

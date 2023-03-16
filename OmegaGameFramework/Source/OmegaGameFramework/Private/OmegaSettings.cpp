// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaSettings.h"

#include "NativeGameplayTags.h"

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Player,"Combat.Faction.Player");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Enemy,"Combat.Faction.Enemy");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Ally,"Combat.Faction.Ally");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Neutral,"Combat.Faction.Neutral");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Active,"Combat.Skill.Active");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Passive,"Combat.Skill.Passive");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Damage,"Combat.Effect.Damage");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Heal,"Combat.Effect.Heal");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Buff,"Combat.Effect.Buff");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Debuff,"Combat.Effect.Debuff");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Effect_Ailment,"Combat.Effect.Ailment");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_State_Dead,"Combat.State.Dead");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_State_Staggered,"Combat.State.Staggered");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_State_Tracking,"Combat.State.Tracking");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_State_Passive,"Combat.State.Passive");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_State_Agressive,"Combat.State.Agressive");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Target_One,"Combat.Target.One");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Target_All,"Combat.Target.All");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Target_Self,"Combat.Target.Self");

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

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Message_Event,"Message.Event");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Message_Combat,"Message.Combat");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Message_Chat,"Message.Chat");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Bgm_Field,"BGM.Field");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Bgm_Scene,"BGM.Scene");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Bgm_Battle,"BGM.Battle");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Bgm_Menu,"BGM.Menu");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Bgm_Jingle,"BGM.Jingle");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Neutral,"Character.Mood.Neutral");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Happy,"Character.Mood.Happy");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Joy,"Character.Mood.Joy");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Sad,"Character.Mood.Sad");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Angry,"Character.Mood.Angry");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Suprised,"Character.Mood.Suprised");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Annoyed,"Character.Mood.Annoyed");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Fear,"Character.Mood.Fear");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Thinking,"Character.Mood.Thinking");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Shy,"Character.Mood.Shy");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Character_Mood_Embarrassed,"Character.Mood.Embarrassed");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_00,"Story.Chapter.00");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_01,"Story.Chapter.01");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_02,"Story.Chapter.02");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_03,"Story.Chapter.03");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_04,"Story.Chapter.04");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_05,"Story.Chapter.05");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_06,"Story.Chapter.06");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_07,"Story.Chapter.07");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_08,"Story.Chapter.08");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_09,"Story.Chapter.09");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_10,"Story.Chapter.10");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_11,"Story.Chapter.11");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_12,"Story.Chapter.12");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_13,"Story.Chapter.13");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_14,"Story.Chapter.14");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_15,"Story.Chapter.15");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_16,"Story.Chapter.16");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_17,"Story.Chapter.17");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_18,"Story.Chapter.18");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_19,"Story.Chapter.19");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Story_Chapter_20,"Story.Chapter.20");


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

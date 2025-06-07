
#include "NativeGameplayTags.h"

// --------------------------------------------------------------------------------------------------------
// Attribute
// --------------------------------------------------------------------------------------------------------

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_HP,"Attribute.HP");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_MP,"Attribute.MP");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_PATK,"Attribute.PATK");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_PDEF,"Attribute.PDEF");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_MATK,"Attribute.MATK");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_MDEF,"Attribute.MDEF");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_Speed,"Attribute.Speed");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_Dex,"Attribute.Dexterity");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_Agility,"Attribute.Agility");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_Cunning,"Attribute.Cunning");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_Wisdom,"Attribute.Wisdom");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attribute_Aggro,"Attribute.Strength");

// --------------------------------------------------------------------------------------------------------
// Skill
// --------------------------------------------------------------------------------------------------------
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Active,"Skill.Type.Active");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Passive,"Skill.Type.Passive");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Tech,"Skill.Type.Tech");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Magic,"Skill.Type.Magic");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Skill_Tactic,"Skill.Type.Tactic");

// --------------------------------------------------------------------------------------------------------
// Combat
// --------------------------------------------------------------------------------------------------------

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Player,"Combat.Faction.Player");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Enemy,"Combat.Faction.Enemy");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Ally,"Combat.Faction.Ally");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Neutral,"Combat.Faction.Neutral");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Faction_Destructable,"Combat.Faction.Destructable");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Enemy_Type_Grunt,"Combat.Enemy.Type.Grunt");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Enemy_Type_Boss,"Combat.Enemy.Type.Boss");

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

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Stage_Default,"Combat.Stage.Default");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Stage_Boss,"Combat.Stage.Boss");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Combat_Adv_Player,"Combat.Advantage.Player");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Combat_Adv_Enemy,"Combat.Advantage.Enemy");

// --------------------------------------------------------------------------------------------------------
// Item
// --------------------------------------------------------------------------------------------------------

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
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Message_Bark,"Message.Bark");

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

// --------------------------------------------------------------------------------------------------------
// Animation
// --------------------------------------------------------------------------------------------------------

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_00,"Animation.Action.Attack.Combo.00");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_01,"Animation.Action.Attack.Combo.01");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_02,"Animation.Action.Attack.Combo.02");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_03,"Animation.Action.Attack.Combo.03");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_04,"Animation.Action.Attack.Combo.04");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_05,"Animation.Action.Attack.Combo.05");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_06,"Animation.Action.Attack.Combo.06");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_07,"Animation.Action.Attack.Combo.07");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_08,"Animation.Action.Attack.Combo.08");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Attack_Combo_09,"Animation.Action.Attack.Combo.09");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Jump_Start,"Animation.Action.Jump.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Jump_Loop,"Animation.Action.Jump.Loop");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Jump_End,"Animation.Action.Jump.End");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Dodge,"Animation.Action.Dodge");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Roll,"Animation.Action.Roll");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Guard,"Animation.Action.Guard");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Cast,"Animation.Action.Cast");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Impact,"Animation.Action.Impact");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Open,"Animation.Action.Open");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Close,"Animation.Action.Close");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Turn_Left,"Animation.Action.Turn.Left");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Act_Turn_Right,"Animation.Action.Turn.Right");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Exp_Happy,"Animation.Expression.Happy");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Exp_Sad,"Animation.Expression.Sad");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Exp_Angry,"Animation.Expression.Angry");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Exp_Rage,"Animation.Expression.Rage");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Exp_Confused,"Animation.Expression.Confused");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Exp_Annoyed,"Animation.Expression.Annoyed");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Exp_Embarrased,"Animation.Expression.Embarrased");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Emote_Yes,"Animation.Emote.Yes");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Emote_No,"Animation.Emote.No");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Emote_Sit,"Animation.Emote.Sit");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Emote_Wave,"Animation.Emote.Wave");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Emote_Point,"Animation.Emote.Point");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Emote_Talking,"Animation.Emote.Talking");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Anim_Emote_Listen,"Animation.Emote.Listen");

// --------------------------------------------------------------------------------------------------------
// Flags
// --------------------------------------------------------------------------------------------------------

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_00,"Flag.Power.0%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_10,"Flag.Power.10%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_20,"Flag.Power.20%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_30,"Flag.Power.30%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_40,"Flag.Power.40%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_50,"Flag.Power.50%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_60,"Flag.Power.60%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_70,"Flag.Power.70%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_80,"Flag.Power.80%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_90,"Flag.Power.90%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_100,"Flag.Power.100%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_200,"Flag.Power.200%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_300,"Flag.Power.300%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_400,"Flag.Power.400%");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Power_500,"Flag.Power.500%");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Snap,"Flag.Snap");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_MoveToTarget,"Flag.MoveToTarget");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_TargetAll,"Flag.TargetAll");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_SelectFirst,"Flag.SelectFirst");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Flag_Consumable,"Flag.Consumable");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_AI_Controlled,"AI.Controlled");

// --------------------------------------------------------------------------------------------------------
// Event
// --------------------------------------------------------------------------------------------------------
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Actor_Interact,"Event.Actor.Interact");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Ability_Begin,"Event.Ability.Begin");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Ability_End,"Event.Ability.End");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Combat_Turn_Start,"Event.Combat.Turn.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Combat_Turn_End,"Event.Combat.Turn.End");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Combat_Start,"Event.Combat.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Combat_End,"Event.Combat.End");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Combat_Impact,"Event.Combat.Impact");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Combat_Attack,"Event.Combat.Attack");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Combat_Defend,"Event.Combat.Defend");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Target_Begin,"Event.Target.Begin");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Target_End,"Event.Target.End");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Target_Update,"Event.Target.Update");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Phys_Footstep,"Event.Physics.Footstep");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Phys_Hit,"Event.Physics.Hit");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Phys_Touch,"Event.Physics.Touch");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Phys_Break,"Event.Physics.Break");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Phys_Grab,"Event.Physics.Grab");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Phys_Climb,"Event.Physics.Climb");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Drag_Grab,"Event.Drag.Grab");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Drag_Drop,"Event.Drag.Drop");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Enter,"Event.Misc.Enter");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Exit,"Event.Misc.Exit");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Open,"Event.Misc.Open");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Close,"Event.Misc.Close");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_On,"Event.Misc.On");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Off,"Event.Misc.Off");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Start,"Event.Misc.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Stop,"Event.Misc.Stop");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Reset,"Event.Misc.Reset");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Misc_Kill,"Event.Misc.Kill");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Msg_Start,"Event.Message.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Msg_Next,"Event.Message.Next");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Msg_End,"Event.Message.End");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Dlg_Start,"Event.Dialogue.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Dlg_End,"Event.Dialogue.End");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Dlg_Line_Init,"Event.Dialogue.Line.Init");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Dlg_Line_PreStart,"Event.Dialogue.Line.PreStart");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Dlg_Line_Start,"Event.Dialogue.Line.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Dlg_Line_End,"Event.Dialogue.Line.End");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Dlg_Line_Next,"Event.Dialogue.Line.Next");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Actor_Type_Interactable,"Actor.Type.Interactable");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Actor_Type_Destructable,"Actor.Type.Destructable");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Choice_Start,"Event.Choice.Start");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Choice_Select,"Event.Choice.Selected");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Event_Choice_End,"Event.Choice.End");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Pref_Game,"Preferences.Game");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Pref_Visual,"Preferences.Visual");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Pref_Audio,"Preferences.Audio");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Pref_Controls,"Preferences.Controls");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Title,"Menu.Title");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Save,"Menu.Save");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Load,"Menu.Load");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Settings,"Menu.Settings");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Pause,"Menu.Pause");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Confirm,"Menu.Confirm");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Info,"Menu.Info");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Tutorial,"Menu.Tutorial");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Equip,"Menu.Equipment");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Items,"Menu.Items");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Party,"Menu.Party");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Quest,"Menu.Quest");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Journal,"Menu.Journal");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Menu_Cooking,"Menu.Cooking");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Quest_Type_Main,"Quest.Type.Main");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Quest_Type_Side,"Quest.Type.Side");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Quest_Type_Hunt,"Quest.Type.Hunt");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_System_Exploration,"System.Exploration");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_System_Combat,"System.Combat");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_System_Menu,"System.Menu");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_System_Pause,"System.Pause");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_System_Cutscene,"System.Cutscene");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_System_Dialog,"System.Dialog");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_System_Loading,"System.Loading");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attributes_Static_HP,"Attributes.Metric.HP");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attributes_Static_MP,"Attributes.Metric.MP");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attributes_Static_TP,"Attributes.Metric.TP");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Attributes_Static_Stamina,"Attributes.Metric.Stamina");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Camera_Battle,"Camera.Battle");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Camera_Dialogue,"Camera.Dialogue");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Delay_Load,"Delay.Load");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Delay_Dlg_Line_Setup,"Delay.Dialogue.Line.Setup");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Delay_Block_Advance,"Delay.Block.Advance");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Query_DLG_Line_CanPlay,"Query.Dialogue.Line.CanPlay")
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Query_DLG_CanPlay,"Query.Dialogue.CanPlay");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Input_Event_Confirm,"Input.Event.Confirm");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Input_Event_Cancel,"Input.Event.Cancel");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Trade_Buy,"Trade.Buy");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Trade_Sell,"Trade.Sell");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Trade_Barter,"Trade.Barter");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Trade_Cook,"Trade.Cook");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Trade_Draft,"Trade.Draft");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Param_Amount,"Param.Amount");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Param_Max,"Param.Max");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Param_Min,"Param.Min");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Param_Active,"Param.Active");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Param_Icon_Big,"Param.Icon.Big");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Param_Icon_Tall,"Param.Icon.Tall");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Param_Icon_Small,"Param.Icon.Small");

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Save_Type_Manual,"Save.Type.Manual");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Save_Type_Auto,"Save.Type.Auto");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Save_Type_Quick,"Save.Type.Quick")

UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Zone_Floor_00,"Zone.Floor.00");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Zone_Floor_01,"Zone.Floor.01");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Zone_Floor_02,"Zone.Floor.02");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Zone_Floor_03,"Zone.Floor.03");
UE_DEFINE_GAMEPLAY_TAG(Tag_Omega_Zone_Floor_04,"Zone.Floor.04");


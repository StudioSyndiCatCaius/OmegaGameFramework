# Omega Game Framework: Documentation

**NOTE**: OGF is desgined as an alternative to UE's "Gameplay Ability System". While not technically *incompatible*, it is NOT recommended to have both active in a project.

* [GettingStarted](docs/tutorial/1_install.md)



____
### Subsystems
||Name|Type|Description|Doc Status|
|-|-|-|-|-|
|![](../docs/images/functions/subsystems/f_subs_GameMang.png)|[Game Manager](../docs/docs/subsystems/subsystem_manager.md)|**Game Instance**| Create & manage *Gameplay Modules*, & Fire **Global Events** | ✅READY
|![](../docs/images/functions/subsystems/f_subs_save.png)|[Save](../docs/docs/subsystems/subsystem_save.md)|**Game Instance**| Save and Load the **Active** & **Global** game data. | ✅READY
|![](../docs/images/functions/subsystems/f_subs_gameplay.png)|[Gameplay](../docs/docs/subsystems/subsystem_gameplay.md)|**World**| Create & manage *Gameplay Systems*. | ✅READY
|![](../docs/images/functions/subsystems/f_subs_player.png)|[Player](../docs/docs/subsystems/subsystem_player.md)|**Player**| Player-specific subsystem for handling UI and input. | 🟡WIP
|![](../docs/images/functions/subsystems/f_subs_zone.png)|[Zone](../docs/docs/subsystems/subsystem_zone.md)|**World**| Subsytem for managing between level zones & transitioning between levels. | ✅READY
|![](../docs/images/functions/subsystems/f_subs_cam.png)|[Dynamic Camera](../docs/docs/subsystems/subsystem_camera.md)|**World**| Subsystem for dynamically blending between various cameras based on a priority list. | 🟡WIP
|![](../docs/images/functions/subsystems/f_subs_dataItem.png)|[Data Item](../docs/docs/subsystems/subsystem_dataItems.md)|**Game Instance**| DataAssets with modular traits that can be accessed or effect an actor. | ❌Incomplete
|![](../docs/images/functions/subsystems/f_subs_Pref.png)|[Game Preferences](../docs/docs/subsystems/subsystem_preferences.md)|**Game Instance**| User-specific prefernced that can be edited and saved as a `FVector` in the `Game` or `Global` saves. | ✅READY
|![](../docs/images/functions/subsystems/f_subs_bgm.png)|[BGM](../docs/docs/subsystems/subsystem_bgm.md)|**World**| Subsytem for playing and managing BGM (music).| 🟡WIP
|![](../docs/images/functions/subsystems/f_subs_msg.png)|[Message](../docs/docs/subsystems/subsystem_message.md)|**Game Instance**| Fire & Log ``FText`` messages for gameplay purposes. | 🟡WIP
|![](../docs/images/functions/subsystems/f_subs_LE.png)|[Linear Events](../docs/docs/subsystems/subsystem_linearEvents.md)|**World**| Run & manage **Linear Events** graphs for *linear* data-driven, async gamepaly events. | ✅READY
|![](../docs/images/functions/subsystems/f_subs_flow.png)|[Flow](../docs/docs/subsystems/subsystem_flow.md)|**World**| Run & manage **FlowAsset** graphs for *branching* data-drive, async gamepaly events. | ❌Incomplete
|![](../docs/images/functions/subsystems/f_subs_mods.png)|[Mods](../docs/docs/subsystems/subsystem_mods.md)|**Game Instance**| Load ``.lua`` and Override files from the Mods folder | 🟡WIP
|![](../docs/images/functions/subsystems/f_subs_lua.png)|[Lua](../docs/docs/subsystems/subsystem_lua.md)|**Game Instance**| Runing local lua files | 🟡WIP

____
### Components
||Name|Description|Doc Status|
|-|-|-|-|
|![](../OmegaGameFramework/Resources/Icons/CombatantComponent_16.png)|[Combatant](../docs/docs/components/comp_combatant.md)| Manage **Attributes** & **Abilites** as well as recieve **Gameplay Effects**| 🟡WIP
|![](../OmegaGameFramework/Resources/Icons/CombatantExtensionComponent_16.png)|[Combatant Extension](../docs/docs/components/comp_combatant.md)| Add additionally functionallity relevant to the ``Combatant Component``. | 🟡WIP
|![](../OmegaGameFramework/Resources/Icons/ActorStateComponent_16.png)|[Actor State](../docs/docs/components/comp_ActorState.md)| Save a `Gameplay Tag` as an actor state, that will be reloaded when the actor or game is reloaded. | ❌Incomplete
|![](../)|[Actor Targeting](../docs/docs/components/comp_ActorTargeting.md)| Add actors to a registry list and cycle through them to get a "target" actor.  | 🟡WIP
|![](../OmegaGameFramework/Resources/Icons/OmegaCombatEncounter_Instance_16.png)|[Combat Encounter](../docs/docs/components/comp_CombatEncounter.md)| Creates a `Stage` and `Encounter` instance ofr handling gameplay encoutners involving combatants. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/EquipmentComponent_16.png)|[Equipment](../docs/docs/components/comp_equipment.md)| "Equip" ``Data Assets`` to slots, with options to have the equipment modify combatant ``skills`` & ``attributes``. | 🟡WIP
|![](../)|Gameplay Systems| Activates a list of gameplay systems which are deactivated upon the component's destruction.| 🟡WIP
|![](../OmegaGameFramework/Resources/Icons/InstanceActorComponent_16.png)|[Instanced Actor](../docs/docs/components/comp_InstanceActor.md)| Creates instances of an actor, using the same functionality with different context objects.| 🟡WIP
|![](../OmegaGameFramework/Resources/Icons/DataAssetCollectionComponent_16.png)|[Inventory](../docs/docs/components/comp_inventory.md)| Add and store an int32 count of ``Data Assets``.| ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/OmegaLevelingAsset_16.png)|[Leveling](../docs/docs/components/comp_leveling.md)| Add XP and calculate a level/rank for a an actor based on a custom curve asset.| 🟡WIP
|![](../OmegaGameFramework/Resources/Icons/OmegaSkin_16.png)|[Skin](../docs/docs/components/comp_skin.md)| For Modular Characters. Creates a child actor to a ``Character``, binding all it's ``SkeletalMeshComponents`` to the owning character's ``AnimInstance``. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/Subscript_16.png)|[Subscript](../docs/docs/components/comp_subscript.md)| A simple ECS-style component. Add extra custom functionality to an actor from a instanced subscript or ``CollectionAsset`` of subscripts. | ❌Incomplete
|![](../)|[Tool Actor](../docs/docs/components/comp_ToolActor.md)| Cycle through a list of actors that can be activated and play montage animations. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/OmegaQuest_16.png)|[Quest](../docs/docs/components/comp_quest.md)| Create & save a state of a list of gameplay events. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/TurnBasedManagerComponent_16.png)|[Turn Manager](../docs/docs/components/comp_TurnManager.md)| Registers & generates a turn-order for a list of combatants, using a custom ability to manage a turn. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/ZoneEntityComponent_16.png)|[Zone Entity](../docs/docs/components/comp_ZoneEntity.md)| Registers this actor to the ``Zone Subsystem``, allowing them to be dispalyed in a minimap. | 🟡WIP
|![](../)|[Grid3D](../docs/docs/components/comp_Grid3D.md)| Create a grid of 3D Tile Actors in the world space. | ❌Incomplete

____
### Actors
||Name|Description|Doc Status|
|-|-|-|-|
|![](../OmegaGameFramework/Resources/Icons/OmegaAbility.png)|[Abilities]()|Modular gameplay actions managed and executed by a ``CombatantComponent``. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/OmegaActorEnvironment.png)|[Environment]()| Actor containing components for lighting and tening a level. (I.E. ``Atmopshere``, ``Clouds``, ``Fog``, ``SkyLight``, ``DirectionalLight``, ``PostProcess`` etc.) | ❌Incomplete
|![](../)|[Combatant Selector]()| Pawn for inputing and selecting from a list of combatants. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/OmegaGameplayEffect.png)|[Gameplay Effect]()| Actor attached to a ``CombatantComponent`` to modify it's status and behavior. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/OmegaGameplayCue.png)|[Gameplay Cue]()| Cosmetic-only actor containing a `Niagara` & `Audio` component. | ❌Incomplete
|![](../)|[Bullet]()|Projectile that applies effects when hitting a combatant. | ❌Incomplete
|![](../)|[Advanced Volume]()| Advanced Volume actor utilizing color, icon, and text. | ❌Incomplete
|![](../)|[Pickup]()|Actor that plays an effect when overlaping with the player, and is then destroyed. | ❌Incomplete
|![](../)|[Randomized Mesh]()| Randomly selects a mesh to display & offset from a int32 seed, which can be determined by the actors world position. | ❌Incomplete

____
### Features/Functions
||Name|Description|Doc Status|
|-|-|-|-|
|![](../OmegaGameFramework/Resources/Icons/OmegaScriptedEffect.png)|[Scripted Effects]()|Apply effects to a combatant from a data script. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/OmegaAnimationEmote.png)|[Animation Emotes]()|A ``DataAsset`` that playes an anim montage on a character, determined based the character's anim instance. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/OmegaObjectSorterAsset.png)|[Object Sorter]()|Sort and Filter an array of UObjects with a Sorter Asset. | ❌Incomplete
|![](../)|[Scripted Trace]()|Run a single or multi trace from a script. | ❌Incomplete
|![](../)|[Tag Events]()| Fire nont-specific `GameplayTag`-based events on an actor or group of actors. | ❌Incomplete

____
### Widgets
||Name|Description|Doc Status|
|-|-|-|-|
|![](../OmegaGameFramework/Resources/Icons/DataWidget.png)|[Data Widgets](../docs/docs/widget/widget_dataWidgets.md)|Display data from a given 'source asset' object.| ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/DataListFormat.png)|[Data Lists](../docs/docs/widget/widget_datalists.md)| Displays a list of ``Data Widgets`` from an object array, aligning them based on a layout script.| ❌Incomplete
|![](../)|[Data Tooltip](../docs/docs/widget/widget_dataWidgets.md)| Hover tooltip for ``Data Widgets``. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/Menu.png)|[Menu](../docs/docs/widget/widget_menu.md)| Async widget that allows for player input. | ❌Incomplete
|![](../OmegaGameFramework/Resources/Icons/HUDLayer.png)|[HUD Layer](../docs/docs/widget/widget_popup.md)| Non-interactive widget typically activated with ``GameplaySystems``, intend to display gameplay data.| ❌Incomplete
|![](../)|[Popups](../docs/docs/widget/widget_popup.md)| A widget with a lifetime spawn based on a world position and display custom text/input data.| ❌Incomplete



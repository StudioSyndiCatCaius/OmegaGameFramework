# OmegaGameFramework — Documentation Index

---

## Start Here

- [Overview](docs/Overview.md) — Plugin summary, module list, feature areas, required plugins
- [Project Structure Standards](ProjectStructueStandards.md) — Studio SyndiCat folder & naming conventions

---

## Subsystems

| File | Description |
|------|-------------|
| [subsystem_gamemanager.md](docs/Subsystems/subsystem_gamemanager.md) | Game Instance subsystem — BGM, global events, modules, machina, preferences |
| [subsystem_world.md](docs/Subsystems/subsystem_world.md) | World subsystem — gameplay systems, combatants, quests, zones, actor groups, messages |
| [subsystem_player.md](docs/Subsystems/subsystem_player.md) | Player subsystem — menus, HUD layers, input mode, dynamic camera |
| [subsystem_save.md](docs/Subsystems/subsystem_save.md) | Save subsystem — save/load, story state, tags, JSON, bit flags |
| [subsystem_engine.md](docs/Subsystems/subsystem_engine.md) | Engine subsystem — sorted assets, dev config, Lua tables |

---

## Components

| File | Description |
|------|-------------|
| [comp_combatant.md](docs/Components/comp_combatant.md) | Combatant — attributes, damage, abilities, targeting, equipment, inventory, XP |
| [comp_combatantextension.md](docs/Components/comp_combatantextension.md) | Combatant Extension — hook modifiers into a linked combatant |
| [comp_combatencounter.md](docs/Components/comp_combatencounter.md) | Combat Encounter — spawn battlers, stages, intro sequences |
| [comp_turnbasedmanager.md](docs/Components/comp_turnbasedmanager.md) | Turn-Based Manager & Turn Tracker — turn order and turn loop |
| [comp_gameplayactor.md](docs/Components/comp_gameplayactor.md) | Gameplay Actor (ActorID) — identity, tags, zone, subscripts, save visibility |
| [comp_instancedactor.md](docs/Components/comp_instancedactor.md) | Instanced Actor — spawn/manage sub-actor lists linked to data |
| [comp_assetsquad.md](docs/Components/comp_assetsquad.md) | Asset Squad — ordered named groups of data assets (parties, decks) |
| [comp_inventory.md](docs/Components/comp_inventory.md) | Inventory — item interfaces and preset inventory assets |
| [comp_leveling.md](docs/Components/comp_leveling.md) | Leveling — XP curve assets and leveling interfaces |
| [comp_skin.md](docs/Components/comp_skin.md) | Skin — swappable character appearances and body customization |
| [comp_saveable.md](docs/Components/comp_saveable.md) | Saveable — persist actor transform/tags/params via GUID |
| [comp_calendar.md](docs/Components/comp_calendar.md) | Calendar — in-game date/period tracking |
| [comp_clock.md](docs/Components/comp_clock.md) | Clock — real-time stopwatch |
| [comp_cursorevents.md](docs/Components/comp_cursorevents.md) | Cursor Events — world-space cursor hover & interaction |
| [comp_datawidget.md](docs/Components/comp_datawidget.md) | Data Widget Component — host a DataWidget in world space |
| [comp_reference.md](docs/Components/comp_reference.md) | Reference — tag/ID marker points on actors |

---

## Actors

| File | Description |
|------|-------------|
| [actor_gameplaystem.md](docs/Actors/actor_gameplaystem.md) | Gameplay System — modular activatable game modes with tag blocking |
| [actor_ability.md](docs/Actors/actor_ability.md) | Ability — activatable combat action actors |
| [actor_gameplayeffect.md](docs/Actors/actor_gameplayeffect.md) | Gameplay Effect — status effect actors |
| [actor_gameplaycue.md](docs/Actors/actor_gameplaycue.md) | Gameplay Cue — visual/audio feedback actors |
| [actor_character.md](docs/Actors/actor_character.md) | Character bases — Omega character classes |
| [actor_player.md](docs/Actors/actor_player.md) | Player — player controller / pawn / state classes |
| [actor_zone.md](docs/Actors/actor_zone.md) | Zones — spawn points, transits, regions, zone entities |
| [actor_dynamiccamera.md](docs/Actors/actor_dynamiccamera.md) | Dynamic Camera — source/master camera actors |
| [actor_interactables.md](docs/Actors/actor_interactables.md) | Interactables — interactable actor bases |
| [actor_props.md](docs/Actors/actor_props.md) | Props — prop, openable, destructible, pickup actors |
| [actor_spawnable.md](docs/Actors/actor_spawnable.md) | Spawnables — spawnable and random-spawn actors |
| [actor_bullet.md](docs/Actors/actor_bullet.md) | Bullet — projectile actors |
| [actor_spline.md](docs/Actors/actor_spline.md) | Spline — spline path actors |
| [actor_timer.md](docs/Actors/actor_timer.md) | Timer — timed trigger actors |
| [actor_volumes.md](docs/Actors/actor_volumes.md) | Volumes — event/modifier/trigger volumes |
| [actor_water.md](docs/Actors/actor_water.md) | Water — water plane and river actors |
| [actor_environment.md](docs/Actors/actor_environment.md) | Environment — environment state actors |
| [actor_widgetdisplay.md](docs/Actors/actor_widgetdisplay.md) | Widget Display — world-space widget actors |

---

## Widgets

| File | Description |
|------|-------------|
| [Menu.md](docs/Widgets/Menu.md) | Menu — full-screen menus with animations, sound, input, parallel systems |
| [DataWidget.md](docs/Widgets/DataWidget.md) | DataWidget — single-object data display widget with hover state |
| [DataList.md](docs/Widgets/DataList.md) | DataList — list of DataWidget entries with hover/selection |

---

## Data Assets

| File | Description |
|------|-------------|
| [DataAssets.md](docs/DataAssets.md) | Overview of all data asset types |
| [da_combat.md](docs/DataAssets/da_combat.md) | Attributes, damage types, factions, equipment slots |
| [da_character.md](docs/DataAssets/da_character.md) | Actor/combatant identities, entity presets |
| [da_campaign.md](docs/DataAssets/da_campaign.md) | Campaigns and story states |
| [da_zone.md](docs/DataAssets/da_zone.md) | Zone and level data |
| [da_bgm.md](docs/DataAssets/da_bgm.md) | Background music assets |
| [da_calendar.md](docs/DataAssets/da_calendar.md) | Calendar, days, weeks, months, periods |
| [da_preferences.md](docs/DataAssets/da_preferences.md) | Game preference assets |
| [da_assetlibs.md](docs/DataAssets/da_assetlibs.md) | Asset libraries and collections |
| [da_misc.md](docs/DataAssets/da_misc.md) | Modifier collections, presets, player IDs, developer info |
| [da_demo.md](docs/DataAssets/da_demo.md) | OmegaDemo "Common" assets — characters, items, equipment, skills |

---

## Systems & Reference

| File | Description |
|------|-------------|
| [Quests.md](docs/Quests.md) | Quest system — data assets, runtime instances, persistence, delegates |
| [AsyncFlow.md](docs/AsyncFlow.md) | OmegaFlow async actions and listener nodes |
| [Interfaces.md](docs/Interfaces.md) | All Blueprint interfaces — data, actor, save, menu, widget input |

---

## Function Libraries

| File | Description |
|------|-------------|
| [F_common.md](docs/Functions/F_common.md) | Overview of all Blueprint function library categories |
| [fl_actor.md](docs/Functions/fl_actor.md) | Actor, pawn, component, physics, trace functions |
| [fl_combat.md](docs/Functions/fl_combat.md) | Combatant, equipment, inventory, scripted effect functions |
| [fl_tags.md](docs/Functions/fl_tags.md) | Tag events, global variables, soft properties/conditions, machina |
| [fl_save.md](docs/Functions/fl_save.md) | Save-related functions |
| [fl_ui.md](docs/Functions/fl_ui.md) | Widget, camera, popup functions |
| [fl_player.md](docs/Functions/fl_player.md) | Player access functions |
| [fl_systems.md](docs/Functions/fl_systems.md) | Gameplay system / module functions |
| [fl_assets.md](docs/Functions/fl_assets.md) | Data asset query functions |
| [fl_animation.md](docs/Functions/fl_animation.md) | Animation & scripted anim functions |
| [fl_bgm.md](docs/Functions/fl_bgm.md) | BGM playback functions |
| [fl_graphics.md](docs/Functions/fl_graphics.md) | Materials, mesh, graphics functions |
| [fl_math.md](docs/Functions/fl_math.md) | Math and geometry functions |
| [fl_text.md](docs/Functions/fl_text.md) | String, text, localization functions |
| [fl_io.md](docs/Functions/fl_io.md) | File and JSON functions |
| [fl_misc.md](docs/Functions/fl_misc.md) | Miscellaneous utilities |

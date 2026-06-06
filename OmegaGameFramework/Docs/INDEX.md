# OmegaGameFramework — Documentation Index

---

## Start Here

- [Overview](Overview.md) — Plugin summary, module list, feature areas, required plugins

---

## Subsystems

| File | Description |
|------|-------------|
| [subsystem_gamemanager.md](Subsystems/subsystem_gamemanager.md) | `UOmegaSubsystem_GameInstance` — BGM, global events, modules, mods, preferences, machina |
| [subsystem_world.md](Subsystems/subsystem_world.md) | `UOmegaSubsystem_World` — gameplay systems, combatants, quests, zones, actor groups, messages |
| [subsystem_player.md](Subsystems/subsystem_player.md) | `UOmegaSubsystem_Player` — menus, HUD layers, input mode, dynamic camera |
| [subsystem_save.md](Subsystems/subsystem_save.md) | `UOmegaSaveSubsystem` — save/load, story state, tags, JSON, bit flags |
| [subsystem_engine.md](Subsystems/subsystem_engine.md) | `UOmegaSubsystem_Engine` — spawnable data, developer config, sorted assets |

---

## Components

| File | Description |
|------|-------------|
| [comp_combatant.md](Components/comp_combatant.md) | `UCombatantComponent` — attributes, damage, abilities, targeting, equipment, leveling |

---

## Widgets

| File | Description |
|------|-------------|
| [Menu.md](Widgets/Menu.md) | `UMenu` — full-screen menus with animations, sound, input, and parallel systems |
| [DataWidget.md](Widgets/DataWidget.md) | `UDataWidget` — single-object data display widget with hover state |
| [DataList.md](Widgets/DataList.md) | `UDataList` — scrollable list of DataWidget entries |

---

## Systems

| File | Description |
|------|-------------|
| [GameplaySystems.md](GameplaySystems.md) | `AOmegaGameplaySystem` — modular activatable game modes with tag blocking |
| [Quests.md](Quests.md) | Quest system — data assets, runtime instances, persistence, delegates |
| [AsyncFlow.md](AsyncFlow.md) | OmegaFlow async actions and listener nodes for coroutine-style Blueprints |

---

## Reference

| File | Description |
|------|-------------|
| [DataAssets.md](DataAssets.md) | All data asset types — combat, story, zones, music, calendar, preferences |
| [Interfaces.md](Interfaces.md) | All interfaces — data, actor, save, menu, widget input |
| [Functions/F_common.md](Functions/F_common.md) | Blueprint function library overview — all 40+ BFL categories |

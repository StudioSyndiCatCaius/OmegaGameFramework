# OmegaGameFramework — Plugin Overview

**Creator:** Studio SyndiCat
**Engine Version:** Unreal Engine 5.8

---

## What Is It?

OmegaGameFramework is a comprehensive gameplay framework plugin for Unreal Engine 5. It provides a large collection of pre-built systems, subsystems, components, actors, widgets, and data assets designed to accelerate game development. Rather than building common game systems from scratch, you extend and configure Omega's building blocks.

---

## Modules

| Module | Type | Purpose |
|--------|------|---------|
| `OmegaCore` | Runtime | Core utilities and static helpers |
| `OmegaGameFramework` | Runtime | Main framework: subsystems, components, actors, widgets |
| `OmegaFlow` | Runtime | Async Blueprint actions and coroutines |
| `OmegaSequence` | Runtime | Level Sequence integration |
| `OmegaOnline` | Runtime | Multiplayer / online features |
| `OmegaDebug` | Runtime | Debug visualization tools |
| `OmegaDemo` | Runtime | Demo content and examples |
| `OmegaForge` | Runtime | In-game level editing / building tools |
| `LuaMachine` | Runtime | Lua scripting runtime |
| `FileSDK` | Runtime | File I/O utilities |
| `Flow` | Runtime | Flow graph execution (third-party) |
| `OmegaEditor` | Editor | Editor-only tooling |
| `LuaMachineEditor` | Editor | Lua scripting editor tools |
| `FlowEditor` | Editor | Flow graph editor |

---

## Core Subsystems

Five subsystems form the backbone of the framework. Each is accessed via the standard UE5 subsystem API.

| Subsystem | Scope | Class | Purpose |
|-----------|-------|-------|---------|
| **Game Manager** | Game Instance | `UOmegaSubsystem_GameInstance` | Global game state, BGM, mods, modules, global events |
| **World** | World | `UOmegaSubsystem_World` | Gameplay systems, combatants, quests, zones, messages |
| **Player** | Local Player | `UOmegaSubsystem_Player` | Menus, HUD, input mode, dynamic camera |
| **Save** | Game Instance | `UOmegaSaveSubsystem` | Save/load, story state, tags, JSON persistence |
| **Engine** | Engine | `UOmegaSubsystem_Engine` | Sorted assets, dev config, Lua table generation |

See the `Subsystems/` folder for detailed documentation on each.

---

## Feature Areas

### Combat
- `UCombatantComponent` — attributes, damage, abilities, equipment, targeting, factions, leveling
- `UOmegaAttribute` / `UOmegaDamageType` — define stat types and damage classifications
- `AOmegaAbility` / `AOmegaGameplayEffect` — implement skills and status effects
- `UCombatantFilterScript` / `UCombatantFilterCollection` — filter combatant lists by custom rules

### Gameplay Systems
- `AOmegaGameplaySystem` — modular, activatable game modes (pause menus, cutscenes, combat phases)
- Tag-based blocking prevents incompatible systems from running simultaneously

### UI
- `UMenu` — full-screen menus with open/close animations, sound, and input routing
- `UHUDLayer` — persistent HUD layers added/removed per context
- `UDataWidget` — data-driven widget that receives a UObject to display
- `UDataList` — scrolling list widget powered by an array of UObjects

### Save System
- Slot-based saving with numeric or named slots
- Separate `ActiveSaveData` (per-playthrough) and `GlobalSaveData` (cross-playthrough)
- Story state and gameplay tag persistence on save objects
- JSON save data for custom objects via `IOmegaSaveInterface`
- BitFlag helpers for compact boolean storage

### Zones & Level Travel
- `AOmegaZonePoint` — named spawn points in levels
- Zone transit system with fade sequences and level streaming
- `UOmegaZoneData` / `UOmegaLevelData` — data assets describing level zones

### Quests
- `UOmegaQuest` — quest data asset with script objects
- `AOmegaQuestInstance` — runtime quest state
- Delegates: `OnQuest_Start`, `OnQuest_End`, `OnQuest_Updated`

### BGM
- `UOmegaBGM` — music data asset (supports Metasound)
- Slot-based playback with fade in/out and pause/resume
- Playback position saved per slot

### Async Flow (OmegaFlow)
Coroutine-style Blueprint async actions. See `AsyncFlow.md` for the full list.

### Lua Scripting
- `UOmegaMod` — mod objects loaded from disk, implementing `IDataInterface_General`
- Global scripts (`UOmegaGlobalScript`) and conditions (`UOmegaGlobalCondition`) can be bound to the Lua VM

### Instanced Actors / Entities
- `FOmegaEntitySet` — structured set of entity references
- `UInstanceActorComponent` — manages pooled/spawned instance actors
- `AOmegaInstancedEntity` — entity actor with built-in Combatant and ActorID components

---

## Key Data Asset Types

| Asset | Purpose |
|-------|---------|
| `DA_Attribute` | Defines a combat attribute (HP, MP, ATK...) |
| `DA_DamageType` | Classifies damage for modifier filtering |
| `DA_Faction` | Team/alignment definition |
| `DA_EquipSlot` | Equipment slot definition |
| `DA_Campaign` | Campaign/story container with scripts |
| `DA_Zone` | Zone descriptor for level travel |
| `DA_BGM` | Background music asset |
| `DA_Calendar` / `DA_Day` / `DA_Week` | In-game calendar definitions |
| `DA_GamePreference` | User-facing setting (mapped to FVector value) |
| `DA_ActorIdentity` | Tags an actor with a primary data asset identity |

See `DataAssets.md` for the complete list.

---

## Blueprint Function Libraries

Over 40 Blueprint function library classes cover every subsystem. Key categories:

| Library | Description |
|---------|-------------|
| `F_Common` | General-purpose utilities |
| `F_Combatant` | Combatant queries and helpers |
| `F_Equipment` | Equipment slot helpers |
| `F_Machina` | State machine control |
| `F_Camera` | Dynamic camera functions |
| `F_TagEvent` | Gameplay tag event system |
| `F_GlobalParam` | Named global variables stored on the save |
| `F_SoftProperty` / `F_SoftEvent` / `F_SoftCondition` | Name-based property access, data-driven events and conditions |
| `F_PropertyBag` | Typed property bag helpers |
| `F_Json` | JSON read/write helpers |
| `F_File` | File I/O (via FileSDK) |
| `F_Localization` | Text localization helpers |

See `Functions/` for per-library documentation.

---

## Required Engine Plugins

OmegaGameFramework enables the following engine plugins:

- EnhancedInput, CommonUI, Metasound, Niagara
- GameFeatures, ModularGameplay
- GeometryScripting, Mutable, SkeletalMerging
- PCG, StateTree, GameplayStateTree
- JsonBlueprintUtilities, AssetSearch
- SequencerScripting, BinkMedia

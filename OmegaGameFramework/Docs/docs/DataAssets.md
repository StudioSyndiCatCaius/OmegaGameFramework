# Data Assets

OmegaGameFramework uses `UPrimaryDataAsset`-derived classes extensively to define game content as data rather than code. Most common types have their own entry in the Content Browser's right-click **Create** menu (Omega categories); any of them can also be created via **Miscellaneous → Data Asset** and picking the class.

Class names below are the C++ names as they appear in the class picker (drop the `U` prefix in editor).

---

## Combat

### `UOmegaAttribute`
Defines a single combat attribute (e.g. HP, MP, ATK, DEF).

| Property | Description |
|----------|-------------|
| Name / Description / Icon / Color | Display info via the General data interface |
| Max value source | How the attribute's max value is derived |
| Default/start values | Base values when no modifiers are applied |

Used by: `CombatantComponent`, damage calculations, `UOmegaAttributeSet`

### `UOmegaAttributeSet`
An ordered collection of attributes assigned to combatants as a group.

### `UOmegaDamageType`
Classifies damage for filtering in modifier calculations (Physical, Fire, etc.).

Used by: `CombatantComponent` damage functions, `DataInterface_Combatant::ModifyDamage`

### `UOmegaFaction`
Defines a team or alignment. Faction affinities determine how combatants treat each other (ally / enemy / neutral).

Used by: `CombatantComponent`, AI targeting, combatant filters

### `UEquipmentSlot`
Defines an equipment slot (Weapon, Armor, Accessory, etc.) for the combatant's equipment system.

Used by: `CombatantComponent` equipment functions

---

## Identity & Appearance

### `UOAsset_ActorIdentity`
Tags an actor with a primary data asset identity so the world subsystem can find actors by their identity.

Used by: `GetFirstActorIfIdentity` on the Gameplay (World) subsystem

### `UOAsset_CombatantIdentity`
An actor identity that also carries scripted combatant modifiers — use for enemies/NPCs whose identity should affect combat stats.

### `UOAsset_Appearance`
Defines a character's visual appearance configuration.

### Body assets (`UOmegaBodyPreset`, `UOmegaBodyType`, `UOmegaBodySlot`, `UOmegaBodyOption`)
Modular character body system: a **Body Type** defines available **Body Slots**, each filled by **Body Options** (meshes, materials); a **Body Preset** stores a chosen combination.

---

## Story & Campaign

### `UOAsset_Campaign`
Top-level story container. References a starting save configuration and optional campaign scripts.

Used by: the Save subsystem's `StartGame` (as `NewCampaign`)

### `UOmegaQuest`
Quest definition — display info, quest type scripts, replayability. See [Quests.md](Quests.md).

### `UOmegaStoryStateAsset`
A save-persistent state that activates/deactivates `OmegaStoryStateScript` objects (e.g. sublevel visibility via `StoryState_Sublevel`).

---

## World & Zones

### `UOmegaZoneData`
Describes a zone/area within a level. Referenced by `OmegaZonePoint` actors.

### `UOmegaLevelData`
Describes an entire level: its soft reference, zones, and metadata.

### `UZoneLegendAsset`
Classifies zone entities (e.g. map icons) for filtering via `GetRegisteredZoneEntities_OfLegend`.

---

## Music

### `UOmegaBGM`
Background music asset. Can reference a `USoundBase` (including MetaSounds).

Properties include the sound, volume/pitch, and optional BGM scripts.

Used by: the Game Instance subsystem's BGM system

---

## Calendar & Time

### `UOAsset_Calendar`
Top-level calendar configuration. References weeks, months, and day periods.

### `UOAsset_Day` / `UOAsset_Week` / `UOAsset_Weekday` / `UOAsset_Month`
Hierarchical time period definitions for the in-game calendar system.

### `UOAsset_DayPeriod`
Defines named time-of-day periods (Morning, Afternoon, Night, etc.).

Used by: `OmegaCalendarComponent`

---

## Preferences

### `UGamePreference`
A single user-facing setting (bool, float, or asset value styles supported via preference scripts).

Used by: the Game Instance subsystem's preference system; values persist in save data.

---

## Actors & Spawning

### `UOmegaEntityPreset`
A preset for spawning instanced entities with predefined properties.

### `UOAsset_TransformPreset`
A named set of transform configurations.

### `UOAsset_EffectsPreset`
A named collection of VFX/sound effect presets.

### `UOmegaStaticMeshPreset`
A named static mesh + material configuration.

### `UOAsset_ActorModifierCollection`
A named collection of actor modifiers that can be applied as a group.

---

## Movement

### `UOmegaComponentConfig_PawnMove`
Movement mode configuration used by Omega pawn movement, with stackable `_Modifier` assets.

---

## Asset Libraries

### `UOmegaAssetLibrary_Animation` / `UOmegaAssetLibrary_Sound` / `UOmegaAssetLibrary_SlateBrush`
Named lookup tables for montages/animations, sounds, and UI brushes — lets systems reference assets by name instead of hard references.

### `UOmegaDataAssetCollection`
A collection of arbitrary data asset references, useful for grouping related assets.

---

## Player

### `UOAsset_PlayerID`
Identifies a player slot or player profile.

---

## Developer

### `UOAsset_Developer`
Developer/branding info loaded by the Engine subsystem (e.g. splash/credits data).

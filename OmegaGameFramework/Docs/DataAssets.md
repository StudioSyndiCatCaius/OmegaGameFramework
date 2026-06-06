# Data Assets

OmegaGameFramework uses `UPrimaryDataAsset`-derived classes extensively to define game content as data rather than code. All data assets are created in the Content Browser via **Miscellaneous → Data Asset** and selecting the appropriate class.

---

## Combat

### `UOmegaAttribute` (DA_Attribute)
Defines a single combat attribute (e.g. HP, MP, ATK, DEF).

| Property | Description |
|----------|-------------|
| Name / Description | Display info via `IDataInterface_General` |
| Min / Max values | Clamping range for this attribute |
| Default value | Base value when no modifiers are applied |

Used by: `UCombatantComponent`, damage calculations, `UOmegaAttributeSet`

### `UOmegaDamageType` (DA_DamageType)
Classifies damage for filtering in modifier calculations (Physical, Fire, etc.).

Used by: `UCombatantComponent::ApplyDamage`, `IDataInterface_DamageModifier`

### `UOmegaFaction` (DA_Faction)
Defines a team or alignment. Combatants assigned to the same faction are considered allies; different factions are enemies (depending on your game logic).

Used by: `UCombatantComponent`, AI targeting

### `UEquipmentSlot` (DA_EquipSlot)
Defines an equipment slot (Weapon, Armor, Accessory, etc.) for the combatant's equipment system.

Used by: `UCombatantComponent` equipment functions

---

## Identity & Appearance

### `UGameplayActorComponent` identity asset (DA_ActorIdentity)
Tags an actor class with a primary data asset identity so the world subsystem can find actors by their identity.

Used by: `UOmegaSubsystem_World::GetFirstActorIfIdentity`

### `UOmegaAppearance` (DA_Appearance)
Defines a character's visual appearance configuration.

### `UOmegaBody` (DA_Body)
Defines body part data for skeletal/modular character setup.

---

## Story & Campaign

### `UOAsset_Campaign` (DA_Campaign)
Top-level story container. References a starting save configuration and optional scripts.

Used by: `UOmegaSaveSubsystem::StartGame` (as `NewCampaign`)

### `UOmegaQuest` (DA_Quest — also `AOmegaQuestInstance` at runtime)
Quest definition. Contains:
- Display name and description
- `UOmegaQuestTypeScript` instanced objects for behavior
- Replayability settings

Quest runtime state is stored in `UOmegaSaveBase::quest_data`.

### `UOmegaStoryStateAsset`
A save-persistent state that activates/deactivates `UOmegaStoryStateScript` objects.

---

## World & Zones

### `UOmegaZoneData` (DA_Zone)
Describes a zone/area within a level. Referenced by `AOmegaZonePoint` actors.

### `UOmegaLevelData`
Describes an entire level: its soft reference, default zone, and metadata.

### `UZoneLegendAsset`
Classifies zone entities for filtering via `GetRegisteredZoneEntities_OfLegend`.

---

## Music

### `UOmegaBGM` (DA_BGM)
Background music asset. Can reference a `USoundBase` or `UMetaSoundSource`.

Properties include fade time, loop settings, and slot assignment.

Used by: `UOmegaSubsystem_GameInstance` BGM system

---

## Calendar & Time

### `UOmegaCalendar` (DA_Calendar)
Top-level calendar configuration. References weeks, months, and day periods.

### `UOmegaDay` / `UOmegaWeek` / `UOmegaWeekday` / `UOmegaMonth` (DA_Day/Week/Weekday/Month)
Hierarchical time period definitions for the in-game calendar system.

### `UOmegaDayPeriod` (DA_DayPeriod)
Defines named time-of-day periods (Morning, Afternoon, Night, etc.).

Used by: `UOmegaCalendarComponent`

---

## Preferences

### `UGamePreference` (DA_GamePreference)
A single user-facing setting mapped to an `FVector` value (supports up to 3 numeric axes).

Used by: `UOmegaSubsystem_GameInstance` preference system, stored in `UOmegaSaveBase::PreferenceValues`

---

## Actors & Spawning

### `UDA_EntityPreset` (DA_EntityPreset)
A preset for spawning instanced entities with predefined properties.

### `UDA_TransformPreset` (DA_TransformPreset)
A named set of transform configurations.

### `UDA_EffectsPreset` (DA_EffectsPreset)
A named collection of VFX/particle presets.

### `UDA_StaticMeshPreset` (DA_StaticMeshPreset)
A named static mesh configuration.

---

## Movement

### `UDA_Config_MoveMode` (DA_Config_MoveMode)
Movement mode configuration data used by character movement components.

---

## Asset Libraries

### `UDA_AssetLib` (DA_AssetLib)
A collection of arbitrary `UPrimaryDataAsset` references, useful for grouping related assets.

---

## Combat Sources

### `UDA_CombatSource` (DA_CombatSource)
Defines a source of combatants for encounters (e.g. which enemy types appear in a given area).

---

## Player

### `UDA_PlayerID` (DA_PlayerID)
Identifies a player slot or player profile.

---

## Developer

### `UDA_Developer` (DA_Developer)
Editor-only data loaded by `UOmegaSubsystem_Engine`. Contains developer configuration that affects build/editor behavior but is stripped from shipping builds.

---

## Modifier Collections

### `UDA_ActorModifierCollection` (DA_ActorModifierCollection)
A named collection of actor modifiers that can be applied as a group.

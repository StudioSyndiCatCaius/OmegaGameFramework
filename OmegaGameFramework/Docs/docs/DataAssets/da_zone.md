# Zone & Level Data Assets

These assets describe the areas of your game world: what levels exist, what zones within them, what streaming to apply, and how entities are categorized on the world map.

> See [Zone Actors](../Actors/actor_zone.md) for the actors that use these assets in the level.

---

## Zone Data

**Class:** `UOmegaZoneData`
**Create:** Content Browser → Data Asset → `OmegaZoneData`

Describes a gameplay zone — an area that can be loaded, unloaded, and associated with specific systems, music, and encounters.

### Properties

| Property | Description |
|---|---|
| **Streamed Levels** | Array of level name strings to stream in when this zone is active. |
| **Data Layers** | Data layers to activate when this zone loads. |
| **Zone BGM** | A `UOmegaBGM` asset to play automatically when this zone is entered. |
| **Default Encounter** | The default encounter asset for random/triggered combat in this zone. |
| **Systems Activated in Zone** | Gameplay System classes that activate automatically when this zone is loaded. |

---

## Level Data

**Class:** `UOmegaLevelData`
**Create:** Content Browser → Data Asset → `OmegaLevelData`

Metadata for an entire level (not just a sub-zone). Lets other systems reference a level by data asset rather than by hard path.

### Properties

| Property | Description |
|---|---|
| **Default Zone** | The `UOmegaZoneData` that represents the default zone for this level. |
| **Override Zone Data** | Fallback zone data used if the default zone is missing or unset. |

---

## Zone Legend Asset

**Class:** `UZoneLegendAsset`
**Create:** Content Browser → Data Asset → `ZoneLegendAsset`

Categorizes zone entities for the world map. Legends act as "types" — Enemy, NPC, Item, Dungeon, Shop, etc. Each `UZoneEntityComponent` references one legend, and the world map can filter entities by legend.

### Properties

| Property | Description |
|---|---|
| **Default Display Actor** | The actor class used to represent entities of this legend type on the world map. |

---

## How These Fit Together

```
Level
 └─ LevelData (metadata)
     └─ ZoneData (area within the level)
         ├─ Streamed sub-levels
         ├─ BGM
         ├─ Encounter
         └─ Auto-activated systems

Zone Entities (actors in the level)
 └─ ZoneEntityComponent
     └─ ZoneLegendAsset (what type of entity it is)
```

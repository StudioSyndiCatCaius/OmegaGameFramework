# Character Data Assets

These assets define what a character looks and behaves like — appearance, body, identity, and full entity configuration.

---

## Appearance

**Class:** `UOAsset_Appearance`
**Create:** Content Browser → Data Asset → `OAsset_Appearance`

Defines a character's full visual configuration: which skeletal mesh to use, which animations to play, what voice assets to use, and what UI icons to show.

### Properties

| Property | Description |
|---|---|
| **Actor Class** | The character class this appearance applies to. |
| **Mesh** | Skeletal mesh component configuration — mesh asset, materials, and overrides. |
| **Library — Anim** | An `UOmegaAssetLibrary_Animation` with all animations, montages, level sequences, and blend spaces for this character. |
| **Library — Voice** | An `UOmegaAssetLibrary_Sound` with voice lines, with a **Voice ID** for localized voice selection. |
| **Library — Slate** | An `UOmegaAssetLibrary_SlateBrush` with UI icons and portraits. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Apply** | Apply this appearance to a character actor. |

---

## Body Type

**Class:** `UOmegaBodyType`
**Create:** Content Browser → Data Asset → `OmegaBodyType`

Defines a customizable character body with multiple named slots (head shape, hair, skin color, etc.). Supports generating a complete skeletal mesh from a set of parameter values or from a random seed.

### Properties

| Property | Description |
|---|---|
| **Default Skin** | The default skin class applied when this body type is used. |
| **Base Skeleton** | The skeleton asset all body part meshes must be compatible with. |
| **Body Slots** | A map of slot names to `UOmegaBodySlot` definitions. Each slot is a customizable dimension of the character's look (a list of options, a float value, a color, etc.). |

### Body Slot Types

Each slot has a **Type** that defines what kind of value it holds:

| Type | Description |
|---|---|
| `BOOL` | A toggle (e.g. enable/disable beard). |
| `INTEGER` | An index into a list (e.g. hair style 0, 1, 2...). |
| `FLOAT` | A continuous value (e.g. height, weight). |
| `OBJECTLIST` | Pick from a list of mesh/material assets. |
| `COLOR` | An `FLinearColor` (e.g. skin tone, eye color). |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Generate Data from Seed** | Creates a full body appearance data struct from a random integer seed. |
| **Generate Mesh from Params** | Builds a skeletal mesh from an appearance data struct. |
| **Generate Mesh from Seed** | Builds a skeletal mesh from a seed directly. |
| **Generate on Component from Params / Seed** | Applies the generated mesh directly to a Skeletal Mesh Component. |
| **Get Slots** | Returns all body slot definitions. |

---

## Actor Identity

**Class:** `UOAsset_ActorIdentity`
**Create:** Content Browser → Data Asset → `OAsset_ActorIdentity`

Configures how an actor initializes when it spawns. Applies modifier collections at different points in the actor lifecycle.

### Properties

| Property | Description |
|---|---|
| **Mods — Init** | Modifiers applied during identity initialization. |
| **Mods — Construct** | Modifiers applied during actor construction. |
| **Mods — BeginPlay** | Modifiers applied at BeginPlay. |
| **Mods — Tag Event** | A map of Gameplay Tags to modifier collections — when that tag fires on the actor, the corresponding modifiers are applied. |

---

## Combatant Identity

**Class:** `UOAsset_CombatantIdentity`
**Create:** Content Browser → Data Asset → `OAsset_CombatantIdentity`

Extends the Actor Identity with combat-specific data: attribute modifiers, damage modifiers, and skill sources. Assign this to a Combatant Component as the identity source to define what that character's combat role is.

### Properties

| Property | Description |
|---|---|
| **Combat Sources** | An `FOmegaCombatantSources` struct containing attribute modifiers, damage modifiers, and skill sources for this identity. |
| *(All Actor Identity properties)* | Inherits all modifier collection fields from Actor Identity. |

---

## Entity Preset

**Class:** `UOmegaEntityPreset`
**Create:** Content Browser → Data Asset → `OmegaEntityPreset`

A complete snapshot of a character's initial state — level, equipment, inventory, skills, and tags. Apply it to a Combatant Component to instantly configure it.

### Properties

| Property | Description |
|---|---|
| **XP Levels** | Map of `UOmegaLevelingAsset` to starting level for each leveling track. |
| **Equipment** | Map of `UEquipmentSlot` to starting equipped item. |
| **Inventory** | Map of item data assets to starting quantities. |
| **Skills** | Array of skill data assets the character starts with. |
| **Entity Tags** | Gameplay Tags assigned to the entity at start. |
| **Params Int** | Named integer parameters on the entity. |
| **Params String** | Named string parameters on the entity. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Entity Data** | Returns the preset as an `FOmegaEntity` struct. |
| **Apply to Combatant** | Directly applies all preset values to a Combatant Component. Toggle **Even If Save Entity** to apply even if the combatant already has save data. |

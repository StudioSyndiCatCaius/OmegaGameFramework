# Combat Data Assets

These assets define the building blocks of Omega's combat system: stats, damage, factions, and equipment slots.

---

## Attribute

**Class:** `UOmegaAttribute`
**Create:** Content Browser → Data Asset → `OmegaAttribute`

Defines a single stat — HP, MP, ATK, DEF, SPD, etc. Every combatant's attribute set is a collection of these assets.

### Properties

| Property | Description |
|---|---|
| **Max Value** | The hard maximum this attribute can reach. |
| **Start Value Percentage** | The initial current value as a 0–1 fraction of the max (e.g. `1.0` = start full, `0.0` = start empty). |
| **Is Value Static** | If enabled, the value is always **Max Value** regardless of level or rank. |
| **Rank Value Curves** | A curve that maps character level/rank to the attribute's max value. Used when **Is Value Static** is off. |
| **Value Category Adjustments** | Tag-based multipliers — give certain categories of characters (by gameplay tag) a bonus or penalty to this attribute. |
| **Allow Modifiers** | If disabled, no external modifier can change this attribute's value. |
| **Attribute Color** | Display color for UI (health bars, stat screens). |
| **Damage Color** | Color used when damage to this attribute is shown. |
| **Script** | An instanced custom script for special attribute calculation logic. |
| **Display formatting** | Rounding mode, digits, grouping — controls how the value is formatted as text. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Attribute Value** | Returns the calculated value for a given level, rank, and value category tag. |
| **Get Attribute Value Display Text** | Formats a raw value using the asset's display settings (rounding, digits). |

---

## Attribute Set

**Class:** `UOmegaAttributeSet`
**Create:** Content Browser → Data Asset → `OmegaAttributeSet`

A collection of `UOmegaAttribute` assets assigned to a Combatant Component. The set determines which stats the combatant has.

### Properties

| Property | Description |
|---|---|
| **Attributes** | Array of `UOmegaAttribute` assets that make up this set. |
| **Inherited Set** | Another attribute set to inherit from — all attributes in the parent are included. |

---

## Damage Type

**Class:** `UOmegaDamageType`
**Create:** Content Browser → Data Asset → `OmegaDamageType`

Classifies damage — Physical, Fire, Ice, Poison, etc. Damage modifiers can check the damage type to apply resistances, weaknesses, or special effects.

### Properties

| Property | Description |
|---|---|
| **Damage Script** | An instanced script object with two overridable Blueprint events: **On Damage Applied** (return a modified damage value) and **On Effect Applied** (trigger a special effect). |

---

## Faction

**Class:** `UOmegaFaction`
**Create:** Content Browser → Data Asset → `OmegaFaction`

Defines a team or alignment. The combatant's faction determines how the targeting and affinity system classifies other combatants relative to it.

### Properties

| Property | Description |
|---|---|
| **Faction Name** | Display name (e.g. "Heroes", "Enemies", "Neutral"). |
| **Faction Icon** | UI icon for this faction. |
| **Faction Color** | Color used in UI when showing faction info. |
| **Faction Tag** | A Gameplay Tag uniquely identifying this faction. |
| **Faction Affinities** | Map of other faction tags to affinity values: `Ally`, `Enemy`, or `Neutral`. |

**How affinities work:** When `GetAffinityToCombatant` is called on a combatant, it looks up the target's faction tag in this map and returns the relationship.

---

## Equipment Slot

**Class:** `UEquipmentSlot`
**Create:** Content Browser → Data Asset → `OmegaEquipmentSlot`

Defines a slot in a character's equipment system — Weapon, Helmet, Chest, Accessory, etc. The number and types of slots a combatant has are entirely up to you.

### Properties

| Property | Description |
|---|---|
| **Required Tags** | Gameplay Tags an item must have to be placed in this slot. Leave empty to accept any item. |
| **Accepted Categories** | Tag-based category filter for accepted item types. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Can Slot Equip Item** | Returns true if the given data asset is valid for this slot. |

---

## Attribute Modifier Struct (`FOmegaAttributeModifier`)

Used throughout the combat system as a lightweight modifier applied to a specific attribute. Contains:

| Field | Description |
|---|---|
| **Attribute** | Which `UOmegaAttribute` to modify. |
| **Incrementer** | A flat value added to the attribute (can be negative). |
| **Multiplier** | A multiplier applied to the attribute (1.0 = no change, 1.25 = +25%). |

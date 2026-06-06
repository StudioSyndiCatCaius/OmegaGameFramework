# Demo Data Assets (OmegaDemo Module)

These assets come from the **OmegaDemo** module and serve as ready-made examples of common game data types. They are fully functional and can be used directly in your game, or used as references when building your own data asset types.

---

## Common Character

**Class:** `UOAsset_CommonCharacter`
**Create:** Content Browser → Data Asset → `OAsset_CommonCharacter`

A complete character definition — appearance, level, attributes, equipment, inventory, and skills all in one asset. Assign to an NPC, enemy, or ally to fully configure them from data.

### Properties

| Property | Description |
|---|---|
| **Appearance — Preset** | A `UOAsset_Appearance` preset asset to use for this character's look. |
| **Appearance — Custom** | An instanced custom appearance override (used if no preset is set). |
| **Flow Asset** | A dialogue or flow graph asset associated with this character. |
| **Level** | The character's starting level. |
| **Attributes** | Map of Gameplay Tag → float for any attribute overrides at this level. |
| **Equipment** | Map of Gameplay Tag (slot) → item data asset for starting equipment. |
| **Inventory** | Map of item data asset → quantity for starting items. |
| **Skills** | Array of skill data assets this character knows. |
| **Gambit** | An AI gambit asset defining this character's combat decision logic. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Attributes** | Returns the attribute override map. |
| **Get Appearance** | Returns the effective appearance (preset takes priority over custom). |

---

## Common Item

**Class:** `UOAsset_CommonItem`
**Create:** Content Browser → Data Asset → `OAsset_CommonItem`

A general-purpose consumable or tradeable item. Implements the inventory collection interface so it works with the Combatant's inventory system and trade systems.

### Properties

| Property | Description |
|---|---|
| **Rank** | Item rank — affects stat scaling if the item is also equippable. |
| **Collection Max** | Maximum stack size (default `99`). |
| **Trade Costs** | Map of item data assets → quantities required to trade for this item. |
| **Trade Costs Tagged** | Tag-based trade requirements for named trade types. |

---

## Common Equipment

**Class:** `UOAsset_CommonEquipment`
**Create:** Content Browser → Data Asset → `OAsset_CommonEquipment`
**Extends:** `UOAsset_CommonItem`

An equippable item with a type, attribute bonuses, visual appearance, and combat modifiers.

### Properties

| Property | Description |
|---|---|
| **Type** | The equipment type asset (Sword, Armor, Ring, etc.) — see **Common Equip Type** below. |
| **Rank** | Item rank — scales attribute bonuses. |
| **Equip Conditions** | Conditions that must pass for the item to be equipped (level requirements, tag requirements, etc.). |
| **Attributes** | Map of `UOmegaAttribute` → value for stat bonuses when equipped. |
| **Combat Modifiers** | An `FOmegaCombatantSources` of attribute mods, damage mods, and skills granted when equipped. |
| **Appearance** | The visual appearance asset for this equipment. |
| **Default to Type Appearance** | If enabled, falls back to the type's appearance if this item has none. |
| **Use Type — Rank Attribute Scaling** | Apply the type's rank-based attribute scaling to this item. |
| **Use Type — Attribute Mods** | Include the type's attribute modifiers. |
| **Use Type — Damage Mods** | Include the type's damage modifiers. |
| **Use Type — Skills** | Include the skills the type provides. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Is of Type** | Returns true if this equipment's type matches any type in the given array. |

---

## Common Equip Type

**Class:** `UOAsset_Common_EquipType`
**Create:** Content Browser → Data Asset → `OAsset_Common_EquipType`

Defines a category of equipment (Sword, Staff, Light Armor, Heavy Armor, etc.) with shared stat scaling and modifiers. Equipment assets can inherit from their type to avoid duplicating values.

---

## Common Skill

**Class:** `UOAsset_CommonSkill`
**Create:** Content Browser → Data Asset → `OAsset_CommonSkill`

A skill or ability that characters can learn. Defines what the skill costs, what it does, and under what conditions it can be used. References an ability class for actual execution.

### Properties

| Property | Description |
|---|---|
| **Rank** | Skill rank — affects power scaling. |
| **Conditions — Can Use** | Conditions that must all pass for this skill to be usable. |
| **Skill Config** | The skill behavior configuration — costs, target selection, effects, and animation. |
| **Append Effects Description** | If enabled, effect descriptions are appended to the skill's tooltip text. |

---

## Common Pickup

**Class:** `UOAsset_CommonPickup`
**Create:** Content Browser → Data Asset → `OAsset_CommonPickup`

Configuration asset for pickup actors. Defines what item the pickup gives, how many, and how the actor behaves (auto-collect range, effects, sounds).

---

## Common Interactable

**Class:** `UOAsset_CommonInteractable`
**Create:** Content Browser → Data Asset → `OAsset_CommonInteractable`

Configuration for interactable actors — what flow/dialogue runs on interaction, conditions for interaction, and any items or effects granted.

---

## Turn Effect

**Class:** `UOAsset_TurnEffect`
**Create:** Content Browser → Data Asset → `OAsset_TurnEffect`

A turn-based status effect asset used by the Demo's combat system. Defines what happens at the start and end of turns while this effect is active.

# Combat Function Libraries

Covers: `F_Combatant`, `F_Equipment`, `F_Inventory`, `F_ScriptedEffects`, `OmegaFunctions_CombatAction`, `OmegaFunctions_CombatantFilter`

---

## Combatant Functions (`UCombatantFunctions`)

General queries and operations on Combatant Components.

| Node | Description |
|---|---|
| **Check Combatant Conditions** | Evaluate a list of conditions against a combatant. Returns success/fail. |
| **Can Combatant Use Skill** | Returns true if the combatant can use a skill right now. Toggle **Check Attribute Cost** to also validate that it has enough resources. |
| **Get Combatant With Highest Attribute Value** | From an array of combatants, returns the one with the highest value for a given attribute. Toggle **Use Current Value** to compare current vs max. |
| **Get Combatant From Target Selection** | Resolves a target selection data object to an array of combatant components. |
| **Get All Combatants With Data Asset** | Finds all active combatants whose source data asset matches the given asset. |
| **Get Data Assets From Combatants** | Returns the source data assets from an array of combatants. |
| **Get First Combatant With Data Asset** | Returns the first combatant matching a data asset. Outputs a **Success** exec. |
| **Get All Combatants of Faction** | Returns all combatants registered in the world that belong to a specific faction. |
| **Check Attribute Value** | Compares a combatant's attribute value against a target value using a method (Equal, Greater, Less, etc.). |
| **Filter Combatants by Tags** | From an array, keeps only combatants that have (or don't have) given gameplay tags. Toggle **Exact** and **Exclude**. |
| **Filter Combatants by Faction** | From an array, keeps only combatants of a given faction. Toggle **Exclude** to invert. |
| **Get Player Combatant** | Returns the Combatant Component belonging to the player at the given index. |
| **Notify Combatant Faction** | Sends a named notify to all combatants of a specific faction. |
| **Notify Combatant Faction of Tag** | Sends a notify to all combatants whose faction matches a gameplay tag. |
| **Make Attribute Mods From Flat Values** | Creates an `FOmegaAttributeModifier` array from a flat attribute→float map. Toggle **As Multiplier** to treat values as multipliers instead of increments. |
| **Attribute Mods — Scale** | Scales all modifier values in an array by a multiplier. |
| **Attribute Mods — Combine** | Merges two modifier arrays into one. Toggle **Flatten** to sum duplicates. |
| **Consume Skill Attributes** | Deducts the attribute costs of a skill from the combatant (e.g. spend MP). |
| **Get Combatant Distance to Active Target** | Returns the distance between a combatant and its active target. |
| **Is Combatant Active Target in Range** | Returns true if the active target is within the given range. |
| **Select First Effect With Context** | From an array of effects, returns the first one whose context matches. |
| **Remove Gameplay Effects With Context** | Removes all active effects on a combatant that match a specific context object. |
| **Remove Gameplay Effects of Class** | Removes all active effects of a specific class. Toggle **Include Child Types**. |
| **Apply Effect From Container** | Applies a gameplay effect from a container object onto a combatant. |
| **Does Combatant Have Tag** | Returns true + exec pin if a combatant has a specific tag. |
| **Does Combatant Have Effect With Tag** | Returns true + exec pin if a combatant has an active effect with matching tags. |

---

## Equipment Functions (`UOmegaEquipmentFunctions`)

| Node | Description |
|---|---|
| **Is Item Equippable** | Returns true if a data asset item can be placed in a specific equipment slot on a combatant. |
| **Filter Equippable Items** | From a list of items, returns only those valid for a given slot. |
| **Get Equippable Items From Inventory** | Returns all inventory items that can go into a given slot, optionally including items from other sources. |
| **Get Equipment From Linked Asset List** | Extracts an equipment map (slot → item) from a named asset list. |

---

## Inventory Functions (`UDataAssetCollectionFunctions`)

Helpers for item quantities, trading, and cost calculation.

| Node | Description |
|---|---|
| **Scale Item Map** | Multiplies all quantities in an item→int map by a scale factor. |
| **Get List Trade Cost — Total** | Returns the total trade cost for a list of items under a given trade tag. |
| **Get List Trade Cost — One** | Returns the cost of a specific trade asset from a list. |
| **Get Data Asset Trade Value — One** | Returns how much of one specific asset is required to trade for a given item+amount. |
| **Get Data Asset Trade Value — All** | Returns all trade costs for a given item+amount. |
| **Can Inventory Perform Trade — For Asset** | Returns true if a combatant's inventory has enough resources to trade for a specific asset. |
| **Can Inventory Perform Trade — For List** | Returns true if a combatant can afford all items in a trade list. Toggle **Invert** to check for inability. |
| **Perform Trade — Single** | Execute a trade for one asset. Returns **Outcome** success. Toggles: **Invert** (reverse the transfer), **Force**, **Withhold Asset** (don't actually give the item). |
| **Perform Trade — List** | Execute a trade for a list of assets. |

---

## Scripted Effects (`UOmegaScriptedEffectFunctions`)

| Node | Description |
|---|---|
| **Apply Scripted Effects — List** | Apply an array of scripted effect objects to a target combatant from an instigator. |
| **Apply Scripted Effects — Asset** | Apply effects defined in a `UOAsset_EffectsPreset` data asset. |
| **Apply Scripted Effects — Source** | Apply effects from a source object filtered by a tag. |
| **Apply Custom Scripted Effect to Combatant** | Apply a custom scripted effect struct directly. |
| **Get Effects Description** | Returns a formatted `FText` listing all effect descriptions, joined by a delimiter. |

---

## Combat Action Selection (`UCombatantActionSelectFunctions`)

| Node | Description |
|---|---|
| **Select Combat Action by Script** | Uses a script object to determine the best action and targets for a combatant. Returns the chosen ability class and target list. |

---

## Combatant Filter (`UCombatantFilterFunctions`)

| Node | Description |
|---|---|
| **Filter Combatants by Script** | Passes an array of combatants through a `UCombatantFilter` Blueprint subclass. Returns only those that pass the filter. |
| **Select First Skill That Can Target** | From a list of skill assets, returns the first one that can validly target a given combatant. |

# Combatant Component

**Component class:** `UCombatantComponent`
**Add to:** Any actor that participates in combat — player characters, enemies, bosses, NPCs, summons.

The Combatant Component is the core of Omega's combat system. It manages a character's stats (attributes), deals and receives damage, runs abilities, tracks targets, stores an inventory, handles equipment, and tracks XP and levels — all in one component.

---

## Setup

### Details Panel Properties

| Property | Description |
|---|---|
| **Combatant Data Asset** | The primary data asset representing this character (links name, portrait, description). |
| **Faction** | The `UOmegaFaction` data asset this combatant belongs to. |
| **Attribute Set** | The `UOmegaAttributeSet` defining which stats this combatant has (HP, MP, ATK, etc.). |
| **Level** | Starting level used to calculate base attribute values from the attribute set. |
| **Combatant Tags** | Gameplay Tags on this combatant — used for filtering and ability conditions. |
| **Granted Abilities** | Ability classes to grant automatically at BeginPlay. |
| **Default Gambit** | An AI decision asset — used when `bAutorunAbilitySelector` is enabled. |
| **Override Max Attributes** | Force-override the maximum value for specific attributes, ignoring the attribute set curve. |

---

## Attributes

Stats are defined by `UOmegaAttribute` data assets. Each attribute has a current value and a maximum value.

| Node | Description |
|---|---|
| **Apply Attribute Damage** | Deal damage to an attribute. Pass the attribute, amount, instigator, and optionally a damage type and hit result. Returns final damage dealt. |
| **Attribute - Get Value** | Returns both the current and max value for an attribute. |
| **Attribute - Get Percentage** | Returns current/max as a 0–1 float. Useful for health bars. |
| **Attribute - Get Base Value** | Returns the unmodified base value before modifiers are applied. |
| **Attribute - Get Map Values** | Returns all attribute values as a map. Toggle **Current** for current vs max values. |
| **Set Current Attribute Value** | Directly set the current value of an attribute. |
| **Set Current Attribute Values** | Set multiple attribute values at once. |
| **Set Override Max Attribute** | Override the max for one attribute at runtime. |
| **Initialize Attributes** | Re-run attribute initialization (useful after changing level or attribute set). |
| **Change Attribute Set** | Swap to a different attribute set at runtime. |
| **Set Combatant Level** | Change level and optionally reinitialize stats. |

---

## Abilities

Abilities are `AOmegaAbility` Blueprint actor classes. The combatant manages which abilities are granted and running.

| Node | Description |
|---|---|
| **Set Ability Granted** | Grant or revoke a single ability class. |
| **Set Abilities Granted** | Grant or revoke a list of ability classes at once. |
| **Activate Ability** | Start an ability. Pass a Context object for extra data. Returns the ability instance and a **Success** bool. |
| **Stop Ability** | Stop a running ability. Pass **Cancel** = true to treat it as a cancellation. |
| **Cancel Abilities With Tags** | Cancel all abilities whose tags match the given container. |
| **Cancel All Abilities** | Cancel every currently running ability. |
| **Get Ability** | Get a granted ability instance by class. Outputs a **Success** bool. |
| **Is Ability Active** | Returns true if a specific ability is currently running. |
| **Get Active Abilities** | Returns all currently running ability instances. |
| **Get Active Abilities With Tags** | Filter running abilities by tag. |
| **Get Granted Abilities** | Returns all granted ability instances (running or not). |
| **Set Abilities Disabled** | Disable or re-enable all ability activation. |

---

## Effects (Status Effects)

Effects are `AOmegaGameplayEffect` Blueprint actor classes applied on top of a combatant.

| Node | Description |
|---|---|
| **Create Effect** | Apply an effect to this combatant. Pass the class, an optional instigator combatant, and a context object. Returns the effect instance. |
| **Remove All Effects** | Remove every active effect. |
| **Remove Effects With Tags** | Remove all effects whose tags match. |
| **Get All Effects** | Returns all active effect instances. |
| **Get Effects With Tags** | Filter active effects by tag. |
| **Get Effects of Category** | Filter active effects by category tag. |
| **Has Effect With Tags** | Returns true if any active effect has the given tags. |
| **Get Active Effect of Class** | Get a specific effect instance by class. |
| **Set Effects Disabled** | Disable or re-enable effect application. |

---

## Targeting

A combatant can hold a list of targets and one designated "active target."

| Node | Description |
|---|---|
| **Set Target Registered** | Add or remove a combatant from the target list. |
| **Set Targets Registered** | Add/remove a list of combatants. Toggle **Clear List First** to reset before adding. |
| **Clear Target List** | Remove all targets. |
| **Set Active Target** | Set which combatant in the list is the primary target. |
| **Try Get Active Target** | Returns the active target. Outputs **Is Valid** bool. |
| **Cycle Active Target** | Move forward or backward through the target list by an amount. |
| **Clear Active Target** | Remove the active target without clearing the list. |
| **Get Registered Target List** | Returns all targets in the list. |
| **Get Active Target** | Returns the current primary target. |

| Event | Fires when... |
|---|---|
| `OnTargetAdded` | A target is added to or removed from the target list |
| `OnAddedAsTarget` | This combatant was added/removed as another combatant's target |
| `OnActiveTargetChanged` | The primary active target changed |

---

## Factions

| Node | Description |
|---|---|
| **Set Faction Asset** | Change this combatant's faction at runtime. |
| **Get Faction Name / Color / Tag** | Quick access to faction display data. |
| **Get Affinity to Combatant** | Returns the affinity (Ally, Enemy, Neutral) between this combatant and another. |
| **Filter Combatants by Affinity** | Filter a list of combatants to only include those with a given affinity. |

| Event | Fires when... |
|---|---|
| `OnFactionChanged` | The faction assignment changes |

---

## Skills

Skills are `UPrimaryDataAsset` objects representing known moves or techniques. The combatant collects them from multiple sources (equipment, inventory, direct assignment).

| Node | Description |
|---|---|
| **Skills - Add** | Add or remove a single skill. |
| **Skills - Add (List)** | Add or remove multiple skills at once. |
| **Skills - Get All** | Returns all skills from all sources. |
| **Skills - Owned?** | Returns true if the combatant has a specific skill. |

---

## Inventory

Items are `UPrimaryDataAsset` objects stored with quantities.

| Node | Description |
|---|---|
| **Inventory - Give Item** | Add an amount of an item. Returns false if the max would be exceeded. |
| **Inventory - Give Item (List)** | Add multiple items at once via a map. |
| **Inventory - Transfer Item** | Move an item to another combatant. |
| **Inventory - Transfer ALL** | Move the entire inventory to another combatant. |
| **Inventory - Set** | Replace the inventory with a new map. Toggle **Clear First**. |
| **Inventory - Clear** | Remove all items. |
| **Inventory - Get** | Returns the inventory as a map (asset → quantity). Pass a **Minimum** to filter out low quantities. |
| **Inventory - Get Amount** | Returns how many of a specific item are held. |
| **Inventory - Has Minimum?** | Returns true if the combatant has at least the given amounts of each item. |
| **Inventory - Override Max** | Override the max stack size for a specific item. |

| Event | Fires when... |
|---|---|
| `OnInventoryEdit` | An item amount changes |

---

## Equipment

Equipment uses `UEquipmentSlot` data assets as slot definitions.

| Node | Description |
|---|---|
| **Equipment - Set in Slot** | Equip an item into a specific slot. |
| **Equipment - Set ALL** | Replace all equipment at once via a map. |
| **Equipment - Clear Slot** | Remove the item from a slot. |
| **Equipment - Get (In Slot)** | Get what's equipped in a specific slot. Outputs a **Result** bool. |
| **Equipment - Get (All)** | Returns all equipment as a slot→item map. |
| **Equipment - Get (EquipList)** | Returns all equipped items as a flat array. |
| **Equipment - Can Set in Slot?** | Returns true if the item is valid for that slot. |

| Event | Fires when... |
|---|---|
| `OnSlot_Equip` | An item is equipped |
| `OnSlot_Unequip` | An item is removed |

---

## XP and Leveling

XP types are defined by `UOmegaLevelingAsset` data assets — you can have multiple independent leveling tracks (main level, weapon proficiency, etc.).

| Node | Description |
|---|---|
| **XP - Set** | Add or set XP for a leveling type. Toggle **Added** to add or set. |
| **XP - Set All** | Set XP for multiple types at once. |
| **XP - Get** | Returns the current XP for a type. |
| **XP - Get Values** | Returns the min XP, max XP, and percentage for the current level. |
| **XP - Get All** | Returns all XP as a map. |
| **Level - Set** | Force-set the level for a leveling type. |
| **Level - Get** | Returns the current level for a type. |

| Event | Fires when... |
|---|---|
| `OnXpChanged` | XP amount changes |
| `OnLevelChanged` | Level changes |

---

## AI / Gambit

Gambits (`UOmegaGambit_Asset`) define AI decision logic — which ability to use and when.

| Node | Description |
|---|---|
| **Run Default Gambit** | Execute the combatant's default gambit. |
| **Run Gambit** | Execute a specific gambit. Toggle **Replace Default** to swap it in permanently. |
| **Select Ability by Utility** | Query the gambit for which ability to use next. Returns the ability class and a context object. |

**Details panel AI properties:**

| Property | Description |
|---|---|
| **Auto-run Ability Selector** | If true, the combatant automatically selects and activates abilities from its gambit. |
| **Ability Selector Frequency** | How often (in seconds) the selector runs. |
| **Cancel Ability on Selector Change** | Cancel the running ability when the selector picks a new one. |

---

## Modifier Sources

These control what feeds into the combatant's damage and attribute calculations.

| Node | Description |
|---|---|
| **Set Source Active (MASTER)** | Add or remove an object from the master modifier source list. |
| **Set Source Active (Attribute Modifier)** | Add or remove an attribute modifier source. |
| **Set Source Active (Skills)** | Add or remove a skill source. |
| **Set Source Active (Damage Modifiers)** | Add or remove a damage modifier source. |

---

## Tags

| Node | Description |
|---|---|
| **Set Combatant Tags Active** | Add or remove tags from the combatant's tag container. |
| **Get Combatant Tags** | Returns all combatant tags. |
| **Combatant Has Tag** | Returns true if the combatant has a specific tag. |
| **Combatant Has Any Tag** | Returns true if the combatant has any tag from the container. |
| **Combatant Has All Tags** | Returns true if the combatant has all tags in the container. |

---

## Entity Params

Named key→value parameters stored directly on the combatant.

| Node | Description |
|---|---|
| **Param (Bool/Int) - Set** | Set a named parameter value. |
| **Param (Bool/Int) - Get** | Get a named parameter value. |

---

## Notify

A simple broadcast system for sending named signals across the combatant.

| Node | Description |
|---|---|
| **Combatant Notify** | Fire a named notify with an optional flag string. Received by abilities, the owning actor, and extension components. |

| Event | Fires when... |
|---|---|
| `OnCombatantNotify` | A notify is fired on this combatant |

---

## General Events

| Event | Fires when... |
|---|---|
| `OnDamaged` | This combatant takes damage (includes attribute, amount, instigator, type, hit) |
| `OnUpdated` | Any stat or modifier changes — use this to refresh UI |
| `OnDataAssetChanged` | The primary data asset (character definition) is swapped |

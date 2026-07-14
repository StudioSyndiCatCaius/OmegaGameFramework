# Leveling (Asset & Interfaces)

Omega's leveling system is data-driven. XP tracking lives on the **Combatant Component** — this page covers the data asset that defines a leveling curve and the interfaces used to plug into it.

> For the actual XP and level nodes (Set XP, Get Level, etc.), see the **XP and Leveling** section in [Combatant Component](comp_combatant.md).

---

## UOmegaLevelingAsset (Data Asset)

Defines a single leveling track — the curve that maps XP to a level number.

**Create one:** Content Browser → Data Asset → `OmegaLevelingAsset`

You can have multiple leveling assets on one combatant (e.g. a main level, a weapon proficiency, a crafting level).

### Details Panel Properties

| Property | Description |
|---|---|
| **XP Name** | The display name for this XP type (e.g. "Experience", "Weapon Mastery"). |
| **Max Rank** | The maximum level achievable. |
| **Value Curve** | A `FRuntimeFloatCurve` — the X axis is level, the Y axis is the XP required to reach that level. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get Level from XP** | Returns the level that corresponds to a given amount of XP. |
| **Get XP from Level** | Returns the minimum and maximum XP values for a given level. |

---

## IActorInterface_Leveling

Implement this on an actor to provide an XP rate multiplier — useful for bonuses from equipment, skills, or world buffs.

| Method | Description |
|---|---|
| **Get XP Rate Offset** | Returns a float multiplier applied to XP gains. Return `1.0` for no change, `2.0` to double XP, etc. |

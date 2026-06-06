# Miscellaneous Data Assets

These assets cover utility, configuration, and modifier functionality used across many systems.

---

## Actor Modifier Collection

**Class:** `UOAsset_ActorModifierCollection`
**Create:** Content Browser → Data Asset → `OAsset_ActorModifierCollection`

A reusable package of actor modifier scripts that can be applied to actors as a group. Collections can import other collections, making it easy to compose complex setups from smaller reusable pieces.

### Properties

| Property | Description |
|---|---|
| **Imported Collections** | Other modifier collections whose modifiers are included as part of this one. |
| **Modifiers** | Instanced modifier script objects to apply. |
| **Conditions** | Condition objects that must all pass before modifiers are applied. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Get All Modifiers** | Returns all modifiers including those from imported collections. |
| **Apply All Modifiers** | Applies modifiers to an actor if conditions pass. Toggle **Ignore Conditions** to skip the condition check. |

---

## Effects Preset

**Class:** `UOAsset_EffectsPreset`
**Create:** Content Browser → Data Asset → `OAsset_EffectsPreset`

A preset combining a combat source with timed effect triggers. Used for status effects, buffs, and debuffs that apply modifiers and trigger effects over turns or seconds.

Extends `UOAsset_CombatSource` so it also provides attribute modifiers, damage modifiers, and skills.

### Properties

| Property | Description |
|---|---|
| **Effects Default** | Effects applied passively while the preset is active. |
| **Effects Turn Start** | Effects applied at the start of this combatant's turn. |
| **Effects Turn End** | Effects applied at the end of this combatant's turn. |
| **Effects Named** | Named custom effects triggered on-demand. |
| **Turns Initial** | Starting duration in turns. |
| **Turns Max** | Maximum turn duration cap. |
| **Lifespan** | Duration in seconds (for real-time use instead of turn-based). |

---

## Static Mesh Preset

**Class:** `UOmegaStaticMeshPreset`
**Create:** Content Browser → Data Asset → `OmegaStaticMeshPreset`

Configuration for spawning or applying a static mesh with a specific setup — materials, scale, collision, and tags.

### Properties

| Property | Description |
|---|---|
| **Static Mesh** | The mesh asset to use. |
| **Scale** | Scale to apply (default `1, 1, 1`). |
| **Materials by Index** | Map of material slot index → material override. |
| **Materials by Slot** | Map of slot name → material override. |
| **Collision Channel** | Collision channel for the mesh (default `WorldStatic`). |
| **Hidden in Game** | If enabled, the mesh is invisible during gameplay. |
| **Actor Tags** | Tags applied to the spawned actor. |

---

## Transform Preset

**Class:** `UOAsset_TransformPreset`
**Create:** Content Browser → Data Asset → `OAsset_TransformPreset`

Stores a transform (location, rotation, scale) for applying to actors or widgets.

### Properties

| Property | Description |
|---|---|
| **Transform** | The location, rotation, and scale to store. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Apply to Actor** | Set the actor's transform to this preset. |
| **Apply to Widget** | Set a widget's render transform to this preset. |

---

## Movement Mode Config

**Class:** `UOmegaComponentConfig_PawnMove`
**Create:** Content Browser → Data Asset → `OmegaComponentConfig_PawnMove`

Configuration for a Character Movement Component. Attach modifier scripts to this asset to configure movement properties (walk speed, jump height, friction, etc.) in a data-driven way.

### Properties

| Property | Description |
|---|---|
| **Modifiers** | Instanced `UOmegaComponentConfig_PawnMove_Modifier` objects. Override **Modify Component** in each one to set movement values. |

### Blueprint Nodes (on the asset)

| Node | Description |
|---|---|
| **Modify Component** | Apply all modifier scripts to a Character Movement Component. |

---

## Combat Source

**Class:** `UOAsset_CombatSource`
**Create:** Content Browser → Data Asset → `OAsset_CombatSource`

A reusable bundle of combat modifiers: attribute modifiers, damage modifiers, and skill sources. Acts as a modifier source that can be registered with a Combatant Component.

### Properties

| Property | Description |
|---|---|
| **Sources** | An `FOmegaCombatantSources` struct containing the attribute mods, damage mods, and skill sources this asset provides. |

---

## Player ID

**Class:** `UOAsset_PlayerID`
**Create:** Content Browser → Data Asset → `OAsset_PlayerID`

Identifies a player slot with an index and color. Used in multiplayer setups or UI systems that need to distinguish players.

### Properties

| Property | Description |
|---|---|
| **Default Index** | The default player index (`-1` = unassigned). |
| **Player Color** | The color representing this player in UI. |

---

## Developer

**Class:** `UOAsset_Developer`
**Create:** Content Browser → Data Asset → `OAsset_Developer`

Team member metadata. Used for in-game credits screens and organizational tooling. Loaded by the Engine Subsystem.

### Properties

| Property | Description |
|---|---|
| **Display Name** | The developer's name. |
| **Dev Color** | An associated color for UI display. |
| **Tags** | Organizational Gameplay Tags (role, team, etc.). |

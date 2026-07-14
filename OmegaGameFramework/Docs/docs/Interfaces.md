# Interfaces

OmegaGameFramework defines a set of Blueprint-compatible interfaces that decouple systems from concrete types. Implement these on your Blueprints (Class Settings → Interfaces) to participate in the relevant system. In the interface picker they appear with a `♎` prefix, e.g. **♎Data🔴 - Menu Source**.

---

## Data Interfaces

These are "query" interfaces — they let any object expose standard data to systems without the system knowing the concrete type.

### `DataInterface_General`
The most commonly used interface. Implement it on any object that has a name, description, icon, or color.

| Event | Description |
|--------|-------------|
| `General - Get Config` | Return display name, description, icon brush, color, label, and meta config in one call |
| `General - Get GameplayTags` | Return the object's category tag and gameplay tags |
| `Tag - Event` / `Tag - Query` / `Tag - Utility` | Respond to tag-based events, boolean queries, and utility scoring |
| `Param - Float` / `Param - Int` / `Param - String` / `Param - Object` | Return a named parameter value by tag |

Used by: UI widgets, tooltips, data lists, and most data assets (built into `UOmegaDataAsset`).

### `DataInterface_ObjectHierarchy`
Hierarchical data relationships.

| Event | Description |
|--------|-------------|
| `Hierarchy - Get Parent` | Return the parent object in a hierarchy |
| `Hierarchy - Get Children` | Return all child objects |

### `DataInterface_Combatant`
Implement on any object that should affect combat: equipment, effects, traits, skills. Covers attribute modifiers, damage modification, and skill sources in one interface.

| Event | Description |
|--------|-------------|
| `💪Combatant - Modify Attributes` | Return an array of attribute modifiers (flat + multiplier) |
| `💪Combatant - Modify Damage` | Return a modified damage value in the damage pipeline |
| `💪Combatant - Get Skills` | Return skill assets granted to the combatant |
| `💪Combatant - Get Config` | Return combatant source config (e.g. use as damage modifier) |
| `💪Combatant - On Event` | React to combatant tag events |
| `💪Combatant - Append Tags` | Add extra gameplay tags to the combatant |

### `DataInterface_Skill`
Implement on data assets used as skills.

| Event | Description |
|--------|-------------|
| `🔥Skill - Can Be Used?` | Guard condition for skill use |
| `🔥Skill - Get Config` | Return use costs, target filter/selector, and required skills |
| `🔥Skill - Get Scripted Animation` | Animation played when the skill executes |
| `🔥Skill - Get Scripted Effects` | Effects applied when the skill executes |
| `🔥Skill - Check Utility` | AI scoring for target selection (single & multi target) |
| `🔥Skill - Get Sequences` / `Get Montages` | Level sequences / montages by name (e.g. Charge, Execution) |

### `DataInterface_DataAsset`
Named data asset access.

| Event | Description |
|--------|-------------|
| `GetDataAsset_Named(Name)` | Return a primary data asset by name |

### `DataInterface_Traits`
Trait list queries — return the `OmegaObjectTrait` instances this object carries.

| Event | Description |
|--------|-------------|
| `Traits - Get` | Return the object's trait list |

### `DataInterface_InputAction`
Lets objects receive standard input action events routed by tag.

| Event | Description |
|--------|-------------|
| `Input - Disabled?` | Return true to ignore this action |
| `Input - Action Begin` | Input started (Player, Action tag, Axis) |
| `Input - Action Tick` | Input ongoing |
| `Input - Action End` | Input ended |

### Other data interfaces
Many focused single-purpose data interfaces exist; the important ones for Blueprint use:

| Interface | Purpose |
|-----------|---------|
| `DataInterface_Equipable` | Marks an asset as equippable (slot, modifiers) |
| `DataInterface_InventoryItem` / `DataInterface_InventorySource` | Inventory item data / item list providers |
| `DataInterface_AppearanceSource` / `DataInterface_SkinSource` | Character appearance & skin providers |
| `DataInterface_HUDSource` | Provides HUD layer classes |
| `DataInterface_FlowAsset` | Provides a Flow graph asset |
| `DataInterface_SoftCondition` / `DataInterface_SoftEvent` | Generic condition checks / event triggers |
| `DataInterface_ScriptedEffects` | Provides scripted effect data |
| `DataInterface_Environment` | Environment state providers |
| `DataInterface_Pickup` / `DataInterface_Tool` / `DataInterface_Prop` | Pickup / tool / prop actor data |

---

## Actor Interfaces

### `ActorInterface_Interactable`
Implement on actors that can be interacted with.

| Event | Description |
|--------|-------------|
| `👆Interaction - On Interact` | Called when the interaction executes (Instigator, Tag, Context) |
| `👆Interaction - Is Blocked?` | Return true to block the interaction |
| `👆Interaction - Get Flags` | Return interaction bit flags |

Used by: `PerformInteraction` / `CanInteract` on the Gameplay (World) subsystem.

### `ActorTagEventInterface`
Implement to react to tag events dispatched to an actor (see `ListenFor_ActorTagEvent` async node).

### `ActorInterface_Relatives`
Return related assets/actors for an actor (used by identity & zone systems).

---

## Menu Interface

### `DataInterface_MenuSource`
Implement to provide a menu class by name.

| Event | Description |
|--------|-------------|
| `GetMenuClass(Name)` | Return a Menu widget class for the given name |

---

## Save Interface

### `OmegaSaveInterface`
Implement on any object that needs custom JSON save/load behavior.

| Event | Description |
|--------|-------------|
| `UseJsonSaveData()` | Return true to opt in to JSON saving |
| `GetJsonPropertyName()` | Unique property key |
| `SaveJsonData(CurrentData)` | Return JSON to save |
| `LoadJsonData(SaveFile)` | Read saved JSON |
| `OnGameFileSaved(SaveFile)` | Called when game is saved |
| `OnGameFileStarted(SaveFile)` | Called when a save is loaded/started |

---

## Widget Interfaces

### `WidgetInterface_Input`
Implement on widgets to receive routed menu input from the Player subsystem.

| Event | Description |
|--------|-------------|
| `ControlWidget_Get` | Return the widget (and priority) that should receive input |
| `OnBecomeControlWidget` | This widget became the input target |
| `InputBlocked()` | Return true to block input routing to this widget |
| `InputConfirm()` / `InputCancel()` | Confirm / cancel action received |
| `InputNavigate(Axis)` | Navigation input received (2D axis) |
| `InputPage(Axis)` | Page input received |
| `InputTag(Tag)` | Tagged input received |

### `WidgetInterface_Combatant`
Implement on widgets that display combatant data — provides hooks to bind attribute text blocks and progress bars, and react to combatant updates.

### `DataInterface_WidgetTrait`
Lifecycle hooks (`OnTraitInit`, `OnWidgetConstruct`, `OnWidgetTick`, `OnWidgetDestruct`) for widget trait objects.

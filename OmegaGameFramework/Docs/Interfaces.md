# Interfaces

OmegaGameFramework defines a set of Blueprint-compatible interfaces that decouple systems from concrete types. Implement these on Blueprints or C++ classes to participate in the relevant system.

---

## Data Interfaces

These are "query" interfaces — they let any object expose standard data to systems without the system knowing the concrete type.

### `IDataInterface_General`
The most commonly used interface. Implement it on any object that has a name, description, icon, or color.

| Method | Description |
|--------|-------------|
| `GetGeneralDataText(Tag, Name, Description)` | Return display name and description |
| `GetGeneralDataImages(Tag, Texture, Material, Brush)` | Return icon/portrait assets |
| `GetGeneralAssetColor(Tag, Color)` | Return a representative color |
| `GetGeneralAssetLabel(Label)` | Return a short string label |

Used by: UI widgets, tooltips, lists, logging

### `IDataInterface_Common`
Hierarchical data relationships.

| Method | Description |
|--------|-------------|
| `GetParentObject()` | Return the parent object in a hierarchy |
| `GetChildObjects()` | Return all child objects |

### `IDataInterface_Combatant`
Damage modifier interface for objects that want to modify incoming damage.

### `IDataInterface_DamageModifier`
Lets objects participate in the damage calculation pipeline.

| Method | Description |
|--------|-------------|
| `ModifyDamage(Attribute, Target, Instigator, BaseDamage, DamageType, Context)` | Return a modified damage value |

### `IDataInterface_AttributeModifier`
Provides flat or multiplicative modifiers to attributes.

| Method | Description |
|--------|-------------|
| `GetModifierValues(CombatantComponent)` | Return an array of `FOmegaAttributeModifier` |

### `IDataInterface_DataAsset`
Named data asset access — return a primary data asset by name or tag.

### `IDataInterface_ObjectTraits`
Tag-based trait queries.

| Method | Description |
|--------|-------------|
| `GetObjectGameplayTags()` | Return the tags this object "has" |
| `GetObjectGameplayCategory()` | Return a single category tag |

### `IDataInterface_Skill`
Skill source — provides a list of `UPrimaryDataAsset` skill references.

| Method | Description |
|--------|-------------|
| `GetSkills(Combatant)` | Return skill assets for a given combatant |

### `IDataInterface_InputAction`
Lets non-input objects receive Enhanced Input action events routed through a combatant.

| Method | Description |
|--------|-------------|
| `OnInputAction_Begin(Player, Action, Axis)` | Input started |
| `OnInputAction_Update(Player, Action, DeltaTime, Axis)` | Input ongoing |
| `OnInputAction_End(Player, Action, Axis)` | Input ended |

### `IDataInterface_Widget`
Widget-specific data queries for widgets that display object data.

---

## Actor Interfaces

### `IActorInterface_Interactable`
Implement on actors that can be interacted with.

| Method | Description |
|--------|-------------|
| `CanBeInteracted(Instigator, Tag, Context)` | Returns true if interaction is allowed |
| `OnInteracted(Instigator, Tag, Context)` | Called when the interaction executes |
| `GetInteractionBlocked()` | Returns true if interaction is currently blocked |

Used by: `UOmegaSubsystem_World::PerformInteraction`

---

## Menu Interfaces

### `IDataInterface_CommonMenu`
Implement to supply a list of `UObject` entries to a `UMenu` or `UDataList`.

| Method | Description |
|--------|-------------|
| `GetDataListEntries(Menu)` | Return the items to display |

### `IDataInterface_MenuSource`
Implement to provide a menu class by name.

| Method | Description |
|--------|-------------|
| `GetMenuClass(Name)` | Return a `TSubclassOf<UMenu>` for the given name |

---

## Save Interface

### `IOmegaSaveInterface`
Implement on any object that needs custom JSON save/load behavior.

| Method | Description |
|--------|-------------|
| `UseJsonSaveData()` | Return true to opt in to JSON saving |
| `GetJsonPropertyName()` | Unique property key |
| `SaveJsonData(CurrentData)` | Return JSON to save |
| `LoadJsonData(SaveFile)` | Read saved JSON |
| `OnGameFileSaved(SaveFile)` | Called when game is saved |
| `OnGameFileStarted(SaveFile)` | Called when a save is loaded/started |

---

## Widget Input Interface

### `IWidgetInterface_Input`
Implement on widgets to receive routed menu input from `UOmegaSubsystem_Player`.

| Method | Description |
|--------|-------------|
| `InputBlocked()` | Return true to block input routing to this widget |
| `OnInputConfirm()` | Confirm action received |
| `OnInputCancel()` | Cancel action received |
| `OnInputNavigate(Axis)` | Navigation input received |
| `OnInputPage(Axis)` | Page input received |
| `OnInputTag(Tag)` | Tagged input received |

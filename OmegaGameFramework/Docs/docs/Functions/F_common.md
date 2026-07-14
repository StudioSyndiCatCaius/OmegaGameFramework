# Blueprint Function Libraries

OmegaGameFramework exposes its functionality through a large number of Blueprint function libraries (BFLs). Each library is a `UBlueprintFunctionLibrary` subclass focused on a specific domain.

---

## General Utilities

### `F_Common`
General-purpose helpers that don't fit a more specific library.
- Object validity checks
- World context shortcuts
- Common math and string utilities

### `F_Actor`
Actor manipulation helpers.
- Spawning actors with data
- Getting components by class
- Actor distance and line-of-sight checks

### `F_Component`
Component-level helpers.
- Finding components by interface
- Component registration utilities

### `F_Enum`
Enumeration utilities — convert enum values to strings and back.

### `F_Conv`
Type conversion helpers — convert between common OmegaGameFramework types.

### `F_Text`
String and `FText` utilities.
- Format text with named arguments
- String splitting and joining
- Rich text helpers

### `F_Utility`
Miscellaneous utilities not covered elsewhere.

---

## Subsystem Access

### `F_Preferences`
Get and set `UGamePreference` values. Thin wrapper over `UOmegaSubsystem_GameInstance` preference functions.

### `F_Save` (implicit via `Subsystem_Save`)
Save slot name conversion, playtime formatting.

---

## Combat & Combatants

### `F_Combatant`
- Get combatants by faction, by tag, by filter
- Damage calculation helpers
- Attribute value queries

### `F_Equipment`
- Get/set equipment in slots
- Check if a slot is occupied
- Get all items in all slots

### `F_CombatantFilter` / `F_CombatantSelector`
Filter and select combatants using script objects and selector assets (used for skill targeting and AI).

---

## State Machines

### `F_Machina`
- `SetMachinaState(Object, State, Meta)` — transition an object to a named state
- `GetMachinaState(Object)` — query current state
- Works with `UOmegaSubsystem_GameInstance` machina maps

### `F_IntState`
Integer-based state helpers for objects that track numeric state values.

---

## Tags & Properties

### `F_TagEvent`
Fire gameplay tag events on actors (received via the Actor Tag Event interface).

### `F_SoftProperty` / `F_SoftEvent` / `F_SoftCondition`
- `F_SoftProperty` — read property values off any object by property name string
- `F_SoftEvent` — fire generic events defined as instanced data objects
- `F_SoftCondition` — evaluate conditions defined as instanced data objects

### `F_GlobalParam`
Named global variables stored on the active or global save (bool, int, float, string, vector, rotator, data asset), plus bitflag helpers.

### `F_PropertyBag`
- Get/set typed properties in an `FOmegaPropertyBagWrapper`
- Supports: bool, int, float, FName, FString, FVector, UObject*

---

## Camera

### `F_Camera`
- Set/clear camera override
- Fade camera in/out
- Query dynamic camera state

---

## UI

### `F_Popup`
Show/hide popup widgets with data. Handles positioning and lifecycle.

---

## Animation

### `F_ScriptedAnim`
Drive animation montages via data-driven scripts rather than direct Blueprintcalls.

---

## AI

### `F_AI`
AI behavior helpers:
- Perception query shortcuts
- Behavior tree / blackboard shortcuts

---

## Data Assets

### `F_DataAsset`
- Get data assets by class from the asset registry
- Filter data asset arrays
- Get/set tags on data assets

### `F_ObjectSorter`
Sort and filter `TArray<UObject*>` using data-driven sort keys.

### `F_ObjectTraits`
Query `IDataInterface_ObjectTraits` on objects — get trait tags, check trait presence.

---

## Mesh & Graphics

### `F_Mesh`
Static and skeletal mesh operations:
- Socket queries
- Bone transforms
- LOD helpers

### `F_Materials`
Dynamic material instance helpers:
- Set scalar / vector / texture parameters by name
- Create dynamic material instances

### `F_Graphics`
Rendering utilities — visibility, stencil, render layer helpers.

---

## Math & Geometry

### `F_Spline`
Spline math helpers:
- Get point along spline by distance or alpha
- Project a location onto a spline

### `F_Grid3D`
3D grid utilities:
- World-to-grid coordinate conversion
- Grid neighbor queries
- Grid distance calculations

---

## Scripted Effects

### `F_ScriptedEffects`
Apply `UOAsset_EffectsPreset` collections to actors:
- Spawn Niagara effects
- Play sounds
- Apply camera shakes

---

## Processes

### `F_Process`
Manage subprocess objects — create, query, and stop background processes.

---

## File I/O

### `F_File`
Thin wrappers over FileSDK:
- Read/write text files
- Check file existence
- List directory contents

---

## JSON

### `F_Json`
`FJsonObjectWrapper` helpers:
- Get/set fields by name
- Convert between JSON and Blueprint types
- Serialize/deserialize objects

---

## Localization

### `F_Localization`
- Get localized text by string table key
- Switch active locale
- Format localized strings

---

## Debug

### `F_Debug`
Draw debug visualizations:
- Sphere, box, line primitives
- On-screen text with categories
- Log to gameplay log

### `F_Draw`
Canvas/HUD drawing utilities for procedural UI rendering.

---

## Command Line

### `F_CommandLine`
Parse command line arguments at startup.
- Check for flag presence
- Get named argument values

---

## MIDI

### `F_Midi`
MIDI input handling helpers for music-based gameplay features.

---

## Meta

### `F_Meta`
Object metadata operations — read/write `FOmegaCommonMeta` context data.

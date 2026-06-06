# Tags, Properties & State Function Libraries

Covers: `F_TagEvent`, `F_TagProperty`, `F_GlobalParam`, `F_SoftProperty`, `F_SoftCondition`, `F_IntState`, `F_BitFlag`, `F_Machina`

---

## Tag Events (`UActorTagEventFunctions`)

Fire named gameplay tag events on actors. Target actors implement an interface to respond.

| Node | Description |
|---|---|
| **Fire Tag Event on Actor** | Send a single gameplay tag event to one actor. |
| **Fire Tag Events on Actor** | Send multiple gameplay tag events to one actor. |
| **Fire Tag Event on Actors** | Send one event to multiple actors at once. |
| **Fire Tag Events on Actors** | Send multiple events to multiple actors. |
| **Fire Actor Tag Events** | Fire events from a tag→actor map. |
| **Fire Actor Tag Events — Container** | Fire events from a pre-built event container. |

---

## Tag Properties (`UOmegaFunctions_TagProperty`)

Read typed properties off objects using gameplay tag names as keys. Useful for querying data from any object without knowing its exact type.

| Node | Description |
|---|---|
| **Get — String / Bool / Float / Int32 / Vector / Rotator / Object** | Read a property value by gameplay tag name from any object. Pass a fallback returned if the property isn't found. |

---

## Global Variables (`UOmegaFunctions_GlobalVars`)

Named variables stored on the active or global save. Supports multiple types and bitflags.

### Value Types
| Node | Description |
|---|---|
| **Set/Get Global Variable — Bool** | Read or write a named bool. Toggle **Global** for the global save. |
| **Toggle Global Variable — Bool** | Flip a bool to its opposite. |
| **Set/Add/Get Global Variable — Int32** | Read, write, or add-to a named integer. |
| **Set/Add/Get Global Variable — Float** | Read, write, or add-to a named float. |
| **Set/Get Global Variable — String** | Read or write a named string. |
| **Set/Get Global Variable — Vector** | Read or write a named FVector. |
| **Set/Get Global Variable — Rotator** | Read or write a named FRotator. |
| **Set/Get Global Variable — Data Asset** | Read or write a named data asset reference. |

### Bitflags
| Node | Description |
|---|---|
| **Bitflag — Set** | Set a bit (0–254) to true or false under a named key. |
| **Bitflag — Get** | Read a bit by index. |
| **Bitflag — Clear** | Set all bits under a key to false. |
| **Bitflag — Has Any** | Returns true if any bit in a mask is set. |
| **Guidflag — Set / Get / Clear** | Same as Bitflag but keyed by `FGuid`. |

---

## Soft Property (`UOmegaFunctions_SoftProperty`)

Read properties off objects by property name string at runtime — no casting needed.

| Node | Description |
|---|---|
| **Get Soft Property — String / Bool / Float / Int32 / Vector / Rotator** | Returns the value of any property on any object by its exact property name. |

---

## Soft Conditions (`UOmegaSoftConditionFunctions`)

| Node | Description |
|---|---|
| **Check Object Soft Condition** | Evaluates a condition object against a target object. Returns true/false and an optional **Reason** text. |
| **Filter Objects by Soft Condition** | From an array, keeps objects that pass (or fail) a condition. Toggle **Invert** and pass **Object Class** for type filtering. |

---

## Integer State (`UOmegaIntStateFunctions`)

A simple integer state interface — any object implementing `IIntStateInterface` can have a tracked integer state.

| Node | Description |
|---|---|
| **Set Int State** | Set an object's integer state. Toggle **Force** to bypass any state change conditions. |
| **Get Int State** | Returns the current integer state. |
| **Check Int State** | Compare current state to a value with exec branching. |

---

## Bit Flags (`UOmegaBitFlagFunctions`)

| Node | Description |
|---|---|
| **Get Object Bitflag** | Reads a bitflag struct from any object and returns a specific bit by index. |
| **Get Object Bitenum** | Same but returns the value as an enum. |
| **Get Bitflag** | Reads a bit from a `FOmegaBitflagsBase` struct directly. |
| **Get Bitenum** | Reads a bit as an enum from the struct. |
| **Filter Objects With Bit Flag** | From an array, keeps objects whose bit at index equals the given value. |

---

## Machina State Machine (`UOmegaFunctions_Machina`)

Simple named state machine for any object.

| Node | Description |
|---|---|
| **Set State** | Transition an object to a named state. Pass optional **Meta** context. |
| **Stop State — Current** | Exit the object's current state without entering a new one. |
| **Get State** | Returns the object's current state name. |
| **Can Set State** | Returns true if the object is allowed to transition to the given state. |

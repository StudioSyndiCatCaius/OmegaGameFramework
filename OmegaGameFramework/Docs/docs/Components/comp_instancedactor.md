# Instanced Actor Component

**Component class:** `UInstanceActorComponent`
**Add to:** Any actor that needs to manage a dynamic list of spawned sub-actors — party member actors, UI card representations, unit tokens on a map.

The Instanced Actor Component spawns and manages multiple instances of a single actor class. Each instance is linked to a **Context** object (any UObject — typically a data asset) so you can associate instances with data. Instances can be ordered, filtered by tags, and swapped around.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Instanced Actor Class** | The actor class to spawn for each instance. |
| **Instance Name Prefix** | A name prefix applied to each spawned instance actor. |

---

## Creating Instances

| Node | Description |
|---|---|
| **Create Instance** | Spawn one instance linked to a Context object. Pass an optional **Flag** string and **Local Transform** offset. |
| **Create Instances** | Spawn multiple instances at once from an array of context objects. |
| **Try Get Instance by Context** | Returns the instance for a context object. If no instance exists and **Create if Invalid** is true, it creates one. Also takes a class for output type casting. |

---

## Getting Instances

| Node | Description |
|---|---|
| **Get Instance by Context** | Returns the instance actor linked to a given context object. |
| **Get Instances by Contexts** | Returns a list of instance actors from a list of context objects. |
| **Get Instance by Name** | Returns an instance actor by its name string. |
| **Get Instance by Index** | Returns the instance actor at a given position in the ordered list. |
| **Get All Instances** | Returns every instance actor as an array. |
| **Get All Instance Contexts** | Returns every context object as an array. |
| **Get Instances of Category** | Filter instances by their Category Tag. Toggle **Exclude** to invert the filter. |
| **Get Instances with Gameplay Tags** | Filter instances by Gameplay Tags. Toggle **Exclude** to invert. |

---

## Ordering Instances

| Node | Description |
|---|---|
| **Swap Instance Indices** | Swap the positions of two instances in the ordered list. |
| **Set Instance Order by Labels** | Reorder instances by passing an array of string labels in the desired order. |
| **Set Instance Order by Contexts** | Reorder instances by passing context objects in the desired order. |
| **Get Instance Order by Labels** | Returns the current order as an array of string labels. |
| **Get Instance Order by Contexts** | Returns the current order as an array of context objects. |

---

## Notifies

| Node | Description |
|---|---|
| **Trigger Notify on All** | Send a named notify to every instance actor at once. |

| Event | Fires when... |
|---|---|
| `OnInstanceNotify` | Any instance actor sends a notification back to this component |

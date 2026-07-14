# Saveable Component

**Component class:** `UOmegaSaveableComponent`
**Add to:** Any actor in the world whose state needs to persist across save/load (doors, chests, NPCs, collectibles).

The Saveable Component links an actor to the save system using a GUID. It can save the actor's transform and tags, and exposes named boolean/integer parameters you can read and write in Blueprints that automatically persist.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Entity Guid** | A unique identifier for this actor in the save file. Generate one here — every saveable actor needs a different GUID. |
| **Save to Global** | If enabled, data is saved to the global save (persists across new games). Otherwise it saves to the active per-playthrough save. |
| **Save Transform** | If enabled, the actor's world transform is saved and restored on load. |
| **Save Actor Tags** | If enabled, the actor's gameplay tags are saved and restored on load. |

---

## Nodes

### Save / Load Manually

| Node | Description |
|---|---|
| **Save to Entity** | Capture the actor's current state and write it to the save system now. |
| **Load from Entity** | Read the actor's saved state and apply it now. |

### Entity Data

| Node | Description |
|---|---|
| **Get Entity Data** | Returns the full entity data struct currently stored in the save. |
| **Set Entity Data** | Replace the stored entity data struct directly. |

### Named Parameters

These are simple key→value values that persist in the save file automatically.

| Node | Description |
|---|---|
| **Set Save Param Bool** | Save a boolean value under a named key. |
| **Get Save Param Bool** | Read a saved boolean by key. |
| **Set Save Param Int** | Save an integer value under a named key. |
| **Get Save Param Int** | Read a saved integer by key. |

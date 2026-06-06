# Zone Actors

Zones are how Omega organizes areas of the world and handles travel between them. Place these actors in your levels to define spawn points, transitions, and named regions.

---

## Zone Spawn Point

**Class:** `AOmegaZonePoint`
**Place in level:** Yes — at least one per level, or one per entrance/exit.

Marks a location where the player can be placed after a zone transit. Each level should have one or more of these; the transit system looks them up by tag.

### Details Panel Properties

| Property | Description |
|---|---|
| **Point Name** | A human-readable name for this spawn location. |
| **Zone Point ID** | A Gameplay Tag identifying this specific point. The transit system uses this to find the right spawn when travelling. |
| **From Level** | The soft level reference this spawn point "comes from" (used for transit matching). |
| **Zone to Load** | A `UOmegaZoneData` asset to load when the player spawns here. |

---

## Zone Transit

**Class:** `AOmegaZoneTransit`
**Place in level:** Yes — at doors, portals, level exits.

A trigger volume that sends the player to another level or zone when they enter. Links to a `AOmegaZonePoint` as the destination.

### Details Panel Properties

| Property | Description |
|---|---|
| **Transit Point** | The destination `AOmegaZonePoint` to spawn the player at. |
| **Transit Point Linked** | A linked transit point (bidirectional portal setup). |
| **Transit to Level** | Enable to transit to a different level instead of within the same level. |
| **Transit Level** | The soft level reference to load. |
| **Level Transit ID** | Tag identifying this transit. |
| **Spawn Zone to Load** | Zone data to load at the destination. |
| **Use Linked Spawn Point** | Use the linked spawn point's location instead of a zone point. |
| **Spawn Point Location** | Transform offset for the spawn location. |
| **Show Display Point** | Show/hide the visual marker for this transit. |

### Nodes

| Node | Description |
|---|---|
| **Trigger Transit** | Manually send a specific player through the transit. |
| **Get Linked Spawn Point** | Returns the spawn point transform at the destination. |
| **Autoset Transits** | Editor utility — automatically configure paired transits. |

### Built-in Components

| Component | Description |
|---|---|
| **Box Transit** (`BoxComponent`) | The area that triggers the transit. |
| **Box Notify** (`BoxComponent`) | A larger area that notifies the player they are near a transit. |
| **Display Emitter** (`NiagaraComponent`) | Visual effect marking the transit location. |

---

## Gameplay Region

**Class:** `AGameplay_Region`
**Place in level:** Yes — at area boundaries or rooms.

A lightweight region marker that registers an area with a data asset identity. Used by the World Subsystem to organize actors into named areas.

### Details Panel Properties

| Property | Description |
|---|---|
| **Region Identity** | A `UPrimaryDataAsset` identifying this region. |

---

## Zone Entity Component & Actor

**Class:** `UZoneEntityComponent` / `AZoneEntity_Mesh`

Add a **Zone Entity Component** to any actor to register it with the world map and zone tracking system. `AZoneEntity_Mesh` is a static mesh actor with this component already added.

### Zone Entity Component — Details Panel Properties

| Property | Description |
|---|---|
| **Legend Asset** | A `UZoneLegendAsset` categorizing this entity on the map (enemy, item, NPC, etc.). |
| **Display Name** | Name shown on the map for this entity. |
| **Display Description** | Description shown on the map. |
| **Current Zone** | The zone this entity currently belongs to. |
| **Extra Tags** | Additional Gameplay Tags for filtering. |
| **Use Parent as Display Actor** | Use the owning actor as the map display representation. |
| **Display Actor Class** | Custom actor class to represent this entity on the map. |

### Zone Entity Component — Nodes

| Node | Description |
|---|---|
| **Set Legend Visible** | Show or hide this entity on the map for a specific legend category. |
| **Get Display Actor** | Returns the actor used as the map representation. |
| **Get Position 2D** | Returns the entity's position on the 2D world map. |
| **Get Rotation 2D** | Returns the entity's rotation on the 2D world map. |

# Gameplay Actor Component

**Component class:** `UGameplayActorComponent`
**Add to:** Any actor that needs an identity, gameplay tags, zone data, or scripted behavior.

The Gameplay Actor Component (also called the "ActorID" component) is the standard identity component for actors in Omega. It connects an actor to a `UPrimaryDataAsset` identity, tags it with Gameplay Tags, assigns it to a Zone, and attaches Subscript objects for event-driven behavior — all without subclassing.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Identity Source** | A `UPrimaryDataAsset` that represents what this actor "is" (e.g. an NPC profile, a chest type). Used by the World Subsystem to find actors by identity. |
| **Override Name** | Override the display name shown for this actor, regardless of what the identity asset says. |
| **Gameplay Tags** | Tags on this actor. Used for group filtering, system queries, and conditions. |
| **Category Tag** | A single tag categorizing this actor (e.g. `Actor.NPC`, `Actor.Pickup`). |
| **Zone** | The `UOmegaZoneData` this actor belongs to. |
| **Guid** | A unique identifier for this actor instance, used by the save system. |
| **Default Config** | An `UOmegaActorConfig` data asset applied at startup to configure the actor. |
| **Subscripts** | Instanced script objects that react to events on this actor (interactions, damage, level change, etc.) without needing Blueprint overrides. |

---

## Blueprint Nodes

| Node | Description |
|---|---|
| **Set Config** | Apply an actor config data asset at runtime. |
| **Set Identity Source Asset** | Change the actor's identity data asset at runtime. |
| **Get Identity Source Asset** | Returns the current identity data asset. |

### Named Parameters

Store simple key→value data directly on the actor.

| Node | Description |
|---|---|
| **Set Bool / Int / Float / Vector** | Set a named parameter by key. |
| **Get Bool / Int / Float / Vector** | Get a named parameter by key. |

---

## Save-Based Visibility

Under the **👁️Visibility** category, the component can automatically show/hide its actor based on the save file:

| Property | Description |
|---|---|
| **Visible (On Save Query)** | Actor is visible only when the save's tags match this tag query. |
| **Hidden (On Save Query)** | Actor is hidden when the save's tags match this query. |
| **Global Save** | Check the global save instead of the active save. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnActorIdentityChanged` | The identity source asset is changed |

---

## Subscripts

Subscripts are instanced Blueprint objects added to the **Subscripts** list in the Details panel. They let you add reactive behavior to an actor without subclassing it.

Common subscript types include responses to:
- Actor interactions
- Combatant damage events
- Level load/unload
- Zone entry/exit

Create a subscript by subclassing the appropriate Omega subscript base class in Blueprint, then add an instance of it in the component's Details panel.

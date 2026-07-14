# Interactable Actors

Omega provides several ready-made interactable actor types for common gameplay objects.

---

## Openable Actor

**Class:** `AOmegaOpenableActor`
**How to create:** Blueprint subclass. Use for doors, gates, drawers, chests (open/close animation).

An actor that animates between open and closed states. Override the Blueprint events to drive your animation or skeletal mesh.

### Details Panel Properties

| Property | Description |
|---|---|
| **Start Open** | If enabled, the actor begins in the open state. |
| **Locked** | If enabled, `CanOpen` returns false until unlocked. |

### Nodes

| Node | Description |
|---|---|
| **Can Open** | Returns true if the actor is currently openable. |
| **Set Locked** | Lock or unlock the actor. |
| **Start Opening** | Begin the open or close animation. **Forward** = opening, false = closing. **Snap** = skip animation. |
| **Set Anim Position** | Directly set the animation progress (0 = closed, 1 = open). |

### Blueprint Events to Override

| Event | Description |
|---|---|
| **Get Openable Style** | Return a style data asset for this openable. |
| **On Open Begin** | Animation starts. **Forward** = true if opening. |
| **On Open End** | Animation ends. |
| **On Open Update** | Called each frame during animation with time and direction. |

### Built-in Components

| Component | Description |
|---|---|
| **Mesh** (`SkeletalMeshComponent`) | The door/chest mesh. |
| **Range** (`BoxComponent`) | Interaction trigger range. |

---

## Pickup Actor

**Class:** `AOmegaPickupActor`
**How to create:** Blueprint subclass or configure via a preset. Use for coins, items, power-ups, collectibles.

### Details Panel Properties

| Property | Description |
|---|---|
| **Preset** | A pickup preset asset defining behavior (attract radius, pickup sound, effects). |
| **Config** | Additional runtime pickup configuration. |

### Nodes

| Node | Description |
|---|---|
| **Set Preset** | Apply a pickup preset at runtime. |

### Blueprint Events to Override

| Event | Description |
|---|---|
| **Can Pickup** | Return false to block pickup for a specific pawn/controller. |
| **On Pickup** | Called when a pawn picks up the item. Receives the pawn and controller. |

### Built-in Components

| Component | Description |
|---|---|
| **Range** (`SphereComponent`) | Pickup detection radius. |
| **Niagara** | Visual particle effect. |
| **Audio** | Pickup sound. |

---

## Interact Transit

**Class:** `AInteractTransit`
**Place in level:** Yes. Use for doorways, portals, cave entrances — any interaction that transitions the player to another area.

When the player interacts with this actor, it triggers a zone transit to the configured level and spawn point.

### Details Panel Properties

| Property | Description |
|---|---|
| **Transit Level** | The soft level reference to travel to. |
| **Spawn Tag** | The Gameplay Tag identifying the spawn point in the destination level. |
| **Spawn Location** | An optional offset applied to the spawn position. |

### Built-in Components

| Component | Description |
|---|---|
| **Range** (`BoxComponent`) | Interaction trigger area. |

---

## Destructible Actor

**Class:** `AOmegaDestructible`
**How to create:** Blueprint subclass. Use for destructible crates, barrels, pillars, environment objects.

An actor with a Combatant Component for health tracking. When HP reaches zero, destruction logic fires.

### Details Panel Properties

| Property | Description |
|---|---|
| **Preset** | A destructible preset defining mesh, effects, sounds, and destruction behavior. |

### Nodes

| Node | Description |
|---|---|
| **Set Preset** | Apply a destructible preset at runtime. |

### Built-in Components

| Component | Description |
|---|---|
| **Range Box** (`BoxComponent`) | Bounds for the destruction area. |
| **Mesh** (`StaticMeshComponent`) | The destructible mesh. |
| **Audio** (`AudioComponent`) | Destruction sound. |
| **Niagara** (`NiagaraComponent`) | Destruction particle effect. |
| **Combatant Component** | Health and damage. Hook into `OnDamaged` here to drive destruction. |

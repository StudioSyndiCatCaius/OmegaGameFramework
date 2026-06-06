# Prop Actors

Omega provides several pre-built prop actors for common world objects.

---

## Prop Actor

**Class:** `AOmegaProp`
**Place in level:** Yes. Use for any visual world object — furniture, decorations, barrels, signs.

A general-purpose prop actor configured entirely by a **Prop Preset** data asset. The preset defines the mesh, material, audio, particles, and behavior. Swap the preset to change the entire object's appearance and behavior.

### Details Panel Properties

| Property | Description |
|---|---|
| **Preset** | A `UOmegaProp_Preset` data asset that configures this prop. |

### Prop Preset Asset Properties

Create a **Prop Preset** in the Content Browser (Data Asset → `OmegaPropPreset`) and set:

| Property | Description |
|---|---|
| **Static Mesh** | Static mesh configuration. |
| **Skeletal Mesh** | Skeletal mesh configuration (for animated props). |
| **Audio** | Sound asset to play. |
| **Niagara** | Particle system to attach. |
| **Appearance Preset / Custom** | Visual appearance overrides. |
| **Collision Type** | Collision preset to use. |
| **Mobility** | Static or Movable. |
| **Can Tick** | Whether the actor should tick. |
| **Set Range to Mesh Bounds** | Auto-scale the interaction range to fit the mesh. |
| **Mods Construct** | Modifier objects applied at construction. |
| **Mods BeginPlay** | Modifier objects applied at BeginPlay. |

### Built-in Components

| Component | Description |
|---|---|
| **Mesh Static** (`StaticMeshComponent`) | Static mesh. |
| **Mesh Skeletal** (`SkeletalMeshComponent`) | Skeletal mesh. |
| **Audio** (`AudioComponent`) | Sound. |
| **Niagara** (`NiagaraComponent`) | Particles. |
| **Range Box** (`BoxComponent`) | Interaction / detection bounds. |

---

## Static Mesh Dynamic Material Actor

**Class:** `AStaticMeshDynaMat`
**Place in level:** Yes. Use for any static mesh that needs material parameters changed at runtime (color-changing panels, glowing surfaces, animated materials).

A static mesh actor with built-in dynamic material instance support. Configure material parameters in the Details panel and update them at runtime without creating a Dynamic Material Instance manually.

### Details Panel Properties

| Property | Description |
|---|---|
| **Material Params Default** | Default parameter values applied at BeginPlay. |
| **Material Params Slot** | Per-material-slot parameter overrides. |
| **Material Overrides** | Material assets to apply to specific slots. |

---

## Null Actor

**Class:** `AOmegaNullActor`
**Place in level:** Yes or spawn at runtime. Use as an invisible anchor point, a placeholder reference, or a target for camera and transform operations.

A bare actor with no mesh or collision. Useful as a target point, a socket reference, or a placeholder that holds a position without any visual presence.

### Details Panel Properties

| Property | Description |
|---|---|
| **New Actor Label** | Custom editor label to make this actor easy to identify in the Outliner. |

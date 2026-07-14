# Volume Actors

Omega provides several volume-based actors for defining interactive or reactive regions in the world.

---

## Advanced Volume (Base Class)

**Class:** `AAdvancedVolume`

A base class for custom volume actors. It provides a visible shape in the editor and is meant to be subclassed.

### Details Panel Properties

| Property | Description |
|---|---|
| **Shape** | Box or sphere volume shape. |
| **Color** | Debug visualization color shown in the editor. |

### Nodes

| Node | Description |
|---|---|
| **Set Color** | Change the debug color at runtime. |

### Built-in Components

| Component | Description |
|---|---|
| **Volume** (`StaticMeshComponent`) | Visual representation of the volume shape. |
| **Text Display** (`TextRenderComponent`) | Editor debug label. |
| **Icon Display** (`BillboardComponent`) | Editor icon. |

---

## Volume Trigger — Global Event

**Class:** `AVolumeTrigger_GlobalEvent`
**Place in level:** Yes.

A simple box volume that fires a global event when an actor overlaps it. No Blueprint subclassing needed — just configure the event in the Details panel.

### Details Panel Properties

| Property | Description |
|---|---|
| **Event Named** | A named (`FName`) global event to fire on overlap. |
| **Event Tag** | A Gameplay Tag global event to fire on overlap. |

---

## Modifier Volume

**Class:** `AActor_ModifierVolume`
**Place in level:** Yes.

A box volume that applies actor modifiers to actors that overlap it, or directly to targeted actors. Use for buff/debuff zones, damage fields, slow zones, etc.

### Details Panel Properties

| Property | Description |
|---|---|
| **Range** | The box collision bounds of the volume. |
| **Modify Delay** | Delay in seconds before modifiers are applied to a new overlap. |
| **Modify Overlaps** | If enabled, modifiers are automatically applied to any actor that overlaps. |
| **Modify Overlap Filter** | Conditions that an overlapping actor must pass before modifiers are applied. |
| **Modify Direct** | A list of actors to apply modifiers to directly (regardless of overlap). |
| **Modifiers** | The modifier objects to apply. |
| **Modifiers on Tag Event** | Modifiers applied only when a specific tag event fires. |

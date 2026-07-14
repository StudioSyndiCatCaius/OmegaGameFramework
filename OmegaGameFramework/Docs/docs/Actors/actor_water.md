# Water Actors

Omega provides two water actors for flat bodies of water and flowing rivers.

---

## Water Plane

**Class:** `AOmegaWater_Plane`
**Place in level:** Yes. Use for lakes, ponds, the sea, swimming pools, or any flat water surface.

A flat water plane with underwater post-processing. When actors enter the water volume, the post-process effect activates to simulate being submerged.

### Details Panel Properties

| Property | Description |
|---|---|
| **Style** | A water style data asset defining surface appearance (material, color, waves). |
| **Config** | Additional water configuration. |
| **Depth** | A vector defining the depth and orientation of the water body. |

### Built-in Components

| Component | Description |
|---|---|
| **Mesh** (`StaticMeshComponent`) | The water surface plane. |
| **Mesh Surface** (`StaticMeshComponent`) | An additional surface mesh layer (e.g. foam or reflections). |
| **Post Process** (`PostProcessComponent`) | Underwater visual effect. |
| **Post Process Range** (`BoxComponent`) | The volume in which the underwater effect applies. |

---

## Water River

**Class:** `AOmegaWater_River`
**Place in level:** Yes. Use for streams, rivers, waterfalls, or any flowing water path.

A spline-based river with surface effects. Edit the spline in the viewport to shape the river's path.

### Details Panel Properties

| Property | Description |
|---|---|
| **Style** | A water style data asset defining surface appearance. |

### Built-in Components

| Component | Description |
|---|---|
| **Spline** (`USplineComponent`) | The river path. Edit in the viewport. |
| **Post Process** (`PostProcessComponent`) | River surface visual effects. |

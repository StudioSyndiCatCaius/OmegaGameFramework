# Spline Actors

Omega provides spline-based actors for paths, walls, and procedural geometry.

---

## Spline Actor

**Class:** `AOmegaSplineActor`
**Place in level:** Yes. Use for patrol routes, movement paths, cable visuals, river outlines, or any path-based gameplay.

A basic spline actor with a visible path and optional point/line visualization meshes. The spline data can be read by other systems (e.g. the `AsyncAction_MovePawnAlongSpline` async node).

### Details Panel Properties

| Property | Description |
|---|---|
| **Point Color** | Color of the spline point markers. |

### Nodes

| Node | Description |
|---|---|
| **Set Spline Color** | Change the spline visualization color at runtime. |

### Built-in Components

| Component | Description |
|---|---|
| **Spline** (`USplineComponent`) | The spline path. Edit points directly in the level viewport. |
| **Display Point** | Mesh shown at each spline point. |
| **Display Line** | Mesh drawn between spline points. |

---

## Dynamic Mesh Spline Block

**Class:** `AOmega_DynamicMesh_SplineBlock`
**Place in level:** Yes. Use for walls, fences, hedgerows, barriers, or terrain that follows a spline path.

Generates a solid mesh block along a spline using UE's Dynamic Mesh system. Edit the spline in the viewport and the mesh regenerates automatically.

### Details Panel Properties

| Property | Description |
|---|---|
| **Build Mesh Block from Spline** | Enable to automatically generate the mesh from the spline shape. |
| **Closed Loop** | Close the spline into a loop (e.g. for a room outline or enclosed area). |
| **Mesh Block Height** | How tall the generated mesh is. |
| **Clamp Spline Range** | Limit the spline extent used for mesh generation. |
| **Mesh Block Offset from Height** | If enabled, the mesh is offset vertically based on its height. |
| **Meshblock Material** | Material applied to the generated mesh. |
| **Is Boolean** | Use boolean mesh operations against other meshes. |
| **Boolean Targets** | The target meshes for boolean subtraction/union. |

### Built-in Components

| Component | Description |
|---|---|
| **Spline** (`USplineComponent`) | The path the mesh is generated along. |
| **Dynamic Mesh** (`UDynamicMeshComponent`) | The procedurally generated mesh. |

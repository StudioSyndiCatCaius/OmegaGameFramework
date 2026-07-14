# Graphics, Materials & Mesh Function Libraries

Covers: `F_Graphics`, `F_Materials`, `F_Mesh`, `F_DynamicMesh`, `F_Draw`

---

## Graphics Functions (`UOmegaGraphicsFunctions`)

| Node | Description |
|---|---|
| **Set Graphics RHI** | Switch the rendering backend at runtime (DirectX 11, DirectX 12, Vulkan). Requires a restart to take effect. |
| **Get Current Graphics RHI** | Returns the name of the currently active rendering backend. |

---

## Material Functions (`UOmegaMaterialFunctions`)

| Node | Description |
|---|---|
| **Apply Materials to Slots** | Apply a map of slot-index → material to a mesh component in one call. |
| **Apply Dynamic Material Params** | Set multiple parameters on a Dynamic Material Instance at once from a parameter map. |

## Texture Functions (`UOmegaTextureFunctions`)

| Node | Description |
|---|---|
| **Get Texture Pixel Colors** | Reads every pixel from a `UTexture2D` and returns them as a `TArray<FLinearColor>`. Useful for data-driven texture sampling. |

---

## Mesh Functions (`UOmegaMeshFunctions`)

| Node | Description |
|---|---|
| **Add Curves to Skeleton From Morphs** | Imports all morph targets on a Skeletal Mesh as animation curves on its skeleton. |
| **Copy Bone Transforms** | Copies bone transforms from one Skeletal Mesh Component to another. Toggle which axes (location, rotation, scale) to copy. Returns success. |

---

## Dynamic Mesh & Spline Mesh (`UOmegaFunctions_DynamicMesh`)

Tools for procedurally placing and generating meshes, especially along splines.

| Node | Description |
|---|---|
| **Stretch Instance Mesh Along Spline** | Distributes instances of a Static Mesh along a spline, stretching them to fill the length. |
| **Add Mesh Instances Along Spline** | Places evenly-spaced mesh instances along a spline. |
| **Get Mesh Instance Transforms** | Returns the transforms of all instances on an Instanced Static Mesh Component. |
| **Remove Mesh Instances From Boolean Points** | Removes instances at specified point indices. |
| **Get 2D Vector Points From Spline** | Extracts all spline points as flat 2D positions. |
| **Build Dynamic Mesh Along Spline** | Generates a full Dynamic Mesh following a spline path. |
| **Clamp Vector to Step — Ref / Copy** | Snaps a vector to the nearest step increment (grid snapping). |

---

## Debug Draw (`UOmegaFunctions_Debug`, `UOmegaFunctions_Draw3D`, `UOmegaFunctions_Draw2D`)

| Node | Description |
|---|---|
| **Draw Debug Component** | Draws a debug visualization around a component. Toggle sphere/box shape, axes, and bounds. Set **Duration** and **Thickness**. |
| **Draw Debug Line Between Components** | Draws a debug line from one component to another. |
| **Draw Object Tree** | Renders a 2D hierarchy tree of an object's children on the HUD canvas. |

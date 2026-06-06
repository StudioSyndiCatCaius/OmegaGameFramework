# Skin Component

**Component class:** `USkinComponent`
**Add to:** Any character actor that supports swappable visual appearances.

The Skin Component manages character visual customization. A **Skin** is a spawned child actor (`AOmegaSkin`) that contains mesh parts, materials, and modifiers. The Skin Component applies it to the character's skeletal mesh — optionally merging everything into a single optimized mesh.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Skin** | The default skin class (`AOmegaSkin` subclass) to apply at startup. |
| **Appearance** | The initial appearance data — body type and body parameters. |
| **Mesh Components** | The skeletal mesh components on this actor that the skin system manages. |

---

## Applying Skins

| Node | Description |
|---|---|
| **Set Skin** | Apply a different skin class at runtime. Destroys the old skin and spawns the new one. |
| **Assemble** | Trigger the full skin assembly process (applies mesh parts, modifiers, and optionally merges). Pass an override mesh to force a specific base mesh. |
| **Setup Linked Components** | Tell the skin component which Skeletal Mesh and Child Actor Component it should work with. |
| **Set Linked Child Actor Component** | Set the child actor component used to host the skin actor. |

---

## Appearance / Body Customization

| Node | Description |
|---|---|
| **Set Body Appearance Data** | Apply a full appearance struct at once (body type + all parameters). |
| **Set Body Type** | Change the character's body type asset. |
| **Set Body Param (Vector / Bool / Int / Float)** | Set a named body customization parameter. |
| **Get Body Type** | Returns the current body type asset. |
| **Get Body Param (Vector / Bool / Int / Float)** | Read a named body parameter. |

---

## Queries

| Node | Description |
|---|---|
| **Get Skin** | Returns the currently active skin actor. |
| **Get Target Mesh** | Returns the skeletal mesh component being modified by the skin. |

---

## AOmegaSkin — Skin Actor Properties

When creating a skin Blueprint (`AOmegaSkin` subclass), configure these in the Details panel:

| Property | Description |
|---|---|
| **Hide Base Mesh** | Hides the character's original base mesh when this skin is active. |
| **Is Compressed Skin** | If true, all mesh parts are merged into a single skeletal mesh at assembly for better performance. |
| **Master Skeleton** | The base skeleton used when compressing into a single mesh. |
| **Merge** | Merge child mesh components together. |
| **Force Follow Master Component** | Forces all parts to follow the owner's transform. |
| **Skin Modifiers** | A list of material or appearance modifier objects applied during assembly. |
| **Animation Class** | The animation Blueprint to apply to the assembled mesh. |

**Blueprint Events on the Skin Actor:**

| Event | When it's called |
|---|---|
| **On Skin Build Finished** | Called after the full skin assembly process completes. Use this to do any post-assembly setup. |

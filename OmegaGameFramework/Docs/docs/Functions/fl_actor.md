# Actor & Component Function Libraries

Covers: `F_Actor`, `F_Component`, `F_Physics`, scripted traces

---

## Actor Functions (`UOmegaActorFunctions`)

| Node | Description |
|---|---|
| **Label — Set** | Sets the editor display label of an actor. Pass a **Rand ID Range** > 0 to append a random ID. Toggle **Only If Default Name** to skip if already renamed. |
| **Label — Get** | Returns the editor label string. |
| **Teleport Actor to Reference Point** | Moves an actor to match a Reference Component's transform. Toggle which axes (location, rotation, scale) to copy. |
| **Snap Actor to Surface** | Line traces between two points and snaps the actor to the hit surface. |
| **Check Actor Condition** | Evaluates a list of condition objects against an actor. Returns true if all pass. |
| **Is Actor Player** | Returns true + the pawn and controller if the actor is player-controlled. |
| **Apply Actor Config Asset** | Applies an `UOmegaActorConfig` data asset to an actor. |
| **Configure Child Actor** | Reconfigures a Child Actor Component — sets class, identity, and owner. |
| **Attach Component to Actor** | Attaches a Scene Component to an actor, with socket name and attachment rules. |
| **Get Actor Nearest to Screen Point** | From an array of actors, returns the one closest to a given screen position. Also outputs distance. |
| **Set Paused** | Pauses or unpauses all actors in a named pause group tag. |
| **Filter Actors by Distance to Vector** | From an array, keeps only actors within (or beyond) a distance from a world point. Toggle **Invert**. |
| **Filter Actors on Screen** | From an array, keeps only actors currently visible on screen. Toggle **Invert**. Pass **Screen Edge Tolerance** to include near-edge actors. |
| **Filter Actors Overlapping Actor** | Returns actors from an array that are currently overlapping a target actor. Filter by class. |
| **Get Tag as Param** | Parses a structured tag from an actor's tag container (e.g. `MyParam.Value`) using a delimiter. |

### Actor Bound Parameters
Named key→value metadata on any actor, stored in the World Subsystem.

| Node | Description |
|---|---|
| **Get/Set Actor Bound Param — String / Float / Int / Bool** | Read or write named parameters on any actor by key. |

### Actor Groups
| Node | Description |
|---|---|
| **Group — Add** | Add or remove an actor from a gameplay tag group. |
| **Group — Add List** | Bulk add/remove actors from a group. |
| **Group — Has Actor** | Returns true if an actor is in the group. |
| **Group — Get Actors** | Returns all actors registered in a group. |

### Tagged Targets
| Node | Description |
|---|---|
| **Get Actor Tag Target** | Returns the actor stored under a gameplay tag key for a given actor. |
| **Set Actor Tag Target** | Stores a target actor under a gameplay tag key. |

### Interaction
| Node | Description |
|---|---|
| **Check Is Actor Interactable** | Returns true if an actor will accept an interaction right now. |
| **Perform Interaction** | Executes an interaction on an actor. Toggle **Force** to skip the interactable check. |

### Faction & Metadata
| Node | Description |
|---|---|
| **Get Faction Tag** | Returns the faction tag of an actor (reads from its Combatant Component). |
| **Get Faction Affinity** | Returns the affinity enum between an actor's faction and a given tag. |
| **Get Faction Affinity to Target** | Returns the affinity between two actors' factions. |
| **Get Meta — Bool / Int / Float / String / DataAsset / Actor** | Read actor metadata values by key. |
| **Get Relative** | Returns a named relative actor from the actor's Gameplay Actor Component. |

---

## Pawn Functions (`UOmegaPawnFunctions`)

| Node | Description |
|---|---|
| **Move Pawn 2D Grounded** | Apply 2D movement input to a pawn using a `FVector2D` axis value. Toggle **Force** to bypass input blocking. Pass **Forward** and **Right** world vectors. |
| **Rotate Control 2D** | Apply 2D rotation input to a pawn's controller with config settings. |
| **Get Pawn Control Vectors** | Returns the pawn's Forward, Right, and Up vectors in world space with configurable axis locks. |

---

## Component Functions (`UOmegaComponentFunctions`)

| Node | Description |
|---|---|
| **Set Box Range to Component Bounds** | Resizes a Box Component to match the bounds of a reference component. Toggle **Set Box Extent** and **Set Position** independently. |
| **Reset Mesh Component Materials** | Resets a mesh's materials back to their default (as defined on the asset). |
| **Interp Component Rotation From Vector** | Smoothly rotates a component toward a world direction vector. |
| **Lerp Scene Component Transform** | Linearly interpolates a component's transform between transform A and B by an alpha. Toggle **World Space**. |
| **Lerp Scene Component Between Components** | Interpolates a component's transform between two reference components. |
| **Point Arrow Component to Target** | Points an Arrow Component at a world location. |

---

## Component Modifier Functions (`UOmegaComponentModifierFunctions`)

| Node | Description |
|---|---|
| **Apply Modifier to Actor** | Apply an array of actor modifier scripts to an actor. |
| **Run Actor Modifier Container** | Apply an `UOAsset_ActorModifierCollection` to actors in the world. |
| **Apply Modifier to Component** | Apply a modifier script to a scene component. |
| **Apply Modifier to Skeletal Mesh** | Apply a modifier to a Skeletal Mesh Component. |
| **Apply Modifier to Static Mesh** | Apply a modifier to a Static Mesh Component. |
| **Apply Modifier to Instanced Static Mesh** | Apply a modifier to an Instanced Static Mesh Component. |

---

## Physics Functions (`UOmegaFunctions_Physics`)

| Node | Description |
|---|---|
| **Offset Vector From Hit Result** | Calculates a world position offset from a hit result. Toggle **Impact** to use the impact normal instead of face normal. |
| **Get Rotation From Hit Result Normal** | Returns a rotator aligned to a hit surface's normal. Useful for placing decals or attaching actors to surfaces. |

---

## Trace Functions (`UOmegaScriptedTraceFunctions`)

Run scripted trace objects as Blueprint nodes.

| Node | Description |
|---|---|
| **Scripted Trace — Single** | Execute a single-hit trace defined by a script object. Returns the `FHitResult` and a **Success** exec. |
| **Scripted Trace — Multi** | Execute a multi-hit trace. Returns an array of `FHitResult`. |

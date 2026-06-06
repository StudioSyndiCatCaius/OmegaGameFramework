# Math, Geometry & Grid Function Libraries

Covers: `F_Math`, `F_Spline`, `F_Grid3D`

---

## Math Functions (`UOmegaMathFunctions`)

| Node | Description |
|---|---|
| **Compare Float** | Compare two floats with an operator (Equal, Greater, Less, etc.). Returns bool. |
| **Compare Int** | Same for integers. |
| **Add Transforms** | Combines two transforms (adds location, rotation, and scale). |
| **Lerp Widget Transform** | Linearly interpolates between two `FWidgetTransform` values. |
| **Lerp Vector2D** | Linearly interpolates between two `FVector2D` values. |
| **Get Angle From Vectors** | Returns the angle in degrees between two world vectors. |
| **Get Angle From Rotators** | Returns the angle in degrees between two rotators. |
| **Conv Vector to Rot Flat** | Converts a direction vector to a rotator locked to the horizontal plane (no pitch). |
| **Conv Transform 3D to Widget Transform** | Converts a `FTransform` to a `FWidgetTransform` for use in UMG. |
| **Normalize to Range Int32** | Maps an integer value within a min/max range to a 0–1 float. |
| **Get Seed From Guid** | Generates a deterministic integer seed from a GUID. |
| **Get Curve Value** | Samples a `FRuntimeFloatCurve` at a given time. |
| **RNG Roll From Float** | Returns true with a probability equal to the input float (0–1). |
| **Variate Float** | Adds random variation to a float. Toggle **Amount Is Scale** to make it proportional. |
| **Offset Vector** | Offsets a world vector in the direction of a rotation + an offset vector. |
| **Offset Actor Location** | Returns an actor's location with an applied offset. |
| **Offset Pawn Location From Control** | Returns a pawn's location offset relative to its controller's view direction. |
| **Random Vector in Range** | Returns a random `FVector` between two min/max vectors. |
| **Random Rotator in Range** | Returns a random `FRotator` between two min/max rotators. |
| **Invert Map Values — Asset/Int** | Swaps keys and values in a `TMap<DataAsset, int32>`. |
| **Invert Map Values — Asset/Float** | Swaps keys and values in a `TMap<DataAsset, float>`. |
| **Do Lines Cross** | Returns true if two 2D line segments intersect. |
| **Do Any Lines Cross** | Finds all intersecting pairs in an array of 2D line segments. Returns the crossing indices. |

---

## Spline Functions (`UOmegaFunctions_Spline`)

| Node | Description |
|---|---|
| **Get 2D Vector Points** | Extracts all spline points as `FVector2D` (ignores Z). |
| **Clamp Tangents** | Constrains the tangent vectors on all spline points to a min/max magnitude. |

---

## 3D Grid System (`F_Grid3D`)

A full tile-based 3D grid system used for strategy/tactics gameplay. Maps are created as components on actors.

### Map (`UOmegaGrid3D_Map`)
| Node | Description |
|---|---|
| **Generate Tiles** | Build the tile grid from the map's configuration. |
| **Destroy Tiles** | Remove all tiles. |
| **Get Coordinate From Vector** | Converts a world position to a grid coordinate. |
| **Get Vector From Coordinate** | Converts a grid coordinate to a world position. |
| **Get Tile From Vector** | Returns the tile at a world position. |
| **Get Tile From Coordinate** | Returns the tile at a grid coordinate. |
| **Set Selected Tile** | Mark a specific tile as selected. |
| **Get Selected Tile** | Returns the currently selected tile. |

### Occupants (`UOmegaGrid3D_Occupant`)
| Node | Description |
|---|---|
| **Set Occupant on Tile** | Place an occupant object on a tile. |
| **Get Occupants** | Returns all occupants on the grid. |

### Pathfinding (`UOmegaGrid3D_Selector`)
| Node | Description |
|---|---|
| **Pathfind 3D — All Possible Paths** | Returns all tiles reachable within a given movement budget. |
| **Get Shortest Path to Coordinate** | Returns the shortest path from the current position to a target coordinate. |
| **Get Shortest Path to Tile** | Returns the shortest path to a specific tile object. |

### Movement (`UOmegaGrid3D_Mover`)
| Node | Description |
|---|---|
| **Add Input — Movement** | Apply directional movement input on the grid. |
| **Add Input — Rotation** | Apply rotation input on the grid. |
| **Is Moving** | Returns true if the mover is currently transitioning between tiles. |

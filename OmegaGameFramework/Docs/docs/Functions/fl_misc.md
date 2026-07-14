# Miscellaneous Function Libraries

Covers: `F_Common`, `F_Utility`, `F_Config`, `F_Meta`, `F_Debug`, `F_Log`, `F_PropertyBag`, `F_PropertyAccess`, `F_Physics`, `F_Midi`, `F_BitFlag` (common), `F_Enum`

---

## Common Framework Utilities (`UOmegaGameFrameworkBPLibrary`)

The largest library — general-purpose nodes that don't belong to a more specific category.

### Settings Access
| Node | Description |
|---|---|
| **Get Settings — Omega / Style / Asset** | Returns each of the three Omega settings objects. |

### World Access
| Node | Description |
|---|---|
| **Get Omega Game Mode** | Returns the current Omega Game Mode. |
| **Get Omega World Manager** | Returns the `AOmegaWorldManager` in the current world. |

### Gameplay Tag Utilities
| Node | Description |
|---|---|
| **Object — Tag Event** | Fire a gameplay tag event on any object. |
| **Object — Tag Query** | Test whether an object matches a gameplay tag query. |
| **Get Object Gameplay Tags** | Returns the gameplay tag container from any object implementing the tags interface. |
| **Does Object Have Gameplay Tag** | Returns true if the object has a specific tag. |

### Asset Loading
| Node | Description |
|---|---|
| **Get All Assets of Class** | Returns all loaded data assets of a given class. |
| **Get Asset From Path** | Returns a single asset from a content path string. |
| **Get Assets From Path** | Returns all assets in a content path. |

### Actor Filtering
| Node | Description |
|---|---|
| **Filter Actors by Class** | From an array, keeps only actors of a specific class. |
| **Filter Actors by Tag** | From an array, keeps actors that have a specific actor tag. |
| **Filter Actors With Components** | From an array, keeps actors that have a specific component class. |

### Player Queries
| Node | Description |
|---|---|
| **Get Player Mouse Over Actor** | Returns the actor currently under the player's cursor. |
| **Get Player Camera Fade Amount** | Returns the current camera fade value (0 = transparent, 1 = fully faded). |

### Actor Bindings
| Node | Description |
|---|---|
| **Set Global Actor Binding** | Register an actor under a string name globally. |
| **Check Tagged Actor Binding** | Returns the actor registered under a tag binding. |

### Interpolation
| Node | Description |
|---|---|
| **Interp Actor Location** | Smoothly moves an actor toward a target location. |
| **Interp Actor Rotation** | Smoothly rotates an actor toward a target rotation. |

### System & Module Access
| Node | Description |
|---|---|
| **Get Active Gameplay System** | Returns an active Gameplay System by class. |
| **Get Gameplay Module** | Returns a Gameplay Module singleton by class. |

### Star Rank (`UOmegaStarRankFunctions`)
| Node | Description |
|---|---|
| **Get Float From Star Rank** | Converts a star rank enum (1–5 stars) to a 0–1 float. |
| **Get Int From Star Rank** | Converts a star rank enum to an integer (0–5). |

### Curve Evaluation (`UOmegaCurveFunctions`)
| Node | Description |
|---|---|
| **Get Curve Value From Time** | Evaluates a `FRuntimeFloatCurve` at a given time value. |

---

## Utility Functions (`UOmegaUtilityFunctions`)

| Node | Description |
|---|---|
| **Are Streamed Levels Loading** | Returns true if any level is currently streaming. |
| **Is Game Async Loading** | Returns true if async asset loading is in progress. Outputs packages remaining. |
| **Are Shaders Compiling** | Returns true if the shader compiler is still running. |
| **Get Shader Compilation Remaining** | Returns the number of shaders still pending compilation. |
| **Apply Graphics Settings From User Settings** | Re-applies graphics config from the user settings file. |
| **Set Console Variable — Bool / Float / Int** | Set any console variable at runtime by name. |
| **Is Build Shipping** | Returns true if this is a packaged shipping build. |
| **Get Window Mode** | Returns whether the game is fullscreen and which mode. |
| **Set Window Mode** | Set fullscreen or windowed mode. |
| **Sort Objects by Display Name** | Sorts an array of objects alphabetically by their display name. |
| **Get Bitmask Flag From Tag** | Converts a Gameplay Tag to a uint8 bitmask index. |
| **Get Command Line Args** | Returns all command line arguments as a string array. |

### String Utilities (`UOmegaStringFunctions`)
| Node | Description |
|---|---|
| **Is String First** | Returns true if string A comes before B alphabetically. |
| **Parse String Intro Params** | Parses a string of `key=value` pairs into a map using configurable delimiters. |

### Audio Utilities (`UOmegaAudioFunctions`)
| Node | Description |
|---|---|
| **Set Sound Wave Volume** | Change the volume of a specific `USoundWave`. |
| **Sound Class — Set / Get Volume** | Read or write the volume on a `USoundClass`. |
| **Sound Class — Set / Get Pitch** | Read or write the pitch on a `USoundClass`. |

---

## Config File (`UOmegaFunctions_Config`)

Read and write values from the `OmegaGameSettings.ini` configuration file.

| Node | Description |
|---|---|
| **Get/Set — Bool / Float / Int / String / Vector / Vector2D** | Read or write a named value in a section of the Omega config file. |

---

## Metadata Parsing (`UOmegaFunctions_Meta`)

Parse typed values out of a metadata struct by parameter name.

| Node | Description |
|---|---|
| **Parse — String / Bool / Int32 / Float** | Read a parameter from an `FOmegaCommonMeta` struct. Pass a **Fallback** and optionally a **Parse Order**. Outputs **Valid** bool. |

---

## Property Bag (`UOmegaFunctions_PropertyBag`)

A dynamic typed property container stored in an `FOmegaPropertyBagWrapper`.

| Node | Description |
|---|---|
| **Set Property Bag Value** | Write any typed value into the bag by property name. (Wildcard pin — accepts any type.) |
| **Get Property Bag Value** | Read a value back from the bag. Outputs **Valid** bool. |

---

## Property Access (`UOmegaFunctions_PropertyAccess`)

Read any property from any UObject at runtime by its exact property name string — no casting required.

| Node | Description |
|---|---|
| **Get — String / Bool / Double / Int64 / Object** | Returns the named property's value from a UObject. Pass a fallback for non-existent properties. |

---

## Log Functions (`UOmegaFunctions_Log`)

| Node | Description |
|---|---|
| **Warning** | Print a yellow warning message to the screen. Pass **Duration** in seconds. |
| **Error** | Print a red error message to the screen. |

---

## MIDI (`UOmegaFunctions_MIDI`)

| Node | Description |
|---|---|
| **Parse MIDI File** | Reads a MIDI file from a path and returns structured MIDI data. Returns a success bool. |

# Engine Subsystem

**How to access:** Get Engine Subsystem → `OmegaSubsystem_Engine`

The Engine subsystem is a low-level singleton that lives for the entire editor and runtime session — even before a Game Instance exists. Most users won't interact with it often, but it provides a few useful Blueprint-accessible tools.

---

## Sorted Assets

A global, label-keyed object registry. Register any object under a string label and retrieve it from anywhere else in your project — without storing direct references.

These nodes are available as standalone Blueprint function library calls (no subsystem reference needed):

| Node | Description |
|---|---|
| **Sorted Asset - Set** | Registers a UObject under a string label. If **Overwrite** is false and the label is taken, the node does nothing and returns false. |
| **Sorted Asset - Get** | Returns the object registered under a label. Returns null if nothing is found. |
| **Sorted Asset - Get All** | Returns all registered objects as an array. |

**Example use case:** Register your game's standard damage formula or a set of FX presets at startup, then retrieve them by name from any Blueprint.

---

## Developer Config

| Node | Description |
|---|---|
| **Load Dev Config** | Reloads the developer configuration file from disk. |

This is mainly for plugin development and editor tooling. The config is stored in `devconfig.lua` at the project root.

---

## Lua Table Generation

| Node | Description |
|---|---|
| **Generate Lua Table Data Assets** | Regenerates Lua table structures from registered data assets so the Lua scripting system can access them. |

This runs automatically at startup. You only need to call it manually if you add new assets mid-session and need them available in Lua scripts immediately.

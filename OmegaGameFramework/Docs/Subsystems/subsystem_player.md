# Player Subsystem

**How to access:** Get Local Player Subsystem → `OmegaSubsystem_Player`

The Player subsystem manages everything belonging to a single local player: their open menus, HUD layers, hover state, input mode, and camera. There is one instance per local player controller.

---

## Menus

Menus are `UMenu` Blueprint widgets managed here. You never add them to the viewport yourself — always open them through this subsystem. Only one instance of each menu class can be open at a time.

| Node | Description |
|---|---|
| **Open Menu** | Creates and opens a menu. Pass the class, an optional **Context** object, **Tags**, and a **Flag** string. Returns the menu instance. |
| **Close Menu** | Closes a menu by class. Plays its close animation, then removes it. |
| **Get Menu** | Gets a currently open menu. Outputs a **Is Valid** bool. |
| **Set Control Widget** | Forces all input to go to a specific widget. |
| **Clear Control Widget** | Stops forcing input to a specific widget. |

| Delegate | Fires when... |
|---|---|
| `OnMenuOpened` | Any menu opens. `bFirstMenu` is true if this is the only open menu. |
| `OnMenuClosed` | Any menu closes. `bLastMenu` is true if no menus remain after this. |

---

## HUD Layers

`UHUDLayer` widgets are persistent overlays — health bars, minimaps, action prompts. Multiple layers can be active at once, stacked on top of each other.

| Node | Description |
|---|---|
| **Add HUD Layer** | Adds a HUD layer to the viewport. Pass the class and an optional Context object. Returns the new instance. |
| **Remove HUD Layer** | Removes a layer by class. |
| **Get HUD Layers** | Returns all currently active layers. |
| **Get HUD Layer by Class** | Gets a specific active layer by class. |
| **Remove All HUD Layers** | Removes every active layer at once. |

---

## Data Widget Hover

Tracks which `UDataWidget` the cursor is currently hovering. Widgets report their hover state here so any system can ask "what is the player looking at?" without being directly connected to the widget.

| Node | Description |
|---|---|
| **Set Current Hover Widget** | Mark a widget as hovered. (Usually called automatically by the widget.) |
| **Try Unhover Widget** | Clears hover if this widget is currently the hovered one. |
| **Get Current Hover Widget** | Returns the currently hovered DataWidget, or null if nothing is hovered. |

---

## Input Mode

Instead of using Unreal's raw SetInputMode nodes, Omega uses `UOmegaInputMode` — a **data asset** you configure in the Content Browser and apply with one node.

**Create one:** Content Browser → Add → Miscellaneous → Data Asset → `OmegaInputMode`

**Properties on the data asset:**

| Property | Description |
|---|---|
| **Type** | `Game`, `UI`, or `Game & UI` |
| **Added Mapping Contexts** | Enhanced Input mapping contexts to activate with this mode |
| **Input Priority** | Priority of those mapping contexts |
| **Show Mouse Cursor** | Whether to show the mouse cursor |
| **Enable Click Events / Mouse Over Events** | Standard mouse interaction flags |

| Node | Description |
|---|---|
| **Set Custom Input Mode** | Apply an Input Mode data asset. Handles cursor, mappings, and mode type all at once. |
| **Is Using Gamepad** | Returns true if the player is currently on a gamepad. |

| Delegate | Fires when... |
|---|---|
| `OnInputModeChanged` | Input mode is switched |
| `OnInputDeviceChanged` | Player switches between keyboard/mouse and gamepad |

---

## Menu Input Forwarding

Rather than binding input directly to UI, call these nodes from your input mappings and the subsystem routes them to whichever widget currently has focus.

| Node | Typical Use |
|---|---|
| **Input Confirm** | Accept / select |
| **Input Cancel** | Back / close |
| **Input Navigate** | Move selection (takes a 2D axis) |
| **Input Page** | Page up/down through lists |
| **Input Tag** | Send a custom tagged input |

---

## Dynamic Camera

The Player subsystem drives a smooth dynamic camera system using `AOmegaDynamicCamera` actors placed in the level. Cameras register and unregister themselves automatically on spawn/destroy.

There are three roles:

| Role | Description |
|---|---|
| **Source** | The camera the view is currently blending toward |
| **Master** | Outputs the final view. Smoothly interpolates toward the source each frame. |
| **Override** | Temporarily takes full control, bypassing the source/master system. |

The camera blends smoothly every frame — no manual lerping needed.

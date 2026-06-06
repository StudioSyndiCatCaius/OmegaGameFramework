# UI & Camera Function Libraries

Covers: `F_Widget`, `F_Camera`, `F_Popup`

---

## Widget Functions (`UOmegaWidgetFunctions`)

| Node | Description |
|---|---|
| **Control Widget — Set** | Force all player input to route to a specific widget. |
| **Control Widget — Get** | Returns the widget currently holding input control. |
| **Control Widget — Clear** | Release input control back to normal. |
| **Set HUD Layer Active** | Add or remove a single HUD layer class. Pass context and flag. |
| **Set HUD Layers Active** | Add or remove multiple HUD layer classes at once. |
| **Try Get HUD Layer** | Returns a specific active HUD layer. **Outcome** exec fires only if found. |
| **Try Get Data Widget From Slot** | Returns the `UDataWidget` registered in a named slot. **Outcome** exec fires only if valid. |
| **Get Source Assets From Data Widgets** | From an array of `UDataWidget` instances, extracts the source UObject from each. Filter by class. |
| **Get Widget Slate Theme** | Walks up the widget hierarchy to find the nearest `UOmegaSlateTheme`. |
| **Get Widget Screen Position** | Returns the screen-space position of a widget. Toggle **Get Center** to use its center instead of its top-left. |
| **Get Widget Viewport Position** | Returns the viewport-space position. Toggle **Get Center**. |

---

## Camera Functions (`UOmegaCameraFunctions`)

### View Target
| Node | Description |
|---|---|
| **Set View Target — Actor** | Set the player's view target to a specific actor with a blend time. |
| **Set View Target — Actor Binding** | Set view target to the actor registered under a global binding name. |
| **Set View Target — Soft Actor** | Set view target from a soft actor reference. |
| **Set View Target — Actor Selector** | Set view target by evaluating an actor selector object. |
| **Project World to Screen From Camera** | Projects a world-space point to screen coordinates as seen from a specific camera actor. |

### Dynamic Camera
| Node | Description |
|---|---|
| **Dynamic Camera — Set Active** | Enable or disable the dynamic camera system for the player. |
| **Dynamic Camera — Is Active** | Returns true if the dynamic camera is currently driving the view. |
| **Get Dynamic Camera — Master** | Returns the master camera (the one driving the actual view). |
| **Get Dynamic Camera — Source** | Returns the current source camera (the one being blended toward). |
| **Set Dynamic Camera — Override** | Force a specific camera into full control. Toggle **Snap To** for instant positioning. |
| **Clear Dynamic Camera — Override** | Remove the override, returning to normal source-based blending. |
| **Dynamic Camera — Snap to Source** | Instantly snap the master camera to the current source position. |
| **Set View Target to Dynamic Camera** | Switch the player view to use the dynamic camera master. |

---

## Popup Functions (`UOmegaFunctions_Popup`)

| Node | Description |
|---|---|
| **Create Popup Widget** | Spawns a floating popup widget at a world location. Set the class, display text, context object, color, and tags. Returns the popup instance. |

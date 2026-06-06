# Data Widget Component

**Component class:** `UDataWidgetComponent`
**Add to:** Any actor that hosts a `UDataWidget` in world space and needs to expose its events to the owning actor.

The Data Widget Component is a wrapper around a 3D widget component specifically for `UDataWidget` instances. It forwards the widget's internal events (selection, hover, highlight, notification) as Blueprint-assignable delegates on the actor, so the owning actor can respond without digging into the widget directly.

---

## Nodes

| Node | Description |
|---|---|
| **Get Data Widget** | Returns the hosted `UDataWidget` instance. Use this to call `SetData` on it and control what it displays. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnWidgetSelected` | The data widget is selected |
| `OnWidgetHovered` | The data widget hover state changes (includes a **Hovered** bool) |
| `OnWidgetHighlight` | The data widget highlight state changes (includes a **Highlighted** bool) |
| `OnWidgetNotify` | The data widget sends a named notification |

# Cursor Events Component

**Component class:** `UOmegaCursorEventComponent`
**Add to:** A Player Controller or player-owned actor that needs to detect what the cursor is hovering over in the world.

The Cursor Events Component fires line traces from the cursor position every frame to detect world-space hover and interaction. It tells you which actor or component the cursor is over, and lets you trigger an interaction on it with one node call.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **Is Tracing Active** | Enables or disables cursor tracing each frame. Toggle this to pause hover detection (e.g. while a menu is open). |
| **Trace Type** | Which collision channel to use for the line trace. |
| **Trace Distance** | How far from the camera the trace reaches (world units). |
| **Accepted Actors** | Optional list of actor classes that can receive cursor events. Leave empty to accept all actors. |

---

## Nodes

| Node | Description |
|---|---|
| **Trigger Overlapped Actor** | Fire an interaction on the actor currently under the cursor. Pass optional metadata. |
| **Get Current Overlapped Actor** | Returns the actor currently under the cursor, or null if nothing is hit. |
| **Get Current Overlapped Component** | Returns the specific component hit under the cursor. |
| **Get Cursor Screen Position** | Returns the current cursor position in screen space. Override this in Blueprint to support virtual cursors. |

---

## Events

| Event | Fires when... |
|---|---|
| `OnCursor_BeginOverlapActor` | The cursor enters an actor's collision |
| `OnCursor_EndOverlapActor` | The cursor leaves an actor's collision |
| `OnCursor_BeginOverlapComponent` | The cursor enters a specific component's collision |
| `OnCursor_EndOverlapComponent` | The cursor leaves a specific component's collision |
| `OnCursor_TriggerOverlappedActor` | An interaction is triggered on the overlapped actor |

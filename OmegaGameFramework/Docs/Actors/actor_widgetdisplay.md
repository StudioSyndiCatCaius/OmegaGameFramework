# Widget Display & World Map Point Actors

---

## Widget Display Actor

**Class:** `AOmegaWidgetDisplayActor`
**How to create:** Blueprint subclass. Use for in-game monitors, security cameras, character preview panels, or any actor that renders a live scene to a texture displayed in the world.

Uses a Scene Capture Component to render a view of the world to a texture, which can then be displayed on a mesh's material. Override the Blueprint events to control what gets rendered.

### Blueprint Events to Override

| Event | Description |
|---|---|
| **Get Rendered Actors** | Return an array of actors to show in the capture. |
| **Get Rendered Components** | Return specific components to show in the capture. |

### Built-in Components

| Component | Description |
|---|---|
| **Spring Arm** (`USpringArmComponent`) | Positions the capture camera. |
| **Scene Capture** (`USceneCaptureComponent2D`) | Renders the scene to a render target texture. |

---

## World Map Point

**Class:** `AOmegaWorldMapPoint`
**Place in level:** Yes. Use for map markers, points of interest, fast travel nodes, quest markers.

A map location actor that players can see on a world map UI. It hosts a `UDataWidget` for its map icon and fires an event when selected.

### Details Panel Properties

| Property | Description |
|---|---|
| **Zone** | The `UOmegaZoneData` asset associated with this map point. |

### Events

| Event | Fires when... |
|---|---|
| `OnPointSelected` | The player selects this map point (provides the player controller). |

### Built-in Components

| Component | Description |
|---|---|
| **Range** (`USphereComponent`) | The interactive area around this map point. |
| **Data Widget Component** | The `UDataWidget` displayed as the map icon. Set data on this widget to show location info. |

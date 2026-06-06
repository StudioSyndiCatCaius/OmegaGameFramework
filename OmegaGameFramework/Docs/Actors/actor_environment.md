# Environment Actor

**Class:** `AOmegaActorEnvironment`
**Place in level:** Yes — one per level or sub-area.

The Environment Actor is the central manager for a level's visual and audio atmosphere. It owns the directional light, sky atmosphere, fog, clouds, post-process, and ambient audio, and lets you switch between preset configurations at runtime.

---

## Details Panel Properties

| Property | Description |
|---|---|
| **BGM to Auto-Play** | A `UOmegaBGM` asset that plays automatically when this environment actor is active. |
| **BGM Slot** | The BGM slot tag to use when auto-playing music. |
| **Named Lists** | Named collections of objects attached to this environment. |

---

## Nodes

| Node | Description |
|---|---|
| **Set Preset** | Apply an environment preset asset, changing lighting/atmosphere/fog all at once. |
| **Get Preset** | Returns the currently active preset asset. |
| **Save to Preset** | Capture the current environment state into the active preset. |
| **Quickset Atmosphere** | Apply quick default settings for sky atmosphere rendering. |
| **Quickset Skybox** | Apply quick default settings for skybox rendering. |

---

## Built-in Components

| Component | Description |
|---|---|
| **Directional Light** | The sun / main directional light. |
| **Sky Light** | Ambient sky lighting. |
| **Atmosphere** (`SkyAtmosphereComponent`) | Sky atmosphere scattering. |
| **Clouds** (`VolumetricCloudComponent`) | Volumetric cloud rendering. |
| **Fog** (`ExponentialHeightFogComponent`) | Height fog and atmospheric haze. |
| **SkyBox** (`StaticMeshComponent`) | The sky sphere mesh. |
| **Post Process** (`PostProcessComponent`) | Post-processing effects (color grading, bloom, etc.). |
| **Audio** (`AudioComponent`) | Ambient background audio. |

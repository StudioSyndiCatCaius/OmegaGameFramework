# Gameplay Systems
Gameplay systems are singleton actors that can be activated automatically on a level starting, OR used as async tasks.

### Creating a Gameplay System
Search `OmegaGameplaySystem` from the blueprint menu.

### Using a Gameplay System

There are a few methods to activate gameplay systems, primaily using the following functions.
![alt text](../images/tutorial/subsystem_gameplay/tut_SubGameplay_ActivacteSystem.png)

--
### Functions
| Name | Description |
|-|-|
| `Shutdown` | Shutdown and destroys the Gameplay System.
| `Output Notify` | Outputs a notify string from the system. Mainly useful for asytem GameplaySystem activation events.
| `Restart` | Runs shutdown on the system and then Activates again with the same flag & context (unless overriden).
| `Finish Shutdown` |  If `OnBeginShutdown` is overriden, this will complete the shutdown event. ONLY use if you need a shutdown to be a delayed/async event.

### Variables
| Name | Description |
|-|-|
|`Tags`| This system's gamepaly tags.
|`Block Tags`| Shutsdown and prevents any systems with these tags from being activated.
|`Required Tags`| Prevents activation of this system unless these tags are active.
|`HUD Layers`| Hud layers activated & shutdown alonside this system.
|`Input Mode`| The Custom Input Mode that willl be set when this system is activated.


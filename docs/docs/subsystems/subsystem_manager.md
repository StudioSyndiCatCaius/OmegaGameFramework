# Omega Subsystem: Game Manager
The **OmegaGameManager** subsystem handles all primary GameInstance-wide events and systems, such as  Gameplay Modules.


### Global Events
Global events are soft name-based event calls fired from the GameManager and can be received by any object with the **OnGlobalEvent** event dispatcher attatched, OR by using the "Wait for Global Event" async task.

To call a global event, simply use the **FireGlobalEvent** functions.

Theses classes have **OnGameplayEvent** already added to them.
* GameplayModule
* GameplaySystem
* HUDLayer
* Menu


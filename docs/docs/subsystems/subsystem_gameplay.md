# Omega Subsystem: Gameplay
The **OmegaGameplaySubsystem** handles all primary World-wide events, such as **GameplaySystems** and **CombatantComponents**.

___
### Gameplay Systems

Gameplay systems are singleton actors for modularly managing gameplay states.

* Create a Gameplay System.
![alt text](../../images/tutorial/subsystem_gameplay/tut_SubGameplay_system_1.png)

* Activating a Gameplay System can be done a few different ways.

|Manually| ![](../../images/tutorial/subsystem_gameplay/tut_SubGameplay_system_activ_1.png)
|-|-|
|**From OmegaGameMode**| ![](../../images/tutorial/subsystem_gameplay/tut_SubGameplay_system_activ_2.png)
|**From GameplayModule**| ![](../../images/tutorial/subsystem_gameplay/tut_SubGameplay_system_activ_3.png)

* Access your Gameplay System at any time with global function for from `OmegaGameplaySubsystem`
![alt text](../../images/tutorial/subsystem_gameplay/tut_SubGameplay_system_2.png)


#### Events
| Name | Description |
|-|-|
| *`OnActivated`* | Called when the system is activated.
| *`OnShutdown`* | Called when the system completes its shutdown.
| *`OnBeginShutdown`* | Called when the system shutdown begins. **NOTE**: by default this immediately runs the `CompleteShutdown` function. If you override this event, you will need to manually call `CompleteShutdown` to finish shutting down the system.

#### Variables
| Name | Type | Description |
|-|-|-|
| *`System Tags`* |`FGameplayTagContainer`| Tags assosiated with this System
| *`Block System Tags`* |`FGameplayTagContainer`| Shutsdown and prevents activation of *`GameplaySystems`* with these tags as long as *this* system is active
| *`Blocked On System Tags`* |`FGameplayTagContainer`| Prevetns this sytem from being activated as long asn any systems with these tags are active.
| *`Global Events on Activate`* |`FGameplayTagContainer`| Tagged Global Events fired when this system is Activated.
| *`Global Events on Shutdown`* |`FGameplayTagContainer`| Tagged Global Events fired when this system is Shutdown.
| *`Player Input Mode`* |`UOmegaInputMode*`| Changes to this `InputMode` when the system is activated.
| *`Added Player Widgets`* |`TArray<TSubclassOf<UHUDLayer>>`| List of `HUDLayers` to add and remove with this system's lifetime.
| *`Add Player Input Mapping`* |`TArray<UInputMappingContext*>`| List of `UInputMappingContext` to enable when this system is activated and remove when deactivated.

#### Functions
| Name | Description|
|-|-|
|`Shutdown`| Shutsdown and destorys the gameplay system.
|`Restart`| Completely shutsdown the system and immediately reactivates it.
| `Output Notify` | Outputs a notify event from the gameplay system with a Flag and Context object.
|`Complete Shutdown`| Finishes shutting down the system. **NOTE**: Only use if you are manually overriding `OnBeginShutdown`


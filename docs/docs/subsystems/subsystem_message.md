## Gameplay Messages

Gameplay messages are logged events with Text, an insitgator object, and lua metadata.

* You can fire a custom gameplay message..
![alt text](../../images/tutorial/subsystem_message/tut_SubMsg_how1.png)
* ..or use a scirpted blueprint message.
![alt text](../../images/tutorial/subsystem_message/tut_SubMsg_how2.png)

The message can then be recieved with the `OnGameplayMessage` delegate.
![alt text](../../images/tutorial/subsystem_message/tut_SubMsg_delg.png)

**NOTE**: `HUDLayers` and `Menus` already have a `OnGameplayMessage` event.
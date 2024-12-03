# Linear Events

Linear events allow you to create a sequence of scripted, data-driven, async events for your game.

You can create a new sequence with the `LinearEventSequence` variable
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_call_2.png)

Then call the event sequence either from the `Subsystem` or as an async event.
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_call_1.png)

#### Create a Linear Event

You can create a new linear event from the blueprint creation menu.
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_new_1.png)

From there you can write your own logic for running the event.
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_new_2.png)
Call `Finish` to end and destroy the event instance. You can use `Jump to ID` to jump to a specfici linear event in this sequence if you don't want to simply advance to the next event.

____
## Linear Choices

Linear Choices allow for a branch events from player input.

Create a new choice with a `FOmegaLinearChoices` variable.
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_choice_1.png) 

Call the choice.
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_choice_3.png)

A `ChoiceInstanceActor` class is needed to runt he choice event. If you don't want to use a default on, you can create your own.
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_choice_4.png)
![alt text](../../images/tutorial/subsystem_le/tut_SubLE_choice_2.png) 
# Omega Subsystem: Saving
Omega's save susystem provides an easy way to save and load game data to disk. There are two kinds of saves.

| Game Save | Global Save |
|-|-|
Contains data for the current game, and can be saved to an numbered slot. A new **GameSave** is always created when the game starts up. | A single save that contains persistent game data that is automatically saved upon closing the game. On startup, a **GlobalSave** will attempt to be loaded from disk, and if unsucessful a new one will be created.


### Saving Data (Soft Property)
The easiest way to save data is to get the **Omega Save Subsystem** and then calling 'Set' of 'Get' for the various save properties, as well as whether to save them to the "Game" or "Global" save file.

### Saving Data (Object JSON)
A second way to save is with the OmegaSaveInterface. Adding this interface to an object, you can then handle saving data to and from a json field in the main save.
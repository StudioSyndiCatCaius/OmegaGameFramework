Omega Game Framework features easy out-of-the-box modding support with Lua scripts & runtime file importing.


## Setup Up Mod Support

To enable mod support fully, add the Gamepaly Module "FileImporter"


## Installing Mod

1. Add a new folder to the "Mods" folder in your game. (If the folder doesn't exist, add it.)

2. Create a new file called "mod.lua". This is the lua file that will be run by default when the game loads.

3. To import your own files, add a folder named "Override" to your mod folder, then add any of the following file types into your game.

| extension | class |
|-|-|
| WAV | SoundBase |
| PNG | Texture2D

4. (For Devs) To ensure mod files can be override, make sure to use "Get Asset From Path" when callied game assets. If an override file loaded, you can us its name instead of the path.
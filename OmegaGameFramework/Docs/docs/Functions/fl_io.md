# File, IO & Scripting Function Libraries

Covers: `F_File`, `F_Json`, `F_Import`, `F_CommandLine`, `F_Lua`, `F_Paker`

---

## File Functions (`UOmegaFileFunctions`)

| Node | Description |
|---|---|
| **Get Plugin Base Dir** | Returns the root directory path of a plugin by name. |
| **Game Data — Get Directories** | Returns all game data directories. Pass an optional folder override. |
| **Game Data — Get Files** | Returns file paths in a game data subdirectory. Pass an extension filter and toggle **Recursive**. |
| **Get Subfolders** | Returns the names of immediate subfolders in a directory. Toggle **Only Names** to return names instead of full paths. |
| **Omega Import — Texture2D** | Imports an image file from disk as a `UTexture2D` asset. Pass mip generation settings. |
| **Omega Import — Sound** | Imports an audio file from disk as a `USoundWave`. Outputs an error string on failure. |

---

## JSON (`F_Json`)

JSON is handled through `FJsonObjectWrapper` (a Blueprint-compatible wrapper around JSON objects). Use the built-in UE **Json Blueprint Utilities** plugin nodes alongside Omega's save system JSON features.

> See [Save Subsystem — JSON Object Persistence](../Subsystems/subsystem_save.md) for saving/loading JSON data via `IOmegaSaveInterface`.

---

## Import (`UOmegaFunctions_Import`)

| Node | Description |
|---|---|
| **MP3** | Imports an MP3 file from a file path and returns it as a `USoundWave`. |

---

## Command Line (`UOmegaFunctions_Command`)

Parse command-line arguments passed when launching the game (useful for dedicated server configs, automated testing, or CI pipelines).

| Node | Description |
|---|---|
| **Parse — String** | Returns the value of a named command-line parameter as a string. Outputs **Valid** bool. |
| **Parse — Bool** | Returns a boolean command-line parameter. |
| **Parse — Int32** | Returns an integer command-line parameter. |
| **Parse — Float** | Returns a float command-line parameter. |

---

## Lua Functions (`UOmegaLuaFunctions`)

Integration with the LuaMachine scripting system. Requires the LuaMachine module.

| Node | Description |
|---|---|
| **Run Plugin External Script** | Execute a Lua script with arguments. Returns a `FLuaValue` result. |
| **Get Object Lua Value** | Returns a Lua value from an object, optionally specifying a field within it. |
| **Get Object Lua Key** | Returns the Lua key name for an object. |
| **Parse String to Lua Table** | Converts a string to a Lua table using a parser. |
| **Object — Get Metakey** | Returns the Lua metakey string for an object. |
| **Object — Get Metadata** | Returns the full Lua metadata table for an object. |
| **Filter Objects by Param Value** | From an array, keeps objects whose Lua parameter matches a target value. |

---

## PAK File Management (`UOmegaPakFunctions`)

Mount and manage PAK archives at runtime — useful for mod support or DLC.

| Node | Description |
|---|---|
| **Mount and Register PAK** | Mounts a .pak file and registers its content path. Outputs **Is Mount Successful**. |
| **Mount PAK File** | Mount a .pak file to a given mount point. Returns success. |
| **Unmount PAK File** | Unmount a previously mounted .pak. Returns success. |
| **Register Mount Point** | Register a content root path manually. |
| **Unregister Mount Point** | Unregister a content path. |
| **Get PAK Mount Point** | Returns the mount point path of a .pak file. |
| **Get PAK Content** | Lists all asset paths inside a .pak file. Toggle **Only Cooked** to filter. |
| **Get PAK Mount Content Path** | Returns the content path prefix for a mounted .pak. |
| **Load PAK Obj Class Reference** | Loads a UClass from a path inside a mounted .pak. |
| **Load PAK File Class** | Loads a UClass from a .pak file by file name. |
| **Conv PAK Content Path to Reference String** | Converts a PAK asset path to a standard asset reference string. |

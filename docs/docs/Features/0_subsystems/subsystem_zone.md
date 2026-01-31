# Omega Subsystem: Zones
![text](../../images/functions/sub_zone/f_Sub-Zone.png)

A subsystem for handling level zones and better transitioning between levels. 

## To use

### Zones
Zones are determined with a data asset called **Omega Zone Data**.

![alt text](../../images/tutorial/subsystem_zone/tut_SubZone_ZoneAsset_params.png)

### Levels
**OmegaLevelData** contains metadata for a specific level asset t work alongside the Zonesubsystem.

![alt text](../../images/tutorial/subsystem_zone/tut_SubZone_LevelAsset_params.png)

**NOTE**: For a Level Data Asset to work, it must be in the same directory as the Level asset and share the same name, with the suffex `_WorldData` added.

![alt text](../../images/tutorial/subsystem_zone/tut_SubZone_LevelAsset_AssetExample.png)

### Transitions
The Zone Manager allows you to setup and use transitions between zones and levels with two actors.
| OmegaSpawnPoint | OmegaZoneTransit |
|-|-|
![alt text](../../images/tutorial/subsystem_zone/tut_SubZone_actor_spawn.png)|![alt text](../../images/tutorial/subsystem_zone/tut_SubZone_actor_transit.png)
| Acts as a reference point to spawn/transition the player's pawn to. **From Level** means when transitioning from that level, spawn at this point. If multiple points have that level, use **ZonePointID** to differentiate. | Acts as a trigger volume to transition to a new SpawnPoint or Level. Used **LinkedSpawnPoint** or **LinkedTransitPoint** to determine where to transit to upon the player pawn entering. Use **TransitToLevel** to open a new level and spawn the player at a specific spawn ID. |


### Project Settings
![alt text](../../images/tutorial/subsystem_zone/tut_SubZone_projectsettings.png)
| Name | Description |
| - | - |
| `Zone Transit System` | Gamepaly System that will activate when a transition even begins, and shutdown upon the transition finishing.
| `Transition Sequence` | Level Sequence that will play forward when a transition event begins and backwards when the transition finishes.
|`Zone BGM Slot`| The BGM slot the play Zone BGMs in.

## Subsystem Functions

| - | Name | Description |
| - | - | - |
![alt text](../../images/functions/sub_zone/f_Sub-Zone_GetCurLevelData.png)| `Get Current Level Data` |
![alt text](../../images/functions/sub_zone/f_Sub-Zone_GetCurLvlRef.png) | `Get Current Level Soft Reference` | Gets a soft object reference to the current level.
![text](../../images/functions/sub_zone/f_Sub-Zone_GetCurLevelData.png)| `Get Current Level Data`|
![text](../../images/functions/sub_zone/f_Sub-Zone_GetLoadZones.png) |`Get Loaded Zones`|
![text](../../images/functions/sub_zone/f_Sub-Zone_GetLvlDat.png)| `Get Loaded Zones`|
![text](../../images/functions/sub_zone/f_Sub-Zone_GetTopZone.png)| `Get Top Loaded Zone`| Gets the ZoneAsset for the currently loaded zone.
![text](../../images/functions/sub_zone/f_Sub-Zone_GetTransitSeq.png)| `Get Transit Sequence Player` 
![text](../../images/functions/sub_zone/f_Sub-Zone_LoadDefZone.png)| `Load Default Zone`
![text](../../images/functions/sub_zone/f_Sub-Zone_LoadZone.png)| `Load Zone`
![text](../../images/functions/sub_zone/f_Sub-Zone_PlayToLvl-name.png)|`Transit Player to Level (Name)`<sup>A</sup>| 
![text](../../images/functions/sub_zone/f_Sub-Zone_PlayToLvl.png)| `Transit Player to Level`<sup>A</sup>|  
![text](../../images/functions/sub_zone/f_Sub-Zone_PlayToPoint-id.png)| `Transit Player to Point ID`<sup>A</sup>| 
![text](../../images/functions/sub_zone/f_Sub-Zone_PlayToPoint.png)| `Transit Player to Point`<sup>A</sup>| 
![text](../../images/functions/sub_zone/f_Sub-Zone_UnloadZone.png)| `Unload Zone`
![text](../../images/functions/sub_zone/f_Sub-Zone_ZoneLoaded.png)| `Is Zone Loaded`


<ol type="A">
  <li>If no "player" is input, will default to Player 0.</li>
</ol>

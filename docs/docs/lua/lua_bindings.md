## Lua Bindings


### Functions
|Function|Return|Requirement|Description|
|-|-|-|-|
`Actor_Spawn(class,transform,meta)` | Object (Actor)
`Actor_SetTransform(actor,transform)`|
`Actor_SetPosition(actor,vector)`|
`Actor_SetRotation(actor,vector)`|
`Actor_SetScale(actor,vector)`|
`Actor_GetNamed(name)` | | | Gets an actor from a global name binding.
`Party_Add(member)`| | Party System
`Party_Remove(member)`| | Party System
`Party_RemoveAll()`| | Party System
`Party_ItemGive(item,amount)`| | Party System
`Party_ItemGetAmount(item)`| int | Party System
`Party_LevelSet(member,level)`| | Party System
`Party_LevelGet(member)`| int | Party System
`Party_SkillGive(member,skill)`| | Party System
`Quest_Start(quest)`| | Quest System
`Quest_End(quest)`| | Quest System
`Level_Open(Level,StartPoint)`|
`Level_GetName()`| string
`Message_Fire(text,instigator,category,meta)` | | | Fires a Gamepaly Message
`GlobalEvent(name,meta)`| | | Fires a Global Event
`BGM_Play(name,slot,fade)`|
`BGM_Stop(slot,fade)`|


### Hooks
|Hook|Meta Values|Description|
|-|-|-|
`LEVEL_OPENED`| level(string)
`GAMEPLAY_STARTED`|
EVENTS={}

-- =====================================================================================================================================================================
-- EVENTS
-- =====================================================================================================================================================================
local class_le_system = UClass.Linear_Events.GameplaySystem
local class_le_menu = UClass.Linear_Events.Menu

function EVENTS.Delay(duration)
    return {
        T="/OmegaGameFramework/DEMO/LinearEvents/LE_Delay.LE_Delay_C",
        duration=duration,
    }
end

-- return EVENT table: Cutscene
function EVENTS.MOVIE(movie)
    return {
        T=class_le_menu,
        class='/OmegaGameFramework/DEMO/Menus/OmegaMenu_Movie.OmegaMenu_Movie_C',
        flag=movie
    }
end

function EVENTS.DLG_Line(data)
    data.T=UClass.Linear_Events.Dialogue_Message
    return data
end

function EVENTS.DIALOG(dialog,teleport_after)
    return {
        T=class_le_system,
        class=UPATHS.system_dialog,
        flag=dialog,
        teleport=teleport_after
    } 
end

function EVENTS.AWAIT_EVENT(AwaitEvent,objective)
    return {
        T='/OmegaGameFramework/DEMO/LinearEvents/LE_WaitFor_GlobalEvent.LE_WaitFor_GlobalEvent_C',
        event=AwaitEvent,
        objective=objective
    }
end 

function EVENTS.AWAIT_LEVEL(level,objective)
    return {
        T='/OmegaGameFramework/DEMO/LinearEvents/LE_WaitFor_Level.LE_WaitFor_Level_C',
        level=level,
        objective=objective
    }
end

function EVENTS.AWAIT_TAGS(tags,objective)
    return {
        T='/OmegaGameFramework/DEMO/LinearEvents/LE_WaitFor_SaveTags.LE_WaitFor_SaveTags_C',
        tags=tags,
        objective=objective
    }
end

function EVENTS.AWAIT_SPAWN(spawn,objective)
    return {
        
        T='/OmegaGameFramework/DEMO/LinearEvents/LE_WaitFor_Spawn.LE_WaitFor_Spawn_C',
        spawn=spawn,
        objective=objective
    }
end


function EVENTS.CHANGELEVEL(level,point)
    return {
        T='/OmegaGameFramework/DEMO/LinearEvents/LE_Level_Transit.LE_Level_Transit_C',
        level=level,
        point=point,
    }
end

function EVENTS.BATTLE(encounter)
    return{
        T=class_le_system,
        class=UPATHS.system_battle,

        encounter=encounter
    }
end


---@param flag string
---@param state boolean
function EVENTS.AWAIT_FLAG(flag,state)
    return {
        T='/OmegaGameFramework/DEMO/LinearEvents/LE_WaitFor_FlagState.LE_WaitFor_FlagState_C',
        flag=flag,
        state=state,
    }
end


function EVENTS.WAIT(time)
    return {
        T='/OmegaGameFramework/DEMO/LinearEvents/LE_Timer.LE_Timer_C',
        duration=time
    }
end

function EVENTS.Fade(fade,duration)
    local dur=0.5
    if (duration) then
        dur=duration
    end
    return {
        T=UClass.Linear_Events.Fade,
        fade=fade,
        duration=dur,
    }
end

function EVENTS.AsyncGlobalEvent(start,await,finish,meta)
    local dat=meta
    dat.event_start=start
    dat.event_await=await
    dat.event_end=finish
    dat.T='/OmegaGameFramework/DEMO/LinearEvents/LE_AsyncGlobalEvents.LE_AsyncGlobalEvents_C'
    return dat
end

EVENTS.Menu=function (class,flag)
    return {
        T=UClass.Linear_Events.Menu,
        class=class,
        flag=flag
    }
end

EVENTS.Tutorial=function (tutorial)
    return {
        T=UClass.Linear_Events.Menu,
        class='/OmegaGameFramework/DEMO/Menus/OmegaMenu_Tutorial.OmegaMenu_Tutorial_C',
        flag=tutorial
    }
end


--- func desc
---@param func function
function CALL(func)
   return { START=func }
end


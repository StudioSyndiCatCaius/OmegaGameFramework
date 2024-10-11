-- Await sets up a hook with an attached function. When the hook is called, the function will fire and the hook will be immediately destroyed

local create_hook=function (m,f)
    local hook_name=m..'_awaitEV'
    print('local create hook')
    SynHook.Add(m,hook_name, function (meta)
        -- when this hook is fired, play the input event and then destroy the hook
        f(meta)
        SynHook.Remove(m,hook_name)
    end)
end


function AWAIT_Event(event,func)
    create_hook("GLOBAL_EVENT",
    function (meta)
        if meta.event==event then
            func()
        end
    end)
end

function AWAIT_Level(level,func)
    create_hook("LEVEL_START",
    function (meta)
        if meta==level then
            func()
        end
    end)
end

function AWAIT_Menu_Close(menu,func)
    create_hook("MENU_CLOSE",
    function (meta)
        print(tostring(menu)..' vs '..tostring(meta.class))
        if meta.class==menu then
            func()
        end
    end)
end

function AWAIT_SYSTEM(system,func)
    create_hook("SYSTEM_SHUTDOWN",
    function (meta)
        if meta.class==system then
            func()
        end
    end)
end
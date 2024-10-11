SynHook={}

local hook_list={}

---@param hook string
---@param name string
---@param func function
function SynHook.Add(hook,name,func)
    if not (hook_list[hook]) then
        hook_list[hook]={}
    end
    hook_list[hook][name]=func
end

---@param hook string
---@param name string
function SynHook.Remove(hook,name)
    if hook_list[hook] and hook_list[hook][name] then
        hook_list[hook][name]=nil
    end
end

---@param hook string
function SynHook.Call(hook,meta)
    if hook_list[hook] then
        print("Called Hook : "..hook.." with meta: "..tostring(meta))
        for key, value in pairs(hook_list[hook]) do
            print("   run hook event: "..key.." ")
            value(meta)
        end
    end
end


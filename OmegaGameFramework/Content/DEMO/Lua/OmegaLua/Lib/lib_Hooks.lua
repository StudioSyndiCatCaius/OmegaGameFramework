SynHook={}

hook_list={}

---Adds a hook call to your code. IF name = '__next', then it will automatically asign it the name of the next available integer in that hook list.
---@param hook string
---@param func function
function SynHook.Add(hook,func,name)
    --make hook if non existent
    if not (hook_list[hook]) then
        hook_list[hook]={}
    end

    if not (name) then
        name=tostring(SynTable.key_length(hook_list[hook])+1)
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
    local out
    if hook_list[hook] then
        print("Called Hook : "..hook.." with meta: "..tostring(meta))
        for key, value in pairs(hook_list[hook]) do
            print("   run hook event: "..key.." ")
            local ret = value(meta)
            if not ret==nil then
                out=ret
            end
        end
    end
    return out
end


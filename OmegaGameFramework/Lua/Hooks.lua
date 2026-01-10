---
--- Created by jorda
--- DateTime: 12/14/2025 4:02 PM
---

local hook_list={
    
}

local hook_init=function(hook)
    if hook_list[hook]==nil then
        hook_list[hook]={}
    end 
end

_HOOK={
    
    ---@param hook string
    ---@param callback function
    ---@param id string
    add=function(hook,callback,id)
        hook_init(hook)
        hook_list[id]=callback
    end,
    
    ---@param hook string
    ---@param id string
    remove=function(hook,id)
        hook_init(hook)
        hook_list[id]=nil
    end,
    
    ---@param hook string
    ---@param meta table
    call=function(hook,meta)
        hook_init(hook)
        
        for k, v in pairs(hook_list[hook]) do
            if type(v)=="function" then
                v(meta)
            end 
        end
    end
}


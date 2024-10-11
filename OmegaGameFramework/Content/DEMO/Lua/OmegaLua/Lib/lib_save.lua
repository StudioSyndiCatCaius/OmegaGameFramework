
--[[
    INTS
]]

if not (_SAV) then _SAV={} end

local _init_ints=function() if not (_SAV['ints']) then _SAV.ints={} end end
local _init_flags=function() if not (_SAV['flags']) then _SAV.flags={} end end

---@param param string
---@param value integer
Int_Set=function (param,value)
    _init_ints()
    _SAV.ints[param]=value
end

---@param param string
---@return integer
Int_Get=function (param)
    _init_ints()
    return SynLit.INT(_SAV.ints[param])
end

---@param param string
---@param value integer
Int_Add=function (param,value)
    _init_ints()
    _SAV.ints[param] = Int_Get(param)+value
end

--[[
    FLAG
]]

---@param flag string
Flag_Get=function (flag)
    _init_flags()
    return SynLit.BOOL(_SAV.flags[flag])
end

---@param flag string
---@param value boolean
Flag_Set=function (flag,value)
    _init_flags()
    print(' is flag valid: '..tostring(flag))
    _SAV.flags[flag]=value
    UE.GLOBAL_EVENT('Flags_Updated')
    if value then
        SynHook.Call('Flag_Added',{flag=flag,value=value})
    else 
        SynHook.Call('Flag_Removed',{flag=flag,value=value})
    end 
end

---@param flag string
Flag_Add=function (flag)
    Flag_Set(flag,true)
end

---@param flag string
Flag_Remove=function (flag)
    Flag_Set(flag,false)
end
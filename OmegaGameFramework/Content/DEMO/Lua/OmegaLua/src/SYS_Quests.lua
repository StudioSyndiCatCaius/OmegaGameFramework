local a={
    _config={
        default_savedata={
            active=false,
            complete=false,
            state=0,
            states_encountered={},
        }
    }
}

-- PRIVATE
-- ========================================================================================================


-- PUBLIC
-- ========================================================================================================
---@return table Quest_GetData
function a.Quest_GetData(quest)
    return D_Quests[quest]
end

---@return table Quest_GetData_Save
function a.Quest_GetData_Save(quest)
    if not (_SAV.quests[quest]) then
        _SAV.quests[quest]=a._config.default_savedata
    end
    return _SAV.quests[quest]
end


---@return table Quest_GetData_Merged
function a.Quest_GetData_Merged(quest)
    return SynTable.Merge({a.Quest_GetData_Save(quest),D_Quests[quest]})
end


---@param quest string
function a.QUEST_START(quest)
    if not a.Quest_IsActive(quest) then
        --a.GET_QUEST_SAVE(quest).active=true
        --a.STATE_SET(quest,1)
        UE.GLOBAL_EVENT('QUEST_START',quest)
    end
end

---@param quest string
function a.QUEST_STOP(quest)
    if a.Quest_IsActive(quest) then
        a.Quest_GetData_Save(quest).active=false
        a.State_Set(quest,-1)
        UE.GLOBAL_EVENT('QUEST_STOPPED',quest)
    end
end

--[[ -------------------------------------------------------------------
    STATE 
]]   -------------------------------------------------------------------

--- Gets the current state index
---@param quest string
function a.State_GetIndex(quest)
    return SynLit.INT(a.Quest_GetData_Save(quest).state)
end

---@return integer GET_STATE_DATA
---@param quest string
function a.State_GetData(quest)
    return D_Quests[quest].states[a.State_GetIndex(quest)]
end


---@param quest string
---@param state integer
function a.State_Set(quest,state)
    print("Attmepting to set quest state: "..quest.." -> "..tostring(state))
    a.Quest_GetData_Save(quest)["state"]=state
    table.insert(a.Quest_GetData_Save(quest).states_encountered,state)
    D_Quests[quest]["states"][state].START(quest)

end




-- Go to next quest state. If invalid, quest ends.
---@param quest string
function a.STATE_NEXT(quest)

    if(D_Quests[quest]["states"][a.State_GetData]) and (D_Quests[quest]["states"][a.State_GetData]["END"]) then
        D_Quests[quest]["states"][a.State_GetData].END(quest)
    end

    a.State_Set(quest,a.State_GetData(quest)+1)
end

---@return boolean IS_ACTIVE
---@param quest string
function a.Quest_IsActive(quest)
    return SynLit.BOOL(a.Quest_GetData_Save(quest)['active'])
end

function a.Quest_IsComplete(quest)
    return SynLit.BOOL(a.Quest_GetData_Save(quest)['complete'])
end

function a.Quest_HasEncounteredState(quest,state)
    return SynTable.has_value(a.Quest_GetData_Save(quest).states_encountered,state)
end

--[[ -------------------------------------------------------------------
    GetList
]]  -------------------------------------------------------------------

local getlist_bool=function (val)
    local out={}
    for key, value in pairs(D_Quests) do
        if SynLit.BOOL(a.Quest_GetData_Save(key)[val]) then
            table.insert(out,key)
        end
    end
    return out
end

--- Gets a list of active quasts
function a.GetList_Active()
    return getlist_bool('active')
end

--- func desc
function a.GetList_Complete()
    return getlist_bool('complete')
end

function a.GetStates_Encountered(quest)
    local out={}
    for index, value in ipairs(D_Quests[quest].states) do
        if a.Quest_HasEncounteredState(quest,index) then
            table.insert(out,value)
        end
    end
    return out
end


G_Quests=a



-- ================================================================
-- Party
-- ================================================================

--
---@param member string
Party_Add=function(member) end

---@param member string
Party_Remove=function(member) end

Party_RemoveAll=function() end

--
---@param member string
---@return boolean
Party_Has=function(member) return true end

---@param member string
---@return boolean
Party_IsActive=function(member) return true end

Party_Equip=function (member,slot,item) end

-- ================================================================
-- Quest
-- ================================================================

--
---@param quest string
---@return boolean
Quest_Start=function(quest) return true end

--- func desc
---@param quest string
---@param complete boolean
Quest_End=function(quest,complete) return true end

--
---@param quest string
---@return boolean
Quest_IsActive=function(quest) return true end

--
---@param quest string
---@return boolean
Quest_IsComplete=function(quest) return true end


-- ================================================================
-- Item
-- ================================================================

Item_Give=function(item,amount) end
Item_Owned=function(item,amount) return true end
Item_GetAmount=function (item) return 0 end


-- ================================================================
-- CG
-- ================================================================

--- func desc
CG_Set=function(cg) end
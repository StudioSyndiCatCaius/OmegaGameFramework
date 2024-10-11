local a={
    _config={
        max_members=4,
        default_savedata={
            attributes={},
            xp=0.0,
            equipment={weapon='',armor='',accessory_1='',accessory_2=''},
            skills={},
            tags={},
        }
    }

}

-- PRIVATE
local get_member_Savedata=function(mem) 
    if not (_SAV.party[mem]) then
        print('setting member data for: '..mem)
        _SAV.party[mem]={}
        --SAVE_GAME.party[mem]=SynTable.copy_deep(a._config.default_savedata)
        _SAV.party[mem]=SynTable.copy_deep(_D.Character[mem].starting_data)
    end
    return _SAV.party[mem]
end

local get_eqpm=function(mem) 
    if not (get_member_Savedata(mem).equipment) then
        get_member_Savedata(mem).equipment=a._config.default_savedata.equipment
    end
    return get_member_Savedata(mem).equipment
end


local get_member_Database=function (m)
    return _D.Character[m]
end


-- PUBLIC ------------------------------------------------------------------------------------------------------
function a.EQUIPMENT_GetItemInSlot(character,slot)
    if (get_eqpm(character)[slot]) then
        return get_eqpm(character)[slot]
    end
    return ''
end

function a.EQUIPMENT_EquipItem(member,item,slot)
    a.EQUIPMENT_UnquipSlot(member,slot)
    get_eqpm(member)[slot]=item
    print([[equiped ']]..item..[[' to slot ']]..slot..[[' on ]]..member)
    SynHook.Call('SLOT_EQUIP',{member=member,slot=slot,item=item})
    G_Inventory.ITEM_GIVE(item,-1)
end

function a.EQUIPMENT_UnquipSlot(member,slot)
    local item=a.EQUIPMENT_GetItemInSlot(member,slot)
    if _D.Item[item] then
        G_Inventory.ITEM_GIVE(item,1)
        print([[Unequiped ']]..item..[[' from slot ']]..slot..[[' on ]]..member)
        get_eqpm(member)[slot]=''
        SynHook.Call('SLOT_UNEQUIP',{member=member,slot=slot,item=item})
    end
end

--- Returns a list of strings keys 
---@param character any
function a.GetItems_Equipable(character)
    local out={}
    for key, value in pairs(_SAV.inventory) do
        if (_D.Item[key]) then
            local item_data=_D.Item[key]
            print('check if '..character..' can equip -> '..key)
            if not (item_data['CanEquip']) or item_data.CanEquip(character) then
                table.insert(out,key)
            end
        end
        
    end
    return SynTable.sort_alphabetical(out)
end

function a.GetItems_EquipableInSlot(character,slot)
    local out={}
    for index, value in ipairs(a.GetItems_Equipable(character)) do
        if _D.Item[value]['equip_type']==D_EquipSlots[slot].type then
            table.insert(out,value)
        end
    end

    return SynTable.sort_alphabetical(out)
end

--[[
    ------------------------------------------------------------------------------------------------------
    FORMATION
    ------------------------------------------------------------------------------------------------------
]]

local get_formation=function() return _SAV.formation end

function a.FORMATION_SWAP(a,b)
    SynTable.swap_byIndex(get_formation(),a,b)
end

function a.FORMATION_SWAP_MEMBERS(a,b)
    SynTable.swap_byValue(get_formation(),a,b)
end

function a.FORMATION_GET_SLOT(index)
    if (_SAV.formation[index]) then
        return _SAV.formation[index]
    end
    return ''
end

function a.FORMATION_GET_INDEX(character)
    return SynTable.find_index(get_formation(),character)
end


function a.FORMATION_ADD(member)
    if not a.FORMATION_HAS(member) then
        table.insert(get_formation(),member)
    end
end

function a.FORMATION_REMOVE(member)
    SynTable.remove_value(get_formation(),member)
end

function a.FORMATION_REMOVEALL()
    _SAV.formation={}
end



--- func desc
---@param member string
---@return boolean
function a.FORMATION_HAS(member)
    return SynTable.has_value(get_formation(), member)
end

function a.GetMember_SaveData(member)
    return get_member_Savedata(member)
end


function a.GetMember_Data(member)
    return SynTable.Merge({get_member_Database(member),get_member_Savedata(member)})
end



function a.MEMBERS_All_GetSaveData()
    local out={}
    for key, value in pairs(_D.Character) do
        if (value['starting_data']) then
            out[key]=a.GetMember_SaveData(key)
        end
    end
    return out
end


function a.MEMBERS_All_GetData()
    local out={}
    for key, value in pairs(_D.Character) do
        if (value['starting_data']) then
            out[key]=a.GetMember_Data(key)
        end
    end
    return out
end

function a.MEMBERS_All_GeyKeys()
    local out={}
    for key, value in pairs(_D.Character) do
        if (value['starting_data']) then
            table.insert(out,key)
        end
    end
    return out
end


--- func desc
---@param tag string
function a.MEMBER_HAS_TAG(member, tag)
    return SynTable.has_value(get_member_Savedata[member].tags,tag)
end

--[[
    ------------------------------------------------------------------------------------------------------
    SKILLS
    ------------------------------------------------------------------------------------------------------
]]

local get_skills=function (m)
    if not (get_member_Savedata(m)['skills']) then
        get_member_Savedata(m).skills={}
    end
    return get_member_Savedata(m).skills
end

--- func desc
---@param member string
---@param skill string
---@return boolean
function a.MEMBER_HasSkill(member,skill)
    return SynTable.has_value(get_skills(member),skill)
end

--- func desc
---@param member string
---@param skill string
function a.Member_AddSkill(member,skill)
    if not a.MEMBER_HasSkill(member,skill) then
        table.insert(get_skills(member),skill)
        SynTable.remove_duplicates(get_skills(member))
    end
end

function a.Member_RemoveSkill(member,skill)
    if a.MEMBER_HasSkill(member,skill) then
        SynTable.remove_value(get_skills(member),skill)
    end
end

--[[
    ------------------------------------------------------------------------------------------------------
    IS
    ------------------------------------------------------------------------------------------------------
]]
function a.IS_Active(member)
    local val_index = a.FORMATION_GET_INDEX(member)
    local val_max=a._config.max_members
    print(tostring(val_index)..'/'..tostring(val_max))
    return val_index<=val_max
end

function a.IS_InParty(member)
    return SynTable.has_value(get_formation(),member)
end

--[[
    ------------------------------------------------------------------------------------------------------
    Attribute
    ------------------------------------------------------------------------------------------------------
]]

local get_att_val=function (m,at)
    if (get_member_Savedata(m).attributes[at]) then
        return get_member_Savedata(m).attributes[at]
    end
    return 0
end

--- func desc
---@param character string
---@param attribute string
---@param inc integer
---@param mult number
function a.ATTRIBUTE_MODIFY(character,attribute,inc,mult)
    get_member_Savedata(character).attributes[attribute]=get_att_val(character,attribute)+inc
end


--[[
    ------------------------------------------------------------------------------------------------------
    Get Members
    ------------------------------------------------------------------------------------------------------
]]

---@param func function
local getmembers_filtered=function (func)
    local out={}
    for key, value in ipairs(_SAV.formation) do
        if SynLit.BOOL(func(value)) then
            table.insert(out,value)
        end
    end
    --table.sort(out)
    return out
end

function a.MEMBERS_Party_GetInParty()
    return get_formation()
end

function a.MEMBERS_Party_GetActive()
    return getmembers_filtered(function (key,dat)
        return a.IS_Active(key)
    end)
end

function a.MEMBERS_Party_GetReserve()
    return getmembers_filtered(function (key,dat)
        return not a.IS_Active(key)
    end)
end

G_Party=a



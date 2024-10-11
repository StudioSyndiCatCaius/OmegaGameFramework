G_Inventory={
    max_amount=99
}


local get_inv=function () return _SAV.inventory end

--- func desc
---@param item string
---@return integer
function G_Inventory.ITEM_GET_AMOUNT (item)
    if (get_inv()[item]) then
        return get_inv()[item]
    end
    return 0
end

--- func desc
---@param item string
---@param amount integer
function G_Inventory.ITEM_GIVE (item,amount)
    print('Item given: '..item.." "..tostring(amount))
    get_inv()[item]=G_Inventory.ITEM_GET_AMOUNT(item)+amount
    
    UE.GLOBAL_EVENT('Save_Updated')
end

--- func desc
---@param items table
function G_Inventory.ITEM_GIVELIST (items)
    for key, value in pairs(items) do
        G_Inventory.ITEM_GIVE(key,value)
    end
end

--Gets the inventory. Removes all values under 1.
function G_Inventory.GET()
    local out={}
    for key, value in pairs(_SAV.inventory) do
        if value>0 then
            out[key]=value
        end
    end
    return out
end

function G_Inventory.GetItems_ByType(type)
    local out={}
    for key, value in pairs(_SAV.inventory) do
        if (_D.Item[key]) then
            local item_dat=_D.Item[key]
            if (item_dat['type']) and item_dat['type']==type then
                out[key]=value
            end
        end
    end
    return out
end


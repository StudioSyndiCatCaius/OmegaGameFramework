-- Extended Table Library
SynTable={}

--[[
    Copy
]]

function SynTable.key_length(tbl)
    local out=0
    for key, value in pairs(tbl) do
        out=out+1
    end
    return out
end


function SynTable.copy_shallow(original)
    local copy = {}
    for key, value in pairs(original) do
        copy[key] = value
    end
    return copy
end


function SynTable.copy_deep(original)
    local original_type = type(original)
    local copy
    if original_type == 'table' then
        copy = {}
        for original_key, original_value in next, original, nil do
            copy[SynTable.copy_deep(original_key)] = SynTable.copy_deep(original_value)
        end
        setmetatable(copy, SynTable.copy_deep(getmetatable(original)))
    else -- for number, string, boolean, etc.
        copy = original
    end
    return copy
end


function SynTable.remove_duplicates(tbl)
    local unique = {}
    local result = {}

    for i, v in ipairs(tbl) do
        if not unique[v] then
            table.insert(result, v)
            unique[v] = true
        end
    end

    return result
end

--- func desc
---@param t1 table
---@param t2 table
---@param unique boolean
function SynTable.append_values(t1, t2, unique)
    -- Iterate over the second table
    for i = 1, #t2 do
        -- Append each element of t2 to t1
        t1[#t1 + 1] = t2[i]
    end

    if unique then
        return SynTable.remove_duplicates(t1)
    end
    return t1
end


function SynTable.filter_byField(tbl, fieldName, fieldValue)
    local filtered = {}
    for _, item in ipairs(tbl) do
        if item[fieldName] == fieldValue then
            SynTable.insert(filtered, item)
        end
    end
    return filtered
end


function SynTable.KeysToValues(tbl_in)
    local out={}

    for key, value in pairs(tbl_in) do
        
        table.insert(out,key)
    end
    
    return out
end

---@param tbl table
---@param Keys table
function SynTable.filter_byKeys(tbl, Keys)
    local filtered = {}
    for key, item in pairs(tbl) do
        if SynTable.has_value(Keys,key) then
            filtered[key]=item
        end
    end
    return filtered
    
end


--Filter a Table from functions
function SynTable.filter_byFunction(tbl, filterFunc,meta)
    print("started table filter")
    if (filterFunc==nil) then
        print("filter function was invalid. returning full table")
        return tbl
    end
    
    local filteredTbl = {}
    for key, value in pairs(tbl) do
        print("starting filter with key values: "..key)
        if filterFunc(key, value,meta) then
            filteredTbl[key]=value
        end
    end
    return filteredTbl
end

--Filter a Table from functions
function SynTable.sort_byFunction(tbl, sort_function, reverse, meta)
    local new_table = tbl

    local function sortingFunction(a, b)
        return sort_function(a, b, meta)
    end


    if reverse then
        SynTable.sort(new_table, function(a, b)
            return not sortingFunction(a, b)
        end)
    else
        SynTable.sort(new_table, sortingFunction)
    end
    return new_table
end



function SynTable.sort_alphabetical(tbl)
    table.sort(tbl, function(a,b) return a < b end)
    return tbl
end

function SynTable.find_index(tbl, value)
    for i, v in ipairs(tbl) do
        if v == value then
            return i
        end
    end
    return -1 -- Return nil if the value is not found
end

function SynTable.has_value(tbl, value)
    for _, v in pairs(tbl) do
        if v == value then
            return true
        end
    end
    return false
end


function SynTable.Merge(tables)
    local out={}
    for index, table_val in ipairs(tables) do
        for key, value in pairs(table_val) do
            out[key]=value
        end
    end
    return out
end

function SynTable.remove_value(tbl,value)
    table.remove(tbl,SynTable.find_index(tbl,value))
end

SynTable.random_key=function (tbl)
    local keys = {}
    for key in pairs(tbl) do
        table.insert(keys, key)
    end

    if #keys == 0 then
        return nil
    end

    local randomIndex = math.random(1, #keys)
    return keys[randomIndex]
end

SynTable.random_value=function (tbl)
    local values = {}
    for _, value in pairs(tbl) do
        table.insert(values, value)
    end

    if #values == 0 then
        return nil
    end

    local randomIndex = math.random(1, #values)
    return values[randomIndex]
end

--[[ ------------------------------------------------------------------------------------------------------
    SWAP
]] ------------------------------------------------------------------------------------------------------

function SynTable.swap_byIndex(t, index1, index2)
    if t[index1] and t[index2] then
        t[index1], t[index2] = t[index2], t[index1]
    else
        print("Invalid indices provided.")
    end
end



function SynTable.swap_byValue(t, value1, value2)
    local index1, index2
    for i, v in ipairs(t) do
        if v == value1 then
            index1 = i
        elseif v == value2 then
            index2 = i
        end
    end

    if index1 and index2 then
        t[index1], t[index2] = t[index2], t[index1]
    else
        print("Values not found in the table.")
    end
end

--[[
    get
]]



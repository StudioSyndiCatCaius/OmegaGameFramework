-- converts an array of lua values into a dictionary table, using the values 'key' field

return function (tbl, toUpper)
    toUpper = toUpper or false  -- default to lowercase
    local newTable = {}
    
    for key, value in pairs(tbl) do
        local newKey = key
        if type(key) == "string" then
            newKey = toUpper and string.upper(key) or string.lower(key)
        end
        newTable[newKey] = value
    end
    
    return newTable
end
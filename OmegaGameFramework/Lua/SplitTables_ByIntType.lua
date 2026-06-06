return function (tbl, offset)
    offset = offset or 0  -- Default to 0 if not provided
    
    -- Find the maximum type value
    local maxType = 0
    for key, value in pairs(tbl) do
        local _valType=tonumber(value.type)
        if _valType and _valType > maxType then
            maxType = _valType
        end
    end
    
    -- Initialize output array with empty tables
    local output = {}
    for i = 1, maxType + offset do
        output[i] = {}
    end
    
    -- Distribute entries into their respective type tables
    for key, value in pairs(tbl) do
        local _valType=tonumber(value.type)
        if _valType then
            local index = _valType + offset
            output[index][key] = value
        end
    end
    
    return output
end
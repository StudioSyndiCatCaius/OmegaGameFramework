--Unstringify table values (changes any table values from string to int/float/bool IF possible)
local function unstringify(tbl, recursive)
    for k, v in pairs(tbl) do
        if type(v) == "string" then
            -- Check for boolean
            if v == "true" then
                tbl[k] = true
            elseif v == "false" then
                tbl[k] = false
            else
                -- Check for number (handles both int and float)
                local num = tonumber(v)
                if num then
                    tbl[k] = num
                end
            end
        elseif recursive and type(v) == "table" then
            unstringify(v, true)
        end
    end
    return tbl
end

return unstringify
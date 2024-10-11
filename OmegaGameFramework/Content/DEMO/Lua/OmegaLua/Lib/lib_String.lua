local a={} --Strings

--- func desc
---@param str string
---@param at string
---@param reverse boolean
a.split = function (str, at, reverse)
    local out = {left = "", right = "", success = false}
    local pos

    if reverse then
        pos = str:match(".*()"..at)
    else
        pos = str:find(at)
    end

    if pos then
        out.left = str:sub(1, pos - 1)
        out.right = str:sub(pos + 1)
        out.success = true
    end

    return out
end



 -- Split a string by a delimiter
    --replacers:
        -- _BREAK = line break 


a.parse = function (str, delimiter, include_delimiter)
    local replacers = {
        _Break = "^\r\n",
    }

    local new_delim = delimiter --.."(%w+)"
    if replacers[delimiter] then
        new_delim = replacers[delimiter]
    end


    local result = {}
    local pattern = include_delimiter and ("([^" .. new_delim .. "]+)") or ("[^" .. new_delim .. "]+")
    
    for match in string.gmatch(str, pattern) do
        if not include_delimiter then
            table.insert(result, match)
        else
            table.insert(result, new_delim .. match)
        end
    end

    return result
end




a.ToValue=function (str)
    if str == "true" then
        return true
    elseif str == "false" then
        return false
    elseif tonumber(str) then
        return tonumber(str)
    else
        return str
    end
end

a.extract = function (str, start, stop)
    local out = ""
    local start_pos, stop_pos

    start_pos = str:find(start, 1, true)
    if start_pos then
        stop_pos = str:find(stop, start_pos + #start, true)
        if stop_pos then
            out = str:sub(start_pos + #start, stop_pos - 1)
        end
    end

    return out
end



SynString=a
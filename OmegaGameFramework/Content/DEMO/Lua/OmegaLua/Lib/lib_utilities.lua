Util={}

-- =========================================================================
-- TABLES
-- =========================================================================

-- ==============================================
-- Translation
-- ==============================================
Util.Culture_default="en"
Util.Culture_current="en"

---localizes a string based on current culture. Will return if just a string,
function LOC(string)
    if type(string) == "string" then
        return string
    end
    if (string[Util.Culture_current]) then
        return string[Util.Culture_current]
    end
    if (string[Util.Culture_default]) then
        return string[Util.Culture_default]
    end
    return ""
end


-- ==============================================
-- MATH
-- ==============================================
function RNG(chance)
    if not type(chance)=="number" then
        return false
    end
    local val = math.random()
    return (val<=chance)
end




return Util


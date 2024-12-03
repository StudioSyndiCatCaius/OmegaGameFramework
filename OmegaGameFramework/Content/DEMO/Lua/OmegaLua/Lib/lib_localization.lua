local a={}

a._config={
    default_language='en'
}


--[[
    Adds a new localization value to a single text field.
        * IF the field is TABLE: Simply addes the now value key 
        * IF the field is STRING: converts the field to a table, with the string as the value for the ``default_language`` in ``_config``
]]

--- func desc
---@param field any
---@param injected_language string
---@param injected_text string
---@return table
a.Inject_SingleText=function (field,injected_language,injected_text)
    if type(field)=='string' then
        local sav_str=field
        field={}
        field[a._config.default_language]=sav_str
        field[injected_language]=injected_text
    elseif type(field)=='table' then
        field[injected_language]=injected_text
    end
    return field
end



-- Localiztion Library
SynLoc=a
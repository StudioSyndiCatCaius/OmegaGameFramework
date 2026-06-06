-- converts an array of lua values into a dictionary table, using the values 'key' field

return function (tbl)
    
local out={}

for index, value in ipairs(tbl) do
    
    if value['key']==nil then
        out[tostring(index)]=value
    else
        out[value['key']]=value
    end


end

return out

end
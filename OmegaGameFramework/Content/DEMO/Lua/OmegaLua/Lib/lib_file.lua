local a={}

function a.get_fileExtension(filepath)
    local v = filepath:match("^.+(%..+)$")
    if (v) then
        return v
    end
    return '_NONE'
end

a.filterFiles_WithExtension=function (files,extension)
    local out={}
    for index, value in ipairs(files) do
        local ext=a.get_fileExtension(value)
        if ext==extension then
           table.insert(out,value) 
        end
    end
    return out
end

a.ListFiles_InDirectory=function (dir,filter_extension)
    local out={}
    local path=[[dir "]]..dir..[[" /b]]

    --base table
    --[[
    for new_dir in io.popen(path):lines() do 
        table.insert(out,dir..[\]..new_dir)
    end
    ]]

    local file_list = UE.FILES_GET_IN_PATH(path)
    for index, new_dir in ipairs(file_list) do
        table.insert(out,dir..[[\]]..new_dir)
    end

    out=a.filterFiles_WithExtension(out,filter_extension)

    return out
end



a.StringFromFile=function (file)
    local opened = io.open(file, "rb")
    if type(opened) == "string" then
        return opened
    end
    local f = assert(opened)
    local content = f:read("*all")
    f:close()
    return content
end


SynFile=a
-----------


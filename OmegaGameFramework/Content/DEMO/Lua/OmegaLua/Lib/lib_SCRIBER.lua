-- parser for SCRIBER dialogue format for lua 

SCRIBER={
    PARSE={
    }
}

local c={
    
}



SCRIBER.PARSE.csv=function (script)
    
end

SCRIBER.PARSE.txt=function (input)
    local tbl = {}
    local current_section = tbl
    local sections = {}
    local function parse_line(line)
        
        --CHOICES
        if line:match("^%+%s*$") then
            table.insert(tbl, {choices = {}})
            current_section = tbl[#tbl].choices

        --LINE KEY
        elseif line:match("^%s*<([^>]+)%s*$") then
            local key = line:match("^%s*<([^>]+)%s*$")
            table.insert(tbl, {key = key})
            current_section = tbl

        --JUMP TO KEY
        elseif line:match("^%s*>%s*(%w+)%s*$") then
            local jump = line:match("^%s*>%s*(%w+)%s*$")
            table.insert(current_section, {jump = jump})

        --Function call
        elseif line:match("^%s*%[.*%]%s*$") then
            local call = line:match("^%s*%[(.*)%]%s*$")
            table.insert(current_section, {call = load("return function() " .. call .. " end")()})

            --Condition Call
        elseif line:match("^%s*%{%s*return.*%}%s*$") then
            local condition = line:match("^%s*%{%s*(return.*)%}%s*$")
            table.insert(current_section, {condition = load("return function() " .. condition .. " end")()})

        --normal line
        elseif line:match("^%s*Fellow:%s*(.*)%s*$") then
            local text, tags = line:match("^%s*Fellow:%s*(.*)%s*(#.*)%s*$")
            tags = tags and tags:sub(2):split("#") or nil
            table.insert(current_section, {speaker = 'Fellow', line = text, tags = tags})

        --jump 2
        elseif line:match("^%s*-%s*(.-)%s*>%s*(%w+)%s*$") then
            local text, jump = line:match("^%s*-%s*(.-)%s*>%s*(%w+)%s*$")
            table.insert(current_section, {text = text, jump = jump})

        --ignore empty lines
        elseif line:match("^%s*$") then
            -- Ignore empty lines
        else
            table.insert(current_section, {speaker = '', line = line})
        end
    end

    for line in input:gmatch("[^\r\n]+") do
        parse_line(line)
    end

    return tbl
    
end
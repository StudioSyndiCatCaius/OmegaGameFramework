
D_Dialogs={}


G_Dialog={
    PARSE={},
    IMPORT_FOLDER=function (path,extension)

        for index, value in ipairs(UE.FILES_GET_IN_PATH(path,extension)) do
            local file_string = SynFile.StringFromFile(value)

            if extension=='txt' then
                local script_list=SynString.parse(file_string,"*")
                for i, script in ipairs(script_list) do
                    local split_data=SynString.split(script,"[\r\n]+",false)
                    local dlg_key=split_data.left
                    D_Dialogs[dlg_key]=G_Dialog.PARSE.TXT(split_data.right)
                end
            end
            
            if extension=='csv' then
                G_Dialog.PARSE.CSV(file_string)
            end

        end
    end,
    Get_Line_FromKey=function (key,line)
        for index, value in ipairs(D_Dialogs[key]) do
            if (value.key) and value.key==line then
                return value
            end
        end
    end
}

G_Dialog.PARSE.TXT=function(script)
    local out={}
    local choice_queue={}
    local raw_lines={}

    local symbol_config={
        {
            symbol='<',
            parse=function (str,line)
                line['key']=str:match("<(%w+)")
            end,
        },
        {
            symbol='>',
            parse=function (str,line)
                line['jump']=str:match(">(%w+)")
            end,
        },
        { --delay
            symbol='$',
            parse=function (str,line)
                line['delay']=str:match("$(%w+)")
            end,
        },
        {
            symbol="#",
            parse=function (str,line)
                line['tags']={}
                print(str)
                local parse_dat = SynString.parse(str,'*')
                for index, value in ipairs(parse_dat) do
                    print('parsed tag '..value)
                    table.insert(line.tags,value)
                end
                --line['jump']=str:match(">(%w+)")
            end,
        },
        {
            symbol="%[",
            parse=function (str,line)
                --script
                local str_call=str:match("%[(.-)%]")
                if str_call~='' then
                    line['call']=str_call --function() load(str_call)() end
                end
            end,
        },
        {
            symbol='{',
            parse=function (str,line)
                --condition
                local str_condition=str:match("%{(.-)%}")
                if str_condition~='' and str_condition~=nil then
                    line['condition']="return "..str_condition --function() load("return " .. str_condition)() end
                end
            end,
        },
    }

    for index, value in ipairs(SynString.parse(script,"_Break")) do
        table.insert(raw_lines,value)
    end

    --for each txt line
    for index, value in ipairs(raw_lines) do

        --SETUP
        local function _splitBySymbol(str)
            for index, value in ipairs(symbol_config) do
                local split_dat=SynString.split(str,value.symbol,false)
                if split_dat.success then
                    return split_dat.left
                end
            end
            return str
        end

        local new_line={}
        local firt_string=string.sub(value,1,1)

        --parse symbol data
        for config_index, config_value in ipairs(symbol_config) do
            config_value.parse(value,new_line)
        end
    
        --IS choice?
        if firt_string=='-' then
            new_line['text']=_splitBySymbol(value)
            table.insert(choice_queue,new_line)

        --Is ChoiceHub
        elseif firt_string=='+' then
            
            table.insert(out,{
                choices=SynTable.copy_deep(choice_queue)
            })
            choice_queue={}

        --Is line
        else
            local text_left=value

            local split_data={} 
            --Line & Speaker
            split_data=SynString.split(_splitBySymbol(value),':',false)
            if split_data.success then
                new_line['speaker']=split_data.left
                new_line['line']=split_data.right
            else
                new_line.line=_splitBySymbol(value)
            end

            table.insert(out,new_line)
        end
    end
    return out
end


--[[
    CSV
]]
G_Dialog.PARSE.CSV=function (file_string)
    local tbl=SynParse.CSV(file_string)
    local scene_key=''
    local line_index=0
    local line_key=function() return scene_key.."_"..tostring(line_index) end
    local choice_queue={}

    for index, value in ipairs(tbl) do
        local new_event=value
        if value['scene']~='' then
            scene_key=value['scene']
            D_Dialogs[scene_key]={}
        end

        --skip line iall empty
        local valid_val=false
        for key, subvalue in pairs(value) do
            if subvalue~=nil or subvalue~='' then
                valid_val=true
                break
            end
        end

        --remove direction string
        new_event['direction']=nil

        --add event
        if scene_key~='' and valid_val then
            --is choice
            if new_event['cmd']=='-' then
                new_event['text']=new_event['line']
                table.insert(choice_queue,new_event)
            elseif new_event['cmd']==[[$]] then
                local choice_ev={
                    choices=SynTable.copy_deep(choice_queue)
                }
                table.insert(D_Dialogs[scene_key],SynTable.copy_deep(choice_ev))
                choice_queue={}
            else
                --default line
                
                --[[
                --autoset line key
                line_index=line_index+1
                if new_event['text']~="" and new_event['key']=="" then
                    new_event['key']=line_key()
                end
                ]]
                
                table.insert(D_Dialogs[scene_key],SynTable.copy_deep(new_event))
            end
        end

    end
 end


--[[ ----------------------------------------------------------------------------------------------------
    DLG 
]]   ----------------------------------------------------------------------------------------------------
PO={
    char={},
    bkg='',
}
local c={}
local po_positions=function (val)
    if type(val) =="number" then
        return {
            position={x=val*150,y=0},
            shear={x=0,y=0},
            scale={x=1,y=1},
        }
    end

    local out={
        position={x=0,y=0},
        shear={x=0,y=0},
        scale={x=1,y=1},
    }
    for key, value in pairs(out) do
        if (val[key]) then
            out[key]=val[key]
        end
    end
    return out
end
local char_get=function (char)
    if not (PO.char[char]) then
        PO.char[char]={
            layer=100,
            visible=false,
            transform={
                position={x=0,y=0},
                shear={x=0,y=0},
                scale={x=1,y=1},
            },
            state='default',
        }
    end
    return PO.char[char]
end

--[[
    Characters
]]

c.Move=function (id,target)
    print(tostring(target))
    char_get(id).transform=po_positions(target)
    UE.GLOBAL_EVENT('Update_Portrait',{})
end

---@param id string
---@param position integer
c.Add=function (id,position,speed)
    print('big ups')
    c.Move(id,position)
    char_get(id).visible=true
    if (speed) then
        char_get(id)['speed']=speed
    end
    UE.GLOBAL_EVENT('Update_Portrait',{})
end

--- 
---@param id string
c.Remove=function (id)
    char_get(id).visible=false
    UE.GLOBAL_EVENT('Update_Portrait',{})
end

c.Get=function (id)
    return char_get(id)
end

c.RemoveAll=function ()
    for key, value in pairs(PO.char) do
        value.visible=false
    end
    UE.GLOBAL_EVENT('Update_Portrait',{})
end

c.State=function (id,state)
    char_get(id).state=state
    UE.GLOBAL_EVENT('Update_Portrait',{})
end

c.Scale=function (id,scale)
    c.Move(id,{scale={x=scale,y=scale}})
end

--[[
    BKG
]]

local bkg={}

function bkg.SET(bkg)
    PO.bkg=bkg
    UE.GLOBAL_EVENT('Update_Portrait',{})
end


--[[ ----------------------------------------------------------------------------------------------------
    FINALIZE 
]]   ----------------------------------------------------------------------------------------------------

DLG={
    _={
        char={}
    },
    Char=c, --characters
    BKG=bkg,
}


SynHook.Add('Dialog_Line','po',function (meta)
    if (meta['speaker']) then
        local speaker=meta['speaker']

        if (meta['portrait']) and tostring(meta.portrait)~='' then

            DLG.Char.State(speaker,meta['portrait'])
        end
    end
end)


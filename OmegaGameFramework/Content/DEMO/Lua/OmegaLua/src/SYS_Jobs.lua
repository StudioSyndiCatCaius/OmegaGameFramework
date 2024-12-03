local a={}

local getdat=function (key)
    if _SAV.party[key]['jobs']==nil then
        _SAV.party[key]['jobs']={}
    end
    return _SAV.party[key]['jobs']
end

---------------------------------------------------------------------------------------------------------------------

a.New_Job=function (key,data)
    if _D.Jobs==nil then _D.Jobs={} end

    data.icon=UGET.Icon('ico_job_'..key)
    _D.Jobs[key]=data
end


a.GetJobs_Available=function (key)
    return getdat(key)
end

a.GetJob_FromCharacter=function (character, job)
    if getdat(character)[job]==nil then
        getdat(character)[job]={}
    end
    return getdat(character)[job]
end

--- func desc
---@param char string
---@param job string
---@param is_unlocked boolean
a.SetJob_Unlocked=function (char,job,is_unlocked)
    if is_unlocked then
        table.insert(getdat(char),job)
    else
        SynTable.remove_value(getdat(char),job)
    end
end

a.JP_Get=function (char)
    if _SAV.party[char]['jp']==nil then _SAV.party[char]['jp']=0 end
    return SynLit.INT(_SAV.party[char]['jp'])
end

local getjp_skill=function (skill)
    return _D.Skills[skill]['jp_cost']
end

a.Skill_CanUnlock=function (char,skill)
    if a.Skill_IsUnlocked(char,skill) then
        return false
    end
    local jp_owned=a.JP_Get(char)
    local jp_needed=SynLit.INT(getjp_skill(skill))
    return jp_owned>=jp_needed
end

a.Skill_Unlock=function (char,skill)
    if a.Skill_CanUnlock(char,skill) then
        table.insert(_SAV.party[char].skills,skill)
        _SAV.party[char].jp=a.JP_Get(char)-getjp_skill(skill)
        return true
    end
    return false
end

a.Skill_IsUnlocked=function (char,skill)
    return SynTable.has_value(_SAV.party[char]['skills'],skill)
end

---------------------------------------------------------------------------------------------------------------------
-- INSTALL
if _A==nil then _A={} end
_A.Jobs=a
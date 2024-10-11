local level_ups={}

local a={}

local PRESET_LevelUpgrades={
    Skill=function ()
        local skill_key=SynTable.random_key(D_Skills)
        local skill_data=D_Skills[skill_key]
        return {
            description="Unlock new skill: "..skill_data.name,
            icon=UGET.Icon('ico_upgrade_skill'),
            skill=skill_key,
            UpgradeChosen=function (self,character)
                a.MEMBER_SET_HAS_SKILL(character,self.skill,true)
            end,
        }
        
    end,
    StatUp=function ()
        local att=SynTable.random_key(D_Attributes)
        local att_dat=D_Attributes[att]
        local att_amount=att_dat.upgrade_amount
        return {
            description="Increase "..att.." +"..tostring(att_amount),
            icon=att_dat.icon,
            attribute=att,
            amount=att_amount,
            UpgradeChosen=function (self,character)
                a.ATTRIBUTE_MODIFY(character,self.attribute,self.amount,0)
            end,
        }
    end
}

--- 
---@param count integer
a.RandomSelector=function (count)
    local out={}
    for i = 1, count, 1 do
        table.insert(out,SynTable.random_value(PRESET_LevelUpgrades)())
    end
    return out
end


G_Rogue=a


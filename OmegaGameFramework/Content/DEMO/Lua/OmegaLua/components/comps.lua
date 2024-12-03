local c={}

-- ==============================================
-- Attributes
-- ==============================================
c.Attributes=function ()
    return {
        attribute_values={},

        GetValue_Base=function (self,attribute)
            return 0
        end,
        GetValue_Max=function (self,attribute)
            return 0
        end,
        GetValue_Current=function (self,attribute)
            return 0
        end,

        DamageAttribute=function (self,attribute,damage_amount,meta)
            self.attribute_values[attribute]=self:GetValue_Current(attribute)-damage_amount
        end,
    }
end

local att=c.Attributes()


-- ==============================================
-- Equipment
-- ==============================================
c.Equipment=function ()
    return {
        equipment={},

        GetItemInSlot=function (self,slot)
            return self.equipment[slot]
        end,

        EquipItem=function (self,item,slot)
            self:UnequipSlot(slot)
            self.equipment[slot]=item
        end,

        UnequipItem=function (self,item,all)
            for key, value in pairs(self.equipment) do
                if self:GetItemInSlot(key)==item then
                    self:UnequipSlot(key)
                    if not all then
                        return
                    end
                end
            end
        end,

        UnequipSlot=function (self,slot)
            self.equipment[slot]=''
        end,
    }
end

local eq=c:Equipment()

eq:EquipItem('sword_1','weapon')

-- ==============================================
-- Equipment
-- ==============================================
c.Inventory=function ()
    return {
        items={},
        GetItemAmount=function (self,item)
            return SynLit.INT(self.items[item])
        end,
        AddItem=function (self,item,amount)
            self.items[item]=self:GetItemAmount(item)+amount
        end,
    }
end


-- ==============================================
-- Turn Manager
-- ==============================================
c.TurnManager=function ()
    return {
        turn_order={},
        combatants={},
        NextTurn=function ()
            
        end,
        Generate_TurnOrder=function ()
            
        end
    }
end


local ev={
    menu=function (options,postition,size,on_close)
        
    end
}
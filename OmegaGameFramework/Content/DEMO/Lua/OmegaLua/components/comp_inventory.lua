--------------------------------------------------------------------
-- Component: Inventory
--------------------------------------------------------------------

COMP.Inventory=function ()
    
    return {
        items={},
        --- func desc
        ---@param item string
        ---@param amount integer
        Give=function (self,item,amount)
            self.items[item]=self.items[item]+amount
        end,

        Transfer=function (target_inventory)
            
        end,

        GetAmount=function (item,amount)
            
        end
    }
end

local adam={
    inv=COMP.Inventory()
}

adam.inv:Give('potion_1',2)
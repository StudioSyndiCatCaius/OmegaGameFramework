D_Days={}
G_DAYS={
    START_DAY=function(day)
        if day ~= _SAV.day then
            _SAV.day=day
            G_Quests.QUEST_START(day)
        end
    end,

    GET_DAY_DATA=function (day)
        return D_Days[_SAV.day]
    end,
}

-- =======================================
-- DAYS
-- =======================================
local weekdays = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}



local function getWeekday(day, month)
    -- Helper function to calculate the day of the week using Zeller's Congruence
    local function zellersCongruence(day, month, year)
        if month < 3 then
            month = month + 12
            year = year - 1
        end

        local k = year % 100
        local j = math.floor(year / 100)

        local h = (day + math.floor((13 * (month + 1)) / 5) + k + math.floor(k / 4) + math.floor(j / 4) - 2 * j) % 7

        return h
    end

    -- Weekday names

    -- Fixed year 2000
    local year = 2000

    -- Get the day of the week (0 = Saturday, 1 = Sunday, ..., 6 = Friday)
    local dayOfWeek = zellersCongruence(day, month, year)

    -- Return the corresponding weekday name
    return weekdays[dayOfWeek + 1]
end


G_DAYS.Get_DayofWeek=function ()
   return getWeekday(_SAV.day,_SAV.month) 
end
local active_events={}


local a={}


--- func desc
---@param event_sequence table
---@param end_callback function
---@return table
a.Play=function (event_sequence,end_callback)
    return {
        sequence=event_sequence,
        current_event=1,

        GetCurrent=function (self)
            return self.sequence[self.current_event]
        end,

        Next=function (self)
            if (self.sequence[self.current_event]) then
                self.GetCurrent():ON_END(self)
            end

            local next_event=self.current_event+1

            if (self.sequence[next_event]) then
                self.current_event=next_event
                self.GetCurrent():ON_START(self)
            else
                self.END('_FINISHED_')
            end
        end,

        End=function (reason)
            end_callback(reason)
        end
    }
end


_A.Event=a

-- ==========================================
-- Events
-- ==========================================
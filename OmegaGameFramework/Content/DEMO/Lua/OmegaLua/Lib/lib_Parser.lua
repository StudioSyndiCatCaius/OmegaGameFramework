

SynParse={
    CSV=function(input)
        local result = {}
        local headers = {}
        local isFirstLine = true
    
        local function parseLine(line)
            local row = {}
            local fieldStart = 1
            local inQuotes = false
            local currentField = ""
    
            for i = 1, #line do
                local c = line:sub(i, i)
                if c == '"' then
                    -- Toggle inQuotes flag
                    inQuotes = not inQuotes
                elseif c == ',' and not inQuotes then
                    -- End of field
                    table.insert(row, currentField)
                    currentField = ""
                    fieldStart = i + 1
                else
                    -- Accumulate characters into the current field
                    currentField = currentField .. c
                end
            end
            -- Capture any remaining field data after the last delimiter
            if currentField ~= "" or line:sub(-1) == ',' then
                table.insert(row, currentField)
            end
            return row
        end
    
        -- Split the input into lines
        for line in input:gmatch("[^\r\n]+") do
            if isFirstLine then
                -- Capture headers
                headers = parseLine(line)
                isFirstLine = false
            else
                -- Process each subsequent line according to headers
                local rowValues = parseLine(line)
                local row = {}
                for i, header in ipairs(headers) do
                    row[header] = rowValues[i] or ""
                end
                table.insert(result, row)
            end
        end
    
        return result
    end,
    --A linear txt game dialogue ditiing format Developed by studio SyndiCat.
    SCB=function (string)
        return {}
    end,
    
}





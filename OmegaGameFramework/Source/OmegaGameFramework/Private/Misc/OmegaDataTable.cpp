#include "Misc/OmegaDataTable.h"

// ── Column Operations ─────────────────────────────────────────────────────────

void UOmegaDataTable::AddColumn(const FString& Header, const FString& ColumnType)
{
    FOmegaDataTableColumn NewCol;
    NewCol.Header     = Header;
    NewCol.ColumnType = ColumnType;
    Columns.Add(NewCol);

    // Pad every existing row with an empty cell
    for (FOmegaDataTableRow& Row : Rows)
    {
        Row.Values.Add(TEXT(""));
    }
}

bool UOmegaDataTable::SetColumnHeader(int32 ColumnIndex, const FString& NewHeader)
{
    if (!Columns.IsValidIndex(ColumnIndex)) return false;
    Columns[ColumnIndex].Header = NewHeader;
    return true;
}

bool UOmegaDataTable::SetColumnType(int32 ColumnIndex, const FString& NewType)
{
    if (!Columns.IsValidIndex(ColumnIndex)) return false;
    Columns[ColumnIndex].ColumnType = NewType;
    return true; // Data is unchanged — still raw FString
}

bool UOmegaDataTable::RemoveColumn(int32 ColumnIndex)
{
    if (!Columns.IsValidIndex(ColumnIndex)) return false;

    Columns.RemoveAt(ColumnIndex);

    for (FOmegaDataTableRow& Row : Rows)
    {
        if (Row.Values.IsValidIndex(ColumnIndex))
        {
            Row.Values.RemoveAt(ColumnIndex);
        }
    }
    return true;
}

// ── Row Operations ────────────────────────────────────────────────────────────

void UOmegaDataTable::AddRow()
{
    FOmegaDataTableRow NewRow;
    NewRow.Values.SetNum(Columns.Num()); // empty FStrings by default
    Rows.Add(NewRow);
}

bool UOmegaDataTable::RemoveRow(int32 RowIndex)
{
    if (!Rows.IsValidIndex(RowIndex)) return false;
    Rows.RemoveAt(RowIndex);
    return true;
}

// ── Cell Operations ───────────────────────────────────────────────────────────

bool UOmegaDataTable::SetCellValue(int32 RowIndex, int32 ColumnIndex, const FString& Value)
{
    if (!Rows.IsValidIndex(RowIndex) || !Columns.IsValidIndex(ColumnIndex)) return false;

    FOmegaDataTableRow& Row = Rows[RowIndex];

    // Grow the row's value array if needed (e.g. column was added after row)
    if (!Row.Values.IsValidIndex(ColumnIndex))
    {
        Row.Values.SetNum(ColumnIndex + 1);
    }

    Row.Values[ColumnIndex] = Value;
    return true;
}

bool UOmegaDataTable::GetCellValue(int32 RowIndex, int32 ColumnIndex, FString& OutValue) const
{
    if (!Rows.IsValidIndex(RowIndex) || !Columns.IsValidIndex(ColumnIndex)) return false;

    const FOmegaDataTableRow& Row = Rows[RowIndex];
    OutValue = Row.Values.IsValidIndex(ColumnIndex) ? Row.Values[ColumnIndex] : TEXT("");
    return true;
}

// ── Export ────────────────────────────────────────────────────────────────────

FString UOmegaDataTable::GetCsvString() const
{
    TArray<FString> Lines;
    Lines.Reserve(Rows.Num() + 1);

    // Header row
    {
        TArray<FString> HeaderFields;
        HeaderFields.Reserve(Columns.Num());
        for (const FOmegaDataTableColumn& Col : Columns)
        {
            HeaderFields.Add(EscapeCsvField(Col.Header));
        }
        Lines.Add(FString::Join(HeaderFields, TEXT(",")));
    }

    // Data rows
    for (const FOmegaDataTableRow& Row : Rows)
    {
        TArray<FString> Fields;
        Fields.Reserve(Columns.Num());

        for (int32 i = 0; i < Columns.Num(); ++i)
        {
            const FString CellValue = Row.Values.IsValidIndex(i) ? Row.Values[i] : TEXT("");
            Fields.Add(EscapeCsvField(CellValue));
        }
        Lines.Add(FString::Join(Fields, TEXT(",")));
    }

    return FString::Join(Lines, TEXT("\n"));
}

// ── Private Helpers ───────────────────────────────────────────────────────────

FString UOmegaDataTable::EscapeCsvField(const FString& Field)
{
    // RFC 4180: wrap in quotes if the field contains comma, double-quote, or newline
    const bool bNeedsQuoting = Field.Contains(TEXT(","))
                             || Field.Contains(TEXT("\""))
                             || Field.Contains(TEXT("\n"))
                             || Field.Contains(TEXT("\r"));

    if (!bNeedsQuoting) return Field;

    // Escape existing double-quotes by doubling them
    FString Escaped = Field.Replace(TEXT("\""), TEXT("\"\""));
    return FString::Printf(TEXT("\"%s\""), *Escaped);
}
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OmegaDataTable.generated.h"

/** Wraps a single row's cell values as strings */
USTRUCT(BlueprintType)
struct FOmegaDataTableRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega|DataTable")
    TArray<FString> Values;
};

/** Column metadata */
USTRUCT(BlueprintType)
struct FOmegaDataTableColumn
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega|DataTable")
    FString Header = TEXT("Column");

    /** Purely informational — data is always stored as FString */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega|DataTable")
    FString ColumnType = TEXT("String");
};

/**
 * A generic CSV-style data table asset.
 * All cell data is stored as FString regardless of declared ColumnType,
 * allowing type changes without data loss.
 */
UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaDataTable : public UDataAsset
{
    GENERATED_BODY()

public:

    // ── Schema ────────────────────────────────────────────────────────────

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega|DataTable")
    TArray<FOmegaDataTableColumn> Columns;

    // ── Data ──────────────────────────────────────────────────────────────

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega|DataTable")
    TArray<FOmegaDataTableRow> Rows;

    // ── Column Operations ─────────────────────────────────────────────────

    /** Appends a new column; existing rows get an empty cell appended. */
    UFUNCTION(BlueprintCallable, Category = "Omega|DataTable")
    void AddColumn(const FString& Header, const FString& ColumnType = TEXT("String"));

    /** Renames a column header without touching row data. */
    UFUNCTION(BlueprintCallable, Category = "Omega|DataTable")
    bool SetColumnHeader(int32 ColumnIndex, const FString& NewHeader);

    /** Changes a column's declared type. Row data is untouched. */
    UFUNCTION(BlueprintCallable, Category = "Omega|DataTable")
    bool SetColumnType(int32 ColumnIndex, const FString& NewType);

    /** Removes a column and its cell data from every row. */
    UFUNCTION(BlueprintCallable, Category = "Omega|DataTable")
    bool RemoveColumn(int32 ColumnIndex);

    // ── Row Operations ────────────────────────────────────────────────────

    /** Appends a new empty row (one cell per column). */
    UFUNCTION(BlueprintCallable, Category = "Omega|DataTable")
    void AddRow();

    /** Removes a row by index. */
    UFUNCTION(BlueprintCallable, Category = "Omega|DataTable")
    bool RemoveRow(int32 RowIndex);

    // ── Cell Operations ───────────────────────────────────────────────────

    UFUNCTION(BlueprintCallable, Category = "Omega|DataTable")
    bool SetCellValue(int32 RowIndex, int32 ColumnIndex, const FString& Value);

    UFUNCTION(BlueprintPure, Category = "Omega|DataTable")
    bool GetCellValue(int32 RowIndex, int32 ColumnIndex, FString& OutValue) const;

    // ── Export ────────────────────────────────────────────────────────────

    /**
     * Returns the full table as a CSV string.
     * Row 0 = headers, subsequent rows = data.
     * Values containing commas or quotes are wrapped in double-quotes (RFC 4180).
     */
    UFUNCTION(BlueprintPure, Category = "Omega|DataTable")
    FString GetCsvString() const;

    // ── Helpers ───────────────────────────────────────────────────────────

    UFUNCTION(BlueprintPure, Category = "Omega|DataTable")
    int32 GetColumnCount() const { return Columns.Num(); }

    UFUNCTION(BlueprintPure, Category = "Omega|DataTable")
    int32 GetRowCount() const { return Rows.Num(); }

private:
    /** Wraps a value in quotes if it contains commas, quotes, or newlines (RFC 4180). */
    static FString EscapeCsvField(const FString& Field);
};
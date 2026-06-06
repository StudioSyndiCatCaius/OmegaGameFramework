// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Draw.h"
#include "Engine/Canvas.h"
#include "CanvasItem.h"
#include "GameFramework/HUD.h"
#include "Misc/OmegaGameMode.h"
#include "UObject/UObjectIterator.h"


static UCanvas* GetCanvas(const UObject* WorldContextObject, APlayerController* PC)
{
    if (!PC)
    {
        UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
        if (World)
            PC = World->GetFirstPlayerController();
    }
    if (!PC) return nullptr;
    AOmegaHUD* OmegaHUD = Cast<AOmegaHUD>(PC->GetHUD());
    return OmegaHUD ? OmegaHUD->GetCanvas() : nullptr;
}



// Recursive helper
static void DrawObjectNode(UCanvas* Canvas, UObject* Obj, FVector2D Pos, float IndentX, float LineHeight, float MaxRight, int32 Depth, int32& OutRowCount)
{
    if (!Obj || !Canvas) return;

    // Indent label based on depth
    FString Label = FString::Printf(TEXT("%s [%s]"), *Obj->GetName(), *Obj->GetClass()->GetName());
    float LabelX = Pos.X + (Depth * IndentX);

    // Clamp so it doesn't overflow Size width
    if (LabelX >= MaxRight) return;

    // Draw connector line from parent indent point
    if (Depth > 0)
    {
        float LineX = Pos.X + ((Depth - 1) * IndentX) + (IndentX * 0.5f);
        float NodeY  = Pos.Y + (OutRowCount * LineHeight) + (LineHeight * 0.5f);

        FCanvasLineItem LineItem(FVector2D(LineX, NodeY), FVector2D(LabelX, NodeY));
        LineItem.SetColor(FLinearColor(0.4f, 0.4f, 0.4f, 1.f));
        Canvas->DrawItem(LineItem);
    }

    // Draw label
    FCanvasTextItem TextItem(
        FVector2D(LabelX, Pos.Y + (OutRowCount * LineHeight)),
        FText::FromString(Label),
        GEngine->GetSmallFont(),
        FLinearColor::White
    );
    TextItem.EnableShadow(FLinearColor::Black);
    TextItem.Scale = FVector2D(1.f, 1.f);
    Canvas->DrawItem(TextItem);

    OutRowCount++;

    // Recurse into direct children (one level only per call — ForEachObjectWithOuter is non-recursive here)
    ForEachObjectWithOuter(Obj, [&](UObject* Child)
    {
        DrawObjectNode(Canvas, Child, Pos, IndentX, LineHeight, MaxRight, Depth + 1, OutRowCount);
    }, /*bIncludeNestedObjects=*/false);
}

void UOmegaFunctions_Draw2D::DrawObjectTree(const UObject* WorldContextObject, FVector2D Position, FVector2D Size, UObject* Object, APlayerController* PC)
{
    UCanvas* Canvas = GetCanvas(WorldContextObject, PC);
    if (!Canvas || !Object) return;

    const float LineHeight = 16.f;
    const float IndentX    = 14.f;
    const float MaxRight   = Position.X + Size.X;

    // Optional: background box
    FCanvasTileItem BG(Position, GWhiteTexture, Size, FLinearColor(0.f, 0.f, 0.f, 0.45f));
    BG.BlendMode = SE_BLEND_Translucent;
    Canvas->DrawItem(BG);

    int32 RowCount = 0;
    DrawObjectNode(Canvas, Object, Position + FVector2D(4.f, 4.f), IndentX, LineHeight, MaxRight, 0, RowCount);
}
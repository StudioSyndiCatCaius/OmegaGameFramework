// Copyright (c) W2.Wizard 2020-2021. All Rights Reserved.

#include "Widget/ColorWheel/ColorWheelHelper.h"

uint8 UColorWheelHelper::HexToByte(FString Hex)
{   
    uint8 OutDec;
    
    Hex.StartsWith("#") ? Hex = Hex.Mid(1,Hex.Len()-1) : Hex;
        
    HexToBytes(Hex.ToUpper(), &OutDec);
    return OutDec;
}

FLinearColor UColorWheelHelper::RandomLinearColor(bool RandomAlpha, bool TrueRandom)
{
    FLinearColor OutColor;

    // True random color
    if (TrueRandom)
    {
        OutColor = FLinearColor
        (
            FMath::FRand(),
            FMath::FRand(),
            FMath::FRand(),
            RandomAlpha ? FMath::FRand() : 1
        );

        return OutColor;
    }

    // Simple random color
    OutColor = FLinearColor::MakeRandomColor();
    if (RandomAlpha) OutColor.A = FMath::FRand();
    
    return OutColor;
}

FColor UColorWheelHelper::RandomColor(bool RandomAlpha, bool TrueRandom)
{
    FColor OutColor;

    // True random color
    if (TrueRandom)
    {
        OutColor = FColor
        (
            FMath::RandRange(0,255),
            FMath::RandRange(0,255),
            FMath::RandRange(0,255),
            RandomAlpha ? FMath::Rand() : 1
        );

        return OutColor;
    }

    // Simple random color
    OutColor = FColor::MakeRandomColor();
    if (RandomAlpha) OutColor.A = FMath::Rand();
    
    return OutColor;
}

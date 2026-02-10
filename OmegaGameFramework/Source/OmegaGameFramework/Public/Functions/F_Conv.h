// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Conv.generated.h"

UCLASS()
class UOmegaFunctions_Conv : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Name [Array] -> String [Array]", BlueprintAutocast, Keywords="to, convert"), Category="Omega|Conv")
	static TArray<FString> NameArray_2_StringArray(TArray<FName> In);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "String [Array] -> Name [Array]", BlueprintAutocast, Keywords="to, convert"), Category="Omega|Conv")
	static TArray<FName> StringArray_2_NameArray(TArray<FString> In);
	
	static TMap<FName,float> Vector_2_FloatMap(FName basename, FVector in);
	static TMap<FName,float> Rotator_2_FloatMap(FName basename, FRotator in);
	static TMap<FName,float> Transform_2_FloatMap(FName basename, FTransform in);
	static FVector FloatMap_2_Vector(FName basename, TMap<FName,float> in);
	static FRotator FloatMap_2_Rotator(FName basename, TMap<FName,float> in);
	static FTransform FloatMap_2_Transform(FName basename, TMap<FName,float> in);
};


UCLASS()
class UOmegaFunctions_Punning : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "PUN (int32 > float)", Keywords="to, pun, convert"), Category="Omega|Conv")
	static float int32_2_float(int32 in);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "PUN (int32 > float)", Keywords="to, pun, convert"), Category="Omega|Conv")
	static int32 float_to_int32(float in);
};

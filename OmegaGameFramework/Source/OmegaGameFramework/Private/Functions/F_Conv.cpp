// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Conv.h"

#include <bit>

TArray<FString> UOmegaFunctions_Conv::NameArray_2_StringArray(TArray<FName> In)
{
	TArray<FString> OutArray;
	OutArray.Reserve(In.Num());
	for (const FName& Name : In)
	{
		OutArray.Add(Name.ToString());
	}
	return OutArray;
}

TArray<FName> UOmegaFunctions_Conv::StringArray_2_NameArray(TArray<FString> In)
{
	TArray<FName> OutArray;
	OutArray.Reserve(In.Num());
	for (const FString& String : In)
	{
		OutArray.Add(FName(*String));
	}
	return OutArray;
}

TMap<FName,float> UOmegaFunctions_Conv::Vector_2_FloatMap(FName basename, FVector in)
{
    TMap<FName,float> Result;
    Result.Add(FName(basename.ToString() + ".X"), in.X);
    Result.Add(FName(basename.ToString() + ".Y"), in.Y);
    Result.Add(FName(basename.ToString() + ".Z"), in.Z);
    return Result;
}

TMap<FName,float> UOmegaFunctions_Conv::Rotator_2_FloatMap(FName basename, FRotator in)
{
    TMap<FName,float> Result;
    Result.Add(FName(basename.ToString() + ".Pitch"), in.Pitch);
    Result.Add(FName(basename.ToString() + ".Yaw"), in.Yaw);
    Result.Add(FName(basename.ToString() + ".Roll"), in.Roll);
    return Result;
}

TMap<FName,float> UOmegaFunctions_Conv::Transform_2_FloatMap(FName basename, FTransform in)
{
    TMap<FName,float> Result;
    
    // Location
    Result.Add(FName(basename.ToString() + ".Location.X"), in.GetLocation().X);
    Result.Add(FName(basename.ToString() + ".Location.Y"), in.GetLocation().Y);
    Result.Add(FName(basename.ToString() + ".Location.Z"), in.GetLocation().Z);
    
    // Rotation
    FRotator Rot = in.Rotator();
    Result.Add(FName(basename.ToString() + ".Rotation.Pitch"), Rot.Pitch);
    Result.Add(FName(basename.ToString() + ".Rotation.Yaw"), Rot.Yaw);
    Result.Add(FName(basename.ToString() + ".Rotation.Roll"), Rot.Roll);
    
    // Scale
    Result.Add(FName(basename.ToString() + ".Scale.X"), in.GetScale3D().X);
    Result.Add(FName(basename.ToString() + ".Scale.Y"), in.GetScale3D().Y);
    Result.Add(FName(basename.ToString() + ".Scale.Z"), in.GetScale3D().Z);
    
    return Result;
}

FVector UOmegaFunctions_Conv::FloatMap_2_Vector(FName basename, TMap<FName,float> in)
{
    float X = in.FindRef(FName(basename.ToString() + ".X"));
    float Y = in.FindRef(FName(basename.ToString() + ".Y"));
    float Z = in.FindRef(FName(basename.ToString() + ".Z"));
    return FVector(X, Y, Z);
}

FRotator UOmegaFunctions_Conv::FloatMap_2_Rotator(FName basename, TMap<FName,float> in)
{
    float Pitch = in.FindRef(FName(basename.ToString() + ".Pitch"));
    float Yaw = in.FindRef(FName(basename.ToString() + ".Yaw"));
    float Roll = in.FindRef(FName(basename.ToString() + ".Roll"));
    return FRotator(Pitch, Yaw, Roll);
}

FTransform UOmegaFunctions_Conv::FloatMap_2_Transform(FName basename, TMap<FName,float> in)
{
    // Location
    FVector Location(
        in.FindRef(FName(basename.ToString() + ".Location.X")),
        in.FindRef(FName(basename.ToString() + ".Location.Y")),
        in.FindRef(FName(basename.ToString() + ".Location.Z"))
    );
    
    // Rotation
    FRotator Rotation(
        in.FindRef(FName(basename.ToString() + ".Rotation.Pitch")),
        in.FindRef(FName(basename.ToString() + ".Rotation.Yaw")),
        in.FindRef(FName(basename.ToString() + ".Rotation.Roll"))
    );
    
    // Scale
    FVector Scale(
        in.FindRef(FName(basename.ToString() + ".Scale.X")),
        in.FindRef(FName(basename.ToString() + ".Scale.Y")),
        in.FindRef(FName(basename.ToString() + ".Scale.Z"))
    );
    
    return FTransform(Rotation, Location, Scale);
}

float UOmegaFunctions_Punning::int32_2_float(int32 in)
{
	return std::bit_cast<float>(in);
}

int32 UOmegaFunctions_Punning::float_to_int32(float in)
{
	return std::bit_cast<int32>(in);
}

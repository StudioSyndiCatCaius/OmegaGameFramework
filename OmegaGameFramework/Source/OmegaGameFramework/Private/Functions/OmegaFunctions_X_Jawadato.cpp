// © 2024 jawadato

#include "Functions/OmegaFunctions_X_Jawadato.h"

UNativeFunctionLibraryBPLibrary::UNativeFunctionLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

//SortActorsByDistance
void UNativeFunctionLibraryBPLibrary::SortActorsByDistance(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue) {

    Array.Sort([RelativeTo](const AActor& A, const AActor& B) {
        float DistanceA = A.GetSquaredDistanceTo(RelativeTo);
        float DistanceB = B.GetSquaredDistanceTo(RelativeTo);
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//SortActorsByDistance2D
void UNativeFunctionLibraryBPLibrary::SortActorsByDistance2D(AActor* RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue) {

    Array.Sort([RelativeTo](const AActor& A, const AActor& B) {
        float DistanceA = A.GetHorizontalDistanceTo(RelativeTo);
        float DistanceB = B.GetHorizontalDistanceTo(RelativeTo);
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//SortActorsByLocation
void UNativeFunctionLibraryBPLibrary::SortActorsByLocation(FVector RelativeTo, TArray<AActor*> Array, TArray<AActor*>& ReturnValue) {

    Array.Sort([RelativeTo](const AActor& A, const AActor& B) {
        float DistanceA = (A.GetActorLocation() - RelativeTo).Size();
        float DistanceB = (B.GetActorLocation() - RelativeTo).Size();
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//SortVectorsByDistance
void UNativeFunctionLibraryBPLibrary::SortVectorsByDistance(FVector RelativeTo, TArray<FVector> Array, TArray<FVector>& ReturnValue) {

    Array.Sort([RelativeTo](const FVector& A, const FVector& B) {
        const float DistanceA = FVector::DistSquared(A, RelativeTo);
        const float DistanceB = FVector::DistSquared(B, RelativeTo);
        return DistanceA < DistanceB;
    });
    ReturnValue = Array;
}


//RandomVectorsInExtent
void UNativeFunctionLibraryBPLibrary::RandomVectorsInBoxExtent(int32 Amount, FVector InBoxExtent, FVector Origin, TArray<FVector>& ReturnValue) {

    TArray<FVector> Vectors;
    for (int32 i = 0; i < Amount; ++i)
    {
        FVector Vector;
        Vector.X = FMath::RandRange(-InBoxExtent.X, InBoxExtent.X);
        Vector.Y = FMath::RandRange(-InBoxExtent.Y, InBoxExtent.Y);
        Vector.Z = FMath::RandRange(-InBoxExtent.Z, InBoxExtent.Z);
        Vectors.Add(Vector + Origin);
    }
    ReturnValue = Vectors;
}


//RandomVectorsInExtentFromStream
void UNativeFunctionLibraryBPLibrary::RandomVectorsInBoxExtentFromStream(int32 Amount, FVector InBoxExtent, FVector Origin, FRandomStream Stream, TArray<FVector>& ReturnValue) {

    TArray<FVector> Vectors;
    for (int32 i = 0; i < Amount; ++i)
    {
        FVector Vector;
        Vector.X = Stream.FRandRange(-InBoxExtent.X, InBoxExtent.X);
        Vector.Y = Stream.FRandRange(-InBoxExtent.Y, InBoxExtent.Y);
        Vector.Z = Stream.FRandRange(-InBoxExtent.Z, InBoxExtent.Z);
        Vectors.Add(Vector + Origin);
    }
    ReturnValue = Vectors;
}


//AverageSeparationBetweenVectors
void UNativeFunctionLibraryBPLibrary::AverageSeparationBetweenVectors(TArray<FVector> Array, float& ReturnValue) {

    float TotalDistance = 0.f;
    const int32 NumVectors = Array.Num();
    for (int32 i = 0; i < NumVectors; ++i)
    {
        for (int32 j = i + 1; j < NumVectors; ++j)
        {
            const FVector& VectorI = Array[i];
            const FVector& VectorJ = Array[j];

            const float Distance = FVector::Dist(VectorI, VectorJ);

            TotalDistance += Distance;
        }
    }
    ReturnValue = (TotalDistance / (NumVectors * (NumVectors - 1))) * 2;
}


//NotNearLocations
bool UNativeFunctionLibraryBPLibrary::NotNearLocations(FVector RelativeTo, TArray<FVector> Array, float Radius) {

    bool bNotInRadius = true;
    float CurrentRadius = 0.f;
        for (FVector& Position : Array)
        {
            CurrentRadius = FVector::Dist(Position, RelativeTo);
            if (CurrentRadius <= Radius)
                {
                    bNotInRadius = false;
                    break;
                }                         
        };
    return bNotInRadius;
}


//PutAllRigidBodiesToSleep
void UNativeFunctionLibraryBPLibrary::PutAllRigidBodiesToSleep(USkeletalMeshComponent* Mesh) {

    if(!Mesh)
    {
       return;
    }

        Mesh->PutAllRigidBodiesToSleep();
    
    return;
}


//ClearOnScreenDebugMessages
void UNativeFunctionLibraryBPLibrary::ClearOnScreenDebugMessages() {
    
    GEngine->ClearOnScreenDebugMessages();
}


//LaunchedWithCommandLineArgument
bool UNativeFunctionLibraryBPLibrary::LaunchedWithCommandLineArgument(FString Argument) {

    return FParse::Param(FCommandLine::Get(), *Argument);
}


//StringToClipboard
void UNativeFunctionLibraryBPLibrary::StringToClipboard(const FString& String) {
 
    FPlatformApplicationMisc::ClipboardCopy(*String);
}


//ClipboardToString
FString UNativeFunctionLibraryBPLibrary::ClipboardToString() {
  
    FString String;
    FPlatformApplicationMisc::ClipboardPaste(String);
    return String;
}


//HexToColor
FColor UNativeFunctionLibraryBPLibrary::HexToColor(FString Hex) {
  
    return FColor::FromHex(Hex);
}


//ColorToHex
FString UNativeFunctionLibraryBPLibrary::ColorToHex(FColor Color) {
   
    return Color.ToHex();
}


//StringToFile
bool UNativeFunctionLibraryBPLibrary::StringToFile(FString String, const FString Filename) {

    const TCHAR* FilePath = *Filename;
    return FFileHelper::SaveStringToFile(String, FilePath);
}


//FileToString
bool UNativeFunctionLibraryBPLibrary::FileToString(FString& String, const FString Filename) {

    const TCHAR* FilePath = *Filename;
    return FFileHelper::LoadFileToString(String, FilePath);
}


//FlushInputs
void UNativeFunctionLibraryBPLibrary::FlushInputs(APlayerController* PlayerController) {
  
    PlayerController->FlushPressedKeys();
}


//GetInputHeldDuration
float UNativeFunctionLibraryBPLibrary::GetInputHeldDuration(APlayerController* PlayerController, FKey Key) {
  
    return PlayerController->GetInputKeyTimeDown(Key);
}


//GetHitResultAtScreenPosition
bool UNativeFunctionLibraryBPLibrary::GetHitResultAtScreenPosition(APlayerController* PlayerController, const FVector2D ScreenPosition, const ETraceTypeQuery TraceChannel, bool bTraceComplex, FHitResult& HitResult) {
  
    return PlayerController->GetHitResultAtScreenPosition(ScreenPosition, TraceChannel, bTraceComplex, HitResult);
}


//ClientFadeCamera
void UNativeFunctionLibraryBPLibrary::ClientFadeCamera(APlayerController* PlayerController, bool bFadeAudio, bool bHoldWhenFinished, FLinearColor FadeColor, float FadeAlphaStart, float FadeAlphaStop, float FadeDuration) {

    FColor ConvertedFadeColor = FadeColor.ToFColor(true);
    FVector2D FadeAlpha = FVector2D(FadeAlphaStart, FadeAlphaStop);
    PlayerController->ClientSetCameraFade(true, ConvertedFadeColor, FadeAlpha, FadeDuration, bFadeAudio, bHoldWhenFinished);
}
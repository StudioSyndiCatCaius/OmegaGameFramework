// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Player.h"

#include "Functions/OmegaFunctions_Utility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

FVector UOmegaPlayerFunctions::OffsetScreenPositionToWorld(APlayerController* Player, FVector2D ScreenPosition,
	FVector Offset)
{
	FVector start_pos;
	FVector start_dir;
	UGameplayStatics::DeprojectScreenToWorld(Player,ScreenPosition,start_pos,start_dir);
	return UOmegaMathFunctions::Offset_Vector(start_pos,UKismetMathLibrary::Conv_VectorToRotator(start_dir),Offset);
}

FRotator UOmegaPlayerFunctions::GetRotationFrom2DDirection(APlayerController* Player, FVector2D Start, FVector2D Target,
                                                           FVector Start_Offset, FVector End_Offset)
{
	if(Player)
	{
		FVector loc_start=OffsetScreenPositionToWorld(Player,Start,Start_Offset);
		FVector loc_end=OffsetScreenPositionToWorld(Player,Target,End_Offset);
		return UKismetMathLibrary::FindLookAtRotation(loc_start,loc_end);
	}
	return FRotator();
}

AOmegaPlayer* UOmegaPlayerFunctions::GetOmegaPlayer(UObject* WorldContextObject, int32 Index)
{
	if(WorldContextObject)
	{
		if(AOmegaPlayer* p=Cast<AOmegaPlayer>(UGameplayStatics::GetPlayerController(WorldContextObject,Index)))
		{
			return p;
		}
	}
	return nullptr;
}

TArray<AOmegaPlayer*> UOmegaPlayerFunctions::GetAllOmegaPlayers(UObject* WorldContextObject)
{
	TArray<AOmegaPlayer*> out;
	for (int i = 0; i < UGameplayStatics::GetNumPlayerControllers(WorldContextObject); ++i)
	{
		if(AOmegaPlayer* p=GetOmegaPlayer(WorldContextObject,i))
		{
			out.Add(p);
		}
	}
	return out;
}

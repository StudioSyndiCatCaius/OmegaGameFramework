// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Actors/Actor_Gameplay.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "OmegaSettings.h"
#include "Components/BillboardComponent.h"
#include "Misc/OmegaUtils_Macros.h"

AOmegaGameplayActor::AOmegaGameplayActor()
{
	RootBillboard=CreateOptionalDefaultSubobject<UBillboardComponent>("ROOT");
	RootComponent=RootBillboard;
}

void AOmegaGameplayActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void AOmegaGameplayActor::BeginPlay()
{
	lua_value=ULuaBlueprintFunctionLibrary::LuaRunString(this,nullptr,Script.LuaCode);
	Super::BeginPlay();
}

FLuaValue AOmegaGameplayActor::GetValue_Implementation(const FString& Field)
{
	return lua_value;
}

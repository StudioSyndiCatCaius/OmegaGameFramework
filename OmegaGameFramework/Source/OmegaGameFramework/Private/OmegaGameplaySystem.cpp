// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameplaySystem.h"

#include "OmegaGameFrameworkBPLibrary.h"

#include "OmegaGameplaySubsystem.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Player/OmegaPlayerSubsystem.h"




// Sets default values
AOmegaGameplaySystem::AOmegaGameplaySystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
	
}

// Called when the game starts or when spawned
void AOmegaGameplaySystem::BeginPlay()
{
	Super::BeginPlay();
	
	///ATTACH TO GAME MODE
	//SetOwner(UGameplayStatics::GetGameMode(this));
	//AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
	
	//Get Players
	TArray <AActor*> FoundPlayers;
	UGameplayStatics::GetAllActorsOfClass(this, APlayerController::StaticClass(), FoundPlayers);


	
	for (AActor* TempActor : FoundPlayers)
	{
		
		const APlayerController* TempPlayer = Cast<APlayerController>(TempActor);
		
		//Add New Widgets To Player Screen
		for (class TSubclassOf <UHUDLayer> TempWidgetClass : AddedPlayerWidgets)
		{
			UOmegaPlayerSubsystem* LocalSystem = TempPlayer->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
			UHUDLayer* CreatedLayer = LocalSystem->AddHUDLayer(TempWidgetClass, this, 0);
			ActivePlayerWidgets.Add(CreatedLayer);
		}
		// Add New Mapping Context
		for(UInputMappingContext* TempMap : AddPlayerInputMapping)
		{
			Cast<APlayerController>(TempActor)->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()->AddMappingContext(TempMap, 0);
		}
	}

	//Setup Game Preferences
	/*
	UGamePreferenceSubsystem* GamePrefSystemRef = GEngine->GetWorld()->GetSubsystem<UGamePreferenceSubsystem>();
	GamePrefSystemRef->OnBoolPreferenceUpdated.AddDynamic(this, &AOmegaGameplaySystem::GamePreferenceUpdatedBool);
	GamePrefSystemRef->OnFloatPreferenceUpdated.AddDynamic(this, &AOmegaGameplaySystem::GamePreferenceUpdatedFloat);
	SubsysRef = GEngine->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	*/
	
	
}

// Called every frame
void AOmegaGameplaySystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOmegaGameplaySystem::Shutdown(FString Flag)
{
	TArray <AActor*> FoundPlayers;
	UGameplayStatics::GetAllActorsOfClass(this, APlayerController::StaticClass(), FoundPlayers);
	
	// Remove Player Widgets
	for (class UHUDLayer* TempWidget : ActivePlayerWidgets)
	{
		TempWidget->RemoveFromParent();
	}
	OnSystemShutdown.Broadcast(Flag);
	SystemShutdown(Flag);
	if (SubsysRef)
	{
		SubsysRef->NativeRemoveSystem(this);
	}

	//Remove Mapping Context
	for (AActor* TempActor : FoundPlayers)
	{
		for(UInputMappingContext* TempMap : AddPlayerInputMapping)
		{
			Cast<APlayerController>(TempActor)->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()->RemoveMappingContext(TempMap);
		}
	}

	K2_DestroyActor();
}
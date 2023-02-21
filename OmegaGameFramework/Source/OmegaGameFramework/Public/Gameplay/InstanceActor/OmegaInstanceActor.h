// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "GameFramework/Actor.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "OmegaInstanceActor.generated.h"

class UInstanceActorComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaInstanceActor : public AActor, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaInstanceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category="InstanceActor")
	void OnInstanceCreated(UObject* Context, const FString& Flag);
	
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor", VisibleInstanceOnly)
	UObject* ContextObject = nullptr;
	UPROPERTY(BlueprintReadOnly, Category="InstanceActor")
	UInstanceActorComponent* OwningComponent;

	// INTERFACES
	bool Local_SourceHasInterface() const;
	
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;

	//NOTIFY
	UFUNCTION(BlueprintCallable, Category="InstanceActor")
	void TriggerNotify(FName Notify);
};

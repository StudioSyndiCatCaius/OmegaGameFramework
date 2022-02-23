// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameplayTagContainer.h"
#include "VolumeUtils.h"
#include "DamageFormula.h"

#include "OmegaGameplayEffect.generated.h"


UENUM()
enum class EEffectLifetime : uint8

{
	/** Description. */
	EffectLifetime_Instant        UMETA(DisplayName = "Instant"),
	/** Description. */
	EffectLifetime_Timer        UMETA(DisplayName = "Timer"),
	/** Description. */
	EffectLifetime_OnTrigger        UMETA(DisplayName = "OnTrigger"),

};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOmegaGameplayEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
		void EffectApplied();

	UFUNCTION(BlueprintCallable, Category = "Ω|Gameplay|Effects")
		void TriggerEffect();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
		void EffectBeginPlay(class UCombatantComponent* EffectInstigator, class AActor* TargetedActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ω|Gameplay|Effects")
		void LifetimeUpdated(float TimeElapsed, float TimeRemaining);

	UPROPERTY()
	class UCombatantComponent* CombatantInstigator;

	UPROPERTY(BlueprintReadOnly, Category = "General")
	class AActor* TargetActor;

	//-----VOLUME-----//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Volume")
		bool bUseVolume = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Volume")
	EVolumeShape VolumeShape;

	//-----Life-----//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime")
		EEffectLifetime EffectLifetime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifetime")
		float Lifetime = 1.0;

	UFUNCTION()
	void LifetimeEnd();

	//-----Damage-----//
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<UDamageFormula> DamageFormula = UDamageFormula::StaticClass();

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "Damage")
		float Power;

	UFUNCTION(BlueprintPure, Category = "Ω|Gameplay|Effects")
		void CalculateDamageValue(float Multiplier, class UObject* DamageInstigator, class UObject* DamageTarget, float& Damage);

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
		class UDamageFormula* LocalFormula;

	//-----Tags-----//
	UPROPERTY(EditAnywhere, Category = "Tags")
		FGameplayTagContainer EffectTags;

	FTimerHandle LifetimeTimer;

	float PastLifetime;
	float RemainingLifetime;

private:


};

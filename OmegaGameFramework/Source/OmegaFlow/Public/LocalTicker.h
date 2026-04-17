#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Tickable.h"
#include "LocalTicker.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnLocalTickerTick,
	float,          DeltaTime,
	ULocalTicker*,  Ticker
);

UCLASS()
class OMEGAFLOW_API ULocalTicker : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:

	// ── Output pin ────────────────────────────────────────────────────────────
	UPROPERTY(BlueprintAssignable)
	FOnLocalTickerTick OnTick;

	// ── Async-action factory node ─────────────────────────────────────────────
	UFUNCTION(BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"),
		Category = "Utilities|Tick")
	static ULocalTicker* LocalTicker(UObject* WorldContextObject);

	// ── Public API ────────────────────────────────────────────────────────────
	/** Stops broadcasting OnTick and marks the task ready for GC. */
	UFUNCTION(BlueprintCallable, Category = "Utilities|Tick")
	void KillTask();

	// ── UBlueprintAsyncActionBase ─────────────────────────────────────────────
	virtual void Activate() override;

	// ── FTickableGameObject ───────────────────────────────────────────────────
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables );
	}


private:
	bool bActive = false;
};
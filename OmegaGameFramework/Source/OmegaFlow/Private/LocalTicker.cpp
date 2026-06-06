#include "LocalTicker.h"

/* static */
ULocalTicker* ULocalTicker::LocalTicker(UObject* WorldContextObject)
{
	// NewObject with the outer keeps the task alive until we decide to destroy it.
	return NewObject<ULocalTicker>(WorldContextObject);
}

void ULocalTicker::Activate()
{
	bActive = true;
}

void ULocalTicker::KillTask()
{
	if (!bActive)
	{
		return;
	}

	bActive = false;

	// Tell the async-action system it can release its reference.
	SetReadyToDestroy();
}

// ── FTickableGameObject ───────────────────────────────────────────────────────

void ULocalTicker::Tick(float DeltaTime)
{
	if (bActive)
	{
		OnTick.Broadcast(DeltaTime, this);
	}
}

bool ULocalTicker::IsTickable() const
{
	// Never tick CDO, never tick after KillTask.
	return !HasAnyFlags(RF_ClassDefaultObject) && bActive && IsValid(this);
}


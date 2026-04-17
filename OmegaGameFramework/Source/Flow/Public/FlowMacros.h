#pragma once

#include "CoreMinimal.h"


#define FLOW_SETUP_PINS_OUTPUT_BOOL() \
OutputPins.Empty(); \
FFlowPin pin_true = FFlowPin(TEXT("true")); \
pin_true.PinFriendlyName = FText::FromString(TEXT("\u2714\uFE0F")); \
FFlowPin pin_false = FFlowPin(TEXT("false")); \
pin_false.PinFriendlyName = FText::FromString(TEXT("\u274C")); \
OutputPins.Add(pin_true); \
OutputPins.Add(pin_false);
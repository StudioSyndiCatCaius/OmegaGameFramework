// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Types/Struct_Bitflag.h"

#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"

FOmegaBitmaskEditorData FOmegaBitflagsBase::GetConfig(UClass* OuterObject)
{
	if (UObject* o= override_source.Get())
	{
		return *OGF_CFG()->GetEditorDataForClass(o->GetClass());
	}
	if (override_config)
	{
		return override_configData;
	}
	if (const FOmegaBitmaskEditorData* d= OGF_CFG()->GetEditorDataForClass(OuterObject))
	{
		return *d;
	}
	return FOmegaBitmaskEditorData();
}

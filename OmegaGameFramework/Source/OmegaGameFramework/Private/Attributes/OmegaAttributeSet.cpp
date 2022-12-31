// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Attributes/OmegaAttributeSet.h"

#include "OmegaAttribute.h"

TArray<UOmegaAttribute*> UOmegaAttributeSet::GetMetricAttributes()
{
	return Local_GetAtt(false);
}

TArray<UOmegaAttribute*> UOmegaAttributeSet::GetStaticAttributes()
{
	return Local_GetAtt(true);
}

TArray<UOmegaAttribute*> UOmegaAttributeSet::Local_GetAtt(bool bStatic)
{
	TArray<UOmegaAttribute*> OutAtts;
	for(auto* TempAtt: Attributes)
	{
		if(TempAtt && (TempAtt->bIsValueStatic == bStatic))
		{
			OutAtts.Add(TempAtt);
		}
	}
	return OutAtts;
}

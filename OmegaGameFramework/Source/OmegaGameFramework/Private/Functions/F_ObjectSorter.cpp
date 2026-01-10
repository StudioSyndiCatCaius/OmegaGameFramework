// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_ObjectSorter.h"

TArray<UObject*> UOmegaObjectSorterClass::FilterObjects_Implementation(const TArray<UObject*>& InObjects,
                                                                       UObject* Context)
{
	TArray<UObject*> OutObjects = InObjects;
	return OutObjects;
}


TArray<UObject*> UOmegaObjectSorterFunctions::SortObjectArray(TArray<UObject*> InObjects,
	UOmegaObjectSorterAsset* Sorter, TSubclassOf<UObject> OutputClass,  UObject* Context)
{
	TArray<UObject*> SortedArray;

	if(Sorter && Sorter->SorterScript)
	{
		// Create a copy of the input array to keep the original intact
		SortedArray = Sorter->SorterScript->FilterObjects(InObjects,Context);

		// Sort the array using the ShouldCheckedObjectSortFirst function as a comparison
		SortedArray.Sort([&](UObject& A, UObject& B)
		{
			return Sorter->SorterScript->ShouldCheckedObjectSortFirst(&A,&B,Context);
		});
	}
	
	return SortedArray;
}

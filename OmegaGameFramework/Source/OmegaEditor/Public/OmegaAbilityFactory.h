// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/BlueprintFactory.h"
#include "AssetTypeActions_Base.h"
#include "OmegaAbilityFactory.generated.h"



UCLASS()
class OMEGAEDITOR_API UOmegaAbilityFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	/*
	UOmegaAbilityFactory();

	 Creates the asset inside the UE4 Editor 
	virtual UObject* FactoryCreateNew
	(
		UClass* InClass,
		UObject* InParent,
		FName InName,
		EObjectFlags Flags,
		UObject* Context,
		FFeedbackContext* Warn,
		FName CallingContext
	) override;
	*/

};
/*
class OMEGAEDITOR_API FOmegaAssetTypeActions : public FAssetTypeActions_Base
{
public:
	FOmegaAssetTypeActions(uint32 InAssetCategory);

	// FAssetTypeActions_Base
	virtual uint32 GetCategories() override;
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	uint32 MyAssetCategory;
	// ~FAssetTypeActions_Base

};
*/
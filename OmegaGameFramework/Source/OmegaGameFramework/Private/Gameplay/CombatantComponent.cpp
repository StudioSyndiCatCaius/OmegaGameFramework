// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Gameplay/CombatantComponent.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "OmegaAbility.h"
#include "OmegaGameplayEffect.h"
#include "OmegaGameplaySubsystem.h"
#include "Widget/WidgetInterface_Combatant.h"
#include "Attributes/OmegaAttributeSet.h"
#include "Gameplay/OmegaDamageType.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"

#include "Gameplay/ActorInterface_Combatant.h"
#include "Gameplay/DataInterface_Combatant.h"
#include "Gameplay/DataInterface_DamageModifier.h"
#include "Gameplay/Combatant/CombatantTargetIndicator.h"
#include "Gameplay/Combatant/OmegaFaction.h"
#include "Kismet/KismetTextLibrary.h"


// Sets default values for this component's properties
UCombatantComponent::UCombatantComponent()
{
	
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatantComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
	//AddToCombatantList
	GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->Native_RegisterCombatant(this, true);
	///---Try Setup Input---//
	OwnerPawn = Cast<APawn>(GetOwner());
	//Grant StarterAbilities
	for(const TSubclassOf<AOmegaAbility> TempAbClass : GrantedAbilities)
	{
		GrantAbility(TempAbClass);
	}

	if(TargetIndicatorClass)
	{
		
		TargetIndicator = GetWorld()->SpawnActorDeferred<ACombatantTargetIndicator>(TargetIndicatorClass, GetOwner()->GetTransform(), nullptr);
		TargetIndicator->CombatantOwner = this;
		
	
		UGameplayStatics::FinishSpawningActor(TargetIndicator, GetOwner()->GetTransform());
		TargetIndicator->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));

	}
	
	InitializeAttributes();
}

void UCombatantComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason == EEndPlayReason::Destroyed || EndPlayReason == EEndPlayReason::RemovedFromWorld)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->Native_RegisterCombatant(this, false);
	}
	
	
	Super::EndPlay(EndPlayReason);
	for(AOmegaAbility* TempAb : AbilityList)
	{
		TempAb->K2_DestroyActor();
	}
}

// Called every frame
void UCombatantComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCombatantComponent::SetMasterDataSourceActive(UObject* Source, bool bActive)
{
	SetSkillSourceActive(Source, bActive);
	SetAttributeModifierActive(Source, bActive);
	SetDamageModifierActive(Source, bActive);
}

void UCombatantComponent::SetAbilityActive(bool bActive, AOmegaAbility* Ability)
{
	if(bActive)
	{
		ActiveAbilities.Add(Ability);
	}
	else if(ActiveAbilities.Contains(Ability))
	{
		ActiveAbilities.Remove(Ability);
	}
}

////////////////////////////////////
////////// -- TAGS -- //////////
///////////////////////////////////
void UCombatantComponent::AddTagsToCombatant(FGameplayTagContainer Tags)
{
	CombatantTags.AppendTags(Tags);
}

void UCombatantComponent::RemoveTagsFromCombatant(FGameplayTagContainer Tags)
{
		CombatantTags.RemoveTags(Tags);
}

FGameplayTagContainer UCombatantComponent::GetCombatantTags()
{
	return CombatantTags;
}

bool UCombatantComponent::CombatantHasTag(FGameplayTag Tag)
{
	return CombatantTags.HasTag(Tag);
}

bool UCombatantComponent::CombatantHasAnyTag(FGameplayTagContainer Tags, bool Exact)
{
	if (Exact)
	{
		return CombatantTags.HasAnyExact(Tags);
	}
	else
	{
		return CombatantTags.HasAny(Tags);
	}
}

bool UCombatantComponent::CombatantHasAllTag(FGameplayTagContainer Tags, bool Exact)
{
	if(Exact)
	{
		return CombatantTags.HasAllExact(Tags);
	}
	else
	{
		return CombatantTags.HasAll(Tags);
	}
}


////////////////////////////////////
////////// -- UPDATE DATA -- //////////
///////////////////////////////////
void UCombatantComponent::Update()
{
	//Update Widgets
	TArray<UUserWidget*> FoundWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsWithInterface(this, FoundWidgets, UWidgetInterface_Combatant::StaticClass(), false);
	for (UUserWidget* TempWidget : FoundWidgets)
	{
		if (IWidgetInterface_Combatant::Execute_GetCombatantComponent(TempWidget) == this&&AttributeSet)
		{

			IWidgetInterface_Combatant::Execute_OnCombatantUpdated(TempWidget, this);
			
			//Set Attribute Texts
			//GEngine->AddOnScreenDebugMessage(-1, 3.0F, FColor::Green, "ReachWidget");
			//IWidgetInterface_Combatant::Execute_GetAttributeTexts(TempWidget)
			for (UOmegaAttribute* LocalAtb : AttributeSet->Attributes)
			{
				float DumVal;
				float DumMax;
				GetAttributeValue(LocalAtb, DumVal, DumMax);

				UTextBlock* ValText;
				UTextBlock* MaxText;
				IWidgetInterface_Combatant::Execute_GetAttributeTexts(TempWidget, LocalAtb, ValText, MaxText);
				//Set Max Value Text
				if (MaxText)
				{
					FText LocalText_Val = UKismetTextLibrary::Conv_FloatToText
					(
						DumMax,
						LocalAtb->RoundingMode,
						LocalAtb->bAlwaysSign,
						LocalAtb->bUseGrouping,
						LocalAtb->MinIntegralDigits,
						LocalAtb->MaxIntegralDigits,
						LocalAtb->MinFractionalDigits,
						LocalAtb->MaxFractionalDigits
						);
					
					MaxText->SetText(LocalText_Val);
				}
				//Set Current Value Text
				if (ValText)
				{
					FText LocalText_Val = UKismetTextLibrary::Conv_FloatToText
					(
						DumVal,
						LocalAtb->RoundingMode,
						LocalAtb->bAlwaysSign,
						LocalAtb->bUseGrouping,
						LocalAtb->MinIntegralDigits,
						LocalAtb->MaxIntegralDigits,
						LocalAtb->MinFractionalDigits,
						LocalAtb->MaxFractionalDigits
						);
					
					ValText->SetText(LocalText_Val);
				}

				class UProgressBar* AttProg;
				bool bLocal_BarToColor;
				IWidgetInterface_Combatant::Execute_GetAttributeProgressBar(TempWidget, LocalAtb, AttProg, bLocal_BarToColor);
				if (AttProg)
				{
					AttProg->SetPercent(GetAttributePercentage(LocalAtb));
					if(bLocal_BarToColor)
					{
						AttProg->SetFillColorAndOpacity(LocalAtb->AttributeColor);
					}
				}
				
			}
		}
	} //Widget Update END
}

APawn* UCombatantComponent::GetOwnerPawn()
{
	if(Cast<APawn>(GetOwner()))
	{
		return Cast<APawn>(GetOwner());
	}
	else
	{
		return nullptr;
	}
}

ACharacter* UCombatantComponent::GetOwnerCharacter()
{
	if(Cast<ACharacter>(GetOwner()))
	{
		return Cast<ACharacter>(GetOwner());
	}
	else
	{
		return nullptr;
	}
}


AController* UCombatantComponent::GetOwnerController()
{
	if(GetOwnerPawn() && GetOwnerPawn()->GetController())
	{
		return GetOwnerPawn()->GetController();
	}
	else if(Cast<AController>(GetOwner()))
	{
		return Cast<AController>(GetOwner());
	}
	else
	{
		return nullptr;
	}
}

APlayerController* UCombatantComponent::GetOwnerPlayerController()
{
	if(GetOwnerPawn() && Cast<APlayerController>(GetOwnerPawn()->GetController()))
	{
		return Cast<APlayerController>(GetOwnerPawn()->GetController());
	}
	
	else if(Cast<APlayerController>(GetOwner()))
	{
		return Cast<APlayerController>(GetOwner());
	}
	
	else
	{
		return nullptr;
	}
}


//--------------------------//
//General Overrides
//--------------------------//
void UCombatantComponent::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	if(CombatantDataAssetIsValidData())
	{
		IDataInterface_General::Execute_GetGeneralDataText(CombatantDataAsset, Label, Context, Name, Description);
	}
	else
	{
		Name = DisplayName;
		Description = CombatantDescription;
	}
}

void UCombatantComponent::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	
	//IDataInterface_General::GetGeneralAssetColor_Implementation(Color);
}

void UCombatantComponent::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
                                                              UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(CombatantDataAssetIsValidData())
	{
		IDataInterface_General::Execute_GetGeneralDataImages(CombatantDataAsset, Label, Context, Texture, Material, Brush);
	}
	else
	{
		Brush = CombatantIcon;
	}
	//IDataInterface_General::GetGeneralDataImages_Implementation(Label, Context, Texture, Material, Brush);
}

/////GRANT ABILITY
	///
bool UCombatantComponent::GrantAbility(TSubclassOf<AOmegaAbility> AbilityClass)
{
	if(!AbilityClass)
	{
		return false;
	}
	bool bTempSuccess;
	if(!GetAbility(AbilityClass, bTempSuccess))
	{
		AOmegaAbility* LocalAbility = nullptr;
		const FTransform SpawnWorldPoint;
		//Spawn Ability
		LocalAbility = GetWorld()->SpawnActorDeferred<AOmegaAbility>(AbilityClass, SpawnWorldPoint, nullptr);
		LocalAbility->CombatantOwner = this;
		
		if (Cast<ACharacter>(GetOwner()))
		{
			LocalAbility->CachedCharacter = Cast<ACharacter>(GetOwner());
		}
		if (Cast<APawn>(GetOwner()))
		{
			LocalAbility->SetInstigator(Cast<APawn>(GetOwner()));
		}
		
		UGameplayStatics::FinishSpawningActor(LocalAbility, SpawnWorldPoint);
		LocalAbility->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
		//Add to AbilitiesList
		AbilityList.Add(LocalAbility);
		return true;
	}
	return false;
}

	/////UNGRANT ABILITY
	///
bool UCombatantComponent::UngrantAbility(TSubclassOf<AOmegaAbility> AbilityClass)
{
	bool bTempSuccess;
	if(!AbilityClass)
	{
		return false;
	}
	if(GetAbility(AbilityClass, bTempSuccess))
	{
		if(!bTempSuccess)
		{
			return false;
		}
		StopAbility(AbilityClass, true);
		AOmegaAbility* AbilityRef = GetAbility(AbilityClass, bTempSuccess);
		AbilityList.Remove(AbilityRef);
		AbilityRef->K2_DestroyActor();
		return true;
	}
	return false;
}

AOmegaAbility* UCombatantComponent::GetAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool& bSuccess)
{
	bSuccess = false;
	for(AOmegaAbility* TempAb : AbilityList)
	{
		if(TempAb->GetClass() == AbilityClass)
		{
			bSuccess = true;
			return TempAb;
		}
	}
	return nullptr;
}

////////////////////////////////////
////////// -- ABILITIES -- //////////
///////////////////////////////////
AOmegaAbility* UCombatantComponent::ExecuteAbility(TSubclassOf<AOmegaAbility> AbilityClass, class UObject* Context, bool& bSuccess)
{
	bool bIsAbilityActive;
	if (AbilityClass&&!IsAbilityTagBlocked(AbilityClass.GetDefaultObject()->AbilityTags)&&GetAbility(AbilityClass, bIsAbilityActive))
	{
		AOmegaAbility* LocalAbility = nullptr;
		LocalAbility = GetAbility(AbilityClass, bIsAbilityActive);		//Set Local Ability if possible
		if(LocalAbility&&!IsAbilityActive(AbilityClass, LocalAbility))
		{
			LocalAbility->ContextObject = Context;
			LocalAbility->Native_Execute();
		}
		/*else
		{
			//If Ability is already spawned, run "Activated" again.
			IsAbilityActive(AbilityClass, LocalAbility);
			if (!LocalAbility->bIsKilling)
			{
				LocalAbility->AbilityTriggered(Context);
			}
			
		}*/
		bSuccess = true;
		return LocalAbility;
	}
	else
	{
		bSuccess = false;
		return nullptr;
	}
	
}

bool UCombatantComponent::IsAbilityActive(class TSubclassOf<AOmegaAbility> AbilityClass, class AOmegaAbility*& Ability)
{
	bool bIsFound = false;
	for (AOmegaAbility* TempAbility : ActiveAbilities)
	{
		if (!bIsFound)
		{
			if (AbilityClass == TempAbility->GetClass())
			{
				Ability = TempAbility;
				bIsFound = true;
			}
		}
	}
	return bIsFound;
}

bool UCombatantComponent::StopAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool Cancel)
{
	for (AOmegaAbility* TempAbility : ActiveAbilities)	//Check if ability is actually active
	{
		if(TempAbility)
		{
			if (AbilityClass == TempAbility->GetClass())
			{
				if(Cancel)
				{
					TempAbility->CancelAbility();
				}
				else
				{
					TempAbility->CompleteAbility();
				}
			}
		}
	}
	return false;
}

TArray<AOmegaAbility*> UCombatantComponent::GetActiveAbilities()
{
	return ActiveAbilities;
}

TArray<AOmegaAbility*> UCombatantComponent::GetActiveAbilitiesWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaAbility*> FoundAbilities;
	for (AOmegaAbility* TempAbility : ActiveAbilities)
	{
		if(TempAbility->IsValidLowLevel())
		{
			if (TempAbility->AbilityTags.HasAnyExact(Tags))
			{
				FoundAbilities.Add(TempAbility);
			}
		}
		
	}
	return FoundAbilities;
}

TArray<AOmegaAbility*> UCombatantComponent::GetGrantedAbilities()
{
	TArray<AOmegaAbility*> FoundAbilities;

	for(auto* TempAbility : AbilityList)
	{
		if(TempAbility)
		{
			FoundAbilities.Add(TempAbility);
		}
	}
	
	return FoundAbilities;
}

TArray<AOmegaAbility*> UCombatantComponent::GetGrantedAbilitiesWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaAbility*> FoundAbilities;
	
	for(auto* TempAbility : GetGrantedAbilities())
	{
		if(TempAbility && TempAbility->AbilityTags.HasAnyExact(Tags))
		{
			FoundAbilities.Add(TempAbility);
		}
	}

	return FoundAbilities;
}

////////////////////////////////////
	////////// -- ATTRIBUTES -- //////////
	///////////////////////////////////
float UCombatantComponent::ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UCombatantComponent* Instigator, UObject* Context, UOmegaDamageType* DamageType, FHitResult Hit)
{
	
	if(!bCanDamageAttributes)
	{
		return 0;
	}
	float CurrentValue;
	float MaxVal;

	// INIT Contextual Values
	UOmegaDamageType* LocalDamageType = nullptr;
	if(DamageType)
	{
		LocalDamageType = DamageType;
	}
	
	UObject* LocalContext = nullptr;
	if(Context)
	{
		LocalContext = Context;
	}

	
	GetAttributeValue(Attribute, CurrentValue, MaxVal);		//Set correct attribute values
	float FinalDamage = BaseDamage;
	
	for(auto* TempMod : GetDamageModifiers())		//Is there a valid damage modifier
	{
		FinalDamage = IDataInterface_DamageModifier::Execute_ModifyDamage(TempMod, Attribute, this, Instigator, BaseDamage, LocalDamageType, Context); //Apply Damage Modifier
	}
	
	//Damage Type modification
	if(LocalDamageType && LocalDamageType->DamageScript)
	{
		FinalDamage = LocalDamageType->DamageScript->OnDamageApplied(FinalDamage);
	}
	
	CurrentValue = CurrentValue - FinalDamage;		//Deduct final damage value from current attribute value
	CurrentValue = FMath::Clamp(CurrentValue, 0.0f, MaxVal);		//Make sure the value does not go under 0 or exceed the max allowed value

	//FINALIZE
	CurrentAttributeValues.Add(Attribute, CurrentValue);
	OnDamaged.Broadcast(this, Attribute, FinalDamage, Instigator, LocalDamageType, Hit);
	Update();
	return FinalDamage;
}

void UCombatantComponent::CancelAbilitiesWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaAbility*> AbilitiesToCancel = GetActiveAbilitiesWithTags(Tags);
	for (AOmegaAbility* TempAbility : AbilitiesToCancel)
	{
		TempAbility->CancelAbility();
	}
}

void UCombatantComponent::CancelAllAbilities()
{
	for(auto* TempAb : GetActiveAbilities())
	{
		TempAb->CancelAbility();
	}
}

int32 UCombatantComponent::GetAttributeLevel(UOmegaAttribute* Attribute)
{
	if(!Attribute)
	{
		return 0;
	}
	return AttributeLevels.FindOrAdd(Attribute);
}

//////////////////
/// Skills //////
////////////////
TArray<UPrimaryDataAsset*> UCombatantComponent::GetAllSkills()
{
	TArray<UPrimaryDataAsset*> OutSkills = Skills;
	for(auto* TempSource : Local_GetSkillSources())
	{
		for(auto* TempSkill : IDataInterface_SkillSource::Execute_GetSkills(TempSource))
		{
			if(TempSkill)
			{
				OutSkills.Add(TempSkill);
			}
		}
	}
	return OutSkills;
}

void UCombatantComponent::AddSkill(UPrimaryDataAsset* Skill)
{
	Skills.Add(Skill);
}

void UCombatantComponent::RemoveSkill(UPrimaryDataAsset* Skill)
{
	Skills.Remove(Skill);
}

bool UCombatantComponent::SetSkillSourceActive(UObject* SkillSource, bool bActive)
{
	if(!SkillSource )
	{
		return false;
	}
	if(SkillSource->Implements<UDataInterface_SkillSource>())
	{
		if(bActive)
		{
			Local_SkillSources.AddUnique(SkillSource);
		}
		else
		{
			Local_SkillSources.Remove(SkillSource);
		}
	}
	return true;
}


bool UCombatantComponent::SetDamageModifierActive(UObject* Modifier, bool bActive)
{
	if(!Modifier)
	{
		return false;
	}
	if(Modifier->Implements<UDataInterface_DamageModifier>())
	{
		if(bActive)
		{
			DamageModifiers.Add(Modifier);
		}
		else
		{
			DamageModifiers.Remove(Modifier);
		}
	}
	return false;
}

TArray<UObject*> UCombatantComponent::GetDamageModifiers()
{
	TArray<UObject*> OutMods;
	for(auto* TempMod : DamageModifiers)
	{
		if(TempMod && TempMod->Implements<UDataInterface_DamageModifier>())
		{
			OutMods.Add(TempMod);
		}
	}
	return OutMods;
}

//// Get Attribute Values + Attribute Modifiers
void UCombatantComponent::GetAttributeValue(UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue)
{
	//Get base value
	float BaseValue = GetAttributeBaseValue(Attribute);
	
	//Gather All modifiers and apply them to final damage.
	BaseValue = GatherAttributeModifiers(GetAttributeModifiers(),BaseValue, Attribute);
	
	MaxValue  = BaseValue;
	//Get Current Value
	if (Attribute->bIsValueStatic)
	{
		CurrentValue = MaxValue;
	}
	else
	{
		CurrentValue = CurrentAttributeValues.FindOrAdd(Attribute);
	}
}

//Get Attribute Base Value
float UCombatantComponent::GetAttributeBaseValue(UOmegaAttribute* Attribute)
{
	return Attribute->GetAttributeValue(Level, GetAttributeLevel(Attribute), AttributeValueCategory);
}

bool UCombatantComponent::IsAbilityTagBlocked(FGameplayTagContainer Tags)
{
	for (AOmegaAbility* TempAbility : ActiveAbilities)
	{
		if(TempAbility)
		{
			if (TempAbility->BlockAbilities.HasAnyExact(Tags))
			{
				return true;
			}
		}
	}
	return false;
}

void UCombatantComponent::InitializeFromAsset(UObject* Asset)
{
	if(Asset && Asset->Implements<UDataInterface_Combatant>())
	{
		
	}
}

float UCombatantComponent::GetAttributePercentage(UOmegaAttribute* Attribute)
{
	float CurVal;
	float MaxVal;
	GetAttributeValue(Attribute, CurVal, MaxVal);
	float OutVal = CurVal / MaxVal;
	return OutVal;
}

TMap<UOmegaAttribute*, float> UCombatantComponent::GetCurrentAttributeValues()
{
	return CurrentAttributeValues;
}

void UCombatantComponent::SetCurrentAttributeValues(TMap<UOmegaAttribute*, float> Values)
{
	CurrentAttributeValues = Values;
	Update();
}

void UCombatantComponent::SetCombatantLevel(int32 NewLevel, bool ReinitializeStats)
{
	Level = NewLevel;
	OnLevelChanged.Broadcast(NewLevel);
	if(ReinitializeStats)
	{
		InitializeAttributes();
	}
}

/// INITIALIZE ATTRIBUTES
void UCombatantComponent::InitializeAttributes()
{
	//Initialize Attributes from Set
	if (AttributeSet)
	{
		float CurrentVal = 0.0f;
		float DumVal = 0.0f;
		for (UOmegaAttribute* TempAtt : AttributeSet->Attributes)
		{
			if (AttributeLevels.Contains(TempAtt))
			{
				int32 DumRank = 0;
				DumRank = AttributeLevels[TempAtt];
			}
			GetAttributeValue(TempAtt, CurrentVal, DumVal);	
			//DumVal = GetAttributeBaseValue(TempAtt);
			CurrentAttributeValues.Add(TempAtt, DumVal*TempAtt->StartValuePercentage);
		}
	}
	else
	{
		//PrintError("CombatantError: No valid Attribute Set");
	}
}

UAttributeModifierContainer* UCombatantComponent::CreateAttributeModifier(UOmegaAttribute* Attribute, float Increment, float Multiplier, FGameplayTagContainer Tags)
{
	UAttributeModifierContainer* NewMod = NewObject<UAttributeModifierContainer>(this, UAttributeModifierContainer::StaticClass());
	NewMod->IncValue = Increment;
	NewMod->MultiValue = Multiplier;
	NewMod->Attribute = Attribute;
	NewMod->Tags = Tags;
	
	return NewMod;
}

void UCombatantComponent::SetAttributeModifierActive(UObject* Modifier, bool bActive)
{
	if(bActive)
	{
		AddAttrbuteModifier(Modifier);
	}
	else
	{
		RemoveAttributeModifier(Modifier);
	}
	
}

bool UCombatantComponent::AddAttrbuteModifier(UObject* Modifier)
{
	if(Modifier->Implements<UDataInterface_AttributeModifier>())
	{
		AttributeModifiers.Add(Modifier);
		return true;
	}
	return false;
}

bool UCombatantComponent::RemoveAttributeModifier(UObject* Modifier)
{
	if(!Modifier)
	{
		return false;
	}
	if(AttributeModifiers.Contains(Modifier))
	{
		AttributeModifiers.Remove(Modifier);
		return true;
	}
	return false;
}

void UCombatantComponent::RemoveAttributeModifersWithTags(FGameplayTagContainer Tags)
{
	for(UObject* TempMod : AttributeModifiers)
	{
		if(IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempMod).HasAnyExact(Tags))
		{
			RemoveAttributeModifier(TempMod);
		}
	}
}

// Compare Modifier list to base value.
float UCombatantComponent::GetAttributeComparedValue(UOmegaAttribute* Attribute, TArray<UObject*> Modifiers)
{
	return GatherAttributeModifiers(Modifiers,GetAttributeBaseValue(Attribute), Attribute);
}

////////////////////////////////////
////////// -- GATHER MODIFIERS -- /////////
///////////////////////////////////
const TArray<UObject*> UCombatantComponent::GetAttributeModifiers()
{
	//Base Modifiers
	TArray<UObject*> LocalMods = AttributeModifiers;
	
	//LocalMods.Append(static_cast<TArray<UObject*>>(Skills));
	//Add Skill Modifiers
	for(UObject* TempMod: static_cast<TArray<UObject*>>(Skills))
	{
		LocalMods.Add(TempMod);	
	}
	//Add Owner Mods
	if(GetOwner()->GetClass()->ImplementsInterface(UActorInterface_Combatant::StaticClass()))
	{
		for(UObject* TempMod: IActorInterface_Combatant::Execute_GetAttributeModifiers(GetOwner()))
		{
			LocalMods.Add(TempMod);	
		}
		//LocalMods.Append();
	}

	return LocalMods;
}

///Gather Modifier Values
float UCombatantComponent::GatherAttributeModifiers(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute)
{
	//Set Init Value
	float OutValue = BaseValue;
	TArray<FOmegaAttributeModifier> TempModList;
	for(UObject* TempObject : Modifiers)
	{
		// Makesute this object uses a Attribute Modifier Interface
		if(TempObject)
		{
			if(TempObject->Implements<UDataInterface_AttributeModifier>())
			{
				//Gather Attributes from Object
				TArray<FOmegaAttributeModifier> NewMods = IDataInterface_AttributeModifier::Execute_GetModifierValues(TempObject);
				TempModList.Append(NewMods);
				
				/*
				for(FOmegaAttributeModifier TempModVal : IDataInterface_AttributeModifier::Execute_GetModifierValues(TempObject))
				{
					if(TempModVal.Attribute==Attribute)
					{
						const float MultipliedValue = GetAttributeBaseValue(Attribute)*TempModVal.Multiplier;
						OutValue = OutValue+MultipliedValue+TempModVal.Incrementer;
					}
				}
				*/
			}
		}
	}
	OutValue = AdjustAttributeValueByModifiers(Attribute, TempModList);
	return OutValue;
}

float UCombatantComponent::AdjustAttributeValueByModifiers(UOmegaAttribute* Attribute,
	TArray<FOmegaAttributeModifier> Modifiers)
{
	float StartVal = GetAttributeBaseValue(Attribute);
	for(FOmegaAttributeModifier Mod : Modifiers)
	{
		if(Mod.Attribute == Attribute)
		{
			StartVal = StartVal+Mod.Incrementer+(Mod.Multiplier*GetAttributeBaseValue(Attribute));
		}
	}
	return StartVal;
}

TArray<FOmegaAttributeModifier> UCombatantComponent::GetAllModifierValues()
{
	TArray<FOmegaAttributeModifier> OutModVals;
	TArray<UObject*> ModsLocal = GetAttributeModifiers();
	for(auto* TempMod: ModsLocal)
	{
		OutModVals.Append(IDataInterface_AttributeModifier::Execute_GetModifierValues(TempMod));
	}
	return OutModVals;
}

////////////////////////////////////
////////// -- Effects -- /////////
///////////////////////////////////

AOmegaGameplayEffect* UCombatantComponent::CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, float Power, FTransform Location, UCombatantComponent* Target, FGameplayTagContainer AddedTags, UObject* Context)
{
	if (EffectClass)
	{
		FTransform SpawnWorldPoint;
		if (Target)
		{
			//IfActorValid, use their location.
			SpawnWorldPoint = Target->GetOwner()->GetActorTransform();
		}
		else
		{
			//If Actor is not valid, spawn at location.
			SpawnWorldPoint = Location;
		}
		
		class AOmegaGameplayEffect* LocalEffect = GetWorld()->SpawnActorDeferred<AOmegaGameplayEffect>(EffectClass, SpawnWorldPoint, nullptr);
		if(Target)
			
		{
			LocalEffect->SetOwner(Target->GetOwner());
			LocalEffect->TargetedCombatant = Target;
		}
		if(Context->IsValidLowLevel())
		{
			LocalEffect->EffectContext = Context;
		}
		LocalEffect->CombatantInstigator = this;
		LocalEffect->Power = Power;

		//Add new tags to effect
		TArray<FGameplayTag> LocalTags;
		AddedTags.GetGameplayTagArray(LocalTags);

		for (FGameplayTag TempTag : LocalTags)
		{
			LocalEffect->EffectTags.AddTag(TempTag);
		}

		UGameplayStatics::FinishSpawningActor(LocalEffect, SpawnWorldPoint);
		ActiveEffects.Add(LocalEffect);

		//Attach to target's owning Actor
		if (Target)
		{
			LocalEffect->AttachToActor(Target->GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
		}

		Update();

		return LocalEffect;
	}
	else
	{
		Update();

		return nullptr;
	}
}

void UCombatantComponent::TriggerEffectsWithTags(FGameplayTagContainer Tags)
{
	for (AOmegaGameplayEffect* TempEffect : GetEffectsWithTags(Tags))
	{
		TempEffect->TriggerEffect();
		UE_LOG(LogTemp, Display, TEXT("Applied Effect"));
	}
	Update();
}

void UCombatantComponent::TriggerEffectsOfCategory(FGameplayTag CategoryTag)
{
	for (AOmegaGameplayEffect* TempEffect : GetEffectsOfCategory(CategoryTag))
	{
		TempEffect->TriggerEffect();
	}
	Update();
}

TArray<AOmegaGameplayEffect*> UCombatantComponent::GetEffectsWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaGameplayEffect*> OutEffects;
	
	for (class AOmegaGameplayEffect* TempEffect : ActiveEffects)
	{
		if(TempEffect->IsValidLowLevel())
		{
			if (TempEffect->EffectTags.HasAnyExact(Tags))
			{
				OutEffects.Add(TempEffect);
			}
		}
	}
	
	return OutEffects;
}

TArray<AOmegaGameplayEffect*> UCombatantComponent::GetEffectsOfCategory(FGameplayTag CategoryTag)
{
	TArray<AOmegaGameplayEffect*> OutEffects;
	
	for (class AOmegaGameplayEffect* TempEffect : ActiveEffects)
	{
		if(TempEffect->IsValidLowLevel())
		{
			if (TempEffect->EffectCategory==CategoryTag)
			{
				OutEffects.Add(TempEffect);
			}
		}
	}
	return OutEffects;
}

AOmegaGameplayEffect* UCombatantComponent::GetActiveEffectOfClass(TSubclassOf<AOmegaGameplayEffect> EffectClass, bool& bIsValid)
{
	for(AOmegaGameplayEffect* TempEffect : GetValidActiveEffects())
	{
		if(TempEffect->GetClass() == EffectClass)
		{
			bIsValid = true;
			return TempEffect;
		}
	}
	bIsValid = false;
	return nullptr;
	
}

TArray<AOmegaGameplayEffect*> UCombatantComponent::GetValidActiveEffects()
{
	TArray<AOmegaGameplayEffect*> OutEffects;
	for(AOmegaGameplayEffect* TempEffect : ActiveEffects)
	{
		if(TempEffect != nullptr) {OutEffects.Add(TempEffect);}
		else {ActiveEffects.Remove(TempEffect);}
	}
	return OutEffects;
}

void UCombatantComponent::RemoveEffectsOfCategory(FGameplayTag CategoryTag)
{
	for(auto* TempEffect : GetEffectsOfCategory(CategoryTag))
	{
		TempEffect->Destroy();
	}
}

void UCombatantComponent::RemoveEffectsWithTags(FGameplayTagContainer EffectTags)
{
	for(auto* TempEffect : GetEffectsWithTags(EffectTags))
	{
		TempEffect->Destroy();
	}
}


///////////////////
/// Targeting ////
/////////////////
void UCombatantComponent::AddTargetToList(UCombatantComponent* Combatant)
{
	if(!Combatant)
	{
		return;
	}
	if(!TargetList.Contains(Combatant))
	{
		TargetList.AddUnique(Combatant);
		OnTargetAdded.Broadcast(Combatant);
		Combatant->OnAddedAsTarget.Broadcast(this);
	}
}

void UCombatantComponent::AddTargetsToList(TArray<UCombatantComponent*> Combatants, bool bClearListFirst)
{
	if(bClearListFirst)
	{
		ClearTargetList();
	}

	for(UCombatantComponent* TempTarget : Combatants)
	{
		if(TempTarget){AddTargetToList(TempTarget);}
		
	}
}

void UCombatantComponent::RemoveTargetFromList(UCombatantComponent* Combatant)
{
	if(!Combatant)
	{
		return;
	}
	if(TargetList.Contains(Combatant))
	{
		TargetList.Remove(Combatant);
		OnTargetRemoved.Broadcast(Combatant);
		Combatant->OnRemovedAsTarget.Broadcast(this);
	}
}

void UCombatantComponent::ClearTargetList()
{
	TArray<UCombatantComponent*> LocalCombatants = TargetList;
	for(UCombatantComponent* TempTarget : LocalCombatants)
	{
		RemoveTargetFromList(TempTarget);
	}
	TargetList.Empty();
}

TArray<UCombatantComponent*> UCombatantComponent::GetRegisteredTargetList()
{
	TArray<UCombatantComponent*> LocalTargets;
	for(UCombatantComponent* TempEntry : TargetList)
	{
		if(TempEntry)
		{
			LocalTargets.AddUnique(TempEntry);
		}
	}
	return LocalTargets;
}

void UCombatantComponent::SetActiveTarget(UCombatantComponent* Combatant)
{
	ActiveTarget = Combatant;
	OnActiveTargetChanged.Broadcast(ActiveTarget, true);
}

UCombatantComponent* UCombatantComponent::GetActiveTarget()
{
	return ActiveTarget;
}

int32 UCombatantComponent::GetActiveTargetIndex()
{
	if(GetActiveTarget() && GetRegisteredTargetList().Contains(GetActiveTarget()))
	{
		return GetRegisteredTargetList().Find(GetActiveTarget());
	}
	return 0;
}

UCombatantComponent* UCombatantComponent::CycleActiveTarget(int32 Amount)
{
	//Get Start Index
	int32 StartIndex = 0;
	if(GetRegisteredTargetList().Contains(GetActiveTarget()))
	{
		StartIndex = GetRegisteredTargetList().Find(GetActiveTarget());
	}

	int32 NewIndex = StartIndex+Amount;

	if(NewIndex < 0)
	{
		NewIndex = GetRegisteredTargetList().Num()-1;
	}
	else if(NewIndex > GetRegisteredTargetList().Num()-1)
	{
		NewIndex = 0;
	}

	if(GetRegisteredTargetList()[NewIndex])
	{
		SetActiveTarget(GetRegisteredTargetList()[NewIndex]);
		return GetRegisteredTargetList()[NewIndex];
	}
	return nullptr;
}

void UCombatantComponent::ClearActiveTarget()
{
	if(IsActiveTargetValid())
	{
		ActiveTarget = nullptr;
		OnActiveTargetChanged.Broadcast(nullptr, false);
	}
}

bool UCombatantComponent::IsActiveTargetValid()
{
	return ActiveTarget->IsValidLowLevel();
}

void UCombatantComponent::CombatantNotify(FName Notify, const FString& Payload)
{
	OnCombatantNotify.Broadcast(this, Notify, Payload);
}


///////////////////
/// Faction ////
/////////////////

FText UCombatantComponent::GetFactionName()
{
	if(FactionDataAsset)
	{
		return FactionDataAsset->Name;
	}
	FText DumText;
	return DumText;
}

FLinearColor UCombatantComponent::GetFactionColor()
{
	
	if(FactionDataAsset)
	{
		return FactionDataAsset->FactionColor;
	}
	const FLinearColor DumColor;
	return DumColor;
}

FGameplayTag UCombatantComponent::GetFactionTag()
{
	if(FactionDataAsset)
	{
		return FactionDataAsset->FactionTag;
	}
	return FactionTag;
}

TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> UCombatantComponent::GetFactionAffinities()
{
	if(FactionDataAsset)
	{
		return FactionDataAsset->FactionAffinities;
	}
	return FactionAffinities;
}

EFactionAffinity UCombatantComponent::GetAffinityToCombatant(UCombatantComponent* CheckedCombatant)
{
	//If invalid combatant
	if(!CheckedCombatant)
	{
		return EFactionAffinity::NeutralAffinity;
	}
	
	// If valid tag, return that
	if(GetFactionAffinities().Contains(CheckedCombatant->GetFactionTag()))
	{
		return GetFactionAffinities().FindOrAdd(CheckedCombatant->GetFactionTag());
	}
	//If same tag as me, they are friendly (unless specified differently above.)
	else if (CheckedCombatant->GetFactionTag()==GetFactionTag())
	{
		return EFactionAffinity::FriendlyAffinity;
	}
	//If all else fails, they are neutral.
	else
	{
		return EFactionAffinity::NeutralAffinity;
	}
}

TArray<UCombatantComponent*> UCombatantComponent::FilterCombatantsByAffinity(TArray<UCombatantComponent*> Combatants,
	EFactionAffinity Affinity, bool bExclude)
{
	TArray<UCombatantComponent*> OutCombatants;

	for(UCombatantComponent* TempCombatant : Combatants)
	{
		//Fitler out mismatched combatants
		if((GetAffinityToCombatant(TempCombatant) == Affinity) == !bExclude)
		{
			OutCombatants.Add(TempCombatant);
		}
	}
	return OutCombatants;
}

///////////////////////////////////
////////// -- REDIRECT DATA -- //////////
///////////////////////////////////

TArray<FOmegaAttributeModifier> UCombatantComponent::GetModifierValues_Implementation()
{
	return GetAllModifierValues();
}

TArray<UPrimaryDataAsset*> UCombatantComponent::GetSkills_Implementation()
{
	return GetAllSkills();
}




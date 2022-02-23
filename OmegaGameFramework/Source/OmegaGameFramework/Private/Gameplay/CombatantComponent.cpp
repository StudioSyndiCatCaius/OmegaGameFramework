// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Gameplay/CombatantComponent.h"

#include "Blueprint/WidgetBlueprintLibrary.h"

#include "OmegaGameplayEffect.h"

#include "Widget/WidgetInterface_Combatant.h"
#include "Attributes/OmegaAttributeSet.h"
#include "GameFramework/Character.h"
#include "Gameplay/DataInterface_DamageModifier.h"


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

	///---Try Setup Input---//

	OwnerPawn = Cast<APawn>(GetOwner());

	//Grant StarterAbilities
	for(const TSubclassOf<AOmegaAbility> TempAbClass : GrantedAbilities)
	{
		GrantAbility(TempAbClass);
	}

	
	InitializeAttributes();
}

void UCombatantComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
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
					MaxText->SetText(FText::FromString(FString::SanitizeFloat(DumMax)));
				}
				//Set Current Value Text
				if (ValText)
				{
					MaxText->SetText(FText::FromString(FString::SanitizeFloat(DumVal)));
				}

				class UProgressBar* AttProg;
				IWidgetInterface_Combatant::Execute_GetAttributeProgressBar(TempWidget, LocalAtb, AttProg);
				if (AttProg)
				{
					//GEngine->AddOnScreenDebugMessage(-1, 3.0F, FColor::Green, "ReachATT");
					
					AttProg->SetPercent(GetAttributePercentage(LocalAtb));
				}

			}
		}
	}
}

	/////GRANT ABILITY
	///
bool UCombatantComponent::GrantAbility(TSubclassOf<AOmegaAbility> AbilityClass)
{
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
			LocalAbility->Execute(Context);
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
		if (TempAbility->AbilityTags.HasAnyExact(Tags))
		{
			FoundAbilities.Add(TempAbility);
		}
	}
	return FoundAbilities;
}

	////////////////////////////////////
	////////// -- ATTRIBUTES -- //////////
	///////////////////////////////////
float UCombatantComponent::ApplyAttributeDamage(class UOmegaAttribute* Attribute, float BaseDamage, class UObject* Instigator, UObject* DamageModifier)
{
	float BaseValue;
	float MaxVal;
	GetAttributeValue(Attribute, BaseValue, MaxVal);
	float FinalDamage;
	
	if(DamageModifier)		//Is there a valid damae modifier
	{
		FinalDamage = IDataInterface_DamageModifier::Execute_ModifyDamage(DamageModifier, Attribute, this, Instigator, BaseDamage); //Apply Damage Modifier
	}
	else
	{
		FinalDamage = BaseDamage;
	}
	
	FinalDamage = BaseValue + (-1.0 * FinalDamage);		//Deduct final damage value from current attribute value
	FinalDamage = FMath::Clamp(FinalDamage, 0.0f, MaxVal);		//Make sure the value does not go under 0 or exceed the max allowed value
	CurrentAttributeValues.Add(Attribute, FinalDamage);				///Update the damage value map
	OnDamaged.Broadcast(this, Attribute, FinalDamage, Instigator);

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

float UCombatantComponent::GatherAttributeModifiers(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute)
{
	float FinalValue = BaseValue;

	for(UObject* TempMod : AttributeModifiers)
	{
		for(UObject* TempObject : Modifiers)
		{
			// Makesute this object uses a Attribute Modifier Interface
			if(TempObject->Implements<UDataInterface_AttributeModifier>())
			{
				//Gather Attributes from Object
				TArray<FOmegaAttributeModifier> TempModList;
				for(FOmegaAttributeModifier TempModVal : IDataInterface_AttributeModifier::Execute_GetModifierValues(TempObject))
				{
					if(TempModVal.Attribute==Attribute)
					{
						FinalValue = FinalValue+(BaseValue*TempModVal.Multiplier)+TempModVal.Incrementer;
					}
				}
			}
		}
	}
	return FinalValue;
}

///////////////////
/// Skills ////
/////////////////

void UCombatantComponent::AddSkill(UPrimaryDataAsset* Skill)
{
	Skills.Add(Skill);
}

void UCombatantComponent::RemoveSkill(UPrimaryDataAsset* Skill)
{
	Skills.Remove(Skill);
}



//// Get Attribute Values + Attribute Modifiers
void UCombatantComponent::GetAttributeValue(UOmegaAttribute* Attribute, float& CurrentValue, float& MaxValue)
{
	int32 AttLevel = AttributeLevels.FindOrAdd(Attribute);
	const float BaseValue = Attribute->GetAttributeValue(Level, AttLevel, AttributeSet->ValueCategory);
	float FinalValue = BaseValue;

	float TempInc = 0.0;
	float TempMult = 0.0;
	
	/*for(UObject* TempMod : AttributeModifiers)
	{
		TArray<FOmegaAttributeModifier> TempModList;
		for(FOmegaAttributeModifier TempModVal : IDataInterface_AttributeModifier::Execute_GetModifierValues(TempMod))
		{
			if(TempModVal.Attribute==Attribute)
			{
				FinalValue = FinalValue+(BaseValue*TempModVal.Multiplier)+TempModVal.Incrementer;
			}
		}
	}
*/
	// Gather from normal modifiers
	FinalValue = GatherAttributeModifiers(AttributeModifiers,FinalValue, Attribute);
	// Gather from skills
	FinalValue = GatherAttributeModifiers(static_cast<TArray<UObject*>>(Skills),FinalValue, Attribute);
	
	MaxValue  = FinalValue;
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
		int32 DumRank = 0;
		float DumVal = 0.0f;
		for (UOmegaAttribute* TempAtt : AttributeSet->Attributes)
		{
			if (AttributeLevels.Contains(TempAtt))
			{
				DumRank = AttributeLevels[TempAtt];
			}
			DumVal = TempAtt->GetAttributeValue(Level, DumRank, AttributeSet->ValueCategory);
			CurrentAttributeValues.Add(TempAtt, DumVal*TempAtt->StartValuePercentage);
		}
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

const TArray<UObject*> UCombatantComponent::GetAttributeModifiers()
{
	return AttributeModifiers;
}

////////////////////////////////////
////////// -- Effects -- /////////
///////////////////////////////////

AOmegaGameplayEffect* UCombatantComponent::CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, float Power, FTransform Location, class AActor* Target, FGameplayTagContainer AddedTags)
{
	if (EffectClass)
	{
		FTransform SpawnWorldPoint;
		if (Target)
		{
			//IfActorValid, use their location.
			SpawnWorldPoint = Target->GetActorTransform();
		}
		else
		{
			//If Actor is not valid, spawn at location.
			SpawnWorldPoint = Location;
		}
		
		class AOmegaGameplayEffect* LocalEffect = GetWorld()->SpawnActorDeferred<AOmegaGameplayEffect>(EffectClass, SpawnWorldPoint, nullptr);
		if(Target)
			
		{
			LocalEffect->SetOwner(Target);
			LocalEffect->TargetActor = Target;
		}
		
		LocalEffect->CombatantInstigator = this;
		LocalEffect->Power = Power;

		//Add new tags to effect
		TArray<FGameplayTag> LocalTags;
		LocalEffect->EffectTags.GetGameplayTagArray(LocalTags);
		for (FGameplayTag TempTag : LocalTags)
		{
			LocalEffect->EffectTags.AddTag(TempTag);
		}

		UGameplayStatics::FinishSpawningActor(LocalEffect, SpawnWorldPoint);
		ActiveEffects.Add(LocalEffect);
		
		if (Target)
		{
			LocalEffect->AttachToActor(Target, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
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
	for (class AOmegaGameplayEffect* TempEffect : ActiveEffects)
	{
		if (TempEffect->EffectTags.HasAnyExact(Tags))
		{
			TempEffect->TriggerEffect();
		}
	}

	Update();
}
///////////////////
/// Targeting ////
/////////////////
void UCombatantComponent::AddTargetToList(UCombatantComponent* Combatant)
{
	if(!TargetList.Contains(Combatant))
	{
		TargetList.AddUnique(Combatant);
		OnTargetAdded.Broadcast(Combatant);
	}
}

void UCombatantComponent::RemoveTargetFromList(UCombatantComponent* Combatant)
{
	if(TargetList.Contains(Combatant))
	{
		TargetList.Remove(Combatant);
		OnTargetRemoved.Broadcast(Combatant);
	}
}

void UCombatantComponent::ClearTargetList()
{
	for(UCombatantComponent* TempTarget : TargetList)
	{
		RemoveTargetFromList(TempTarget);
	}
}

void UCombatantComponent::SetActiveTarget(UCombatantComponent* Combatant)
{
	ActiveTarget = Combatant;
	OnActiveTargetChanged.Broadcast(ActiveTarget, true);
}

void UCombatantComponent::ClearActiveTarget()
{
	ActiveTarget = nullptr;
	OnActiveTargetChanged.Broadcast(nullptr, false);
}






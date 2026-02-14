// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_Combatant.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Gameplay.h"
#include "OmegaSettings_Global.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetTextLibrary.h"

#include "Actors/Actor_Ability.h"
#include "Actors/Actor_GameplayEffect.h"

#include "Subsystems/Subsystem_Gameplay.h"

#include "Interfaces/I_Widget.h"
#include "Interfaces/I_Combatant.h"

#include "Misc/OmegaAttribute.h"
#include "Misc/OmegaDamageType.h"
#include "DataAssets/DA_CombatantGambits.h"
#include "Misc/OmegaFaction.h"

#include "Components/PrimitiveComponent.h"
#include "Functions/F_Common.h"

#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Misc/OmegaUtils_Macros.h"


float UCombatantComponent::L_ModifyDamage(UOmegaAttribute* Attribute,UCombatantComponent* Instigator,float BaseDamage,UOmegaDamageType* DamageType,UObject* Context)
{
	float FinalDamage = BaseDamage;
	
	if (Attribute)
	{
		UE_LOG(LogTemp, Log, TEXT("Modifying damage to '%s' on attribute '%s' with starting value: '%f' "), *GetName(),*Attribute->GetName(),FinalDamage);
		UOmegaGlobalSettings* globSet=GetMutableDefault<UOmegaSettings>()->GetGlobalSettings();
	
	
		FinalDamage=globSet->Combatant_ModifyDamage_PreMod(Attribute,this,Instigator,BaseDamage,DamageType,Context);
		UE_LOG(LogTemp, Log, TEXT("		---  Applying PRE SOURCE modifiers. Result: '%f' "),FinalDamage);
		
		UE_LOG(LogTemp, Log, TEXT("		---  Applying SOURCE modifiers."));
		for(auto* TempMod : GetDamageModifiers())
		{
			if (TempMod)
			{
				FinalDamage = IDataInterface_DamageModifier::Execute_ModifyDamage(TempMod, Attribute, this, Instigator, BaseDamage, DamageType, Context); //Apply Damage Modifier
				UE_LOG(LogTemp, Log, TEXT("				-----  Applying SOURCE modifier from '%s' with result: %f."), *TempMod->GetName(), FinalDamage);
			}
		}
		
		FinalDamage=globSet->Combatant_ModifyDamage_PostMod(Attribute,this,Instigator,BaseDamage,DamageType,Context);
		UE_LOG(LogTemp, Log, TEXT("		---  Applying POST SOURCE modifiers. Result: '%f' "),FinalDamage);
	}
	
	return FinalDamage;
}

UCombatantComponent::UCombatantComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCombatantComponent::BeginPlay()
{
	Super::BeginPlay();
	if(UOmegaAttributeSet* NewSet=GetMutableDefault<UOmegaSettings>()->Default_AttributeSet.LoadSynchronous())
	{
		AttributeSet=NewSet;
	}
    
	auto* WorldSubsystem = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
	if (WorldSubsystem)
	{
		WorldSubsystem->Native_RegisterCombatant(this, true);
	}
    
	ref_OwnerPawn = Cast<APawn>(GetOwner());

	// Grant StarterAbilities
	for (auto ab: OGF_CFG()->Default_Abilities)
	{
		if (TSubclassOf<AOmegaAbility> abc=ab.LoadSynchronous())
		{
			SetAbilityGranted(abc,true);
		}
	}
	SetAbilitiesGranted(GrantedAbilities,true);

	InitializeAttributes();
}

void UCombatantComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason == EEndPlayReason::Destroyed || EndPlayReason == EEndPlayReason::RemovedFromWorld)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->Native_RegisterCombatant(this, false);
	}
	

	
	//Destroy Effects
	for(auto* TempActor : GetAllEffects())
	{
		TempActor->K2_DestroyActor();
	}
	
	//Destroy abilities
	Super::EndPlay(EndPlayReason);
	for(AOmegaAbility* TempAb : abilities_granted)
	{
		TempAb->K2_DestroyActor();
	}
}

void UCombatantComponent::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	if(CombatantDataAsset && CombatantDataAsset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(CombatantDataAsset,Label,Context,Name,Description);	
	}
	if(GetOwner()->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(GetOwner(),Label,Context,Name,Description);	
	}
}

void UCombatantComponent::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(CombatantDataAsset && CombatantDataAsset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataImages(CombatantDataAsset,Label,Context,Texture,Material,Brush);	
	}
	if(GetOwner()->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataImages(GetOwner(),Label,Context,Texture,Material,Brush);	
	}
}

void UCombatantComponent::GetGeneralAssetColor_Implementation(FLinearColor& Color)
{
	Color=GetFactionColor();
}

float UCombatantComponent::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
                                                       UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	return L_ModifyDamage(Attribute,Instigator,BaseDamage,DamageType,Context);
}

void UCombatantComponent::SetMasterDataSourceActive(UObject* Source, bool bActive)
{
	if(Source)
	{
		if(bActive && !SOURCES_Master.Contains(Source))
		{
			SOURCES_Master.Add(Source);
			Update();
		}
		else if(!bActive && SOURCES_Master.Contains(Source))
		{
			SOURCES_Master.Remove(Source);
			Update();
		}
	}
}


void UCombatantComponent::ChangeAttributeSet(UOmegaAttributeSet* NewSet, bool Reinitialize)
{
	AttributeSet=NewSet;
	if(Reinitialize)
	{
		InitializeAttributes();
	}
}

////////////////////////////////////
////////// -- TAGS -- //////////
///////////////////////////////////

FGameplayTagContainer UCombatantComponent::GetCombatantTags()
{
	return CombatantTags;
}

bool UCombatantComponent::CombatantHasTag(FGameplayTag Tag) const
{
	return CombatantTags.HasTag(Tag);
}

bool UCombatantComponent::CombatantHasAnyTag(FGameplayTagContainer Tags, bool Exact) const
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

bool UCombatantComponent::CombatantHasAllTag(FGameplayTagContainer Tags, bool Exact) const
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
	L_CacheAttributeMods();
}

APawn* UCombatantComponent::GetOwnerPawn() const
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

APlayerController* UCombatantComponent::GetOwnerPlayerController() const
{
	if(APawn* p=GetOwnerPawn())
	{
		if(APlayerController* c=Cast<APlayerController>(p->GetController()))
		{
			return c;
		}
	}
	return nullptr;
}

void UCombatantComponent::SetSourceDataAsset(UPrimaryDataAsset* DataAsset)
{
	if(DataAsset)
	{
		UPrimaryDataAsset* oldAsset=DataAsset;
		CombatantDataAsset=DataAsset;
		OnDataAssetChanged.Broadcast(this,DataAsset,oldAsset);
	}
}

UPrimaryDataAsset* UCombatantComponent::GetSourceDataAsset() const
{
	if(CombatantDataAsset) {return CombatantDataAsset;} return nullptr;
}

//--------------------------//
//General Overrides
//--------------------------//

bool UCombatantComponent::SetAbilityGranted(TSubclassOf<AOmegaAbility> AbilityClass, bool Granted)
{
	if(!AbilityClass)
	{
		return false;
	}
	if(Granted)
	{
		bool bTempSuccess;
		if(!GetAbility(AbilityClass, bTempSuccess))
		{
			AOmegaAbility* LocalAbility = nullptr;
			const FTransform SpawnWorldPoint;
			//Spawn Ability
			LocalAbility = GetWorld()->SpawnActorDeferred<AOmegaAbility>(AbilityClass, SpawnWorldPoint, nullptr);
			if(LocalAbility)
			{
				LocalAbility->CombatantOwner = this;
		
				if (Cast<ACharacter>(GetOwner()))
				{
					LocalAbility->ref_character = Cast<ACharacter>(GetOwner());
				}
				if (Cast<APawn>(GetOwner()))
				{
					LocalAbility->SetInstigator(Cast<APawn>(GetOwner()));
				}
		
				UGameplayStatics::FinishSpawningActor(LocalAbility, SpawnWorldPoint);
				LocalAbility->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
				//Add to AbilitiesList
				abilities_granted.Add(LocalAbility);
				return true;
			}
		}
	}
	else
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
			abilities_granted.Remove(AbilityRef);
			AbilityRef->K2_DestroyActor();
			return true;
		}
	}
	return false;
}

void UCombatantComponent::SetAbilitiesGranted(TArray<TSubclassOf<AOmegaAbility>> AbilityClass, bool Granted)
{
	for(TSubclassOf<AOmegaAbility> c : AbilityClass)
	{
		SetAbilityGranted(c,Granted);
	}
}


AOmegaAbility* UCombatantComponent::GetAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool& bSuccess)
{
	bSuccess = false;
	for(AOmegaAbility* TempAb : abilities_granted)
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
	bSuccess = false;
	bool bValidAbility=false;
	if(AOmegaAbility* _ability = GetAbility(AbilityClass, bValidAbility))
	{
		_ability->ContextObject=Context;
		bSuccess=_ability->Native_Execute();
		return _ability;
	}
	return nullptr;
}

bool UCombatantComponent::IsAbilityActive(class TSubclassOf<AOmegaAbility> AbilityClass)
{
	for (AOmegaAbility* TempAbility : abilities_granted)
	{
		if(TempAbility and TempAbility->bIsActive)
		{
			return true;
		}
	}
	return false;
}

bool UCombatantComponent::StopAbility(TSubclassOf<AOmegaAbility> AbilityClass, bool Cancel)
{
	bool if_success;
	if(AOmegaAbility* TempAbility = GetAbility(AbilityClass,if_success))
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
	return false;
}

TArray<AOmegaAbility*> UCombatantComponent::GetActiveAbilities()
{
	TArray<AOmegaAbility*> out;
	for(auto* a : abilities_granted)
	{
		if(a && a->bIsActive)
		{
			out.Add(a);
		}
	}
	return out;
}

TArray<AOmegaAbility*> UCombatantComponent::GetActiveAbilitiesWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaAbility*> FoundAbilities;
	for (AOmegaAbility* TempAbility : GetActiveAbilities())
	{
		if(TempAbility)
		{
			if (!Tags.IsEmpty() && TempAbility->AbilityTags.HasAnyExact(Tags))
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

	for(auto* TempAbility : abilities_granted)
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
	
	if(Attribute)
	{
		if(!bCanDamageAttributes || Attribute->bIsValueStatic)
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

		//Aply Damage Modifiers
		FinalDamage=L_ModifyDamage(Attribute,Instigator,FinalDamage,DamageType,Context);
		
		// DAMAGE TYPE REACTIONS
		if(DamageType && DamageTypeReactions.Contains(DamageType))
		{
			UOmegaDamageTypeReactionAsset* ReactClass = DamageTypeReactions.FindOrAdd(DamageType);
			if(ReactClass)
			{
				IDataInterface_DamageModifier::Execute_ModifyDamage(ReactClass, Attribute, this, Instigator, BaseDamage, LocalDamageType, Context); //Apply Damage Modifier
			}
			if(ReactionEffectClass && ReactClass)
			{
				CreateEffect(ReactionEffectClass,1.0,this,FGameplayTagContainer(),ReactClass);
			}
		}
	
		//--------------------- FINISH AND APPLY ---------------------///
	
		CurrentValue = CurrentValue - FinalDamage;		//Deduct final damage value from current attribute value
		CurrentValue = FMath::Clamp(CurrentValue, 0.0f, MaxVal);		//Make sure the value does not go under 0 or exceed the max allowed value

		//FINALIZE
		CurrentAttributeValues.Add(Attribute, CurrentValue);
		OnDamaged.Broadcast(this, Attribute, FinalDamage, Instigator, LocalDamageType, Hit);
		Update();
		return FinalDamage;
	}
	return 0;
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

void UCombatantComponent::SetAttributeValueCategory(FGameplayTag CategoryTag, bool bReinitialize)
{
	AttributeValueCategory = CategoryTag;
	if(bReinitialize)
	{
		InitializeAttributes();
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

void UCombatantComponent::L_CacheAttributeMods()
{
	if(bCacheAttributeModifierValues)
	{
		CachedAttributeModValues=GetAllModifierValues();
	}
}

//////////////////
/// Skills //////
////////////////
TArray<UPrimaryDataAsset*> UCombatantComponent::GetAllSkills()
{
	TArray<UPrimaryDataAsset*> OutSkills = Skills;
	for(auto* TempSource : L_GetSources_Skill())
	{
		for(auto* TempSkill : IDataInterface_SkillSource::Execute_GetSkills(TempSource,this))
		{
			if(TempSkill)
			{
				OutSkills.Add(TempSkill);
			}
		}
	}
	OutSkills.Append(GetMutableDefault<UOmegaSettings>()->GetGlobalSettings()->Combatant_Append_Skills(this));
	return OutSkills;
}

void UCombatantComponent::AddSkill(UPrimaryDataAsset* Skill, bool Added)
{
	if(Skill)
	{
		bool has_interface=Skill->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass());
		if(Added)
		{
			Skills.Add(Skill);
			if(has_interface)
			{
				IDataInterface_Skill::Execute_OnSkillAddedToCombatant(Skill,this,true);
			}
		}
		else
		{
			Skills.Remove(Skill);
			if(has_interface)
			{
				IDataInterface_Skill::Execute_OnSkillAddedToCombatant(Skill,this,false);
			}
		}
	}
}

void UCombatantComponent::AddSkills(TArray<UPrimaryDataAsset*> skill_list, bool Added)
{
	for(auto* i : skill_list)
	{
		AddSkill(i,Added);
	}
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
			SOURCES_Skills.AddUnique(SkillSource);
		}
		else
		{
			SOURCES_Skills.Remove(SkillSource);
		}
	}
	return true;
}

TArray<UObject*> UCombatantComponent::L_GetSources_Skill()
{
	TArray<UObject*> OutSkills;
	for(auto* i : SOURCES_Skills)
	{
		if(i && i->GetClass()->ImplementsInterface(UDataInterface_SkillSource::StaticClass()))
		{
			OutSkills.AddUnique(i);
		}
	}
	for(auto* i : SOURCES_Master)
	{
		if(i && i->GetClass()->ImplementsInterface(UDataInterface_SkillSource::StaticClass()))
		{
			OutSkills.AddUnique(i);
		}
	}
	return OutSkills;
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
			SOURCES_DamageMods.Add(Modifier);
		}
		else
		{
			SOURCES_DamageMods.Remove(Modifier);
		}
	}
	return false;
}

TArray<UObject*> UCombatantComponent::GetDamageModifiers()
{
	TArray<UObject*> OutMods;
	for(auto* TempMod : SOURCES_DamageMods)
	{
		if(TempMod && TempMod->Implements<UDataInterface_DamageModifier>())
		{
			OutMods.Add(TempMod);
		}
	}
	for(auto* TempMod : SOURCES_Master)
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
	if(!Attribute)
	{
		CurrentValue = 0;
		MaxValue = 0;
		return;
	}
	if(OverrideMaxAttributes.Contains(Attribute))
	{
		MaxValue = OverrideMaxAttributes[Attribute];
	}
	else
	{
		//Get base value
		float BaseValue = GetAttributeBaseValue(Attribute);
	
		//Gather All modifiers and apply them to final damage.
		BaseValue = L_GetAllModsOfAttribute(GetAttributeModifiers(),BaseValue, Attribute);
	
		MaxValue  = BaseValue;
		//Get Current Value
	}
	
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
	int32 attribute_rank=GetAttributeLevel(Attribute);
	float _baseVal=Attribute->GetAttributeValue(Level, attribute_rank, AttributeValueCategory);
	_baseVal=OGF_GLOBAL_SETTINGS()->Attribute_GetMaxValue(this,Attribute,attribute_rank,_baseVal);
	return _baseVal;
}

bool UCombatantComponent::IsAbilityTagBlocked(FGameplayTagContainer Tags)
{
	if(Tags.IsEmpty()) { return false; }
	for (AOmegaAbility* TempAbility : GetActiveAbilities())
	{
		if(TempAbility)
		{
			if (!TempAbility->BlockAbilities.IsEmpty() && TempAbility->BlockAbilities.HasAnyExact(Tags))
			{
				UE_LOG(LogTemp, Warning, TEXT("Ability Tag: %s is blocked on %s"),*Tags.ToString(),*TempAbility->GetName());

				return true;
			}
		}
	}
	return false;
}

void UCombatantComponent::SetOverrideMaxAttribute(UOmegaAttribute* Attribute, float Value)
{
	OverrideMaxAttributes.Add(Attribute,Value);
	Update();
}

void UCombatantComponent::SetOverrideMaxAttributes(TMap<UOmegaAttribute*, float> Value)
{
	OverrideMaxAttributes=Value;
	Update();
}



float UCombatantComponent::GetAttributePercentage(UOmegaAttribute* Attribute)
{
	if(Attribute)
	{
		float CurVal;
		float MaxVal;
		GetAttributeValue(Attribute, CurVal, MaxVal);
		float OutVal = CurVal / MaxVal;
		return OutVal;
	}
	return 0.0;
}

TMap<UOmegaAttribute*, float> UCombatantComponent::GetCurrentAttributeValues()
{
	return CurrentAttributeValues;
}

void UCombatantComponent::SetCurrentAttributeValue(UOmegaAttribute* Attribute, float Value)
{
	if(Attribute)
	{
		CurrentAttributeValues.Add(Attribute,Value);
	}
	Update();
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
		TMap<UOmegaAttribute*,FOmegaAttributeSetOverride> temp_confg=AttributeSet->GetAttributeConfigs();
		TArray<UOmegaAttribute*> TempAtts;
		temp_confg.GetKeys(TempAtts);
		
		for (UOmegaAttribute* TempAtt : TempAtts)
		{
			if(TempAtt)
			{
				FOmegaAttributeSetOverride f=temp_confg.FindOrAdd(TempAtt);
				// if attributeSet overrides max value AND max values is not already overwritten
				if(f.bOverrideMax && !OverrideMaxAttributes.Contains(TempAtt))
				{
					OverrideMaxAttributes.Add(TempAtt,f.MaxOverride);
				}

				GetAttributeValue(TempAtt, CurrentVal, DumVal);	

				if(!TempAtt->bIsValueStatic)
				{
					CurrentAttributeValues.Add(TempAtt, DumVal*TempAtt->StartValuePercentage);	
				}
			}
		}
	}
	else
	{
		//PrintError("CombatantError: No valid Attribute Set");
	}
}

// =============================================================================================================================================
// Attribute Modifiers
// =============================================================================================================================================

TArray<FOmegaAttributeModifier> UCombatantComponent::GetModifierValues_Implementation(UCombatantComponent* CombatantComponent)
{
	if(bCacheAttributeModifierValues)
	{
		return CachedAttributeModValues;
	}
	return GetAllModifierValues();
}


void UCombatantComponent::SetAttributeModifierActive(UObject* Modifier, bool bActive)
{
	if(Modifier)
	{
		if(bActive && !SOURCES_AttributeMods.Contains(Modifier))
		{
			SOURCES_AttributeMods.Add(Modifier);
			//Local_CacheAttributeMods();
			Update();
		}
		else if(!bActive && SOURCES_AttributeMods.Contains(Modifier))
		{
			SOURCES_AttributeMods.Remove(Modifier);
			Update();
		}
	}
}

// Compare Modifier list to base value.
float UCombatantComponent::GetAttributeComparedValue(UOmegaAttribute* Attribute, TArray<UObject*> Modifiers)
{
	return L_GetAllModsOfAttribute(Modifiers,GetAttributeBaseValue(Attribute), Attribute);
}

////////////////////////////////////
////////// -- GATHER MODIFIERS -- /////////
///////////////////////////////////
const TArray<UObject*> UCombatantComponent::GetAttributeModifiers()
{
	//Base Modifiers
	TArray<UObject*> _mods = SOURCES_AttributeMods;
	
	if(bUseSkillsAsMasterSource)
	{
		for(UObject* TempMod: static_cast<TArray<UObject*>>(GetAllSkills()))
		{
			_mods.Add(TempMod);	
		}
	}
	for(auto* i : SOURCES_Master)
	{
		if(i && i->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			_mods.Add(i);
		}
	}
	return _mods;
}

///Applies Modifier Values
float UCombatantComponent::L_GetAllModsOfAttribute(TArray<UObject*> Modifiers, float BaseValue, UOmegaAttribute* Attribute)
{
	
	if(!Attribute->bAllowModifiers)
	{
		return BaseValue;
	}
	
	//Set Init Value
	float OutValue = BaseValue;
	TArray<FOmegaAttributeModifier> TempModList;
	for(UObject* TempObject : Modifiers)
	{
		// Make suRe this object uses a Attribute Modifier Interface
		if(TempObject)
		{
			if(TempObject->Implements<UDataInterface_AttributeModifier>())
			{
				//Gather Attributes from Object
				TArray<FOmegaAttributeModifier> NewMods = IDataInterface_AttributeModifier::Execute_GetModifierValues(TempObject,this);
				TempModList.Append(NewMods);
				
			}
		}
	}
	OutValue = AdjustAttributeValueByModifiers(Attribute, TempModList);

	
	return OutValue;
}


float UCombatantComponent::AdjustAttributeValueByModifiers(UOmegaAttribute* Attribute,
                                                           TArray<FOmegaAttributeModifier> Modifiers)
{
	if(!Attribute)
	{
		return 0;
	}
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
		if(TempMod!=nullptr && TempMod->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			TArray<FOmegaAttributeModifier> in_mods=IDataInterface_AttributeModifier::Execute_GetModifierValues(TempMod,this);
			OutModVals.Append(in_mods);
		}
	}
	return OutModVals;
}


////////////////////////////////////
////////// -- Effects -- /////////
///////////////////////////////////

FGameplayTagContainer UCombatantComponent::GetBlockedEffectTags()
{
	return BlockEffectWithTags;
}

AOmegaGameplayEffect* UCombatantComponent::GetEffectOfContext(UObject* Context,
	TSubclassOf<AOmegaGameplayEffect> EffectClass)
{
	for(auto* TempEffect : GetAllEffects())
	{
		if(TempEffect && (!EffectClass || TempEffect->GetClass()) && TempEffect->EffectContext==Context)
		{
			return TempEffect;
		}
	}
	return nullptr;
}

float UCombatantComponent::GetEffectSuccessRate(TSubclassOf<AOmegaGameplayEffect> EffectClass)
{
	if(EffectClass)
	{
		const float DefaultRate = GetMutableDefault<AOmegaGameplayEffect>(EffectClass)->DefaultSuccessRate;
		if(EffectSuccessRate.Contains(EffectClass))
		{
			return  FMath::Clamp(EffectSuccessRate[EffectClass]+DefaultRate,0.0f,2.0f);
		}
		return DefaultRate;
	}
	return 1;
}

void UCombatantComponent::SetEffectSuccessRate(TSubclassOf<AOmegaGameplayEffect> EffectClass, float OffsetRate)
{
	EffectSuccessRate.Add(EffectClass,OffsetRate);
}



AOmegaGameplayEffect* UCombatantComponent::CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, float Power, UCombatantComponent* Target, FGameplayTagContainer AddedTags, UObject* Context)
{
	//Check Effect Success Rate. Abort function if unsuccessful
	const float SuccessValue = UKismetMathLibrary::RandomFloat();
	if(SuccessValue>GetEffectSuccessRate(EffectClass))
	{
		return nullptr;
	}
		
	if (EffectClass && Target &&
		!Target->GetBlockedEffectTags().HasAny(GetMutableDefault<AOmegaGameplayEffect>(EffectClass)->EffectTags))
	{
		const FTransform SpawnWorldPoint = Target->GetOwner()->GetActorTransform();
		
		class AOmegaGameplayEffect* LocalEffect = GetWorld()->SpawnActorDeferred<AOmegaGameplayEffect>(EffectClass, SpawnWorldPoint, nullptr);
		LocalEffect->SetOwner(Target->GetOwner());
		LocalEffect->TargetedCombatant = Target;
		LocalEffect->EffectContext = Context;
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

		LocalEffect->AttachToActor(Target->GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
		
		Update();
		return LocalEffect;

	}
	
	Update();
	return nullptr;
}

bool UCombatantComponent::HasEffectWithTags(FGameplayTagContainer Tags)
{
	return GetEffectsWithTags(Tags).IsValidIndex(0);
}

TArray<AOmegaGameplayEffect*> UCombatantComponent::GetAllEffects()
{
	TArray<AOmegaGameplayEffect*> OutEffects;
	
	TArray<AActor*> TempActors;
	GetOwner()->GetAttachedActors(TempActors);
	
	//Destroy Effects
	for(auto* TempActor : TempActors)
	{
		if(TempActor && TempActor->GetClass()->IsChildOf(AOmegaGameplayEffect::StaticClass()))
		{
			OutEffects.AddUnique(Cast<AOmegaGameplayEffect>(TempActor));
		}
	}
	
	return OutEffects;
}

TArray<AOmegaGameplayEffect*> UCombatantComponent::GetEffectsWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaGameplayEffect*> OutEffects;
	
	for (class AOmegaGameplayEffect* TempEffect : GetAllEffects())
	{
		if(TempEffect->IsValidLowLevel())
		{
			
			if (UOmegaGameFrameworkBPLibrary::GetObjectGameplayTags(TempEffect).HasAnyExact(Tags))
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
	
	for (class AOmegaGameplayEffect* TempEffect : GetAllEffects())
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
	for(AOmegaGameplayEffect* TempEffect : GetAllEffects())
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


void UCombatantComponent::RemoveEffectsWithTags(FGameplayTagContainer EffectTags)
{
	for(auto* TempEffect : GetEffectsWithTags(EffectTags))
	{
		TempEffect->K2_DestroyActor();
	}
}


///////////////////
/// Targeting ////
/////////////////

void UCombatantComponent::SetTargetRegistered(UCombatantComponent* Combatant, bool IsRegistered)
{
	if(Combatant)
	{
		bool _has = GetRegisteredTargetList().Contains(Combatant);
		if(IsRegistered && !_has)
		{
			target_list.Add(Combatant);
			Combatant->OnAddedAsTarget.Broadcast(Combatant,this,true);
			OnTargetAdded.Broadcast(this,Combatant,true);
		}
		else if(!IsRegistered && _has)
		{
			target_list.Remove(Combatant);
			Combatant->OnAddedAsTarget.Broadcast(Combatant,this,false);
			OnTargetAdded.Broadcast(this,Combatant,false);
		}
	}
}

void UCombatantComponent::SetTargetsRegistered(TArray<UCombatantComponent*> Combatants, bool IsRegistered,
	bool ClearListFirst)
{
	if(ClearListFirst)
	{
		ClearTargetList();
	}
	for(auto* c : Combatants)
	{
		if(c) { SetTargetRegistered(c,IsRegistered);}
	}
}


void UCombatantComponent::ClearTargetList()
{
	SetTargetsRegistered(target_list,false,false);
	target_list.Empty();
}

TArray<UCombatantComponent*> UCombatantComponent::GetRegisteredTargetList()
{
	TArray<UCombatantComponent*> LocalTargets;
	for(UCombatantComponent* TempEntry : target_list)
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
	target_active = Combatant;
	OnActiveTargetChanged.Broadcast(target_active, true);
}

UCombatantComponent* UCombatantComponent::GetActiveTarget() const
{
	if(target_active) { return target_active;}  return nullptr;
}


UCombatantComponent* UCombatantComponent::TryGetActiveTarget(bool& IsValid)
{
	if(target_active)
	{
		IsValid=true;
		return target_active;
	}
	IsValid=false;
	return nullptr;
}

int32 UCombatantComponent::GetActiveTargetIndex()
{
	if(UCombatantComponent* c=GetActiveTarget())
	{
		if(GetRegisteredTargetList().Contains(c))
		{
			return GetRegisteredTargetList().Find(c);
		}
	}
	return 0;
}

UCombatantComponent* UCombatantComponent::CycleActiveTarget(int32 Amount)
{
	//Get Start Index
	int32 StartIndex = GetActiveTargetIndex();
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
	if(GetActiveTarget())
	{
		target_active = nullptr;
		OnActiveTargetChanged.Broadcast(nullptr, false);
	}
}


void UCombatantComponent::CombatantNotify(FName Notify, const FString& Payload)
{
	OnCombatantNotify.Broadcast(this, Notify, Payload);
}


///////////////////
/// Faction ////
/////////////////

void UCombatantComponent::SetFaction_Asset(UOmegaFaction* Faction)
{
	UOmegaFaction* new_fact=nullptr;
	UOmegaFaction* old_fact=nullptr;
	if(Faction) {new_fact=Faction;}
	if(FactionDataAsset) {old_fact=FactionDataAsset;}
	FactionDataAsset=Faction;
	OnFactionChanged.Broadcast(this,new_fact,old_fact);
}

FText UCombatantComponent::GetFactionName()
{
	if(FactionDataAsset)
	{
		return FactionDataAsset->FactionName;
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
	return FLinearColor::White;
}

FGameplayTag UCombatantComponent::GetFactionTag()
{
	if(FactionDataAsset)
	{
		return FactionDataAsset->FactionTag;
	}
	return FGameplayTag();
}

TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> UCombatantComponent::GetFactionAffinities()
{
	TMap<FGameplayTag, TEnumAsByte<EFactionAffinity>> out;
	if(FactionDataAsset)
	{
		return FactionDataAsset->FactionAffinities;
	}
	return out;
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


TArray<UPrimaryDataAsset*> UCombatantComponent::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	return GetAllSkills();
}

bool UCombatantComponent::RunDefaultGambit()
{
	if(DefaultGambit)
	{
		return RunGambit(DefaultGambit);
	}
	return false;
}

bool UCombatantComponent::RunGambit(UCombatantGambitAsset* Gambit, bool bReplaceDefaultGambit)
{
	if(Gambit)
	{
		TSubclassOf<AOmegaAbility> IncomingAbility;
		UObject* IncomingContext;
		
		if(GetActionDataFromGambit(Gambit, IncomingAbility,IncomingContext))
		{
			bool WasSuccess;
			ExecuteAbility(IncomingAbility, IncomingContext,WasSuccess);
			if(WasSuccess)
			{
				return true;
			}
		}
	}
	return false;
}

bool UCombatantComponent::GetActionDataFromGambit(UCombatantGambitAsset* Gambit, TSubclassOf<AOmegaAbility>& Ability,
	UObject*& Context)
{
	if(Gambit)
	{
		for (auto* a :Gambit->GetAllGambitActions())
		{
			if(a)
			{
				
				if(a->CanRunGambit(this))
				{
					a->RunGambitAction(this,Ability,Context);
					return true;
				}
			}
		}
	}
	return false;
}


//##################################################################################################################
// Deprecated
//##################################################################################################################
	

// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Components/Component_Combatant.h"

#include "OmegaSettings.h"
#include "OmegaGameManager.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Actors/Actor_Ability.h"
#include "Actors/Actor_GameplayEffect.h"
#include "DataAssets/DA_CombatantGambits.h"
#include "Components/Component_Leveling.h"
#include "Subsystems/Subsystem_World.h"
#include "Interfaces/I_Combatant.h"
#include "DataAssets/DA_Attribute.h"
#include "DataAssets/DA_DamageType.h"
#include "DataAssets/DA_Faction.h"
#include "Components/PrimitiveComponent.h"
#include "Functions/F_Common.h"
#include "Functions/F_Entity.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"


float UCombatantComponent::L_ModifyDamage(UOmegaAttribute* Attribute,UCombatantComponent* Instigator,float BaseDamage,UOmegaDamageType* DamageType,UObject* Context)
{
	float FinalDamage = BaseDamage;
	
	if (Attribute)
	{
		UE_LOG(LogTemp, Log, TEXT("COMBATANT: Modifying damage to '%s' on attribute '%s' with starting value: '%f' "), *GetOwner()->GetName(),*Attribute->GetName(),FinalDamage);
		UOmegaGameManager* globSet=GetMutableDefault<UOmegaSettings>()->GetGameCore();
	
	
		FinalDamage=globSet->Combatant_ModifyDamage_PreMod(Attribute,this,Instigator,BaseDamage,DamageType,Context);
		UE_LOG(LogTemp, Log, TEXT("COMBATANT: 		---  Applying PRE SOURCE modifiers. Result: '%f' "),FinalDamage);
		
		UE_LOG(LogTemp, Log, TEXT("COMBATANT: 		---  Applying SOURCE modifiers."));
		for(auto* TempMod : GetDamageModifiers())
		{
			if (TempMod && TempMod->GetClass()->ImplementsInterface(UDataInterface_DamageModifier::StaticClass()))
			{
				FinalDamage = IDataInterface_DamageModifier::Execute_ModifyDamage(TempMod, Attribute, this, Instigator, FinalDamage, DamageType, Context); //Apply Damage Modifier
				UE_LOG(LogTemp, Log, TEXT("COMBATANT: 				-----  Applying SOURCE modifier from '%s' with result: %f."), *TempMod->GetName(), FinalDamage);
			}
		}
		
		FinalDamage=globSet->Combatant_ModifyDamage_PostMod(Attribute,this,Instigator,FinalDamage,DamageType,Context);
		UE_LOG(LogTemp, Log, TEXT("COMBATANT: 		---  Applying POST SOURCE modifiers. Result: '%f' "),FinalDamage);
	}
	
	return FinalDamage;
}

UCombatantComponent::UCombatantComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	ModiferToggle_Inventory.bModify_Attributes=false;
	ModiferToggle_Inventory.bModify_Damage=false;
	ModiferToggle_Inventory.bModify_Skill=false;
}

void UCombatantComponent::BeginPlay()
{
	Super::BeginPlay();
	
	OGF_CFG()->L_GetCombatantConfigFromActor(GetOwner()).Apply(this);
    
	auto* WorldSubsystem = GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
	if (WorldSubsystem)
	{
		WorldSubsystem->Native_RegisterCombatant(this, true);
	}
    
	ref_OwnerPawn = Cast<APawn>(GetOwner());
	
	SetAbilitiesGranted(GrantedAbilities,true);

	InitializeAttributes();
}

void UCombatantComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason == EEndPlayReason::Destroyed || EndPlayReason == EEndPlayReason::RemovedFromWorld)
	{
		GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->Native_RegisterCombatant(this, false);
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

void UCombatantComponent::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name,
	FText& Description)
{
	if(CombatantDataAsset && CombatantDataAsset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(CombatantDataAsset,Tag,Name,Description);	
	}
	if(GetOwner()->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataText(GetOwner(),Tag,Name,Description);	
	}
}

void UCombatantComponent::GetGeneralDataImages_Implementation(FGameplayTag Tag,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	if(CombatantDataAsset && CombatantDataAsset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataImages(CombatantDataAsset,Tag,Texture,Material,Brush);	
	}
	if(GetOwner()->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		IDataInterface_General::Execute_GetGeneralDataImages(GetOwner(),Tag,Texture,Material,Brush);	
	}
}

void UCombatantComponent::GetGeneralAssetColor_Implementation(FGameplayTag Tag,FLinearColor& Color)
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


void UCombatantComponent::SetOverrideAbilitySkelMesh(USkeletalMeshComponent* mesh)
{
	if (mesh)
	{
		Override_AbilitySkelMesh=mesh;
	}
	else
	{
		mesh=nullptr;
	}
}

////////////////////////////////////
////////// -- UPDATE DATA -- //////////
///////////////////////////////////
void UCombatantComponent::Update()
{
	if (blockUpdateCall.Num()>0) { return; }
	L_CacheAttributeMods();
	OnUpdated.Broadcast(this);
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
	if (AbilityClass)
	{
		if(AOmegaAbility* _ability = GetAbility(AbilityClass, bValidAbility))
		{
			_ability->ContextObject=Context;
			bSuccess=_ability->Native_Execute();
			return _ability;
		}
		OGF_Log::LogError("ABILITY - failed to execute :: could not get ability. possible not granted");
	}
	else
	{
		OGF_Log::LogError("ABILITY - failed to execute :: invalid class");
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

		//Apply Damage Modifiers
		FinalDamage=L_ModifyDamage(Attribute,Instigator,FinalDamage,DamageType,Context);

		//--------------------- FINISH AND APPLY ---------------------///
	
		CurrentValue = CurrentValue - FinalDamage;		//Deduct final damage value from current attribute value
		CurrentValue = FMath::Clamp(CurrentValue, 0.0f, MaxVal);		//Make sure the value does not go under 0 or exceed the max allowed value

		//FINALIZE
		L_GetEntityData()->Attributes.Add(Attribute, CurrentValue);
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
	TArray<UPrimaryDataAsset*> OutSkills = L_GetEntityData()->GetSkills();
	for(auto* TempSource : L_GetSources_Skill())
	{
		if (TempSource && TempSource->GetClass()->ImplementsInterface(UDataInterface_SkillSource::StaticClass()))
		{
			for(auto* TempSkill : IDataInterface_SkillSource::Execute_GetSkills(TempSource,this))
			{
				if(TempSkill)
				{
					OutSkills.Add(TempSkill);
				}
			}
		}
	}
	OutSkills.Append(GetMutableDefault<UOmegaSettings>()->GetGameCore()->Combatant_Append_Skills(this));
	return OutSkills;
}

void UCombatantComponent::AddSkill(UPrimaryDataAsset* Skill, bool Added)
{
	if(Skill)
	{
		bool has_interface=Skill->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass());
		if(Added)
		{
			L_GetEntityData()->Skills.Add(Skill);
			if(has_interface)
			{
				IDataInterface_Skill::Execute_OnSkillAddedToCombatant(Skill,this,true);
			}
		}
		else
		{
			L_GetEntityData()->Skills.Remove(Skill);
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

void UCombatantComponent::SetCombatantTagsActive(FGameplayTagContainer GameplayTags, bool TagsActive)
{
	if(TagsActive)
	{
		CombatantTags.AppendTags(GameplayTags);
	}
	else
	{
		CombatantTags.RemoveTags(GameplayTags);
	}
}

void UCombatantComponent::SetTagsActive(FGameplayTagContainer GameplayTags, bool TagsActive)
{
	if(TagsActive)
	{
		L_GetEntityData()->Tags.AppendTags(GameplayTags);
	}
	else
	{
		L_GetEntityData()->Tags.RemoveTags(GameplayTags);
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
	
	OutSkills.Append(L_GetModifierOfType(1));
	
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
	
	OutMods.Append(L_GetModifierOfType(2));
	
	return OutMods;
}

bool UCombatantComponent::CanApplyEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass, UObject* Context,
	FOmegaCommonMeta _meta)
{
	if (EffectClass)
	{
		AOmegaGameplayEffect* def=EffectClass.GetDefaultObject();
		for (AOmegaGameplayEffect* ef : GetAllEffects())
		{
			if (ef && ef->BlockEffects.HasAnyExact(def->EffectTags))
			{
				return false;
			}
		}
		
		if (EffectClass->GetDefaultObject<AOmegaGameplayEffect>()->EffectCanApply(this,Context,_meta))
		{
			return true;
		}
		
	}
	return false;
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
		CurrentValue = L_GetEntityData()->Attributes.FindOrAdd(Attribute);
	}
}


//Get Attribute Base Value
float UCombatantComponent::GetAttributeBaseValue(UOmegaAttribute* Attribute)
{
	int32 attribute_rank=GetAttributeLevel(Attribute);
	float _baseVal=Attribute->GetAttributeValue(Level, attribute_rank, AttributeValueCategory);
	_baseVal=OGF_GAME_CORE()->Attribute_GetMaxValue(this,Attribute,attribute_rank,_baseVal);
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
	if (Attribute)
	{
		OverrideMaxAttributes.Add(Attribute,Value);
		float _val=L_GetEntityData()->Attributes.FindOrAdd(Attribute);
		L_GetEntityData()->Attributes.Add(Attribute,UKismetMathLibrary::FClamp(_val,0,Value	));
		Update();	
	}
}

void UCombatantComponent::SetOverrideMaxAttributes(TMap<UOmegaAttribute*, float> Value)
{
	blockUpdateCall.Add(496);
	OverrideMaxAttributes=Value;
	TArray<UOmegaAttribute*> TempAttributes;
	Value.GetKeys(TempAttributes);
	for (UOmegaAttribute* TempAttribute : TempAttributes)
	{
		if (TempAttribute)
		{
			SetOverrideMaxAttribute(TempAttribute, Value[TempAttribute]);
		}
	}
	blockUpdateCall.Remove(496);
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

TMap<UOmegaAttribute*, float> UCombatantComponent::GetCurrentAttributeValues(bool bCurrent)
{
	TMap<UOmegaAttribute*, float> out;
	float CurVal;
	float MaxVal;
	TArray<UOmegaAttribute*> AttributeList; 
    if (AttributeSet)
    {
    	for (auto a : AttributeSet->GetAllAttributes())
    	{
    		GetAttributeValue(a,CurVal,MaxVal);
    		if (bCurrent)
    		{
    			out.Add(a,CurVal);
    		}
		    else
		    {
		    	out.Add(a,MaxVal);
		    }
    	}
    }
	
	return out;
}

void UCombatantComponent::SetCurrentAttributeValue(UOmegaAttribute* Attribute, float Value)
{
	if(Attribute)
	{
		L_GetEntityData()->Attributes.Add(Attribute,Value);
	}
	Update();
}

void UCombatantComponent::SetCurrentAttributeValues(TMap<UOmegaAttribute*, float> Values)
{
	TArray<UOmegaAttribute*> AssetList;
	Values.GetKeys(AssetList);
	for (auto a : AssetList)
	{
		if (a)
		{
			L_GetEntityData()->Attributes.Add(a,Values[a]);
		}
	}
	
	Update();
}

void UCombatantComponent::SetCombatantLevel(int32 NewLevel, bool ReinitializeStats)
{
	Level = NewLevel;

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
					L_GetEntityData()->Attributes.Add(TempAtt,DumVal*TempAtt->StartValuePercentage);	
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
	
	_mods.Append(L_GetModifierOfType(0));
	
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


class AOmegaGameplayEffect* UCombatantComponent::CreateEffect(TSubclassOf<AOmegaGameplayEffect> EffectClass,
	UCombatantComponent* Instigator, UObject* Context, FOmegaCommonMeta meta)
{
	if (EffectClass)
	{
		if (CanApplyEffect(EffectClass,Context,meta))
		{
			const FTransform SpawnWorldPoint = GetOwner()->GetActorTransform();
		
			if (AOmegaGameplayEffect* LocalEffect = GetWorld()->SpawnActorDeferred<AOmegaGameplayEffect>(EffectClass, SpawnWorldPoint, nullptr))
			{
				LocalEffect->SetOwner(GetOwner());
				LocalEffect->TargetedCombatant = this;
				LocalEffect->EffectContext = Context;
				LocalEffect->CombatantInstigator = Instigator;
				
				UGameplayStatics::FinishSpawningActor(LocalEffect, SpawnWorldPoint);
	
				LocalEffect->AttachToActor(GetOwner(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));
				LocalEffect->EffectBeginPlay(Context,meta);
				Update();
				return LocalEffect;
			}
		}
		
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

void UCombatantComponent::OnInputAction_Begin_Implementation(APlayerController* Player, FGameplayTag Action,
	FVector axis)
{
	for (auto* a : GetGrantedAbilities())
	{
		if (Action==a->LinkedInputAction)
		{
			//OGF_Log::LogInfo("ABILITY - executing via input ::"+a->GetName());
			a->Execute(this);	
		}
		IDataInterface_InputAction::Execute_OnInputAction_Begin(a,Player,Action,axis);
	}
}

void UCombatantComponent::OnInputAction_Update_Implementation(APlayerController* Player, FGameplayTag Action,
	float DeltaTime, FVector axis)
{
	for (auto* a : GetGrantedAbilities())
	{
		IDataInterface_InputAction::Execute_OnInputAction_Update(a,Player,Action,DeltaTime,axis);
	}
}

void UCombatantComponent::OnInputAction_End_Implementation(APlayerController* Player, FGameplayTag Action, FVector axis)
{
	for (auto* a : GetGrantedAbilities())
	{
		if (Action==a->LinkedInputAction && a->bStopAbilityOnInputActionEnd)
		{
			a->CancelAbility();	
		}
		IDataInterface_InputAction::Execute_OnInputAction_End(a,Player,Action,axis);
	}
}

FOmegaEntity* UCombatantComponent::L_GetEntityData()
{
	if (use_entity_id)
	{
		if (FOmegaEntity* EntityData = UOmegaFunctions_Entity::getEntityRefById(this,entity_id,false))
		{
			return EntityData;
		}
	}
	return &entity_data;
}

FOmegaEntity_AssetData* UCombatantComponent::L_GetEntity_AssetData(UPrimaryDataAsset* asset)
{
	if (asset)
	{
		return &L_GetEntityData()->AssetData.FindOrAdd(asset);
	}
	return nullptr;
}

TArray<UPrimaryDataAsset*> UCombatantComponent::L_GetEntity_AssetsSaved()
{
	TArray<UPrimaryDataAsset*> out;
	
	if(FOmegaEntity* dat=L_GetEntityData())
	{
		return dat->GetAssetDataList();
	}
	
	return out;
}

TArray<UObject*> UCombatantComponent::L_AppendModifiers(TArray<UObject*> current, TArray<UObject*> to_append,
                                                        uint8 type, FOmegaCombatantModifierToggles toggles)
{
	bool can_append = false;
	if (type==0) { can_append=toggles.bModify_Attributes; }
	if (type==1) { can_append=toggles.bModify_Skill; }
	if (type==2) { can_append=toggles.bModify_Damage; }

	TArray<UObject*> out=current;
	if (can_append)
	{
		out.Append(to_append);
	}
	return out;
}

TArray<UObject*> UCombatantComponent::L_GetModifierOfType(uint8 type)
{
	TArray<UObject*> base;

	base=L_AppendModifiers(base,TArray<UObject*>(Equipment_GetEquipList()),type,ModiferToggle_Equipment);
	//base=L_AppendModifiers(base,TArray<UObject*>(Equipment_GetEquipList()),type,ModiferToggle_Inventory);
	
	return base;
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

// ------------------------------------------------------------------------------------------
// EQUIPMENT
// ------------------------------------------------------------------------------------------

TMap<UEquipmentSlot*, UPrimaryDataAsset*> UCombatantComponent::Equipment_Get()
{
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> out=OGF_GAME_CORE()->Equipment_Append(this);
	out.Append(L_GetEntityData()->Equipment);
	return out;
}

TArray<UPrimaryDataAsset*> UCombatantComponent::Equipment_GetEquipList()
{
	TArray<UEquipmentSlot*> eq;
	Equipment_Get().GetKeys(eq);
	
	TArray<UPrimaryDataAsset*> out;
	for (auto* i : eq)
	{
		if (i)
		{
			out.Add(Equipment_Get().FindOrAdd(i));
		}
	}
	
	return out;
}

UPrimaryDataAsset* UCombatantComponent::Equipment_GetInSlot(UEquipmentSlot* Slot, bool& result)
{
	result=false;
	if (UPrimaryDataAsset* _item=Equipment_Get().FindOrAdd(Slot))
	{
		result=true;
		return _item;
	}
	return nullptr;
}

void UCombatantComponent::Equipment_SetInSlot(UPrimaryDataAsset* Item, UEquipmentSlot* Slot)
{
	blockUpdateCall.Add(2001);
	if (Slot)
	{
		Equipment_ClearSlot(Slot);
		if(Item)
		{
			L_GetEntityData()->Equipment[Slot]=Item;	
			OnSlot_Equip.Broadcast(this,Slot,Item);
		}
	}
	blockUpdateCall.Remove(2001);
	Update();
}

void UCombatantComponent::Equipment_SetAll(TMap<UEquipmentSlot*, UPrimaryDataAsset*> equipment)
{
	L_GetEntityData()->Equipment=equipment;
	Update();
}

void UCombatantComponent::Equipment_ClearSlot(UEquipmentSlot* Slot)
{
	if (Slot)
	{
		bool _res;
		if (UPrimaryDataAsset* _item=Equipment_GetInSlot(Slot,_res))
		{
			OnSlot_Unequip.Broadcast(this,Slot,_item);
		}
		L_GetEntityData()->Equipment.Add(Slot,nullptr);
		
		Update();
	}
}

bool UCombatantComponent::Equipment_CanSetInSlot(UPrimaryDataAsset* Item, UEquipmentSlot* Slot)
{
	return true;
}

// ------------------------------------------------------------------------------------------
// INVENTORY
// ------------------------------------------------------------------------------------------

bool UCombatantComponent::Inventory_Add(UPrimaryDataAsset* Item, int32 amount)
{
	if (Item)
	{
		int32 _newAmount=amount+Inventory_GetAmount(Item);
		L_GetEntityData()->Inventory.Add(Item,_newAmount);
		OnInventoryEdit.Broadcast(this,Item,amount);
		Update();
		return true;
	}
	return false;
}

void UCombatantComponent::Inventory_AddList(TMap<UPrimaryDataAsset*, int32> Assets, bool bInvertAmount)
{
	blockUpdateCall.Add(3001);
	TArray<UPrimaryDataAsset*> asset_keys;
	Assets.GetKeys(asset_keys);
	for(auto* i : asset_keys)
	{
		int32 multiplier=1;
		if(bInvertAmount) {multiplier=-1;}
		Inventory_Add(i,Assets[i]*multiplier);
	}
	blockUpdateCall.Remove(3001);
	Update();
}

void UCombatantComponent::Inventory_Transfer(UCombatantComponent* To, UPrimaryDataAsset* Asset, int32 Amount,
                                             bool bTransferAll)
{
	if(!Asset || !To)
	{
		return;
	}
	int32 AmountToRemove = Amount;
	if(bTransferAll)
	{
		AmountToRemove = Inventory_GetAmount(Asset);
	}
	else
	{
		AmountToRemove = UKismetMathLibrary::Clamp(AmountToRemove, 0, Inventory_GetAmount(Asset));
	}

	//Transfer
	blockUpdateCall.Add(3002);
	Inventory_Add(Asset, AmountToRemove*-1);
	To->Inventory_Add(Asset, AmountToRemove);
	blockUpdateCall.Remove(3002);
	Update();
}

void UCombatantComponent::Inventory_TransferAll(UCombatantComponent* To)
{
	TArray<UPrimaryDataAsset*> AssetListLocal;
	Inventory_Get().GetKeys(AssetListLocal);

	blockUpdateCall.Add(3003);
	for(auto* TempAsset : AssetListLocal)
	{
		Inventory_Transfer(To, TempAsset, 0, true);
	}
	
	blockUpdateCall.Remove(3003);
	Update();
}

void UCombatantComponent::Inventory_Set(TMap<UPrimaryDataAsset*, int32> map,bool bClearFirst)
{
	blockUpdateCall.Add(3004);
	if (bClearFirst)
	{
		Inventory_Clear();	
	}
	TArray<UPrimaryDataAsset*> temp;
	map.GetKeys(temp);
	for(auto i : temp)
	{
		if (i)
		{
			L_GetEntityData()->Inventory.Append(map);		
		}
	}
	blockUpdateCall.Remove(3004);
	Update();
}

void UCombatantComponent::Inventory_Clear()
{
	L_GetEntityData()->Inventory.Empty();
	OnInventoryEdit.Broadcast(this,nullptr,0);
	Update();
}

TMap<UPrimaryDataAsset*, int32> UCombatantComponent::Inventory_Get(int32 Minimum)
{
	TMap<UPrimaryDataAsset*, int32> out;
	
	if (FOmegaEntity* e=L_GetEntityData())
	{
		TArray<UPrimaryDataAsset*> item_list;
		e->Inventory.GetKeys(item_list);
		for (UPrimaryDataAsset* a : item_list)
		{
			if (a)
			{
				if (Inventory_GetAmount(a)>=Minimum)
				{
					out.Add(a);
				}
			}
		}
	}
	
	return out;
}

int32 UCombatantComponent::Inventory_GetAmount(UPrimaryDataAsset* Item)
{
	if (Item)
	{
		if (L_GetEntityData()->Inventory.Contains(Item))
		{
			return L_GetEntityData()->Inventory.FindOrAdd(Item);	
		}
	}
	return 0;
}

TArray<UPrimaryDataAsset*> UCombatantComponent::Inventory_GetItemsAsArray()
{
	TArray<UPrimaryDataAsset*> out;
	Inventory_Get().GetKeys(out);
	return out;
}

bool UCombatantComponent::Inventory_HasMinimum(TMap<UPrimaryDataAsset*, int32> Assets)
{
	TArray<UPrimaryDataAsset*> temp;
	Assets.GetKeys(temp);
	for (auto* a : temp)
	{
		if (a)
		{
			int32 i_amount=Inventory_GetAmount(a);
			if (i_amount<Assets[a])
			{
				return false;
			}
		}
	}
	return true;
}

// ------------------------------------------------------------------------------------------
// LEVELING
// ------------------------------------------------------------------------------------------

void UCombatantComponent::XP_Set(UOmegaLevelingAsset* Type, float amount, bool bAdded)
{
	if (Type)
	{
		blockUpdateCall.Add(4001);
		int32 cur_level=XP_GetLevel(Type);
		float _cur=XP_Get(Type);
		float base=amount;
		if (bAdded)
		{
			base+=_cur;
		}
		L_GetEntityData()->Attributes.Add(Type,base);
		OnXpChanged.Broadcast(this,Type,_cur,base);
		
		int32 new_lvl=XP_GetLevel(Type);
		if (cur_level!=new_lvl)
		{
			OnLevelChanged.Broadcast(this,Type,cur_level,new_lvl);
		}
		blockUpdateCall.Remove(4001);
		Update();
	}
}

void UCombatantComponent::XP_SetAll(TMap<UOmegaLevelingAsset*, float> XP, bool bAdded)
{
	TArray<UOmegaLevelingAsset*> temps;
	blockUpdateCall.Add(4020);
	for (auto a : temps)
	{
		if (a)
		{
			XP_Set(a,XP[a],bAdded);
		}
	}
	blockUpdateCall.Remove(4020);
	Update();
}

void UCombatantComponent::XP_SetLevel(UOmegaLevelingAsset* Type, int32 NewLevel)
{
	if (Type)
	{
		blockUpdateCall.Add(4002);
		float _min , _max; 
		Type->GetXPFromLevel(NewLevel,_min,_max);
		XP_Set(Type,_min,false);
		blockUpdateCall.Remove(4002);
		Update();
	}
}


TMap<UOmegaLevelingAsset*, float> UCombatantComponent::XP_GetAll()
{
	TMap<UOmegaLevelingAsset*, float> out;
	TArray<UPrimaryDataAsset*> AssetList;
	L_GetEntityData()->Attributes.GetKeys(AssetList);
	for (auto a : AssetList)
	{
		if (a && a->GetClass()->IsChildOf(UOmegaLevelingAsset::StaticClass()))
		{
			out.Add(Cast<UOmegaLevelingAsset>(a),L_GetEntityData()->Attributes.FindOrAdd(a));
		}
	}
	return out;
}

float UCombatantComponent::XP_Get(UOmegaLevelingAsset* Type)
{
	return XP_GetAll().FindOrAdd(Type);
}

void UCombatantComponent::XP_GetValues(UOmegaLevelingAsset* Type, float& LevelMin, float& LevelMax, float& Percent)
{
	if (Type)
	{
		int32 _lvl=XP_GetLevel(Type);
		Type->GetXPFromLevel(_lvl,LevelMin,LevelMax);
		float _cur=XP_Get(Type);
		Percent=(_cur-LevelMin)/(LevelMax-LevelMin);
	}
}

int32 UCombatantComponent::XP_GetLevel(UOmegaLevelingAsset* Type)
{
	if (Type)
	{
		return Type->GetLevelFromXP(XP_Get(Type));
	}
	return 0;
}
	
// ------------------------------------------------------------------------------------------
// Asset Tags
// ------------------------------------------------------------------------------------------

void UCombatantComponent::AssetLink_RemoveAllTags(UPrimaryDataAsset* Asset)
{
	if (Asset)
	{
		L_GetEntity_AssetData(Asset)->GameplayTags=FGameplayTagContainer();
	}
}

void UCombatantComponent::AssetLink_SetTagsActive(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags,
	bool bTagsActive)
{
	if (Asset)
	{
		if (bTagsActive)
		{
			L_GetEntity_AssetData(Asset)->GameplayTags.AppendTags(Tags);
		}
		else
		{
			L_GetEntity_AssetData(Asset)->GameplayTags.RemoveTags(Tags);
		}
	}
}

FGameplayTagContainer UCombatantComponent::AssetLink_GetActiveTags(UPrimaryDataAsset* Asset)
{
	if (Asset)
	{
		return L_GetEntity_AssetData(Asset)->GameplayTags;	
	}
	return FGameplayTagContainer();
}
	
// ------------------------------------------------------------------------------------------
// Param 
// ------------------------------------------------------------------------------------------

void UCombatantComponent::EntityParam_Bool_Set(FName Param, bool Value)
{
	L_GetEntityData()->params_int32.Add(Param,Value);
}

bool UCombatantComponent::EntityParam_Bool_Get(FName Param)
{
	return L_GetEntityData()->params_int32.FindOrAdd(Param)>0;
}

void UCombatantComponent::EntityParam_Int_Set(FName Param, int32 Value, bool bAdded)
{
	int32 _target=Value;
	if (bAdded)
	{
		_target+=EntityParam_Int_Get(Param);
	}
	L_GetEntityData()->params_int32.Add(Param,_target);
}

int32 UCombatantComponent::EntityParam_Int_Get(FName Param)
{
	return L_GetEntityData()->params_int32.FindOrAdd(Param);
}


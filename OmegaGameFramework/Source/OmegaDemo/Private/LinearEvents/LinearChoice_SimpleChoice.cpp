// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearChoice_SimpleChoice.h"

bool ULinearChoice_SimpleChoice::IsChoiceAvailable_Implementation() const
{
	return UOmegaFunctions_GlobalScripting::RunGlobalConditions(this,Conditions);
}
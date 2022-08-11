// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataSettings.h"

UOmegaDataSettings::UOmegaDataSettings()
{
	FDirectoryPath LocalPath;
	LocalPath.Path = "/Game/";
	DataItemScansPath.Add(LocalPath);
}

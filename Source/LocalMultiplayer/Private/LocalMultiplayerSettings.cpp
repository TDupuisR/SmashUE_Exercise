// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMultiplayerSettings.h"

bool FLocalMultiplayerProfileData::ContainsKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const
{
	UInputMappingContext* CurrentMappingType = GetIMCFromType(MappingType);
	if (CurrentMappingType == nullptr)
		return false;

	TArray<FEnhancedActionKeyMapping> Mappings = CurrentMappingType->GetMappings();

	for (int16 i = 0; i < Mappings.Num(); i++)
	{
		if (Mappings[i].Key == Key)
			return true;
	}

	return false;
}

UInputMappingContext* FLocalMultiplayerProfileData::GetIMCFromType(ELocalMultiplayerInputMappingType MappingType) const
{
	switch (MappingType)
	{
	case ELocalMultiplayerInputMappingType::InGame:
		return IMCGames;
	case ELocalMultiplayerInputMappingType::Menu:
		return IMCMenu;
	default:
		return nullptr;
	}
}

int ULocalMultiplayerSettings::GetNbKeyboardProfiles() const
{
	return KeyboardProfilesData.Num();
}

int ULocalMultiplayerSettings::FindKeyboardProfileIndexFromKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const
{
	for (int16 i = 0; i < KeyboardProfilesData.Num(); i++)
	{
		if(KeyboardProfilesData[i].ContainsKey(Key, MappingType))
			return i;
	}
	
	return -1;
}

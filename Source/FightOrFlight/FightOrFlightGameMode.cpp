// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FightOrFlightGameMode.h"
#include "FightOrFlightHUD.h"
#include "FightOrFlightCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFightOrFlightGameMode::AFightOrFlightGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFightOrFlightHUD::StaticClass();
}

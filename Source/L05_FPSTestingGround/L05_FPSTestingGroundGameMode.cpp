// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "L05_FPSTestingGround.h"
#include "L05_FPSTestingGroundGameMode.h"
#include "L05_FPSTestingGroundHUD.h"
#include "Player/FirstPersonCharacter.h"

AL05_FPSTestingGroundGameMode::AL05_FPSTestingGroundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Player/Behavior/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AL05_FPSTestingGroundHUD::StaticClass();
}

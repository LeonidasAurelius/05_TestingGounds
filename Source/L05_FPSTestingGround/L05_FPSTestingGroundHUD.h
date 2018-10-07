// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "L05_FPSTestingGroundHUD.generated.h"

UCLASS()
class AL05_FPSTestingGroundHUD : public AHUD
{
	GENERATED_BODY()

public:
	AL05_FPSTestingGroundHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


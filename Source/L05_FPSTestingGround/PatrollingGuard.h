// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class L05_FPSTESTINGGROUND_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
public:
	GENERATED_BODY()
		UPROPERTY(EditInstanceOnly, Category = "PatrolRoute")
		TArray<AActor*> PatrolPointsCPP;

};

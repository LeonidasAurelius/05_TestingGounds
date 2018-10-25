// Fill out your copyright notice in the Description page of Project Settings.

#include "L05_FPSTestingGround.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	//UE_LOG(LogTemp, Warning, TEXT("AI in C++!!!!!"));
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) {
		return EBTNodeResult::Failed;
	}

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("Someone is missing patrol points"));
		return EBTNodeResult::Failed;
	}

	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackBoardComp){
		UE_LOG(LogTemp, Warning, TEXT("No actor component"));
		return EBTNodeResult::Failed;
	}
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	auto WayPoint = BlackBoardComp->GetValueAsInt(WaypointKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("IndexKey = %i, name = %s"), Index, *IndexKey.SelectedKeyName.ToString());
	UE_LOG(LogTemp, Warning, TEXT("WaypointKey = %i, name = %s"), WayPoint, *WaypointKey.SelectedKeyName.ToString());
	return EBTNodeResult::Succeeded;
}



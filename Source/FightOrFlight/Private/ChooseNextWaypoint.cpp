// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ChooseNextWaypoint.h"
#include "Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Classes/BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)  
{
	// Get AI Setup
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(NextWaypointIndex.SelectedKeyName);
	auto AIController = OwnerComp.GetAIOwner();

	auto PatrolRoute = AIController->GetPawn()->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	auto PatrolguardWaypoints = PatrolRoute->GetPatrolPoints();
	
	if (PatrolguardWaypoints.Num() == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Waypoints"));
		return EBTNodeResult::Failed;
	}

	// Set Next Waypoint
	BlackboardComp->SetValueAsObject(BlackboardWayPoint.SelectedKeyName, PatrolguardWaypoints[Index] );

	// Cycle Index
	auto NextIndex = (Index+1) % (PatrolguardWaypoints.Num());
	BlackboardComp->SetValueAsInt(NextWaypointIndex.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}

//UE_LOG(LogTemp, Warning, TEXT("%i is waypoint index"), Index);
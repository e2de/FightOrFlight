// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ChooseNextWaypoint.h"
#include "Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Classes/BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)  
{
	auto EBTResult = EBTNodeResult::Succeeded;

	// Get Patrol Points
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	
	auto Index = BlackboardComp->GetValueAsInt(NextWaypointIndex.SelectedKeyName);

	// Set Next Waypoint

	// Cycle Index

	// UE_LOG(LogTemp, Warning, TEXT("%i is waypoint index"), Index);

	return EBTResult;
}
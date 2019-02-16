// Copyright 2019 Alice Meng

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTORFLIGHT_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Setup")
	TArray <AActor *> PatrolPoints;
};

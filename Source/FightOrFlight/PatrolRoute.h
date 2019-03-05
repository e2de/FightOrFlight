// Copyright 2019 Alice Meng

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIGHTORFLIGHT_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public: 
	TArray <AActor *> GetPatrolPoints() const;

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		TArray <AActor *> PatrolPoints;
};



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewActor.generated.h"

UCLASS()
class TRIAL2_API ANewActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

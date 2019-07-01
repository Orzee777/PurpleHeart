#pragma once

#include <fstream>
#include <iostream>
#include "FileHelper.h"
#include "Paths.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataCollectionActor.generated.h" // must be last


UCLASS()
class TRIAL2_API ADataCollectionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADataCollectionActor();
	void writeToFile(FString filePath, FString content);

	void rewriteFile(FString filePath, FString content);

	int getParticipantNumber(FString inputFilePath);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
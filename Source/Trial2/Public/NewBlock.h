#pragma once

#include <algorithm>
#include <vector>
#include <random>
#include "DataFunctions.h"
#include "Trial.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewBlock.generated.h"

UCLASS()
class TRIAL2_API ANewBlock : public AActor
{
	GENERATED_BODY()

private:
	static std::vector<Trial> block;
	static int blockNumber;
	static int currentTrialNumber;		// total Trial Number overall
	static int blockTrialNumber;		// Trial Number of current Block
	static float startReactionTime;
	static float endReactionTime;
	static int participantNumber;		// participant number from NewParticipant

	static FString logPathLocation;
	
public:	
	// Sets default values for this actor's properties
	ANewBlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString printBlock();

	void numberTrials();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static int getCurrentTrialNumber();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static void setCurrentTrialNumber(int num);

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static FString getStimulus();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static FString getColor();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static void getResponse(int response, float end);

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static bool isNextTrial();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static bool isBreak(int count);

	// used in dataFunctions.cpp
	UFUNCTION(BlueprintCallable, Category = "Trial")
	static FString getStats();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static void startTimer(float start);

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static float getStartReactionTime();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static bool isCorrect(int response);

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static int getBlockNumber();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static void incrementBlockNumber();

	UFUNCTION(BlueprintCallable, Category = "Participant")
	static void getParticipantNumberForBlock(int pn);

	UFUNCTION(BlueprintCallable, Category = "Participant")
	static void initializeLogFile();
};

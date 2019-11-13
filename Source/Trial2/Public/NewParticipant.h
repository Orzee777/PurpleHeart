#pragma once

#include <vector>
#include "NewBlock.h"
#include "DataFunctions.h"
#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewParticipant.generated.h"

UCLASS()
class TRIAL2_API ANewParticipant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewParticipant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
private:
	static int participantNumber;
	static FString dataPathLocation;
	static int currentBlock;
	static std::vector<ANewBlock> allBlocks;
public:
	// accuracy of participant so far (100.00%)
	float participantAccuracy = 0;

	// reaction time of the participant in milliseconds
	int participantRT = 0;

	// total number of correct answers so far
	int participantCorrect = 0;

	// total number of trials so far
	int participantTotal = 0;

	UFUNCTION(Blueprintcallable, Category = "Participant")
	static void setParticipantNumber(int number);
	UFUNCTION(Blueprintcallable, Category = "Participant")
	static void changeParticipantNumber(int number);
	UFUNCTION(Blueprintcallable, Category = "Participant")
	static int getParticipantNumber();

	FString printStats();
	FString printAllBlocks();

	void printParticipant();

	UFUNCTION(BlueprintCallable, Category = "Participant")
	static int retrieveParticipantNumber();

	UFUNCTION(BlueprintCallable, Category = "Participant")
	static void writeTrialStats();

	UFUNCTION(BlueprintCallable, Category = "Participant")
	static void setupData();

};

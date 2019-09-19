#pragma once

#include <vector>
#include "Block.h"
#include "DataFunctions.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Participant.generated.h"

UCLASS()
class TRIAL2_API UParticipant : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		/*
private:
	int participantNumber;
	int currentBlock = 0;
	static std::vector<UBlock> allBlocks;
public:
	UParticipant();
	~UParticipant();

	// accuracy of participant so far (100.00%)
	float participantAccuracy = 0;

	// reaction time of the participant in milliseconds
	int participantRT = 0;

	// total number of correct answers so far
	int participantCorrect = 0;

	// total number of trials so far
	int participantTotal = 0;

	void setParticipantNumber(int number);
	int getParticipantNumber();

	void incrementCurrentBlock();
	int getCurrentBlock();

	FString printStats();
	FString printAllBlocks();

	void printParticipant();
	*/
};

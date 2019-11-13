#include "Public/NewParticipant.h"

std::vector<ANewBlock> ANewParticipant::allBlocks;
int ANewParticipant::currentBlock = 0;
int ANewParticipant::participantNumber;
FString ANewParticipant::dataPathLocation = FString(FPlatformProcess::UserDir()) + "\\GameData\\";

// Called when the game starts or when spawned
void ANewParticipant::BeginPlay()
{
	Super::BeginPlay();
	
}

ANewParticipant::ANewParticipant() {
	//ANewBlock* block1Pointer = NewObject<ANewBlock>();
	//UDatabaseCommunicatorModel* Model = Cast(Query->QueryModel);
	//allBlocks.push_back(block1);
}

void ANewParticipant::setParticipantNumber(int number) {
	participantNumber = number;
}

void ANewParticipant::changeParticipantNumber(int number) {
	participantNumber = number;
	rewriteParticipantNumber(dataPathLocation + "dataInputFile.txt", number);
}

int ANewParticipant::getParticipantNumber() {
	return participantNumber;
}

FString ANewParticipant::printAllBlocks() {
	FString output = "* Participant " + FString::FromInt(participantNumber) + " Data *" + "\n";

	for (int i = 0; i < allBlocks.size(); i++) {
		output += allBlocks[i].printBlock();
	}

	output += "* Participant " + FString::FromInt(participantNumber) + " Data Completed -\n";

	return output;
}

FString ANewParticipant::printStats() {
	FString output = "\nSTATS\nAccuracy: "
		+ FString::SanitizeFloat(participantAccuracy) + "%\nReaction Time: "
		+ FString::FromInt(participantRT) + "ms\nCorrect: " + FString::FromInt(participantCorrect) + " / " + FString::FromInt(participantTotal) + "\n";

	return output;
}

void ANewParticipant::printParticipant() {
	FString filePath = "participant" + FString::FromInt(participantNumber);
	FString content = printAllBlocks() + printStats();
	rewriteFile(filePath, content);
}

int ANewParticipant::retrieveParticipantNumber() {
	return getParticipantNumberFromFile(dataPathLocation + "dataInputFile.txt");
}

void ANewParticipant::writeTrialStats() {
	FString content = "\n" + ANewBlock::getStats();
	writeToFile(dataPathLocation + "\\v1.0.0\\Stats\\PN" + FString::FromInt(participantNumber) + "stats.txt", content);
}

// setupData is called after initializing the participant
// Unreal automatically calls the initializer upon compile and creates a number of issues
void ANewParticipant::setupData() {
	participantNumber = getParticipantNumberFromFile(dataPathLocation + "dataInputFile.txt");
	incrementParticipantNumber(dataPathLocation + "dataInputFile.txt");

	createStatsFile(dataPathLocation + "\\v1.0.0\\Stats\\", "PN" + FString::FromInt(participantNumber) + "stats.txt");
}
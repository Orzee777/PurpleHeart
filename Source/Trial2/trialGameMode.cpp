#include "trialGameMode.h"

std::vector<UBlock> AtrialGameMode::allBlocks;

void AtrialGameMode::BeginPlay() {
	Super::BeginPlay();
}

AtrialGameMode::AtrialGameMode() {
	FString inputFileName = "C:\\Users\\bradi\\Desktop\\dataInputFile.txt";
	
	getParticipantNumberFromFile(inputFileName);
	incrementParticipantNumber(inputFileName);


	//createStatsFile("C:\\Users\\bradi\\Desktop\\dataInfo", "PN" + pnFile);
	//UBlock* block1Pointer = NewObject<UBlock>();
	//UDatabaseCommunicatorModel* Model = Cast(Query->QueryModel);
	//allBlocks.push_back(block1);
}

void AtrialGameMode::setParticipantNumber(int number) {
	participantNumber = number;
}

int AtrialGameMode::getParticipantNumber() {
	return this->participantNumber;
}

void AtrialGameMode::incrementCurrentBlock() {
	currentBlock = currentBlock++;
}

int AtrialGameMode::getCurrentBlock() {
	return this->currentBlock;
}

FString AtrialGameMode::printAllBlocks() {
	FString output = "* Participant " + FString::FromInt(participantNumber) + " Data *" + "\n";

	for (int i = 0; i < allBlocks.size(); i++) {
		output += allBlocks[i].printBlock();
	}

	output += "* Participant " + FString::FromInt(participantNumber) + " Data Completed -\n";

	return output;
}

FString AtrialGameMode::printStats() {
	FString output = "\nSTATS\nAccuracy: "
		+ FString::SanitizeFloat(participantAccuracy) + "%\nReaction Time: "
		+ FString::FromInt(participantRT) + "ms\nCorrect: " + FString::FromInt(participantCorrect) + " / " + FString::FromInt(participantTotal) + "\n";

	return output;
}

void AtrialGameMode::printParticipant() {
	FString filePath = "participant" + FString::FromInt(participantNumber);
	FString content = printAllBlocks() + printStats();
	rewriteFile(filePath, content);
}

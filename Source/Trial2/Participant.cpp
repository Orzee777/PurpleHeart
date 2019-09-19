#include "Participant.h"
/*
std::vector<UBlock> UParticipant::allBlocks;

UParticipant::UParticipant() {
	FString inputFileName = "dataInputFile.txt";
	FString pnFile, result, left, right;
	FFileHelper::LoadFileToString(result, *inputFileName);
	int index = result.Find("PN ");
	left = result.Left(index);
	right = result.RightChop(index);
	result = result.RightChop(index);
	result = result.Left(4);
	participantNumber = FCString::Atoi(*result);
	pnFile = FString::FromInt(participantNumber + 1);
	for (int i = 0; i > pnFile.Len() - 4; i++) {
		pnFile = "0" + pnFile;
	}
	rewriteFile(inputFileName, left + pnFile + right);

	//participantNumber = getParticipantNumberFromFile(inputFileName);

	
	createStatsFile("C:\\Users\\bradi\\Desktop\\dataInfo", "PN" + pnFile);
	//UBlock* block1Pointer = NewObject<UBlock>();
	//UDatabaseCommunicatorModel* Model = Cast(Query->QueryModel);
	//allBlocks.push_back(block1);
}

UParticipant::~UParticipant() {}

void UParticipant::setParticipantNumber(int number) {
	participantNumber = number;
}

int UParticipant::getParticipantNumber() {
	return this->participantNumber;
}

void UParticipant::incrementCurrentBlock() {
	currentBlock = currentBlock++;
}

int UParticipant::getCurrentBlock() {
	return this->currentBlock;
}

FString UParticipant::printAllBlocks() {
	FString output = "* Participant " + FString::FromInt(participantNumber) + " Data *" + "\n";

	for (int i = 0; i < allBlocks.size(); i++) {
		output += allBlocks[i].printBlock();
	}

	output += "* Participant " + FString::FromInt(participantNumber) + " Data Completed -\n";

	return output;
}

FString UParticipant::printStats() {
	FString output = "\nSTATS\nAccuracy: " 
		+ FString::SanitizeFloat(participantAccuracy) + "%\nReaction Time: "
		+ FString::FromInt(participantRT) + "ms\nCorrect: " + FString::FromInt(participantCorrect) + " / " + FString::FromInt(participantTotal) + "\n";

	return output;
}

void UParticipant::printParticipant() {
	FString filePath = "participant" + FString::FromInt(participantNumber);
	FString content = printAllBlocks() + printStats();
	rewriteFile(filePath, content);
}
*/
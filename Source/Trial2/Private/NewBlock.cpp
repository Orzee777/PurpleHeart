#include "Public/NewBlock.h"

std::vector<Trial> ANewBlock::block;
int ANewBlock::blockNumber;
int ANewBlock::currentTrialNumber = 0;
int ANewBlock::blockTrialNumber;
int ANewBlock::participantNumber;
float ANewBlock::startReactionTime;
float ANewBlock::endReactionTime;
FString ANewBlock::logPathLocation = FString(FPlatformProcess::UserDir()) + "\\GameData\\v1.0.0\\Logs\\PN";

// Sets default values
ANewBlock::ANewBlock()
{

	blockNumber++;

	Trial red1("red", "red");
	Trial red2("red", "blue");
	Trial red3("red", "green");
	Trial red4("red", "yellow");

	Trial blue1("blue", "red");
	Trial blue2("blue", "blue");
	Trial blue3("blue", "green");
	Trial blue4("blue", "yellow");

	Trial green1("green", "red");
	Trial green2("green", "blue");
	Trial green3("green", "green");
	Trial green4("green", "yellow");

	Trial yellow1("yellow", "red");
	Trial yellow2("yellow", "blue");
	Trial yellow3("yellow", "green");
	Trial yellow4("yellow", "yellow");
	

	for (int i = 0; i < 8; i++) {
		
		block.push_back(red1);
		block.push_back(red2);
		block.push_back(red3);
		block.push_back(red4);
		block.push_back(blue1);
		block.push_back(blue2);
		block.push_back(blue3);
		block.push_back(blue4);
		block.push_back(green1);
		block.push_back(green2);
		block.push_back(green3);
		block.push_back(green4);
		block.push_back(yellow1);
		block.push_back(yellow2);
		block.push_back(yellow3);
		block.push_back(yellow4);

		// match congruent and incongruent trials

		block.push_back(red1);
		block.push_back(red1);
		block.push_back(blue2);
		block.push_back(blue2);
		block.push_back(green3);
		block.push_back(green3);
		block.push_back(yellow4);
		block.push_back(yellow4);
	}
	std::shuffle(std::begin(block), std::end(block), std::default_random_engine());

	numberTrials();

	currentTrialNumber = 0;
	blockTrialNumber = 0;
}

// Called when the game starts or when spawned
void ANewBlock::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANewBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FString ANewBlock::printBlock() {
	FString output = "- Block " + FString::FromInt(blockNumber) + " Start -" + "\n";

	for (int i = 0; i < block.size(); i++) {
		output += block[i].printTrial();
	}

	output += "- Block " + FString::FromInt(blockNumber) + " End -\n";

	return output;
}

void ANewBlock::numberTrials() {
	for (int i = 0; i < block.size(); i++) {
		block[i].setTrialNumber(i + 1);
	}
}

int ANewBlock::getCurrentTrialNumber() {
	return currentTrialNumber;
}

void ANewBlock::setCurrentTrialNumber(int num) {
	currentTrialNumber = num;
}

FString ANewBlock::getColor() {
	return block[currentTrialNumber].getColor();
}

FString ANewBlock::getStimulus() {
	return block[currentTrialNumber].getStimulus();
}

void ANewBlock::getResponse(int response, float end) {

	// Trial.cpp handles the dataStream and other info

	endReactionTime = end;

	float reactionTime = end - getStartReactionTime();

	block[currentTrialNumber].getResponse(response, reactionTime);

	// write to fileStream

	writeToFile(logPathLocation + FString::FromInt(participantNumber) + "log.txt", block[currentTrialNumber].printTrial());

	//writeToFile("C:\\Users\\bradi\\Desktop\\dataInfo\\response.txt", FString::FromInt(response));

	currentTrialNumber++;
	blockTrialNumber++;

}

FString ANewBlock::getStats() {
	return block[currentTrialNumber - 1].getTrialStats();
}

bool ANewBlock::isNextTrial() {
	if (blockTrialNumber < block.size()) {
		return true;
	}
	else {
		return false;
	}
}

bool ANewBlock::isBreak(int count) {
	if (count == 0) {
		return false;
	}
	else {
		if (count % 48 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

void ANewBlock::startTimer(float start) {
	startReactionTime = start;
}

float ANewBlock::getStartReactionTime() {
	return startReactionTime;
}

bool ANewBlock::isCorrect(int response) {
	if (block[currentTrialNumber].getCorrectLane() == response) {
		return true;
	}
	else {
		return false;
	}
}

int ANewBlock::getBlockNumber() {
	return blockNumber;
}

void ANewBlock::incrementBlockNumber() {
	blockNumber++;
}

void ANewBlock::getParticipantNumberForBlock(int pn) {
	participantNumber = pn;
}

void ANewBlock::initializeLogFile() {
	FString content = "Operation Purple Heart v1.0.0\nPN " + FString::FromInt(participantNumber) + "\n" + FDateTime::Now().ToString() + "\n===========================\n";
	writeToFile(logPathLocation + FString::FromInt(participantNumber) + "log.txt", content);
}
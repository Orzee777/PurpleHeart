#include "block.h"

std::vector<Trial> UBlock::block;
int UBlock::blockNumber;
int UBlock::currentTrialNumber = 0;
float UBlock::startReactionTime;
float UBlock::endReactionTime;

UBlock::UBlock()
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

	std::shuffle(std::begin(block), std::end(block), std::default_random_engine());

	numberTrials();
}


UBlock::~UBlock()
{
}

FString UBlock::printBlock() {
	FString output = "- Block " + FString::FromInt(blockNumber) + " Start -" + "\n";

	for (int i = 0; i < block.size(); i++) {
		output += block[i].printTrial();
	}

	output += "- Block " + FString::FromInt(blockNumber) + " End -\n";

	return output;
}

void UBlock::numberTrials() {
	for (int i = 0; i < block.size(); i++) {
		block[i].setTrialNumber(i+1);
	}
}

int UBlock::getCurrentTrialNumber() {
	return currentTrialNumber;
}

void UBlock::setCurrentTrialNumber(int num) {
	currentTrialNumber = num;
}

FString UBlock::getColor() {
	return block[currentTrialNumber].getColor();
}

FString UBlock::getStimulus() {
	return block[currentTrialNumber].getStimulus();
}

void UBlock::getResponse(int response, float end) {
	
	// Trial.cpp handles the dataStream and other info

	endReactionTime = end;

	float reactionTime = end - getStartReactionTime();
	
	block[currentTrialNumber].getResponse(response, reactionTime);

	// write to fileStream

	writeToFile(FString(FPlatformProcess::UserDir()) + "\\GameData\\Logs\\response.txt", block[currentTrialNumber].printTrial());

	//writeToFile("C:\\Users\\bradi\\Desktop\\dataInfo\\response.txt", FString::FromInt(response));

	currentTrialNumber++;

}

FString UBlock::getStats() {
	return block[currentTrialNumber-1].getTrialStats();
}

bool UBlock::isNextTrial() {
	if (currentTrialNumber < block.size()) {
		return true;
	}
	else {
		return false;
	}
}

void UBlock::startTimer(float start) {
	startReactionTime = start;
}

float UBlock::getStartReactionTime() {
	return startReactionTime;
}

bool UBlock::isCorrect(int response) {
	if (block[currentTrialNumber].getCorrectLane() == response) {
		return true;
	}
	else {
		return false;
	}
}
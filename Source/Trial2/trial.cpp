#include "Trial.h"

int Trial::totalTrials;

Trial::Trial(FString stimulusWord, FString stimulusColor)
{
	stimulus = stimulusWord;
	color = stimulusColor;
	trialNumber = -1;

	if (stimulus == color) {
		isCongruentTrial = true;
	}
	else {
		isCongruentTrial = false;
	}

	if (color == "red") {
		correctLane = 0;
	}
	else if (color == "blue") {
		correctLane = 1;
	}
	else if (color == "green") {
		correctLane = 2;
	}
	else if (color == "yellow") {
		correctLane = 3;
	}
	else {}
}


Trial::~Trial()
{
}

FString Trial::printTrial() {
	FString output =
		"  *** TRIAL " + FString::FromInt(this->getTrialNumber()) + " ***" + "\n" +
		"    stimulus text: " + stimulus + "\n"
		"    stimulus color: " + color + "\n"
		"    lane selected: " + FString::FromInt(selectedLane) + " correct: " + FString::FromInt(correctLane) + "\n";
	return output;
}

/*
FString Trial::getTrialStats() {
	FString congruent, correct, output;
	congruent = (isCongruentTrial) ? "YES" : "NO";
	correct = (correctLane == selectedLane) ? "YES" : "NO";
	output = FString::FromInt(trialNumber) + "," + color + "," + stimulus + "," + congruent + "," + correct + ","
		+ FString::FromInt(selectedLane) + "," + FString::FromInt(correctLane) + "," + FString::SanitizeFloat(6);

	return output;
}
*/
void Trial::setTrialNumber(int number) {
	this->trialNumber = number;
}

int Trial::getTrialNumber() {
	return trialNumber;
}

FString Trial::getColor() {
	return color;
}

FString Trial::getStimulus() {
	return stimulus;
}

void Trial::getResponse(int laneSelected) {
	// send data to dataStream
	

	// get Elapsed time
	reactionTime = 100.00;

	selectedLane = laneSelected;
}
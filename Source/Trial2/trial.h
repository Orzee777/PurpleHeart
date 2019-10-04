//#pragma once

#include "CoreMinimal.h"

class Trial
{
private:
	FString stimulus;
	FString color;
	static int totalTrials;
	int trialNumber;
	bool isCongruentTrial;
	int correctLane;
	int selectedLane = -1;
	float reactionTime = 0; // in ms
public:

	Trial(FString stimulusWord, FString stimulusColor);
	~Trial();

	FString printTrial();

	void setTrialNumber(int number);

	int getTrialNumber();
	int getCorrectLane();

	FString getColor();

	FString getStimulus();

	void getResponse(int laneSelected, float reactTime);

	FString getTrialStats();
};


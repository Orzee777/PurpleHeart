#pragma once

#include <algorithm>
#include <vector>
#include <random>
#include "DataFunctions.h"
#include "Trial.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Block.generated.h" // must be last

UCLASS()
class TRIAL2_API UBlock : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	static std::vector<Trial> block;
	static int blockNumber;
	static int currentTrialNumber;
	static float startReactionTime;
	static float endReactionTime;
public:
	UBlock();
	~UBlock();

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

	// used in dataFunctions.cpp
	UFUNCTION(BlueprintCallable, Category = "Trial")
	static FString getStats();

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static void startTimer(float start);

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static float getStartReactionTime();

	//UFUNCTION(BlueprintCallable, Category = "Trial")
	//static void printParticipantData();
};
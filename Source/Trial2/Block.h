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
	static void getResponse(int response);

	UFUNCTION(BlueprintCallable, Category = "Trial")
	static bool isNextTrial();

	// used in dataFunctions.cpp
	//static FString getStats();

	//UFUNCTION(BlueprintCallable, Category = "Trial")
	//static void printParticipantData();
};
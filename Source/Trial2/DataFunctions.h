// DataFunctions.h
// 
// Used for manipulating data to make it better organize and work with

#pragma once

#include "FileHelper.h"
#include "Paths.h"
#include "CoreMinimal.h"

void writeToFile(FString filePath, FString content);

void rewriteFile(FString filePath, FString content);

int getParticipantNumberFromFile(FString inputFilePath);

void incrementParticipantNumber(FString inputFilePath);

void rewriteParticipantNumber(FString inputFilePath, int newNumber);

FString fixToWidth(FString word, int width);

void createStatsFile(FString filePath, FString fileName);

FString fourDigitIntToString(int num);

//void writeToStatsFile(FString filePath, FString fileName, UBlock block);
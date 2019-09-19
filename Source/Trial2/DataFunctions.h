// DataFunctions.h
// 
// Used for manipulating data to make it better organize and work with

#pragma once

//#include "Block.h"
//#include "Participant.h"
#include "FileHelper.h"
#include "Paths.h"
#include "CoreMinimal.h"

void writeToFile(FString filePath, FString content);

void rewriteFile(FString filePath, FString content);

int getParticipantNumberFromFile(FString inputFilePath);

void incrementParticipantNumber(FString inputFilePath);

FString fixToWidth(FString word, int width);

void createStatsFile(FString filePath, FString fileName);

//void writeToStatsFile(FString filePath, FString fileName, UBlock block);

//FString fileDirectory = "C:\\Users\\bradi\\Desktop\\dataInfo";
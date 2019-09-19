#include "DataFunctions.h"

void writeToFile(FString filePath, FString content) {
	FString completeFilePath = filePath;
	FString fileContent = content;
	FFileHelper::SaveStringToFile(fileContent, *completeFilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

void rewriteFile(FString filePath, FString content) {
	FString completeFilePath = filePath;
	FString fileContent = content;
	FFileHelper::SaveStringToFile(fileContent, *completeFilePath);
}

int getParticipantNumberFromFile(FString inputFilePath) {
	FString filePath = inputFilePath;
	FString result;
	FFileHelper::LoadFileToString(result, *filePath);
	incrementParticipantNumber(inputFilePath);
	return FCString::Atoi(*result);
}

void incrementParticipantNumber(FString inputFilePath) {
	FString inputFileName = "dataInputFile.txt";
	FString pnFile, result, left, right = "";
	int index = 0;
	int participantNumber;

	FFileHelper::LoadFileToString(result, *inputFileName);
	index = result.Find("PN ");
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
}

FString fixToWidth(FString word, int width) {
	FString newWord = word;
	int leadingSpaces = width - word.Len();
	if (leadingSpaces >= 0) {
		for (int i = 0; i < leadingSpaces; i++) {
			newWord = " " + newWord;
		}
		return newWord;
	}
	else {
		return newWord.Left(width);
	}
}

void createStatsFile(FString filePath, FString fileName) {
	FString content = "Trial,\"Stimulus Color\",\"Stimulus Word\",Congruent?,Correct?,Selection,\"Correct Lane\",\"Reaction Time\"";
	// take all variables and convert them into a stats file
	writeToFile(filePath + fileName, content);
}


/*
void writeToStatsFile(FString filePath, FString fileName, UBlock block) {
	writeToFile(filePath + fileName, block.getStats());
}
*/


// File Directory
//FString fileDirectory = "C:\\Users\\bradi\\Desktop\\dataInfo";

// Default Game Directory
//FPaths path;
//FString gameDirectory = path.GameDir();
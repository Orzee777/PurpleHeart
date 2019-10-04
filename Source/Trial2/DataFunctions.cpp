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
	const TCHAR* inputFile = *inputFilePath;
	FString pnFile, result, left, center, right = "";
	int index, participantNumber = 0;

	FFileHelper::LoadFileToString(result, inputFile);
	index = result.Find("PN ") + 3;
	left = result.Left(index);
	center = result.RightChop(index);
	center = center.Left(4);
	right = result.RightChop(index + 4);

	const TCHAR* newResult = *center;
	participantNumber = FCString::Atoi(newResult);

	rewriteFile("C:\\Users\\bradi\\Desktop\\dataInfo\\output.txt", FString::FromInt(participantNumber));
	
	return participantNumber;
}

void incrementParticipantNumber(FString inputFilePath) {
	const TCHAR* inputFile = *inputFilePath;
	FString pnFile, result, left, center, right = "";
	int index = 0;
	int participantNumber = 0;
	
	FFileHelper::LoadFileToString(result, inputFile);
	index = result.Find("PN ") + 3;
	left = result.Left(index);
	center = result.RightChop(index);
	center = center.Left(4);
	right = result.RightChop(index + 4);

	const TCHAR* newResult = *center;
	participantNumber = FCString::Atoi(newResult);
	
	pnFile = FString::FromInt(participantNumber + 1);

	for (int i = 0; i < pnFile.Len() - 4; i++) {
		pnFile = "0" + pnFile;
	}

	rewriteFile(inputFilePath, left + pnFile + right);
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

void writeToStatsFile(FString filePath, FString fileName) {
	writeToFile(filePath + fileName, "");
}

// File Directory
//FString fileDirectory = "C:\\Users\\bradi\\Desktop\\dataInfo";

// Default Game Directory
//FPaths path;
//FString gameDirectory = path.GameDir();
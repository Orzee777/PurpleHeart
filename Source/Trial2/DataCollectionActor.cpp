#include "DataCollectionActor.h"

// Sets default values
ADataCollectionActor::ADataCollectionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataCollectionActor::BeginPlay()
{
	Super::BeginPlay();

	writeToFile("C:\\Users\\bradi\\Desktop\\dataInfo\\input.txt", "it works!");
}

// Called every frame
void ADataCollectionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADataCollectionActor::writeToFile(FString filePath, FString content) {
	FString completeFilePath = filePath;
	FString fileContent = TEXT(content);
	FFileHelper::SaveStringToFile(fileContent, *completeFilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}
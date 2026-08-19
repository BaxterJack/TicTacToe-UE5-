// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTMenuGameMode.h"

void ATTTMenuGameMode::BeginPlay()
{
	
	Super::BeginPlay();
	SetTTTGameInstance();

}


void ATTTMenuGameMode::SetTTTGameInstance() {
	TTTGameInstance = Cast<UTTTGameInstance>(GetGameInstance());
	if (!TTTGameInstance) {
		UE_LOG(LogTemp, Warning, TEXT("TTTGameInstance not found!"));
	}
}

UTTTGameInstance* ATTTMenuGameMode::GetTTTGameInstance() {
	return TTTGameInstance;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTGameStateBase.h"

void ATTTGameStateBase::ResetPlayerScores() {
	PlayerOneScore = 0;
	PlayerTwoScore = 0;
}

void ATTTGameStateBase::UpdateScore(int32 PlayerNumber) {
    if (PlayerNumber == 1)
    {
        PlayerOneScore += 1;
    }
    else if (PlayerNumber == 2)
    {
        PlayerTwoScore += 1;
    }
}

int32 ATTTGameStateBase::GetPlayerScore(int32 PlayerNumber)
{
    switch (PlayerNumber) {
    case 1:
        return PlayerOneScore;
    case 2:
        return PlayerTwoScore;
    default:
        UE_LOG(LogTemp, Warning, TEXT("GetPlayerScore called with invalid PlayerNumber: %d"), PlayerNumber);
        return 0;
    }
}

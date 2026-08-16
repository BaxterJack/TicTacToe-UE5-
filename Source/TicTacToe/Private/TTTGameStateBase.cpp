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

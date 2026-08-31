// Fill out your copyright notice in the Description page of Project Settings.


#include "StateStartNewSeries.h"
#include "TicTacToeGameMode.h"

void UStateStartNewSeries::Initialise(ATicTacToeGameMode* In_TTT_GameMode)
{
	Super::Initialise(In_TTT_GameMode);
}

void UStateStartNewSeries::OnEnter()
{
	TTT_GameMode->SetupSeries();
	TTT_GameMode->NextState();
}

void UStateStartNewSeries::UpdateState()
{
}

void UStateStartNewSeries::OnExit()
{
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "StateStartNewGame.h"
#include "TicTacToeGameMode.h"

void UStateStartNewGame::Initialise(ATicTacToeGameMode* In_TTT_GameMode)
{
	Super::Initialise(In_TTT_GameMode);
}

void UStateStartNewGame::OnEnter()
{
	TTT_GameMode->SetupGame();
	TTT_GameMode->NextState();
}

void UStateStartNewGame::UpdateState()
{
}

void UStateStartNewGame::OnExit()
{
}

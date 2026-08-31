// Fill out your copyright notice in the Description page of Project Settings.


#include "StateInitialiseGame.h"
#include "TicTacToeGameMode.h"

void UStateInitialiseGame::Initialise(ATicTacToeGameMode* In_TTT_GameMode)
{
	Super::Initialise(In_TTT_GameMode);
}

void UStateInitialiseGame::OnEnter()
{
	TTT_GameMode->InitialiseTTTGameMode();
	TTT_GameMode->NextState();
}

void UStateInitialiseGame::UpdateState()
{
}

void UStateInitialiseGame::OnExit()
{
}



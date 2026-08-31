// Fill out your copyright notice in the Description page of Project Settings.


#include "StateWaitingForInput.h"
#include "TicTacToeGameMode.h"
#include "TTT_AI.h"

void UStateWaitingForInput::Initialise(ATicTacToeGameMode* In_TTT_GameMode)
{
	Super::Initialise(In_TTT_GameMode);
	IsVsAi = false;
}

void UStateWaitingForInput::OnEnter()
{
	EGameModeChoice CurrentGameMode = TTT_GameMode->GetTTTGameInstance()->GameModeChoice;
	int32 CurrentPlayer = TTT_GameMode->GetCurrentPlayer();

	IsVsAi = (CurrentGameMode == EGameModeChoice::VsAI && CurrentPlayer == 2);
	if (IsVsAi) {
		TTT_GameMode->GetWorldTimerManager().SetTimer(AITimerHandle, TTT_GameMode, &ATicTacToeGameMode::TriggerAiTurn, 0.75f, false);
	}
}

void UStateWaitingForInput::UpdateState()
{
	
}

void UStateWaitingForInput::OnExit()
{
	TTT_GameMode->GetWorldTimerManager().ClearTimer(AITimerHandle);
	IsVsAi = false;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_StateMachine.h"
#include "TicTacToeGameMode.h"
#include "StateWaitingForInput.h"
#include "StateInitialiseGame.h"
#include "StateStartNewSeries.h"
#include "StateStartNewGame.h"


void UTTT_StateMachine::Initialise(ATicTacToeGameMode* InTTTGameMode) {
	InitialiseGame = NewObject<UStateInitialiseGame>(this);
	InitialiseGame->Initialise(InTTTGameMode);
	
	StartNewSeries = NewObject<UStateStartNewSeries>(this);
	StartNewSeries->Initialise(InTTTGameMode);

	StartNewGame = NewObject<UStateStartNewGame>(this);
	StartNewGame->Initialise(InTTTGameMode);

	WaitingForInput = NewObject<UStateWaitingForInput>(this);
	WaitingForInput->Initialise(InTTTGameMode);


	InitialiseGame->SetTransitionState(StartNewSeries);
	StartNewSeries->SetTransitionState(WaitingForInput);
	StartNewGame->SetTransitionState(WaitingForInput);

	TransitionToState(InitialiseGame);
}

void UTTT_StateMachine::Update() {
	if (CurrentState) {
		CurrentState->UpdateState();
	}
	
}

void UTTT_StateMachine::TransitionToState(UTTT_State* NewState)
{
	if (CurrentState) {
		CurrentState->OnExit();
	}
	CurrentState = NewState;
	if (CurrentState) {
		CurrentState->OnEnter();
	}
}

void UTTT_StateMachine::TransitionToNextState()
{
	UTTT_State* NextState = CurrentState->GetTransitionState();
	if (CurrentState) {
		CurrentState->OnExit();
	}
	CurrentState = NextState;
	if (CurrentState) {
		CurrentState->OnEnter();
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_StateMachine.h"
#include "TicTacToeGameMode.h"
#include "StateWaitingForInput.h"


void UTTT_StateMachine::Initialise(ATicTacToeGameMode* InTTTGameMode) {
	WaitingForInput = NewObject<UStateWaitingForInput>(this);
	WaitingForInput->Initialise(InTTTGameMode);
	CurrentState = WaitingForInput;
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

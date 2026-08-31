// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_State.h"
#include "TicTacToeGameMode.h"

void UTTT_State::Initialise(ATicTacToeGameMode* In_TTT_GameMode)
{
	TTT_GameMode = In_TTT_GameMode;
}

void UTTT_State::SetTransitionState(UTTT_State* InTransitionState)
{
    if (!InTransitionState)
    {
        UE_LOG(LogTemp, Warning, TEXT("SetTransitionState failed on %s — InTransitionState is null"),
            *GetName());
        return;
    }
    TransitionState = InTransitionState;
    UE_LOG(LogTemp, Log, TEXT("%s TransitionState set to %s"),
        *GetName(), *InTransitionState->GetName());
}

UTTT_State* UTTT_State::GetTransitionState()
{
    if (!TransitionState)
    {
        UE_LOG(LogTemp, Warning, TEXT("GetTransitionState failed on %s — TransitionState is null"),
            *GetName());
        return nullptr;
    }
    return TransitionState;
}

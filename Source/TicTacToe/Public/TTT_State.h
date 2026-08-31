// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TTT_State.generated.h"

class ATicTacToeGameMode;
/**
 * 
 */
UCLASS(Abstract)
class TICTACTOE_API UTTT_State : public UObject
{
	GENERATED_BODY()
public:
	virtual void Initialise(ATicTacToeGameMode* In_TTT_GameMode);
	virtual void OnEnter() PURE_VIRTUAL(UTTT_State::OnEnter,);
	virtual void UpdateState() PURE_VIRTUAL(UTTT_State::UpdateState,);
	virtual void OnExit() PURE_VIRTUAL(UTTT_State::OnExit,);
	void SetTransitionState(UTTT_State* InTransitionState);
	UTTT_State* GetTransitionState();

protected:
	UPROPERTY()
	ATicTacToeGameMode* TTT_GameMode;
	UPROPERTY()
	UTTT_State* TransitionState;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TTT_State.h"
#include "TTT_StateMachine.generated.h"

class ATicTacToeGameMode;


/**
 * 
 */
UCLASS()
class TICTACTOE_API UTTT_StateMachine : public UObject
{
	GENERATED_BODY()
	
public:

	void Initialise(ATicTacToeGameMode* InTTTGameMode);
	void Update();
	void TransitionToState(UTTT_State* NewState);
	UPROPERTY()
	UTTT_State* WaitingForInput;

protected:
	UPROPERTY()
	UTTT_State* CurrentState;
	
	
};

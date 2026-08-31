// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTT_State.h"
#include "StateStartNewSeries.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UStateStartNewSeries : public UTTT_State
{
	GENERATED_BODY()
	
public:
	void Initialise(ATicTacToeGameMode* In_TTT_GameMode) override;
	void OnEnter() override;
	void UpdateState() override;
	void OnExit() override;
};

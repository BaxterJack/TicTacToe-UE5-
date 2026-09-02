// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTT_AI.h"
#include "TTT_AI_Impossible.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UTTT_AI_Impossible : public UTTT_AI
{
	GENERATED_BODY()
	
public:

	int32 ChooseMove(const TArray<int32>& InGrid, int32 InAiPlayerNumber) override;

private:
	
	int32 MiniMax(TArray<int32> InCopyGrid, int32 InDepth, int32 InCurrentPlayer, int32 InAiPlayerNumber);

	int32 IsTerminal(const TArray<int32>& InGrid);

	const int32 WinPatterns[8][3] =
	{ {0,1,2},
		{3,4,5},
		{6,7,8},

		{0,3,6},
		{1,4,7},
		{2,5,8},

		{0,4,8},
		{2,4,6}
	};
};

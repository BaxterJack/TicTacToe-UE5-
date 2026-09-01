// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTT_AI.h"
#include "TTT_AI_Medium.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UTTT_AI_Medium : public UTTT_AI
{
	GENERATED_BODY()
public:

	int32 ChooseMove(const TArray<int32>& InGrid, int32 InAiPlayerNumber) override;


private:
	int32 FindLineWin(const TArray<int32>& InGrid, int32 InAiPlayerNumber);
	int32 ChooseBestFreeSquare(const TArray<int32>& InGrid);
	int32 CheckFreeSpaces(const TArray<int32>& InGrid, const TArray<int32>& SquaresArray);
	 const int32 WinPatterns[8][3] =
	 {   {0,1,2},
		 {3,4,5},
		 {6,7,8},

		 {0,3,6},
		 {1,4,7},
		 {2,5,8},

		 {0,4,8},
		 {2,4,6}
	 };
	 //Index of MiddleSquare for InGrid
	 const int32 MiddleSquare = 4;
	 //Indices of Corner Squares for InGrid
	 const TArray<int32> CornerSquares = { 0,2,6,8 };
	 //Indices of Edge Squares for InGrid
	 const TArray<int32> EdgeSquares = { 1,3,5,7 };
	
};

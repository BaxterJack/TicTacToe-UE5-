// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_AI_Impossible.h"

//Choose Move will always be the Ais Players move first, hence will be maximising
int32 UTTT_AI_Impossible::ChooseMove(const TArray<int32>& InGrid, int32 InAiPlayerNumber)
{
	int32 Depth = 0;
	int32 CurrentPlayer = InAiPlayerNumber;
	int32 BestSquare = -1;
	int32 BestScore = -1000;
	for (int32 i = 0; i < 9; i++) {
		if (InGrid[i] == 0) {
			TArray<int32> GridCopy = InGrid;
			GridCopy[i] = InAiPlayerNumber;
			int32 OpponentPlayer = (InAiPlayerNumber == 1) ? 2 : 1;
			int32 Score = MiniMax(GridCopy, 1, OpponentPlayer, InAiPlayerNumber);
			if (Score > BestScore) {
				BestScore = Score;
				BestSquare = i;
			}
		}
	}
	return BestSquare;
	
}



int32 UTTT_AI_Impossible::MiniMax(TArray<int32> InCopyGrid, int32 InDepth, int32 InCurrentPlayer, int32 InAiPlayerNumber)
{
	int32 GameOutcome = IsTerminal(InCopyGrid);
	if (GameOutcome != -1) { //Game has terminated
		if (GameOutcome == InAiPlayerNumber) return 10 - InDepth;  // AI wins
		if (GameOutcome == 0) return 0;                             // Draw
		return -10 + InDepth;
	}
	bool bIsMaximising = (InAiPlayerNumber == InCurrentPlayer);
	int32 BestScore = bIsMaximising ? -1000 : 1000;
	int32 OponentPlayer = (InCurrentPlayer == 1) ? 2 : 1;
	for (int32 i = 0; i < 9; i++) {
		
		if (InCopyGrid[i] == 0) {
			InCopyGrid[i] = InCurrentPlayer;
			int32 Score = MiniMax(InCopyGrid, InDepth+1, OponentPlayer, InAiPlayerNumber);
			InCopyGrid[i] = 0;
			if (bIsMaximising && Score > BestScore)
			{
				BestScore = Score;
			}
			else if (!bIsMaximising && Score < BestScore)
			{
				BestScore = Score;
			}
		}
	}
	return BestScore;
}

int32 UTTT_AI_Impossible::IsTerminal(const TArray<int32>& InGrid)
{
	int32 GridProduct = InGrid[8];
	for (int32 i = 0; i < 8; i++) {
		int32 A = InGrid[WinPatterns[i][0]];
		int32 B = InGrid[WinPatterns[i][1]];
		int32 C = InGrid[WinPatterns[i][2]];
		GridProduct *= InGrid[i];

		if (A!=0 && A == B && B == C) {
			//3 in a Row - Returns winning player
			return A;
		}
	}
	if (GridProduct > 0) {
		//All sqaures occupied - Returns Draw
		return 0;
	}
	//Free Squares Remaining - Not Terminal
	return -1;
}


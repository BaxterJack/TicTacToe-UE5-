// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_AI_Medium.h"


int32 UTTT_AI_Medium::ChooseMove(const TArray<int32>& InGrid, int32 InAiPlayerNumber)
{
	int32 SquareIndex;
	int32 EnemyPlayerNumber = InAiPlayerNumber == 2 ? 1 : 2;
	SquareIndex = FindLineWin(InGrid, InAiPlayerNumber);
		if (SquareIndex != -1) return SquareIndex;
	SquareIndex = FindLineWin(InGrid, EnemyPlayerNumber);
		if (SquareIndex != -1) return SquareIndex;
	SquareIndex = ChooseBestFreeSquare(InGrid);
		return SquareIndex;
	
}

int32 UTTT_AI_Medium::FindLineWin(const TArray<int32>& InGrid, int32 InAiPlayerNumber)
{
    for (int32 i = 0; i < 8; i++)
    {
        int32 PlayerCount = 0;
        int32 EmptyIndex = -1;
        bool bOpponentPresent = false;

        for (int32 j = 0; j < 3; j++)
        {
            int32 SquareIndex = WinPatterns[i][j];
            if (InGrid[SquareIndex] == InAiPlayerNumber)
            {
                PlayerCount++;
            }
            else if (InGrid[SquareIndex] == 0)
            {
                EmptyIndex = SquareIndex;
            }
            else
            {
                // Opponent piece present — this line is blocked
                bOpponentPresent = true;
            }
        }

        if (PlayerCount == 2 && EmptyIndex != -1 && !bOpponentPresent)
        {
            UE_LOG(LogTemp, Warning, TEXT("Pattern %d matched — returning square %d"), i, EmptyIndex);
            return EmptyIndex;
        }
    }
    return -1;
}

int32 UTTT_AI_Medium::ChooseBestFreeSquare(const TArray<int32>& InGrid)
{


    if (InGrid[MiddleSquare] == 0) {return MiddleSquare;}
    
    int32 FreeSquare = CheckFreeSpaces(InGrid, CornerSquares);
    if (FreeSquare != -1) { return FreeSquare; }
    FreeSquare = CheckFreeSpaces(InGrid, EdgeSquares);
    return FreeSquare; 

}

	

int32 UTTT_AI_Medium::CheckFreeSpaces(const TArray<int32>& InGrid, const TArray<int32>& SquaresArray)
{
    TArray<int32> FreeSpaces;

    for (int32 i = 0; i < SquaresArray.Num(); i++) {
        if (InGrid[SquaresArray[i]] == 0) {
            FreeSpaces.Add(SquaresArray[i]);
        }
    }
    int32 NumFreeSpaces = FreeSpaces.Num();
    if (NumFreeSpaces > 0) {
       return FreeSpaces[ FMath::RandRange(0, NumFreeSpaces - 1)];
    }
    return -1;
}





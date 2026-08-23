// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_AI_Easy.h"


//InAiPlayerNumber exists, but is unsed for Easy AI - commented out name to acknowledge its existence
int32 UTTT_AI_Easy::ChooseMove(const TArray<int32>& InGrid, int32 /*InAiPlayerNumber*/)
{

	return GetRandomSquare(GetEmptySpaces(InGrid));
}

TArray<int32> UTTT_AI_Easy::GetEmptySpaces(const TArray<int32>& InGrid)
{
	TArray<int32> EmptySpaces;

	for (int i = 0; i < InGrid.Num(); i++) {
		if (InGrid[i] == 0) {
			EmptySpaces.Add(i);
		}
	}

	return EmptySpaces;
}

int32 UTTT_AI_Easy::GetRandomSquare(const TArray<int32>& InEmptySpaces)
{
	int32 NumSpaces = InEmptySpaces.Num();
	if (NumSpaces == 0) {
		UE_LOG(LogTemp, Warning, TEXT("GetRandomSquare called with no empty spaces!"));
		return -1;
	}
	return InEmptySpaces[FMath::RandRange(0, NumSpaces - 1)];

}

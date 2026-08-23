// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTT_AI.h"
#include "TTT_AI_Easy.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UTTT_AI_Easy : public UTTT_AI
{
	GENERATED_BODY()
public:
	int32 ChooseMove(const TArray<int32>& InGrid, int32 InAiPlayerNumber) override;
private:
	TArray<int32> GetEmptySpaces(const TArray<int32>& InGrid);
	int32 GetRandomSquare(const TArray<int32>& InEmptySpaces);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TTT_AI.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TICTACTOE_API UTTT_AI : public UObject
{
	GENERATED_BODY()
	
public:
	virtual int32 ChooseMove(const TArray<int32>& InGrid, int32 InAiPlayerNumber) PURE_VIRTUAL(UTTT_AI::ChooseMove, return -1;);
};

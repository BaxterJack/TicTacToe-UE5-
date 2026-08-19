// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TTTGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATTTGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly)
	int32 PlayerOneScore = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 PlayerTwoScore = 0;

	void ResetPlayerScores();

	void UpdateScore(int32 PlayerNumber);

	int32 GetPlayerScore(int32 PlayerNumber);

protected:
	
	
private:

};

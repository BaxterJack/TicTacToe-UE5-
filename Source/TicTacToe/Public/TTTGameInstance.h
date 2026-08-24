// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TTTGameInstance.generated.h"

UENUM(BlueprintType)
enum class EGameModeChoice :uint8 {
	TwoPlayer UMETA(DisplayName = "Two Players"),
	VsAI UMETA(DisplayName = "Vs Ai")
};
UENUM(BlueprintType)
enum class EAiDifficulty :uint8 {
	Easy UMETA(DisplayName = "Easy Difficulty"),
	Medium UMETA(DisplayName = "Medium Difficulty"),
	Impossible UMETA(DisplayName = "Impossible Difficulty")
};


UCLASS()
class TICTACTOE_API UTTTGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:


	UPROPERTY(BlueprintReadWrite)
	FString PlayerOneName = TEXT("Player 1");
	UPROPERTY(BlueprintReadWrite)
	FString PlayerTwoName = TEXT("Player 2");

	UPROPERTY(BlueprintReadWrite)
	int32 SeriesLength = 1;

	UPROPERTY()
	EGameModeChoice GameModeChoice = EGameModeChoice::TwoPlayer;

	EAiDifficulty AiDifficulty = EAiDifficulty::Easy;

	void SetSeriesLength(int32 NumSeries);

	int32 GetSeriesLength();

	UFUNCTION(BlueprintCallable)
	void SetVSGameModeChoice(EGameModeChoice InGameModeChoice);

	UFUNCTION(BlueprintCallable)
	void SetAiDiffuclty(EAiDifficulty InAiDifficulty);

private:
	
};

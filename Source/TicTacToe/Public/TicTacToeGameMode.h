// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TTTGameStateBase.h"
#include "TTTGameInstance.h"
#include "TTT_StateMachine.h"
#include "Blueprint/UserWidget.h"
#include "TicTacToeGameMode.generated.h"

class ABoardActor;
class UTTT_AI;
/**
 * 
 */
UCLASS()
class TICTACTOE_API ATicTacToeGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

    // Constructor
    ATicTacToeGameMode();

    // Called when the game starts
    virtual void BeginPlay() override;

    // Called by the Board Actor when a square is tapped
    UFUNCTION(BlueprintCallable)
    void HandleSquareSelected(int32 SquareIndex);

    // Switches turn between player 1 and 2
    UFUNCTION(BlueprintCallable)
    void SwitchTurn();

    // Resets the game back to its initial state
    UFUNCTION(BlueprintCallable)
    void RestartGame();

    void SetupGame();

    UFUNCTION(BlueprintCallable)
    void RestartSeries();

    void SetupSeries();

    // Returns the current player number (1 or 2)
    UFUNCTION(BlueprintPure)
    int32 GetCurrentPlayer() const;

    // Returns true if the game is currently over
    UFUNCTION(BlueprintPure)
    bool IsGameOver() const;

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateTurnDisplay(int32 Player);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateGameOverDisplay(int32 WinningPlayer);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateRestartDisplay();

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateScoreDisplay(int32 P1Score, int32 P2Score);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateSeriesOverDisplay(int32 WinningPlayer);

    UFUNCTION(BlueprintCallable)
    UTTTGameInstance* GetTTTGameInstance();

    UTTT_AI* GetAiPlayer();

    TArray<int32> GetGrid();

    void TriggerAiTurn();

    void InitialiseTTTGameMode();

    void NextState();

protected:

    // The grid — 9 squares, each stores 0 (empty), 1 (player 1) or 2 (player 2)
    UPROPERTY()
    TArray<int32> Grid;

    // Which player's turn it is — 1 or 2
    UPROPERTY(BlueprintReadOnly)
    int32 CurrentPlayer;

    // Whether the game has ended
    UPROPERTY(BlueprintReadOnly)
    bool bGameOver;

    // Who won — 0 means no winner yet, 1 or 2 means that player won
    UPROPERTY(BlueprintReadOnly)
    int32 Winner;
    
    UPROPERTY()
    ABoardActor* BoardActorRef;

    UPROPERTY()
    ATTTGameStateBase* TTTGameState;

    UPROPERTY()
    UTTTGameInstance* TTTGameInstance;

    UPROPERTY()
    UTTT_StateMachine* TTT_StateMachine;

    void InitialiseStateMachine();

    void UpdatePlayersScore(int32 winner);


    // Get the player controller and set input mode
    void SetPlayerInputSettings(APlayerController* PC);

    //Sets BoardActorRef
    void SetBoardActorRef();

    void SetGameState();

    void SetGameInstance();

    //Sets Camera Settings
    void SetCameraSettings(APlayerController* PC);

    void CreateAiPlayer(EAiDifficulty InAiDifficulty);



private:

    // Checks all win conditions — returns winning player or 0
    int32 CheckWinCondition();

    bool CheckSeriesWin(int32 WinningPlayer);

    // Checks if all squares are filled
    bool CheckDrawCondition();

    // Sets up a fresh empty grid
    void InitialiseGrid();

    int32 DetermineStartingPlayer();

    UPROPERTY()
    UTTT_AI* AiPlayer;
};

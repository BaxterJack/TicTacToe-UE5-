// Fill out your copyright notice in the Description page of Project Settings.


#include "TicTacToeGameMode.h"
#include "BoardActor.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"


ATicTacToeGameMode::ATicTacToeGameMode() {
	PrimaryActorTick.bCanEverTick = false;
}

void ATicTacToeGameMode::BeginPlay() {
	Winner = 0;
	InitialiseGrid();
	Super::BeginPlay();
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	SetCameraSettings(PC);

	SetBoardActorRef();
	SetPlayerInputSettings(PC);
	
}



void ATicTacToeGameMode::SetPlayerInputSettings(APlayerController* PC) {
	PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableTouchEvents = true;
		PC->bEnableMouseOverEvents = true;
		FInputModeGameAndUI InputMode;
		InputMode.SetHideCursorDuringCapture(false);
		PC->SetInputMode(InputMode);
	}
}

void ATicTacToeGameMode::SetBoardActorRef() {
	BoardActorRef = Cast<ABoardActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoardActor::StaticClass()));
	if (!BoardActorRef)
	{
		UE_LOG(LogTemp, Warning, TEXT("BoardActor not found in level!"));
	}
}

void ATicTacToeGameMode::SetCameraSettings(APlayerController* PC)
{
	AActor* Camera = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
	if (Camera)
	{
		PC->SetViewTargetWithBlend(Camera);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera not found!"));
	}
}

void ATicTacToeGameMode::InitialiseGrid() {
	Grid.Init(0, 9);
	CurrentPlayer = DetermineStartingPlayer();
	bGameOver = false;

}

int32 ATicTacToeGameMode::DetermineStartingPlayer() {
	if (Winner == 0) {
		return FMath::RandRange(1, 2);
		
	}
	else {
		int32 startingPlayer = 0;
		startingPlayer = (Winner == 1) ? 2 : 1;
		return startingPlayer;
	}
}

void ATicTacToeGameMode::HandleSquareSelected(int32 SquareIndex) {
	if (bGameOver || Grid[SquareIndex] != 0)
	{
		return;
	}

	Grid[SquareIndex] = CurrentPlayer;

	if (BoardActorRef) {
		BoardActorRef->SpawnPieceAtSquare(SquareIndex, CurrentPlayer);
	}
	int32 WinResult = CheckWinCondition();

	if (WinResult != 0) {
		bGameOver = true;
		Winner = WinResult;
		UE_LOG(LogTemp, Warning, TEXT("Player %d wins!"), Winner);
		UpdateGameOverDisplay(WinResult);
		UpdatePlayersScore(Winner);
		return;
	}

	if (CheckDrawCondition()) {
		bGameOver = true;
		Winner = 0;
		UE_LOG(LogTemp, Warning, TEXT("Draw!"));
		UpdateGameOverDisplay(0);
		return;
	}
	SwitchTurn();
	UpdateTurnDisplay(CurrentPlayer);
}

void ATicTacToeGameMode::UpdatePlayersScore(int32 winner)
{
	switch (winner)
	{
	case 1:
		PlayerOneScore += 1;
		break;
	case 2:
		PlayerTwoScore += 1;
		break;
	}
	UpdateScoreDisplay();
}




void ATicTacToeGameMode::ResetPlayerScores() {
	PlayerOneScore = 0;
	PlayerTwoScore = 0;
}

void ATicTacToeGameMode::SwitchTurn()
{
	CurrentPlayer = (CurrentPlayer == 1) ? 2 : 1;
}

void ATicTacToeGameMode::RestartGame()
{
	if (BoardActorRef) {
		BoardActorRef->ClearBoard();
	}
	InitialiseGrid();
	UpdateTurnDisplay(CurrentPlayer);
	UpdateRestartDisplay();
}

int32 ATicTacToeGameMode::GetCurrentPlayer() const
{
	return CurrentPlayer;
}

bool ATicTacToeGameMode::IsGameOver() const
{
	return bGameOver;
}

int32 ATicTacToeGameMode::CheckWinCondition() {
	const int32 WinPatterns[8][3] = {
		// Rows
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		// Columns
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		// Diagonals
		{0, 4, 8},
		{2, 4, 6}
	};
	for (int32 i = 0; i < 8; i++) {
		int32 A = Grid[WinPatterns[i][0]];
		int32 B = Grid[WinPatterns[i][1]];
		int32 C = Grid[WinPatterns[i][2]];
		// If all three squares match and aren't empty
		if (A != 0 && A == B && B == C)
		{
			return A; // Returns 1 or 2 — the winning player
		}
	}

	return 0; // No winner found
	
}

bool ATicTacToeGameMode::CheckDrawCondition() {
	for (int32 i = 0; i < 9; i++) {
		if (Grid[i] == 0) {
			return false;
		}
	}
	return true;
}
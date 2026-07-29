// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TicTacToeGameMode.h"
#include "BoardActor.generated.h"

UCLASS()
class TICTACTOE_API ABoardActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoardActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when a square mesh is clicked/tapped
	// SquareIndex corresponds to element0-element8
	UFUNCTION(BlueprintCallable)
	void OnSquareClicked(int32 SquareIndex);

	// Spawns the correct piece at the correct square
	// PieceType: 1 = X (blue), 2 = O (red)
	UFUNCTION(BlueprintCallable)
	void SpawnPieceAtSquare(int32 SquareIndex, int32 PieceType);

	// Clears all spawned pieces from the board
	UFUNCTION(BlueprintCallable)
	void ClearBoard();

	// Reference to the X piece Blueprint class to spawn
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pieces")
	TSubclassOf<AActor> PieceXClass;

	// Reference to the O piece Blueprint class to spawn
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pieces")
	TSubclassOf<AActor> PieceOClass;
	
	UFUNCTION(BlueprintCallable)
	void GetBoardSpaces();



protected:

	// Stores references to all spawned pieces so we can clear them on restart
	TArray<AActor*> SpawnedPieces;

	//Stores the location of all board spaces
	TArray<UStaticMeshComponent*> BoardSpaces;

	// Gets the world location of a square by index
    // Used to know where to spawn a piece
	FVector GetSquareLocation(int32 SquareIndex) const;

private:

	// Cached reference to the GameMode
	UPROPERTY()
	ATicTacToeGameMode* GameModeRef;
	// Finds a reference to the GameMode
	// Called in BeginPlay so we can talk to it
	ATicTacToeGameMode* GetTicTacToeGameMode() const;

};

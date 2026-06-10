// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardActor.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABoardActor::ABoardActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABoardActor::BeginPlay()
{
	Super::BeginPlay();
	GameModeRef = GetTicTacToeGameMode();
	GetBoardSpaces();

}

ATicTacToeGameMode* ABoardActor::GetTicTacToeGameMode() const {
	AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	if (GameMode == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("GameMode Not Found!"));
		return NULL;
	}
	return Cast<ATicTacToeGameMode>(GameMode);
}

void ABoardActor::OnSquareClicked(int32 SquareIndex) {
	if (GameModeRef)
	{
		GameModeRef->HandleSquareSelected(SquareIndex);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GameModeRef is null!"));
	}
}

void ABoardActor::GetBoardSpaces() {
	BoardSpaces.Empty();
	GetComponents<UStaticMeshComponent>(BoardSpaces);
	UE_LOG(LogTemp, Warning, TEXT("Found %d board spaces"), BoardSpaces.Num());

	BoardSpaces.Sort([](const UStaticMeshComponent& A, const UStaticMeshComponent& B)
		{
			return A.GetName() < B.GetName();
		});


	for (int32 i = 0; i < BoardSpaces.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("BoardSpace %d: %s"), i, *BoardSpaces[i]->GetName());
	}
}

void ABoardActor::SpawnPieceAtSquare(int32 SquareIndex, int32 PieceType)
{
	if (SquareIndex >= 0 && SquareIndex <= 8)
	{
		FVector Location = GetSquareLocation(SquareIndex);
		Location.Z += 10.0f;
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Location);

		switch (PieceType)
		{
		case 1:
			if (PieceXClass)
			{
				AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(PieceXClass, SpawnTransform);
				if (SpawnedActor)
				{
					SpawnedPieces.Add(SpawnedActor);
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("PieceXClass is null!"));
			}
			break;

		case 2:
			if (PieceOClass)
			{
				AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(PieceOClass, SpawnTransform);
				if (SpawnedActor)
				{
					SpawnedPieces.Add(SpawnedActor);
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("PieceOClass is null!"));
			}
			break;
		}
	}
}

void ABoardActor::ClearBoard()
{
	for (AActor* Piece : SpawnedPieces) {
		if (Piece) {
			Piece->Destroy();
		}
	}
	SpawnedPieces.Empty();
}

FVector ABoardActor::GetSquareLocation(int32 SquareIndex) const
{
	return BoardSpaces[SquareIndex]->GetComponentTransform().GetTranslation();

}




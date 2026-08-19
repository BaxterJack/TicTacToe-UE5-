// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TTTGameInstance.h"
#include "TTTMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATTTMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	UTTTGameInstance* GetTTTGameInstance();

protected:
	void SetTTTGameInstance();

	UPROPERTY()
	UTTTGameInstance* TTTGameInstance;
};

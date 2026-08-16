// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TTTPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API ATTTPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	void SetName(FString name);
protected:
	FString Name;
private:

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTGameInstance.h"

void UTTTGameInstance::SetSeriesLength(int32 NumSeries)
{
	SeriesLength = NumSeries;
}

int32 UTTTGameInstance::GetSeriesLength()
{
	return SeriesLength;
}

void UTTTGameInstance::SetVSGameModeChoice(EGameModeChoice InGameModeChoice)
{
	GameModeChoice = InGameModeChoice;
}




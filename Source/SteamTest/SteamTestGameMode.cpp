// Copyright Epic Games, Inc. All Rights Reserved.

#include "SteamTestGameMode.h"
#include "SteamTestCharacter.h"
#include "SubsystemManager.h"
#include "UObject/ConstructorHelpers.h"

ASteamTestGameMode::ASteamTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASteamTestGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto SessionInterface = USubsystemManager::GetSessionInterface();
	if (USubsystemManager* SubsystemManager = GetGameInstance()->GetSubsystem<USubsystemManager>())
	{
		SubsystemManager->CreateSession();
	}
}

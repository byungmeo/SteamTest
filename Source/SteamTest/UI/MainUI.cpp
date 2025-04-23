// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUI.h"

#include "OnlineSessionSettings.h"
#include "SteamTest/SteamTestGameInstance.h"
#include "SteamTest/SubsystemManager.h"

void UMainUI::FindFirstSessionComplete(const FOnlineSessionSearchResult& OnlineSessionSearchResult, bool bArg)
{
	if (USubsystemManager* SubsystemManager = GetGameInstance()->GetSubsystem<USubsystemManager>())
	{
		if (bArg)
		{
			SubsystemManager->JoinSession(OnlineSessionSearchResult);
		}
	}
}

void UMainUI::NativeConstruct()
{
	Super::NativeConstruct();

	if (USubsystemManager* SubsystemManager = GetGameInstance()->GetSubsystem<USubsystemManager>())
	{
		SubsystemManager->AuraOnFindFirstSessionCompleteDelegate.AddUObject(this, &ThisClass::FindFirstSessionComplete);
	}
}

void UMainUI::CreateSession()
{
	GetWorld()->ServerTravel(TEXT("/Game/Maps/SessionRoomMap?listen"));

	/*
	auto SessionInterface = USubsystemManager::GetSessionInterface();
	if (USubsystemManager* SubsystemManager = GetGameInstance()->GetSubsystem<USubsystemManager>())
	{
		SubsystemManager->CreateSession();
	}
	*/
}

void UMainUI::FindAndJoinSession()
{
	auto SessionInterface = USubsystemManager::GetSessionInterface();
	if (USubsystemManager* SubsystemManager = GetGameInstance()->GetSubsystem<USubsystemManager>())
	{
		SubsystemManager->FindSessions();
	}
}

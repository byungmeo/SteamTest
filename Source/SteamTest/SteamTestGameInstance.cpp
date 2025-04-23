// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamTestGameInstance.h"

#include "OnlineSubsystemUtils.h"
#include "SubsystemManager.h"
#include "Interfaces/OnlineSessionInterface.h"

void USteamTestGameInstance::Init()
{
	Super::Init();

	const IOnlineSessionPtr SessionInterface = USubsystemManager::GetSessionInterface();
	if (SessionInterface.IsValid())
	{
		// OnlineSubsystem
		
		FName SubsystemName = Online::GetSubsystem(GetWorld())->GetSubsystemName();
		UE_LOG(LogTemp, Warning, TEXT("SubsystemName : %s"), *SubsystemName.ToString());
		
		// 게임 초대를 수락하면 OnSessionUserInviteAccepted 호출하도록 연동
		OnSessionUserInviteAcceptedDelegateHandle = SessionInterface->AddOnSessionUserInviteAcceptedDelegate_Handle(FOnSessionUserInviteAcceptedDelegate::CreateUObject(this, &ThisClass::OnSessionUserInviteAccepted));
	}
}

void USteamTestGameInstance::Shutdown()
{
	Super::Shutdown();
}

void USteamTestGameInstance::OnSessionUserInviteAccepted(const bool bWasSuccessful, const int32 ControllerId,
	FUniqueNetIdPtr UserId, const FOnlineSessionSearchResult& InviteResult)
{
}

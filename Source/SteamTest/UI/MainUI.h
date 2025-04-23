// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

/**
 * 
 */
UCLASS()
class STEAMTEST_API UMainUI : public UUserWidget
{
	GENERATED_BODY()

public:
	void FindFirstSessionComplete(const FOnlineSessionSearchResult& OnlineSessionSearchResult, bool bArg);
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void CreateSession();

	UFUNCTION(BlueprintCallable)
	void FindAndJoinSession();
};

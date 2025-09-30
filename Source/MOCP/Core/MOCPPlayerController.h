// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"

#include "MOCPPlayerController.generated.h"

/**
 *
 */
UCLASS()
class MOCP_API AMOCPPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> SpecialAction;

	//
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	void		 OnMove(const FInputActionValue& Value);
	void		 OnJumpStarted(const FInputActionValue& Value);
	void		 OnJumpEnded(const FInputActionValue& Value);
	void		 OnSpecialStarted(const FInputActionValue& Value);
	void		 OnSpecialEnded(const FInputActionValue& Value);
};

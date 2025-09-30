// Fill out your copyright notice in the Description page of Project Settings.

#include "MOCPPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PossessInterface.h"

void AMOCPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* InputSubSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		InputSubSystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
void AMOCPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Move
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMOCPPlayerController::OnMove);

		// Jump
		EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &AMOCPPlayerController::OnJumpStarted);
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMOCPPlayerController::OnJumpEnded);

		// Special
		EIC->BindAction(SpecialAction, ETriggerEvent::Started, this, &AMOCPPlayerController::OnSpecialStarted);
		EIC->BindAction(SpecialAction, ETriggerEvent::Completed, this, &AMOCPPlayerController::OnSpecialEnded);
	}
}
void AMOCPPlayerController::OnMove(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UPossessInterface>())
	{
		IPossessInterface* PossessInterface = Cast<IPossessInterface>(GetPawn());
		PossessInterface->HandleMovement(Value.Get<FVector2D>());
	}
}
void AMOCPPlayerController::OnJumpStarted(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UPossessInterface>())
	{
		IPossessInterface* PossessInterface = Cast<IPossessInterface>(GetPawn());
		PossessInterface->HandleJump(true);
	}
}
void AMOCPPlayerController::OnJumpEnded(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UPossessInterface>())
	{
		IPossessInterface* PossessInterface = Cast<IPossessInterface>(GetPawn());
		PossessInterface->HandleJump(false);
	}
}
void AMOCPPlayerController::OnSpecialStarted(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UPossessInterface>())
	{
		IPossessInterface* PossessInterface = Cast<IPossessInterface>(GetPawn());
		PossessInterface->HandleSpecial(true);
	}
}
void AMOCPPlayerController::OnSpecialEnded(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UPossessInterface>())
	{
		IPossessInterface* PossessInterface = Cast<IPossessInterface>(GetPawn());
		PossessInterface->HandleSpecial(false);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/PossessInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Frog.generated.h"

UCLASS()
class MOCP_API AFrog : public APawn, public IPossessInterface
{
	GENERATED_BODY()

public:
	AFrog();

	virtual void HandleMovement(const FVector2D& Direction) override;
	virtual void HandleJump(bool bPressed) override;
	virtual void HandleSpecial(bool bPressed) override;
};

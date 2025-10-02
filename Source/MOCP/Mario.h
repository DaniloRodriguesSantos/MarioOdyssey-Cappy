// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/PossessInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Mario.generated.h"

UCLASS()
class MOCP_API AMario : public ACharacter, public IPossessInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMario();

	//~ Begin IPossessInterface Interface
	virtual void HandleMovement(const FVector2D& Direction) override;
	virtual void HandleJump(bool bPressed) override;
	virtual void HandleSpecial(bool bPressed) override;
	//~ End IPossessInterface Interface
};

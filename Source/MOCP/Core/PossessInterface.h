// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "PossessInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPossessInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class MOCP_API IPossessInterface
{
	GENERATED_BODY()

public:
	virtual void HandleMovement(const FVector2D& Direction) = 0;
	virtual void HandleJump(bool bPressed)					= 0;
	virtual void HandleSpecial(bool bPressed)				= 0;
};

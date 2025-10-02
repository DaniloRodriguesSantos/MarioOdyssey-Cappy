// Fill out your copyright notice in the Description page of Project Settings.

#include "Mario.h"

// Sets default values
AMario::AMario()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
void AMario::HandleMovement(const FVector2D& Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("[POSSESSMECHANIC] - Mario moved - %s"), *Direction.ToString());
}
void AMario::HandleJump(bool bPressed)
{
	UE_LOG(LogTemp, Warning, TEXT("[POSSESSMECHANIC] - Mario jumped - %s"), bPressed ? TEXT("True") : TEXT("False"));
}
void AMario::HandleSpecial(bool bPressed)
{
	UE_LOG(LogTemp, Warning, TEXT("[POSSESSMECHANIC] - Mario special - %s"), bPressed ? TEXT("True") : TEXT("False"));
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "Frog.h"

// Sets default values
AFrog::AFrog()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
void AFrog::HandleMovement(const FVector2D& Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("[POSSESSMECHANIC] - Frog moved - %s"), *Direction.ToString());
}
void AFrog::HandleJump(bool bPressed)
{
	UE_LOG(LogTemp, Warning, TEXT("[POSSESSMECHANIC] - Frog jumped - %s"), bPressed ? TEXT("True") : TEXT("False"));
}
void AFrog::HandleSpecial(bool bPressed)
{
	UE_LOG(LogTemp, Warning, TEXT("[POSSESSMECHANIC] - Frog special - %s"), bPressed ? TEXT("True") : TEXT("False"));
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank is not found!"));
		return nullptr;
	}

	return Cast<ATank>(PlayerTank);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank())
	{
		// Get the location where the AI is aiming at
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}
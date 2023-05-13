// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerPawn::PlayerMoveTypeOne);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::PlayerMoveTypeTwo);
}

void APlayerPawn::PlayerMoveTypeOne(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void APlayerPawn::PlayerMoveTypeTwo(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}
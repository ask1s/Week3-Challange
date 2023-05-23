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


	bUseMovementTypeOne ? PlayerMoveTypeOne() : PlayerMoveTypeTwo();
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerPawn::PlayerMoveTypeOne()
{
	AddActorWorldOffset(ConsumeMovementInputVector());

	AddMovementInput(GetActorForwardVector() * MovementSpeed * GetInputAxisValue("MoveForward") * GetWorld()->DeltaTimeSeconds);
	AddMovementInput(GetActorRightVector() * MovementSpeed * GetInputAxisValue("MoveRight") * GetWorld()->DeltaTimeSeconds);

	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Yellow, FString::Printf(TEXT("%f"),GetInputAxisValue("MoveForward")));
	GEngine->AddOnScreenDebugMessage(-2, 0.01f, FColor::Yellow, FString::Printf(TEXT("%f"), GetInputAxisValue("MoveRight")));
	
	UE_LOG(LogTemp, Warning, TEXT("MoveTypeTwo"));
}

void APlayerPawn::PlayerMoveTypeTwo()
{
	const float Forward = GetInputAxisValue("MoveForward") * MovementSpeed * GetWorld()->DeltaTimeSeconds;
	const float Right = GetInputAxisValue("MoveRight") * MovementSpeed * GetWorld()->DeltaTimeSeconds;

	AddActorWorldOffset(FVector(Forward, Right, 0));

	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Yellow, FString::Printf(TEXT("%f"), GetInputAxisValue("MoveForward")));
	GEngine->AddOnScreenDebugMessage(-2, 0.01f, FColor::Yellow, FString::Printf(TEXT("%f"), GetInputAxisValue("MoveRight")));

	UE_LOG(LogTemp, Warning, TEXT("MoveTypeTwo"));
}
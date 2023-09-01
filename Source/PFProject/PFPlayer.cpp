// Fill out your copyright notice in the Description page of Project Settings.


#include "PFPlayer.h"

// Sets default values
APFPlayer::APFPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APFPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void APFPlayer::MoveForward(float Value)
{
}

void APFPlayer::MoveBackward(float Value)
{
}

void APFPlayer::MoveRight(float Value)
{
}

void APFPlayer::MoveLeft(float Value)
{
}

// Called every frame
void APFPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APFPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveForward"), EKeys::W, 1.f));
	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveBackward"), EKeys::S, -1.f));
	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveRight"), EKeys::D, 1.f));
	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveLeft"), EKeys::A, -1.f));


	PlayerInputComponent->BindAxis("MoveForward", this, &APFPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveBackward", this, &APFPlayer::MoveBackward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APFPlayer::MoveRight);
	PlayerInputComponent->BindAxis("MoveLeft", this, &APFPlayer::MoveLeft);

}


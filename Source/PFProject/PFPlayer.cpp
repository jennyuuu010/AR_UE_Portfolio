// Fill out your copyright notice in the Description page of Project Settings.


#include "PFPlayer.h"

// Sets default values
APFPlayer::APFPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttachSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("AttachSpring"));
	AttachSpring->SetupAttachment(GetRootComponent());
	AttachSpring->TargetArmLength = 600.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>("ViewCamera");
	ViewCamera->SetupAttachment(AttachSpring);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void APFPlayer::BeginPlay()
{
	Super::BeginPlay();
	
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

	static bool bBindingsAdded = false; 

	if (!bBindingsAdded)
	{

		bBindingsAdded = true; 

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveForward"), EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveForward"), EKeys::S, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveRight"), EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping(("MoveRight"), EKeys::A, -1.f));
	
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerTurn", EKeys::MouseX, 1.f));

	
	}

	PlayerInputComponent->BindAxis("MoveForward", this, &APFPlayer::MoveForward);	
	PlayerInputComponent->BindAxis("MoveRight", this, &APFPlayer::MoveRight);
	


	PlayerInputComponent->BindAxis("PlayerTurn", this, &APFPlayer::AddControllerYawInput);


}

void APFPlayer::MoveForward(float Value)
{


	if (Controller && (Value != 0.f))
	{

		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value, true);
	}



}


void APFPlayer::MoveRight(float Value)
{

	if (Controller && (Value != 0.f))
	{
		FRotator const ControlSpaceRot = Controller->GetControlRotation();

		AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Value);
	}


}




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

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

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
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerTurn", EKeys::MouseX, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerLookUp", EKeys::MouseY, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerLookUp", EKeys::MouseY, 1.f));
		
		//점프
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("JumpAction", EKeys::SpaceBar, 1.f));

			
	}

	PlayerInputComponent->BindAxis("MoveForward", this, &APFPlayer::MoveForward);	
	PlayerInputComponent->BindAxis("MoveRight", this, &APFPlayer::MoveRight);
	PlayerInputComponent->BindAxis("PlayerLookUp", this, &APFPlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookAroundRate", this, &APFPlayer::LookAroundRate);
	PlayerInputComponent->BindAxis("PlayerTurn", this, &APFPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APFPlayer::TurnRate);
	PlayerInputComponent->BindAction("JumpAction", IE_Pressed, this, &APFPlayer::JumpAction);

}

void APFPlayer::MoveForward(float Value)
{

	//캐릭터 클래스에서는 기본적으로 Controller가 붙어 있다. 
	if (Controller && (Value != 0.f))
	{
		FRotator const ControlSpaceRot = Controller->GetControlRotation();
		FVector Forward = GetActorForwardVector();
		AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Value);
		

	
		
	}

}


void APFPlayer::MoveRight(float Value)
{

	if (Controller && (Value != 0.f))
	{
		FRotator const ControlSpaceRot = Controller->GetControlRotation();
		FVector Right = GetActorRightVector();
		AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Value);
		

	}


}

void APFPlayer::TurnRate(float Rate)
{

	AddControllerYawInput(Rate * GetWorld()->GetDeltaSeconds()* CustomTimeDilation);

}

void APFPlayer::LookAroundRate(float Rate)
{

	AddControllerPitchInput(Rate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
}

void APFPlayer::JumpAction()
{

	Jump();
}

void APFPlayer::Attack()
{

	GetMesh()->GetAnimInstance();

}

void APFPlayer::JumpAxis(float Rate)
{
	if (0.f == Rate)
	{
		if (true == AxisJump)
		{
			StopJumping();
			AxisJump = false; 


		}
		return; 

	}

	AxisJump = true; 
	Jump();


}




// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "PFPlayer.h"


void UPlayerAnimInstance::NativeBeginPlay()
{

	Super::NativeBeginPlay();

	APFPlayer* Player = Cast<APFPlayer>(GetOwningActor());

	if (nullptr == Player && false == Player->IsValidLowLevel())
	{

		return;
	}
}


void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

		
	APFPlayer* Player = Cast<APFPlayer>(GetOwningActor());

	

	
	Speed = Player->GetVelocity().Size(); 
	Direction = CalculateDirection(Player->GetVelocity(), Player->GetActorRotation());

	if (nullptr == Player)
	{


		return;
	}
	

}



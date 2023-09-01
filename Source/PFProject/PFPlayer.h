// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PFPlayer.generated.h"

UCLASS()
class PFPROJECT_API APFPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	
	APFPlayer();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	
	virtual void BeginPlay() override;

	//캐릭터 앞뒤좌우이동 
	void MoveForward(float Value);
	void MoveBackward(float Value);
	void MoveRight(float Value);
	void MoveLeft(float Value);



private:	
	

};

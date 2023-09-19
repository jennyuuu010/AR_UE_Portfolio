// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PFPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;


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
	void MoveRight(float Value);
	void TurnRate(float Rate);
	void LookAroundRate(float Rate);

	//점프

	void JumpAction();
	void JumpAxis(float Rate);
	
	//공격 
	void Attack();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USpringArmComponent* AttachSpring;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float BaseLookUpRate;

	bool AxisJump = false; 
	

	
	

};

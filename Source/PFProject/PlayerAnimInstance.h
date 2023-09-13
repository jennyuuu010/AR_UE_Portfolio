// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
class UCharacterMovementComponent;

UCLASS()
class PFPROJECT_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

public: 

	UCharacterMovementComponent* movement;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = PlayerAnim)
	float speed = 0; 
	float direction = 0;
	bool isInAir = false; 

	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float walkSpeed = 200;
	float runSpeed = 600;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

};

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
	float Speed = 0; 

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = PlayerAnim)
	float Direction = 0;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = PlayerAnim)
	bool isInAir = false; 

	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float walkSpeed = 200;

	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float runSpeed = 600;

	void NativeUpdateAnimation(float DeltaSeconds) override;
	void NativeBeginPlay() override;

};

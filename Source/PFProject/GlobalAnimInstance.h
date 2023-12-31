// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PFPlayer.h"
#include "GlobalAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PFPROJECT_API UGlobalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTime) override;

	
	
};

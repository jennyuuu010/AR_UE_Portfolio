// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class AnimState 
{
	None UMETA(DisplayName = "사용안함"),
	Idle UMETA(DisplayName = "서있기"),
	LeftMove UMETA(DisplayName = "좌 이동"),
	RightMove UMETA(DisplayName = "우 이동"),
	ForwardMove UMETA(DisplayName = "전방 이동"),
	BackwardMove UMETA(DisplayName = "후방 이동"),
	Jump UMETA(DisplayName = "점프"),
	Attack UMETA(DisplayName = "공격"),

};
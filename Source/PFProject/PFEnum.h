// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class AnimState 
{
	None UMETA(DisplayName = "������"),
	Idle UMETA(DisplayName = "���ֱ�"),
	LeftMove UMETA(DisplayName = "�� �̵�"),
	RightMove UMETA(DisplayName = "�� �̵�"),
	ForwardMove UMETA(DisplayName = "���� �̵�"),
	BackwardMove UMETA(DisplayName = "�Ĺ� �̵�"),
	Jump UMETA(DisplayName = "����"),
	Attack UMETA(DisplayName = "����"),

};
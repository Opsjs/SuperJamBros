// Fill out your copyright notice in the Description page of Project Settings.


#include "Inputs/InputTriggerDoubleTap.h"

#include "EnhancedPlayerInput.h"

ETriggerState UInputTriggerDoubleTap::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput,
                                                                 FInputActionValue ModifiedValue, float DeltaTime)
{
	return ETriggerState::None;
}

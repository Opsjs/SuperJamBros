// Fill out your copyright notice in the Description page of Project Settings.


#include "Inputs/InputTriggerPressedFast.h"

#include "EnhancedPlayerInput.h"

ETriggerState UInputTriggerPressedFast::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput,
                                                                   FInputActionValue ModifiedValue, float DeltaTime)
{
	return ETriggerState::None;
}

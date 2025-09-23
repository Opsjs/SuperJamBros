// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SmashCharacterInputData.generated.h"

class UInputAction;
/**
 * 
 */
UCLASS()
class SMASHUE_API USmashCharacterInputData : public UDataAsset
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> InputActionMoveX;
};

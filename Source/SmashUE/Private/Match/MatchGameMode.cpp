// Fill out your copyright notice in the Description page of Project Settings.


#include "Match/MatchGameMode.h"
#include "SmashCharacter.h"
#include "Arena/ArenaPlayerStart.h"
#include "Kismet/GameplayStatics.h"

void AMatchGameMode::FindPlayerStartActorsInArena(TArray<AArenaPlayerStart*>& ResultActors)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArenaPlayerStart::StaticClass(), FoundActors);

	for (int i=0; i < FoundActors.Num(); i++)
	{
		AArenaPlayerStart* ArenaPlayerStartActor = Cast<AArenaPlayerStart>(FoundActors[i]);
		if (ArenaPlayerStartActor == nullptr) continue;
		
		ResultActors.Add(ArenaPlayerStartActor);
	}
}

void AMatchGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AArenaPlayerStart*> PlayerStartPoints;
	FindPlayerStartActorsInArena(PlayerStartPoints);
	SpawnCharacters(PlayerStartPoints);
}

TSubclassOf<ASmashCharacter> AMatchGameMode::GetSmashCharacterClassFromInputType(EAutoReceiveInput::Type InputType) const
{
	switch (InputType)
	{
	case EAutoReceiveInput::Player0:
		return SmashCharacterClassP0;
		
	case EAutoReceiveInput::Player1:
		return SmashCharacterClassP1;
		
	case EAutoReceiveInput::Player2:
		return SmashCharacterClassP2;
		
	case EAutoReceiveInput::Player3:
		return SmashCharacterClassP3;
	default:
		return nullptr;
	}
}

void AMatchGameMode::SpawnCharacters(const TArray<AArenaPlayerStart*>& SpawnPoints)
{
	for (AArenaPlayerStart* SpawnPoint : SpawnPoints)
	{
		EAutoReceiveInput::Type InputType = SpawnPoint->AutoReceiveInput.GetValue();
		TSubclassOf<ASmashCharacter> SmashCharacterClass = GetSmashCharacterClassFromInputType(InputType);
		if (SmashCharacterClass == nullptr) continue;

		ASmashCharacter* NewCharacter = GetWorld()->SpawnActorDeferred<ASmashCharacter>(
			SmashCharacterClass,
			SpawnPoint->GetTransform());

		if (NewCharacter == nullptr) continue;
		NewCharacter->AutoPossessPlayer = SpawnPoint->AutoReceiveInput;
		NewCharacter->SetOrientX(SpawnPoint->GetStartOrientX());
		NewCharacter->FinishSpawning(SpawnPoint->GetTransform());

		CharactersInsideArena.Add(NewCharacter);
	}
}

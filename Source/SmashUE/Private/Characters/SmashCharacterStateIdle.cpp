// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SmashCharacterStateIdle.h"


ESmashCharacterStateID USmashCharacterStateIdle::GetStateID()
{
	return ESmashCharacterStateID::Idle;
}

void USmashCharacterStateIdle::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Cyan,
		TEXT("Enter StateWalk")
		);
}

void USmashCharacterStateIdle::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateEnter(NextStateID);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		TEXT("Exit StateWalk")
		);
}

void USmashCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(
		-1,
		0.1f,
		FColor::Green,
		TEXT("Tick StateIdle")
		);
}
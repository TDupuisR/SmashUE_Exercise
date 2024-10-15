// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SmashCharacterStateRun.h"
#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterStateMachine.h"

void USmashCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);

	if (FMath::Abs(Character->GetInputMoveX()) < .1f /*CharacterSettings->InputMoveXThreshold*/ )
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Idle);
	}
	else
	{
		Character->SetOrientX(Character->GetInputMoveX());
		Character->AddMovementInput(FVector::ForwardVector, Character->GetOrientX());
	}
}


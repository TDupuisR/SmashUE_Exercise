// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/State/SmashCharacterStateRun.h"
#include "Characters/SmashCharacter.h"
#include "Characters/State/SmashCharacterStateMachine.h"
#include "Characters/SmashCharacterSettings.h"

void USmashCharacterStateRun::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);

	//Character->PlayAnimMontage(RunAnim);
}

void USmashCharacterStateRun::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
}

void USmashCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);

	if (FMath::Abs(Character->GetInputMoveX()) < 0.1f /*CharacterSettings->InputMoveXThreshold*/ )
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Idle);
	}
	else
	{
		Character->SetOrientX(Character->GetInputMoveX());
		Character->AddMovementInput(FVector::ForwardVector, Character->GetOrientX());
	}
}


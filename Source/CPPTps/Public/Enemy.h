// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

DECLARE_DELEGATE_OneParam(FEnemyDieDelegate, class AEnemy*);

UCLASS()
class CPPTPS_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//적 AI 관리 하는 컴포넌트(FSM)
	UPROPERTY(EditAnywhere)
	class UEnemyFSM* fsm;


	// 활성 / 비활성 하는 기능
	void SetActive(bool bActive);


	//죽었을 때 호출되는 함수를 담는 변수
	FEnemyDieDelegate dieDelegate;
};

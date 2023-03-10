// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TpsPlayer.generated.h"


UCLASS()
class CPPTPS_API ATpsPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATpsPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* compArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* compCam;

	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* compRifle;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* compSniper;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShakeBase> cameraShake;

	UPROPERTY(EditAnywhere)
	class UPlayerMove* compPlayerMove;
	UPROPERTY(EditAnywhere)
	class UPlayerFire* compPlayerFire;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainUI> mainUIFactory;
	UPROPERTY(EditAnywhere)
	class UMainUI* mainUI;

	//현재 HP
	float currHP;
	//최대 HP
	float maxHP = 2;
	//이전 HP
	float prevHP;
	//HP UI 를 갱신할 수 있니?
	bool bUpdateHP = false;
	//HP UI 줄어드는 비율
	float ratioHP = 0.0f;


	//미니맵 블루프린트 클래스
	UPROPERTY()
	TSubclassOf<class AMinimap> miniFactory;

	//게임오브 블루프린트 클래스
	UPROPERTY()
	TSubclassOf<class UGameOverUI> gameOverUIFactory;

public:
	void ReceiveDamage(float damage);	
};

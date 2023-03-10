// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

UCLASS()
class CPPTPS_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//생성시간
	float createTime = 0;
	//현재시간
	float currTime = 0;
	//최소시간
	float minTime = 1;
	//최대시간
	float maxTime = 5;
	//Enemy 공장
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemy> enemyFactory;

	//적 생성 위치들
	UPROPERTY(EditAnywhere)
	TArray<AActor*> spawnPosArray;

	//Enemy 탄창
	UPROPERTY(EditAnywhere)
	TArray<class AEnemy*> enemyArray;

public:
	int32 spawnIdx = 0;
	void FindSpawnPos();

	UFUNCTION()
	void AddEnemy(class AEnemy* e);
};

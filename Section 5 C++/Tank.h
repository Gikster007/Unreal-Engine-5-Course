// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const {return TankPlayerController;};

	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Base Pawn Components")
	class USpringArmComponent *SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Base Pawn Components")
	class UCameraComponent *Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 600.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 90.f;

	void Move(float Value);

	void Turn(float Value);

	APlayerController *TankPlayerController;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

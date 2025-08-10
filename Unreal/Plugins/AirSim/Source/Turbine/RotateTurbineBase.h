// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "common/CommonStructs.hpp"
#include "RotateTurbineBase.generated.h"

UENUM(BlueprintType)
enum class ERotateType :uint8
{
	ANTI_CLOCKWISE =0 UMETA(DisplayName = "Positive"),
	CLOCK_WISE = 1 UMETA(DisplayName = "Negative"),
	RANDOM = 2 UMETA(DisplayName = "Random")

};

UCLASS()
class AIRSIM_API ARotateTurbineBase : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="State")
	double CurrentAngle;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="State")
	double InitialAngle;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Control")
	double FixSpeed=1.0;

	UPROPERTY(BlueprintReadWrite,Category="State")
	FVector BladePivotLocation;

	UPROPERTY(BlueprintReadWrite,Category="State")
	FRotator BladePivotRotation;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Control")
    ERotateType RotateMode;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Control")
	double RandSpeedLowerBound = -1.0;


	UPROPERTY(EditAnyWhere,BLueprintReadWrite,Category="Control")
	double RandSpeedUpperBound = 4;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Control")
	bool EnableRotate;

	UFUNCTION(BlueprintCallable,Category="Control")
	void SetEnableRotate();

	UFUNCTION(BlueprintCallable,Category="Control")
	void SetDisableRotate();

	FVector getBladePivotLocation() const;

	FRotator getBladePivotRotation() const;

	typedef msr::airlib::RotateTurbineState State; 

	// Sets default values for this actor's properties
	ARotateTurbineBase();

	State getState();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

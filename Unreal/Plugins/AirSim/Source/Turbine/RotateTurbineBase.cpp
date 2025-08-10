// Fill out your copyright notice in the Description page of Project Settings.


#include "Turbine/RotateTurbineBase.h"

// Sets default values
ARotateTurbineBase::ARotateTurbineBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARotateTurbineBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateTurbineBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ARotateTurbineBase::SetEnableRotate(){
	EnableRotate =true;
}

void ARotateTurbineBase::SetDisableRotate(){
	EnableRotate =false;
}

ARotateTurbineBase::State ARotateTurbineBase::getState(){
	ARotateTurbineBase::State state;
	state.angle =CurrentAngle;
	FString name;
	GetName(name);
	state.name =std::string(TCHAR_TO_UTF8(*name));
	// state.blade_pivot_pose.position.x() = BladePivotLocation.X;
	// state.blade_pivot_pose.position.y() = BladePivotLocation.Y;
	// state.blade_pivot_pose.position.z() = BladePivotLocation.Z;
	// state.blade_pivot_pose.orientation.x() = BladePivotRotation.Quaternion().X;
	// state.blade_pivot_pose.orientation.y() = BladePivotRotation.Quaternion().Y;
	// state.blade_pivot_pose.orientation.z() = BladePivotRotation.Quaternion().Z;
	// state.blade_pivot_pose.orientation.w() = BladePivotRotation.Quaternion().W;
	return state;
}

FVector ARotateTurbineBase::getBladePivotLocation() const{
	return BladePivotLocation;
}

FRotator ARotateTurbineBase::getBladePivotRotation() const{
	return BladePivotRotation;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();

    CurrentLocation += PlatformVelocity * DeltaTime;

    DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
    if (DistanceMoved > DistanceThreshold)
    {
        // Find MoveDirection(+ve or -ve) in each axis
        FVector MoveDirection = PlatformVelocity.GetSafeNormal();
        float Overshoot = DistanceMoved - DistanceThreshold;
        UE_LOG(LogTemp, Warning, TEXT("Overshoot value is %f"), Overshoot);

        // Overshoot Mitigation
        StartLocation = StartLocation + MoveDirection * DistanceThreshold;
        CurrentLocation = StartLocation;

        PlatformVelocity = -PlatformVelocity;
    }

    SetActorLocation(CurrentLocation);
}
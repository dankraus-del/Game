#include "AIEnemy.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AAIEnemy::AAIEnemy()
{
    PrimaryActorTick.bCanEverTick = true;

    FireInterval = 2.0f;
    MuzzleOffset = FVector(100.f, 0.f, 50.f);
}

void AAIEnemy::BeginPlay()
{
    Super::BeginPlay();

    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    GetWorldTimerManager().SetTimer(ShootTimerHandle, this, &AAIEnemy::ShootAtPlayer, FireInterval, true);
}

void AAIEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (PlayerPawn)
    {
        FVector Direction = PlayerPawn->GetActorLocation() - GetActorLocation();
        FRotator NewRot = Direction.Rotation();
        NewRot.Pitch = 0;
        SetActorRotation(NewRot);

    }
}

void AAIEnemy::ShootAtPlayer()
{
    if (!PlayerPawn || !ProjectileClass)
        return;

    FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * MuzzleOffset.X + FVector(0, 0, MuzzleOffset.Z);
    FRotator SpawnRotation = (PlayerPawn->GetActorLocation() - SpawnLocation).Rotation();

    UWorld* World = GetWorld();
    if (World)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();

        AProjectile* Projectile = World->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
        if (Projectile)
        {
            FVector LaunchDirection = SpawnRotation.Vector();
            Projectile->FireInDirection(LaunchDirection);
        }
    }
}

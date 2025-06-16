#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class Game_API AProjectile : public AActor
{
    GENERATED_BODY()

public:
    AProjectile();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, Category = "Movement")
    UProjectileMovementComponent* ProjectileMovementComponent;

    void FireInDirection(const FVector& ShootDirection);

    UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
    UStaticMeshComponent* ProjectileMeshComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = "Movement")
    UMaterialInstanceDynamic* ProjectileMaterialInstance;

    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* HitComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComponent,
        FVector NormalImpulse,
        const FHitResult& Hit
    );
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Projectile.h"
#include "AIEnemy.generated.h"

UCLASS()
class Game_API AAIEnemy : public ACharacter
{
    GENERATED_BODY()

public:
    AAIEnemy();

protected:
    virtual void BeginPlay() override;

    FTimerHandle ShootTimerHandle;

    UPROPERTY(EditAnywhere, Category = "AI")
    float FireInterval;

    UPROPERTY(EditAnywhere, Category = "AI")
    TSubclassOf<AProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere, Category = "AI")
    FVector MuzzleOffset;

    APawn* PlayerPawn;

    void ShootAtPlayer();

public:
    virtual void Tick(float DeltaTime) override;
};

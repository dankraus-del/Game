#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "HealthBarWidget.h"
#include "Character.generated.h"

UCLASS()
class Game_API ACharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ACharacter();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Health")
    float MaxHealth = 100.f;

    UPROPERTY(VisibleAnywhere, Category = "Health")
    float CurrentHealth;

    UPROPERTY(VisibleAnywhere, Category = "UI")
    UWidgetComponent* HealthBarComponent;

    void UpdateHealthBar();

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    TSubclassOf<class AProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere)
    FVector MuzzleOffset;

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* FPSCameraComponent;

    UPROPERTY(VisibleDefaultsOnly)
    USkeletalMeshComponent* FPSMesh;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

    UFUNCTION()
    void MoveForward(float Value);

    UFUNCTION()
    void MoveRight(float Value);

    UFUNCTION()
    void StartJump();

    UFUNCTION()
    void StopJump();

    UFUNCTION()
    void Fire();

    UFUNCTION()
    void TakeDamage(float DamageAmount);
};

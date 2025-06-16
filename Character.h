#pragma once
     
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "FPSCharacter.generated.h"
     
UCLASS()
class FPSPROJECT_API AFPSCharacter : public ACharacter
{
    GENERATED_BODY()
 
public:
    AFPSCharacter();
     
protected:          
    virtual void BeginPlay() override;
     
public: 
    virtual void Tick( float DeltaTime ) override;
     
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
     
    UFUNCTION()
    void MoveForward(float Value);
     
    UFUNCTION()
    void MoveRight(float Value);
     
    UFUNCTION()
    void StartJump();
     
    UFUNCTION()
    void StopJump();

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* FPSCameraComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    USkeletalMeshComponent* FPSMesh;
};

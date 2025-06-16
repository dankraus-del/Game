#include "FPSCharacter.h"
     
AFPSCharacter::AFPSCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    check(FPSCameraComponent != nullptr);

    FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent>(GetCapsuleComponent()));

    FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

    FPSCameraComponent->bUsePawnControlRotation = true;

    FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
    check(FPSMesh != nullptr);

    FPSMesh->SetOnlyOwnerSee(true);

    FPSMesh->SetupAttachment(FPSCameraComponent);

    FPSMesh->bCastDynamicShadow = false;
    FPSMesh->CastShadow = false;

    GetMesh()->SetOwnerNoSee(true);
}

void AFPSCharacter::BeginPlay()
{
    Super::BeginPlay();
     
    check(GEngine != nullptr);

      GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
        
}

void AFPSCharacter::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
 
}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

    PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);
}
     
void AFPSCharacter::MoveForward(float Value)
{
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value);
}
     
void AFPSCharacter::MoveRight(float Value)
{
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}
     
void AFPSCharacter::StartJump()
{
    bPressedJump = true;
}
     
void AFPSCharacter::StopJump()
{
    bPressedJump = false;
}

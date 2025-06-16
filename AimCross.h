#pragma once

#include "CoreMinimal.h"
#include "GameFramework/AimCross.h"
#include "Engine/Canvas.h"
#include "AimCross.generated.h"

UCLASS()
class Game_API CrossHair : public CrossHair
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, Category = "HUD")
    UTexture2D* CrosshairTexture;

public:
    virtual void DrawHUD() override;
};

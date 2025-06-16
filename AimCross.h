#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Texture2D.h"
#include "AimCross.generated.h"

UCLASS()
class Game_API AAimCross : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, Category = "HUD")
    UTexture2D* CrosshairTexture;

public:
    virtual void DrawHUD() override;
};

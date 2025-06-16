#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode.generated.h"

UCLASS()
class Game_API AGameMode : public AGameMode
{
    GENERATED_BODY()
 
    virtual void StartPlay() override;
};

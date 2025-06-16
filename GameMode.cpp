#include "GameMode.h"
 
void AGameMode::StartPlay()
{
    Super::StartPlay();
 
    check(GEngine != nullptr);
}

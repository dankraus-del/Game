#include "AimCross.h"
#include "Engine/Canvas.h"

void AAimCross::DrawHUD()
{
    Super::DrawHUD();

    if (CrosshairTexture && Canvas)
    {
        const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

        const FVector2D CrosshairDrawPosition(
            Center.X - (CrosshairTexture->GetSizeX() * 0.5f),
            Center.Y - (CrosshairTexture->GetSizeY() * 0.5f)
        );

        FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
        TileItem.BlendMode = SE_BLEND_Translucent;

        Canvas->DrawItem(TileItem);
    }
}

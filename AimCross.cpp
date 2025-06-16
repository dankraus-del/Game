#include "AimCross.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"

void CrossHair::DrawHUD()
{
    Super::DrawHUD();

    if (CrosshairTexture)
    {
        FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

        FVector2D CrossHairDrawPosition(
            Center.X - (CrosshairTexture->GetSizeX() * 0.5f),
            Center.Y - (CrosshairTexture->GetSizeY() * 0.5f)
        );

        FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
        TileItem.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TileItem);
    }
}

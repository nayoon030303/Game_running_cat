#include "global.h"
#include "tile_bridge.h"


TileBridge::TileBridge(float x, float y)
{
    posX = x;
    posY = y;
    speed = SPEED;
    width = TILE_BRIDGE_WIDTH;
    height = TILE_BRIDGE_HEIGHT;
}

void TileBridge::Update()
{
    //posX -= speed;
}

void TileBridge::Render()
{
    TextureElement* element = textureManager.GetTexture(TEX_TILE_GROUND);

    RECT rc;
    D3DXVECTOR3 pos;
    D3DXVECTOR3 cen;

    element->sprite->Begin(D3DXSPRITE_ALPHABLEND);


    rc.left = 0;
    rc.top = 0;
    rc.right = width;
    rc.bottom = height;

    pos = { posX, posY, 0 };

    element->sprite->Draw(*element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

    element->sprite->End();


}
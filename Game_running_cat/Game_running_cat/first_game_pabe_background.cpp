#include "global.h"
#include "first_game_page_background.h"

#define FRIST_GAME_PAGE_BACKGROUND_WIDTH 2500

FirstGamePageBackground::FirstGamePageBackground()
{
    posX = 0;
    speed = SPEED;
}

void FirstGamePageBackground::Update()
{
    posX -= speed;
}

void FirstGamePageBackground::Render()
{
    TextureElement* element = textureManager.GetTexture(TEX_FIRST_GAME_BACKGROUND);

    RECT rc;
    D3DXVECTOR3 pos;
    D3DXVECTOR3 cen;

    element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

    rc.left = 0;
    rc.top = 0;
    rc.right = FRIST_GAME_PAGE_BACKGROUND_WIDTH;
    rc.bottom = WINDOW_HEIGHT;

    float  px = posX % FRIST_GAME_PAGE_BACKGROUND_WIDTH;
    pos = { px, 0,0 };
    element->sprite->Draw(*element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

    px = posX % FRIST_GAME_PAGE_BACKGROUND_WIDTH + FRIST_GAME_PAGE_BACKGROUND_WIDTH;
    pos = { px, 0,0 };
    element->sprite->Draw(*element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

    element->sprite->End();


}
#include "title_page.h"
#include "global.h"


#define BUTTON_WIDTH 330
#define BUTTON_HEIGHT 100

#define START_BUTTON_POSX 1650
#define START_BUTTON_POSY 700
#define EXIT_BUTTON_POSX 1650
#define EXIT_BUTTON_POSY 900

TitlePage::TitlePage()
{
    classType = TITLE_PAGE;
    startButtonState = TEX_START_BUTTON_NORMAL;
    exitButtonState = TEX_EXIT_BUTTON_NORMAL;
}

void TitlePage::Render()
{
    BackgroundRender();
    StartButtonRender();
    ExitButtonRender();
}

void TitlePage::Update()
{
    POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hWnd, &pt);

    StartButtonUpdate(pt);
    ExitButtonUpdate(pt);
}

void TitlePage::StartButtonUpdate(POINT pt)
{
    if (pt.x > START_BUTTON_POSX - BUTTON_WIDTH / 2 && pt.x < START_BUTTON_POSX + BUTTON_WIDTH / 2
        && pt.y>START_BUTTON_POSY-BUTTON_HEIGHT/2 && pt.y<START_BUTTON_POSY+BUTTON_HEIGHT/2)
    {
        startButtonState = TEX_START_BUTTON_BORDER;

        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
            pageManager.CreateFirstGamePage(); 
        }
    }
    else
    {
        startButtonState = TEX_START_BUTTON_NORMAL;
    }
}

void TitlePage::ExitButtonUpdate(POINT pt)
{
    if (pt.x > EXIT_BUTTON_POSX - BUTTON_WIDTH / 2 && pt.x < EXIT_BUTTON_POSX + BUTTON_WIDTH / 2
        && pt.y>EXIT_BUTTON_POSY - BUTTON_HEIGHT / 2 && pt.y < EXIT_BUTTON_POSY + BUTTON_HEIGHT / 2)
    {
        exitButtonState = TEX_EXIT_BUTTON_BORDER;
        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
            PostQuitMessage(0);
        }
    }
    else
    {
        exitButtonState = TEX_EXIT_BUTTON_NORMAL;
    }
}

void TitlePage::BackgroundRender()
{
    TextureElement* element = textureManager.GetTexture(TEX_TITLE_BACKGROUND);

    RECT rc;
    D3DXVECTOR3 pos;
    D3DXVECTOR3 cen;

    element->sprite->Begin(D3DXSPRITE_ALPHABLEND);


    rc.left = 0;
    rc.top = 0;
    rc.right = WINDOW_WIDTH;
    rc.bottom = WINDOW_HEIGHT;

    pos = { 0, 0, 0 };

    element->sprite->Draw(*element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

    element->sprite->End();
}

void TitlePage::StartButtonRender()
{

    TextureElement* element = textureManager.GetTexture(startButtonState);

    RECT rc;
    D3DXVECTOR3 pos;
    D3DXVECTOR3 cen;

    element->sprite->Begin(D3DXSPRITE_ALPHABLEND);


    rc.left = 0;
    rc.top = 0;
    rc.right = BUTTON_WIDTH; pos = { 0, 0, 0 };
    rc.bottom = BUTTON_HEIGHT;

    cen = { BUTTON_WIDTH / 2,BUTTON_HEIGHT / 2,0 };
    pos = { START_BUTTON_POSX, START_BUTTON_POSY, 0 };

    element->sprite->Draw(*element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

    element->sprite->End();

 
}

void TitlePage::ExitButtonRender()
{
    TextureElement* element = textureManager.GetTexture(exitButtonState);

    RECT rc;
    D3DXVECTOR3 pos;
    D3DXVECTOR3 cen;

    element->sprite->Begin(D3DXSPRITE_ALPHABLEND);


    rc.left = 0;
    rc.top = 0;
    rc.right = BUTTON_WIDTH; 
    rc.bottom = BUTTON_HEIGHT;

    cen = { BUTTON_WIDTH / 2,BUTTON_HEIGHT / 2,0 };
    pos = { EXIT_BUTTON_POSX, EXIT_BUTTON_POSY, 0 };

    element->sprite->Draw(*element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

    element->sprite->End();

}
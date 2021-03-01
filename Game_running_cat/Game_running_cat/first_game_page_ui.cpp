#include "global.h"
#include <tchar.h>
#include "first_game_page_ui.h"

#define STAGE_UI_WIDTH 1510
#define STAGE_UI_HEIGHT 60

#define STAGE_UI_CAT_WIDTH 40
#define STAGE_UI_CAT_HEIGHT 40

FirstGamePageUI::FirstGamePageUI()
{
	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);
	int fontSize = 30;
	int nHeight = -fontSize * nLogPixelsY / 72;
	TCHAR g_strFont[LF_FACESIZE];
	wcscpy_s(g_strFont, 32, L"Arial");
	D3DXCreateFont(g_pd3dDevice,            // D3D device
		nHeight,               // Height
		0,                     // Width
		FW_BOLD,               // Weight
		1,                     // MipLevels, 0 = autogen mipmaps
		FALSE,                 // Italic
		DEFAULT_CHARSET,       // CharSet
		OUT_DEFAULT_PRECIS,    // OutputPrecision
		DEFAULT_QUALITY,       // Quality
		DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
		g_strFont,              // pFaceName
		&font1);
}

void FirstGamePageUI::Update()
{

}

void FirstGamePageUI::Render()
{
	////cat

	/*TextureElement* element = textureManager.GetTexture(TEX_FIRST_GAME_UI_CAT);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);


	rc.left = 0;
	rc.top = 0;
	rc.right = STAGE_UI_CAT_WIDTH;
	rc.bottom = STAGE_UI_CAT_HEIGHT;

	pos = { WINDOW_WIDTH / 2 - STAGE_UI_WIDTH / 2 + 5, 10, 0 };

	element->sprite->Draw(*element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();*/

	/*RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	WCHAR text[256];
	rc.left = 100;
	rc.top = 100;
	text[256];
	int t = gameSystem.player->posY;
	_stprintf_s<256>(text, _T("score: %d"), t);
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));*/


}
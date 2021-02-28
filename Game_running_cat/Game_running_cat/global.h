#pragma once

#include "input_manager.h"
#include "texture_manager.h"
#include "page_manager.h"
#include "game_system.h"

//window_size
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

//first_stage
#define START_BOTTOM 890
#define GRAVITY 20
#define SPEED 10;

//tile
#define TILE_GROUND_WIDTH 200
#define TILE_GROUND_HEIGHT 200
#define TILE_BRIDGE_WIDTH 200
#define TILE_BRIDGE_HEIGHT 40

/*Class Type*/
//page
#define TITLE_PAGE 1
#define FIRST_GAME_PAGE 2
#define SECOND_GAME_PAGE 2


/*Texture ID*/
//Background
#define TEX_TITLE_BACKGROUND 1000
#define TEX_FIRST_GAME_BACKGROUND 1100

//UI
#define TEX_START_BUTTON_NORMAL 2000
#define TEX_START_BUTTON_BORDER 2100
#define TEX_EXIT_BUTTON_NORMAL 2200
#define TEX_EXIT_BUTTON_BORDER 2300
#define TEX_FIRST_GAME_UI_BAR 2400
#define TEX_FIRST_GAME_UI_CAT 2500

//Object
#define TEX_TILE_GROUND 3000

//Character
#define TEX_PLAER_NORMAL_1 4000
#define TEX_PLAER_NORMAL_2 -4000
#define TEX_PLAER_DOWN_1 4100
#define TEX_PLAER_DOWN_2 -4100
#define TEX_PLAER_JUMP_1 4200
#define TEX_PLAER_JUMP_2 -4200


/* global */
// basic
extern HWND hWnd;
extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;

//Manager
extern InputManager inputManager;
extern PageManager pageManager;
extern TextureManager textureManager;
extern GameSystem gameSystem;
// Game_running_cat.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Game_running_cat.h"


#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )
#include "global.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];            

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

/*global*/

//variable
HWND hWnd;
LPDIRECT3D9         g_pD3D = NULL;
LPDIRECT3DDEVICE9   g_pd3dDevice = NULL;



//Manager
InputManager inputManager;
PageManager pageManager;
TextureManager textureManager;
GameSystem gameSystem;


// Other
float deltaTime = 0.3f;
DWORD prevTime;

HRESULT InitD3D(HWND hWnd)
{
    // Create the D3D object.
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;

    // Set up the structure used to create the D3DDevice. Since we are now
    // using more complex geometry, we will create a device with a zbuffer.
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    /*  d3dpp.Windowed = TRUE;
      d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
      d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
      d3dpp.EnableAutoDepthStencil = TRUE;
      d3dpp.AutoDepthStencilFormat = D3DFMT_D16;*/


    d3dpp.Windowed = false;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
    d3dpp.BackBufferWidth = WINDOW_WIDTH;
    d3dpp.BackBufferHeight = WINDOW_HEIGHT;

    // Create the D3DDevice
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }

    return S_OK;
}

void Render()
{

    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET,
        D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        pageManager.Render();
        g_pd3dDevice->EndScene();
    }


    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void Update()
{

    DWORD cur = GetTickCount();
    DWORD diff = cur - prevTime;
    deltaTime = diff / 1000.0f;
    if (deltaTime > 0.016f)
    {
        deltaTime = 0.016f;
    }
    prevTime = cur;

    if (inputManager.prevKey[VK_ESCAPE] == 1 && inputManager.key[VK_ESCAPE] == 0)
    {
        PostQuitMessage(0);

    }
    else if (inputManager.prevKey[VK_F1] == 1 && inputManager.key[VK_F1] == 0)
    {
        pageManager.CreateTitlePage();
    }

    pageManager.Update();
    //cheat.Update();
    inputManager.Update();
}

void GameLoop()
{
    Render();
    Update();
}

void InitMyStuff()
{

    /*background*/
    textureManager.LoadTexture("source/img/page/_title.png", TEX_TITLE_BACKGROUND);
    textureManager.LoadTexture("source/img/page/first_game_page.png", TEX_FIRST_GAME_BACKGROUND);

    /* ui*/
    //title
    textureManager.LoadTexture("source/img/ui/title/start_button_normal.png", TEX_START_BUTTON_NORMAL);
    textureManager.LoadTexture("source/img/ui/title/start_button_border.png", TEX_START_BUTTON_BORDER);
    textureManager.LoadTexture("source/img/ui/title/exit_button_normal.png", TEX_EXIT_BUTTON_NORMAL);
    textureManager.LoadTexture("source/img/ui/title/exit_button_border.png", TEX_EXIT_BUTTON_BORDER);

    //first_game_page
    textureManager.LoadTexture("source/img/ui/first_game_page/bar.png", TEX_FIRST_GAME_UI_BAR);
    textureManager.LoadTexture("source/img/ui/first_game_page/cat_ui.png", TEX_FIRST_GAME_UI_CAT);

    /*object*/
    //tile
    textureManager.LoadTexture("source/img/object/tile/tile_bridge.png", TEX_TILE_GROUND);

    //character
    textureManager.LoadTexture("source/img/object/player/player_normal1.png", TEX_PLAER_NORMAL_1);
    textureManager.LoadTexture("source/img/object/player/player_normal2.png", TEX_PLAER_NORMAL_2);
    textureManager.LoadTexture("source/img/object/player/player_down1.png", TEX_PLAER_DOWN_1);
    textureManager.LoadTexture("source/img/object/player/player_down2.png", TEX_PLAER_DOWN_2);
    textureManager.LoadTexture("source/img/object/player/player_jump1.png", TEX_PLAER_JUMP_1);
    textureManager.LoadTexture("source/img/object/player/player_jump2.png", TEX_PLAER_JUMP_2);

    pageManager.CreateTitlePage();
    prevTime = GetTickCount();
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GAMERUNNINGCAT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMERUNNINGCAT));

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            GameLoop();
        }

    }
    return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMERUNNINGCAT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GAMERUNNINGCAT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);
    if (!hWnd)
    {
        return FALSE;
    }

    InitD3D(hWnd);
    InitMyStuff();
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYUP:
        inputManager.key[wParam] = 0;
        break;
    case WM_KEYDOWN:
        inputManager.key[wParam] = 1;
        break;
    case WM_LBUTTONDOWN:
        inputManager.key[VK_LBUTTON] = 1;
        break;
    case WM_LBUTTONUP:
        inputManager.key[VK_LBUTTON] = 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
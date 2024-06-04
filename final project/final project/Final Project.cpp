#include <windows.h>
#include <tchar.h>
#include <time.h>
#include <cmath>
#include "resource1.h"
#include "hamsu.h"
#pragma comment (lib, "msimg32.lib")

HINSTANCE g_hInst;
LPCWSTR lpszClass = L"Window Class Name";
LPCWSTR lpszWindowName = L"Formicide";
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

void InitializeMap(Box MAP[MaxV][MaxH]);
void UpdatePlayerPosition(Box& player, bool Up, bool Down, bool Left, bool Right);
void ApplyGravity(Box& player, const Box MAP[MaxV][MaxH]);
bool IsRectOverlap(const RECT* rect1, const RECT* rect2);
BOOL InRectangle(RECT rect, int mx, int my);
float LengthPts(int x1, int y1, int x2, int y2);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
    HWND hWnd;
    MSG Message;
    WNDCLASSEX WndClass;
    g_hInst = hInstance;

    WndClass.cbSize = sizeof(WndClass);
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_HAND);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = lpszClass;
    WndClass.hIconSm = LoadIcon(NULL, IDI_QUESTION);
    RegisterClassEx(&WndClass);
    hWnd = CreateWindow(lpszClass, lpszWindowName, WS_POPUPWINDOW, 200,100 , 1536, 768, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&Message, NULL, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return (int)Message.wParam;
}
int CameraX{ 0 }, CameraY{ 0 }, CameraX2{ 0 }, CameraY2{ 0 }, StartX{ 0 }, StartY{ 0 };
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hDC, mDC, bitDC;
    static HBITMAP hBitmap, mybit, largebit, forebit;
    static BITMAP bmp, largebmp, forebmp;
    static RECT rt;
    static TCHAR Clear1[100];
    static Box MAP[MaxV][MaxH], player,player2;
    static bool base = false, Screenmod = false, DevideScreen = false, Left = false, Right = false, Up = false, Down = false;
    static int count = 0;
    static double  mx, my, JumpForce = { 0 }, gapx{ 0 }, gapy{ 0 }, gapx2{ 4607 }, gapy2{ 0 };
    static HFONT TypeName = CreateFont(24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Courier New");
    static HBRUSH backgroundcolor = CreateSolidBrush(RGB(9, 15, 12));
    static HPEN redpen = CreatePen(PS_SOLID, 1, RGB(255, 50, 50));
    static HBRUSH Nullbrush = (HBRUSH)GetStockObject(NULL_BRUSH);

    switch (uMsg)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rt); //--- 윈도우 크기 얻어오기
        SetTimer(hWnd, Move, 50, NULL);
        SetTimer(hWnd, Gravity, 50, NULL);

        mybit = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(103));
        largebit = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(102));
        forebit = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(101));
        GetObject(mybit, sizeof(BITMAP), &bmp);
        GetObject(largebit, sizeof(BITMAP), &largebmp);
        GetObject(forebit, sizeof(BITMAP), &forebmp);
        InitializeMap(MAP);       
        player.rect.left = 30 * mapsize/8;
        player.rect.right = 31 * mapsize/8;
        player.rect.top = 40 * mapsize * 3 / 8;
        player.rect.bottom = 41 * mapsize * 3 / 8;
        player.rect.left = 680 - 50;
        player.rect.right = 680;
        player.rect.top = 680 - 90;
        player.rect.bottom = 680 ;
        player.x2 = (player.rect.left + player.rect.right) / 2;
        player.y2 = (player.rect.top + player.rect.bottom) / 2;
        player2.rect.left = 6144 - 31 * mapsize;
        player2.rect.right = 6144 - 30 * mapsize;
        player2.rect.top = 40 * mapsize;
        player2.rect.bottom = 41 * mapsize;
        player2.x2 = (player2.rect.left + player2.rect.right) / 2;
        player2.y2 = (player2.rect.top + player2.rect.bottom) / 2;
        player2.Land = false;
        for (int i = 0; i < MaxV; i++)
        {
            for (int j = 0; j < MaxH; j++)
            {
                MAP[i][j].rect.left = j * mapsize;
                MAP[i][j].rect.right = (j + 1) * mapsize;
                MAP[i][j].rect.top = i * mapsize;
                MAP[i][j].rect.bottom = (i + 1) * mapsize;
            }
        }
        break;

    case WM_LBUTTONDOWN:
        hDC = GetDC(hWnd);
        mx = LOWORD(lParam);
        my = HIWORD(lParam);

        InvalidateRect(hWnd, NULL, false);
        ReleaseDC(hWnd, hDC);
        break;

    case WM_CHAR:
        if (wParam == 'w' || wParam == 'W') Up = true;
        if (wParam == 's' || wParam == 'S') Down = true;
        if (wParam == 'a' || wParam == 'A') Left = true;
        if (wParam == 'd' || wParam == 'D') Right = true;
        InvalidateRect(hWnd, NULL, false);
        break;

    case WM_KEYUP:
        if (wParam == 'w' || wParam == 'W') Up = false;
        if (wParam == 's' || wParam == 'S') Down = false;
        if (wParam == 'a' || wParam == 'A') Left = false;
        if (wParam == 'd' || wParam == 'D') Right = false;
        InvalidateRect(hWnd, NULL, false);
        break;

    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        mDC = CreateCompatibleDC(hDC); //--- 메모리 DC 만들기
        bitDC = CreateCompatibleDC(mDC);
        hBitmap = CreateCompatibleBitmap(hDC, rt.right, rt.bottom); //--- 메모리 DC와 연결할 비트맵 만들기
        SelectObject(mDC, (HBITMAP)hBitmap); //--- 메모리 DC와 비트맵 연결하기

        SelectObject(mDC, backgroundcolor);
        Rectangle(mDC, 0, 0, rt.right, rt.bottom); //--- 화면에 비어있기 때문에 화면 가득히 사각형을 그려 배경색으로 설정하기

        //플레이어 시점 1 그리기
        SelectObject(bitDC, largebit);
        TransparentBlt(mDC, 0, 0, rt.right/2, rt.bottom, bitDC, gapx, gapy, 1536, 1536, RGB(0, 0, 0));
        SelectObject(bitDC, forebit);
        TransparentBlt(mDC, 0, 0, rt.right / 2, rt.bottom, bitDC, gapx, gapy, 1536, 1536, RGB(0, 0, 0));
        SelectObject(bitDC, mybit);
        TransparentBlt(mDC, 0, 0, rt.right / 2, rt.bottom, bitDC, gapx, gapy, 1536, 1536, RGB(0, 0, 0));

        //플레이어 시점 1 그리기
        SelectObject(bitDC, largebit);
        TransparentBlt(mDC, rt.right / 2, 0, rt.right / 2, rt.bottom, bitDC, gapx2, gapy2, 1536, 1536, RGB(0, 0, 0));
        SelectObject(bitDC, forebit);
        TransparentBlt(mDC, rt.right / 2, 0, rt.right / 2, rt.bottom, bitDC, gapx2, gapy2, 1536, 1536, RGB(0, 0, 0));
        SelectObject(bitDC, mybit);
        TransparentBlt(mDC, rt.right / 2, 0, rt.right / 2, rt.bottom, bitDC, gapx2, gapy2, 1536, 1536, RGB(0, 0, 0));


        SelectObject(mDC, TypeName);
        SetTextColor(mDC, RGB(255, 255, 255));
        SetBkMode(mDC, 1);
        wsprintf(Clear1, L"Left : %d", player.rect.left);
        TextOut(mDC, 20, 20, Clear1, lstrlen(Clear1));
        wsprintf(Clear1, L"Right : %d", player.rect.right);    
        TextOut(mDC, 20, 50, Clear1, lstrlen(Clear1));
        wsprintf(Clear1, L"Top : %d", player.rect.top);
        TextOut(mDC, 20, 80, Clear1, lstrlen(Clear1));
        wsprintf(Clear1, L"Bottom : %d", player.rect.bottom);
        TextOut(mDC, 20, 110, Clear1, lstrlen(Clear1));
        SelectObject(mDC, (HBITMAP)hBitmap);
        SelectObject(mDC, redpen);
        SelectObject(mDC, Nullbrush);
        Rectangle(mDC, (player.rect.left - gapx) / 2, (player.rect.top - gapy) / 2, (player.rect.right - gapx) / 2, (player.rect.bottom - gapy)/2);
        BitBlt(hDC, 0, 0, rt.right, rt.bottom, mDC, 0, 0, SRCCOPY);
        DeleteDC(bitDC);
        DeleteDC(mDC);
        DeleteObject(hBitmap);
        EndPaint(hWnd, &ps);
        break;

    case WM_TIMER:
        switch (wParam)
        {
        case Move:
            UpdatePlayerPosition(player, Up, Down, Left, Right);
            if (MAP[(int)((player.rect.bottom + mapsize) / mapsize)][(int)(player.rect.left / mapsize)].status == 0 && MAP[(int)((player.rect.bottom + mapsize) / mapsize)][(int)(player.rect.left / mapsize) + 1].status == 0 && MAP[(int)((player.rect.bottom + mapsize) / mapsize)][(int)(player.rect.left / mapsize) + 2].status == 0 && MAP[(int)((player.rect.bottom + mapsize) / mapsize)][(int)(player.rect.left / mapsize) + 3].status == 0)
            {
                player.Land = false;
            }
            else {
                player.Land = true;
            }
            InvalidateRect(hWnd, NULL, false);
            break;
        case Gravity:
            if (!player.Land)
            {
                ApplyGravity(player, MAP);
            }
            if (MAP[(int)((player.rect.bottom + mapsize) / mapsize)][(int)(player.x2 / mapsize)].status == 0 && MAP[(int)((player.rect.bottom + mapsize) / mapsize)][(int)(player.x2 / mapsize) + 1].status == 0)
            {
                player.Land = false;
            }
            else {
                player.Land = true;
            }
            if (player.x2 > 768 && player.x2<6144- 768)
            {
                gapx = player.x2 - 768;
            }
            else if (player.x2 <= 768)
            {
                gapx = 0;
            }
            else if (player.x2>=5376)
            {
                gapx = 4608;
            }
            if (player.rect.bottom > 768 && player.rect.bottom < 2048 - 768)
            {
                gapy = player.rect.bottom - 768;
            }
            else if (player.rect.bottom <= 768)
            {
                gapy = 0;
            }
            else if (player.rect.bottom >= 1280)
            {
                gapy = 512;
            }
            //
            if (player2.x2 >= 768 && player2.x2 <= 6144 - 768-mapsize)
            {
                gapx2 = player2.x2 - 768;
            }
            else if (player2.x2 <= 768)
            {
                gapx2 = 0;
            }
            else if (player2.x2 >= 5376)
            {
                gapx2 = 4608;
            }
            if (player2.rect.bottom >= 768 && player2.rect.bottom <= 2048 - 768-mapsize)
            {
                gapy2 = player2.rect.bottom - 768;
            }
            else if (player2.rect.bottom <= 768)
            {
                gapy2 = 0;
            }
            else if (player2.rect.bottom >= 1280)
            {
                gapy2 = 512;
            }
            //
            
            InvalidateRect(hWnd, NULL, false);
            break;
        default:
            break;
        }
        break;

    case WM_DESTROY:
        DeleteObject(TypeName);
        DeleteObject(backgroundcolor);
        DeleteObject(redpen);
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}   
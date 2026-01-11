#include <windows.h>
#include "creature.h"
#include "./utils/circle.h"

Creature creature;
Circle circle(50, 400, 300);

//Window procedure (handles messages)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch(uMsg){
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            creature.update();
            creature.draw(hdc);
            circle.draw(hdc);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//Entry point for Windows apps (not main)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow){
    // Window class setup
    const wchar_t CLASS_NAME[] = L"MyWindowClass";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    RegisterClassW(&wc);

    //Create window
    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"My Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800, 600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );
    if(hwnd == nullptr){
        return 0;
    }

    //Show window
    ShowWindow(hwnd, nCmdShow);

    //Message loop
    MSG msg = {};
    while(GetMessage(&msg, nullptr, 0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
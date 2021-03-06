#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"CGOL"; // Conways game of life
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;  // defines behaviour of the window
    wc.hInstance     = hInstance;   // handle to application instance
    wc.lpszClassName = CLASS_NAME;  // string to identify the window class

    RegisterClass(&wc); // This function registers the window class with the operating system.

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Conway's Game of Life",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop. https://docs.microsoft.com/en-us/windows/win32/learnwin32/window-messages
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            if (MessageBox(hwnd, L"Are you sure you want to quit?", L"Conway's Game of Life", MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hwnd);
            }
            return 0;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);

                FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

                EndPaint(hwnd, &ps);
            }
            return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); // If a msg is un-handled return it. Making it perform the default action to that msg
}


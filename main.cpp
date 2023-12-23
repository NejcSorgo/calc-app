#ifndef UNICODE
#define UNICODE

#endif
#define WM_LBUTTONDOWN    0x0201
#include <windows.h>
#include <winuser.h>
#include "./validator.cpp";
#include "./operatorji.cpp";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HWND window,inputBox,hwndButton,resultBox;
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Calculator App";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;

    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    window = CreateWindowEx(
            0,                              // Optional window styles.
            CLASS_NAME,                     // Window class
            L"Calculator app",    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, 400, 600,

            NULL,       // Parent window
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
    );
     hwndButton = CreateWindow(
             L"BUTTON",  // Predefined class; Unicode assumed
            L"OK",      // Button text
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
            10,         // x position
            10,         // y position
            100,        // Button width
            100,        // Button height
            window,     // Parent window
            NULL,       // No menu.
            (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
             NULL);
     inputBox = CreateWindow(
             L"EDIT",  // Predefined class; Edit - omogoca uporabniski vnos
            L"",      // Button text
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | WS_CHILD | WS_VISIBLE,  // Styles
            100,         // x position
            100,         // y position
            100,        // Button width
            20,        // Button height
            window,     // Parent window
            NULL,       // No menu.
            (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
             NULL);
    resultBox = CreateWindow(
            L"EDIT",  // Predefined class; Edit - omogoca uporabniski vnos
            L"",      // Button text
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | WS_CHILD | WS_VISIBLE,  // Styles
            100,         // x position
            200,         // y position
            200,        // Button width
            20,        // Button height
            window,     // Parent window
            NULL,       // No menu.
            (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
            NULL);

    if (window == NULL)
    {
        return 0;
    }

    ShowWindow(window, nCmdShow);
    ShowWindow(hwndButton, nCmdShow);
    ShowWindow(inputBox, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
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

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
            return 0;
        case WM_KEYDOWN:
                if (VK_RETURN)
                {
                    wchar_t text[GetWindowTextLengthA(hwnd)];
                    GetWindowText(hwnd,text,130);
                    std::wstring ws(text);
                    std::string str(ws.begin(), ws.end());
                    if(validator(str)) // poslje text na validator
                    {
                        SendMessage(resultBox, EM_SETSEL, -1, -1);
                        SendMessage(resultBox, EM_REPLACESEL, 0, (LPARAM)&text[0]);
                    } else
                    {

                    }
                    delete[] text;
                }
                break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case 1: // when button is clicked, this will happen:

                    // what code should go here??

                    break;
            }




    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
int main()
{
    wWinMain(NULL,NULL,NULL,SW_RESTORE);
}
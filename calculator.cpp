// calculator.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "calculator.h"
#include <iostream>
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;   // current instance 
HWND window, inputBox, hwndButton, resultBox, numberSystemComboBox, modeComboBox;
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CALCULATOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CALCULATOR));

    MSG msg;
 
   
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CALCULATOR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CALCULATOR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND window = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,CW_USEDEFAULT,400, 600, nullptr, nullptr, hInstance, nullptr);
   hwndButton = CreateWindow(
       L"BUTTON",  // Predefined class; Unicode assumed
       L"Poslji",      // Button text
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
       10,         // x position
       210,         // y position
       100,        // Sirina
       100,        // Visina
       window,     // Parent window
       (HMENU)1,       // No menu.
       (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
       NULL);

   numberSystemComboBox = CreateWindow(
       L"COMBOBOX",  // Predefined class; Unicode assumed
       L"Izberi",      // Button text
       CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,  // Styles
       10,         // x position
       310,         // y position
       100,        // Sirina
       100,        // Visina
       window,     // Parent window
       (HMENU)2,       // No menu.
       (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
       NULL);
   modeComboBox = CreateWindow(
       L"COMBOBOX",  // Predefined class; Unicode assumed
       L"Izberi",      // Button text
       CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,  // Styles
       10,         // x position
       330,         // y position
       100,        // Sirina
       100,        // Visina
       window,     // Parent window
       (HMENU)3,       // No menu.
       (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
       NULL);
   inputBox = CreateWindow(
       L"EDIT",  // Predefined class; Edit - omogoca uporabniski vnos
       L"",      // Button text
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_MULTILINE,  // Styles
       110,         // x position
       210,         // y position
       270,        // Sirina
       100,        // Visina
       window,     // Parent window
       NULL,       // No menu.
       (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
       NULL);
   resultBox = CreateWindow(
       L"EDIT",  // Predefined class; Edit - omogoca uporabniski vnos
       L"",      // Button text
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_MULTILINE,  // Styles
       10,         // x position
       10,         // y position
       370,        // Button width
       199,        // Button height
       window,     // Parent window
       NULL,       // No menu.
       (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
       NULL);
   //Napolni dropdown za stevilske sisteme
   TCHAR StevilskiSistemi[4][14] =
   {
           TEXT("Dvojiski"), TEXT("Desetiski"), TEXT("Osmiski"), TEXT("Sestnajstiski"),

   };
   TCHAR Nacini[2][14] =
   {
           TEXT("Aritmetika"), TEXT("Logicna vrata"),

   };
   TCHAR A[14];
   memset(&A, 0, sizeof(A));
   for (int k = 0; k < 4; k++)
   {
       if (k < 2)
       {
           wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)Nacini[k]);
           SendMessage(modeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)Nacini[k]);
       }
       wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)StevilskiSistemi[k]);
       SendMessage(numberSystemComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)StevilskiSistemi[k]);
   }
 
   if (!window)
   {
      return FALSE;
   }
   ShowWindow(window, nCmdShow);
   ShowWindow(hwndButton, nCmdShow);
   ShowWindow(inputBox, nCmdShow);
   ShowWindow(window, nCmdShow);
   UpdateWindow(window);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case 1:
                wchar_t inputText[2000];
                GetWindowText(inputBox, inputText, GetWindowTextLengthA(inputBox) + 1);

            
                if (preveri(inputText, SendMessage(numberSystemComboBox, CB_SETCURSEL, (WPARAM)2, (LPARAM)0))) // poslje text na validator
                {
                    // SendMessage(resultBox, EM_SETSEL, -1, -1);
                    std::wstring ws(inputText);
                    std::string (ws.begin(), ws.end()); // convertanje v string
                    
                    SendMessage(resultBox, EM_REPLACESEL, 0, (LPARAM)&inputText[0]);
                }
                else
                {

                    wchar_t error[7] = { L"napaka" };
                    SendMessage(resultBox, EM_REPLACESEL, 0, (LPARAM)&error[0]);
                }
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

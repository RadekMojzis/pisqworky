#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>

class Game {
	void draw();
	bool victory(int x, int y);
	bool count_symbol(int in);

	std::vector<std::vector<int>> playfield;
	bool player;
public:
	Game() :player{ true }, playfield{ std::vector<std::vector<int>>(15, std::vector<int>(15, 0)) } {};
	int move(int x, int y);
	int newgame();

};


// Global variable
HINSTANCE hInst;

// Function prototypes.
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);


// Application entry point. This is the same as main() in standart C.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;
    BOOL bRet;
    WNDCLASS wcx;          // register class
    HWND hWnd;

    hInst = hInstance;     // Save the application-instance handle.
	    // Fill in the window class structure with parameters that describe the main window.

    wcx.style = CS_HREDRAW | CS_VREDRAW;              // redraw if size changes
    wcx.lpfnWndProc = (WNDPROC) MainWndProc;                    // points to window procedure
    wcx.cbClsExtra = 0;                               // no extra class memory
    wcx.cbWndExtra = 0;                               // no extra window memory
    wcx.hInstance = hInstance;                        // handle to instance
    wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);      // predefined app. icon
    wcx.hCursor = LoadCursor(NULL, IDC_ARROW);                                   // predefined arrow
    wcx.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);  // white background brush
    wcx.lpszMenuName =  (LPCSTR) "MainMenu";                   // name of menu resource
    wcx.lpszClassName = (LPCSTR) "MainWClass";                 // name of window class

    // Register the window class.

    if (!RegisterClass(&wcx)) return FALSE;

    // create window of registered class

    hWnd = CreateWindow(
        "MainWClass",        // name of window class
        "ITU",       // title-bar string
        WS_OVERLAPPEDWINDOW, // top-level window
        50,                  // default horizontal position
        100,                 // default vertical position
        640,                 // default width
        480,                 // default height
        (HWND) NULL,         // no owner window
        (HMENU) NULL,        // use class menu
        hInstance,           // handle to application instance
        (LPVOID) NULL);      // no window-creation data
    if (!hWnd) return FALSE;

    // Show the window and send a WM_PAINT message to the window procedure.
    // Record the current cursor position.

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // loop of message processing

    while( (bRet = GetMessage( &msg, NULL, 0, 0 )) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;
}

// **************************************************************** //
LRESULT CALLBACK MainWndProc(
    HWND hWnd,        // handle to window
    UINT uMsg,        // message identifier
    WPARAM wParam,    // first message parameter
    LPARAM lParam)    // second message parameter
{

    switch (uMsg)
    {
        case WM_CREATE:
            // Initialize the window.
            return 0;

        case WM_SIZE:
            // Set the size and position of the window.
            return 0;

        case WM_DESTROY:
            // Clean up window-specific data objects.
            PostQuitMessage(0);
            return 0;

        //
        // Process other messages.
        //

        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
}


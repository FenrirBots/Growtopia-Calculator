#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int main(int argc, char** argv)
{

    WNDCLASSEX wcex = { sizeof WNDCLASSEX };
    wcex.hInstance     = GetModuleHandle(0);
    wcex.lpszClassName = TEXT("Window Class");
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = DefWindowProc;

    if (!RegisterClassEx(&wcex))
    {
        /* Throw Error */
    }

    HWND hWnd = CreateWindowEx(0, wcex.lpszClassName, TEXT("Growtopia Price Calulator"), 0, 0, 0, 100, 100, 0, 0, wcex.hInstance, 0);
    if (!hWnd)
    {
        /* Throw Error */
        return 0;
    }

    ShowWindow(hWnd, SW_SHOW);

    MSG Msg;
    while (Msg.message != WM_QUIT)
    {
        if (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
        {
            if (!TranslateMessage(&Msg))
            {
                /* Throw Error */
                return 0;
            }

            DispatchMessageW(&Msg);
        }
    }

    return 0;
}
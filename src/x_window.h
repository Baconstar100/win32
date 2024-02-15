#ifndef TESTING_X_WINDOW_H
#define TESTING_X_WINDOW_H

#include <string.h>
#include <stdio.h>

#include "standard.h"
#include "colors.h"
#include "resource.h"

void InitWindow(MainWindow* xWindow, char xTitle[], int xWidth, int xHeight);
void StartWindow(MainWindow* paraWindow, HINSTANCE paraInst, int nCmdShow);
static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


void InitWindow(MainWindow* xWindow, char xTitle[], int xWidth, int xHeight) {
    strncpy(xWindow->title, xTitle, sizeof(xTitle));
    xWindow->width = xWidth;
    xWindow->height = xHeight;

    RECT windowRect = {0, 0, (LONG)xWindow->width, (LONG)xWindow->height};
    xWindow->windowRect = windowRect;
}

void StartWindow(MainWindow* paraWindow, HINSTANCE paraInst, int nCmdShow) {
    BOOL bRet;
    
    WNDCLASSEX windowClass = {0};
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = paraInst;
    windowClass.hCursor = LoadCursor(NULL, IDC_NO);
    windowClass.lpszClassName = "ClassOne";
    RegisterClassEx(&windowClass);

    AdjustWindowRect(&paraWindow->windowRect, WS_OVERLAPPEDWINDOW | WS_VISIBLE, FALSE);

    paraWindow->xHwnd = CreateWindow(
            windowClass.lpszClassName,
            paraWindow->title,
            WS_OVERLAPPEDWINDOW,
            0,
            0,
            paraWindow->windowRect.right - paraWindow->windowRect.left,
            paraWindow->windowRect.bottom - paraWindow->windowRect.top,
            NULL,
            NULL,
            paraInst,
            paraWindow
    );
    
    HACCEL haccel = LoadAccelerators(paraInst, MAKEINTRESOURCE(IDR_ACCEL1));

    ShowWindow(paraWindow->xHwnd, nCmdShow);

    MSG msg;
    while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
        if (bRet != -1) {
            if (!TranslateAcceleratorW(paraWindow->xHwnd, haccel, &msg)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        } else {

        }
    }
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC psHdc = GetDC(hWnd);
    
    switch (msg) {
        case WM_CREATE: {
            //LPCREATESTRUCT xCreateStruct = (LPCREATESTRUCT) lParam;
            //SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)xCreateStruct->lpCreateParams);
            CreateWindowW(L"STATIC", L"Text here", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 20, 300, 25, hWnd, NULL, NULL, NULL);
            PaintRect(hWnd, psHdc, &ps, wParam, 1);
            return 0;
        }
        case WM_KEYDOWN: {
            PaintRect(hWnd, psHdc, &ps, wParam, 1);
            RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_INVALIDATE);
            return 0;
        }
        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case BOOST_ADD:
                    PaintRect(hWnd, psHdc, &ps, VK_OEM_PLUS, 10);
                    RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_INVALIDATE);
                    break;
                case BOOST_SUBTRACT:
                    PaintRect(hWnd, psHdc, &ps, VK_OEM_MINUS, 10);
                    RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_INVALIDATE);
                    break;
                default:
                    break;
            }
        }
        case WM_PAINT: {
            return 0;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

#endif //TESTING_X_WINDOW_H

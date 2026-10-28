#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define ID_EDIT   101
#define ID_PUSH   102
#define ID_POP    103
#define ID_STATUS 104

Stack myStack;
HWND hEdit, hStatus;

void updateStatus(HWND hwnd, const char *msg) {
    SetWindowText(hStatus, msg);
    InvalidateRect(hwnd, NULL, TRUE);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            initStack(&myStack);

            CreateWindow("STATIC", "Enter number:", WS_VISIBLE | WS_CHILD,
                20, 20, 100, 20, hwnd, NULL, NULL, NULL);

            hEdit = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                130, 18, 100, 22, hwnd, (HMENU)ID_EDIT, NULL, NULL);

            CreateWindow("BUTTON", "Push", WS_VISIBLE | WS_CHILD,
                250, 18, 70, 24, hwnd, (HMENU)ID_PUSH, NULL, NULL);

            CreateWindow("BUTTON", "Pop", WS_VISIBLE | WS_CHILD,
                330, 18, 70, 24, hwnd, (HMENU)ID_POP, NULL, NULL);

            hStatus = CreateWindow("STATIC", "Stack empty", WS_VISIBLE | WS_CHILD,
                20, 55, 380, 20, hwnd, (HMENU)ID_STATUS, NULL, NULL);

            break;
        }

        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_PUSH) {
                char buffer[20];
                GetWindowText(hEdit, buffer, 20);
                int value = atoi(buffer);

                if (push(&myStack, value)) {
                    char msg[50];
                    sprintf(msg, "Pushed %d onto the stack", value);
                    updateStatus(hwnd, msg);
                } else {
                    updateStatus(hwnd, "Stack is full!");
                }
                SetWindowText(hEdit, "");
            }
            else if (LOWORD(wParam) == ID_POP) {
                int value;
                if (pop(&myStack, &value)) {
                    char msg[50];
                    sprintf(msg, "Popped %d from the stack", value);
                    updateStatus(hwnd, msg);
                } else {
                    updateStatus(hwnd, "Stack is empty!");
                }
            }
            break;
        }

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            RECT rect;
            GetClientRect(hwnd, &rect);
            HBRUSH bg = CreateSolidBrush(RGB(25, 25, 25));
            FillRect(hdc, &rect, bg);
            DeleteObject(bg);

            // draw stack blocks bottom-up
            int blockWidth = 100;
            int blockHeight = 30;
            int baseX = 40;
            int baseY = 420;

            for (int i = 0; i <= myStack.top; i++) {
                int y = baseY - (i * (blockHeight + 5));

                RECT block = {baseX, y, baseX + blockWidth, y + blockHeight};
                HBRUSH brush = CreateSolidBrush(RGB(60, 140, 255));
                FillRect(hdc, &block, brush);
                DeleteObject(brush);

                FrameRect(hdc, &block, (HBRUSH)GetStockObject(WHITE_BRUSH));

                char numText[10];
                sprintf(numText, "%d", myStack.items[i]);
                SetTextColor(hdc, RGB(255, 255, 255));
                SetBkMode(hdc, TRANSPARENT);
                TextOut(hdc, baseX + 40, y + 7, numText, strlen(numText));
            }

            // label
            SetTextColor(hdc, RGB(200, 200, 200));
            TextOut(hdc, baseX, baseY + 15, "<- Bottom", 9);

            EndPaint(hwnd, &ps);
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    (void)hPrevInstance;
    (void)lpCmdLine;

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "StackGUIClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);

    
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, "StackGUIClass", "Stack Visualizer",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 440, 480,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
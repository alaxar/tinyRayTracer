#include "../include/window.h"
#include <raytracer.h>
bool isRunning = true;

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    Window *pThis;
    LRESULT ret = 0;
    HDC hdc;
    int windowWidth, windowHeight;
    // get the "this" pointer for this static member to access non static memory
    if(msg == WM_NCCREATE) {
        // recover the "this" pointer passed in the createwindow
        LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lp;
        pThis = (Window*)lpcs->lpCreateParams;

        // store it in the win32 window user data.
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
    } else {
        pThis = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    }

    switch(msg) {
        case WM_PAINT:
            PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            RECT rect;
            GetClientRect(hwnd, &rect);
            windowWidth = rect.right - rect.left;
            windowHeight = rect.bottom - rect.top;
            StretchDIBits(hdc, 0, 0, windowWidth, windowHeight, 0, 0, pThis->renderer.width, pThis->renderer.height, pThis->renderer.framebuffer, &pThis->bmi, DIB_RGB_COLORS, SRCCOPY);
            EndPaint(hwnd, &ps);
            break;
        case WM_DESTROY:
            isRunning = false;
            break;
        default:
            ret = DefWindowProc(hwnd, msg, wp, lp);
            break;
    }
    return ret;
}

void Window::Run() {
    MSG msg = {};
    
    while(isRunning) {
        while(PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // game loop here.
        renderer.render();

        InvalidateRect(hwnd, nullptr, FALSE);
    }
}

Window::Window(HINSTANCE hinst, RayTracer& raytracer) : renderer(raytracer) {
    WNDCLASS wc = {sizeof(WNDCLASS)};

    wc.lpfnWndProc = Window::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "MyWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hbrBackground = CreateSolidBrush(RGB(50, 50, 50));

    if(!RegisterClass(&wc)) {
        MessageBox(0, "Window Registration Failed!", "Error!", MB_ICONINFORMATION | MB_OK);
    }

    hwnd = CreateWindowExW(0, L"MyWindowClass", L"3D renderer", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, this->renderer.width, this->renderer.height, NULL, NULL, hInst, this);

    if(!hwnd) return;

    // describing the bitmap structure
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = this->renderer.width;
    bmi.bmiHeader.biHeight = -this->renderer.height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
}
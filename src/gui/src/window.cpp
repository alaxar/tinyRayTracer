#include "../include/window.h"
#include <raytracer.h>
bool isRunning = true;

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    LRESULT ret = 0;
    switch(msg) {
        case WM_DESTROY:
            exit(0);
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
    }
}

Window::Window(HINSTANCE hinst, RayTracer& raytracer) : renderer(raytracer) {
    WNDCLASS wc = {sizeof(WNDCLASS)};

    wc.lpfnWndProc = Window::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "MyWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClass(&wc)) {
        MessageBox(0, "Window Registration Failed!", "Error!", MB_ICONINFORMATION | MB_OK);
    }

    hwnd = CreateWindowExW(0, L"MyWindowClass", L"3D renderer", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 800, NULL, NULL, hInst, NULL);

    if(!hwnd) return;
}
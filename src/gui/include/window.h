#pragma once
#include <windows.h>

extern bool isRunning;
class RayTracer;        // forward declaration

class Window {
public:
    Window() = default;
    Window(HINSTANCE hInst, RayTracer &renderer);
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
    void Run();

private:
    HINSTANCE hInst;
    RayTracer &renderer;
    HWND hwnd;
    BITMAPINFO bmi = {};
};
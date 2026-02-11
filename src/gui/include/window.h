#pragma once
#include <windows.h>

extern bool isRunning;

class Window {
public:
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
    int init(HINSTANCE hInst);
};
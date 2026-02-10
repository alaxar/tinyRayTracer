#include "gui/include/window.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    
    Window window;
    window.init(hInst);
    
    return 0;
}
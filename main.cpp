#include "src/gui/include/window.h"
#include "src/mathlib/include/Vector.h"
#include "src/engine/raytracer/include/raytracer.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    
    RayTracer raytracer;

    Window window(hInst, raytracer);
    window.Run();

    return 0;
}
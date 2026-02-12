#include "src/gui/include/window.h"
#include "src/engine/Math/include/Vector.h"
#include "src/engine/raytracer/include/raytracer.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {  
    RayTracer raytracer(640, 480);

    Window window(hInst, raytracer);
    window.Run();

    return 0;
}